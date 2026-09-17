	push {lr}
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x11
	lsls r1, r0
	lsrs r1, r1, #0x10
	ldr r2, _0823D21C @ =0x03003E78
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0823D21C: .4byte 0x03003E78
