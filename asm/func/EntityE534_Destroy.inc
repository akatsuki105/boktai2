	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_08012B7A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08011854
	adds r4, #1
	adds r5, #0xc8
	cmp r4, #0xf
	ble _08012B7A
	ldr r1, _08012B9C @ =0x00000CD4
	adds r0, r6, r1
	bl FUN_08022428
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08012B9C: .4byte 0x00000CD4
