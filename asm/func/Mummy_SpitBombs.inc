	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, [sp, #0x14]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _08127600 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	asrs r0, r0, #0x10
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0xa
	ldrsh r1, [r1, r2]
	subs r1, r0, r1
	cmp r1, #0xff
	bgt _08127604
	movs r6, #0xf
	b _0812762E
	.align 2, 0
_08127600: .4byte 0x0000FFFF
_08127604:
	ldr r0, _08127610 @ =0x000001FF
	cmp r1, r0
	bgt _08127614
	movs r6, #0x14
	b _0812762E
	.align 2, 0
_08127610: .4byte 0x000001FF
_08127614:
	ldr r0, _08127620 @ =0x000002FF
	cmp r1, r0
	bgt _08127624
	movs r6, #0x17
	b _0812762E
	.align 2, 0
_08127620: .4byte 0x000002FF
_08127624:
	ldr r0, _081276B4 @ =0x000003FF
	movs r6, #0x22
	cmp r1, r0
	bgt _0812762E
	movs r6, #0x1b
_0812762E:
	add r4, sp, #0xc
	adds r3, r5, #0
	adds r3, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	adds r1, r4, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r4, #0
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, r1, #0
	cmp r1, #0
	bge _08127668
	rsbs r3, r1, #0
_08127668:
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r2, r0, #0
	cmp r0, #0
	bge _08127674
	rsbs r2, r0, #0
_08127674:
	cmp r3, r2
	ble _0812767A
	adds r0, r1, #0
_0812767A:
	adds r1, r6, #0
	bl Div
	adds r4, r0, #0
	adds r0, r4, #0
	cmp r4, #0
	bge _0812768A
	rsbs r0, r4, #0
_0812768A:
	adds r4, r0, #0
	cmp r4, #0xa
	bgt _08127692
	movs r4, #0xa
_08127692:
	movs r1, #0xdf
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r4, r0
	ble _081276A0
	adds r4, r0, #0
_081276A0:
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081276B8
	cmp r0, #1
	beq _081276BC
	movs r3, #3
	b _081276BE
	.align 2, 0
_081276B4: .4byte 0x000003FF
_081276B8:
	movs r3, #1
	b _081276BE
_081276BC:
	movs r3, #2
_081276BE:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r2, r0, #6
	adds r1, #0xfd
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r1, r0, r2
	cmp r1, #0x80
	ble _081276E0
	ldr r0, _081276DC @ =0xFFFFFF00
	b _081276EC
	.align 2, 0
_081276DC: .4byte 0xFFFFFF00
_081276E0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081276EE
	movs r0, #0x80
	lsls r0, r0, #1
_081276EC:
	adds r1, r1, r0
_081276EE:
	adds r6, r1, #0
	adds r0, r6, #0
	cmp r6, #0
	bge _081276F8
	rsbs r0, r6, #0
_081276F8:
	cmp r0, #0x1c
	ble _08127700
	adds r6, r2, #0
	b _08127708
_08127700:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r6, [r0]
_08127708:
	ldr r2, _08127748 @ =0x000006FA
	adds r0, r7, r2
	ldrh r0, [r0]
	mov sb, r0
	cmp r3, #0
	beq _081277BE
	add r0, sp, #0xc
	mov r8, r0
	movs r1, #0xff
	mov sl, r1
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r7, r3, #0
	ldr r2, _0812774C @ =gSineTable
	adds r0, r0, r2
	str r0, [sp, #0x1c]
_0812772A:
	adds r0, r6, #0
	adds r0, #0x40
	mov r1, sl
	ands r0, r1
	lsls r0, r0, #1
	ldr r2, _0812774C @ =gSineTable
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08127750
	asrs r1, r0, #0xc
	b _08127756
	.align 2, 0
_08127748: .4byte 0x000006FA
_0812774C: .4byte gSineTable
_08127750:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08127756:
	movs r0, #0
	mov r2, r8
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, [sp, #0x1c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0812776E
	asrs r0, r0, #0xc
	b _08127774
_0812776E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08127774:
	mov r1, r8
	strh r0, [r1, #4]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	adds r2, #8
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r3, [r0]
	adds r1, #8
	adds r0, r5, r1
	ldrh r0, [r0]
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	add r0, sp, #0x14
	add r1, sp, #0xc
	bl Entity080dd1f8_Spawn
	mov r1, sb
	lsls r0, r1, #3
	movs r1, #0xa
	bl Div
	mov sb, r0
	lsls r0, r4, #2
	movs r1, #0xa
	bl Div
	adds r4, r4, r0
	subs r7, #1
	cmp r7, #0
	bne _0812772A
_081277BE:
	ldr r0, _081277D4 @ =0x00000101
	bl PlaySound_082406e0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081277D4: .4byte 0x00000101
