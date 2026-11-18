	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081c67fc
	adds r0, r4, #0
	bl FUN_081c6bf8
	adds r0, r4, #0
	bl FUN_080fa77c
	ldr r1, _081CB3D8 @ =0x0000214A
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081CB3D0
	adds r0, r4, #0
	bl FUN_080f9f20
	lsls r0, r0, #0x18
_081CB3D0:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CB3D8: .4byte 0x0000214A
