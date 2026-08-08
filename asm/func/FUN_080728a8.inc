	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080728C4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080728B8
	b _080729CE
_080728B8:
	lsls r0, r0, #2
	ldr r1, _080728C8 @ =_080728CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080728C4: .4byte 0x0000037D
_080728C8: .4byte _080728CC
_080728CC: @ jump table
	.4byte _080728E0 @ case 0
	.4byte _08072900 @ case 1
	.4byte _08072910 @ case 2
	.4byte _08072930 @ case 3
	.4byte _08072980 @ case 4
_080728E0:
	ldr r1, _080728F8 @ =0x00000211
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080729CE
	ldr r0, _080728FC @ =0x0000037D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807296E
	.align 2, 0
_080728F8: .4byte 0x00000211
_080728FC: .4byte 0x0000037D
_08072900:
	ldr r1, _0807290C @ =0x00000212
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080729CE
	.align 2, 0
_0807290C: .4byte 0x00000212
_08072910:
	ldr r1, _0807292C @ =0x00000211
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080729CE
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_08072620
	b _0807296E
	.align 2, 0
_0807292C: .4byte 0x00000211
_08072930:
	ldr r1, _08072978 @ =0x00000212
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r1, _0807297C @ =0x0000037E
	adds r5, r4, r1
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _08072956
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_08072956:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080729CE
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08060b84
_0807296E:
	adds r0, r4, #0
	bl FUN_080726b4
	b _080729CE
	.align 2, 0
_08072978: .4byte 0x00000212
_0807297C: .4byte 0x0000037E
_08072980:
	ldr r1, _080729D4 @ =0x00000212
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _080729D8 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _080729A6
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08060c40
_080729A6:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080729CE
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _080729DC @ =FUN_080726e0
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080726b4
_080729CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080729D4: .4byte 0x00000212
_080729D8: .4byte 0x0000037E
_080729DC: .4byte FUN_080726e0
