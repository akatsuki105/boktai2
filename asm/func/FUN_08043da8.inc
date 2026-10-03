	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043DCA
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #1
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl EntityMsgBox_EndWait
_08043DCA:
	ldr r2, _08043E38 @ =0x00000236
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _08043E44
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _08043E48
	adds r1, r5, #0
	adds r1, #0x22
	ldr r6, _08043E3C @ =0x00000231
	adds r0, r4, r6
	ldrb r2, [r1]
	ldrb r3, [r0]
	cmp r2, r3
	bne _08043DFE
	adds r0, r5, #0
	adds r0, #0x23
	adds r6, #1
	adds r1, r4, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08043E28
_08043DFE:
	cmp r2, r3
	bls _08043E0C
	ldr r1, _08043E40 @ =0x00000233
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r2, r0
	blo _08043E28
_08043E0C:
	ldr r6, _08043E40 @ =0x00000233
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r2, r0
	bne _08043E48
	adds r0, r5, #0
	adds r0, #0x23
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08043E48
_08043E28:
	movs r0, #0xf
	movs r1, #0
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _08043E4E
	.align 2, 0
_08043E38: .4byte 0x00000236
_08043E3C: .4byte 0x00000231
_08043E40: .4byte 0x00000233
_08043E44:
	subs r0, #1
	strh r0, [r1]
_08043E48:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_08043E4E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
