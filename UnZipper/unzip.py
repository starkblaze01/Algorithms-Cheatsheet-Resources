from zipfile import ZipFile


def unzipper(file):
    with Zipfile(file, "r") as zip:
        zip.printdir()
        print("Extracting all the files...")
        zip.extractall()
        print("EXTRACION COMPLETE")


if __name__ == "__main__":
    zip_file = input(r"Path to compressed file:")
    unzipper(zip_file)
