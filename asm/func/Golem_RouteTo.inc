	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	mov sb, r6
	mov r8, r6
	ldr r0, _08115630 @ =0x000004A4
	adds r4, r6, r0
	ldr r0, [r4]
	adds r1, r6, #0
	adds r1, #8
	movs r3, #0xda
	lsls r3, r3, #3
	adds r2, r6, r3
	bl Map_TryFindNavRoute
	adds r1, r0, #0
	cmp r1, #0
	bne _081155F0
	b _08115780
_081155F0:
	ldr r1, [r4]
	movs r4, #0x1c
	ldrsh r2, [r1, r4]
	movs r5, #8
	ldrsh r0, [r6, r5]
	subs r7, r2, r0
	movs r0, #0x20
	ldrsh r2, [r1, r0]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	subs r2, r2, r0
	ldrh r0, [r1, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0811562A
	cmp r1, #0
	blt _0811562A
	ldr r0, _08115634 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0811562A
	ldr r0, _08115638 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811563C
_0811562A:
	movs r4, #0
	mov ip, r4
	b _0811564C
	.align 2, 0
_08115630: .4byte 0x000004A4
_08115634: .4byte 0x030046A8
_08115638: .4byte 0x030046AC
_0811563C:
	ldr r0, _08115678 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r3
	mov ip, r0
_0811564C:
	mov r5, r8
	ldrh r1, [r5, #8]
	lsls r0, r1, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	adds r5, r1, #0
	cmp r4, #0
	blt _08115674
	cmp r3, #0
	blt _08115674
	ldr r0, _0811567C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08115674
	ldr r0, _08115680 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _08115684
_08115674:
	movs r0, #0
	b _08115692
	.align 2, 0
_08115678: .4byte 0x030046A4
_0811567C: .4byte 0x030046A8
_08115680: .4byte 0x030046AC
_08115684:
	ldr r0, _081156BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r4
_08115692:
	cmp ip, r0
	beq _081156DA
	adds r1, r7, #0
	cmp r7, #0
	bge _0811569E
	rsbs r1, r7, #0
_0811569E:
	adds r0, r2, #0
	cmp r2, #0
	bge _081156A6
	rsbs r0, r2, #0
_081156A6:
	cmp r1, r0
	bge _081156C8
	ldr r0, _081156C0 @ =0x000004A4
	add r0, sb
	ldr r1, [r0]
	ldr r0, _081156C4 @ =0xFFFFFF00
	ands r0, r5
	adds r0, #0x80
	strh r0, [r1, #0x1c]
	b _081156DA
	.align 2, 0
_081156BC: .4byte 0x030046A4
_081156C0: .4byte 0x000004A4
_081156C4: .4byte 0xFFFFFF00
_081156C8:
	ldr r0, _08115774 @ =0x000004A4
	add r0, sb
	ldr r2, [r0]
	mov r0, r8
	ldrh r1, [r0, #0xc]
	ldr r0, _08115778 @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2, #0x20]
_081156DA:
	ldr r5, _08115774 @ =0x000004A4
	add r5, sb
	ldr r2, [r5]
	movs r3, #0x1c
	ldrsh r1, [r2, r3]
	mov r4, r8
	movs r3, #8
	ldrsh r0, [r4, r3]
	subs r7, r1, r0
	movs r4, #0x20
	ldrsh r1, [r2, r4]
	mov r2, r8
	movs r3, #0xc
	ldrsh r0, [r2, r3]
	subs r2, r1, r0
	adds r0, r7, #0
	adds r1, r2, #0
	bl ArcTan2_8
	ldr r4, _0811577C @ =0x000006C2
	adds r7, r6, r4
	strb r0, [r7]
	ldrb r0, [r7]
	adds r0, #0x20
	movs r6, #0xff
	ands r0, r6
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r7]
	mov r4, sp
	mov r3, sb
	adds r3, #8
	ldr r0, [r5]
	adds r2, r0, #0
	adds r2, #0x1c
	ldrh r0, [r0, #0x1c]
	mov r5, sb
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	adds r2, r0, #0
	adds r0, #0x20
	ands r0, r6
	asrs r2, r0, #6
	mov r0, sp
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r5, #4
	ldrsh r0, [r4, r5]
	cmn r1, r0
	beq _08115786
	ldrb r0, [r7]
	lsrs r0, r0, #6
	cmp r2, r0
	beq _08115786
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08115786
	.align 2, 0
_08115774: .4byte 0x000004A4
_08115778: .4byte 0xFFFFFF00
_0811577C: .4byte 0x000006C2
_08115780:
	ldr r2, _08115798 @ =0x000006B4
	adds r0, r6, r2
	strh r1, [r0]
_08115786:
	movs r0, #1
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08115798: .4byte 0x000006B4
