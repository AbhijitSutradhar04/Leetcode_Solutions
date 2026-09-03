var addTwoPromises = async function(promise1, promise2) {
    let a = await promise1;
    let b = await promise2;

    return a + b;
};