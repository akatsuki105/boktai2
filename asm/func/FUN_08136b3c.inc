	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r5, #0xff
	movs r1, #0
	ldr r2, _08136B74 @ =0x00000B3A
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08136B8A
	movs r7, #4
	adds r3, r0, #0
	movs r2, #0
	movs r6, #0xcb
	lsls r6, r6, #3
_08136B60:
	adds r0, r2, r4
	adds r0, r0, r6
	adds r0, #0xfd
	ldrb r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _08136B78
	movs r0, #1
	b _08136B7A
	.align 2, 0
_08136B74: .4byte 0x00000B3A
_08136B78:
	movs r0, #0
_08136B7A:
	cmp r0, #0
	bne _08136BA2
	movs r0, #0x90
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r1, #1
	cmp r1, r3
	blt _08136B60
_08136B8A:
	cmp r5, #0xff
	beq _08136BD2
	movs r1, #1
	movs r2, #0xb3
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08136BA6
	movs r0, #1
	b _08136BA8
_08136BA2:
	adds r5, r1, #0
	b _08136B8A
_08136BA6:
	movs r0, #0
_08136BA8:
	cmp r0, #0
	beq _08136BD2
	ldr r0, _08136BD8 @ =0x00000AF4
	adds r3, r4, r0
	lsls r2, r5, #3
	adds r2, r2, r5
	lsls r2, r2, #5
	adds r0, r4, r2
	ldr r1, _08136BDC @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, _08136BE0 @ =0x00000B14
	adds r0, r4, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r2, r1
	adds r2, r4, r2
	str r2, [r0]
_08136BD2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08136BD8: .4byte 0x00000AF4
_08136BDC: .4byte 0x00000674
_08136BE0: .4byte 0x00000B14
