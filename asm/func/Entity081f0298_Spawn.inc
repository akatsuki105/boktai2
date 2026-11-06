	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	adds r7, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, _081F0130 @ =0x030001E0
	ldr r6, [r0]
	cmp r6, #0
	bne _081F00C0
	bl Entity081f0298_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081F00C0
	b _081F01BE
_081F00C0:
	adds r0, r6, #0
	bl FUN_081f0088
	adds r5, r0, #0
	cmp r5, #0
	beq _081F01BE
	adds r0, #0x96
	movs r1, #0
	movs r2, #1
	mov sl, r2
	mov r2, sl
	strb r2, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r4, r5, #0
	adds r4, #0x9b
	strb r7, [r4]
	adds r0, #4
	strh r1, [r0]
	ldr r0, [sp, #0x30]
	str r0, [sp]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	ldr r3, [sp, #0x2c]
	bl Entity081f0298_InitHitbox
	adds r7, r5, #0
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	add r3, sp, #4
	mov r2, sp
	adds r2, #5
	ldrb r0, [r4]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	mov r8, r4
	adds r4, r2, #0
	cmp r1, #1
	bls _081F0134
	mov r0, sl
	strb r0, [r4]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081F013A
	.align 2, 0
_081F0130: .4byte 0x030001E0
_081F0134:
	movs r0, #0
	strb r0, [r4]
	strb r1, [r3]
_081F013A:
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r6, #0x34]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0x12
	bl AuxAnim_SetAnim
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r2, _081F0178 @ =gSineTable
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x34]
	muls r0, r1, r0
	cmp r0, #0
	blt _081F017C
	asrs r0, r0, #0xc
	b _081F0182
	.align 2, 0
_081F0178: .4byte gSineTable
_081F017C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F0182:
	strh r0, [r5, #0x3c]
	ldr r0, _081F01A0 @ =gSineTable
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r1, [sp, #0x34]
	muls r0, r1, r0
	cmp r0, #0
	blt _081F01A4
	asrs r4, r0, #0xc
	b _081F01AA
	.align 2, 0
_081F01A0: .4byte gSineTable
_081F01A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_081F01AA:
	adds r0, r5, #0
	adds r0, #0x40
	strh r4, [r0]
	movs r0, #0xa
	strh r0, [r5, #0x3e]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	strb r1, [r7, #7]
_081F01BE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
