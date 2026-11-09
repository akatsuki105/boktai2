	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov ip, r0
	ldr r4, _0814B7EC @ =0x0203B400
	ldr r3, _0814B7F0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0814B7F4 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0x1f
	add r6, sp, #4
	ands r4, r0
	ldr r1, _0814B7F8 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0814B7FC
	asrs r2, r0, #0xc
	b _0814B802
	.align 2, 0
_0814B7EC: .4byte 0x0203B400
_0814B7F0: .4byte 0x030046B8
_0814B7F4: .4byte 0x000003FF
_0814B7F8: .4byte gSineTable
_0814B7FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814B802:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0814B81A
	asrs r0, r0, #0xc
	b _0814B820
_0814B81A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814B820:
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0814B854 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0814B858 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x30
	add r1, sp, #4
	strh r0, [r1, #2]
	movs r0, #3
	str r0, [sp]
	mov r0, ip
	movs r2, #0x3c
	movs r3, #3
	bl Entity081ee2a0_SpawnEx
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814B854: .4byte 0x000003FF
_0814B858: .4byte 0x0203B400
