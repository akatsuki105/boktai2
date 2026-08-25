	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0x20
	movs r1, #0
	strb r1, [r2]
	movs r7, #0
	ldr r2, _0800211C @ =0x00000664
	adds r1, r6, r2
	b _08002232
	.align 2, 0
_0800211C: .4byte 0x00000664
_08002120:
	lsls r1, r7, #1
	movs r3, #0xcd
	lsls r3, r3, #3
	adds r2, r6, r3
	adds r2, r2, r1
	ldrh r3, [r2]
	lsls r1, r7, #4
	movs r4, #0xcf
	lsls r4, r4, #3
	adds r1, r1, r4
	adds r4, r6, r1
	movs r5, #0
	strh r5, [r2]
	ldrb r1, [r6, #0x1b]
	cmp r1, #3
	bhi _080021FC
	subs r1, r3, #1
	cmp r1, #5
	bhi _0800222C
	lsls r1, r1, #2
	ldr r2, _08002150 @ =_08002154
	adds r1, r1, r2
	ldr r1, [r1]
	mov pc, r1
	.align 2, 0
_08002150: .4byte _08002154
_08002154: @ jump table
	.4byte _0800216C @ case 0
	.4byte _080021A4 @ case 1
	.4byte _080021C4 @ case 2
	.4byte _080021A4 @ case 3
	.4byte _080021C4 @ case 4
	.4byte _080021E0 @ case 5
_0800216C:
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r1, r1, #1
	ldr r2, _0800219C @ =0x00000634
	adds r0, r6, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _080021A0 @ =0x000092B3
	bl GetFile
	adds r1, r0, #0
	adds r1, #0x14
	str r1, [r6, #0x28]
	movs r2, #0
	movs r1, #1
	strb r1, [r6, #0x1b]
	strb r2, [r6, #0x1d]
	ldrh r1, [r4, #2]
	strb r1, [r6, #0x1c]
	ldrh r1, [r4, #4]
	strb r1, [r6, #0x1e]
	ldrh r1, [r4, #6]
	strb r1, [r6, #0x1f]
	b _0800222C
	.align 2, 0
_0800219C: .4byte 0x00000634
_080021A0: .4byte 0x000092B3
_080021A4:
	cmp r3, #2
	bne _080021AC
	strb r3, [r6, #0x1b]
	b _080021B0
_080021AC:
	movs r1, #4
	strb r1, [r6, #0x1b]
_080021B0:
	ldr r3, _080021C0 @ =0x0000063C
	adds r2, r6, r3
	movs r1, #0
	strh r1, [r2]
	ldrh r2, [r4]
	adds r3, #2
	b _08002210
	.align 2, 0
_080021C0: .4byte 0x0000063C
_080021C4:
	cmp r3, #3
	bne _080021CC
	strb r3, [r6, #0x1b]
	b _080021D0
_080021CC:
	movs r1, #5
	strb r1, [r6, #0x1b]
_080021D0:
	ldr r1, _080021DC @ =0x0000063C
	adds r2, r6, r1
	movs r1, #0
	strh r1, [r2]
	b _0800220C
	.align 2, 0
_080021DC: .4byte 0x0000063C
_080021E0:
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #5
	orrs r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	lsls r0, r0, #0xa
	orrs r1, r0
	adds r0, r6, #0
	bl FUN_08001a18
	b _0800222C
_080021FC:
	cmp r3, #4
	beq _08002204
	cmp r3, #5
	bne _0800222C
_08002204:
	strb r3, [r6, #0x1b]
	ldr r2, _080022E0 @ =0x0000063C
	adds r1, r6, r2
	strh r5, [r1]
_0800220C:
	ldrh r2, [r4]
	ldr r3, _080022E4 @ =0x0000063E
_08002210:
	adds r1, r6, r3
	strh r2, [r1]
	ldr r3, _080022E8 @ =0x03004494
	ldrh r2, [r4, #6]
	lsls r2, r2, #0xa
	ldrh r1, [r4, #4]
	lsls r1, r1, #5
	orrs r2, r1
	ldrh r1, [r4, #2]
	orrs r2, r1
	strh r2, [r3]
	ldr r2, _080022EC @ =0x03004454
	ldrh r1, [r4, #8]
	strh r1, [r2]
_0800222C:
	adds r7, #1
	ldr r4, _080022F0 @ =0x00000664
	adds r1, r6, r4
_08002232:
	ldr r1, [r1]
	cmp r7, r1
	bhs _0800223A
	b _08002120
_0800223A:
	ldr r7, _080022F0 @ =0x00000664
	adds r1, r6, r7
	movs r4, #0
	str r4, [r1]
	ldrb r2, [r6, #0x1a]
	movs r1, #1
	ands r1, r2
	cmp r1, #0
	beq _0800230C
	ldr r0, _080022F4 @ =0x0000064C
	adds r0, r0, r6
	mov r8, r0
	ldr r7, _080022F8 @ =gClock
	ldrh r0, [r0]
	ldrb r1, [r7, #0xe]
	cmp r0, r1
	beq _080022A2
	mov r5, sp
	adds r5, #2
	mov r0, sp
	adds r1, r5, #0
	bl FUN_0823ce10
	movs r2, #0xc8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	movs r3, #0xc9
	lsls r3, r3, #3
	adds r0, r6, r3
	strh r4, [r0]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldr r1, _080022FC @ =0x00000634
	adds r4, r6, r1
	adds r0, r4, r0
	ldrh r1, [r0]
	ldr r0, _08002300 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	ldr r0, _08002300 @ =0x000092B3
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x28]
_080022A2:
	ldrb r0, [r7, #0xe]
	mov r2, r8
	strh r0, [r2]
	ldrb r1, [r7, #0xf]
	ldr r3, _08002304 @ =0x0000064E
	adds r0, r6, r3
	strh r1, [r0]
	adds r0, r6, #0
	adds r0, #0x34
	str r0, [r6, #0x30]
	movs r7, #0xc8
	lsls r7, r7, #3
	adds r4, r6, r7
	ldrb r0, [r4]
	cmp r0, #0x3f
	bhi _080022C8
	adds r0, r6, #0
	bl FUN_08001bd0
_080022C8:
	adds r0, r6, #0
	bl FUN_08001c10
	adds r0, r6, #0
	bl FUN_08001a34
	ldrb r2, [r4]
	ldr r3, _08002308 @ =0x00000641
	adds r1, r6, r3
	strb r2, [r1]
	b _080023B4
	.align 2, 0
_080022E0: .4byte 0x0000063C
_080022E4: .4byte 0x0000063E
_080022E8: .4byte 0x03004494
_080022EC: .4byte 0x03004454
_080022F0: .4byte 0x00000664
_080022F4: .4byte 0x0000064C
_080022F8: .4byte gClock
_080022FC: .4byte 0x00000634
_08002300: .4byte 0x000092B3
_08002304: .4byte 0x0000064E
_08002308: .4byte 0x00000641
_0800230C:
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _080023B4
	ldr r4, _08002364 @ =0x0000065E
	adds r5, r6, r4
	ldrh r1, [r5]
	adds r4, r1, #0
	cmp r4, #0
	bne _080023A0
	movs r7, #0xca
	lsls r7, r7, #3
	adds r3, r6, r7
	ldrh r1, [r3]
	adds r1, #1
	strh r1, [r3]
	adds r7, #2
	adds r2, r6, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r2]
	cmp r1, r2
	blo _080023A4
	strh r4, [r3]
	ldr r1, _08002368 @ =0x00000654
	adds r2, r6, r1
	adds r7, #4
	adds r3, r6, r7
	ldrh r1, [r3]
	ldrh r7, [r2]
	adds r1, r1, r7
	strh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0
	bgt _0800236C
	strh r4, [r2]
	ldrh r1, [r3]
	rsbs r1, r1, #0
	strh r1, [r3]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r6, r2
	b _0800237E
	.align 2, 0
_08002364: .4byte 0x0000065E
_08002368: .4byte 0x00000654
_0800236C:
	cmp r1, #0x3f
	ble _08002382
	movs r1, #0x40
	strh r1, [r2]
	ldrh r1, [r3]
	rsbs r1, r1, #0
	strh r1, [r3]
	ldr r3, _08002398 @ =0x00000662
	adds r1, r6, r3
_0800237E:
	ldrh r1, [r1]
	strh r1, [r5]
_08002382:
	ldr r4, _0800239C @ =0x0000065A
	adds r2, r6, r4
	movs r3, #0
	movs r1, #1
	strb r1, [r2]
	movs r7, #0xcb
	lsls r7, r7, #3
	adds r1, r6, r7
	strb r3, [r1]
	b _080023A4
	.align 2, 0
_08002398: .4byte 0x00000662
_0800239C: .4byte 0x0000065A
_080023A0:
	subs r1, #1
	strh r1, [r5]
_080023A4:
	ldr r2, _080023D4 @ =0x0000065A
	adds r1, r6, r2
	ldrb r1, [r1]
	cmp r1, #0
	beq _080023B4
	adds r0, r6, #0
	bl FUN_08001cbc
_080023B4:
	ldr r2, _080023D8 @ =0x085AA634
	ldrb r1, [r6, #0x1b]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _080023C8
	adds r0, r6, #0
	bl _call_via_r1
_080023C8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080023D4: .4byte 0x0000065A
_080023D8: .4byte 0x085AA634
