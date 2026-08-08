	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xc6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0820fea8
	ldr r3, _08211D78 @ =0x00000322
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r4, #4]
	ldrh r2, [r4, #2]
	adds r1, r1, r2
	movs r3, #0
	ldrsh r2, [r4, r3]
	adds r1, r1, r2
	cmp r0, r1
	ble _08211D70
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08211bac
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08211D70:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08211D78: .4byte 0x00000322
