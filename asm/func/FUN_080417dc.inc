	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _08041874 @ =0x03002B50
	ldr r2, [r0]
	cmp r2, #0
	bne _080417F4
	b _08041906
_080417F4:
	ldr r0, _08041878 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08041804
	b _08041906
_08041804:
	ldr r2, [r2, #0x1c]
	mov r8, r2
	cmp r2, #0
	beq _08041906
	ldr r0, _0804187C @ =0x085B0A08
	mov sl, r0
	add r7, sp, #8
_08041812:
	movs r1, #0x80
	lsls r1, r1, #5
	mov r2, r8
	ldrh r0, [r2, #0xe]
	ands r0, r1
	cmp r0, #0
	beq _080418F8
	mov r6, r8
	adds r6, #0x64
	adds r2, r5, #0
	adds r2, #8
	movs r3, #8
	ldrsh r1, [r5, r3]
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r4, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r3, #4
	ldrsh r0, [r6, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08041880 @ =0x0000270F
	mov sb, r2
	cmp r1, r0
	bgt _080418F8
	adds r0, r4, #0
	adds r1, r3, #0
	bl ArcTan2_8
	add r2, sp, #8
	adds r3, r0, #0
	movs r4, #0x64
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08041884
	asrs r1, r0, #0xc
	b _0804188A
	.align 2, 0
_08041874: .4byte 0x03002B50
_08041878: .4byte 0x030047A4
_0804187C: .4byte 0x085B0A08
_08041880: .4byte 0x0000270F
_08041884:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0804188A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	add r0, sl
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _080418A6
	asrs r0, r0, #0xc
	b _080418AC
_080418A6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080418AC:
	strh r0, [r2, #4]
	ldrh r2, [r6]
	ldrh r0, [r7]
	adds r2, r2, r0
	strh r2, [r7]
	ldrh r3, [r7, #2]
	ldrh r0, [r6, #2]
	adds r3, r3, r0
	strh r3, [r7, #2]
	ldrh r1, [r6, #4]
	ldrh r0, [r7, #4]
	adds r1, r1, r0
	strh r1, [r7, #4]
	adds r4, r5, #0
	adds r4, #0x10
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	strh r2, [r5, #0x10]
	mov r2, sb
	ldrh r0, [r2, #2]
	subs r3, r3, r0
	strh r3, [r4, #2]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	ldr r1, [r5, #0x18]
	cmp r1, #0
	beq _080418F8
	ldrh r3, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	str r0, [sp]
	ldrb r0, [r5, #4]
	str r0, [sp, #4]
	adds r0, r1, #0
	mov r1, sb
	adds r2, r4, #0
	bl FUN_0823349c
_080418F8:
	movs r0, #0xbb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _08041812
_08041906:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
