	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0822ACE4 @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r1, _0822ACE8 @ =0x00000401
	mov sl, r1
	cmp r0, #0
	beq _0822ACAE
	ldr r2, _0822ACEC @ =0x00000201
	mov sl, r2
_0822ACAE:
	ldr r1, _0822ACF0 @ =0x03003560
	ldr r0, _0822ACF4 @ =0x03003530
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0822AD9C
_0822ACBE:
	ldr r1, [r4]
	adds r0, r1, #0
	mov r5, sl
	ands r0, r5
	mov ip, r1
	cmp r0, #0
	bne _0822AD96
	ldr r3, [r4, #0xc]
	movs r0, #0x1c
	ldrsh r2, [r4, r0]
	ldr r1, _0822ACF8 @ =0x03003540
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _0822ACFC
	asrs r0, r0, #3
	b _0822AD02
	.align 2, 0
_0822ACE4: .4byte 0x03002CF0
_0822ACE8: .4byte 0x00000401
_0822ACEC: .4byte 0x00000201
_0822ACF0: .4byte 0x03003560
_0822ACF4: .4byte 0x03003530
_0822ACF8: .4byte 0x03003540
_0822ACFC:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0822AD02:
	adds r0, #0x78
	mov r8, r0
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r5, #2
	ldrsh r0, [r2, r5]
	subs r0, r1, r0
	cmp r0, #0
	blt _0822AD18
	asrs r0, r0, #3
	b _0822AD1E
_0822AD18:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0822AD1E:
	adds r7, r0, #0
	adds r7, #0x5a
	movs r0, #0x20
	ldrsh r1, [r4, r0]
	movs r5, #4
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	mov sb, r1
	movs r0, #0x40
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	bne _0822AD8A
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0822AD4E
	movs r0, #0xa
	ldrsb r0, [r3, r0]
	add r0, r8
	ldrb r1, [r3, #8]
	subs r5, r0, r1
	adds r6, r1, #0
	b _0822AD58
_0822AD4E:
	movs r0, #0xa
	ldrsb r0, [r3, r0]
	mov r2, r8
	subs r5, r2, r0
	ldrb r6, [r3, #8]
_0822AD58:
	movs r0, #8
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _0822AD6E
	movs r0, #0xb
	ldrsb r0, [r3, r0]
	adds r0, r7, r0
	ldrb r1, [r3, #9]
	subs r2, r0, r1
	b _0822AD76
_0822AD6E:
	movs r0, #0xb
	ldrsb r0, [r3, r0]
	subs r2, r7, r0
	ldrb r1, [r3, #9]
_0822AD76:
	cmp r5, #0xf0
	bgt _0822AD96
	cmp r2, #0xb4
	bgt _0822AD96
	adds r0, r5, r6
	cmp r0, #0
	blt _0822AD96
	adds r0, r2, r1
	cmp r0, #0
	blt _0822AD96
_0822AD8A:
	adds r0, r4, #0
	mov r1, r8
	adds r2, r7, #0
	mov r3, sb
	bl FUN_0822a574
_0822AD96:
	ldr r4, [r4, #0x28]
	cmp r4, #0
	bne _0822ACBE
_0822AD9C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
