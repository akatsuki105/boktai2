	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r4, _08190684 @ =0x00000F36
	adds r0, r6, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r5, r0, #1
	cmp r5, #0
	blt _081906C4
	movs r4, #1
	mov r8, r4
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r5
	lsls r2, r0, #2
	adds r0, r2, #0
	adds r0, #0x98
	adds r3, r0, r1
	movs r4, #0x91
	lsls r4, r4, #1
	adds r0, r2, r4
	adds r4, r0, r1
_08190674:
	ldrh r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08190688
	movs r0, #1
	b _0819068A
	.align 2, 0
_08190684: .4byte 0x00000F36
_08190688:
	movs r0, #0
_0819068A:
	cmp r0, #0
	bne _081906B8
	adds r0, r3, #0
	bl Hitbox_Unregister
	ldrh r1, [r4]
	mov r0, r8
	orrs r0, r1
	strh r0, [r4]
	ldr r2, _081906B4 @ =0x00000F46
	adds r1, r6, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_08191774
	movs r0, #1
	b _081906C6
	.align 2, 0
_081906B4: .4byte 0x00000F46
_081906B8:
	ldr r0, _081906D0 @ =0xFFFFFEDC
	adds r3, r3, r0
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _08190674
_081906C4:
	movs r0, #0
_081906C6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081906D0: .4byte 0xFFFFFEDC
