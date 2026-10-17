	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r1, _08088568 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08088534
	adds r0, r4, #0
	movs r1, #3
	bl Coffin_SetState
_08088534:
	ldr r0, _0808856C @ =0x030047A4
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _08088544
	b _08088708
_08088544:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08088574
	ldr r3, _08088570 @ =0x0000032A
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, #0x94
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_080856f4
	adds r7, r4, #0
	adds r7, #0x48
	b _080886FC
	.align 2, 0
_08088568: .4byte 0x000001F5
_0808856C: .4byte 0x030047A4
_08088570: .4byte 0x0000032A
_08088574:
	ldr r3, _080885E8 @ =0x0000032A
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r7, r4, #0
	adds r7, #0x48
	cmp r0, #0x5a
	bhi _0808858E
	b _080886BE
_0808858E:
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r2, #0
	ldrsh r0, [r7, r2]
	subs r1, r1, r0
	mov sb, r1
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	mov r8, r2
	mov sl, r1
	mov r0, sb
	cmp r0, #0
	bne _080885C2
	cmp r2, #0
	beq _08088690
_080885C2:
	mov r0, sb
	mov r1, r8
	bl ArcTan2_8
	adds r5, r0, #0
	ldr r2, _080885EC @ =gSineTable
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _080885F0
	asrs r0, r0, #0xc
	b _080885F6
	.align 2, 0
_080885E8: .4byte 0x0000032A
_080885EC: .4byte gSineTable
_080885F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080885F6:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r1, _08088618 @ =gSineTable
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _0808861C
	asrs r0, r0, #0xc
	b _08088622
	.align 2, 0
_08088618: .4byte gSineTable
_0808861C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08088622:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08088664 @ =0xFFFF0000
	mov r6, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r2, _08088668 @ =0x00000841
	adds r0, r7, #0
	mov r1, sp
	bl FUN_08088430
	adds r1, r0, #0
	cmp r1, #0
	beq _08088670
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r7]
	adds r0, r0, r1
	strh r0, [r7]
	ldrh r0, [r6, #4]
	mov r2, sl
	ldrh r2, [r2]
	adds r0, r0, r2
	mov r3, sl
	strh r0, [r3]
	ldr r0, _0808866C @ =0x0000033A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08088676
	.align 2, 0
_08088664: .4byte 0xFFFF0000
_08088668: .4byte 0x00000841
_0808866C: .4byte 0x0000033A
_08088670:
	ldr r2, _080886F0 @ =0x0000033A
	adds r0, r4, r2
	strb r1, [r0]
_08088676:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
_08088690:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080886BE
	mov r0, sb
	mov r1, r8
	bl FUN_080884f4
	cmp r0, #0
	beq _080886BE
	movs r2, #0xec
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080886BE
	movs r1, #0
	bl VM_ExecByID
_080886BE:
	movs r3, #0xee
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _080886D6
	movs r0, #0
	strh r0, [r1]
_080886D6:
	ldrb r0, [r4, #0x1a]
	cmp r0, #5
	bne _080886F4
	ldr r1, _080886F0 @ =0x0000033A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080886F4
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _080886FC
	.align 2, 0
_080886F0: .4byte 0x0000033A
_080886F4:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
_080886FC:
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r1, r7, #0
	bl Map_StepNavPath
_08088708:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
