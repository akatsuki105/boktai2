	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r1
	ldr r0, _08062014 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08062018 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, _0806201C @ =0x0000085E
	adds r1, r7, r3
	adds r0, #2
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _08061F9A
	b _080620CC
_08061F9A:
	subs r3, #1
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r6, r7, r0
	mov r8, r6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	ldr r2, _08062020 @ =0x00000858
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r3, _08062024 @ =0x0203B400
	mov ip, r3
	ldr r3, _08062028 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0806202C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	add r1, ip
	movs r5, #0xff
	ldrb r4, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r2, r0, #0
	adds r2, #0x80
	ldr r1, _08062030 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _08062034
	asrs r0, r0, #0xc
	b _0806203A
	.align 2, 0
_08062014: .4byte 0x030046A0
_08062018: .4byte 0x00000942
_0806201C: .4byte 0x0000085E
_08062020: .4byte 0x00000858
_08062024: .4byte 0x0203B400
_08062028: .4byte 0x030046B8
_0806202C: .4byte 0x000003FF
_08062030: .4byte 0x085B0A08
_08062034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806203A:
	strh r0, [r6, #0x2c]
	ldr r0, _08062050 @ =0x085B0A08
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08062054
	asrs r0, r0, #0xc
	b _0806205A
	.align 2, 0
_08062050: .4byte 0x085B0A08
_08062054:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806205A:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, r8
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r2, #0x1c]
	adds r0, r0, r2
	mov r1, r8
	strh r0, [r1, #0x1c]
	ldr r2, _080620D8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080620DC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080620E0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #0xe
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080620E4 @ =0x0000085D
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080620BC
	strb r3, [r1]
_080620BC:
	ldr r1, _080620E8 @ =0x0000085E
	adds r0, r7, r1
	ldrb r1, [r0]
	subs r1, #0x28
	strb r1, [r0]
	ldr r3, _080620EC @ =0x0000085C
	adds r0, r7, r3
	strb r2, [r0]
_080620CC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080620D8: .4byte 0x030046B8
_080620DC: .4byte 0x000003FF
_080620E0: .4byte 0x0203B400
_080620E4: .4byte 0x0000085D
_080620E8: .4byte 0x0000085E
_080620EC: .4byte 0x0000085C
