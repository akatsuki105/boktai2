	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080AD56A
	mov r4, sp
	movs r5, #2
_080AD55C:
	bl VM_GetValue
	stm r4!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _080AD55C
	b _080AD58E
_080AD56A:
	ldr r0, _080AD67C @ =0x08251D7C
	bl FUN_08230860
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r0, _080AD680 @ =0x08251D98
	bl FUN_08230860
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, _080AD684 @ =0x08251DB4
	bl FUN_08230860
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
_080AD58E:
	movs r5, #0
	mov r6, sp
_080AD592:
	lsls r4, r5, #2
	ldm r6!, {r1}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080AD688 @ =0x000092B3
	bl GetFile
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r1, r1, r4
	adds r0, #0x14
	str r0, [r1]
	adds r5, #1
	cmp r5, #2
	ble _080AD592
	bl Time_GetSpanOfTime
	ldr r3, _080AD68C @ =0x00000C0B
	adds r1, r7, r3
	movs r4, #0
	strb r0, [r1]
	ldrb r1, [r1]
	adds r0, r7, #0
	bl FUN_080ad3e8
	ldr r1, _080AD690 @ =0x00001426
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _080AD694 @ =0x00001424
	adds r0, r7, r2
	strh r4, [r0]
	ldr r3, _080AD698 @ =0x0000022D
	adds r0, r7, r3
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	adds r6, r7, #0
	adds r6, #0x20
	mov r4, r8
	movs r5, #0xf
_080AD5EE:
	adds r0, r4, #0
	adds r1, r6, #0
	ldr r2, _080AD69C @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _080AD5EE
	ldr r6, _080AD6A0 @ =0x03004250
	mov r4, r8
	movs r5, #2
_080AD608:
	adds r0, r4, #0
	adds r1, r6, #0
	ldr r2, _080AD69C @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _080AD608
	movs r5, #2
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r0, r7, r3
_080AD624:
	strh r5, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080AD624
	movs r0, #0x95
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	beq _080AD664
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r1, _080AD6A4 @ =0x000002BE
	adds r2, r7, r1
	strh r0, [r2]
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r0, r7, r3
	subs r3, #0x53
	adds r1, r7, r3
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r2]
	subs r3, #0xa5
	adds r2, r2, r3
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
_080AD664:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	str r0, [r1]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD67C: .4byte 0x08251D7C
_080AD680: .4byte 0x08251D98
_080AD684: .4byte 0x08251DB4
_080AD688: .4byte 0x000092B3
_080AD68C: .4byte 0x00000C0B
_080AD690: .4byte 0x00001426
_080AD694: .4byte 0x00001424
_080AD698: .4byte 0x0000022D
_080AD69C: .4byte 0x04000008
_080AD6A0: .4byte 0x03004250
_080AD6A4: .4byte 0x000002BE
