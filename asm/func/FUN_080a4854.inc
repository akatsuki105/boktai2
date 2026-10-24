	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A4898 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080A48A0
	adds r5, r4, #0
	adds r5, #0xde
	movs r2, #0x1e
	ldrsh r1, [r4, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _080A4884
	ldr r0, _080A489C @ =0x000002B3
	bl PlaySound_082406e0
_080A4884:
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	subs r0, #0x10
	cmp r1, r0
	ble _080A48B6
	ldrh r0, [r4, #0x1e]
	subs r0, #2
	b _080A48B4
	.align 2, 0
_080A4898: .4byte 0x03002BE0
_080A489C: .4byte 0x000002B3
_080A48A0:
	adds r0, r4, #0
	adds r0, #0xde
	ldrh r2, [r4, #0x1e]
	movs r3, #0x1e
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _080A48B6
	adds r0, r2, #2
_080A48B4:
	strh r0, [r4, #0x1e]
_080A48B6:
	pop {r4, r5}
	pop {r0}
	bx r0
