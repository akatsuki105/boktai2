	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802585E
	movs r3, #0
	strb r3, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r3, #1
	bl Boss_PlayAnim
_0802585E:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025936
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025936
	adds r0, r4, #0
	adds r0, #0xd4
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	movs r2, #0
	cmp r1, r0
	bhi _0802589A
	movs r2, #1
_0802589A:
	cmp r2, #0
	beq _080258AC
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x50]
	str r1, [r4, #0x54]
	b _0802590A
_080258AC:
	adds r0, r4, #0
	adds r0, #0xd8
	ldr r2, _080258D8 @ =0x0000055C
	adds r1, r4, r2
	adds r5, r4, #0
	adds r5, #0x58
	ldr r3, [r0]
	ldrh r6, [r1]
	ldr r2, _080258DC @ =gSineTable
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
	blt _080258E0
	asrs r1, r0, #0xc
	b _080258E6
	.align 2, 0
_080258D8: .4byte 0x0000055C
_080258DC: .4byte gSineTable
_080258E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080258E6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08025902
	asrs r0, r0, #0xc
	b _08025908
_08025902:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025908:
	strh r0, [r5, #4]
_0802590A:
	ldr r1, _08025940 @ =0x00000275
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08025936
	ldr r2, _08025944 @ =FUN_08025948
	movs r0, #4
	adds r3, r4, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08025936:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025940: .4byte 0x00000275
_08025944: .4byte FUN_08025948
