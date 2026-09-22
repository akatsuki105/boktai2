	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ldrh r1, [r6, #0x38]
	adds r0, r0, r1
	strh r0, [r6, #0x38]
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	ldrh r2, [r6, #0x3c]
	adds r0, r0, r2
	strh r0, [r6, #0x3c]
	adds r4, r6, #0
	adds r4, #0x64
	adds r5, r6, #0
	adds r5, #0x38
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r2, [r6, #0x18]
	ldr r1, _08080924 @ =0x00080002
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
	adds r0, r5, #0
	bl FUN_082328ec
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0x3a
	ldrsh r1, [r6, r2]
	cmp r0, r1
	ble _0808092C
	ldr r1, _08080928 @ =FUN_0808094c
	adds r0, r6, #0
	bl FUN_080801f4
	b _08080944
	.align 2, 0
_08080924: .4byte 0x00080002
_08080928: .4byte FUN_0808094c
_0808092C:
	adds r1, r6, #0
	adds r1, #0xca
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _08080944
	adds r0, r6, #0
	bl KillEntity
_08080944:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
