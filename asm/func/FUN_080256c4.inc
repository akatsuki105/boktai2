	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sb, r1
	mov r8, r5
	adds r7, r5, #0
	adds r7, #0xcc
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025710
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl Boss_PlayAnim
	ldr r0, _08025764 @ =0x00000551
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r3, #0xaa
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	strb r4, [r2]
_08025710:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08025724
	b _08025820
_08025724:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025820
	adds r0, r5, #0
	adds r0, #0xd4
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	movs r2, #0
	cmp r1, r0
	bhi _0802574E
	movs r2, #1
_0802574E:
	cmp r2, #0
	beq _08025768
	ldrh r1, [r7]
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrh r1, [r7, #4]
	adds r0, #4
	strh r1, [r0]
	movs r4, #1
	b _080257C8
	.align 2, 0
_08025764: .4byte 0x00000551
_08025768:
	adds r0, r5, #0
	adds r0, #0xd8
	ldr r3, _08025794 @ =0x0000055C
	adds r1, r5, r3
	adds r4, r5, #0
	adds r4, #0x58
	ldr r3, [r0]
	ldrh r6, [r1]
	ldr r2, _08025798 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802579C
	asrs r1, r0, #0xc
	b _080257A2
	.align 2, 0
_08025794: .4byte 0x0000055C
_08025798: .4byte gSineTable
_0802579C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080257A2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _080257BE
	asrs r0, r0, #0xc
	b _080257C4
_080257BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080257C4:
	strh r0, [r4, #4]
	movs r4, #0
_080257C8:
	movs r0, #7
	mov r3, sb
	ands r0, r3
	cmp r0, #0
	bne _080257E4
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0xff
	bls _080257E4
	mov r0, r8
	bl FUN_08023de8
_080257E4:
	movs r1, #2
	ldrsh r0, [r7, r1]
	movs r3, #0xac
	lsls r3, r3, #1
	add r3, r8
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r2, r0, #0
	cmp r0, #0
	bge _080257FA
	rsbs r2, r0, #0
_080257FA:
	cmp r2, #0x1f
	bgt _08025810
	ldrh r0, [r7, #2]
	strh r0, [r3]
	cmp r4, #0
	beq _08025820
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08025820
_08025810:
	cmp r0, #0
	bge _0802581A
	adds r0, r1, #0
	subs r0, #0x20
	b _0802581E
_0802581A:
	adds r0, r1, #0
	adds r0, #0x20
_0802581E:
	strh r0, [r3]
_08025820:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
