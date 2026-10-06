	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0x64
	movs r1, #0xd0
	adds r1, r1, r5
	mov sb, r1
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08042946
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	mov r3, r8
	ldr r2, [r3, #8]
	ldrh r0, [r2]
	movs r3, #0
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	ldrh r1, [r2, #2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r5, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r5, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r5, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _0804299C @ =0x00000213
	adds r0, r5, r2
	strb r4, [r0]
_08042946:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08042A38
	ldr r0, _0804299C @ =0x00000213
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080429F6
	mov r1, sb
	ldr r0, [r1]
	cmp r0, #2
	bne _080429CC
	adds r2, r5, #0
	adds r2, #0xfc
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080429EC
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080429A0
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	lsrs r0, r0, #1
	b _080429A8
	.align 2, 0
_0804299C: .4byte 0x00000213
_080429A0:
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
_080429A8:
	adds r1, r7, #0
	adds r1, #8
	adds r2, r7, #0
	adds r2, #0x10
	adds r3, r7, #5
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, r8
	bl Map_GetStepToPathNode
	ldr r2, _080429C8 @ =0x00000213
	adds r1, r5, r2
	strb r0, [r1]
	b _080429EC
	.align 2, 0
_080429C8: .4byte 0x00000213
_080429CC:
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r2, r5, #0
	adds r2, #0x6c
	adds r3, r5, #0
	adds r3, #0x61
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, r8
	adds r1, r6, #0
	bl Map_GetStepToPathNode
	strb r0, [r4]
_080429EC:
	ldr r1, _08042A0C @ =0x00000213
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08042A20
_080429F6:
	mov r2, sb
	ldr r1, [r2]
	cmp r1, #2
	bne _08042A10
	mov r0, sb
	adds r0, #0x2c
	ldrb r0, [r0, #0x1d]
	ands r1, r0
	cmp r1, #0
	beq _08042A20
	b _08042A1C
	.align 2, 0
_08042A0C: .4byte 0x00000213
_08042A10:
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08042A20
_08042A1C:
	movs r0, #1
	strb r0, [r5, #7]
_08042A20:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080414fc
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08042A38:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
