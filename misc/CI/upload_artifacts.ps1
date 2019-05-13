param(
[string]$upload="false",
[Parameter(Mandatory=$true)][string]$remotePath,
[Parameter(Mandatory=$true)][string]$localPath,
[Parameter(Mandatory=$true)][int]$jobId,
[Parameter(Mandatory=$true)][string]$jobUrl)

if($upload.ToLower().equals("true"))
{
    $resolvedPath = Resolve-Path -Path $localPath
    write-host -b green "uploading $resolvedPath"
    rclone purge $remotePath/latest
    rclone copy $resolvedPath $remotePath/$jobId/
    rclone copy $resolvedPath $remotePath/latest/
    $jobUrl | Out-File 'job.txt'
    rclone copy 'job.txt' $remotePath/$jobId/
    rclone copy 'job.txt' $remotePath/latest/
}
else
{
    write-host -b red "artifacts upload to OneDrive turned off"
}