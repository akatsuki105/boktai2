	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	mov sb, r1
	adds r5, r2, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sl, r3
	ldr r0, _08232E44 @ =0x030046A4
	ldr r1, [r0]
	ldr r0, [r1, #4]
	cmp r0, #0
	beq _08232E74
	adds r6, r0, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r3, #0
	blt _08232E40
	cmp r2, #0
	blt _08232E40
	ldr r0, _08232E48 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08232E40
	ldr r0, _08232E4C @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _08232E50
_08232E40:
	movs r0, #0
	b _08232E5A
	.align 2, 0
_08232E44: .4byte 0x030046A4
_08232E48: .4byte 0x030046A8
_08232E4C: .4byte 0x030046AC
_08232E50:
	lsls r0, r2, #1
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r3
_08232E5A:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r1, r8
	ldrh r0, [r1, #6]
	cmp r0, r7
	beq _08232E74
	mov r0, sb
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232E78
_08232E74:
	movs r0, #0
	b _082332E6
_08232E78:
	mov r2, r8
	ldrh r1, [r2, #6]
	subs r2, r7, r1
	movs r0, #4
	ldrsh r3, [r6, r0]
	rsbs r0, r3, #0
	adds r0, #1
	adds r4, r1, #0
	cmp r2, r0
	bgt _08232E92
	adds r0, r2, #1
	adds r2, r0, r3
	b _08232EB0
_08232E92:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne _08232E9E
	movs r2, #3
	b _08232EB0
_08232E9E:
	cmp r2, #1
	bne _08232EA6
	movs r2, #4
	b _08232EB0
_08232EA6:
	subs r0, r3, #1
	cmp r2, r0
	blt _08232EB0
	adds r0, r2, #6
	subs r2, r0, r3
_08232EB0:
	cmp r2, #7
	bls _08232EB6
	b _082332E4
_08232EB6:
	lsls r0, r2, #2
	ldr r1, _08232EC0 @ =_08232EC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08232EC0: .4byte _08232EC4
_08232EC4: @ jump table
	.4byte _08232EE4 @ case 0
	.4byte _08232FEE @ case 1
	.4byte _08232FFE @ case 2
	.4byte _082330FE @ case 3
	.4byte _08233110 @ case 4
	.4byte _08233124 @ case 5
	.4byte _082331F8 @ case 6
	.4byte _08233200 @ case 7
_08232EE4:
	mov r2, r8
	ldrh r1, [r2, #4]
	adds r0, r7, #1
	cmp r1, r0
	bne _08232F78
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08232F74 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r4, sp
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232F24
	b _082332B2
_08232F24:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r4, #4]
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232F4E
	b _082332B2
_08232F4E:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
	.align 2, 0
_08232F74: .4byte 0xFFFF0000
_08232F78:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1, #4]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232FA0
	b _082332B2
_08232FA0:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232FCA
	b _082332B2
_08232FCA:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
_08232FEE:
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
_08232FFE:
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r7, #1
	cmp r1, r0
	bne _08233084
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08233034
	b _082332B2
_08233034:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r4, #4]
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _0823305E
	b _082332B2
_0823305E:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
_08233084:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1, #4]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _082330AC
	b _082332B2
_082330AC:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _082330D8
	b _082332B2
_082330D8:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
_082330FE:
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r5]
	b _082332E4
_08233110:
	movs r2, #4
	ldrsh r1, [r6, r2]
	adds r0, r4, #0
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r5]
	b _082332E4
_08233124:
	mov r0, r8
	ldrh r1, [r0, #4]
	adds r0, r7, #1
	cmp r1, r0
	bne _08233196
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r2, #4
	ldrsh r1, [r6, r2]
	adds r0, r4, #0
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08233158
	b _082332B2
_08233158:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r4, #4]
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08233184
	b _082332B2
_08233184:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	b _082332CE
_08233196:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1, #4]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	b _082332CE
_082331F8:
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	b _082332D8
_08233200:
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r7, #1
	cmp r1, r0
	bne _08233260
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r4, #4]
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	b _082332BC
_08233260:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1, #4]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _082332BC
_082332B2:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r5]
	str r1, [r5, #4]
	b _082332E4
_082332BC:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
_082332CE:
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
_082332D8:
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
_082332E2:
	strh r0, [r5, #4]
_082332E4:
	movs r0, #1
_082332E6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
