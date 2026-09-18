	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0823CE0C @ =0x08DBD83C
	movs r2, #0
	movs r3, #0xaa
	bl FUN_0823cdc0
	pop {r1}
	bx r1
	.align 2, 0
_0823CE0C: .4byte 0x08DBD83C
