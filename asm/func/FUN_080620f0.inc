	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	ldr r1, _08062190 @ =0x0000085E
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r1, #0xff
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08062114
	b _08062236
_08062114:
	ldr r0, _08062194 @ =0x0000085D
	add r0, r8
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r0, r1
	mov r2, r8
	adds r6, r2, r0
	adds r7, r6, #0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08062198 @ =0x00000858
	add r0, r8
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #4
	bl FUN_0822dafc
	ldr r3, _0806219C @ =0x0203B400
	mov ip, r3
	ldr r3, _080621A0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080621A4 @ =0x000003FF
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
	movs r1, #0x7f
	ands r0, r1
	adds r1, #0x81
	adds r2, r0, r1
	ldr r1, _080621A8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080621AC
	asrs r0, r0, #0xc
	b _080621B2
	.align 2, 0
_08062190: .4byte 0x0000085E
_08062194: .4byte 0x0000085D
_08062198: .4byte 0x00000858
_0806219C: .4byte 0x0203B400
_080621A0: .4byte 0x030046B8
_080621A4: .4byte 0x000003FF
_080621A8: .4byte 0x085B0A08
_080621AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080621B2:
	strh r0, [r6, #0x2c]
	ldr r0, _080621C8 @ =0x085B0A08
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _080621CC
	asrs r0, r0, #0xc
	b _080621D2
	.align 2, 0
_080621C8: .4byte 0x085B0A08
_080621CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080621D2:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x18]
	str r1, [r7, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r7, #0x18]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldr r2, _08062244 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08062248 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0806224C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x1c
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _08062250 @ =0x0000085C
	add r0, r8
	strb r1, [r0]
	ldr r1, _08062254 @ =0x0000085D
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _08062236
	strb r3, [r1]
_08062236:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062244: .4byte 0x030046B8
_08062248: .4byte 0x000003FF
_0806224C: .4byte 0x0203B400
_08062250: .4byte 0x0000085C
_08062254: .4byte 0x0000085D
