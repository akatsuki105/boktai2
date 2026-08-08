	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _0822AE28 @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r1, _0822AE2C @ =0x00000401
	mov sb, r1
	cmp r0, #0
	beq _0822ADCA
	ldr r2, _0822AE30 @ =0x00000201
	mov sb, r2
_0822ADCA:
	ldr r1, _0822AE34 @ =0x03003560
	ldr r0, _0822AE38 @ =0x03003530
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	bne _0822ADDC
	b _0822AF2A
_0822ADDC:
	ldr r1, [r5]
	adds r0, r1, #0
	mov r6, sb
	ands r0, r6
	cmp r0, #0
	beq _0822ADEA
	b _0822AF22
_0822ADEA:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	bne _0822ADF6
	b _0822AF22
_0822ADF6:
	ldr r6, [r5, #0xc]
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	bne _0822AEAC
	mov r7, sp
	movs r0, #0x1c
	adds r0, r0, r5
	mov ip, r0
	ldrh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	mov r1, ip
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822AE3C
	asrs r0, r0, #8
	b _0822AE42
	.align 2, 0
_0822AE28: .4byte 0x03002CF0
_0822AE2C: .4byte 0x00000401
_0822AE30: .4byte 0x00000201
_0822AE34: .4byte 0x03003560
_0822AE38: .4byte 0x03003530
_0822AE3C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822AE42:
	strh r0, [r7]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0822AE54
	asrs r0, r0, #8
	b _0822AE5A
_0822AE54:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822AE5A:
	adds r4, r0, #0
	mov r2, ip
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0822AE70
	asrs r0, r0, #8
	b _0822AE76
_0822AE70:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0822AE76:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0822AEA8 @ =0x030047C8
	ldrh r0, [r7]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r7]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r7, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r7, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r7, [r0, r1]
	movs r2, #2
	ldrsh r3, [r0, r2]
	movs r2, #4
	ldrsh r1, [r0, r2]
	mov r8, r1
	b _0822AEBA
	.align 2, 0
_0822AEA8: .4byte 0x030047C8
_0822AEAC:
	movs r0, #0x1c
	ldrsh r7, [r5, r0]
	movs r1, #0x1e
	ldrsh r3, [r5, r1]
	movs r0, #0x20
	ldrsh r2, [r5, r0]
	mov r8, r2
_0822AEBA:
	ldr r1, [r5]
	movs r0, #0x40
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	bne _0822AF16
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _0822AEDA
	movs r0, #0xa
	ldrsb r0, [r6, r0]
	adds r0, r7, r0
	ldrb r1, [r6, #8]
	subs r2, r0, r1
	b _0822AEE2
_0822AEDA:
	movs r0, #0xa
	ldrsb r0, [r6, r0]
	subs r2, r7, r0
	ldrb r1, [r6, #8]
_0822AEE2:
	mov ip, r1
	movs r0, #8
	ands r0, r4
	cmp r0, #0
	beq _0822AEF8
	movs r0, #0xb
	ldrsb r0, [r6, r0]
	adds r0, r3, r0
	ldrb r1, [r6, #9]
	subs r4, r0, r1
	b _0822AF00
_0822AEF8:
	movs r0, #0xb
	ldrsb r0, [r6, r0]
	subs r4, r3, r0
	ldrb r1, [r6, #9]
_0822AF00:
	cmp r2, #0xf0
	bgt _0822AF22
	cmp r4, #0xb4
	bgt _0822AF22
	mov r6, ip
	adds r0, r2, r6
	cmp r0, #0
	blt _0822AF22
	adds r0, r4, r1
	cmp r0, #0
	blt _0822AF22
_0822AF16:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r3, #0
	mov r3, r8
	bl FUN_0822a574
_0822AF22:
	ldr r5, [r5, #0x28]
	cmp r5, #0
	beq _0822AF2A
	b _0822ADDC
_0822AF2A:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
