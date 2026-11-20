	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0819D684 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D688
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D68A
	.align 2, 0
_0819D684: .4byte 0x0000046C
_0819D688:
	movs r0, #0
_0819D68A:
	cmp r0, #0
	beq _0819D6D0
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r6, _0819D734 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r6, _0819D738 @ =0x00000E52
	adds r1, r4, r6
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
_0819D6D0:
	adds r0, r5, #0
	bl Ax_SpawnAfterimage
	ldr r1, _0819D738 @ =0x00000E52
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r1, r0
	bls _0819D77A
	ldr r0, _0819D73C @ =0x03002BE0
	mov r2, sp
	ldr r1, [r0]
	adds r4, r1, #0
	adds r4, #0x2c
	adds r3, r5, #0
	adds r3, #8
	ldrh r0, [r5, #8]
	ldrh r1, [r1, #0x2c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r6, #4
	ldrsh r1, [r2, r6]
	bl ArcTan2_8
	adds r4, r0, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819D744
	ldr r0, _0819D740 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819D752
	.align 2, 0
_0819D734: .4byte 0x0000046D
_0819D738: .4byte 0x00000E52
_0819D73C: .4byte 0x03002BE0
_0819D740: .4byte 0xFFFFFF00
_0819D744:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819D752
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0819D752:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819D75A
	rsbs r0, r0, #0
_0819D75A:
	cmp r0, #0x3f
	bgt _0819D762
	adds r4, #0x40
	b _0819D764
_0819D762:
	adds r4, #0xc0
_0819D764:
	movs r0, #0xff
	ands r4, r0
	movs r0, #0x20
	movs r1, #8
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bgt _0819D7F6
	movs r2, #2
	b _0819D7F6
_0819D77A:
	ldr r0, _0819D7C0 @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r6, #4
	ldrsh r1, [r2, r6]
	bl ArcTan2_8
	adds r4, r0, #0
	ldrb r0, [r5, #5]
	subs r1, r4, r0
	cmp r1, #0x80
	ble _0819D7C8
	ldr r0, _0819D7C4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819D7D6
	.align 2, 0
_0819D7C0: .4byte 0x03002BE0
_0819D7C4: .4byte 0xFFFFFF00
_0819D7C8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819D7D6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0819D7D6:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819D7DE
	rsbs r0, r0, #0
_0819D7DE:
	cmp r0, #0
	blt _0819D7E6
	asrs r0, r0, #3
	b _0819D7EC
_0819D7E6:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0819D7EC:
	adds r2, r0, #0
	cmp r0, #0
	bgt _0819D7F4
	movs r0, #2
_0819D7F4:
	adds r2, r0, #0
_0819D7F6:
	ldrb r0, [r5, #5]
	subs r1, r4, r0
	cmp r1, #0x80
	ble _0819D808
	ldr r3, _0819D804 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0819D816
	.align 2, 0
_0819D804: .4byte 0xFFFFFF00
_0819D808:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819D816
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_0819D816:
	cmp r1, #0
	ble _0819D820
	ldrb r0, [r5, #5]
	adds r0, r0, r2
	b _0819D824
_0819D820:
	ldrb r0, [r5, #5]
	subs r0, r0, r2
_0819D824:
	strb r0, [r5, #5]
	add r3, sp, #8
	ldrb r4, [r5, #5]
	ldr r2, _0819D848 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0819D84C
	asrs r1, r0, #0xc
	b _0819D852
	.align 2, 0
_0819D848: .4byte gSineTable
_0819D84C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819D852:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0819D86C
	asrs r0, r0, #0xc
	b _0819D872
_0819D86C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819D872:
	strh r0, [r3, #4]
	ldr r2, [r5, #0x44]
	ldrb r1, [r5, #5]
	movs r0, #0x9f
	subs r0, r0, r1
	strb r0, [r2, #6]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r5, #0x10]
	str r1, [r5, #0x14]
	ldr r3, _0819D898 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819D898: .4byte 0x00000484
