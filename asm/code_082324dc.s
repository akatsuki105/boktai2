	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_082326d8
FUN_082326d8: @ 0x082326D8
	push {r4, r5, lr}
	ldr r3, _082326E8 @ =0x030046A4
	ldr r2, [r3]
	cmp r2, #0
	bne _082326EC
	movs r0, #0
	b _0823272C
	.align 2, 0
_082326E8: .4byte 0x030046A4
_082326EC:
	movs r0, #0
	str r0, [r2, #4]
	str r0, [r2, #8]
	str r0, [r2, #0xc]
	str r0, [r2, #0x10]
	str r0, [r2, #0x18]
	ldr r1, _08232734 @ =0x030046B0
	str r0, [r1]
	strh r0, [r2]
	movs r4, #0
	adds r5, r3, #0
_08232702:
	movs r0, #0x2c
	adds r1, r4, #0
	muls r1, r0, r1
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, [r5]
	adds r0, r0, r1
	bl FUN_08234bd8
	ldr r1, [r5]
	lsls r0, r4, #2
	ldr r2, _08232738 @ =0x00000D24
	adds r1, r1, r2
	adds r1, r1, r0
	movs r0, #0
	str r0, [r1]
	adds r4, #1
	cmp r4, #0x3f
	ble _08232702
	movs r0, #1
_0823272C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08232734: .4byte 0x030046B0
_08232738: .4byte 0x00000D24

	thumb_func_start FUN_0823273c
FUN_0823273c: @ 0x0823273C
	ldr r0, _08232758 @ =0x030046A4
	ldr r1, [r0]
	ldr r2, [r1, #4]
	ldrh r0, [r2, #4]
	rsbs r0, r0, #0
	strh r0, [r1, #0x1c]
	movs r0, #1
	strh r0, [r1, #0x1e]
	ldrh r0, [r2, #4]
	strh r0, [r1, #0x20]
	ldr r0, _0823275C @ =0x0000FFFF
	strh r0, [r1, #0x22]
	bx lr
	.align 2, 0
_08232758: .4byte 0x030046A4
_0823275C: .4byte 0x0000FFFF

	thumb_func_start FUN_08232760
FUN_08232760: @ 0x08232760
	push {r4, r5, r6, r7, lr}
	ldr r5, _08232798 @ =0x030046A4
	ldr r0, [r5]
	ldr r1, [r0, #4]
	movs r2, #4
	ldrsh r6, [r1, r2]
	adds r4, r0, #0
	adds r4, #0x24
	movs r3, #0
	movs r2, #0
	movs r7, #6
	ldrsh r0, [r1, r7]
	cmp r2, r0
	bge _08232792
	adds r1, r4, #0
_0823277E:
	strh r3, [r1]
	adds r3, r3, r6
	adds r1, #2
	adds r2, #1
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r4, #6
	ldrsh r0, [r0, r4]
	cmp r2, r0
	blt _0823277E
_08232792:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08232798: .4byte 0x030046A4

	thumb_func_start FUN_0823279c
FUN_0823279c: @ 0x0823279C
	ldr r1, _082327B4 @ =0x030046A8
	ldr r0, _082327B8 @ =0x030046A4
	ldr r0, [r0]
	ldr r2, [r0, #4]
	movs r3, #4
	ldrsh r0, [r2, r3]
	str r0, [r1]
	ldr r1, _082327BC @ =0x030046AC
	movs r3, #6
	ldrsh r0, [r2, r3]
	str r0, [r1]
	bx lr
	.align 2, 0
_082327B4: .4byte 0x030046A8
_082327B8: .4byte 0x030046A4
_082327BC: .4byte 0x030046AC

	thumb_func_start FUN_082327c0
FUN_082327c0: @ 0x082327C0
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _082327E8 @ =0x0000AE1B
	bl FUN_082310cc
	ldr r1, _082327EC @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #4]
	bl FUN_0823273c
	bl FUN_08232760
	bl FUN_0823279c
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_082327E8: .4byte 0x0000AE1B
_082327EC: .4byte 0x030046A4

	thumb_func_start FUN_082327f0
FUN_082327f0: @ 0x082327F0
	push {lr}
	ldr r1, _08232808 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #4]
	bl FUN_0823273c
	bl FUN_08232760
	bl FUN_0823279c
	pop {r0}
	bx r0
	.align 2, 0
_08232808: .4byte 0x030046A4

	thumb_func_start FUN_0823280c
FUN_0823280c: @ 0x0823280C
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, _08232844 @ =0x030046A4
	ldr r4, [r0]
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _08232880
	adds r5, r0, #0
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232840
	cmp r1, #0
	blt _08232840
	ldr r0, _08232848 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232840
	ldr r0, _0823284C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232850
_08232840:
	movs r0, #0
	b _0823285C
	.align 2, 0
_08232844: .4byte 0x030046A4
_08232848: .4byte 0x030046A8
_0823284C: .4byte 0x030046AC
_08232850:
	lsls r0, r1, #1
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r2
_0823285C:
	strh r0, [r3, #6]
	strh r0, [r3, #4]
	ldrh r0, [r3, #6]
	lsls r0, r0, #2
	adds r0, #0xc
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r2, #0xf
	ands r2, r1
	strb r2, [r3, #9]
	ldrb r1, [r0]
	lsrs r1, r1, #4
	strb r1, [r3, #0xb]
	ldrh r0, [r0, #2]
	strh r0, [r3, #0xe]
	strb r2, [r3, #8]
	strb r1, [r3, #0xa]
	strh r0, [r3, #0xc]
_08232880:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08232888
FUN_08232888: @ 0x08232888
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	adds r6, r1, #0
	movs r4, #0
	ldr r0, _082328E8 @ =0x030046A4
	ldr r0, [r0]
	adds r0, #0x1c
	mov sl, r0
	movs r0, #0xff
	mov sb, r0
	movs r5, #0xc0
	movs r1, #3
	mov r8, r1
_082328AA:
	adds r0, r4, #0
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sl
	movs r7, #0
	ldrsh r1, [r0, r7]
	mov r2, ip
	movs r3, #0
	adds r0, r5, #0
	mov r7, sb
	ands r0, r7
_082328C2:
	adds r2, r2, r1
	cmp r2, r6
	beq _082328DA
	adds r3, #1
	cmp r3, #3
	ble _082328C2
	adds r5, #0x40
	adds r4, #1
	cmp r4, #3
	ble _082328AA
	movs r0, #1
	rsbs r0, r0, #0
_082328DA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082328E8: .4byte 0x030046A4

	thumb_func_start FUN_082328ec
FUN_082328ec: @ 0x082328EC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232914
	cmp r1, #0
	blt _08232914
	ldr r0, _08232918 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232914
	ldr r0, _0823291C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232920
_08232914:
	movs r4, #0
	b _0823292E
	.align 2, 0
_08232918: .4byte 0x030046A8
_0823291C: .4byte 0x030046AC
_08232920:
	ldr r0, _08232940 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823292E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232944
	adds r0, #4
	b _08232950
	.align 2, 0
_08232940: .4byte 0x030046A4
_08232944:
	ldr r0, _08232964 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08232950:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08232968
	cmp r2, #2
	beq _0823296C
	b _08232970
	.align 2, 0
_08232964: .4byte 0x030046A4
_08232968:
	ldrb r0, [r5, #4]
	b _0823296E
_0823296C:
	ldrb r0, [r5]
_0823296E:
	subs r1, r1, r0
_08232970:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823297C:
	.byte 0x10, 0xB5, 0x02, 0x1C
	.byte 0x03, 0x48, 0x01, 0x68, 0x48, 0x68, 0x00, 0x28, 0x04, 0xD1, 0x00, 0x20, 0x24, 0xE0, 0x00, 0x00
	.byte 0xA4, 0x46, 0x00, 0x03, 0x04, 0x1C, 0x10, 0x88, 0x00, 0x04, 0x03, 0x16, 0x90, 0x88, 0x00, 0x04
	.byte 0x02, 0x16, 0x00, 0x2B, 0x09, 0xDB, 0x00, 0x2A, 0x07, 0xDB, 0x05, 0x48, 0x00, 0x68, 0x83, 0x42
	.byte 0x03, 0xD2, 0x04, 0x48, 0x00, 0x68, 0x82, 0x42, 0x06, 0xD3, 0x00, 0x20, 0x09, 0xE0, 0x00, 0x00
	.byte 0xA8, 0x46, 0x00, 0x03, 0xAC, 0x46, 0x00, 0x03, 0x50, 0x00, 0x24, 0x31, 0x09, 0x18, 0x08, 0x88
	.byte 0xC0, 0x18, 0x80, 0x00, 0x00, 0x19, 0xC0, 0x89, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_082329e0
FUN_082329e0: @ 0x082329E0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232A0A
	cmp r1, #0
	blt _08232A0A
	ldr r0, _08232A10 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232A0A
	ldr r0, _08232A14 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232A18
_08232A0A:
	movs r4, #0
	b _08232A26
	.align 2, 0
_08232A10: .4byte 0x030046A8
_08232A14: .4byte 0x030046AC
_08232A18:
	ldr r0, _08232A38 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08232A26:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232A3C
	adds r0, #4
	b _08232A48
	.align 2, 0
_08232A38: .4byte 0x030046A4
_08232A3C:
	ldr r0, _08232A5C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08232A48:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08232A60
	cmp r2, #2
	beq _08232A64
	b _08232A68
	.align 2, 0
_08232A5C: .4byte 0x030046A4
_08232A60:
	ldrb r0, [r5, #4]
	b _08232A66
_08232A64:
	ldrb r0, [r5]
_08232A66:
	subs r1, r1, r0
_08232A68:
	adds r5, r1, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232A8E
	cmp r1, #0
	blt _08232A8E
	ldr r0, _08232A94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232A8E
	ldr r0, _08232A98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232A9C
_08232A8E:
	movs r4, #0
	b _08232AAA
	.align 2, 0
_08232A94: .4byte 0x030046A8
_08232A98: .4byte 0x030046AC
_08232A9C:
	ldr r0, _08232ABC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08232AAA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232AC0
	adds r0, #4
	b _08232ACC
	.align 2, 0
_08232ABC: .4byte 0x030046A4
_08232AC0:
	ldr r0, _08232AE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08232ACC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08232AE4
	cmp r2, #2
	beq _08232AE8
	b _08232AEC
	.align 2, 0
_08232AE0: .4byte 0x030046A4
_08232AE4:
	ldrb r0, [r6, #4]
	b _08232AEA
_08232AE8:
	ldrb r0, [r6]
_08232AEA:
	subs r1, r1, r0
_08232AEC:
	subs r0, r5, r1
	cmp r0, #0
	bge _08232AF4
	rsbs r0, r0, #0
_08232AF4:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08232b00
FUN_08232b00: @ 0x08232B00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232B36
	cmp r1, #0
	blt _08232B36
	ldr r0, _08232B3C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232B36
	ldr r0, _08232B40 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232B44
_08232B36:
	movs r0, #0
	b _08232B52
	.align 2, 0
_08232B3C: .4byte 0x030046A8
_08232B40: .4byte 0x030046AC
_08232B44:
	ldr r0, _08232B68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08232B52:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232B6C
	adds r0, #4
	mov sb, r0
	b _08232B7A
	.align 2, 0
_08232B68: .4byte 0x030046A4
_08232B6C:
	ldr r0, _08232B8C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r1, r1, r0
	mov sb, r1
_08232B7A:
	mov r0, sb
	ldrh r5, [r0, #2]
	cmp r4, #4
	bne _08232B90
	movs r1, #2
	mov sl, r1
	movs r4, #0x80
	b _08232B96
	.align 2, 0
_08232B8C: .4byte 0x030046A4
_08232B90:
	movs r2, #1
	mov sl, r2
	movs r4, #0x64
_08232B96:
	adds r0, r5, #0
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _08232BA2
	b _08232DDE
_08232BA2:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_082329e0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r4
	ble _08232BB4
	b _08232DDE
_08232BB4:
	mov r2, r8
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r4, r8
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232BDC
	cmp r1, #0
	blt _08232BDC
	ldr r0, _08232BE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232BDC
	ldr r0, _08232BE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232BE8
_08232BDC:
	movs r0, #0
	b _08232BF6
	.align 2, 0
_08232BE0: .4byte 0x030046A8
_08232BE4: .4byte 0x030046AC
_08232BE8:
	ldr r0, _08232C0C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08232BF6:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232C10
	adds r0, #4
	mov r8, r0
	b _08232C1E
	.align 2, 0
_08232C0C: .4byte 0x030046A4
_08232C10:
	ldr r0, _08232C7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r1, r1, r0
	mov r8, r1
_08232C1E:
	mov r1, r8
	ldrb r0, [r1]
	lsrs r1, r0, #4
	mov r2, sb
	ldrb r0, [r2]
	lsrs r3, r0, #4
	subs r2, r6, r4
	cmp r1, #1
	bne _08232CCC
	cmp r2, #1
	beq _08232C3E
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq _08232C3E
	b _08232DE8
_08232C3E:
	ldr r0, _08232C80 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08232C84 @ =0x00000934
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08232C5A
	movs r0, #0x80
	ands r5, r0
	cmp r5, #0
	beq _08232C5A
	b _08232DDE
_08232C5A:
	cmp r3, #0
	beq _08232C60
	b _08232DE8
_08232C60:
	ldrb r0, [r7, #4]
	cmp r0, #0x7f
	bgt _08232C8C
	ldr r0, _08232C88 @ =0x030046A8
	ldr r0, [r0]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08232C9E
	b _08232CA8
	.align 2, 0
_08232C7C: .4byte 0x030046A4
_08232C80: .4byte 0x030046A0
_08232C84: .4byte 0x00000934
_08232C88: .4byte 0x030046A8
_08232C8C:
	ldr r0, _08232CA4 @ =0x030046A8
	ldr r0, [r0]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232CA8
_08232C9E:
	adds r3, r0, #4
	b _08232CB4
	.align 2, 0
_08232CA4: .4byte 0x030046A8
_08232CA8:
	ldr r0, _08232CC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_08232CB4:
	ldrb r2, [r3]
	lsrs r0, r2, #4
	cmp r0, #0
	beq _08232CBE
	b _08232DDE
_08232CBE:
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r2
	mov r4, sb
	b _08232DCC
	.align 2, 0
_08232CC8: .4byte 0x030046A4
_08232CCC:
	cmp r1, #2
	bne _08232D54
	ldr r0, _08232D14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	beq _08232CDE
	cmn r2, r0
	beq _08232CDE
	b _08232DE8
_08232CDE:
	ldr r0, _08232D18 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08232D1C @ =0x00000934
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08232CF8
	movs r0, #0x80
	ands r5, r0
	cmp r5, #0
	bne _08232DDE
_08232CF8:
	cmp r3, #0
	bne _08232DE8
	ldrb r0, [r7]
	cmp r0, #0x7f
	bgt _08232D20
	subs r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08232D2E
	b _08232D32
	.align 2, 0
_08232D14: .4byte 0x030046A8
_08232D18: .4byte 0x030046A0
_08232D1C: .4byte 0x00000934
_08232D20:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232D32
_08232D2E:
	adds r3, r0, #4
	b _08232D3E
_08232D32:
	ldr r0, _08232D50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_08232D3E:
	ldrb r2, [r3]
	lsrs r0, r2, #4
	cmp r0, #0
	bne _08232DDE
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r2
	mov r4, sb
	b _08232DCC
	.align 2, 0
_08232D50: .4byte 0x030046A4
_08232D54:
	ldr r0, _08232D70 @ =0x030046A8
	ldr r1, [r0]
	cmp r2, r1
	beq _08232D60
	cmn r2, r1
	bne _08232D78
_08232D60:
	cmp r3, #2
	bne _08232DE8
	ldrb r0, [r7]
	cmp r0, #0x7f
	bgt _08232D74
	subs r4, #1
	b _08232D90
	.align 2, 0
_08232D70: .4byte 0x030046A8
_08232D74:
	adds r4, #1
	b _08232D90
_08232D78:
	cmp r2, #1
	beq _08232D84
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne _08232DE8
_08232D84:
	cmp r3, #1
	bne _08232DE8
	ldrb r0, [r7, #4]
	cmp r0, #0x7f
	bgt _08232D9E
	subs r4, r4, r1
_08232D90:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08232DAC
	b _08232DB0
_08232D9E:
	adds r4, r4, r1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232DB0
_08232DAC:
	adds r3, r0, #4
	b _08232DBC
_08232DB0:
	ldr r0, _08232DE4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_08232DBC:
	ldrb r2, [r3]
	lsrs r0, r2, #4
	cmp r0, #0
	bne _08232DDE
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r2
	mov r4, r8
_08232DCC:
	ldrb r2, [r4]
	ands r0, r2
	cmp r1, r0
	bne _08232DDE
	ldrh r0, [r3, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _08232DE8
_08232DDE:
	movs r0, #0
	b _08232DEA
	.align 2, 0
_08232DE4: .4byte 0x030046A4
_08232DE8:
	movs r0, #1
_08232DEA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08232df8
FUN_08232df8: @ 0x08232DF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	mov sb, r1
	adds r5, r2, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sl, r3
	ldr r0, _08232E44 @ =0x030046A4
	ldr r1, [r0]
	ldr r0, [r1, #4]
	cmp r0, #0
	beq _08232E74
	adds r6, r0, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r3, #0
	blt _08232E40
	cmp r2, #0
	blt _08232E40
	ldr r0, _08232E48 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08232E40
	ldr r0, _08232E4C @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _08232E50
_08232E40:
	movs r0, #0
	b _08232E5A
	.align 2, 0
_08232E44: .4byte 0x030046A4
_08232E48: .4byte 0x030046A8
_08232E4C: .4byte 0x030046AC
_08232E50:
	lsls r0, r2, #1
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r3
_08232E5A:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r1, r8
	ldrh r0, [r1, #6]
	cmp r0, r7
	beq _08232E74
	mov r0, sb
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232E78
_08232E74:
	movs r0, #0
	b _082332E6
_08232E78:
	mov r2, r8
	ldrh r1, [r2, #6]
	subs r2, r7, r1
	movs r0, #4
	ldrsh r3, [r6, r0]
	rsbs r0, r3, #0
	adds r0, #1
	adds r4, r1, #0
	cmp r2, r0
	bgt _08232E92
	adds r0, r2, #1
	adds r2, r0, r3
	b _08232EB0
_08232E92:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne _08232E9E
	movs r2, #3
	b _08232EB0
_08232E9E:
	cmp r2, #1
	bne _08232EA6
	movs r2, #4
	b _08232EB0
_08232EA6:
	subs r0, r3, #1
	cmp r2, r0
	blt _08232EB0
	adds r0, r2, #6
	subs r2, r0, r3
_08232EB0:
	cmp r2, #7
	bls _08232EB6
	b _082332E4
_08232EB6:
	lsls r0, r2, #2
	ldr r1, _08232EC0 @ =_08232EC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08232EC0: .4byte _08232EC4
_08232EC4: @ jump table
	.4byte _08232EE4 @ case 0
	.4byte _08232FEE @ case 1
	.4byte _08232FFE @ case 2
	.4byte _082330FE @ case 3
	.4byte _08233110 @ case 4
	.4byte _08233124 @ case 5
	.4byte _082331F8 @ case 6
	.4byte _08233200 @ case 7
_08232EE4:
	mov r2, r8
	ldrh r1, [r2, #4]
	adds r0, r7, #1
	cmp r1, r0
	bne _08232F78
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08232F74 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	mov r4, sp
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232F24
	b _082332B2
_08232F24:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r4, #4]
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232F4E
	b _082332B2
_08232F4E:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
	.align 2, 0
_08232F74: .4byte 0xFFFF0000
_08232F78:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1, #4]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232FA0
	b _082332B2
_08232FA0:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08232FCA
	b _082332B2
_08232FCA:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
_08232FEE:
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
_08232FFE:
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r7, #1
	cmp r1, r0
	bne _08233084
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08233034
	b _082332B2
_08233034:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r4, #4]
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _0823305E
	b _082332B2
_0823305E:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
_08233084:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1, #4]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _082330AC
	b _082332B2
_082330AC:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _082330D8
	b _082332B2
_082330D8:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	b _082332E2
_082330FE:
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	strh r0, [r5]
	b _082332E4
_08233110:
	movs r2, #4
	ldrsh r1, [r6, r2]
	adds r0, r4, #0
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r5]
	b _082332E4
_08233124:
	mov r0, r8
	ldrh r1, [r0, #4]
	adds r0, r7, #1
	cmp r1, r0
	bne _08233196
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r2, #4
	ldrsh r1, [r6, r2]
	adds r0, r4, #0
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08233158
	b _082332B2
_08233158:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r4, #4]
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _08233184
	b _082332B2
_08233184:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	b _082332CE
_08233196:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1, #4]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	b _082332CE
_082331F8:
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	b _082332D8
_08233200:
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r7, #1
	cmp r1, r0
	bne _08233260
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	strh r0, [r4, #4]
	mov r0, sb
	mov r1, sp
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	b _082332BC
_08233260:
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #4
	ldrsh r1, [r6, r0]
	adds r0, r4, #0
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1, #4]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	bne _082332B2
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r0, sb
	mov r2, sl
	bl FUN_08232b00
	cmp r0, #0
	beq _082332BC
_082332B2:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r5]
	str r1, [r5, #4]
	b _082332E4
_082332BC:
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
_082332CE:
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #6]
	movs r2, #4
	ldrsh r1, [r6, r2]
_082332D8:
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
_082332E2:
	strh r0, [r5, #4]
_082332E4:
	movs r0, #1
_082332E6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082332f8
FUN_082332f8: @ 0x082332F8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	ldr r0, _08233334 @ =0x030046A4
	ldr r1, [r0]
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _0823330C
	b _08233422
_0823330C:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r3, #0
	blt _08233330
	cmp r2, #0
	blt _08233330
	ldr r0, _08233338 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08233330
	ldr r0, _0823333C @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _08233340
_08233330:
	movs r0, #0
	b _0823334A
	.align 2, 0
_08233334: .4byte 0x030046A4
_08233338: .4byte 0x030046A8
_0823333C: .4byte 0x030046AC
_08233340:
	lsls r0, r2, #1
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r3
_0823334A:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823335E
	adds r2, r0, #4
	b _0823336A
_0823335E:
	ldr r0, _082333C4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r2, r1, r0
_0823336A:
	ldrh r0, [r4, #6]
	cmp r0, r5
	beq _08233392
	strh r0, [r4, #4]
	ldrb r0, [r4, #0xb]
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #9]
	strb r0, [r4, #8]
	ldrh r0, [r4, #0xe]
	strh r0, [r4, #0xc]
	strh r5, [r4, #6]
	ldrb r0, [r2]
	lsrs r0, r0, #4
	strb r0, [r4, #0xb]
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #9]
	ldrh r0, [r2, #2]
	strh r0, [r4, #0xe]
_08233392:
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7]
	str r1, [r7, #4]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _082333BE
	cmp r1, #0
	blt _082333BE
	ldr r0, _082333C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _082333BE
	ldr r0, _082333CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082333D0
_082333BE:
	movs r4, #0
	b _082333DE
	.align 2, 0
_082333C4: .4byte 0x030046A4
_082333C8: .4byte 0x030046A8
_082333CC: .4byte 0x030046AC
_082333D0:
	ldr r0, _082333F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_082333DE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082333F4
	adds r0, #4
	b _08233400
	.align 2, 0
_082333F0: .4byte 0x030046A4
_082333F4:
	ldr r0, _08233414 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08233400:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08233418
	cmp r2, #2
	beq _0823341C
	b _08233420
	.align 2, 0
_08233414: .4byte 0x030046A4
_08233418:
	ldrb r0, [r6, #4]
	b _0823341E
_0823341C:
	ldrb r0, [r6]
_0823341E:
	subs r1, r1, r0
_08233420:
	strh r1, [r7, #2]
_08233422:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08233428
FUN_08233428: @ 0x08233428
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r3, [sp, #0x20]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrh r0, [r2]
	ldrh r1, [r4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r6, _08233494 @ =0xFFFF0000
	mov r8, r6
	ldrh r1, [r2, #2]
	ldrh r6, [r4, #2]
	adds r1, r1, r6
	lsls r1, r1, #0x10
	ldr r6, _08233498 @ =0x0000FFFF
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r2, #4]
	ldrh r0, [r4, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	ands r0, r6
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08232df8
	strb r0, [r5]
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_082332f8
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08233494: .4byte 0xFFFF0000
_08233498: .4byte 0x0000FFFF

	thumb_func_start FUN_0823349c
FUN_0823349c: @ 0x0823349C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	adds r7, r0, #0
	mov r8, r1
	str r2, [sp, #0x50]
	ldr r0, [sp, #0x88]
	ldr r1, [sp, #0x8c]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x54]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x58]
	movs r5, #0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _082334D2
	movs r5, #0x10
	b _082334D8
_082334D2:
	cmp r0, #0
	bge _082334D8
	movs r5, #0x20
_082334D8:
	ldr r2, [sp, #0x50]
	movs r4, #4
	ldrsh r0, [r2, r4]
	ldrh r1, [r2, #4]
	mov sb, r1
	cmp r0, #0
	ble _082334EA
	movs r0, #1
	b _082334F0
_082334EA:
	cmp r0, #0
	bge _082334F2
	movs r0, #2
_082334F0:
	orrs r5, r0
_082334F2:
	mov r4, r8
	ldrh r2, [r4]
	lsls r0, r2, #0x10
	asrs r4, r0, #0x18
	mov r0, r8
	ldrh r1, [r0, #4]
	lsls r0, r1, #0x10
	asrs r3, r0, #0x18
	adds r6, r1, #0
	cmp r4, #0
	blt _0823351C
	cmp r3, #0
	blt _0823351C
	ldr r0, _08233520 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0823351C
	ldr r0, _08233524 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _08233528
_0823351C:
	movs r0, #0
	b _08233536
	.align 2, 0
_08233520: .4byte 0x030046A8
_08233524: .4byte 0x030046AC
_08233528:
	ldr r0, _08233580 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r4
_08233536:
	strh r0, [r7, #6]
	ldr r1, [sp, #0x50]
	ldrh r0, [r1]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	ldr r3, _08233584 @ =0xFFFF0000
	ldrh r1, [r1, #2]
	mov r2, r8
	ldrh r2, [r2, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldr r2, _08233588 @ =0x0000FFFF
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	mov r4, sb
	adds r1, r6, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #4]
	cmp r5, #0x22
	bls _08233574
	bl FUN_08233d40
_08233574:
	lsls r0, r5, #2
	ldr r1, _0823358C @ =_08233590
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08233580: .4byte 0x030046A4
_08233584: .4byte 0xFFFF0000
_08233588: .4byte 0x0000FFFF
_0823358C: .4byte _08233590
_08233590: @ jump table
	.4byte _0823361C @ case 0
	.4byte _0823374C @ case 1
	.4byte _082337D2 @ case 2
	.4byte _08233D40 @ case 3
	.4byte _08233D40 @ case 4
	.4byte _08233D40 @ case 5
	.4byte _08233D40 @ case 6
	.4byte _08233D40 @ case 7
	.4byte _08233D40 @ case 8
	.4byte _08233D40 @ case 9
	.4byte _08233D40 @ case 10
	.4byte _08233D40 @ case 11
	.4byte _08233D40 @ case 12
	.4byte _08233D40 @ case 13
	.4byte _08233D40 @ case 14
	.4byte _08233D40 @ case 15
	.4byte _0823362A @ case 16
	.4byte _08233858 @ case 17
	.4byte _08233AAA @ case 18
	.4byte _08233D40 @ case 19
	.4byte _08233D40 @ case 20
	.4byte _08233D40 @ case 21
	.4byte _08233D40 @ case 22
	.4byte _08233D40 @ case 23
	.4byte _08233D40 @ case 24
	.4byte _08233D40 @ case 25
	.4byte _08233D40 @ case 26
	.4byte _08233D40 @ case 27
	.4byte _08233D40 @ case 28
	.4byte _08233D40 @ case 29
	.4byte _08233D40 @ case 30
	.4byte _08233D40 @ case 31
	.4byte _082336C8 @ case 32
	.4byte _08233998 @ case 33
	.4byte _08233BE8 @ case 34
_0823361C:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_0823362A:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r1, [r4]
	add r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0823367C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233680
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	b _08233CDC
	.align 2, 0
_0823367C: .4byte 0xFFFF0000
_08233680:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	subs r0, r0, r4
	strh r0, [r2, #0xc]
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _082336BA
	mov r1, sp
	ldrh r0, [r1, #8]
	mov r2, sl
	subs r0, r0, r2
	strh r0, [r1, #8]
	ldrh r0, [r1, #0xc]
	adds r0, r4, r0
	strh r0, [r1, #0xc]
	b _08233CDC
_082336BA:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_082336C8:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	mov r1, sl
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r2, [sp, #0x54]
	adds r0, r2, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233702
	mov r4, sp
	ldrh r0, [r4, #8]
	add r0, sl
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	b _08233CDA
_08233702:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _0823373E
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	adds r0, r4, r0
	strh r0, [r2, #0xc]
	b _08233CDC
_0823373E:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_0823374C:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233788
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	b _08233CDC
_08233788:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r2, #0xc]
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _082337C4
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	subs r0, r0, r4
	strh r0, [r2, #0xc]
	b _08233CDC
_082337C4:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_082337D2:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _0823380E
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r2, #0xc]
	b _08233CDC
_0823380E:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _0823384A
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	adds r0, r4, r0
	strh r0, [r2, #0xc]
	b _08233CDC
_0823384A:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
_08233858:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233894
	mov r2, sp
	ldrh r0, [r2, #8]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r2, #0xc]
	b _08233CDC
_08233894:
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	add r5, sp, #0x10
	add r1, sl
	ldrh r0, [r5]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _0823390C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r1, r5, #0
	mov r0, r8
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	mov sb, r0
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0, #4]
	add r6, sp, #0x18
	ldr r2, [sp, #0x54]
	adds r1, r1, r2
	ldrh r0, [r6, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r6, #4]
	mov r0, r8
	adds r1, r6, #0
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	mov r1, sb
	cmp r1, #0
	beq _08233910
	cmp r0, #0
	beq _0823397A
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
	.align 2, 0
_0823390C: .4byte 0xFFFF0000
_08233910:
	cmp r0, #0
	bne _08233950
	ldrh r0, [r7, #6]
	ldr r4, _0823394C @ =0x030046A8
	ldr r1, [r4]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r2, sp
	strh r0, [r2, #8]
	ldrh r0, [r7, #6]
	ldr r1, [r4]
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r4, sp
	ldrh r1, [r4, #8]
	mov r2, sl
	subs r1, r1, r2
	strh r1, [r4, #8]
	ldr r4, [sp, #0x54]
	subs r0, r0, r4
	mov r1, sp
	strh r0, [r1, #0xc]
	b _08233CDC
	.align 2, 0
_0823394C: .4byte 0x030046A8
_08233950:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldrh r0, [r5]
	mov r2, sl
	subs r0, r0, r2
	strh r0, [r5]
	ldr r4, [sp, #0x50]
	ldrh r0, [r4, #4]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	bl FUN_082332f8
	b _08233D3C
_0823397A:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r6, #4]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	b _08233D30
_08233998:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	mov r2, sl
	subs r0, r0, r2
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _082339D4
	mov r2, sp
	ldrh r0, [r2, #8]
	add r0, sl
	strh r0, [r2, #8]
	ldrh r0, [r2, #0xc]
	ldr r4, [sp, #0x54]
	subs r0, r0, r4
	strh r0, [r2, #0xc]
	b _08233CDC
_082339D4:
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	add r0, sp, #0x20
	mov sb, r0
	mov r2, sl
	subs r1, r1, r2
	ldrh r4, [r0]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _08233A50 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	mov r1, sb
	mov r0, r8
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	str r0, [sp, #0x5c]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0, #4]
	add r6, sp, #0x28
	ldr r2, [sp, #0x54]
	adds r1, r1, r2
	ldrh r0, [r6, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r6, #4]
	mov r0, r8
	adds r1, r6, #0
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	ldr r1, [sp, #0x5c]
	cmp r1, #0
	beq _08233A54
	cmp r0, #0
	beq _08233A8C
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
	.align 2, 0
_08233A50: .4byte 0xFFFF0000
_08233A54:
	cmp r0, #0
	beq _08233A5A
	b _08233CEC
_08233A5A:
	ldrh r0, [r7, #6]
	ldr r4, _08233A88 @ =0x030046A8
	ldr r1, [r4]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r2, sp
	strh r0, [r2, #8]
	ldrh r0, [r7, #6]
	ldr r1, [r4]
	bl Div
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r4, sp
	ldrh r1, [r4, #8]
	add r1, sl
	strh r1, [r4, #8]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	b _08233CDA
	.align 2, 0
_08233A88: .4byte 0x030046A8
_08233A8C:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r6, #4]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	b _08233D30
_08233AAA:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r4, sp, #8
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r2, [sp, #0x54]
	subs r0, r0, r2
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233AE4
	mov r4, sp
	ldrh r0, [r4, #8]
	mov r1, sl
	subs r0, r0, r1
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	ldr r2, [sp, #0x54]
	adds r0, r2, r0
	b _08233CDA
_08233AE4:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0]
	add r2, sp, #0x30
	mov sb, r2
	add r1, sl
	ldrh r4, [r2]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _08233B5C @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x30]
	mov r1, sb
	mov r0, r8
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	str r0, [sp, #0x60]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x38]
	str r1, [sp, #0x3c]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0, #4]
	add r6, sp, #0x38
	ldr r2, [sp, #0x54]
	subs r1, r1, r2
	ldrh r0, [r6, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r6, #4]
	mov r0, r8
	adds r1, r6, #0
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	ldr r1, [sp, #0x60]
	cmp r1, #0
	beq _08233B60
	cmp r0, #0
	beq _08233BCA
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
	.align 2, 0
_08233B5C: .4byte 0xFFFF0000
_08233B60:
	cmp r0, #0
	bne _08233B9C
	ldrh r0, [r7, #6]
	ldr r4, _08233B98 @ =0x030046A8
	ldr r1, [r4]
	bl Mod
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #1
	mov r2, sp
	strh r0, [r2, #8]
	ldrh r0, [r7, #6]
	ldr r1, [r4]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	mov r4, sp
	ldrh r1, [r4, #8]
	mov r2, sl
	subs r1, r1, r2
	strh r1, [r4, #8]
	ldr r4, [sp, #0x54]
	adds r0, r4, r0
	mov r1, sp
	strh r0, [r1, #0xc]
	b _08233CDC
	.align 2, 0
_08233B98: .4byte 0x030046A8
_08233B9C:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sb
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	mov r2, sb
	ldrh r0, [r2]
	mov r4, sl
	subs r0, r0, r4
	strh r0, [r2]
	ldr r1, [sp, #0x50]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	mov r4, sb
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	mov r2, sb
	bl FUN_082332f8
	b _08233D3C
_08233BCA:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldr r1, [sp, #0x50]
	ldrh r0, [r1]
	ldrh r2, [r6]
	adds r0, r0, r2
	strh r0, [r6]
	ldrh r0, [r6, #4]
	ldr r4, [sp, #0x54]
	adds r0, r4, r0
	b _08233D30
_08233BE8:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #8
	ldrh r0, [r1]
	mov r2, sl
	subs r0, r0, r2
	strh r0, [r1]
	adds r4, r1, #0
	ldrh r0, [r4, #4]
	ldr r1, [sp, #0x54]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	cmp r0, #0
	beq _08233C2E
	ldrh r0, [r4]
	add r0, sl
	strh r0, [r4]
	ldrh r0, [r4, #4]
	ldr r2, [sp, #0x54]
	adds r0, r2, r0
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	bl FUN_082332f8
	b _08233D3C
_08233C2E:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0]
	add r2, sp, #0x40
	mov sb, r2
	mov r4, sl
	subs r1, r1, r4
	ldrh r0, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _08233CA8 @ =0xFFFF0000
	ldr r0, [sp, #0x40]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x40]
	mov r1, sb
	mov r0, r8
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	str r0, [sp, #0x64]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	ldr r0, [sp, #0x50]
	ldrh r1, [r0, #4]
	add r6, sp, #0x48
	ldr r2, [sp, #0x54]
	subs r1, r1, r2
	ldrh r0, [r6, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r6, #4]
	mov r0, r8
	adds r1, r6, #0
	ldr r2, [sp, #0x58]
	bl FUN_08232b00
	ldr r1, [sp, #0x64]
	cmp r1, #0
	beq _08233CAC
	cmp r0, #0
	beq _08233D14
	adds r0, r7, #0
	mov r1, r8
	mov r2, sp
	bl FUN_082332f8
	movs r0, #0
	b _08233D3E
	.align 2, 0
_08233CA8: .4byte 0xFFFF0000
_08233CAC:
	cmp r0, #0
	bne _08233CEC
	ldrh r0, [r7, #6]
	ldr r4, _08233CE8 @ =0x030046A8
	ldr r1, [r4]
	bl Mod
	lsls r0, r0, #8
	adds r0, #1
	mov r2, sp
	strh r0, [r2, #8]
	ldrh r0, [r7, #6]
	ldr r1, [r4]
	bl Div
	lsls r0, r0, #8
	adds r0, #1
	mov r4, sp
	ldrh r1, [r4, #8]
	add r1, sl
	strh r1, [r4, #8]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
_08233CDA:
	strh r0, [r4, #0xc]
_08233CDC:
	adds r0, r7, #0
	mov r1, r8
	add r2, sp, #8
	bl FUN_082332f8
	b _08233D3C
	.align 2, 0
_08233CE8: .4byte 0x030046A8
_08233CEC:
	adds r0, r7, #0
	mov r1, r8
	mov r2, sb
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	mov r2, sb
	ldrh r0, [r2]
	add r0, sl
	strh r0, [r2]
	ldr r4, [sp, #0x50]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r7, #0
	mov r1, r8
	bl FUN_082332f8
	b _08233D3C
_08233D14:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	ldr r3, [sp, #0x58]
	bl FUN_08232df8
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r6, #4]
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
_08233D30:
	strh r0, [r6, #4]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	bl FUN_082332f8
_08233D3C:
	movs r0, #1
_08233D3E:
	strb r0, [r7]

_08233D40:
FUN_08233d40:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08233d50
FUN_08233d50: @ 0x08233D50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp]
	adds r6, r1, #0
	mov sb, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov ip, r0
	movs r2, #0
	ldrsh r3, [r6, r2]
	subs r0, r0, r3
	str r0, [sp, #0x10]
	mov r7, sb
	movs r0, #4
	ldrsh r7, [r7, r0]
	mov r8, r7
	movs r1, #4
	ldrsh r2, [r6, r1]
	subs r7, r7, r2
	mov sl, r7
	ldrh r1, [r6, #2]
	lsls r1, r1, #0x10
	ldr r0, _08233DD8 @ =0x0000FFFF
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	ldrb r0, [r6]
	str r0, [sp, #0x14]
	ldrb r1, [r6, #4]
	str r1, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r7, [sp, #0x14]
	subs r7, r0, r7
	str r7, [sp, #0x1c]
	subs r1, r0, r1
	str r1, [sp, #0x20]
	movs r1, #0xff
	lsls r1, r1, #8
	adds r7, r1, #0
	ands r7, r3
	ands r1, r2
	str r1, [sp, #4]
	adds r2, r7, r0
	str r2, [sp, #8]
	adds r0, r1, r0
	str r0, [sp, #0xc]
	cmp ip, r7
	blt _08233DDC
	cmp ip, r2
	bgt _08233DDC
	cmp r8, r1
	blt _08233DDC
	cmp r8, r0
	bgt _08233DDC
	mov r7, sb
	ldr r0, [r7]
	ldr r1, [r7, #4]
	ldr r2, [sp]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #1
	b _082340B6
	.align 2, 0
_08233DD8: .4byte 0x0000FFFF
_08233DDC:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	bne _08233E40
	mov r1, sl
	cmp r1, #0
	bne _08233DF8
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r7, [sp]
	str r0, [r7]
	str r1, [r7, #4]
	movs r0, #1
	b _082340B6
_08233DF8:
	mov r0, sl
	cmp r0, #0
	ble _08233E14
	ldr r2, [sp, #0xc]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08233E10 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	b _08233E1C
	.align 2, 0
_08233E10: .4byte 0xFFFF0000
_08233E14:
	ldr r0, _08233E3C @ =0xFFFF0000
	ands r0, r5
	ldr r5, [sp, #4]
	orrs r5, r0
_08233E1C:
	ldrh r1, [r6]
	ldr r0, _08233E3C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #3
	mov r1, sl
	cmp r1, #0
	bgt _08233E36
	b _082340B6
_08233E36:
	movs r0, #2
	b _082340B6
	.align 2, 0
_08233E3C: .4byte 0xFFFF0000
_08233E40:
	mov r2, sl
	cmp r2, #0
	bne _08233E8C
	ldr r0, [sp, #0x10]
	cmp r0, #0
	ble _08233E60
	ldr r2, [sp, #8]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08233E5C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	b _08233E68
	.align 2, 0
_08233E5C: .4byte 0xFFFF0000
_08233E60:
	ldr r0, _08233E88 @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r7
_08233E68:
	ldrh r1, [r6, #4]
	ldr r0, _08233E88 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #4
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bgt _08233E82
	b _082340B6
_08233E82:
	movs r0, #5
	b _082340B6
	.align 2, 0
_08233E88: .4byte 0xFFFF0000
_08233E8C:
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
	ldr r0, [sp, #0x10]
	cmp r0, #0
	ble _08233E9E
	movs r1, #0x80
	lsls r1, r1, #5
	mov r8, r1
_08233E9E:
	mov r2, sl
	cmp r2, #0
	ble _08233EAE
	movs r0, #0x10
	mov r1, r8
	orrs r1, r0
	mov r8, r1
	b _08233EB6
_08233EAE:
	movs r0, #1
	mov r2, r8
	orrs r2, r0
	mov r8, r2
_08233EB6:
	movs r0, #0x10
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08233F34
	ldr r2, [sp, #0x20]
	ldr r1, [sp, #0x10]
	adds r0, r2, #0
	muls r0, r1, r0
	mov r1, sl
	cmp r1, #0
	bge _08233ED0
	rsbs r1, r1, #0
_08233ED0:
	bl Div
	ldrh r2, [r6]
	mov ip, r2
	add r0, ip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08233F30 @ =0xFFFF0000
	mov sb, r1
	mov r3, sb
	ands r3, r4
	orrs r3, r0
	adds r4, r3, #0
	ldr r2, [sp, #0xc]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	cmp r1, r7
	blt _08233F34
	ldr r0, [sp, #8]
	cmp r1, r0
	bgt _08233F34
	movs r2, #0xff
	lsls r2, r2, #8
	ands r1, r2
	movs r7, #0
	ldrsh r0, [r6, r7]
	ands r0, r2
	cmp r1, r0
	ble _08233F24
	movs r0, #0xff
	mov r1, ip
	orrs r0, r1
	mov r2, sb
	ands r3, r2
	adds r4, r3, #0
	orrs r4, r0
_08233F24:
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #3
	b _082340B6
	.align 2, 0
_08233F30: .4byte 0xFFFF0000
_08233F34:
	movs r0, #1
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08233FB4
	ldr r2, [sp, #0x18]
	ldr r1, [sp, #0x10]
	adds r0, r2, #0
	muls r0, r1, r0
	mov r1, sl
	cmp r1, #0
	bge _08233F4E
	rsbs r1, r1, #0
_08233F4E:
	bl Div
	ldrh r2, [r6]
	mov ip, r2
	add r0, ip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08233FB0 @ =0xFFFF0000
	mov sb, r1
	mov r3, sb
	ands r3, r4
	orrs r3, r0
	adds r4, r3, #0
	ldr r1, [sp, #4]
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	cmp r1, r7
	blt _08233FB4
	ldr r2, [sp, #8]
	cmp r1, r2
	bgt _08233FB4
	movs r2, #0xff
	lsls r2, r2, #8
	ands r1, r2
	movs r7, #0
	ldrsh r0, [r6, r7]
	ands r0, r2
	cmp r1, r0
	ble _08233FA4
	movs r0, #0xff
	mov r1, ip
	orrs r0, r1
	mov r2, sb
	ands r3, r2
	adds r4, r3, #0
	orrs r4, r0
_08233FA4:
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #2
	b _082340B6
	.align 2, 0
_08233FB0: .4byte 0xFFFF0000
_08233FB4:
	movs r0, #0x80
	lsls r0, r0, #1
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08234034
	subs r1, r7, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08234030 @ =0xFFFF0000
	mov sb, r2
	mov r0, sb
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	ldr r7, [sp, #0x14]
	mov r0, sl
	muls r0, r7, r0
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bge _08233FE0
	rsbs r1, r1, #0
_08233FE0:
	bl Div
	ldrh r1, [r6, #4]
	mov ip, r1
	add r0, ip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sb
	ands r3, r5
	orrs r3, r0
	adds r5, r3, #0
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	ldr r2, [sp, #4]
	cmp r1, r2
	blt _08234034
	ldr r7, [sp, #0xc]
	cmp r1, r7
	bgt _08234034
	movs r2, #0xff
	lsls r2, r2, #8
	ands r1, r2
	movs r7, #4
	ldrsh r0, [r6, r7]
	ands r0, r2
	cmp r1, r0
	ble _08234024
	movs r0, #0xff
	mov r1, ip
	orrs r0, r1
	mov r2, sb
	ands r3, r2
	adds r5, r3, #0
	orrs r5, r0
_08234024:
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #4
	b _082340B6
	.align 2, 0
_08234030: .4byte 0xFFFF0000
_08234034:
	movs r0, #0x80
	lsls r0, r0, #5
	mov r1, r8
	ands r1, r0
	cmp r1, #0
	beq _082340B4
	ldr r2, [sp, #8]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	ldr r7, _082340B0 @ =0xFFFF0000
	mov r8, r7
	mov r0, r8
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	ldr r1, [sp, #0x1c]
	mov r0, sl
	muls r0, r1, r0
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bge _08234060
	rsbs r1, r1, #0
_08234060:
	bl Div
	ldrh r2, [r6, #4]
	mov sb, r2
	add r0, sb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, r8
	ands r3, r5
	orrs r3, r0
	adds r5, r3, #0
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	ldr r7, [sp, #4]
	cmp r1, r7
	blt _082340B4
	ldr r0, [sp, #0xc]
	cmp r1, r0
	bgt _082340B4
	movs r2, #0xff
	lsls r2, r2, #8
	ands r1, r2
	movs r7, #4
	ldrsh r0, [r6, r7]
	ands r0, r2
	cmp r1, r0
	ble _082340A4
	movs r0, #0xff
	mov r1, sb
	orrs r0, r1
	mov r2, r8
	ands r3, r2
	adds r5, r3, #0
	orrs r5, r0
_082340A4:
	ldr r7, [sp]
	str r4, [r7]
	str r5, [r7, #4]
	movs r0, #5
	b _082340B6
	.align 2, 0
_082340B0: .4byte 0xFFFF0000
_082340B4:
	movs r0, #0
_082340B6:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082340c8
FUN_082340c8: @ 0x082340C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov sb, r0
	str r1, [sp, #0x10]
	mov r8, r2
	mov sl, r3
	ldr r0, _08234120 @ =0x030046A4
	ldr r4, [r0]
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _082340E8
	b _082341F6
_082340E8:
	movs r3, #0
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0823411C
	cmp r1, #0
	blt _0823411C
	ldr r0, _08234124 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0823411C
	ldr r0, _08234128 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08234130
_0823411C:
	movs r6, #0
	b _0823413C
	.align 2, 0
_08234120: .4byte 0x030046A4
_08234124: .4byte 0x030046A8
_08234128: .4byte 0x030046AC
_0823412C:
	movs r0, #1
	b _082341F8
_08234130:
	lsls r0, r1, #1
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r6, r0, r2
_0823413C:
	movs r7, #0
	cmp r7, r8
	bge _082341F6
	add r5, sp, #8
_08234144:
	adds r0, r5, #0
	mov r1, sp
	ldr r2, [sp, #0x10]
	bl FUN_08233d50
	adds r3, r0, #0
	cmp r3, #1
	ble _08234192
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08234178
	cmp r1, #0
	blt _08234178
	ldr r0, _0823417C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08234178
	ldr r0, _08234180 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08234184
_08234178:
	movs r6, #0
	b _08234192
	.align 2, 0
_0823417C: .4byte 0x030046A8
_08234180: .4byte 0x030046AC
_08234184:
	ldr r0, _082341A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_08234192:
	adds r4, r5, #0
	adds r0, r6, #0
	movs r1, #1
	str r3, [sp, #0x14]
	bl FUN_08234224
	ldr r3, [sp, #0x14]
	cmp r0, #0
	beq _082341AC
	adds r0, #4
	b _082341B8
	.align 2, 0
_082341A8: .4byte 0x030046A4
_082341AC:
	ldr r0, _082341CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_082341B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _082341D0
	cmp r2, #2
	beq _082341D4
	b _082341D8
	.align 2, 0
_082341CC: .4byte 0x030046A4
_082341D0:
	ldrb r0, [r4, #4]
	b _082341D6
_082341D4:
	ldrb r0, [r4]
_082341D6:
	subs r1, r1, r0
_082341D8:
	mov r4, sb
	movs r2, #2
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, sl
	bge _082341F6
	cmp r3, #1
	beq _0823412C
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	adds r7, #1
	cmp r7, r8
	blt _08234144
_082341F6:
	movs r0, #0
_082341F8:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08234208
FUN_08234208: @ 0x08234208
	push {r4, r5, r6, lr}
	ldr r5, [sp, #0x10]
	ldr r6, [sp, #0x14]
	movs r4, #0
	strh r1, [r0, #2]
	strh r4, [r0]
	lsls r2, r2, #4
	orrs r2, r3
	strb r2, [r0, #4]
	strb r5, [r0, #5]
	strh r6, [r0, #6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08234224
FUN_08234224: @ 0x08234224
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, _0823426C @ =0x030046A4
	ldr r0, [r0]
	ldr r3, [r0, #0x18]
	movs r4, #0
	cmp r3, #0
	beq _08234262
	movs r5, #0xf
_08234238:
	ldrh r0, [r3]
	ands r0, r6
	cmp r0, #0
	bne _0823425C
	ldrh r0, [r3, #2]
	cmp r0, r7
	bne _0823425C
	cmp r4, #0
	beq _0823425A
	ldrb r0, [r4, #4]
	ldrb r2, [r3, #4]
	adds r1, r5, #0
	ands r1, r0
	adds r0, r5, #0
	ands r0, r2
	cmp r1, r0
	bhs _0823425C
_0823425A:
	adds r4, r3, #0
_0823425C:
	ldr r3, [r3, #0xc]
	cmp r3, #0
	bne _08234238
_08234262:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823426C: .4byte 0x030046A4

	thumb_func_start FUN_08234270
FUN_08234270: @ 0x08234270
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, [sp, #0x14]
	ldr r4, [sp, #0x18]
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	bl FUN_08234208
	movs r0, #0
	str r0, [r5, #8]
	ldr r1, _082342A4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #0x18]
	str r0, [r5, #0xc]
	cmp r0, #0
	beq _08234296
	str r5, [r0, #8]
_08234296:
	ldr r0, [r1]
	str r5, [r0, #0x18]
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_082342A4: .4byte 0x030046A4

	thumb_func_start FUN_082342a8
FUN_082342a8: @ 0x082342A8
	push {lr}
	ldr r2, [r0, #8]
	ldr r1, [r0, #0xc]
	cmp r2, #0
	beq _082342B6
	str r1, [r2, #0xc]
	b _082342BC
_082342B6:
	ldr r0, _082342C8 @ =0x030046A4
	ldr r0, [r0]
	str r1, [r0, #0x18]
_082342BC:
	cmp r1, #0
	beq _082342C2
	str r2, [r1, #8]
_082342C2:
	pop {r0}
	bx r0
	.align 2, 0
_082342C8: .4byte 0x030046A4

	thumb_func_start FUN_082342cc
FUN_082342cc: @ 0x082342CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r1, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r0, r1
	adds r0, #0x80
	mov sb, r0
	movs r2, #2
	ldrsh r6, [r4, r2]
	ands r6, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	ands r0, r1
	adds r0, #0x80
	mov r8, r0
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0823431E
	cmp r1, #0
	blt _0823431E
	ldr r0, _08234324 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0823431E
	ldr r0, _08234328 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823432C
_0823431E:
	movs r5, #0
	b _0823433A
	.align 2, 0
_08234324: .4byte 0x030046A8
_08234328: .4byte 0x030046AC
_0823432C:
	ldr r0, _0823434C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0823433A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08234350
	adds r0, #4
	b _0823435C
	.align 2, 0
_0823434C: .4byte 0x030046A4
_08234350:
	ldr r0, _082343CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823435C:
	cmp r0, #0
	bne _08234362
	b _082345D8
_08234362:
	ldrb r0, [r0]
	movs r1, #0xf
	mov sl, r1
	mov r2, sl
	ands r2, r0
	mov sl, r2
	movs r1, #0xff
	ldrb r0, [r4]
	cmp r0, r7
	bge _08234400
	ldrh r0, [r4, #4]
	ands r1, r0
	cmp r1, r7
	bge _08234380
	b _082345D8
_08234380:
	mov r1, sb
	lsls r0, r1, #0x10
	ldr r3, _082343D0 @ =0xFFFF0000
	lsls r1, r6, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	mov r1, r8
	adds r1, #0xff
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sp
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _082343C6
	cmp r1, #0
	blt _082343C6
	ldr r0, _082343D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _082343C6
	ldr r0, _082343D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082343DC
_082343C6:
	movs r4, #0
	b _082343EA
	.align 2, 0
_082343CC: .4byte 0x030046A4
_082343D0: .4byte 0xFFFF0000
_082343D4: .4byte 0x030046A8
_082343D8: .4byte 0x030046AC
_082343DC:
	ldr r0, _082343FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_082343EA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082343F8
	b _082345AE
_082343F8:
	b _082345B8
	.align 2, 0
_082343FC: .4byte 0x030046A4
_08234400:
	ldrh r0, [r4, #4]
	ands r1, r0
	cmp r1, r7
	bge _0823440A
	b _08234554
_0823440A:
	mov r1, sb
	adds r1, #0xff
	mov r0, sp
	strh r1, [r0]
	strh r6, [r0, #2]
	mov r2, r8
	strh r2, [r0, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r2, r0, #0x18
	adds r7, r1, #0
	cmp r3, #0
	blt _0823443E
	cmp r2, #0
	blt _0823443E
	ldr r0, _08234444 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0823443E
	ldr r0, _08234448 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _0823444C
_0823443E:
	movs r4, #0
	b _0823445A
	.align 2, 0
_08234444: .4byte 0x030046A8
_08234448: .4byte 0x030046AC
_0823444C:
	ldr r0, _0823446C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0823445A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08234470
	adds r0, #4
	b _0823447C
	.align 2, 0
_0823446C: .4byte 0x030046A4
_08234470:
	ldr r0, _082344C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823447C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp sl, r0
	bge _08234488
	b _082345CE
_08234488:
	mov r0, sp
	mov r1, sb
	strh r1, [r0]
	strh r6, [r0, #2]
	mov r1, r8
	adds r1, #0xff
	strh r1, [r0, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	lsls r0, r1, #0x10
	asrs r2, r0, #0x18
	adds r5, r1, #0
	cmp r3, #0
	blt _082344BA
	cmp r2, #0
	blt _082344BA
	ldr r0, _082344C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _082344BA
	ldr r0, _082344C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _082344CC
_082344BA:
	movs r4, #0
	b _082344DA
	.align 2, 0
_082344C0: .4byte 0x030046A4
_082344C4: .4byte 0x030046A8
_082344C8: .4byte 0x030046AC
_082344CC:
	ldr r0, _082344EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_082344DA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082344F0
	adds r0, #4
	b _082344FC
	.align 2, 0
_082344EC: .4byte 0x030046A4
_082344F0:
	ldr r0, _08234548 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_082344FC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp sl, r0
	blt _082345CE
	mov r0, sp
	strh r7, [r0]
	strh r6, [r0, #2]
	strh r5, [r0, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r0, r5, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	bge _0823451E
	b _082343C6
_0823451E:
	cmp r1, #0
	bge _08234524
	b _082343C6
_08234524:
	ldr r0, _0823454C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	blo _0823452E
	b _082343C6
_0823452E:
	ldr r0, _08234550 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08234538
	b _082343C6
_08234538:
	ldr r0, _08234548 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
	b _082343EA
	.align 2, 0
_08234548: .4byte 0x030046A4
_0823454C: .4byte 0x030046A8
_08234550: .4byte 0x030046AC
_08234554:
	mov r1, sb
	adds r1, #0xff
	mov r0, sp
	strh r1, [r0]
	strh r6, [r0, #2]
	mov r2, r8
	strh r2, [r0, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08234586
	cmp r1, #0
	blt _08234586
	ldr r0, _0823458C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08234586
	ldr r0, _08234590 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08234594
_08234586:
	movs r4, #0
	b _082345A2
	.align 2, 0
_0823458C: .4byte 0x030046A8
_08234590: .4byte 0x030046AC
_08234594:
	ldr r0, _082345B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_082345A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082345B8
_082345AE:
	adds r0, #4
	b _082345C4
	.align 2, 0
_082345B4: .4byte 0x030046A4
_082345B8:
	ldr r0, _082345D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_082345C4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp sl, r0
	bge _082345D8
_082345CE:
	movs r0, #1
	b _082345DA
	.align 2, 0
_082345D4: .4byte 0x030046A4
_082345D8:
	movs r0, #0
_082345DA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082345ec
FUN_082345ec: @ 0x082345EC
	ldr r0, _082345F4 @ =0x0300077C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_082345F4: .4byte 0x0300077C

	thumb_func_start FUN_082345f8
FUN_082345f8: @ 0x082345F8
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08234618 @ =0x0000DCFB
	bl FUN_082310cc
	ldr r1, _0823461C @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0xc]
	ldr r1, _08234620 @ =0x0300077C
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08234618: .4byte 0x0000DCFB
_0823461C: .4byte 0x030046A4
_08234620: .4byte 0x0300077C

	thumb_func_start FUN_08234624
FUN_08234624: @ 0x08234624
	ldr r1, _08234634 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0xc]
	ldr r1, _08234638 @ =0x0300077C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08234634: .4byte 0x030046A4
_08234638: .4byte 0x0300077C
_0823463C:
	.byte 0x70, 0xB5, 0x05, 0x1C
	.byte 0x00, 0x24, 0xE8, 0x78, 0x84, 0x42, 0x08, 0xDA, 0x2E, 0x1C, 0x08, 0x36, 0x01, 0xCE, 0x00, 0xF0
	.byte 0x97, 0xF9, 0x01, 0x34, 0xE8, 0x78, 0x84, 0x42, 0xF8, 0xDB, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_08234660
FUN_08234660: @ 0x08234660
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	movs r0, #0
	str r0, [sp]
	ldr r1, _082346D4 @ =0x0300077C
	movs r0, #1
	str r0, [r1]
	mov r0, r8
	ldrb r5, [r0, #3]
	movs r2, #0
	ldr r1, _082346D8 @ =0x030046A4
	ldr r0, [r1]
	ldrh r0, [r0]
	cmp r2, r0
	blt _0823468A
	b _08234848
_0823468A:
	ldr r3, _082346DC @ =0x00001516
	mov sl, r3
_0823468E:
	movs r0, #0x2c
	muls r0, r2, r0
	movs r7, #0x89
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r1, [r1]
	adds r1, r1, r0
	mov ip, r1
	ldrh r0, [r1, #6]
	mov r1, r8
	ldrh r1, [r1]
	cmp r0, r1
	beq _082346B4
	adds r3, r2, #1
	mov sb, r3
	ldr r7, _082346E0 @ =0x000014C9
	cmp r0, r7
	beq _082346B4
	b _0823483A
_082346B4:
	mov r0, ip
	ldrh r1, [r0, #0xc]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _082346E8
	ldr r0, _082346E4 @ =0x030044E0
	ldrh r1, [r0, #2]
	mov r3, ip
	ldr r0, [r3, #0x20]
	ands r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	b _082346EA
	.align 2, 0
_082346D4: .4byte 0x0300077C
_082346D8: .4byte 0x030046A4
_082346DC: .4byte 0x00001516
_082346E0: .4byte 0x000014C9
_082346E4: .4byte 0x030044E0
_082346E8:
	movs r0, #1
_082346EA:
	adds r2, #1
	mov sb, r2
	cmp r0, #0
	beq _082347C4
	mov r7, r8
	ldr r7, [r7, #4]
	str r7, [sp, #4]
	mov r0, ip
	ldr r2, [r0, #0x28]
	movs r4, #0
	ldrh r6, [r0, #0xe]
	cmp r4, r6
	bge _082347C4
	movs r1, #0
	ldrsh r3, [r7, r1]
_08234708:
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp r3, r0
	blt _0823472E
	movs r1, #4
	ldrsh r0, [r2, r1]
	cmp r3, r0
	bge _0823472E
	ldr r7, [sp, #4]
	movs r0, #4
	ldrsh r1, [r7, r0]
	movs r7, #2
	ldrsh r0, [r2, r7]
	cmp r1, r0
	blt _0823472E
	movs r7, #6
	ldrsh r0, [r2, r7]
	cmp r1, r0
	blt _08234738
_0823472E:
	adds r2, #0xc
	adds r4, #1
	cmp r4, r6
	blt _08234708
	b _082347C4
_08234738:
	mov r7, r8
	adds r7, #8
	mov r6, sp
	movs r2, #0
	mov r0, ip
	ldr r4, [r0]
	cmp r2, r5
	bge _0823476C
	adds r3, r4, #0
	adds r1, r7, #0
_0823474C:
	ldr r0, [r1]
	cmp r0, r3
	bne _08234764
	str r2, [r6]
	mov r3, ip
	ldrh r1, [r3, #4]
	ldr r0, _08234760 @ =0x0000A5BF
	cmp r1, r0
	beq _082347AE
	b _082347A4
	.align 2, 0
_08234760: .4byte 0x0000A5BF
_08234764:
	adds r1, #4
	adds r2, #1
	cmp r2, r5
	blt _0823474C
_0823476C:
	lsls r0, r5, #2
	adds r0, r0, r7
	str r4, [r0]
	str r5, [r6]
	mov r7, ip
	ldrh r1, [r7, #4]
	ldr r0, _0823479C @ =0x00000DD2
	cmp r1, r0
	beq _0823478E
	ldr r0, _082347A0 @ =0x000014C9
	cmp r1, r0
	beq _0823478E
	cmp r1, sl
	beq _0823478E
	adds r0, #0x4e
	cmp r1, r0
	bne _08234798
_0823478E:
	mov r0, r8
	mov r1, ip
	ldr r2, _0823479C @ =0x00000DD2
	bl FUN_08234868
_08234798:
	adds r5, #1
	b _0823483A
	.align 2, 0
_0823479C: .4byte 0x00000DD2
_082347A0: .4byte 0x000014C9
_082347A4:
	cmp r1, sl
	beq _082347AE
	ldr r0, _082347BC @ =0x00001517
	cmp r1, r0
	bne _0823483A
_082347AE:
	mov r0, r8
	mov r1, ip
	ldr r2, _082347C0 @ =0x0000A5BF
	bl FUN_08234868
	b _0823483A
	.align 2, 0
_082347BC: .4byte 0x00001517
_082347C0: .4byte 0x0000A5BF
_082347C4:
	mov r4, sp
	movs r2, #0
	cmp r2, r5
	bge _08234814
	mov r3, r8
	adds r3, #8
	adds r6, r3, #0
_082347D2:
	ldr r1, [r3]
	mov r7, ip
	ldr r0, [r7]
	cmp r1, r0
	bne _0823480C
	str r2, [r4]
	cmp r2, r5
	bge _08234808
	subs r4, r5, #1
	adds r3, r6, #0
	movs r6, #0
_082347E8:
	cmp r2, r4
	bge _082347FC
	lsls r1, r2, #2
	adds r1, r3, r1
	adds r2, #1
	lsls r0, r2, #2
	adds r0, r3, r0
	ldr r0, [r0]
	str r0, [r1]
	b _08234804
_082347FC:
	lsls r0, r2, #2
	adds r0, r3, r0
	str r6, [r0]
	adds r2, #1
_08234804:
	cmp r2, r5
	blt _082347E8
_08234808:
	movs r0, #1
	b _08234816
_0823480C:
	adds r3, #4
	adds r2, #1
	cmp r2, r5
	blt _082347D2
_08234814:
	movs r0, #0
_08234816:
	cmp r0, #1
	bne _0823483A
	subs r5, #1
	mov r0, ip
	ldrh r1, [r0, #4]
	ldr r0, _0823485C @ =0x0000D5CC
	cmp r1, r0
	beq _08234830
	ldr r3, _08234860 @ =0x000014C9
	cmp r1, r3
	beq _08234830
	cmp r1, sl
	bne _0823483A
_08234830:
	mov r0, r8
	mov r1, ip
	ldr r2, _0823485C @ =0x0000D5CC
	bl FUN_08234868
_0823483A:
	mov r2, sb
	ldr r1, _08234864 @ =0x030046A4
	ldr r0, [r1]
	ldrh r0, [r0]
	cmp r2, r0
	bge _08234848
	b _0823468E
_08234848:
	mov r7, r8
	strb r5, [r7, #3]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823485C: .4byte 0x0000D5CC
_08234860: .4byte 0x000014C9
_08234864: .4byte 0x030046A4

	thumb_func_start FUN_08234868
FUN_08234868: @ 0x08234868
	push {r4, r5, lr}
	sub sp, #0x40
	mov ip, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r1, [r0]
	str r1, [sp]
	mov r3, ip
	ldrh r1, [r3, #8]
	str r1, [sp, #4]
	add r3, sp, #8
	stm r3!, {r2}
	ldr r1, [r0, #4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	stm r3!, {r0}
	movs r2, #2
	ldrsh r0, [r1, r2]
	stm r3!, {r0}
	movs r2, #4
	ldrsh r0, [r1, r2]
	stm r3!, {r0}
	add r4, sp, #0x38
	mov r1, ip
	adds r1, #0x10
	movs r2, #3
_0823489C:
	ldrh r0, [r1]
	stm r3!, {r0}
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0823489C
	mov r0, ip
	ldr r5, [r0, #0x24]
	mov r1, ip
	adds r1, #0x18
	movs r2, #3
_082348B2:
	ldrh r0, [r1]
	stm r3!, {r0}
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _082348B2
	ldr r1, _082348E4 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r1
	movs r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x38]
	mov r2, sp
	str r2, [r4, #4]
	mov r3, ip
	ldrh r1, [r3, #0xc]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _082348E8
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823a8a4
	b _082348F0
	.align 2, 0
_082348E4: .4byte 0xFFFF0000
_082348E8:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823a88c
_082348F0:
	add sp, #0x40
	pop {r4, r5}
	pop {r0}
	bx r0
_082348F8:
	.byte 0x10, 0xB5, 0x00, 0x04, 0x04, 0x0C, 0x00, 0x22
	.byte 0x05, 0x48, 0x00, 0x68, 0xC1, 0x68, 0x08, 0x78, 0x82, 0x42, 0x0B, 0xDA, 0x03, 0x1C, 0xC8, 0x89
	.byte 0xA0, 0x42, 0x03, 0xD1, 0x01, 0x20, 0x06, 0xE0, 0xA4, 0x46, 0x00, 0x03, 0x0C, 0x31, 0x01, 0x32
	.byte 0x9A, 0x42, 0xF4, 0xDB, 0x00, 0x20, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_0823492c
FUN_0823492c: @ 0x0823492C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r0, #0
	strh r0, [r1]
	movs r5, #0
	movs r4, #0
	ldr r6, _0823497C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #0xc]
	ldrb r0, [r0]
	cmp r5, r0
	bge _08234972
	mov ip, r6
	movs r3, #4
_0823494A:
	mov r2, ip
	ldr r0, [r2]
	ldr r0, [r0, #0xc]
	adds r2, r0, r3
	ldrh r0, [r2, #0xa]
	cmp r0, r7
	bne _08234964
	cmp r5, #0
	bne _0823495E
	adds r5, r2, #0
_0823495E:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08234964:
	adds r3, #0xc
	adds r4, #1
	ldr r0, [r6]
	ldr r0, [r0, #0xc]
	ldrb r0, [r0]
	cmp r4, r0
	blt _0823494A
_08234972:
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823497C: .4byte 0x030046A4

	thumb_func_start FUN_08234980
FUN_08234980: @ 0x08234980
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #0
	ldr r0, _082349A4 @ =0x030046A4
	ldr r1, [r0]
	ldr r0, [r1, #0xc]
	ldrb r0, [r0]
	cmp r2, r0
	bge _082349B0
	adds r3, r0, #0
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
_0823499A:
	ldr r0, [r1]
	cmp r0, r4
	bne _082349A8
	adds r0, r1, #0
	b _082349B2
	.align 2, 0
_082349A4: .4byte 0x030046A4
_082349A8:
	adds r1, #0x2c
	adds r2, #1
	cmp r2, r3
	blt _0823499A
_082349B0:
	movs r0, #0
_082349B2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_082349b8
FUN_082349b8: @ 0x082349B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	str r1, [sp]
	ldr r1, _08234A64 @ =0x030046B0
	ldr r0, [r1]
	ldr r2, _08234A68 @ =0x030046A4
	mov r8, r2
	cmp r0, #0
	bne _082349D8
	movs r0, #1
	str r0, [r1]
_082349D8:
	ldr r0, [r1]
	mov r3, sb
	str r0, [r3]
	adds r0, #1
	str r0, [r1]
	movs r4, #0
	mov r6, r8
	ldr r1, [r6]
	ldrh r5, [r1]
	cmp r5, #0
	ble _08234A26
	subs r2, r5, #1
	movs r0, #0x2c
	muls r0, r2, r0
	adds r0, r1, r0
	movs r7, #0x8b
	lsls r7, r7, #2
	adds r0, r0, r7
	ldrh r1, [r3, #8]
	adds r3, r1, #0
	ldrh r0, [r0]
	cmp r3, r0
	beq _08234A70
_08234A06:
	adds r5, r2, #0
	cmp r5, #0
	ble _08234A26
	mov r0, r8
	ldr r1, [r0]
	subs r2, r5, #1
	movs r0, #0x2c
	muls r0, r2, r0
	adds r1, r1, r0
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r1, r1, r6
	ldrh r1, [r1]
	cmp r3, r1
	bne _08234A06
	movs r4, #1
_08234A26:
	cmp r4, #0
	bne _08234A70
	mov r7, r8
	ldr r1, [r7]
	ldrh r2, [r1]
	movs r0, #0x2c
	muls r0, r2, r0
	adds r1, r1, r0
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
	mov r0, sb
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r2, r7}
	stm r1!, {r2, r7}
	mov r3, r8
	ldr r0, [r3]
	ldrh r1, [r0]
	lsls r1, r1, #2
	ldr r4, _08234A6C @ =0x00000D24
	adds r0, r0, r4
	adds r0, r0, r1
	ldr r6, [sp]
	str r6, [r0]
	b _08234AFC
	.align 2, 0
_08234A64: .4byte 0x030046B0
_08234A68: .4byte 0x030046A4
_08234A6C: .4byte 0x00000D24
_08234A70:
	mov r7, r8
	ldr r0, [r7]
	ldrh r4, [r0]
	lsls r0, r5, #2
	str r0, [sp, #4]
	cmp r4, r5
	ble _08234ACA
	mov ip, r8
	ldr r1, _08234B18 @ =0x00000D24
	mov sl, r1
_08234A84:
	mov r2, ip
	ldr r1, [r2]
	movs r3, #0x2c
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r1, r0
	subs r3, r4, #1
	movs r6, #0x2c
	adds r2, r3, #0
	muls r2, r6, r2
	adds r1, r1, r2
	movs r7, #0x89
	lsls r7, r7, #2
	adds r0, r0, r7
	adds r1, r1, r7
	ldm r1!, {r2, r6, r7}
	stm r0!, {r2, r6, r7}
	ldm r1!, {r2, r6, r7}
	stm r0!, {r2, r6, r7}
	ldm r1!, {r2, r6, r7}
	stm r0!, {r2, r6, r7}
	ldm r1!, {r2, r6}
	stm r0!, {r2, r6}
	mov r7, ip
	ldr r1, [r7]
	lsls r2, r4, #2
	add r1, sl
	adds r2, r1, r2
	lsls r0, r3, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	adds r4, r3, #0
	cmp r4, r5
	bgt _08234A84
_08234ACA:
	mov r0, r8
	ldr r1, [r0]
	movs r0, #0x2c
	muls r0, r5, r0
	adds r1, r1, r0
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r1, r2
	mov r0, sb
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r4, r6, r7}
	stm r1!, {r4, r6, r7}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	mov r4, r8
	ldr r0, [r4]
	ldr r6, _08234B18 @ =0x00000D24
	adds r0, r0, r6
	ldr r7, [sp, #4]
	adds r0, r0, r7
	ldr r1, [sp]
	str r1, [r0]
_08234AFC:
	mov r2, r8
	ldr r1, [r2]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08234B18: .4byte 0x00000D24

	thumb_func_start FUN_08234b1c
FUN_08234b1c: @ 0x08234B1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _08234B38 @ =0x030046A4
	ldr r0, [r0]
	ldrh r5, [r0]
	movs r0, #0x6e
	bl prepare_08231510
	b _08234BB0
	.align 2, 0
_08234B38: .4byte 0x030046A4
_08234B3C:
	ldr r1, _08234BD0 @ =0x030046A4
	ldr r0, [r1]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r0, r2
	ldr r6, _08234BD4 @ =0x00000D24
	adds r6, r6, r0
	mov sl, r6
	movs r7, #0
	mov sb, r7
	str r1, [sp]
	bl fetch_082316e4
	mov r8, r0
	ldr r1, [sp]
	cmp sb, r5
	bge _08234BAE
	mov ip, r1
	adds r2, r5, #0
	movs r3, #0
_08234B64:
	ldrh r0, [r4, #8]
	cmp r8, r0
	beq _08234BA2
	mov r5, ip
	ldr r1, [r5]
	adds r1, r1, r3
	movs r6, #0x89
	lsls r6, r6, #2
	adds r1, r1, r6
	adds r0, r4, #0
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r7}
	stm r1!, {r5, r7}
	mov r6, ip
	ldr r0, [r6]
	mov r7, sb
	lsls r1, r7, #2
	ldr r5, _08234BD4 @ =0x00000D24
	adds r0, r0, r5
	adds r0, r0, r1
	mov r6, sl
	ldr r1, [r6]
	str r1, [r0]
	adds r3, #0x2c
	movs r7, #1
	add sb, r7
_08234BA2:
	subs r2, #1
	adds r4, #0x2c
	movs r0, #4
	add sl, r0
	cmp r2, #0
	bne _08234B64
_08234BAE:
	mov r5, sb
_08234BB0:
	bl FUN_082316bc
	cmp r0, #0
	bne _08234B3C
	ldr r0, _08234BD0 @ =0x030046A4
	ldr r0, [r0]
	strh r5, [r0]
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08234BD0: .4byte 0x030046A4
_08234BD4: .4byte 0x00000D24

	thumb_func_start FUN_08234bd8
FUN_08234bd8: @ 0x08234BD8
	push {lr}
	movs r1, #0x2c
	bl FUN_082309cc
	pop {r0}
	bx r0

	thumb_func_start FUN_08234be4
FUN_08234be4: @ 0x08234BE4
	push {r4, r5, lr}
	sub sp, #0xc
	bl FUN_082316bc
	cmp r0, #0
	beq _08234C04
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_0823492c
	adds r5, r0, #0
	cmp r5, #0
	bne _08234C0A
_08234C04:
	movs r0, #1
	rsbs r0, r0, #0
	b _08234CF0
_08234C0A:
	add r4, sp, #4
	adds r0, r4, #0
	bl FUN_0823167c
	movs r0, #0
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #8]
	lsls r2, r2, #4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	movs r0, #2
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	movs r0, #4
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #9]
	lsls r2, r2, #4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	movs r0, #6
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	adds r3, r4, #0
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #0
	ldrsh r0, [r5, r2]
	adds r0, r1, r0
	cmp r0, #0
	blt _08234C92
	asrs r2, r0, #1
	b _08234C98
_08234C92:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r2, r0, #0
_08234C98:
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	adds r3, r4, #0
	ldrb r1, [r5, #9]
	ldrb r0, [r5, #8]
	adds r0, r1, r0
	cmp r0, #0
	blt _08234CB6
	asrs r0, r0, #1
	b _08234CBC
_08234CB6:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08234CBC:
	lsls r2, r0, #4
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	adds r3, r4, #0
	movs r0, #6
	ldrsh r1, [r5, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r0, r1, r0
	cmp r0, #0
	blt _08234CE0
	asrs r2, r0, #1
	b _08234CE6
_08234CE0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r2, r0, #0
_08234CE6:
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0823206c
	movs r0, #0
_08234CF0:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08234cf8
FUN_08234cf8: @ 0x08234CF8
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_0823492c
	adds r1, r0, #0
	cmp r1, #0
	beq _08234D1C
	ldrh r0, [r1]
	strh r0, [r4]
	ldrb r0, [r1, #8]
	lsls r0, r0, #4
	strh r0, [r4, #2]
	ldrh r0, [r1, #2]
	strh r0, [r4, #4]
_08234D1C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08234d24
FUN_08234d24: @ 0x08234D24
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_0823492c
	adds r1, r0, #0
	cmp r1, #0
	beq _08234D48
	ldrh r0, [r1, #4]
	strh r0, [r4]
	ldrb r0, [r1, #9]
	lsls r0, r0, #4
	strh r0, [r4, #2]
	ldrh r0, [r1, #6]
	strh r0, [r4, #4]
_08234D48:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08234d50
FUN_08234d50: @ 0x08234D50
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_0823492c
	adds r2, r0, #0
	cmp r2, #0
	bne _08234D6C
	b _08234DAC
_08234D68:
	movs r0, #1
	b _08234DAE
_08234D6C:
	movs r4, #0
	mov r0, sp
	ldrh r0, [r0]
	cmp r4, r0
	bhs _08234DAC
	movs r1, #0
	ldrsh r3, [r5, r1]
	adds r6, r0, #0
_08234D7C:
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp r3, r0
	blt _08234DA0
	movs r1, #4
	ldrsh r0, [r2, r1]
	cmp r3, r0
	bge _08234DA0
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r7, #2
	ldrsh r0, [r2, r7]
	cmp r1, r0
	blt _08234DA0
	movs r7, #6
	ldrsh r0, [r2, r7]
	cmp r1, r0
	blt _08234D68
_08234DA0:
	adds r2, #0xc
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r6
	blo _08234D7C
_08234DAC:
	movs r0, #0
_08234DAE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08234db8
FUN_08234db8: @ 0x08234DB8
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08234DD4 @ =0x0000D4FB
	bl FUN_082310cc
	ldr r1, _08234DD8 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0x10]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08234DD4: .4byte 0x0000D4FB
_08234DD8: .4byte 0x030046A4

	thumb_func_start FUN_08234ddc
FUN_08234ddc: @ 0x08234DDC
	ldr r1, _08234DE4 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0x10]
	bx lr
	.align 2, 0
_08234DE4: .4byte 0x030046A4

	thumb_func_start FUN_08234de8
FUN_08234de8: @ 0x08234DE8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldr r0, _08234E10 @ =0x030046A4
	ldr r0, [r0]
	ldr r2, [r0, #0x10]
	ldrh r0, [r2]
	cmp r5, r0
	bhs _08234E0A
	lsls r0, r5, #2
	adds r0, #4
	adds r1, r2, r0
	adds r6, r1, #0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08234E14
_08234E0A:
	movs r0, #0
	b _08234E36
	.align 2, 0
_08234E10: .4byte 0x030046A4
_08234E14:
	ldrb r1, [r1]
	cmp r3, r1
	blo _08234E1C
	movs r3, #0
_08234E1C:
	ldrh r0, [r6, #2]
	adds r1, r2, r0
	movs r0, #0
	strb r5, [r4]
	strb r7, [r4, #1]
	strb r3, [r4, #2]
	strb r0, [r4, #3]
	str r6, [r4, #4]
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r0, r1, r0
	str r0, [r4, #8]
	movs r0, #1
_08234E36:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08234e3c
FUN_08234e3c: @ 0x08234E3C
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #2]
	adds r0, #1
	movs r3, #0
	strb r0, [r2, #2]
	ldr r1, [r2, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08234E56
	strb r3, [r2, #2]
_08234E56:
	strb r3, [r2, #3]
	ldr r0, _08234E74 @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, [r2, #4]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrb r0, [r2, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r2, #8]
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_08234E74: .4byte 0x030046A4

	thumb_func_start FUN_08234e78
FUN_08234e78: @ 0x08234E78
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r2, #0
	mov r8, r3
	ldr r3, [r0, #8]
	ldrh r4, [r3]
	ldr r2, _08234EE8 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r4
	ldrh r0, [r3, #2]
	ands r2, r7
	adds r7, r2, #0
	orrs r7, r0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r3, #0
	ldrsh r2, [r1, r3]
	subs r2, r0, r2
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r1, r3]
	subs r4, r0, r1
	adds r0, r2, #0
	adds r1, r4, #0
	str r2, [sp]
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov r0, r8
	strb r3, [r0]
	ldr r2, [sp]
	adds r1, r2, #0
	cmp r2, #0
	bge _08234ECA
	rsbs r1, r2, #0
_08234ECA:
	ldr r0, [sp, #0x1c]
	cmp r1, r0
	bhi _08234EEC
	adds r1, r4, #0
	cmp r4, #0
	bge _08234ED8
	rsbs r1, r4, #0
_08234ED8:
	ldr r0, [sp, #0x20]
	cmp r1, r0
	bhi _08234EEC
	strh r2, [r5]
	strh r4, [r5, #4]
	movs r0, #1
	b _08234F36
	.align 2, 0
_08234EE8: .4byte 0xFFFF0000
_08234EEC:
	ldr r2, _08234F0C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp, #0x24]
	muls r0, r1, r0
	cmp r0, #0
	blt _08234F10
	asrs r0, r0, #0xc
	b _08234F16
	.align 2, 0
_08234F0C: .4byte 0x085B0A08
_08234F10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08234F16:
	strh r0, [r5]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x24]
	muls r0, r3, r0
	cmp r0, #0
	blt _08234F2C
	asrs r0, r0, #0xc
	b _08234F32
_08234F2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08234F32:
	strh r0, [r5, #4]
	movs r0, #0
_08234F36:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08234f44
FUN_08234f44: @ 0x08234F44
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _08234F60 @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldrh r0, [r1]
	cmp r2, r0
	bhs _08234F64
	lsls r0, r2, #2
	adds r0, #4
	adds r0, r1, r0
	b _08234F66
	.align 2, 0
_08234F60: .4byte 0x030046A4
_08234F64:
	movs r0, #0
_08234F66:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08234f6c
FUN_08234f6c: @ 0x08234F6C
	adds r1, r0, #0
	ldr r0, _08234F7C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08234F7C: .4byte 0x030046A4

	thumb_func_start FUN_08234f80
FUN_08234f80: @ 0x08234F80
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x15
	adds r2, r2, r1
	ldrh r1, [r2]
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r0, #4]
	bx lr

	thumb_func_start FUN_08234f90
FUN_08234f90: @ 0x08234F90
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	bl FUN_08234f44
	bl FUN_08234f6c
	adds r1, r0, #0
	cmp r1, #0
	beq _08234FB8
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08234f80
	movs r0, #0
	b _08234FC0
_08234FB8:
	strh r1, [r4]
	strh r1, [r4, #4]
	movs r0, #1
	rsbs r0, r0, #0
_08234FC0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08234FC8:
	.byte 0x30, 0xB5, 0x84, 0xB0, 0xFC, 0xF7, 0x8A, 0xFB
	.byte 0x04, 0x1C, 0xFC, 0xF7, 0x87, 0xFB, 0x02, 0x1C, 0x6D, 0x46, 0x24, 0x06, 0x24, 0x0E, 0x12, 0x06
	.byte 0x12, 0x0E, 0x68, 0x46, 0x21, 0x1C, 0xFF, 0xF7, 0xD3, 0xFF, 0x00, 0x28, 0x1E, 0xDB, 0x02, 0xAC
	.byte 0x20, 0x1C, 0xFC, 0xF7, 0x43, 0xFB, 0x68, 0x46, 0x00, 0x21, 0x42, 0x5E, 0x20, 0x1C, 0x00, 0x21
	.byte 0xFD, 0xF7, 0x34, 0xF8, 0x20, 0x1C, 0xFC, 0xF7, 0x39, 0xFB, 0x02, 0x20, 0x2A, 0x5E, 0x20, 0x1C
	.byte 0x00, 0x21, 0xFD, 0xF7, 0x2B, 0xF8, 0x20, 0x1C, 0xFC, 0xF7, 0x30, 0xFB, 0x04, 0x21, 0x6A, 0x5E
	.byte 0x20, 0x1C, 0x00, 0x21, 0xFD, 0xF7, 0x22, 0xF8, 0x00, 0x20, 0x01, 0xE0, 0x01, 0x20, 0x40, 0x42
	.byte 0x04, 0xB0, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_08235038
FUN_08235038: @ 0x08235038
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r7, r2, #0
	mov ip, r3
	ldr r2, [r0, #8]
	ldrh r3, [r2]
	ldr r1, _08235084 @ =0xFFFF0000
	adds r0, r1, #0
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r3
	ldrh r0, [r2, #2]
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
	adds r2, r5, #0
	movs r0, #0
	ldrsh r1, [r6, r0]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r0, r1, r0
	cmp r0, #0
	bge _08235068
	rsbs r0, r0, #0
_08235068:
	cmp r0, r7
	bhi _08235088
	movs r0, #4
	ldrsh r1, [r6, r0]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, r1, r0
	cmp r0, #0
	bge _0823507C
	rsbs r0, r0, #0
_0823507C:
	cmp r0, ip
	bhi _08235088
	movs r0, #0
	b _0823508A
	.align 2, 0
_08235084: .4byte 0xFFFF0000
_08235088:
	movs r0, #1
_0823508A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08235090
FUN_08235090: @ 0x08235090
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r0, r4, #0
	bl FUN_08234f44
	adds r3, r0, #0
	cmp r3, #0
	beq _082350AA
	ldrb r0, [r3]
	cmp r0, #0
	bne _082350B6
_082350AA:
	movs r0, #0
	strh r0, [r5]
	strh r0, [r5, #2]
	strh r0, [r5, #4]
	subs r0, #1
	b _08235170
_082350B6:
	ldr r2, _08235108 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0823510C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08235110 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrb r1, [r3]
	bl Mod
	adds r6, r0, #0
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08234f90
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08235102
	cmp r1, #0
	blt _08235102
	ldr r0, _08235114 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08235102
	ldr r0, _08235118 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823511C
_08235102:
	movs r4, #0
	b _0823512A
	.align 2, 0
_08235108: .4byte 0x030046B8
_0823510C: .4byte 0x000003FF
_08235110: .4byte 0x0203B400
_08235114: .4byte 0x030046A8
_08235118: .4byte 0x030046AC
_0823511C:
	ldr r0, _0823513C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823512A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235140
	adds r0, #4
	b _0823514C
	.align 2, 0
_0823513C: .4byte 0x030046A4
_08235140:
	ldr r0, _08235160 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823514C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08235164
	cmp r2, #2
	beq _08235168
	b _0823516C
	.align 2, 0
_08235160: .4byte 0x030046A4
_08235164:
	ldrb r0, [r5, #4]
	b _0823516A
_08235168:
	ldrb r0, [r5]
_0823516A:
	subs r1, r1, r0
_0823516C:
	strh r1, [r5, #2]
	adds r0, r6, #0
_08235170:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08235178
FUN_08235178: @ 0x08235178
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov sb, r1
	adds r0, r2, #0
	movs r1, #1
	rsbs r1, r1, #0
	mov sl, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov r8, r0
	cmp r0, #0
	beq _082351A4
	ldrb r0, [r0]
	cmp r0, #0
	bne _082351AE
_082351A4:
	movs r0, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strh r0, [r6, #4]
	b _082352AE
_082351AE:
	mov r0, r8
	bl FUN_08234f6c
	str r0, [sp, #0xc]
	cmp r0, #0
	bne _082351CE
	mov r7, sp
	ldrh r7, [r7, #0xc]
	strh r7, [r6]
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r6, #2]
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r6, #4]
	b _082352AE
_082351CE:
	mov r3, sl
	movs r5, #0
	mov r7, r8
	ldrb r7, [r7]
	cmp r5, r7
	bge _0823522A
	mov r4, sp
_082351DC:
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	ldr r1, [sp, #0xc]
	str r3, [sp, #8]
	bl FUN_08234f80
	mov r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r7, #0
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	mov r0, sb
	movs r7, #4
	ldrsh r1, [r0, r7]
	movs r7, #4
	ldrsh r0, [r4, r7]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r0, #0
	adds r0, r1, #0
	muls r0, r1, r0
	adds r2, r2, r0
	ldr r3, [sp, #8]
	cmp r2, r3
	bhs _08235220
	mov sl, r5
	adds r3, r2, #0
	ldrh r0, [r4]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
_08235220:
	adds r5, #1
	mov r1, r8
	ldrb r1, [r1]
	cmp r5, r1
	blt _082351DC
_0823522A:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0823524E
	cmp r1, #0
	blt _0823524E
	ldr r0, _08235254 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0823524E
	ldr r0, _08235258 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823525C
_0823524E:
	movs r4, #0
	b _0823526A
	.align 2, 0
_08235254: .4byte 0x030046A8
_08235258: .4byte 0x030046AC
_0823525C:
	ldr r0, _0823527C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823526A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235280
	adds r0, #4
	b _0823528C
	.align 2, 0
_0823527C: .4byte 0x030046A4
_08235280:
	ldr r0, _082352A0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823528C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _082352A4
	cmp r2, #2
	beq _082352A8
	b _082352AC
	.align 2, 0
_082352A0: .4byte 0x030046A4
_082352A4:
	ldrb r0, [r6, #4]
	b _082352AA
_082352A8:
	ldrb r0, [r6]
_082352AA:
	subs r1, r1, r0
_082352AC:
	strh r1, [r6, #2]
_082352AE:
	mov r0, sl
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_082352c0
FUN_082352c0: @ 0x082352C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov sb, r1
	adds r0, r2, #0
	movs r1, #1
	rsbs r1, r1, #0
	mov sl, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov r8, r0
	cmp r0, #0
	beq _082352EC
	ldrb r0, [r0]
	cmp r0, #0
	bne _082352F6
_082352EC:
	movs r0, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strh r0, [r6, #4]
	b _082353F6
_082352F6:
	mov r0, r8
	bl FUN_08234f6c
	str r0, [sp, #0xc]
	cmp r0, #0
	bne _08235316
	mov r7, sp
	ldrh r7, [r7, #0xc]
	strh r7, [r6]
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r6, #2]
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r6, #4]
	b _082353F6
_08235316:
	movs r3, #0
	movs r5, #0
	mov r7, r8
	ldrb r7, [r7]
	cmp r5, r7
	bge _08235372
	mov r4, sp
_08235324:
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	ldr r1, [sp, #0xc]
	str r3, [sp, #8]
	bl FUN_08234f80
	mov r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r7, #0
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	mov r0, sb
	movs r7, #4
	ldrsh r1, [r0, r7]
	movs r7, #4
	ldrsh r0, [r4, r7]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r0, #0
	adds r0, r1, #0
	muls r0, r1, r0
	adds r2, r2, r0
	ldr r3, [sp, #8]
	cmp r2, r3
	blo _08235368
	mov sl, r5
	adds r3, r2, #0
	ldrh r0, [r4]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
_08235368:
	adds r5, #1
	mov r1, r8
	ldrb r1, [r1]
	cmp r5, r1
	blt _08235324
_08235372:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08235396
	cmp r1, #0
	blt _08235396
	ldr r0, _0823539C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08235396
	ldr r0, _082353A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082353A4
_08235396:
	movs r4, #0
	b _082353B2
	.align 2, 0
_0823539C: .4byte 0x030046A8
_082353A0: .4byte 0x030046AC
_082353A4:
	ldr r0, _082353C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_082353B2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _082353C8
	adds r0, #4
	b _082353D4
	.align 2, 0
_082353C4: .4byte 0x030046A4
_082353C8:
	ldr r0, _082353E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_082353D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _082353EC
	cmp r2, #2
	beq _082353F0
	b _082353F4
	.align 2, 0
_082353E8: .4byte 0x030046A4
_082353EC:
	ldrb r0, [r6, #4]
	b _082353F2
_082353F0:
	ldrb r0, [r6]
_082353F2:
	subs r1, r1, r0
_082353F4:
	strh r1, [r6, #2]
_082353F6:
	mov r0, sl
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08235408
FUN_08235408: @ 0x08235408
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov sb, r1
	adds r0, r2, #0
	str r3, [sp, #8]
	movs r1, #1
	rsbs r1, r1, #0
	mov sl, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov r8, r0
	cmp r0, #0
	beq _08235436
	ldrb r0, [r0]
	cmp r0, #0
	bne _08235440
_08235436:
	movs r0, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strh r0, [r6, #4]
	b _0823555A
_08235440:
	mov r0, r8
	bl FUN_08234f6c
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _08235460
	mov r7, sp
	ldrh r7, [r7, #0x10]
	strh r7, [r6]
	mov r0, sp
	ldrh r0, [r0, #0x10]
	strh r0, [r6, #2]
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r6, #4]
	b _0823555A
_08235460:
	mov r4, sp
	mov r0, sp
	ldr r1, [sp, #0x10]
	movs r2, #0
	bl FUN_08234f80
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
	mov r3, sl
	movs r5, #0
	mov r7, r8
	ldrb r7, [r7]
	cmp r5, r7
	bge _082354D8
	mov r4, sp
_08235484:
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	ldr r1, [sp, #0x10]
	str r3, [sp, #0xc]
	bl FUN_08234f80
	mov r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r7, #0
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	mov r0, sb
	movs r7, #4
	ldrsh r1, [r0, r7]
	movs r7, #4
	ldrsh r0, [r4, r7]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r0, #0
	adds r0, r1, #0
	muls r0, r1, r0
	adds r2, r2, r0
	ldr r3, [sp, #0xc]
	cmp r2, r3
	bhs _082354CE
	ldr r1, [sp, #8]
	cmp r2, r1
	blo _082354CE
	mov sl, r5
	adds r3, r2, #0
	ldrh r0, [r4]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
_082354CE:
	adds r5, #1
	mov r7, r8
	ldrb r7, [r7]
	cmp r5, r7
	blt _08235484
_082354D8:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _082354FC
	cmp r1, #0
	blt _082354FC
	ldr r0, _08235500 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _082354FC
	ldr r0, _08235504 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08235508
_082354FC:
	movs r4, #0
	b _08235516
	.align 2, 0
_08235500: .4byte 0x030046A8
_08235504: .4byte 0x030046AC
_08235508:
	ldr r0, _08235528 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08235516:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823552C
	adds r0, #4
	b _08235538
	.align 2, 0
_08235528: .4byte 0x030046A4
_0823552C:
	ldr r0, _0823554C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235538:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08235550
	cmp r2, #2
	beq _08235554
	b _08235558
	.align 2, 0
_0823554C: .4byte 0x030046A4
_08235550:
	ldrb r0, [r6, #4]
	b _08235556
_08235554:
	ldrb r0, [r6]
_08235556:
	subs r1, r1, r0
_08235558:
	strh r1, [r6, #2]
_0823555A:
	mov r0, sl
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823556c
FUN_0823556c: @ 0x0823556C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	mov sb, r1
	mov sl, r2
	str r3, [sp, #8]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov r8, r0
	cmp r0, #0
	beq _08235594
	ldrb r0, [r0]
	cmp r0, #0
	bne _082355A0
_08235594:
	movs r0, #0
	strh r0, [r7]
	strh r0, [r7, #2]
	strh r0, [r7, #4]
	subs r0, #1
	b _082356B4
_082355A0:
	ldr r2, _0823563C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08235640 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08235644 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, r8
	ldrb r1, [r2]
	bl Mod
	adds r6, r0, #0
	adds r5, r6, #0
	mov r3, r8
	ldrb r1, [r3]
	adds r0, r6, r1
	cmp r6, r0
	bge _082356B2
	mov r4, sp
_082355CC:
	adds r0, r5, #0
	bl Mod
	str r0, [sp, #0xc]
	mov r0, sl
	lsls r1, r0, #0x18
	ldr r3, [sp, #0xc]
	lsls r2, r3, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	lsrs r1, r1, #0x18
	bl FUN_08234f90
	mov r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r2, r2, r0
	mov r0, sb
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	ldr r3, [sp, #8]
	cmp r0, r3
	blo _082356A6
	ldrh r0, [r4]
	strh r0, [r7]
	ldrh r1, [r4, #4]
	strh r1, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08235638
	cmp r1, #0
	blt _08235638
	ldr r0, _08235648 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08235638
	ldr r0, _0823564C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08235650
_08235638:
	movs r4, #0
	b _0823565E
	.align 2, 0
_0823563C: .4byte 0x030046B8
_08235640: .4byte 0x000003FF
_08235644: .4byte 0x0203B400
_08235648: .4byte 0x030046A8
_0823564C: .4byte 0x030046AC
_08235650:
	ldr r0, _08235670 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823565E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235674
	adds r0, #4
	b _08235680
	.align 2, 0
_08235670: .4byte 0x030046A4
_08235674:
	ldr r0, _08235694 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235680:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08235698
	cmp r2, #2
	beq _0823569C
	b _082356A0
	.align 2, 0
_08235694: .4byte 0x030046A4
_08235698:
	ldrb r0, [r7, #4]
	b _0823569E
_0823569C:
	ldrb r0, [r7]
_0823569E:
	subs r1, r1, r0
_082356A0:
	strh r1, [r7, #2]
	ldr r0, [sp, #0xc]
	b _082356B4
_082356A6:
	adds r5, #1
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, r1
	cmp r5, r0
	blt _082355CC
_082356B2:
	adds r0, r6, #0
_082356B4:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_082356c4
FUN_082356c4: @ 0x082356C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x10]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_08234f44
	mov sb, r0
	cmp r0, #0
	beq _082356F2
	ldrb r0, [r0]
	cmp r0, #0
	bne _082356FC
_082356F2:
	movs r0, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strh r0, [r6, #4]
	b _0823584A
_082356FC:
	mov r0, sb
	bl FUN_08234f6c
	mov r8, r0
	cmp r0, #0
	bne _08235712
	mov r2, r8
	strh r2, [r6]
	strh r2, [r6, #2]
	strh r2, [r6, #4]
	b _0823584A
_08235712:
	ldr r2, _0823579C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _082357A0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _082357A4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, sb
	ldrb r1, [r2]
	bl Mod
	mov sl, r0
	mov r4, sp
	mov r0, sp
	mov r1, r8
	movs r2, #0
	bl FUN_08234f80
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6]
	ldrh r0, [r4, #4]
	strh r0, [r6, #4]
	mov r4, sl
	mov r3, sb
	ldrb r1, [r3]
	adds r0, r4, r1
	cmp r4, r0
	bge _082357C6
	mov r5, sp
_08235754:
	adds r0, r4, #0
	bl Mod
	adds r7, r0, #0
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	mov r1, r8
	bl FUN_08234f80
	movs r0, #0
	ldrsh r1, [r5, r0]
	ldr r2, [sp, #8]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _082357A8
	ldr r2, [sp, #0xc]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _082357A8
	movs r0, #4
	ldrsh r1, [r5, r0]
	ldr r2, [sp, #8]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _082357A8
	ldr r2, [sp, #0xc]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bgt _082357A8
	movs r0, #1
	b _082357AA
	.align 2, 0
_0823579C: .4byte 0x030046B8
_082357A0: .4byte 0x000003FF
_082357A4: .4byte 0x0203B400
_082357A8:
	movs r0, #0
_082357AA:
	cmp r0, #0
	beq _082357B8
	str r7, [sp, #0x10]
	ldrh r0, [r5]
	strh r0, [r6]
	ldrh r0, [r5, #4]
	strh r0, [r6, #4]
_082357B8:
	adds r4, #1
	mov r0, sb
	ldrb r1, [r0]
	mov r2, sl
	adds r0, r2, r1
	cmp r4, r0
	blt _08235754
_082357C6:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _082357EA
	cmp r1, #0
	blt _082357EA
	ldr r0, _082357F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _082357EA
	ldr r0, _082357F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082357F8
_082357EA:
	movs r4, #0
	b _08235806
	.align 2, 0
_082357F0: .4byte 0x030046A8
_082357F4: .4byte 0x030046AC
_082357F8:
	ldr r0, _08235818 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08235806:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823581C
	adds r0, #4
	b _08235828
	.align 2, 0
_08235818: .4byte 0x030046A4
_0823581C:
	ldr r0, _0823583C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235828:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08235840
	cmp r2, #2
	beq _08235844
	b _08235848
	.align 2, 0
_0823583C: .4byte 0x030046A4
_08235840:
	ldrb r0, [r6, #4]
	b _08235846
_08235844:
	ldrb r0, [r6]
_08235846:
	subs r1, r1, r0
_08235848:
	strh r1, [r6, #2]
_0823584A:
	ldr r0, [sp, #0x10]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823585c
FUN_0823585c: @ 0x0823585C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r3, #0
	ldr r3, [sp, #0x10]
	movs r0, #1
	rsbs r0, r0, #0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r3, r1, #0
	cmp r2, #5
	bhi _082358E2
	lsls r0, r2, #2
	ldr r1, _08235880 @ =_08235884
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08235880: .4byte _08235884
_08235884: @ jump table
	.4byte _0823589C @ case 0
	.4byte _082358A6 @ case 1
	.4byte _082358B2 @ case 2
	.4byte _082358BE @ case 3
	.4byte _082358CA @ case 4
	.4byte _082358D6 @ case 5
_0823589C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08235090
	b _082358E2
_082358A6:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235178
	b _082358E2
_082358B2:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_082352c0
	b _082358E2
_082358BE:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235408
	b _082358E2
_082358CA:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823556c
	b _082358E2
_082358D6:
	adds r0, r5, #0
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	adds r3, r4, #0
	bl FUN_082356c4
_082358E2:
	cmp r0, #0
	bge _082358EE
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08235090
_082358EE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_082358f4
FUN_082358f4: @ 0x082358F4
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08235910 @ =0x0000F63B
	bl FUN_082310cc
	adds r1, r0, #0
	ldr r0, _08235914 @ =0x030046A4
	ldr r0, [r0]
	str r1, [r0, #0x14]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08235910: .4byte 0x0000F63B
_08235914: .4byte 0x030046A4

	thumb_func_start FUN_08235918
FUN_08235918: @ 0x08235918
	ldr r1, _08235920 @ =0x030046A4
	ldr r1, [r1]
	str r0, [r1, #0x14]
	bx lr
	.align 2, 0
_08235920: .4byte 0x030046A4

	thumb_func_start FUN_08235924
FUN_08235924: @ 0x08235924
	push {lr}
	lsls r2, r2, #4
	adds r2, r0, r2
	movs r0, #0
	ldrsh r3, [r1, r0]
	ldrb r0, [r2]
	lsls r0, r0, #8
	cmp r3, r0
	blt _08235956
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	cmp r3, r0
	bge _08235956
	movs r0, #4
	ldrsh r1, [r1, r0]
	ldrb r0, [r2, #1]
	lsls r0, r0, #8
	cmp r1, r0
	blt _08235956
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	cmp r1, r0
	bge _08235956
	movs r0, #1
	b _08235958
_08235956:
	movs r0, #0
_08235958:
	pop {r1}
	bx r1

	thumb_func_start FUN_0823595c
FUN_0823595c: @ 0x0823595C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r2, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r1, #0
	cmp r0, r3
	bne _08235970
	movs r0, #0
	b _08235994
_08235970:
	cmp r0, r3
	bgt _0823597E
	muls r1, r0, r1
	adds r1, r1, r3
	adds r2, r0, #2
	adds r0, #1
	b _08235988
_0823597E:
	adds r1, r3, #0
	muls r1, r2, r1
	adds r1, r1, r0
	adds r2, r3, #2
	adds r0, r3, #1
_08235988:
	muls r0, r2, r0
	asrs r0, r0, #1
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
_08235994:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823599c
FUN_0823599c: @ 0x0823599C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov sb, r2
	ldr r0, _082359DC @ =0x030046A4
	ldr r1, [r0]
	ldr r0, [r1, #0x14]
	mov r8, r0
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r3, #0
	blt _082359D6
	cmp r2, #0
	blt _082359D6
	ldr r0, _082359E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _082359D6
	ldr r0, _082359E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _082359E8
_082359D6:
	movs r4, #0
	b _082359F2
	.align 2, 0
_082359DC: .4byte 0x030046A4
_082359E0: .4byte 0x030046A8
_082359E4: .4byte 0x030046AC
_082359E8:
	lsls r0, r2, #1
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r4, r0, r3
_082359F2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235A02
	adds r0, #4
	b _08235A0E
_08235A02:
	ldr r0, _08235A1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235A0E:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08235A24
	b _08235A72
	.align 2, 0
_08235A1C: .4byte 0x030046A4
_08235A20:
	movs r0, #1
	b _08235A74
_08235A24:
	movs r7, #0
	mov r1, r8
	ldrh r1, [r1]
	cmp r7, r1
	bge _08235A72
_08235A2E:
	lsls r1, r7, #2
	mov r0, r8
	adds r0, #4
	adds r0, r0, r1
	ldr r0, [r0]
	mov r2, r8
	adds r5, r2, r0
	ldr r0, [r5, #8]
	adds r6, r5, r0
	movs r4, #0
	ldrh r0, [r5]
	cmp r4, r0
	bge _08235A68
_08235A48:
	adds r0, r6, #0
	mov r1, sb
	adds r2, r4, #0
	bl FUN_08235924
	cmp r0, #0
	beq _08235A60
	mov r1, sl
	ldrh r1, [r1, #4]
	cmp r7, r1
	beq _08235A20
	b _08235A72
_08235A60:
	adds r4, #1
	ldrh r2, [r5]
	cmp r4, r2
	blt _08235A48
_08235A68:
	adds r7, #1
	mov r0, r8
	ldrh r0, [r0]
	cmp r7, r0
	blt _08235A2E
_08235A72:
	movs r0, #0
_08235A74:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08235a84
FUN_08235a84: @ 0x08235A84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r2, [sp, #0x20]
	movs r2, #0xc
	ldrsh r1, [r0, r2]
	ldr r3, [sp, #0x20]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne _08235AD4
	ldr r0, [sp, #0x18]
	movs r2, #0x10
	ldrsh r1, [r0, r2]
	movs r7, #4
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne _08235AD4
	ldr r0, [sp, #0x18]
	movs r2, #0x14
	ldrsh r1, [r0, r2]
	ldr r3, [sp, #0x1c]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne _08235AD4
	ldr r0, [sp, #0x18]
	movs r2, #0x18
	ldrsh r1, [r0, r2]
	movs r7, #4
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne _08235AD4
	movs r0, #2
	b _08235F2E
_08235AD4:
	ldr r0, _08235AF8 @ =0x030046A4
	ldr r0, [r0]
	ldr r5, [r0, #0x14]
	ldr r1, [sp, #0x20]
	ldrh r0, [r1]
	ldr r2, [sp, #0x18]
	strh r0, [r2, #0xc]
	ldrh r0, [r1, #4]
	strh r0, [r2, #0x10]
	movs r3, #0xff
	movs r7, #0xff
	movs r0, #0
	str r0, [sp, #0x24]
	movs r1, #0
	str r1, [sp, #0x28]
	movs r6, #0
	b _08235B40
	.align 2, 0
_08235AF8: .4byte 0x030046A4
_08235AFC:
	lsls r1, r6, #2
	adds r0, r5, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r5, r0
	str r0, [sp, #0x24]
	ldr r0, [r0, #8]
	ldr r1, [sp, #0x24]
	adds r0, r1, r0
	str r0, [sp, #0x28]
	movs r4, #0
	ldrh r2, [r1]
	cmp r4, r2
	bge _08235B3E
_08235B18:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x20]
	adds r2, r4, #0
	str r3, [sp, #0x58]
	bl FUN_08235924
	ldr r3, [sp, #0x58]
	cmp r0, #0
	beq _08235B34
	adds r3, r6, #0
	adds r7, r4, #0
	ldrh r6, [r5]
	ldr r0, [sp, #0x24]
	ldrh r4, [r0]
_08235B34:
	adds r4, #1
	ldr r1, [sp, #0x24]
	ldrh r1, [r1]
	cmp r4, r1
	blt _08235B18
_08235B3E:
	adds r6, #1
_08235B40:
	ldrh r2, [r5]
	cmp r6, r2
	blt _08235AFC
	cmp r7, #0xff
	bne _08235B52
	movs r0, #0
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	b _08235F2E
_08235B52:
	ldr r1, [sp, #0x18]
	ldrh r0, [r1, #4]
	cmp r0, r3
	beq _08235B60
	movs r0, #0
	strh r0, [r1]
	b _08235F2E
_08235B60:
	ldr r2, [sp, #0x18]
	ldrh r1, [r2, #6]
	cmp r1, r7
	bne _08235B8A
	ldr r3, [sp, #0x20]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	adds r7, r2, #0
	str r0, [r7, #0xc]
	str r1, [r7, #0x10]
	ldr r2, [sp, #0x18]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r3, [sp, #0x1c]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	movs r0, #6
	b _08235F2A
_08235B8A:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _08235B96
	ldr r1, [sp, #0x28]
	cmp r1, #0
	bne _08235B9A
_08235B96:
	movs r0, #0
	b _08235F2E
_08235B9A:
	ldr r2, [sp, #0x24]
	ldr r0, [r2, #0xc]
	adds r0, r2, r0
	str r0, [sp, #0x2c]
	ldr r0, [r2, #0x10]
	adds r0, r2, r0
	str r0, [sp, #0x30]
	lsls r0, r7, #4
	mov r3, sp
	adds r3, #0xc
	str r3, [sp, #0x4c]
	movs r2, #0xff
	mov r1, sp
	adds r1, #0xa
_08235BB6:
	strh r2, [r1]
	subs r1, #2
	cmp r1, sp
	bge _08235BB6
	ldr r1, [sp, #0x28]
	adds r1, r1, r0
	mov sl, r1
	mov r0, sp
	strh r7, [r0]
	movs r2, #1
	str r2, [sp, #0x44]
	movs r6, #0
	adds r1, #4
	mov r3, sl
	ldrb r0, [r3, #4]
	cmp r0, #0xff
	beq _08235C78
_08235BD8:
	adds r0, r1, r6
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r7, [sp, #0x2c]
	adds r5, r7, r0
	movs r4, #0
	adds r1, r5, #6
	ldrb r0, [r5, #6]
	b _08235C56
_08235BEE:
	adds r0, r1, r4
	ldrb r2, [r0]
	mov r0, sp
	adds r1, r4, #1
	mov sb, r1
	ldrh r0, [r0]
	cmp r2, r0
	beq _08235C4A
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x20]
	bl FUN_08235924
	cmp r0, #0
	beq _08235C4A
	movs r7, #1
	ldr r2, [sp, #0x44]
	cmp r2, #0
	beq _08235C2C
	adds r0, r5, #6
	adds r0, r0, r4
	ldrb r3, [r0]
	mov r2, sp
	ldr r1, [sp, #0x44]
_08235C1C:
	ldrh r0, [r2]
	cmp r0, r3
	bne _08235C24
	movs r7, #0
_08235C24:
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne _08235C1C
_08235C2C:
	cmp r7, #0
	beq _08235C4A
	ldr r3, [sp, #0x44]
	lsls r0, r3, #1
	mov r7, sp
	adds r1, r7, r0
	adds r0, r5, #6
	adds r0, r0, r4
	ldrb r0, [r0]
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x44]
_08235C4A:
	mov r4, sb
	cmp r4, #5
	bgt _08235C60
	adds r1, r5, #6
	adds r0, r1, r4
	ldrb r0, [r0]
_08235C56:
	cmp r0, #0xff
	beq _08235C60
	ldr r0, [sp, #0x44]
	cmp r0, #5
	bls _08235BEE
_08235C60:
	adds r6, #1
	cmp r6, #0xb
	bgt _08235C78
	mov r1, sl
	adds r1, #4
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08235C78
	ldr r2, [sp, #0x44]
	cmp r2, #5
	bls _08235BD8
_08235C78:
	ldr r3, [sp, #0x18]
	ldrh r1, [r3, #6]
	ldr r2, [sp, #0x4c]
	movs r3, #0xff
	adds r0, r2, #0
	adds r0, #0xa
_08235C84:
	strh r3, [r0]
	subs r0, #2
	cmp r0, r2
	bge _08235C84
	lsls r0, r1, #4
	ldr r7, [sp, #0x28]
	adds r0, r7, r0
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x4c]
	strh r1, [r0]
	movs r1, #1
	str r1, [sp, #0x48]
	movs r6, #0
	ldr r1, [sp, #0x34]
	adds r1, #4
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	cmp r0, #0xff
	beq _08235D56
_08235CAA:
	adds r0, r1, r6
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, [sp, #0x2c]
	adds r5, r3, r0
	movs r4, #0
	adds r1, r5, #6
	ldrb r0, [r5, #6]
	adds r6, #1
	str r6, [sp, #0x50]
	cmp r0, #0xff
	beq _08235D3E
	ldr r7, [sp, #0x48]
	cmp r7, #5
	bhi _08235D3E
_08235CCC:
	adds r0, r1, r4
	ldrb r2, [r0]
	adds r0, r4, #1
	mov sb, r0
	ldr r1, [sp, #0x4c]
	ldrh r1, [r1]
	cmp r2, r1
	beq _08235D28
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x1c]
	bl FUN_08235924
	cmp r0, #0
	beq _08235D28
	movs r6, #1
	ldr r2, [sp, #0x48]
	cmp r2, #0
	beq _08235D0A
	adds r0, r5, #6
	adds r0, r0, r4
	ldrb r3, [r0]
	ldr r2, [sp, #0x4c]
	ldr r1, [sp, #0x48]
_08235CFA:
	ldrh r0, [r2]
	cmp r0, r3
	bne _08235D02
	movs r6, #0
_08235D02:
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne _08235CFA
_08235D0A:
	cmp r6, #0
	beq _08235D28
	ldr r3, [sp, #0x48]
	lsls r1, r3, #1
	ldr r7, [sp, #0x4c]
	adds r1, r7, r1
	adds r0, r5, #6
	adds r0, r0, r4
	ldrb r0, [r0]
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x48]
_08235D28:
	mov r4, sb
	cmp r4, #5
	bgt _08235D3E
	adds r1, r5, #6
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08235D3E
	ldr r0, [sp, #0x48]
	cmp r0, #5
	bls _08235CCC
_08235D3E:
	ldr r6, [sp, #0x50]
	cmp r6, #0xb
	bgt _08235D56
	ldr r1, [sp, #0x34]
	adds r1, #4
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08235D56
	ldr r2, [sp, #0x48]
	cmp r2, #5
	bls _08235CAA
_08235D56:
	movs r6, #0
	ldr r3, [sp, #0x48]
	cmp r6, r3
	bge _08235D88
	ldr r2, [sp, #0x4c]
_08235D60:
	movs r4, #0
	ldr r7, [sp, #0x44]
	cmp r4, r7
	bge _08235D7E
	ldrh r1, [r2]
	mov r0, sp
_08235D6C:
	ldrh r3, [r0]
	cmp r1, r3
	bne _08235D74
	b _08235EC8
_08235D74:
	adds r0, #2
	adds r4, #1
	ldr r7, [sp, #0x44]
	cmp r4, r7
	blt _08235D6C
_08235D7E:
	adds r2, #2
	adds r6, #1
	ldr r0, [sp, #0x48]
	cmp r6, r0
	blt _08235D60
_08235D88:
	ldr r1, _08235D98 @ =0x0000FFFF
	str r1, [sp, #0x38]
	movs r2, #0xff
	str r2, [sp, #0x3c]
	movs r3, #0xff
	str r3, [sp, #0x40]
	movs r6, #0
	b _08235EA8
	.align 2, 0
_08235D98: .4byte 0x0000FFFF
_08235D9C:
	lsls r0, r6, #1
	ldr r1, [sp, #0x4c]
	adds r0, r1, r0
	ldrh r0, [r0]
	lsls r0, r0, #4
	ldr r2, [sp, #0x28]
	adds r0, r2, r0
	str r0, [sp, #0x34]
	movs r4, #0
	adds r6, #1
	str r6, [sp, #0x50]
	b _08235EA0
_08235DB4:
	lsls r0, r4, #1
	add r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #4
	ldr r7, [sp, #0x28]
	adds r7, r7, r0
	mov sl, r7
	movs r1, #0
	ldrb r0, [r7, #4]
	adds r4, #1
	mov sb, r4
	cmp r0, #0xff
	beq _08235E9E
	ldr r0, [sp, #0x34]
	adds r0, #4
	str r0, [sp, #0x54]
_08235DD4:
	movs r2, #0
	mov r8, r2
	ldr r3, [sp, #0x34]
	adds r3, #4
	ldr r7, [sp, #0x34]
	ldrb r0, [r7, #4]
	adds r2, r1, #1
	str r2, [sp, #0x5c]
	cmp r0, #0xff
	beq _08235E8C
	mov r0, sl
	adds r0, #4
	adds r6, r0, r1
_08235DEE:
	ldr r7, [sp, #0x24]
	ldrh r1, [r7, #2]
	ldrb r2, [r6]
	mov r0, r8
	adds r5, r3, r0
	ldrb r3, [r5]
	ldr r0, [sp, #0x30]
	bl FUN_0823595c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x38]
	cmp r0, r1
	bhs _08235E16
	str r0, [sp, #0x38]
	ldrb r5, [r5]
	str r5, [sp, #0x3c]
	ldrb r2, [r6]
	str r2, [sp, #0x40]
	b _08235E78
_08235E16:
	ldr r3, [sp, #0x38]
	cmp r0, r3
	bne _08235E78
	ldr r0, _08235EC0 @ =0x0000FFFF
	cmp r3, r0
	beq _08235E78
	ldr r7, [sp, #0x1c]
	movs r0, #0
	ldrsh r4, [r7, r0]
	ldrb r5, [r5]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r1, [sp, #0x2c]
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r1, r4, r1
	movs r2, #4
	ldrsh r3, [r7, r2]
	ldrh r0, [r0, #2]
	subs r0, r3, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r2, r2, r0
	ldr r1, [sp, #0x3c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r7, [sp, #0x2c]
	adds r0, r0, r7
	ldrh r1, [r0]
	subs r1, r4, r1
	ldrh r0, [r0, #2]
	subs r0, r3, r0
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	cmp r2, r1
	bge _08235E78
	str r5, [sp, #0x3c]
	ldrb r0, [r6]
	str r0, [sp, #0x40]
_08235E78:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #0xb
	bgt _08235E8C
	ldr r3, [sp, #0x54]
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08235DEE
_08235E8C:
	ldr r1, [sp, #0x5c]
	cmp r1, #0xb
	bgt _08235E9E
	mov r0, sl
	adds r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08235DD4
_08235E9E:
	mov r4, sb
_08235EA0:
	ldr r3, [sp, #0x44]
	cmp r4, r3
	blt _08235DB4
	ldr r6, [sp, #0x50]
_08235EA8:
	ldr r7, [sp, #0x48]
	cmp r6, r7
	bge _08235EB0
	b _08235D9C
_08235EB0:
	ldr r0, _08235EC4 @ =0x0000FFFE
	ldr r1, [sp, #0x38]
	cmp r1, r0
	bls _08235EEA
	movs r0, #0
	ldr r2, [sp, #0x18]
	strh r0, [r2]
	b _08235F2E
	.align 2, 0
_08235EC0: .4byte 0x0000FFFF
_08235EC4: .4byte 0x0000FFFE
_08235EC8:
	ldr r3, [sp, #0x20]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0xc]
	str r1, [r7, #0x10]
	ldr r2, [sp, #0x18]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r3, [sp, #0x1c]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	movs r0, #6
	b _08235F2A
_08235EEA:
	movs r2, #0
	add r0, sp, #0x40
	ldrh r1, [r0]
	ldr r0, [sp, #0x18]
	strh r1, [r0, #8]
	ldr r3, [sp, #0x20]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0xc]
	str r1, [r7, #0x10]
	ldr r3, [sp, #0x1c]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	mov r0, sp
	ldrh r0, [r0, #0x3c]
	strh r0, [r7, #0xa]
	ldr r1, [sp, #0x3c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, [sp, #0x2c]
	adds r0, r0, r3
	ldrh r1, [r0]
	strh r1, [r7, #0x1c]
	strh r2, [r7, #0x1e]
	ldrh r0, [r0, #2]
	strh r0, [r7, #0x20]
	movs r0, #3
_08235F2A:
	strh r0, [r7]
	movs r0, #1
_08235F2E:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08235f40
FUN_08235f40: @ 0x08235F40
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08235F6C
	cmp r1, #0
	blt _08235F6C
	ldr r0, _08235F70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08235F6C
	ldr r0, _08235F74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08235F78
_08235F6C:
	movs r4, #0
	b _08235F86
	.align 2, 0
_08235F70: .4byte 0x030046A8
_08235F74: .4byte 0x030046AC
_08235F78:
	ldr r0, _08235F98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08235F86:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08235F9C
	adds r0, #4
	b _08235FA8
	.align 2, 0
_08235F98: .4byte 0x030046A4
_08235F9C:
	ldr r0, _08235FC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08235FA8:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08235FC4
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235a84
	b _08235FC8
	.align 2, 0
_08235FC0: .4byte 0x030046A4
_08235FC4:
	movs r0, #0
	strh r0, [r6]
_08235FC8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08235FD0:
	.byte 0x00, 0x21, 0x01, 0x80, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_08235fd8
FUN_08235fd8: @ 0x08235FD8
	push {lr}
	adds r2, r0, #0
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08235FEA
	movs r0, #0
	b _08235FF2
_08235FEA:
	ldr r0, _08235FF8 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
_08235FF2:
	pop {r1}
	bx r1
	.align 2, 0
_08235FF8: .4byte 0x0000FFFD

	thumb_func_start FUN_08235ffc
FUN_08235ffc: @ 0x08235FFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp]
	adds r3, r1, #0
	mov sl, r2
	ldrh r1, [r3, #4]
	lsls r1, r1, #2
	adds r0, #4
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp]
	adds r7, r1, r0
	ldr r0, [r7, #8]
	adds r0, r0, r7
	mov r8, r0
	ldrh r2, [r3, #6]
	mov r1, sl
	str r3, [sp, #0xc]
	bl FUN_08235924
	ldr r3, [sp, #0xc]
	cmp r0, #0
	bne _0823611E
	ldr r0, [r7, #0xc]
	adds r0, r7, r0
	str r0, [sp, #4]
	ldrh r0, [r3, #6]
	lsls r0, r0, #4
	add r0, r8
	str r0, [sp, #8]
	movs r6, #0
	adds r1, r0, #0
	adds r1, #4
	ldrb r0, [r0, #4]
	cmp r0, #0xff
	beq _082360A2
_0823604C:
	adds r0, r1, r6
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, [sp, #4]
	adds r2, r2, r0
	mov sb, r2
	movs r4, #0
_0823605E:
	mov r0, sb
	adds r0, #6
	adds r5, r0, r4
	ldrb r0, [r5]
	cmp r0, #0xff
	beq _08236088
	adds r2, r0, #0
	ldrh r0, [r3, #6]
	cmp r2, r0
	beq _0823608A
	mov r0, r8
	mov r1, sl
	str r3, [sp, #0xc]
	bl FUN_08235924
	ldr r3, [sp, #0xc]
	cmp r0, #0
	beq _0823608A
	ldrb r0, [r5]
	strh r0, [r3, #6]
	b _0823611E
_08236088:
	movs r4, #6
_0823608A:
	adds r4, #1
	cmp r4, #5
	ble _0823605E
	adds r6, #1
	cmp r6, #0xb
	bgt _082360A2
	ldr r1, [sp, #8]
	adds r1, #4
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0823604C
_082360A2:
	movs r6, #0
	ldrh r1, [r7]
	cmp r6, r1
	bge _082360CE
_082360AA:
	ldrh r2, [r3, #6]
	cmp r6, r2
	beq _082360C6
	mov r0, r8
	mov r1, sl
	adds r2, r6, #0
	str r3, [sp, #0xc]
	bl FUN_08235924
	ldr r3, [sp, #0xc]
	cmp r0, #0
	beq _082360C6
	strh r6, [r3, #6]
	b _0823611E
_082360C6:
	adds r6, #1
	ldrh r0, [r7]
	cmp r6, r0
	blt _082360AA
_082360CE:
	movs r6, #0
	b _08236116
_082360D2:
	ldrh r2, [r3, #4]
	cmp r6, r2
	beq _08236114
	lsls r1, r6, #2
	ldr r0, [sp]
	adds r0, #4
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp]
	adds r7, r1, r0
	ldr r0, [r7, #8]
	adds r0, r0, r7
	mov r8, r0
	movs r4, #0
	ldrh r2, [r7]
	cmp r4, r2
	bge _08236114
_082360F4:
	mov r0, r8
	mov r1, sl
	adds r2, r4, #0
	str r3, [sp, #0xc]
	bl FUN_08235924
	ldr r3, [sp, #0xc]
	cmp r0, #0
	beq _0823610C
	strh r6, [r3, #4]
	strh r4, [r3, #6]
	b _0823611E
_0823610C:
	adds r4, #1
	ldrh r0, [r7]
	cmp r4, r0
	blt _082360F4
_08236114:
	adds r6, #1
_08236116:
	ldr r1, [sp]
	ldrh r1, [r1]
	cmp r6, r1
	blt _082360D2
_0823611E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08236130
FUN_08236130: @ 0x08236130
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r8, r1
	ldrh r3, [r1, #4]
	lsls r3, r3, #2
	adds r1, r0, #4
	adds r1, r1, r3
	ldr r1, [r1]
	adds r0, r0, r1
	mov sb, r0
	ldr r0, [r0, #8]
	add r0, sb
	str r0, [sp]
	mov r1, sb
	ldr r0, [r1, #0xc]
	add r0, sb
	str r0, [sp, #4]
	ldr r0, [r1, #0x10]
	add r0, sb
	str r0, [sp, #8]
	mov r3, r8
	ldrh r4, [r3, #0xa]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, [sp, #4]
	adds r5, r1, r0
	movs r0, #0
	ldrsh r3, [r2, r0]
	ldrh r0, [r5]
	subs r3, r3, r0
	movs r1, #4
	ldrsh r0, [r2, r1]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	adds r1, r3, #0
	muls r1, r3, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0xe1
	lsls r0, r0, #4
	cmp r1, r0
	bgt _08236258
	mov r3, r8
	ldrh r3, [r3, #8]
	cmp r4, r3
	bne _082361AA
	mov r2, r8
	ldr r0, [r2, #0xc]
	ldr r1, [r2, #0x10]
	mov r3, r8
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #6
	b _08236256
_082361AA:
	ldr r0, _08236228 @ =0x0000FFFF
	str r0, [sp, #0xc]
	movs r1, #0xff
	mov sl, r1
	movs r2, #0
	adds r1, r5, #6
	ldrb r0, [r5, #6]
	str r1, [sp, #0x10]
	cmp r0, #0xff
	beq _0823621A
_082361BE:
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldr r3, [sp]
	adds r6, r3, r0
	movs r5, #0
	adds r1, r6, #4
	ldrb r0, [r6, #4]
	adds r7, r2, #1
	cmp r0, #0xff
	beq _0823620A
_082361D4:
	adds r4, r1, r5
	ldrb r3, [r4]
	cmp r3, sl
	beq _082361FA
	mov r0, sb
	ldrh r1, [r0, #2]
	mov r0, r8
	ldrh r2, [r0, #8]
	ldr r0, [sp, #8]
	bl FUN_0823595c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	cmp r0, r1
	bge _082361FA
	str r0, [sp, #0xc]
	ldrb r4, [r4]
	mov sl, r4
_082361FA:
	adds r5, #1
	cmp r5, #0xb
	bgt _0823620A
	adds r1, r6, #4
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _082361D4
_0823620A:
	adds r2, r7, #0
	cmp r7, #5
	bgt _0823621A
	ldr r1, [sp, #0x10]
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _082361BE
_0823621A:
	ldr r0, _0823622C @ =0x0000FFFE
	ldr r2, [sp, #0xc]
	cmp r2, r0
	ble _08236230
	movs r0, #0
	mov r3, r8
	b _08236256
	.align 2, 0
_08236228: .4byte 0x0000FFFF
_0823622C: .4byte 0x0000FFFE
_08236230:
	movs r2, #0
	mov r1, sl
	mov r0, r8
	strh r1, [r0, #0xa]
	mov r3, sl
	lsls r0, r3, #1
	add r0, sl
	lsls r0, r0, #2
	ldr r1, [sp, #4]
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, r8
	strh r1, [r3, #0x1c]
	strh r2, [r3, #0x1e]
	ldrh r0, [r0, #2]
	strh r0, [r3, #0x20]
	ldrh r1, [r3]
	movs r0, #2
	orrs r0, r1
_08236256:
	strh r0, [r3]
_08236258:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08236268
FUN_08236268: @ 0x08236268
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, _08236298 @ =0x030046A4
	ldr r0, [r0]
	ldr r5, [r0, #0x14]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08235ffc
	ldrh r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08236292
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08236130
_08236292:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08236298: .4byte 0x030046A4

	thumb_func_start FUN_0823629c
FUN_0823629c: @ 0x0823629C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	ldr r0, _082362B0 @ =0x030046A4
	ldr r0, [r0]
	ldr r6, [r0, #0x14]
	movs r3, #0
	b _082362E6
	.align 2, 0
_082362B0: .4byte 0x030046A4
_082362B4:
	lsls r1, r3, #2
	adds r0, r6, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r5, r6, r0
	ldr r0, [r5, #8]
	adds r7, r5, r0
	movs r4, #0
	b _082362DE
_082362C6:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r4, #0
	str r3, [sp]
	bl FUN_08235924
	ldr r3, [sp]
	cmp r0, #0
	beq _082362DC
	adds r0, r4, #0
	b _082362EE
_082362DC:
	adds r4, #1
_082362DE:
	ldrh r0, [r5]
	cmp r4, r0
	blt _082362C6
	adds r3, #1
_082362E6:
	ldrh r0, [r6]
	cmp r3, r0
	blt _082362B4
	movs r0, #0xff
_082362EE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082362fc
FUN_082362fc: @ 0x082362FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov sl, r1
	ldr r1, _0823631C @ =0x030046A4
	ldr r1, [r1]
	ldr r7, [r1, #0x14]
	movs r1, #0xff
	strh r1, [r6, #4]
	strh r1, [r6, #6]
	movs r3, #0
	b _0823635A
	.align 2, 0
_0823631C: .4byte 0x030046A4
_08236320:
	lsls r2, r3, #2
	adds r1, r7, #4
	adds r1, r1, r2
	ldr r1, [r1]
	adds r5, r7, r1
	ldr r1, [r5, #8]
	adds r1, r1, r5
	mov r8, r1
	movs r4, #0
	adds r1, r3, #1
	mov sb, r1
	b _08236352
_08236338:
	mov r0, r8
	mov r1, sl
	adds r2, r4, #0
	str r3, [sp]
	bl FUN_08235924
	adds r1, r0, #0
	ldr r3, [sp]
	cmp r1, #0
	beq _08236350
	strh r3, [r6, #4]
	strh r4, [r6, #6]
_08236350:
	adds r4, #1
_08236352:
	ldrh r1, [r5]
	cmp r4, r1
	blt _08236338
	mov r3, sb
_0823635A:
	ldrh r1, [r7]
	cmp r3, r1
	blt _08236320
	movs r1, #0
	strh r1, [r6]
	mov r3, sl
	ldr r1, [r3]
	ldr r2, [r3, #4]
	str r1, [r6, #0xc]
	str r2, [r6, #0x10]
	str r1, [r6, #0x1c]
	str r2, [r6, #0x20]
	str r1, [r6, #0x14]
	str r2, [r6, #0x18]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08236388
FUN_08236388: @ 0x08236388
	push {lr}
	adds r3, r0, #0
	ldr r0, _0823639C @ =0x03000780
	ldr r2, [r0]
	adds r1, r0, #0
	cmp r2, #0
	beq _082363BE
	ldr r0, [r2, #0x18]
	b _082363A4
	.align 2, 0
_0823639C: .4byte 0x03000780
_082363A0:
	cmp r0, r3
	beq _082363BE
_082363A4:
	ldr r0, [r0]
	cmp r0, #0
	bne _082363A0
	ldr r1, [r1]
	ldr r0, [r1, #0x20]
	str r3, [r0]
	movs r0, #0
	str r0, [r3]
	str r3, [r1, #0x20]
	adds r1, #0xc8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_082363BE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082363c4
FUN_082363c4: @ 0x082363C4
	push {lr}
	adds r3, r0, #0
	ldr r0, _082363FC @ =0x03000780
	ldr r2, [r0]
	adds r1, r0, #0
	cmp r2, #0
	beq _082363F6
	ldr r0, [r2, #0x1c]
	ldr r2, [r0]
	cmp r2, #0
	beq _082363E4
_082363DA:
	cmp r2, r3
	beq _082363F6
	ldr r2, [r2]
	cmp r2, #0
	bne _082363DA
_082363E4:
	ldr r1, [r1]
	ldr r2, [r1, #0x1c]
	ldr r0, [r2]
	str r0, [r3]
	str r3, [r2]
	adds r1, #0xca
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_082363F6:
	pop {r0}
	bx r0
	.align 2, 0
_082363FC: .4byte 0x03000780

	thumb_func_start FUN_08236400
FUN_08236400: @ 0x08236400
	push {lr}
	adds r2, r0, #0
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _08236418
	adds r0, r2, #0
	bl FUN_082363c4
	b _0823641E
_08236418:
	adds r0, r2, #0
	bl FUN_08236388
_0823641E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08236424
FUN_08236424: @ 0x08236424
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _08236458 @ =0x03000780
	ldr r2, [r0]
	adds r4, r0, #0
	cmp r2, #0
	beq _08236464
	ldr r1, [r2, #0x18]
	ldr r2, [r1]
	cmp r2, #0
	beq _08236464
_0823643A:
	cmp r2, r3
	bne _0823645C
	ldr r3, [r4]
	ldr r0, [r3, #0x20]
	cmp r2, r0
	bne _08236448
	str r1, [r3, #0x20]
_08236448:
	ldr r0, [r2]
	str r0, [r1]
	ldr r1, [r4]
	adds r1, #0xc8
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _08236464
	.align 2, 0
_08236458: .4byte 0x03000780
_0823645C:
	adds r1, r2, #0
	ldr r2, [r2]
	cmp r2, #0
	bne _0823643A
_08236464:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823646c
FUN_0823646c: @ 0x0823646C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r0, [sp, #0x18]
	ldr r5, [sp, #0x1c]
	ldr r6, [sp, #0x20]
	movs r4, #0
	mov r8, r4
	movs r4, #0
	mov r7, ip
	strh r2, [r7, #6]
	strh r1, [r7, #4]
	strh r3, [r7, #8]
	strh r0, [r7, #0xa]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	mov r2, ip
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	mov r0, ip
	adds r0, #0x43
	mov r1, r8
	strb r1, [r0]
	strh r4, [r7, #0x3e]
	str r4, [r7, #0x34]
	str r4, [r7, #0x38]
	subs r0, #3
	strh r4, [r0]
	str r4, [r7, #0x48]
	mov r1, ip
	adds r1, #0x47
	movs r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082364c4
FUN_082364c4: @ 0x082364C4
	ldrh r3, [r1]
	strh r3, [r0, #0xc]
	ldrh r3, [r1, #2]
	strh r3, [r0, #0xe]
	ldrh r1, [r1, #4]
	strh r1, [r0, #0x10]
	strh r2, [r0, #8]
	bx lr

	thumb_func_start FUN_082364d4
FUN_082364d4: @ 0x082364D4
	push {r4, r5, lr}
	ldr r4, [r1]
	ldr r5, [r1, #4]
	str r4, [r0, #0xc]
	str r5, [r0, #0x10]
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0, #0x14]
	str r2, [r0, #0x18]
	strh r3, [r0, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082364f0
FUN_082364f0: @ 0x082364F0
	strh r1, [r0, #0x3c]
	adds r0, #0x40
	strh r2, [r0]
	bx lr

	thumb_func_start FUN_082364f8
FUN_082364f8: @ 0x082364F8
	push {r4, r5, lr}
	ldr r4, [sp, #0xc]
	ldr r5, [sp, #0x10]
	strh r1, [r0, #0x3c]
	adds r1, r0, #0
	adds r1, #0x40
	strh r2, [r1]
	str r3, [r0, #0x34]
	str r4, [r0, #0x38]
	adds r0, #0x44
	strh r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08236514
FUN_08236514: @ 0x08236514
	strh r1, [r0, #0x3c]
	str r2, [r0, #0x38]
	str r3, [r0, #0x34]
	bx lr

	thumb_func_start FUN_0823651c
FUN_0823651c: @ 0x0823651C
	str r1, [r0, #0x48]
	str r2, [r0, #0x4c]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08236524
FUN_08236524: @ 0x08236524
	push {r4, r5, lr}
	adds r5, r0, #0
	mov ip, r1
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	beq _08236532
	b _0823663A
_08236532:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r5, #0x38]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08236544
	ldrh r1, [r5, #0x3c]
	b _0823654C
_08236544:
	ldrh r1, [r5, #0x3c]
	mov r3, ip
	ldrh r0, [r3, #0x3c]
	subs r1, r1, r0
_0823654C:
	cmp r1, #0
	bgt _08236552
	movs r1, #1
_08236552:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq _08236560
	movs r3, #0
	b _08236568
_08236560:
	mov r0, ip
	ldr r3, [r0, #0x38]
	movs r0, #0x7f
	ands r3, r0
_08236568:
	mov r0, ip
	ldr r4, [r0, #0x34]
	movs r0, #0x7f
	ands r4, r0
	ands r2, r0
	cmp r2, #0
	bne _0823657C
	mov r3, ip
	strh r1, [r3, #0x3e]
	b _082365DE
_0823657C:
	cmp r3, #0
	bne _0823658C
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	b _082365E0
_0823658C:
	cmp r3, #0x40
	bne _0823659E
	asrs r0, r1, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
	mov r1, ip
	adds r1, #0x43
	movs r0, #2
	b _082365E4
_0823659E:
	cmp r2, #0x40
	bne _082365AE
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	b _082365E0
_082365AE:
	ands r3, r2
	cmp r3, #0
	beq _082365C2
	asrs r0, r1, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
	mov r1, ip
	adds r1, #0x43
	movs r0, #2
	b _082365E4
_082365C2:
	ands r4, r2
	cmp r4, #0
	beq _082365D4
	lsls r0, r1, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	adds r1, #0x43
	movs r0, #4
	b _082365E4
_082365D4:
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
_082365DE:
	mov r1, ip
_082365E0:
	adds r1, #0x43
	movs r0, #1
_082365E4:
	strb r0, [r1]
	adds r2, r1, #0
	mov r0, ip
	ldrh r1, [r0, #6]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0823662E
	ldrh r1, [r5, #6]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0823662E
	mov r0, ip
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	bge _08236616
	rsbs r0, r0, #0
_08236616:
	cmp r0, #0x20
	bgt _0823662E
	mov r3, ip
	ldrh r1, [r3, #0x3e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r0, r0, #1
	strh r0, [r3, #0x3e]
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_0823662E:
	mov r1, ip
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	bne _0823663A
	movs r0, #1
	strh r0, [r1, #0x3e]
_0823663A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08236640
FUN_08236640: @ 0x08236640
	push {r4, r5, lr}
	adds r5, r0, #0
	mov ip, r1
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	beq _0823664E
	b _08236762
_0823664E:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r5, #0x38]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08236660
	ldrh r1, [r5, #0x3c]
	b _08236668
_08236660:
	ldrh r1, [r5, #0x3c]
	mov r3, ip
	ldrh r0, [r3, #0x3c]
	subs r1, r1, r0
_08236668:
	cmp r1, #0
	bgt _0823666E
	movs r1, #1
_0823666E:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq _0823667C
	movs r3, #0
	b _08236684
_0823667C:
	mov r0, ip
	ldr r3, [r0, #0x38]
	movs r0, #0x7f
	ands r3, r0
_08236684:
	mov r0, ip
	ldr r4, [r0, #0x34]
	movs r0, #0x7f
	ands r4, r0
	ands r2, r0
	cmp r2, #0
	bne _08236698
	mov r3, ip
	strh r1, [r3, #0x3e]
	b _08236706
_08236698:
	cmp r3, #0
	bne _082366A8
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	b _08236708
_082366A8:
	cmp r3, #0x40
	bne _082366BE
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
	mov r1, ip
	adds r1, #0x43
	movs r0, #2
	b _0823670C
_082366BE:
	cmp r2, #0x40
	bne _082366CE
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r1, ip
	strh r0, [r1, #0x3e]
	b _08236708
_082366CE:
	ands r3, r2
	cmp r3, #0
	beq _082366E6
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
	mov r1, ip
	adds r1, #0x43
	movs r0, #2
	b _0823670C
_082366E6:
	ands r4, r2
	cmp r4, #0
	beq _082366FC
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r1, ip
	strh r0, [r1, #0x3e]
	adds r1, #0x43
	movs r0, #4
	b _0823670C
_082366FC:
	lsls r0, r1, #2
	adds r0, r0, r1
	asrs r0, r0, #2
	mov r3, ip
	strh r0, [r3, #0x3e]
_08236706:
	mov r1, ip
_08236708:
	adds r1, #0x43
	movs r0, #1
_0823670C:
	strb r0, [r1]
	adds r2, r1, #0
	mov r0, ip
	ldrh r1, [r0, #6]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08236756
	ldrh r1, [r5, #6]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08236756
	mov r0, ip
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	bge _0823673E
	rsbs r0, r0, #0
_0823673E:
	cmp r0, #0x20
	bgt _08236756
	mov r3, ip
	ldrh r1, [r3, #0x3e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r0, r0, #1
	strh r0, [r3, #0x3e]
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_08236756:
	mov r1, ip
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	bne _08236762
	movs r0, #1
	strh r0, [r1, #0x3e]
_08236762:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08236768
FUN_08236768: @ 0x08236768
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r2, r0, #6
	cmp r2, #0
	bne _08236796
	ldrh r0, [r3, #0x1c]
	ldrh r3, [r3, #0x24]
	adds r0, r0, r3
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r0
	ldrh r0, [r5, #0x24]
	subs r1, r1, r0
	strh r1, [r4]
	strh r2, [r4, #2]
	strh r2, [r4, #4]
	b _082367DE
_08236796:
	cmp r2, #1
	bne _082367AC
	movs r0, #0
	strh r0, [r4]
	strh r0, [r4, #2]
	ldrh r1, [r3, #0x20]
	ldrh r3, [r3, #0x28]
	adds r1, r1, r3
	ldrh r0, [r5, #0x20]
	adds r0, r0, r1
	b _082367D8
_082367AC:
	cmp r2, #2
	bne _082367C8
	ldrh r0, [r3, #0x24]
	ldrh r1, [r3, #0x1c]
	subs r0, r0, r1
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	ldrh r1, [r5, #0x24]
	subs r0, r0, r1
	movs r1, #0
	strh r0, [r4]
	strh r1, [r4, #2]
	strh r1, [r4, #4]
	b _082367DE
_082367C8:
	movs r0, #0
	strh r0, [r4]
	strh r0, [r4, #2]
	ldrh r0, [r3, #0x28]
	ldrh r1, [r3, #0x20]
	subs r0, r0, r1
	ldrh r1, [r5, #0x20]
	subs r0, r0, r1
_082367D8:
	ldrh r1, [r5, #0x28]
	subs r0, r0, r1
	strh r0, [r4, #4]
_082367DE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_082367e4
FUN_082367e4: @ 0x082367E4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrh r0, [r5]
	ldrh r1, [r4]
	subs r0, r0, r1
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _082367FC
	asrs r0, r1, #0x11
	b _08236806
_082367FC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_08236806:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r4]
	ldrh r1, [r5]
	adds r0, r0, r1
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _0823681C
	asrs r0, r1, #0x11
	b _08236826
_0823681C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_08236826:
	strh r0, [r2, #0x24]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08236832
	rsbs r0, r0, #0
_08236832:
	strh r0, [r2, #0x1c]
	ldrh r1, [r5, #2]
	ldrh r0, [r4, #2]
	subs r0, r1, r0
	lsls r3, r0, #0x10
	asrs r0, r3, #0x10
	cmp r0, #0
	blt _08236846
	asrs r0, r3, #0x11
	b _08236850
_08236846:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_08236850:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r4, #2]
	adds r0, r1, r0
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _08236864
	asrs r0, r1, #0x11
	b _0823686E
_08236864:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_0823686E:
	strh r0, [r2, #0x26]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0823687A
	rsbs r0, r0, #0
_0823687A:
	strh r0, [r2, #0x1e]
	ldrh r1, [r5, #4]
	ldrh r0, [r4, #4]
	subs r0, r1, r0
	lsls r3, r0, #0x10
	asrs r0, r3, #0x10
	cmp r0, #0
	blt _0823688E
	asrs r0, r3, #0x11
	b _08236898
_0823688E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_08236898:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r4, #4]
	adds r0, r1, r0
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _082368AC
	asrs r0, r1, #0x11
	b _082368B6
_082368AC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
_082368B6:
	movs r1, #0
	strh r0, [r2, #0x28]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _082368C4
	rsbs r0, r0, #0
_082368C4:
	strh r0, [r2, #0x20]
	strh r1, [r2, #0x14]
	strh r1, [r2, #0x16]
	strh r1, [r2, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082368d4
FUN_082368d4: @ 0x082368D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r1
	mov sl, r2
	adds r6, r3, #0
	ldrh r7, [r5]
	ldrh r0, [r1]
	lsls r3, r7, #0x10
	asrs r2, r3, #0x10
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov ip, r1
	cmp r0, #0
	beq _082369A8
	mov r4, sl
	movs r0, #0
	ldrsh r1, [r4, r0]
	cmp r1, r2
	bge _08236916
	ldrh r0, [r6]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r2
	ble _08236926
	b _08236924
_08236916:
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r2
	bge _08236926
_08236924:
	lsrs r4, r3, #0x10
_08236926:
	mov r1, r8
	movs r0, #2
	ldrsh r2, [r1, r0]
	movs r1, #2
	ldrsh r0, [r5, r1]
	subs r2, r2, r0
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	mov sb, r1
	mov r0, sb
	muls r0, r2, r0
	mov r2, ip
	lsls r1, r2, #0x10
	asrs r7, r1, #0x10
	adds r1, r7, #0
	bl Div
	ldrh r1, [r5, #2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	str r0, [sp]
	asrs r1, r1, #0x10
	mov r2, sl
	movs r0, #2
	ldrsh r3, [r2, r0]
	movs r0, #2
	ldrsh r2, [r6, r0]
	subs r0, r3, r2
	cmp r1, r0
	blt _082369A8
	adds r0, r3, r2
	cmp r1, r0
	bgt _082369A8
	mov r1, r8
	movs r2, #4
	ldrsh r0, [r1, r2]
	movs r2, #4
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r7, #0
	bl Div
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	mov r2, sl
	movs r0, #4
	ldrsh r3, [r2, r0]
	movs r0, #4
	ldrsh r2, [r6, r0]
	subs r0, r3, r2
	cmp r1, r0
	blt _082369A8
	adds r0, r3, r2
	cmp r1, r0
	ble _082369AC
_082369A8:
	movs r0, #0
	b _082369BA
_082369AC:
	ldr r1, [sp, #0x24]
	strh r4, [r1]
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r1, #2]
	strh r5, [r1, #4]
	movs r0, #1
_082369BA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082369cc
FUN_082369cc: @ 0x082369CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r1
	mov sl, r2
	adds r6, r3, #0
	ldrh r7, [r5, #2]
	ldrh r0, [r1, #2]
	lsls r3, r7, #0x10
	asrs r2, r3, #0x10
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov ip, r1
	cmp r0, #0
	beq _08236AA0
	mov r4, sl
	movs r0, #2
	ldrsh r1, [r4, r0]
	cmp r1, r2
	bge _08236A0E
	ldrh r0, [r6, #2]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r2
	ble _08236A1E
	b _08236A1C
_08236A0E:
	ldrh r0, [r6, #2]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r2
	bge _08236A1E
_08236A1C:
	lsrs r4, r3, #0x10
_08236A1E:
	mov r1, r8
	movs r0, #4
	ldrsh r2, [r1, r0]
	movs r1, #4
	ldrsh r0, [r5, r1]
	subs r2, r2, r0
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	mov sb, r1
	mov r0, sb
	muls r0, r2, r0
	mov r2, ip
	lsls r1, r2, #0x10
	asrs r7, r1, #0x10
	adds r1, r7, #0
	bl Div
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	str r0, [sp]
	asrs r1, r1, #0x10
	mov r2, sl
	movs r0, #4
	ldrsh r3, [r2, r0]
	movs r0, #4
	ldrsh r2, [r6, r0]
	subs r0, r3, r2
	cmp r1, r0
	blt _08236AA0
	adds r0, r3, r2
	cmp r1, r0
	bgt _08236AA0
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r2, #0
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r7, #0
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	mov r2, sl
	movs r0, #0
	ldrsh r3, [r2, r0]
	movs r0, #0
	ldrsh r2, [r6, r0]
	subs r0, r3, r2
	cmp r1, r0
	blt _08236AA0
	adds r0, r3, r2
	cmp r1, r0
	ble _08236AA4
_08236AA0:
	movs r0, #0
	b _08236AB2
_08236AA4:
	ldr r1, [sp, #0x24]
	strh r4, [r1, #2]
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r1, #4]
	strh r5, [r1]
	movs r0, #1
_08236AB2:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08236ac4
FUN_08236ac4: @ 0x08236AC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r1
	mov sl, r2
	adds r6, r3, #0
	ldrh r7, [r5, #4]
	ldrh r0, [r1, #4]
	lsls r3, r7, #0x10
	asrs r2, r3, #0x10
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov ip, r1
	cmp r0, #0
	beq _08236B98
	mov r4, sl
	movs r0, #4
	ldrsh r1, [r4, r0]
	cmp r1, r2
	bge _08236B06
	ldrh r0, [r6, #4]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r2
	ble _08236B16
	b _08236B14
_08236B06:
	ldrh r0, [r6, #4]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r2
	bge _08236B16
_08236B14:
	lsrs r4, r3, #0x10
_08236B16:
	mov r1, r8
	movs r0, #0
	ldrsh r2, [r1, r0]
	movs r1, #0
	ldrsh r0, [r5, r1]
	subs r2, r2, r0
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	mov sb, r1
	mov r0, sb
	muls r0, r2, r0
	mov r2, ip
	lsls r1, r2, #0x10
	asrs r7, r1, #0x10
	adds r1, r7, #0
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	str r0, [sp]
	asrs r1, r1, #0x10
	mov r2, sl
	movs r0, #0
	ldrsh r3, [r2, r0]
	movs r0, #0
	ldrsh r2, [r6, r0]
	subs r0, r3, r2
	cmp r1, r0
	blt _08236B98
	adds r0, r3, r2
	cmp r1, r0
	bgt _08236B98
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	movs r2, #2
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r7, #0
	bl Div
	ldrh r1, [r5, #2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	mov r2, sl
	movs r0, #2
	ldrsh r3, [r2, r0]
	movs r0, #2
	ldrsh r2, [r6, r0]
	subs r0, r3, r2
	cmp r1, r0
	blt _08236B98
	adds r0, r3, r2
	cmp r1, r0
	ble _08236B9C
_08236B98:
	movs r0, #0
	b _08236BAA
_08236B9C:
	ldr r1, [sp, #0x24]
	strh r4, [r1, #4]
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r1]
	strh r5, [r1, #2]
	movs r0, #1
_08236BAA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08236bbc
FUN_08236bbc: @ 0x08236BBC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	mov r8, r1
	adds r4, r3, #0
	adds r5, r2, #0
	adds r5, #0x24
	adds r6, r2, #0
	adds r6, #0x1c
	str r4, [sp]
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_082368d4
	cmp r0, #0
	bne _08236C08
	str r4, [sp]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_082369cc
	cmp r0, #0
	bne _08236C08
	str r4, [sp]
	adds r0, r7, #0
	mov r1, r8
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_08236ac4
	cmp r0, #0
	bne _08236C08
	movs r0, #0
	b _08236C0A
_08236C08:
	movs r0, #1
_08236C0A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08236C18:
	.byte 0xF0, 0xB5, 0x47, 0x46, 0x80, 0xB4, 0x96, 0xB0
	.byte 0x06, 0x1C, 0x0C, 0x1C, 0x24, 0x30, 0x31, 0x1C, 0x14, 0x31, 0x6A, 0x46, 0xFF, 0xF7, 0xDA, 0xFD
	.byte 0x6D, 0x46, 0x00, 0x20, 0x84, 0x46, 0x1C, 0x21, 0x68, 0x5E, 0x1C, 0x22, 0xA1, 0x5E, 0x40, 0x18
	.byte 0x00, 0x27, 0xB8, 0x46, 0x24, 0x21, 0x6B, 0x5E, 0x00, 0x04, 0x02, 0x14, 0x98, 0x1A, 0x24, 0x27
	.byte 0xE1, 0x5F, 0x88, 0x42, 0x04, 0xDC, 0x88, 0x1A, 0x98, 0x42, 0x01, 0xDC, 0x01, 0x20, 0x80, 0x46
	.byte 0x41, 0x46, 0x00, 0x29, 0x2E, 0xD0, 0x1E, 0x22, 0xA8, 0x5E, 0x1E, 0x27, 0xE1, 0x5F, 0x40, 0x18
	.byte 0x00, 0x21, 0x88, 0x46, 0x26, 0x22, 0xAB, 0x5E, 0x00, 0x04, 0x02, 0x14, 0x98, 0x1A, 0x26, 0x27
	.byte 0xE1, 0x5F, 0x88, 0x42, 0x04, 0xDC, 0x88, 0x1A, 0x98, 0x42, 0x01, 0xDC, 0x01, 0x20, 0x80, 0x46
	.byte 0x41, 0x46, 0x00, 0x29, 0x16, 0xD0, 0x20, 0x22, 0xA8, 0x5E, 0x20, 0x27, 0xE1, 0x5F, 0x40, 0x18
	.byte 0x00, 0x27, 0x28, 0x21, 0x6B, 0x5E, 0x00, 0x04, 0x02, 0x14, 0x98, 0x1A, 0x28, 0x25, 0x61, 0x5F
	.byte 0x88, 0x42, 0x03, 0xDC, 0x88, 0x1A, 0x98, 0x42, 0x00, 0xDC, 0x01, 0x27, 0x00, 0x2F, 0x01, 0xD0
	.byte 0x01, 0x27, 0xBC, 0x46, 0x60, 0x46, 0x00, 0x28, 0x09, 0xD0, 0x30, 0x1C, 0x24, 0x30, 0x31, 0x1C
	.byte 0x14, 0x31, 0x14, 0xAB, 0x22, 0x1C, 0xFF, 0xF7, 0x71, 0xFF, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20
	.byte 0x10, 0xE0, 0xE1, 0x88, 0x02, 0x20, 0x08, 0x40, 0x00, 0x28, 0x06, 0xD1, 0x14, 0x98, 0x15, 0x99
	.byte 0xE0, 0x62, 0x21, 0x63, 0xF0, 0x62, 0x31, 0x63, 0x03, 0xE0, 0x14, 0x98, 0x15, 0x99, 0xE0, 0x62
	.byte 0x21, 0x63, 0x01, 0x20, 0x16, 0xB0, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_08236d10
FUN_08236d10: @ 0x08236D10
	push {r4, lr}
	ldr r2, [r2]
	cmp r2, #0
	beq _08236D38
_08236D18:
	adds r1, r2, #0
	ldr r2, [r2]
	ldrh r0, [r1, #0x14]
	ldrh r4, [r1, #0xc]
	adds r0, r0, r4
	strh r0, [r1, #0x24]
	ldrh r0, [r1, #0x16]
	ldrh r4, [r1, #0xe]
	adds r0, r0, r4
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x18]
	ldrh r4, [r1, #0x10]
	adds r0, r0, r4
	strh r0, [r1, #0x28]
	cmp r2, #0
	bne _08236D18
_08236D38:
	ldr r3, [r3]
	cmp r3, #0
	beq _08236D6A
	movs r4, #4
_08236D40:
	adds r2, r3, #0
	ldr r3, [r3]
	ldrh r1, [r2, #6]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08236D66
	ldrh r0, [r2, #0x14]
	ldrh r1, [r2, #0xc]
	adds r0, r0, r1
	strh r0, [r2, #0x24]
	ldrh r0, [r2, #0x16]
	ldrh r1, [r2, #0xe]
	adds r0, r0, r1
	strh r0, [r2, #0x26]
	ldrh r0, [r2, #0x18]
	ldrh r1, [r2, #0x10]
	adds r0, r0, r1
	strh r0, [r2, #0x28]
_08236D66:
	cmp r3, #0
	bne _08236D40
_08236D6A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08236d70
FUN_08236d70: @ 0x08236D70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r2, #0
	mov sb, r3
	bl FUN_08236d10
	ldr r4, [r4]
	mov r8, r4
	cmp r4, #0
	beq _08236E3A
	ldr r0, _08236E30 @ =0x08236F19
	mov sl, r0
_08236D8E:
	mov r5, r8
	ldr r1, [r5]
	mov r8, r1
	mov r0, sb
	ldr r6, [r0]
_08236D98:
	cmp r6, #0
	beq _08236E34
	adds r4, r6, #0
	ldr r6, [r6]
	ldrh r1, [r5, #0xa]
	ldrh r0, [r4, #0xa]
	ands r0, r1
	cmp r0, #0
	bne _08236D98
	ldrh r3, [r4, #6]
	movs r0, #4
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	bne _08236D98
	ldrh r0, [r4, #4]
	cmp r0, #0
	beq _08236DC4
	ldrh r1, [r5, #4]
	cmp r0, r1
	beq _08236D98
_08236DC4:
	ldrh r1, [r5, #6]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08236DD8
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	bne _08236D98
_08236DD8:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08236DEC
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq _08236D98
_08236DEC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_sl
	cmp r0, #0
	beq _08236D98
	strh r7, [r4, #0x3e]
	ldrh r1, [r4, #6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08236E14
	ldr r3, [r5, #0x48]
	cmp r3, #0
	beq _08236E14
	ldr r2, [r5, #0x4c]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r3
_08236E14:
	ldrh r1, [r5, #6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08236D98
	ldr r3, [r4, #0x48]
	cmp r3, #0
	beq _08236D98
	ldr r2, [r4, #0x4c]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r3
	b _08236D98
	.align 2, 0
_08236E30: .4byte 0x08236F19
_08236E34:
	mov r0, r8
	cmp r0, #0
	bne _08236D8E
_08236E3A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08236e48
FUN_08236e48: @ 0x08236E48
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0xca
	ldrh r0, [r6]
	cmp r0, #0
	beq _08236E8A
	ldr r0, _08236E68 @ =0x030044BC
	ldr r5, [r0]
	cmp r5, #0
	beq _08236E6C
	movs r1, #0
	strh r1, [r6]
	ldr r0, [r4, #0x1c]
	str r1, [r0]
	b _08236E88
	.align 2, 0
_08236E68: .4byte 0x030044BC
_08236E6C:
	adds r1, r4, #0
	adds r1, #0xc8
	ldrh r0, [r1]
	cmp r0, #0
	beq _08236E82
	ldrh r0, [r6]
	ldrh r1, [r1]
	ldr r2, [r4, #0x1c]
	ldr r3, [r4, #0x18]
	bl FUN_08236d70
_08236E82:
	strh r5, [r6]
	ldr r0, [r4, #0x1c]
	str r5, [r0]
_08236E88:
	str r0, [r4, #0x24]
_08236E8A:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08236E94:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0x80, 0x07, 0x00, 0x03

	thumb_func_start FUN_08236ea0
FUN_08236ea0: @ 0x08236EA0
	push {lr}
	ldr r0, _08236ECC @ =0x03000780
	ldr r3, [r0]
	cmp r3, #0
	beq _08236EC8
	adds r2, r3, #0
	adds r2, #0x28
	str r2, [r3, #0x18]
	adds r0, r3, #0
	adds r0, #0x78
	str r0, [r3, #0x1c]
	movs r1, #0
	str r1, [r3, #0x28]
	str r1, [r3, #0x78]
	str r2, [r3, #0x20]
	str r0, [r3, #0x24]
	adds r0, #0x50
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_08236EC8:
	pop {r0}
	bx r0
	.align 2, 0
_08236ECC: .4byte 0x03000780

	thumb_func_start FUN_08236ed0
FUN_08236ed0: @ 0x08236ED0
	push {r4, r5, lr}
	ldr r5, _08236F00 @ =0x03000780
	ldr r0, [r5]
	cmp r0, #0
	bne _08236EF8
	movs r0, #0xb
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08236EF6
	ldr r1, _08236F04 @ =FUN_08236e48
	ldr r2, _08236F08 @ =0x08236E95
	bl SetEntityRoutine
	str r4, [r5]
	bl FUN_08236ea0
_08236EF6:
	adds r0, r4, #0
_08236EF8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08236F00: .4byte 0x03000780
_08236F04: .4byte FUN_08236e48
_08236F08: .4byte 0x08236E95
_08236F0C:
	.byte 0x01, 0x48, 0x00, 0x68
	.byte 0x70, 0x47, 0x00, 0x00, 0x80, 0x07, 0x00, 0x03, 0xF0, 0xB5, 0x04, 0x1C, 0x0D, 0x1C, 0x00, 0x20
	.byte 0x84, 0x46, 0x1C, 0x21, 0x60, 0x5E, 0x1C, 0x22, 0xA9, 0x5E, 0x40, 0x18, 0x00, 0x26, 0x24, 0x27
	.byte 0xE3, 0x5F, 0x00, 0x04, 0x02, 0x14, 0x98, 0x1A, 0x24, 0x27, 0xE9, 0x5F, 0x88, 0x42, 0x03, 0xDC
	.byte 0x88, 0x1A, 0x98, 0x42, 0x00, 0xDC, 0x01, 0x26, 0x00, 0x2E, 0x2B, 0xD0, 0x1E, 0x21, 0x60, 0x5E
	.byte 0x1E, 0x22, 0xA9, 0x5E, 0x40, 0x18, 0x00, 0x26, 0x26, 0x27, 0xE3, 0x5F, 0x00, 0x04, 0x02, 0x14
	.byte 0x98, 0x1A, 0x26, 0x27, 0xE9, 0x5F, 0x88, 0x42, 0x03, 0xDC, 0x88, 0x1A, 0x98, 0x42, 0x00, 0xDC
	.byte 0x01, 0x26, 0x00, 0x2E, 0x16, 0xD0, 0x20, 0x21, 0x60, 0x5E, 0x20, 0x22, 0xA9, 0x5E, 0x40, 0x18
	.byte 0x00, 0x26, 0x28, 0x27, 0xE3, 0x5F, 0x00, 0x04, 0x02, 0x14, 0x98, 0x1A, 0x28, 0x24, 0x29, 0x5F
	.byte 0x88, 0x42, 0x03, 0xDC, 0x88, 0x1A, 0x98, 0x42, 0x00, 0xDC, 0x01, 0x26, 0x00, 0x2E, 0x01, 0xD0
	.byte 0x01, 0x27, 0xBC, 0x46, 0x60, 0x46, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_08236fac
FUN_08236fac: @ 0x08236FAC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r6, #2
	adds r0, #4
	adds r2, r1, r0
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrb r0, [r2, #1]
	muls r0, r3, r0
	lsls r0, r0, #1
	adds r0, r1, r0
	str r0, [r4]
	movs r0, #0x40
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xa]
	cmp r0, r6
	bne _08237002
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08237002
	movs r3, #4
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _08236FF8
	ldrb r1, [r4, #4]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08237002
	b _08237036
_08236FF8:
	ldrb r1, [r4, #4]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08237036
_08237002:
	ldrb r0, [r2, #1]
	strb r0, [r4, #5]
	movs r0, #4
	ands r0, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08237016
	ldrb r0, [r4, #5]
	subs r0, #1
_08237016:
	strh r0, [r4, #8]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r1, r1, r0
	ldrh r1, [r1]
	movs r0, #0xf
	ands r0, r1
	movs r1, #0
	strb r0, [r4, #6]
	strb r0, [r4, #7]
	strh r1, [r4, #0xe]
	strh r6, [r4, #0xa]
	strb r5, [r4, #4]
	movs r0, #1
	b _0823703A
_08237036:
	strb r5, [r4, #4]
	movs r0, #0
_0823703A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08237040
FUN_08237040: @ 0x08237040
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, [sp, #0x10]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	movs r4, #0
	strb r4, [r0, #5]
	str r5, [sp]
	bl FUN_08236fac
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08237064
FUN_08237064: @ 0x08237064
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08237076
	movs r0, #1
	strb r0, [r4, #7]
_08237076:
	ldrb r0, [r4, #7]
	ldrh r1, [r4, #0xe]
	muls r1, r5, r1
	bl DivArm
	strh r0, [r4, #0xe]
	strb r5, [r4, #7]
	lsls r0, r5, #0x18
	cmp r0, #0
	bne _0823708E
	movs r0, #1
	strb r0, [r4, #7]
_0823708E:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08237098
FUN_08237098: @ 0x08237098
	push {lr}
	adds r2, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r3, r1, #0
	ldrh r0, [r2, #0xc]
	cmp r0, r1
	beq _082370BC
	ldrb r0, [r2, #6]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r2, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _082370BA
	movs r0, #1
	strb r0, [r2, #7]
_082370BA:
	strh r3, [r2, #0xc]
_082370BC:
	pop {r0}
	bx r0
_082370C0:
	.byte 0x81, 0x79, 0xC1, 0x71, 0x40, 0x21, 0x81, 0x81, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_082370cc
FUN_082370cc: @ 0x082370CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	mov ip, r1
	ldr r0, [sp, #0x20]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r7, [r1, #0x10]
	lsls r0, r2, #3
	adds r3, r0, r7
	ldr r1, [r1, #0x18]
	ldr r0, [r3, #4]
	adds r1, r1, r0
	mov r8, r1
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	bne _08237114
	movs r0, #2
	ands r0, r6
	cmp r0, #0
	beq _08237110
	ldrh r0, [r3, #2]
	lsls r0, r0, #2
	subs r0, #4
	b _0823711A
_08237110:
	mov r5, r8
	b _0823711C
_08237114:
	ldrh r0, [r4, #0x14]
	lsls r0, r0, #2
	mov r1, r8
_0823711A:
	adds r5, r1, r0
_0823711C:
	lsls r0, r2, #3
	adds r2, r0, r7
	ldrh r1, [r4, #0x12]
	mov sb, r0
	ldrh r2, [r2]
	cmp r1, r2
	bne _08237132
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _08237142
_08237132:
	ldrh r2, [r5]
	mov r0, sl
	lsls r3, r0, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	mov r1, ip
	bl FUN_0822f3cc
_08237142:
	mov r0, sb
	adds r1, r0, r7
	ldrh r0, [r1]
	strh r0, [r4, #0x12]
	ldrh r0, [r1, #2]
	strh r0, [r4, #0x16]
	ldrh r1, [r5, #2]
	ldrh r0, [r4, #0x10]
	muls r0, r1, r0
	cmp r0, #0
	blt _0823715C
	asrs r0, r0, #6
	b _08237162
_0823715C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08237162:
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0823716E
	movs r0, #1
	strh r0, [r4, #0xe]
_0823716E:
	strh r6, [r4, #0x18]
	mov r1, r8
	str r1, [r4, #0x54]
	mov r0, sl
	strb r0, [r4, #0x1b]
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	bne _0823719E
	movs r0, #2
	ands r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08237190
	ldrh r0, [r4, #0x16]
	subs r0, #1
_08237190:
	strh r0, [r4, #0x14]
	movs r0, #0
	movs r1, #0
	strh r1, [r4, #0xc]
	strb r0, [r4, #0x1d]
	movs r0, #0x40
	strh r0, [r4, #0x10]
_0823719E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_082371ac
FUN_082371ac: @ 0x082371AC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, [r7, #0x10]
	lsrs r2, r2, #0xd
	adds r6, r2, r0
	ldr r1, [r7, #0x18]
	ldr r0, [r6, #4]
	adds r1, r1, r0
	strh r3, [r5, #0x14]
	ldrh r0, [r6, #2]
	cmp r3, r0
	blo _082371D0
	subs r0, #1
	strh r0, [r5, #0x14]
_082371D0:
	ldrh r4, [r5, #0x14]
	lsls r4, r4, #2
	adds r4, r1, r4
	ldrh r2, [r4]
	ldrb r3, [r5, #0x1b]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0822f3cc
	ldrh r0, [r6, #2]
	strh r0, [r5, #0x16]
	ldrh r1, [r4, #2]
	ldrh r0, [r5, #0x10]
	muls r0, r1, r0
	cmp r0, #0
	blt _082371F4
	asrs r0, r0, #6
	b _082371FA
_082371F4:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_082371FA:
	strh r0, [r5, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08237206
	movs r0, #1
	strh r0, [r5, #0xe]
_08237206:
	movs r0, #0
	strh r0, [r5, #0xc]
	strb r0, [r5, #0x1d]
	ldrh r0, [r5, #0xc]
	adds r0, #1
	ldrh r1, [r5, #0xe]
	cmp r0, r1
	blt _08237236
	ldrh r1, [r5, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08237228
	ldrh r0, [r5, #0x14]
	cmp r0, #0
	bne _08237236
	b _08237232
_08237228:
	ldrh r0, [r5, #0x14]
	adds r0, #1
	ldrh r1, [r5, #0x16]
	cmp r0, r1
	blt _08237236
_08237232:
	movs r0, #1
	strb r0, [r5, #0x1d]
_08237236:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0823723c
FUN_0823723c: @ 0x0823723C
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x14]
	lsls r0, r0, #2
	ldr r2, [r3, #0x54]
	adds r2, r2, r0
	strh r1, [r3, #0x10]
	ldrh r1, [r2, #2]
	ldrh r0, [r3, #0x10]
	muls r0, r1, r0
	cmp r0, #0
	blt _08237258
	asrs r0, r0, #6
	b _0823725E
_08237258:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0823725E:
	strh r0, [r3, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0823726A
	movs r0, #1
	strh r0, [r3, #0xe]
_0823726A:
	ldrb r0, [r3, #0x1d]
	movs r2, #0xfe
	ands r2, r0
	movs r4, #0
	strb r2, [r3, #0x1d]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	ldrh r1, [r3, #0xe]
	cmp r0, r1
	blt _082372A2
	ldrh r1, [r3, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08237290
	ldrh r0, [r3, #0x14]
	cmp r0, #0
	bne _082372A2
	b _0823729A
_08237290:
	ldrh r0, [r3, #0x14]
	adds r0, #1
	ldrh r1, [r3, #0x16]
	cmp r0, r1
	blt _082372A2
_0823729A:
	movs r1, #1
	adds r0, r2, #0
	orrs r0, r1
	strb r0, [r3, #0x1d]
_082372A2:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_082372AC:
	.byte 0x30, 0xB5, 0x05, 0x1C
	.byte 0x0C, 0x04, 0x24, 0x0C, 0xE8, 0x89, 0xA9, 0x89, 0x61, 0x43, 0x14, 0xF0, 0x81, 0xFF, 0xA8, 0x81
	.byte 0xEC, 0x81, 0x01, 0x20, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_082372cc
FUN_082372cc: @ 0x082372CC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _082372DC
	movs r0, #0
	b _082373DC
_082372DC:
	movs r6, #0
	movs r7, #0
	strb r6, [r4, #0x1d]
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _082372FC
	ldrh r0, [r4, #0x14]
	lsls r0, r0, #2
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	ldrh r2, [r1]
	ldrb r3, [r4, #0x1b]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822f3cc
_082372FC:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #0xe]
	cmp r0, r1
	blo _082373AC
	ldrh r1, [r4, #0x18]
	movs r0, #2
	ands r0, r1
	adds r3, r1, #0
	cmp r0, #0
	beq _08237326
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	bne _08237322
	movs r6, #1
	b _08237340
_08237322:
	subs r0, #1
	b _0823733A
_08237326:
	ldrh r0, [r4, #0x14]
	adds r0, #1
	strh r0, [r4, #0x14]
	ldrh r1, [r4, #0x16]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _0823733C
	movs r6, #1
	subs r0, r1, #1
_0823733A:
	strh r0, [r4, #0x14]
_0823733C:
	cmp r6, #0
	beq _08237376
_08237340:
	ldrb r1, [r4, #0x1d]
	movs r0, #2
	movs r2, #0
	orrs r0, r1
	strb r0, [r4, #0x1d]
	ldrb r0, [r4, #0x1b]
	cmp r0, #2
	bne _08237354
	strb r2, [r4, #0x1b]
	b _0823737E
_08237354:
	cmp r0, #3
	bne _08237364
	strb r2, [r4, #0x1b]
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
	b _0823737E
_08237364:
	movs r0, #2
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _08237374
	ldrh r0, [r4, #0x16]
	subs r0, #1
_08237374:
	strh r0, [r4, #0x14]
_08237376:
	ldrb r1, [r4, #0x1d]
	movs r0, #4
	orrs r0, r1
	strb r0, [r4, #0x1d]
_0823737E:
	ldrh r0, [r4, #0x14]
	lsls r0, r0, #2
	ldr r1, [r4, #0x54]
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r4, #0xc]
	ldrh r1, [r1, #2]
	ldrh r0, [r4, #0x10]
	muls r0, r1, r0
	cmp r0, #0
	blt _08237398
	asrs r0, r0, #6
	b _0823739E
_08237398:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0823739E:
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _082373DA
	movs r0, #1
	strh r0, [r4, #0xe]
	b _082373DA
_082373AC:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	ldrh r1, [r4, #0xe]
	cmp r0, r1
	blt _082373DA
	ldrh r1, [r4, #0x18]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _082373C8
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	bne _082373DA
	b _082373D2
_082373C8:
	ldrh r0, [r4, #0x14]
	adds r0, #1
	ldrh r1, [r4, #0x16]
	cmp r0, r1
	blt _082373DA
_082373D2:
	ldrb r0, [r4, #0x1d]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0x1d]
_082373DA:
	adds r0, r6, #0
_082373DC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082373E4:
	.byte 0x00, 0xB5, 0x08, 0x69, 0xD2, 0x00, 0x12, 0x18, 0x89, 0x69, 0x50, 0x68
	.byte 0x09, 0x18, 0x00, 0x23, 0x50, 0x88, 0x83, 0x42, 0x06, 0xDA, 0x02, 0x1C, 0x48, 0x88, 0x1B, 0x18
	.byte 0x04, 0x31, 0x01, 0x3A, 0x00, 0x2A, 0xF9, 0xD1, 0x18, 0x1C, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_08237410
FUN_08237410: @ 0x08237410
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	ldr r6, _08237458 @ =0x0203B400
	movs r0, #3
	mov r8, r0
_0823741E:
	bl FUN_08230888
	adds r4, r0, #0
	bl FUN_08230888
	mov r1, r8
	ands r0, r1
	asrs r4, r0
	strh r4, [r6]
	adds r6, #2
	adds r7, #1
	ldr r5, _0823745C @ =0x000003FF
	cmp r7, r5
	ble _0823741E
	ldr r4, _08237460 @ =0x030046B8
	bl FUN_08230888
	ands r0, r5
	str r0, [r4]
	ldr r4, _08237464 @ =0x030046B4
	bl FUN_08230888
	ands r0, r5
	str r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08237458: .4byte 0x0203B400
_0823745C: .4byte 0x000003FF
_08237460: .4byte 0x030046B8
_08237464: .4byte 0x030046B4

	thumb_func_start FUN_08237468
FUN_08237468: @ 0x08237468
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov ip, r1
	adds r7, r2, #0
	adds r5, r3, #0
	ldr r0, [sp, #0x20]
	mov sb, r0
	movs r0, #1
	mov r1, sb
	lsls r0, r1
	subs r6, r0, r5
	movs r0, #0xf
	mov sl, r0
_0823748A:
	mov r0, ip
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r3, r0, #0
	muls r3, r6, r3
	ldrh r4, [r7]
	movs r0, #0x1f
	ands r0, r4
	muls r0, r5, r0
	adds r3, r3, r0
	mov r0, sb
	asrs r3, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r2, r0, #0
	muls r2, r6, r2
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r4
	muls r0, r5, r0
	adds r2, r2, r0
	mov r0, sb
	asrs r2, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	adds r1, r0, #0
	muls r1, r6, r1
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r4
	muls r0, r5, r0
	adds r1, r1, r0
	mov r0, sb
	asrs r1, r0
	movs r0, #0x1f
	ands r3, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r2, r0
	orrs r3, r2
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r1, r0
	orrs r3, r1
	mov r1, r8
	strh r3, [r1]
	movs r0, #2
	add ip, r0
	adds r7, #2
	add r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add sl, r1
	mov r0, sl
	cmp r0, #0
	bge _0823748A
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08237510
FUN_08237510: @ 0x08237510
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	adds r7, r1, #0
	adds r4, r3, #0
	ldr r0, [sp, #0x24]
	mov sb, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0x1f
	ands r1, r2
	str r1, [sp]
	movs r3, #0xf8
	lsls r3, r3, #2
	mov r8, r2
	mov r0, r8
	ands r0, r3
	mov r8, r0
	movs r1, #0xf8
	lsls r1, r1, #7
	adds r6, r2, #0
	ands r6, r1
	movs r0, #1
	mov r2, sb
	lsls r0, r2
	subs r5, r0, r4
	movs r0, #0xf
	mov sl, r0
_08237550:
	ldrh r1, [r7]
	movs r0, #0x1f
	ands r0, r1
	adds r3, r0, #0
	muls r3, r5, r3
	ldr r2, [sp]
	adds r0, r2, #0
	muls r0, r4, r0
	adds r3, r3, r0
	mov r0, sb
	asrs r3, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r2, r0, #0
	muls r2, r5, r2
	mov r0, r8
	muls r0, r4, r0
	adds r2, r2, r0
	mov r0, sb
	asrs r2, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	muls r0, r5, r0
	adds r1, r6, #0
	muls r1, r4, r1
	adds r0, r0, r1
	mov r1, sb
	asrs r0, r1
	movs r1, #0x1f
	ands r3, r1
	movs r1, #0xf8
	lsls r1, r1, #2
	ands r2, r1
	orrs r3, r2
	movs r2, #0xf8
	lsls r2, r2, #7
	ands r0, r2
	orrs r3, r0
	mov r0, ip
	strh r3, [r0]
	adds r7, #2
	movs r1, #2
	add ip, r1
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	bge _08237550
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082375c8
FUN_082375c8: @ 0x082375C8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	cmp r5, r3
	bgt _082375DC
	movs r0, #0
	cmp r5, r2
	ble _082375DC
	movs r0, #1
_082375DC:
	ldr r1, _08237604 @ =0x085B0A00
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	cmp r0, #0
	bne _0823760C
	ldr r1, [r4]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _08237608
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _0823760A
	.align 2, 0
_08237604: .4byte 0x085B0A00
_08237608:
	orrs r1, r2
_0823760A:
	str r1, [r4]
_0823760C:
	cmp r5, #0x3c
	bgt _08237614
	movs r0, #0
	b _0823761E
_08237614:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
_0823761E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08237624
FUN_08237624: @ 0x08237624
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r6, r3, #0
	ldr r3, [sp, #0x14]
	movs r7, #0
	ldrb r2, [r5]
	ldr r1, _08237644 @ =0x030044E0
	lsls r0, r0, #3
	adds r1, r0, r1
	ldrh r0, [r1, #2]
	ands r0, r4
	cmp r0, #0
	beq _08237648
	adds r2, r3, #0
	b _0823765A
	.align 2, 0
_08237644: .4byte 0x030044E0
_08237648:
	ldrh r0, [r1]
	ands r0, r4
	cmp r0, #0
	beq _08237658
	cmp r2, r3
	bge _0823765E
	adds r2, #1
	b _0823765A
_08237658:
	movs r2, #0
_0823765A:
	cmp r2, r3
	blt _08237662
_0823765E:
	movs r2, #0
	adds r7, r6, #0
_08237662:
	strb r2, [r5]
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823766c
FUN_0823766c: @ 0x0823766C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	b _0823767C
_08237674:
	strb r3, [r1]
	adds r4, #1
	adds r1, #1
	adds r0, #1
_0823767C:
	cmp r0, r2
	bge _08237686
	ldrb r3, [r4]
	cmp r3, #0
	bne _08237674
_08237686:
	adds r2, #1
	cmp r0, r2
	bge _0823769A
	movs r3, #0
	subs r0, r2, r0
_08237690:
	strb r3, [r1]
	adds r1, #1
	subs r0, #1
	cmp r0, #0
	bne _08237690
_0823769A:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082376a4
FUN_082376a4: @ 0x082376A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r4, r0, #0
	str r1, [sp, #0x20]
	mov sl, r3
	ldr r6, [sp, #0x44]
	cmp r3, #8
	ble _082376C0
	movs r0, #8
	mov sl, r0
_082376C0:
	movs r3, #0
	adds r1, r6, #0
	ldr r0, _082377CC @ =0x0098967F
	ldr r5, [sp, #0x54]
	rsbs r7, r5, #0
	cmp r2, r0
	ble _082376D8
	ldr r5, _082377D0 @ =0xFF676980
_082376D0:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _082376D0
_082376D8:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	ldr r0, _082377D4 @ =0x000F423F
	cmp r2, r0
	ble _082376F2
	ldr r5, _082377D8 @ =0xFFF0BDC0
_082376EA:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _082376EA
_082376F2:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	ldr r0, _082377DC @ =0x0001869F
	cmp r2, r0
	ble _0823770C
	ldr r5, _082377E0 @ =0xFFFE7960
_08237704:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _08237704
_0823770C:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	ldr r0, _082377E4 @ =0x0000270F
	cmp r2, r0
	ble _08237726
	ldr r5, _082377E8 @ =0xFFFFD8F0
_0823771E:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _0823771E
_08237726:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	ldr r0, _082377EC @ =0x000003E7
	cmp r2, r0
	ble _08237740
	ldr r5, _082377F0 @ =0xFFFFFC18
_08237738:
	adds r1, #1
	adds r2, r2, r5
	cmp r2, r0
	bgt _08237738
_08237740:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	cmp r2, #0x63
	ble _08237756
_0823774E:
	adds r1, #1
	subs r2, #0x64
	cmp r2, #0x63
	bgt _0823774E
_08237756:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	cmp r2, #9
	ble _0823776C
_08237764:
	adds r1, #1
	subs r2, #0xa
	cmp r2, #9
	bgt _08237764
_0823776C:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	adds r1, r6, #0
	cmp r2, #0
	ble _08237782
_0823777A:
	adds r1, #1
	subs r2, #1
	cmp r2, #0
	bgt _0823777A
_08237782:
	lsls r0, r3, #2
	add r0, sp
	str r1, [r0]
	adds r3, #1
	mov r0, sl
	subs r0, r3, r0
	mov sb, r0
	ldr r1, [sp, #0x54]
	orrs r7, r1
	lsrs r7, r7, #0x1f
	mov r8, r7
	ldr r7, [sp, #0x48]
	movs r6, #0
	cmp r6, sl
	bge _08237824
	lsls r0, r0, #2
	mov r1, sp
	adds r5, r0, r1
_082377A6:
	mov r0, sb
	adds r2, r0, r6
	mov r1, r8
	cmp r1, #0
	beq _082377F4
	ldr r0, [r5]
	cmp r0, #0
	beq _082377BA
	movs r0, #0
	mov r8, r0
_082377BA:
	mov r1, r8
	cmp r1, #0
	beq _082377F4
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
	b _08237816
	.align 2, 0
_082377CC: .4byte 0x0098967F
_082377D0: .4byte 0xFF676980
_082377D4: .4byte 0x000F423F
_082377D8: .4byte 0xFFF0BDC0
_082377DC: .4byte 0x0001869F
_082377E0: .4byte 0xFFFE7960
_082377E4: .4byte 0x0000270F
_082377E8: .4byte 0xFFFFD8F0
_082377EC: .4byte 0x000003E7
_082377F0: .4byte 0xFFFFFC18
_082377F4:
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	lsls r0, r2, #2
	add r0, sp
	ldrh r2, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r3, #0
	bl FUN_0822f3cc
	strh r7, [r4, #0x20]
	add r0, sp, #0x4c
	ldrh r0, [r0]
	strh r0, [r4, #0x22]
_08237816:
	ldr r1, [sp, #0x50]
	adds r7, r7, r1
	adds r5, #4
	adds r6, #1
	adds r4, #0x60
	cmp r6, sl
	blt _082377A6
_08237824:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08237834:
	.byte 0x00, 0x04, 0x00, 0x0C, 0x10, 0x30, 0xFF, 0x21, 0x08, 0x40, 0x40, 0x11
	.byte 0x03, 0x30, 0x07, 0x21, 0x08, 0x40, 0x70, 0x47, 0x00, 0x04, 0x00, 0x0C, 0x20, 0x30, 0xFF, 0x21
	.byte 0x08, 0x40, 0x80, 0x11, 0x01, 0x30, 0x03, 0x21, 0x08, 0x40, 0x70, 0x47

	thumb_func_start FUN_0823785c
FUN_0823785c: @ 0x0823785C
	push {r4, lr}
	adds r2, r0, #0
	cmp r2, #0
	bne _08237874
	cmp r1, #0
	beq _0823787C
	cmp r1, #0
	ble _08237870
	movs r0, #0x40
	b _08237964
_08237870:
	movs r0, #0xc0
	b _08237964
_08237874:
	cmp r1, #0
	bne _08237884
	cmp r2, #0
	ble _08237880
_0823787C:
	movs r0, #0
	b _08237964
_08237880:
	movs r0, #0x80
	b _08237964
_08237884:
	cmp r2, #0
	ble _082378FC
	cmp r1, #0
	ble _082378BC
	cmp r2, r1
	ble _082378A4
	ldr r4, _082378A0 @ =0x085B0C88
	lsls r0, r1, #8
	adds r1, r2, #0
	bl Div
	adds r0, r0, r4
	ldrb r0, [r0]
	b _08237964
	.align 2, 0
_082378A0: .4byte 0x085B0C88
_082378A4:
	lsls r0, r2, #8
	bl Div
	ldr r1, _082378B8 @ =0x085B0C88
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x40
	subs r0, r0, r1
	b _08237964
	.align 2, 0
_082378B8: .4byte 0x085B0C88
_082378BC:
	rsbs r3, r1, #0
	cmp r2, r3
	ble _082378E4
	lsls r0, r1, #8
	rsbs r0, r0, #0
	adds r1, r2, #0
	bl Div
	ldr r1, _082378E0 @ =0x085B0C88
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	b _08237964
	.align 2, 0
_082378E0: .4byte 0x085B0C88
_082378E4:
	lsls r0, r2, #8
	adds r1, r3, #0
	bl Div
	ldr r1, _082378F8 @ =0x085B0C88
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #0xc0
	b _08237964
	.align 2, 0
_082378F8: .4byte 0x085B0C88
_082378FC:
	cmp r1, #0
	ble _08237934
	rsbs r3, r2, #0
	cmp r3, r1
	ble _08237920
	lsls r0, r1, #8
	adds r1, r3, #0
	bl Div
	ldr r1, _0823791C @ =0x085B0C88
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	b _08237964
	.align 2, 0
_0823791C: .4byte 0x085B0C88
_08237920:
	lsls r0, r2, #8
	bl Div
	ldr r1, _08237930 @ =0x085B0C88
	subs r1, r1, r0
	ldrb r0, [r1]
	adds r0, #0x40
	b _08237964
	.align 2, 0
_08237930: .4byte 0x085B0C88
_08237934:
	rsbs r4, r2, #0
	rsbs r3, r1, #0
	cmp r4, r3
	bgt _08237954
	lsls r0, r2, #8
	adds r1, r3, #0
	bl Div
	ldr r1, _08237950 @ =0x085B0C88
	subs r1, r1, r0
	ldrb r1, [r1]
	movs r0, #0xc0
	subs r0, r0, r1
	b _08237964
	.align 2, 0
_08237950: .4byte 0x085B0C88
_08237954:
	lsls r0, r1, #8
	adds r1, r4, #0
	bl Div
	ldr r1, _0823796C @ =0x085B0C88
	subs r1, r1, r0
	ldrb r0, [r1]
	adds r0, #0x80
_08237964:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823796C: .4byte 0x085B0C88

	thumb_func_start FUN_08237970
FUN_08237970: @ 0x08237970
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r2, [sp, #0x14]
	movs r0, #1
	lsls r0, r2
	subs r4, r0, r3
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r1, r0, #0
	muls r1, r4, r1
	movs r7, #0
	ldrsh r0, [r6, r7]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _08237998
	asrs r0, r2
	b _0823799E
_08237998:
	rsbs r0, r0, #0
	asrs r0, r2
	rsbs r0, r0, #0
_0823799E:
	mov r1, ip
	strh r0, [r1]
	movs r7, #2
	ldrsh r0, [r5, r7]
	adds r1, r0, #0
	muls r1, r4, r1
	movs r7, #2
	ldrsh r0, [r6, r7]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _082379BA
	asrs r0, r2
	b _082379C0
_082379BA:
	rsbs r0, r0, #0
	asrs r0, r2
	rsbs r0, r0, #0
_082379C0:
	mov r1, ip
	strh r0, [r1, #2]
	movs r7, #4
	ldrsh r0, [r5, r7]
	adds r1, r0, #0
	muls r1, r4, r1
	movs r4, #4
	ldrsh r0, [r6, r4]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _082379DC
	asrs r0, r2
	b _082379E2
_082379DC:
	rsbs r0, r0, #0
	asrs r0, r2
	rsbs r0, r0, #0
_082379E2:
	mov r7, ip
	strh r0, [r7, #4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_082379ec
FUN_082379ec: @ 0x082379EC
	ldr r1, _082379F4 @ =0x04000208
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_082379F4: .4byte 0x04000208

	thumb_func_start FUN_082379f8
FUN_082379f8: @ 0x082379F8
	ldr r1, _08237A00 @ =0x04000208
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_08237A00: .4byte 0x04000208

	thumb_func_start FUN_08237a04
FUN_08237a04: @ 0x08237A04
	push {r4, r5, lr}
	ldr r4, _08237A40 @ =0x04000208
	movs r0, #0
	strh r0, [r4]
	ldr r2, _08237A44 @ =0x04000200
	ldrh r3, [r2]
	strh r0, [r2]
	ldr r1, _08237A48 @ =0x0400010C
	ldr r5, _08237A4C @ =0x0000F5D8
	adds r0, r5, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xc1
	strh r0, [r1]
	ldr r1, _08237A50 @ =0x03002CB0
	ldr r0, _08237A54 @ =FUN_08237aac
	str r0, [r1, #8]
	movs r1, #0x40
	adds r0, r1, #0
	orrs r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	strh r0, [r2]
	movs r0, #1
	strh r0, [r4]
	ldr r0, _08237A58 @ =0x04000202
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08237A40: .4byte 0x04000208
_08237A44: .4byte 0x04000200
_08237A48: .4byte 0x0400010C
_08237A4C: .4byte 0x0000F5D8
_08237A50: .4byte 0x03002CB0
_08237A54: .4byte FUN_08237aac
_08237A58: .4byte 0x04000202

	thumb_func_start FUN_08237a5c
FUN_08237a5c: @ 0x08237A5C
	push {r4, lr}
	ldr r4, _08237A90 @ =0x04000208
	movs r1, #0
	strh r1, [r4]
	ldr r2, _08237A94 @ =0x04000200
	ldrh r3, [r2]
	strh r1, [r2]
	ldr r0, _08237A98 @ =0x0400010E
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	ldr r1, _08237A9C @ =0x03002CB0
	ldr r0, _08237AA0 @ =FUN_0822a18c
	str r0, [r1, #8]
	ldr r0, _08237AA4 @ =0x0000FFBF
	ands r0, r3
	strh r0, [r2]
	movs r0, #1
	strh r0, [r4]
	ldr r1, _08237AA8 @ =0x04000202
	movs r0, #0x40
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08237A90: .4byte 0x04000208
_08237A94: .4byte 0x04000200
_08237A98: .4byte 0x0400010E
_08237A9C: .4byte 0x03002CB0
_08237AA0: .4byte FUN_0822a18c
_08237AA4: .4byte 0x0000FFBF
_08237AA8: .4byte 0x04000202

	thumb_func_start FUN_08237aac
FUN_08237aac: @ 0x08237AAC
	push {r4, r5, r6, lr}
	ldr r0, _08237AF0 @ =0x04000122
	ldrh r0, [r0]
	adds r3, r0, #0
	ldr r0, _08237AF4 @ =0x04000124
	ldrh r0, [r0]
	adds r2, r0, #0
	ldr r0, _08237AF8 @ =0x04000126
	ldrh r0, [r0]
	adds r4, r0, #0
	movs r5, #0
	ldr r0, _08237AFC @ =0x030046BC
	strh r3, [r0]
	ldr r0, _08237B00 @ =0x04000128
	ldrh r1, [r0]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _08237ADC
	ldr r0, _08237B04 @ =0x0000FFFF
	cmp r2, r0
	bne _08237AE6
	cmp r4, r2
	beq _08237B1C
_08237ADC:
	ldr r0, _08237B04 @ =0x0000FFFF
	cmp r2, r0
	bne _08237AE6
	cmp r4, r2
	beq _08237B0C
_08237AE6:
	ldr r1, _08237B08 @ =0x030046D4
	movs r0, #7
	rsbs r0, r0, #0
	str r0, [r1]
	b _08237B90
	.align 2, 0
_08237AF0: .4byte 0x04000122
_08237AF4: .4byte 0x04000124
_08237AF8: .4byte 0x04000126
_08237AFC: .4byte 0x030046BC
_08237B00: .4byte 0x04000128
_08237B04: .4byte 0x0000FFFF
_08237B08: .4byte 0x030046D4
_08237B0C:
	ldr r1, _08237B18 @ =0x030046D4
	movs r0, #8
	rsbs r0, r0, #0
	str r0, [r1]
	b _08237B90
	.align 2, 0
_08237B18: .4byte 0x030046D4
_08237B1C:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r3
	ldr r6, _08237BB0 @ =0x03000790
	cmp r0, #0
	beq _08237B46
	cmp r3, r4
	beq _08237B46
	ldr r1, _08237BB4 @ =0x030007A0
	ldr r2, _08237BB8 @ =0x03000788
	ldr r0, [r2]
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #1
	movs r1, #0x3f
	ands r0, r1
	str r0, [r2]
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
_08237B46:
	ldr r0, [r6]
	cmp r0, #0x3e
	ble _08237B52
	movs r0, #0x80
	lsls r0, r0, #7
	orrs r5, r0
_08237B52:
	ldr r6, _08237BBC @ =0x0300079C
	ldr r4, [r6]
	cmp r4, #0
	ble _08237B82
	movs r0, #0x80
	lsls r0, r0, #7
	ands r3, r0
	cmp r3, #0
	bne _08237B82
	ldr r0, _08237BC0 @ =0x030007E0
	ldr r2, _08237BC4 @ =0x03000798
	ldr r1, [r2]
	adds r0, r1, r0
	ldrb r0, [r0]
	orrs r5, r0
	adds r1, #1
	movs r0, #0x3f
	ands r1, r0
	str r1, [r2]
	subs r0, r4, #1
	str r0, [r6]
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r5, r0
_08237B82:
	ldr r0, _08237BC8 @ =0x0000FFFF
	cmp r5, r0
	bne _08237B8C
	movs r5, #0x80
	lsls r5, r5, #8
_08237B8C:
	ldr r0, _08237BCC @ =0x0400012A
	strh r5, [r0]
_08237B90:
	ldr r2, _08237BD0 @ =0x04000128
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08237BD4 @ =0x0400010C
	ldr r2, _08237BD8 @ =0x0000F5D8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08237BDC @ =0x030046C0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08237BB0: .4byte 0x03000790
_08237BB4: .4byte 0x030007A0
_08237BB8: .4byte 0x03000788
_08237BBC: .4byte 0x0300079C
_08237BC0: .4byte 0x030007E0
_08237BC4: .4byte 0x03000798
_08237BC8: .4byte 0x0000FFFF
_08237BCC: .4byte 0x0400012A
_08237BD0: .4byte 0x04000128
_08237BD4: .4byte 0x0400010C
_08237BD8: .4byte 0x0000F5D8
_08237BDC: .4byte 0x030046C0

	thumb_func_start FUN_08237be0
FUN_08237be0: @ 0x08237BE0
	push {r4, r5, r6, lr}
	ldr r5, _08237C1C @ =0x04000208
	movs r0, #0
	strh r0, [r5]
	ldr r3, _08237C20 @ =0x04000200
	ldrh r4, [r3]
	strh r0, [r3]
	ldr r1, _08237C24 @ =0x03002CB0
	ldr r0, _08237C28 @ =FUN_08237c88
	str r0, [r1, #4]
	ldr r2, _08237C2C @ =0x04000128
	ldrh r0, [r2]
	movs r6, #0x80
	lsls r6, r6, #7
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	adds r0, r1, #0
	orrs r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	ldr r0, _08237C30 @ =0x04000202
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08237C1C: .4byte 0x04000208
_08237C20: .4byte 0x04000200
_08237C24: .4byte 0x03002CB0
_08237C28: .4byte FUN_08237c88
_08237C2C: .4byte 0x04000128
_08237C30: .4byte 0x04000202

	thumb_func_start FUN_08237c34
FUN_08237c34: @ 0x08237C34
	push {r4, r5, lr}
	ldr r5, _08237C68 @ =0x04000208
	movs r0, #0
	strh r0, [r5]
	ldr r3, _08237C6C @ =0x04000200
	ldrh r4, [r3]
	strh r0, [r3]
	ldr r1, _08237C70 @ =0x03002CB0
	ldr r0, _08237C74 @ =FUN_0822a18c
	str r0, [r1, #4]
	ldr r2, _08237C78 @ =0x04000128
	ldrh r1, [r2]
	ldr r0, _08237C7C @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08237C80 @ =0x0000FF7F
	ands r0, r4
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	ldr r1, _08237C84 @ =0x04000202
	movs r0, #0x80
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08237C68: .4byte 0x04000208
_08237C6C: .4byte 0x04000200
_08237C70: .4byte 0x03002CB0
_08237C74: .4byte FUN_0822a18c
_08237C78: .4byte 0x04000128
_08237C7C: .4byte 0x0000BFFF
_08237C80: .4byte 0x0000FF7F
_08237C84: .4byte 0x04000202

	thumb_func_start FUN_08237c88
FUN_08237c88: @ 0x08237C88
	push {r4, r5, r6, lr}
	ldr r0, _08237CCC @ =0x04000120
	ldrh r0, [r0]
	adds r3, r0, #0
	ldr r0, _08237CD0 @ =0x04000124
	ldrh r0, [r0]
	adds r2, r0, #0
	ldr r0, _08237CD4 @ =0x04000126
	ldrh r0, [r0]
	adds r4, r0, #0
	movs r5, #0
	ldr r0, _08237CD8 @ =0x030046D0
	strh r3, [r0]
	ldr r0, _08237CDC @ =0x04000128
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08237CB8
	ldr r0, _08237CE0 @ =0x0000FFFF
	cmp r2, r0
	bne _08237CC2
	cmp r4, r2
	beq _08237CF4
_08237CB8:
	ldr r0, _08237CE0 @ =0x0000FFFF
	cmp r2, r0
	bne _08237CC2
	cmp r4, r2
	beq _08237CE8
_08237CC2:
	ldr r1, _08237CE4 @ =0x030046D4
	movs r0, #7
	rsbs r0, r0, #0
	b _08237D8A
	.align 2, 0
_08237CCC: .4byte 0x04000120
_08237CD0: .4byte 0x04000124
_08237CD4: .4byte 0x04000126
_08237CD8: .4byte 0x030046D0
_08237CDC: .4byte 0x04000128
_08237CE0: .4byte 0x0000FFFF
_08237CE4: .4byte 0x030046D4
_08237CE8:
	ldr r1, _08237CF0 @ =0x030046D4
	movs r0, #8
	rsbs r0, r0, #0
	b _08237D8A
	.align 2, 0
_08237CF0: .4byte 0x030046D4
_08237CF4:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r3
	ldr r6, _08237D9C @ =0x03000790
	cmp r0, #0
	beq _08237D1E
	cmp r3, r4
	beq _08237D1E
	ldr r1, _08237DA0 @ =0x030007A0
	ldr r2, _08237DA4 @ =0x03000788
	ldr r0, [r2]
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #1
	movs r1, #0x3f
	ands r0, r1
	str r0, [r2]
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
_08237D1E:
	ldr r0, [r6]
	cmp r0, #0x3e
	ble _08237D2A
	movs r0, #0x80
	lsls r0, r0, #7
	orrs r5, r0
_08237D2A:
	ldr r6, _08237DA8 @ =0x0300079C
	ldr r4, [r6]
	cmp r4, #0
	ble _08237D5A
	movs r0, #0x80
	lsls r0, r0, #7
	ands r3, r0
	cmp r3, #0
	bne _08237D5A
	ldr r0, _08237DAC @ =0x030007E0
	ldr r2, _08237DB0 @ =0x03000798
	ldr r1, [r2]
	adds r0, r1, r0
	ldrb r0, [r0]
	orrs r5, r0
	adds r1, #1
	movs r0, #0x3f
	ands r1, r0
	str r1, [r2]
	subs r0, r4, #1
	str r0, [r6]
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r5, r0
_08237D5A:
	ldr r0, _08237DB4 @ =0x0000FFFF
	cmp r5, r0
	bne _08237D64
	movs r5, #0x80
	lsls r5, r5, #8
_08237D64:
	ldr r0, _08237DB8 @ =0x0400012A
	strh r5, [r0]
	ldr r2, _08237DBC @ =0x030046CC
	ldr r1, [r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08237D8C
	ldr r0, _08237DC0 @ =0x04000128
	ldrh r0, [r0]
	lsrs r0, r0, #4
	movs r1, #3
	ands r0, r1
	str r0, [r2]
	cmp r0, #1
	beq _08237D8C
	ldr r1, _08237DC4 @ =0x030046D4
	movs r0, #5
	rsbs r0, r0, #0
_08237D8A:
	str r0, [r1]
_08237D8C:
	ldr r1, _08237DC8 @ =0x030046C8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08237D9C: .4byte 0x03000790
_08237DA0: .4byte 0x030007A0
_08237DA4: .4byte 0x03000788
_08237DA8: .4byte 0x0300079C
_08237DAC: .4byte 0x030007E0
_08237DB0: .4byte 0x03000798
_08237DB4: .4byte 0x0000FFFF
_08237DB8: .4byte 0x0400012A
_08237DBC: .4byte 0x030046CC
_08237DC0: .4byte 0x04000128
_08237DC4: .4byte 0x030046D4
_08237DC8: .4byte 0x030046C8

	thumb_func_start FUN_08237dcc
FUN_08237dcc: @ 0x08237DCC
	push {r4, lr}
	ldr r0, _08237E0C @ =0x030046D4
	movs r3, #0
	str r3, [r0]
	ldr r1, _08237E10 @ =0x030046CC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	ldr r4, _08237E14 @ =0x04000208
	strh r3, [r4]
	ldr r2, _08237E18 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08237E1C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r4]
	ldr r0, _08237E20 @ =0x04000134
	strh r3, [r0]
	subs r2, #0xd8
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08237E0C: .4byte 0x030046D4
_08237E10: .4byte 0x030046CC
_08237E14: .4byte 0x04000208
_08237E18: .4byte 0x04000200
_08237E1C: .4byte 0x0000FF7F
_08237E20: .4byte 0x04000134

	thumb_func_start FUN_08237e24
FUN_08237e24: @ 0x08237E24
	push {r4, lr}
	ldr r4, _08237E48 @ =0x0400012A
	movs r0, #0
	strh r0, [r4]
	ldr r0, _08237E4C @ =0x04000128
	ldrh r0, [r0]
	adds r1, r0, #0
	adds r3, r1, #0
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08237E54
	ldr r1, _08237E50 @ =0x030046D4
	movs r0, #9
	rsbs r0, r0, #0
	str r0, [r1]
	b _08237E8E
	.align 2, 0
_08237E48: .4byte 0x0400012A
_08237E4C: .4byte 0x04000128
_08237E50: .4byte 0x030046D4
_08237E54:
	movs r0, #0x80
	ands r1, r0
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08237E70
	ldr r1, _08237E6C @ =0x030046D4
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
	b _08237E8E
	.align 2, 0
_08237E6C: .4byte 0x030046D4
_08237E70:
	movs r0, #4
	ands r3, r0
	cmp r3, #0
	bne _08237E84
	ldr r0, _08237E80 @ =0x030046CC
	str r2, [r0]
	b _08237E8C
	.align 2, 0
_08237E80: .4byte 0x030046CC
_08237E84:
	ldr r1, _08237E94 @ =0x030046CC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
_08237E8C:
	strh r2, [r4]
_08237E8E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08237E94: .4byte 0x030046CC

	thumb_func_start FUN_08237e98
FUN_08237e98: @ 0x08237E98
	push {lr}
	ldr r1, _08237EAC @ =0x030046D4
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	bl FUN_08237dcc
	pop {r0}
	bx r0
	.align 2, 0
_08237EAC: .4byte 0x030046D4

	thumb_func_start FUN_08237eb0
FUN_08237eb0: @ 0x08237EB0
	bx lr
	.align 2, 0

	thumb_func_start FUN_08237eb4
FUN_08237eb4: @ 0x08237EB4
	push {r4, r5, r6, r7, lr}
	ldr r2, _08237F18 @ =0x03000788
	ldr r0, _08237F1C @ =0x0300078C
	movs r1, #0
	str r1, [r0]
	str r1, [r2]
	ldr r2, _08237F20 @ =0x03000794
	ldr r0, _08237F24 @ =0x03000798
	str r1, [r0]
	str r1, [r2]
	ldr r0, _08237F28 @ =0x03000790
	str r1, [r0]
	ldr r0, _08237F2C @ =0x0300079C
	str r1, [r0]
	ldr r5, _08237F30 @ =0x030046D4
	ldr r6, _08237F34 @ =0x030046CC
	ldr r0, _08237F38 @ =0x030046C0
	mov ip, r0
	ldr r7, _08237F3C @ =0x030046C8
	ldr r4, _08237F40 @ =0x030007A0
	movs r2, #0
	ldr r3, _08237F44 @ =0x030007E0
_08237EE0:
	adds r0, r1, r4
	strb r2, [r0]
	adds r0, r1, r3
	strb r2, [r0]
	adds r1, #1
	cmp r1, #0x3f
	ble _08237EE0
	movs r1, #0
	str r1, [r5]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r6]
	str r1, [r7]
	mov r0, ip
	str r1, [r0]
	bl FUN_08237e24
	ldr r0, [r5]
	cmp r0, #0
	blt _08237F4E
	ldr r0, [r6]
	cmp r0, #0
	beq _08237F48
	bl FUN_08237be0
	movs r0, #1
	b _08237F4E
	.align 2, 0
_08237F18: .4byte 0x03000788
_08237F1C: .4byte 0x0300078C
_08237F20: .4byte 0x03000794
_08237F24: .4byte 0x03000798
_08237F28: .4byte 0x03000790
_08237F2C: .4byte 0x0300079C
_08237F30: .4byte 0x030046D4
_08237F34: .4byte 0x030046CC
_08237F38: .4byte 0x030046C0
_08237F3C: .4byte 0x030046C8
_08237F40: .4byte 0x030007A0
_08237F44: .4byte 0x030007E0
_08237F48:
	bl FUN_08237a04
	movs r0, #0
_08237F4E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08237f54
FUN_08237f54: @ 0x08237F54
	push {lr}
	ldr r0, _08237F64 @ =0x030046CC
	ldr r0, [r0]
	cmp r0, #0
	bne _08237F68
	bl FUN_08237a5c
	b _08237F6C
	.align 2, 0
_08237F64: .4byte 0x030046CC
_08237F68:
	bl FUN_08237c34
_08237F6C:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08237f74
FUN_08237f74: @ 0x08237F74
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _08237FB4 @ =0x030046D4
	mov r8, r0
	ldr r0, [r0]
	cmp r0, #0
	blt _0823800A
	bl FUN_082379ec
	ldr r0, _08237FB8 @ =0x0300078C
	ldr r4, [r0]
	ldr r0, _08237FBC @ =0x03000790
	ldr r7, [r0]
	bl FUN_082379f8
	cmp r7, #0
	ble _08238008
	ldr r1, _08237FC0 @ =0x030007A0
	adds r0, r4, r1
	ldrb r5, [r0]
	adds r4, #1
	movs r0, #0x3f
	ands r4, r0
	cmp r5, #0x3f
	ble _08237FC4
	subs r0, #0x45
	mov r1, r8
	str r0, [r1]
	b _0823800A
	.align 2, 0
_08237FB4: .4byte 0x030046D4
_08237FB8: .4byte 0x0300078C
_08237FBC: .4byte 0x03000790
_08237FC0: .4byte 0x030007A0
_08237FC4:
	adds r0, r5, #1
	cmp r0, r7
	bgt _08238008
	cmp r5, #0
	beq _08237FE6
	adds r3, r1, #0
	movs r2, #0x3f
	adds r1, r5, #0
_08237FD4:
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r6]
	adds r6, #1
	adds r4, #1
	ands r4, r2
	subs r1, #1
	cmp r1, #0
	bne _08237FD4
_08237FE6:
	bl FUN_082379ec
	ldr r0, _08238000 @ =0x03000790
	ldr r1, [r0]
	subs r1, #1
	subs r1, r1, r5
	str r1, [r0]
	ldr r0, _08238004 @ =0x0300078C
	str r4, [r0]
	bl FUN_082379f8
	adds r0, r5, #0
	b _0823800A
	.align 2, 0
_08238000: .4byte 0x03000790
_08238004: .4byte 0x0300078C
_08238008:
	movs r0, #0
_0823800A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08238014
FUN_08238014: @ 0x08238014
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _0823807C @ =0x030046D4
	ldr r0, [r0]
	cmp r0, #0
	blt _0823808E
	bl FUN_082379ec
	ldr r0, _08238080 @ =0x03000794
	ldr r5, [r0]
	ldr r0, _08238084 @ =0x0300079C
	ldr r4, [r0]
	bl FUN_082379f8
	adds r4, #1
	adds r4, r4, r7
	cmp r4, #0x3f
	bgt _0823808C
	ldr r1, _08238088 @ =0x030007E0
	adds r0, r5, r1
	strb r7, [r0]
	adds r5, #1
	movs r0, #0x3f
	ands r5, r0
	cmp r7, #0
	ble _08238062
	adds r4, r1, #0
	movs r3, #0x3f
	adds r2, r7, #0
_08238050:
	adds r1, r5, r4
	ldrb r0, [r6]
	strb r0, [r1]
	adds r6, #1
	adds r5, #1
	ands r5, r3
	subs r2, #1
	cmp r2, #0
	bne _08238050
_08238062:
	bl FUN_082379ec
	ldr r0, _08238080 @ =0x03000794
	str r5, [r0]
	ldr r1, _08238084 @ =0x0300079C
	ldr r0, [r1]
	adds r0, #1
	adds r0, r0, r7
	str r0, [r1]
	bl FUN_082379f8
	adds r0, r7, #0
	b _0823808E
	.align 2, 0
_0823807C: .4byte 0x030046D4
_08238080: .4byte 0x03000794
_08238084: .4byte 0x0300079C
_08238088: .4byte 0x030007E0
_0823808C:
	movs r0, #0
_0823808E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08238094
FUN_08238094: @ 0x08238094
	push {lr}
	ldr r0, _082380A4 @ =0x030046D4
	ldr r0, [r0]
	cmp r0, #0
	blt _082380A0
	movs r0, #0
_082380A0:
	pop {r1}
	bx r1
	.align 2, 0
_082380A4: .4byte 0x030046D4

	thumb_func_start FUN_082380a8
FUN_082380a8: @ 0x082380A8
	push {lr}
	ldr r0, _082380C0 @ =0x030046D0
	ldr r1, _082380C4 @ =0x030046BC
	ldrh r2, [r0]
	ldrh r0, [r1]
	orrs r0, r2
	ldr r1, _082380C8 @ =0x0000FFFF
	cmp r0, r1
	bne _082380CC
	movs r0, #0
	b _082380CE
	.align 2, 0
_082380C0: .4byte 0x030046D0
_082380C4: .4byte 0x030046BC
_082380C8: .4byte 0x0000FFFF
_082380CC:
	movs r0, #1
_082380CE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082380d4
FUN_082380d4: @ 0x082380D4
	push {lr}
	ldr r0, _082380E4 @ =0x030046D0
	ldrh r1, [r0]
	ldr r0, _082380E8 @ =0x0000FFFF
	cmp r1, r0
	bne _082380EC
	movs r0, #0
	b _082380EE
	.align 2, 0
_082380E4: .4byte 0x030046D0
_082380E8: .4byte 0x0000FFFF
_082380EC:
	movs r0, #1
_082380EE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082380f4
FUN_082380f4: @ 0x082380F4
	push {lr}
	ldr r0, _08238104 @ =0x030046BC
	ldrh r1, [r0]
	ldr r0, _08238108 @ =0x0000FFFF
	cmp r1, r0
	bne _0823810C
	movs r0, #0
	b _0823810E
	.align 2, 0
_08238104: .4byte 0x030046BC
_08238108: .4byte 0x0000FFFF
_0823810C:
	movs r0, #1
_0823810E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08238114
FUN_08238114: @ 0x08238114
	ldr r0, _0823811C @ =0x030046C0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0823811C: .4byte 0x030046C0

	thumb_func_start FUN_08238120
FUN_08238120: @ 0x08238120
	ldr r0, _08238128 @ =0x030046C8
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08238128: .4byte 0x030046C8

	thumb_func_start FUN_0823812c
FUN_0823812c: @ 0x0823812C
	ldr r0, _08238134 @ =0x030046CC
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08238134: .4byte 0x030046CC

	thumb_func_start FUN_08238138
FUN_08238138: @ 0x08238138
	ldr r1, _08238140 @ =0x03000820
	ldr r0, _08238144 @ =0x0203F800
	str r0, [r1]
	bx lr
	.align 2, 0
_08238140: .4byte 0x03000820
_08238144: .4byte 0x0203F800

	thumb_func_start FUN_08238148
FUN_08238148: @ 0x08238148
	movs r1, #0
	str r1, [r0]
	str r1, [r0, #0x24]
	adds r1, r0, #0
	adds r1, #0x20
	str r1, [r0, #4]
	str r0, [r0, #0x20]
	bx lr

	thumb_func_start FUN_08238158
FUN_08238158: @ 0x08238158
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2]
	ldr r0, [r2, #4]
	cmp r1, #0
	beq _08238166
	str r0, [r1, #4]
_08238166:
	cmp r0, #0
	beq _0823816C
	str r1, [r0]
_0823816C:
	movs r0, #0
	str r0, [r2]
	str r0, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08238178
FUN_08238178: @ 0x08238178
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08238158
	adds r1, r5, #0
	adds r1, #0x20
	ldr r0, [r5, #0x20]
	str r0, [r4]
	str r1, [r4, #4]
	str r4, [r0, #4]
	str r4, [r5, #0x20]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08238198
FUN_08238198: @ 0x08238198
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_08238158
	ldr r0, [r4, #4]
	str r5, [r4, #4]
	str r5, [r0]
	str r4, [r5]
	str r0, [r5, #4]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_082381b4
FUN_082381b4: @ 0x082381B4
	push {lr}
	ldr r1, [r0, #4]
	ldr r0, [r1, #4]
	cmp r0, #0
	beq _082381C2
	adds r0, r1, #0
	b _082381C4
_082381C2:
	movs r0, #0
_082381C4:
	pop {r1}
	bx r1

	thumb_func_start FUN_082381c8
FUN_082381c8: @ 0x082381C8
	push {lr}
	ldr r2, [r0, #4]
	b _082381DA
_082381CE:
	ldrb r0, [r2, #8]
	cmp r0, r1
	bne _082381D8
	adds r0, r2, #0
	b _082381E2
_082381D8:
	ldr r2, [r2, #4]
_082381DA:
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _082381CE
	movs r0, #0
_082381E2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082381e8
FUN_082381e8: @ 0x082381E8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	adds r1, r3, #1
	movs r2, #0xff
	ands r1, r2
	str r1, [r0]
	adds r0, r3, #0
	bx lr

	thumb_func_start FUN_082381fc
FUN_082381fc: @ 0x082381FC
	push {lr}
	ldrb r3, [r0, #0xc]
	adds r2, r0, #0
	adds r2, #0xd
	ldrb r0, [r0, #9]
	cmp r0, #1
	ble _08238218
	subs r1, r0, #1
_0823820C:
	ldrb r0, [r2]
	eors r3, r0
	adds r2, #1
	subs r1, #1
	cmp r1, #0
	bne _0823820C
_08238218:
	cmp r3, #0
	bne _08238220
	movs r0, #0
	b _08238224
_08238220:
	movs r0, #1
	rsbs r0, r0, #0
_08238224:
	pop {r1}
	bx r1

	thumb_func_start FUN_08238228
FUN_08238228: @ 0x08238228
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #0
	adds r2, r3, #0
	adds r2, #0xd
	ldrb r0, [r3, #9]
	cmp r0, #1
	ble _08238246
	subs r1, r0, #1
_0823823A:
	ldrb r0, [r2]
	eors r4, r0
	adds r2, #1
	subs r1, #1
	cmp r1, #0
	bne _0823823A
_08238246:
	strb r4, [r3, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08238250
FUN_08238250: @ 0x08238250
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r6, r3, #0
	movs r1, #0
	strb r1, [r5, #0xc]
	movs r1, #1
	strb r1, [r5, #0xd]
	bl FUN_082381e8
	strb r0, [r5, #0xe]
	strb r6, [r5, #0xf]
	strb r0, [r5, #8]
	movs r0, #0xf0
	lsls r0, r0, #1
	strh r0, [r5, #0xa]
	adds r0, r6, #4
	strb r0, [r5, #9]
	adds r1, r5, #0
	adds r1, #0x10
	cmp r6, #0
	ble _0823828C
	adds r3, r6, #0
_0823827E:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r1, #1
	adds r4, #1
	subs r3, #1
	cmp r3, #0
	bne _0823827E
_0823828C:
	adds r0, r5, #0
	bl FUN_08238228
	ldrb r0, [r5, #9]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823829c
FUN_0823829c: @ 0x0823829C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r0, #0xc0
	bl FUN_082381b4
	adds r4, r0, #0
	cmp r4, #0
	beq _082382E0
	movs r1, #0
	strb r1, [r4, #0xc]
	movs r0, #2
	strb r0, [r4, #0xd]
	strb r6, [r4, #0xe]
	strb r1, [r4, #0xf]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	strb r0, [r4, #8]
	movs r0, #0xf0
	lsls r0, r0, #1
	strh r0, [r4, #0xa]
	movs r0, #4
	strb r0, [r4, #9]
	adds r0, r4, #0
	bl FUN_08238228
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08238178
	movs r0, #0
	b _082382E4
_082382E0:
	movs r0, #1
	rsbs r0, r0, #0
_082382E4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082382ec
FUN_082382ec: @ 0x082382EC
	movs r2, #0xc2
	lsls r2, r2, #2
	adds r0, r0, r2
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_082382f8
FUN_082382f8: @ 0x082382F8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5, #0xd]
	cmp r0, #1
	beq _0823830E
	cmp r0, #2
	beq _0823832A
	adds r0, r4, #0
	movs r1, #3
	b _08238348
_0823830E:
	adds r0, r4, #0
	adds r0, #0x80
	adds r1, r5, #0
	bl FUN_08238178
	ldrb r1, [r5, #8]
	adds r0, r4, #0
	bl FUN_0823829c
	cmp r0, #0
	bge _0823834C
	adds r0, r4, #0
	movs r1, #1
	b _08238348
_0823832A:
	adds r0, r4, #0
	adds r0, #0x40
	ldrb r1, [r5, #0xe]
	bl FUN_082381c8
	adds r1, r0, #0
	cmp r1, #0
	beq _08238344
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238178
	b _0823834C
_08238344:
	adds r0, r4, #0
	movs r1, #0
_08238348:
	bl FUN_082382ec
_0823834C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08238354
FUN_08238354: @ 0x08238354
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0xc0
	adds r6, r7, #0
	b _082383A6
_08238360:
	adds r0, r4, #0
	adds r0, #0xc
	bl FUN_08237f74
	adds r1, r0, #0
	strb r1, [r4, #9]
	ldrb r0, [r4, #0xe]
	strb r0, [r4, #8]
	cmp r1, #0
	beq _082383D4
	cmp r1, #0
	bge _08238382
	adds r0, r5, #0
	movs r1, #4
	bl FUN_082382ec
	b _082383D4
_08238382:
	adds r0, r4, #0
	bl FUN_082381fc
	cmp r0, #0
	bge _0823839E
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08238178
	adds r0, r5, #0
	movs r1, #5
	bl FUN_082382ec
	b _082383D4
_0823839E:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_082382f8
_082383A6:
	adds r0, r6, #0
	bl FUN_082381b4
	adds r4, r0, #0
	cmp r4, #0
	bne _08238360
	b _082383D4
_082383B4:
	ldrb r0, [r4, #0xd]
	cmp r0, #1
	beq _082383C0
	cmp r0, #2
	beq _082383CC
	b _082383D4
_082383C0:
	adds r0, r5, #0
	adds r0, #0x40
	adds r1, r4, #0
	bl FUN_08238178
	b _082383D4
_082383CC:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08238178
_082383D4:
	adds r0, r5, #0
	bl FUN_082381b4
	adds r4, r0, #0
	cmp r4, #0
	beq _082383FA
	adds r0, #0xc
	ldrb r1, [r4, #9]
	bl FUN_08238014
	adds r1, r0, #0
	cmp r1, #0
	beq _082383FA
	cmp r1, #0
	bge _082383B4
	adds r0, r5, #0
	movs r1, #6
	bl FUN_082382ec
_082383FA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08238400:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0x20, 0x08, 0x00, 0x03

	thumb_func_start FUN_0823840c
FUN_0823840c: @ 0x0823840C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xc3
	lsls r1, r1, #2
	bl FUN_082309cc
	adds r0, r4, #0
	bl FUN_08238148
	adds r0, r4, #0
	adds r0, #0x40
	bl FUN_08238148
	adds r0, r4, #0
	adds r0, #0x80
	bl FUN_08238148
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238148
	movs r6, #0
	movs r0, #0x82
	lsls r0, r0, #1
	mov r8, r0
	movs r7, #0
	adds r5, r4, r0
_08238446:
	lsls r0, r6, #5
	mov r2, r8
	adds r1, r4, r2
	adds r1, r1, r0
	str r7, [r1]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r4, r2
	adds r1, r1, r0
	str r7, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	adds r1, r5, #0
	bl FUN_08238178
	adds r5, #0x20
	adds r6, #1
	cmp r6, #0xf
	ble _08238446
	ldr r0, _0823847C @ =0x03000820
	str r4, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823847C: .4byte 0x03000820

	thumb_func_start FUN_08238480
FUN_08238480: @ 0x08238480
	push {r4, lr}
	bl FUN_08238138
	ldr r0, _08238498 @ =0x03000820
	ldr r4, [r0]
	adds r0, r4, #0
	bl FUN_0823840c
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08238498: .4byte 0x03000820

	thumb_func_start FUN_0823849c
FUN_0823849c: @ 0x0823849C
	push {lr}
	ldr r0, _082384AC @ =0x03000820
	ldr r0, [r0]
	bl FUN_08238354
	pop {r0}
	bx r0
	.align 2, 0
_082384AC: .4byte 0x03000820

	thumb_func_start FUN_082384b0
FUN_082384b0: @ 0x082384B0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _082384E4 @ =0x03000820
	ldr r5, [r0]
	cmp r5, #0
	beq _082384E8
	adds r0, r5, #0
	adds r0, #0xc0
	bl FUN_082381b4
	adds r4, r0, #0
	cmp r4, #0
	beq _082384E8
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_08238250
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08238178
	ldrb r0, [r4, #8]
	b _082384EC
	.align 2, 0
_082384E4: .4byte 0x03000820
_082384E8:
	movs r0, #1
	rsbs r0, r0, #0
_082384EC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082384f4
FUN_082384f4: @ 0x082384F4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08238508 @ =0x03000820
	ldr r4, [r0]
	cmp r4, #0
	bne _0823850C
	movs r0, #1
	rsbs r0, r0, #0
	b _08238530
	.align 2, 0
_08238508: .4byte 0x03000820
_0823850C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082381c8
	cmp r0, #0
	beq _0823851C
	movs r0, #1
	b _08238530
_0823851C:
	adds r0, r4, #0
	adds r0, #0x40
	adds r1, r5, #0
	bl FUN_082381c8
	cmp r0, #0
	bne _0823852E
	movs r0, #0
	b _08238530
_0823852E:
	movs r0, #2
_08238530:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08238538
FUN_08238538: @ 0x08238538
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0823854C @ =0x03000820
	ldr r4, [r0]
	cmp r4, #0
	bne _08238550
	movs r0, #1
	rsbs r0, r0, #0
	b _0823858A
	.align 2, 0
_0823854C: .4byte 0x03000820
_08238550:
	adds r0, r4, #0
	adds r0, #0x80
	bl FUN_082381b4
	adds r5, r0, #0
	cmp r5, #0
	bne _08238562
	movs r0, #0
	b _0823858A
_08238562:
	ldrb r6, [r5, #0xf]
	adds r1, r5, #0
	adds r1, #0x10
	adds r3, r7, #0
	adds r4, #0xc0
	cmp r6, #0
	beq _08238580
	adds r2, r6, #0
_08238572:
	ldrb r0, [r1]
	strb r0, [r3]
	adds r1, #1
	adds r3, #1
	subs r2, #1
	cmp r2, #0
	bne _08238572
_08238580:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08238178
	adds r0, r6, #0
_0823858A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08238590
FUN_08238590: @ 0x08238590
	push {lr}
	ldr r0, _082385AC @ =0x03000820
	ldr r0, [r0]
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _082385A4
	str r1, [r0]
_082385A4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_082385AC: .4byte 0x03000820

	thumb_func_start FUN_082385b0
FUN_082385b0: @ 0x082385B0
	push {r4, r5, r6, lr}
	ldr r0, _082385B8 @ =0x03000820
	ldr r4, [r0]
	b _082385C4
	.align 2, 0
_082385B8: .4byte 0x03000820
_082385BC:
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238178
_082385C4:
	adds r0, r4, #0
	bl FUN_082381b4
	adds r1, r0, #0
	cmp r1, #0
	bne _082385BC
	adds r5, r4, #0
	adds r5, #0x40
	adds r6, r4, #0
	adds r6, #0x80
	b _082385E2
_082385DA:
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238178
_082385E2:
	adds r0, r5, #0
	bl FUN_082381b4
	adds r1, r0, #0
	cmp r1, #0
	bne _082385DA
	b _082385F8
_082385F0:
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238178
_082385F8:
	adds r0, r6, #0
	bl FUN_082381b4
	adds r1, r0, #0
	cmp r1, #0
	bne _082385F0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823860c
FUN_0823860c: @ 0x0823860C
	ldr r1, _08238614 @ =0x04000208
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_08238614: .4byte 0x04000208

	thumb_func_start FUN_08238618
FUN_08238618: @ 0x08238618
	ldr r1, _08238620 @ =0x04000208
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_08238620: .4byte 0x04000208

	thumb_func_start FUN_08238624
FUN_08238624: @ 0x08238624
	ldr r0, _08238630 @ =0x04000128
	ldrh r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08238630: .4byte 0x04000128

	thumb_func_start FUN_08238634
FUN_08238634: @ 0x08238634
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08238680 @ =0x04000208
	movs r0, #0
	mov r8, r0
	strh r0, [r4]
	ldr r3, _08238684 @ =0x04000200
	ldrh r1, [r3]
	ldr r0, _08238688 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r3]
	ldr r1, _0823868C @ =0x03002CB0
	ldr r0, _08238690 @ =FUN_082386e4
	str r0, [r1, #4]
	movs r6, #1
	strh r6, [r4]
	ldr r0, _08238694 @ =0x04000202
	movs r5, #0x80
	strh r5, [r0]
	ldr r2, _08238698 @ =0x04000128
	ldrh r0, [r2]
	movs r7, #0x80
	lsls r7, r7, #7
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	mov r0, r8
	strh r0, [r4]
	ldrh r0, [r3]
	orrs r0, r5
	strh r0, [r3]
	strh r6, [r4]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08238680: .4byte 0x04000208
_08238684: .4byte 0x04000200
_08238688: .4byte 0x0000FF7F
_0823868C: .4byte 0x03002CB0
_08238690: .4byte FUN_082386e4
_08238694: .4byte 0x04000202
_08238698: .4byte 0x04000128

	thumb_func_start FUN_0823869c
FUN_0823869c: @ 0x0823869C
	ldr r3, _082386C8 @ =0x04000208
	movs r0, #0
	strh r0, [r3]
	ldr r2, _082386CC @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _082386D0 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldr r1, _082386D4 @ =0x03002CB0
	ldr r0, _082386D8 @ =FUN_0822a18c
	str r0, [r1, #4]
	movs r0, #1
	strh r0, [r3]
	ldr r1, _082386DC @ =0x04000128
	ldr r2, _082386E0 @ =0x00002003
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0xda
	movs r0, #0x80
	strh r0, [r1]
	bx lr
	.align 2, 0
_082386C8: .4byte 0x04000208
_082386CC: .4byte 0x04000200
_082386D0: .4byte 0x0000FF7F
_082386D4: .4byte 0x03002CB0
_082386D8: .4byte FUN_0822a18c
_082386DC: .4byte 0x04000128
_082386E0: .4byte 0x00002003

	thumb_func_start FUN_082386e4
FUN_082386e4: @ 0x082386E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _08238718 @ =0x04000120
	ldrh r0, [r4]
	ldr r2, _0823871C @ =0x030046D4
	movs r0, #0
	str r0, [r2]
	ldr r0, _08238720 @ =0x04000128
	ldrh r0, [r0]
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08238710
	movs r0, #0xb0
	ands r1, r0
	cmp r1, #0x80
	bne _08238724
_08238710:
	movs r0, #2
	rsbs r0, r0, #0
	str r0, [r2]
	b _08238996
	.align 2, 0
_08238718: .4byte 0x04000120
_0823871C: .4byte 0x030046D4
_08238720: .4byte 0x04000128
_08238724:
	movs r3, #0
	ldr r0, _082387E0 @ =0x03000828
	mov sb, r0
	ldr r0, [r0]
	movs r1, #1
	mov ip, r1
	subs r0, r1, r0
	lsls r0, r0, #3
	ldr r1, _082387E4 @ =0x03004720
	adds r6, r0, r1
	ldr r2, _082387E8 @ =0x03000830
	ldr r0, [r2]
	mov r1, ip
	subs r0, r1, r0
	lsls r0, r0, #3
	ldr r1, _082387EC @ =0x030046F0
	adds r7, r0, r1
	ldrh r0, [r4]
	adds r1, r0, #0
	mov r8, r1
	strh r1, [r7]
	movs r4, #0x80
	lsls r4, r4, #8
	ands r0, r4
	mov sl, sb
	cmp r0, #0
	bne _0823875C
	adds r3, r1, #0
_0823875C:
	ldr r0, _082387F0 @ =0x04000122
	ldrh r0, [r0]
	adds r1, r0, #0
	strh r1, [r7, #2]
	ands r0, r4
	cmp r0, #0
	bne _0823876C
	orrs r3, r1
_0823876C:
	ldr r0, _082387F4 @ =0x04000124
	ldrh r0, [r0]
	adds r1, r0, #0
	strh r1, [r7, #4]
	ands r0, r4
	cmp r0, #0
	bne _0823877C
	orrs r3, r1
_0823877C:
	ldr r0, _082387F8 @ =0x04000126
	ldrh r0, [r0]
	adds r1, r0, #0
	strh r1, [r7, #6]
	ands r0, r4
	cmp r0, #0
	bne _0823878C
	orrs r3, r1
_0823878C:
	movs r5, #0x80
	lsls r5, r5, #7
	ands r3, r5
	cmp r3, #0
	beq _08238798
	b _082388D4
_08238798:
	ldr r0, _082387FC @ =0x0300082C
	ldr r1, [r0]
	mov sb, r0
	cmp r1, #0
	beq _08238810
	ldr r0, _08238800 @ =0x03004730
	ldrh r1, [r0]
	ldr r4, _08238804 @ =0x030046E0
	ldrh r0, [r4]
	adds r1, r1, r0
	movs r0, #3
	ands r1, r0
	ldr r2, _08238808 @ =0x03004700
	lsls r3, r1, #3
	adds r0, r3, r2
	mov r6, r8
	strh r6, [r0]
	adds r0, r2, #2
	adds r0, r3, r0
	ldrh r1, [r7, #2]
	strh r1, [r0]
	adds r0, r2, #4
	adds r0, r3, r0
	ldrh r1, [r7, #4]
	strh r1, [r0]
	adds r2, #6
	adds r3, r3, r2
	ldrh r0, [r7, #6]
	strh r0, [r3]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r0, _0823880C @ =0x03000826
	strh r5, [r0]
	adds r2, r0, #0
	b _08238978
	.align 2, 0
_082387E0: .4byte 0x03000828
_082387E4: .4byte 0x03004720
_082387E8: .4byte 0x03000830
_082387EC: .4byte 0x030046F0
_082387F0: .4byte 0x04000122
_082387F4: .4byte 0x04000124
_082387F8: .4byte 0x04000126
_082387FC: .4byte 0x0300082C
_08238800: .4byte 0x03004730
_08238804: .4byte 0x030046E0
_08238808: .4byte 0x03004700
_0823880C: .4byte 0x03000826
_08238810:
	ldr r0, _08238890 @ =0x030046E0
	mov ip, r0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0823889C
	ldr r2, _08238894 @ =0x03004700
	ldr r1, _08238898 @ =0x03004730
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r6]
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r5, r2, #2
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r6, #2]
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r4, r2, #4
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r6, #4]
	ldrh r0, [r1]
	lsls r0, r0, #3
	adds r3, r2, #6
	mov r8, r3
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r6, #6]
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #3
	ands r0, r3
	strh r0, [r1]
	mov r6, ip
	ldrh r0, [r6]
	mov r6, sp
	strh r0, [r6]
	subs r0, #1
	mov r6, ip
	strh r0, [r6]
	ldrh r1, [r1]
	ldrh r0, [r6]
	adds r1, r1, r0
	ands r1, r3
	lsls r1, r1, #3
	adds r2, r1, r2
	ldrh r0, [r7]
	strh r0, [r2]
	adds r5, r1, r5
	ldrh r0, [r7, #2]
	strh r0, [r5]
	adds r4, r1, r4
	ldrh r0, [r7, #4]
	strh r0, [r4]
	add r1, r8
	ldrh r0, [r7, #6]
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6]
	b _082388AC
	.align 2, 0
_08238890: .4byte 0x030046E0
_08238894: .4byte 0x03004700
_08238898: .4byte 0x03004730
_0823889C:
	mov r1, r8
	strh r1, [r6]
	ldrh r0, [r7, #2]
	strh r0, [r6, #2]
	ldrh r0, [r7, #4]
	strh r0, [r6, #4]
	ldrh r0, [r7, #6]
	strh r0, [r6, #6]
_082388AC:
	ldr r2, _082388CC @ =0x03000826
	ldr r1, _082388D0 @ =0x03000824
	ldrh r0, [r1]
	strh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	strh r0, [r1]
	mov r6, sl
	ldr r0, [r6]
	movs r1, #1
	subs r0, r1, r0
	str r0, [r6]
	mov r0, sb
	str r1, [r0]
	b _08238978
	.align 2, 0
_082388CC: .4byte 0x03000826
_082388D0: .4byte 0x03000824
_082388D4:
	ldr r7, _08238948 @ =0x0300082C
	ldr r0, [r7]
	cmp r0, #0
	bne _08238960
	ldr r4, _0823894C @ =0x030046E0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08238960
	ldr r2, _08238950 @ =0x03004700
	ldr r3, _08238954 @ =0x03004730
	ldrh r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r6]
	ldrh r0, [r3]
	lsls r0, r0, #3
	adds r1, r2, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r6, #2]
	ldrh r0, [r3]
	lsls r0, r0, #3
	adds r1, r2, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r6, #4]
	ldrh r0, [r3]
	lsls r0, r0, #3
	adds r2, #6
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r6, #6]
	ldrh r0, [r3]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strh r0, [r3]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	ldr r2, _08238958 @ =0x03000826
	ldrh r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0823893A
	ldr r1, _0823895C @ =0x03000824
	ldrh r0, [r1]
	strh r0, [r2]
	strh r5, [r1]
_0823893A:
	mov r1, sb
	ldr r0, [r1]
	mov r3, ip
	subs r0, r3, r0
	str r0, [r1]
	str r3, [r7]
	b _08238978
	.align 2, 0
_08238948: .4byte 0x0300082C
_0823894C: .4byte 0x030046E0
_08238950: .4byte 0x03004700
_08238954: .4byte 0x03004730
_08238958: .4byte 0x03000826
_0823895C: .4byte 0x03000824
_08238960:
	ldr r2, _082389AC @ =0x03000826
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08238978
	ldr r1, _082389B0 @ =0x03000824
	ldrh r0, [r1]
	strh r0, [r2]
	strh r3, [r1]
_08238978:
	ldr r1, _082389B4 @ =0x0400012A
	ldrh r0, [r2]
	strh r0, [r1]
	ldr r2, _082389B8 @ =0x030046CC
	ldr r0, _082389BC @ =0x04000128
	ldrh r0, [r0]
	lsrs r0, r0, #4
	movs r1, #3
	ands r0, r1
	str r0, [r2]
	ldr r6, _082389C0 @ =0x03000830
	ldr r1, [r6]
	movs r0, #1
	subs r0, r0, r1
	str r0, [r6]
_08238996:
	ldr r1, _082389C4 @ =0x03007FF8
	movs r0, #0x80
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082389AC: .4byte 0x03000826
_082389B0: .4byte 0x03000824
_082389B4: .4byte 0x0400012A
_082389B8: .4byte 0x030046CC
_082389BC: .4byte 0x04000128
_082389C0: .4byte 0x03000830
_082389C4: .4byte 0x03007FF8

	thumb_func_start FUN_082389c8
FUN_082389c8: @ 0x082389C8
	push {r4, lr}
	ldr r0, _08238A10 @ =0x030046D4
	movs r4, #0
	str r4, [r0]
	ldr r1, _08238A14 @ =0x030046CC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	ldr r3, _08238A18 @ =0x04000208
	strh r4, [r3]
	ldr r2, _08238A1C @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08238A20 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r1, _08238A24 @ =0x04000202
	movs r0, #0x80
	strh r0, [r1]
	bl FUN_08229f34
	ldr r0, _08238A28 @ =0x04000134
	strh r4, [r0]
	ldr r2, _08238A2C @ =0x04000128
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08238A10: .4byte 0x030046D4
_08238A14: .4byte 0x030046CC
_08238A18: .4byte 0x04000208
_08238A1C: .4byte 0x04000200
_08238A20: .4byte 0x0000FF7F
_08238A24: .4byte 0x04000202
_08238A28: .4byte 0x04000134
_08238A2C: .4byte 0x04000128

	thumb_func_start FUN_08238a30
FUN_08238a30: @ 0x08238A30
	push {r4, r5, r6, lr}
	ldr r0, _08238A8C @ =0x030046D4
	movs r6, #0
	str r6, [r0]
	ldr r1, _08238A90 @ =0x030046CC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	ldr r3, _08238A94 @ =0x04000208
	strh r6, [r3]
	ldr r2, _08238A98 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08238A9C @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r1, _08238AA0 @ =0x04000202
	movs r0, #0x80
	strh r0, [r1]
	ldr r5, _08238AA4 @ =0x04000134
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r5]
	ldr r4, _08238AA8 @ =0x04000128
	strh r6, [r4]
	bl FUN_08229f34
	bl FUN_08229f34
	strh r6, [r5]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, #3
	orrs r0, r1
	strh r0, [r4]
	bl FUN_08229f34
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08238A8C: .4byte 0x030046D4
_08238A90: .4byte 0x030046CC
_08238A94: .4byte 0x04000208
_08238A98: .4byte 0x04000200
_08238A9C: .4byte 0x0000FF7F
_08238AA0: .4byte 0x04000202
_08238AA4: .4byte 0x04000134
_08238AA8: .4byte 0x04000128

	thumb_func_start FUN_08238aac
FUN_08238aac: @ 0x08238AAC
	push {r4, r5, lr}
	ldr r4, _08238AD0 @ =0x030046CC
	movs r3, #1
	rsbs r3, r3, #0
	str r3, [r4]
	ldr r5, _08238AD4 @ =0x030046D4
	movs r0, #0
	str r0, [r5]
	ldr r0, _08238AD8 @ =0x04000128
	ldrh r0, [r0]
	adds r2, r0, #0
	movs r1, #0x88
	ands r0, r1
	cmp r0, #8
	beq _08238ADC
	str r3, [r5]
	b _08238AF8
	.align 2, 0
_08238AD0: .4byte 0x030046CC
_08238AD4: .4byte 0x030046D4
_08238AD8: .4byte 0x04000128
_08238ADC:
	movs r0, #4
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08238AEC
	str r0, [r4]
	b _08238AEE
_08238AEC:
	str r3, [r4]
_08238AEE:
	ldr r1, _08238B00 @ =0x0400012A
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
_08238AF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08238B00: .4byte 0x0400012A

	thumb_func_start FUN_08238b04
FUN_08238b04: @ 0x08238B04
	push {r4, r5, lr}
	ldr r1, _08238B90 @ =0x030046C4
	movs r0, #1
	str r0, [r1]
	bl FUN_082389c8
	ldr r0, _08238B94 @ =0x0300082C
	movs r2, #0
	str r2, [r0]
	ldr r0, _08238B98 @ =0x03000826
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	strh r1, [r0]
	ldr r0, _08238B9C @ =0x03000824
	strh r1, [r0]
	ldr r1, _08238BA0 @ =0x03004720
	ldr r0, _08238BA4 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	ldr r0, _08238BA8 @ =0x03000828
	str r2, [r0]
	ldr r1, _08238BAC @ =0x030046F0
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	ldr r0, _08238BB0 @ =0x03000830
	str r2, [r0]
	ldr r0, _08238BB4 @ =0x030046E0
	strh r2, [r0]
	ldr r0, _08238BB8 @ =0x03004730
	strh r2, [r0]
	movs r1, #0
	ldr r5, _08238BBC @ =0x03004700
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
_08238B6C:
	lsls r0, r1, #3
	adds r3, r1, #1
	adds r1, r0, r5
	movs r2, #3
_08238B74:
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08238B74
	adds r1, r3, #0
	cmp r1, #3
	ble _08238B6C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08238B90: .4byte 0x030046C4
_08238B94: .4byte 0x0300082C
_08238B98: .4byte 0x03000826
_08238B9C: .4byte 0x03000824
_08238BA0: .4byte 0x03004720
_08238BA4: .4byte 0x0000FFFF
_08238BA8: .4byte 0x03000828
_08238BAC: .4byte 0x030046F0
_08238BB0: .4byte 0x03000830
_08238BB4: .4byte 0x030046E0
_08238BB8: .4byte 0x03004730
_08238BBC: .4byte 0x03004700

	thumb_func_start FUN_08238bc0
FUN_08238bc0: @ 0x08238BC0
	push {lr}
	bl FUN_08238aac
	ldr r0, _08238BE0 @ =0x030046D4
	ldr r0, [r0]
	cmp r0, #0
	blt _08238BEE
	ldr r0, _08238BE4 @ =0x030046CC
	ldr r0, [r0]
	cmp r0, #0
	beq _08238BE8
	bl FUN_08238634
	movs r0, #1
	b _08238BEE
	.align 2, 0
_08238BE0: .4byte 0x030046D4
_08238BE4: .4byte 0x030046CC
_08238BE8:
	bl FUN_08238634
	movs r0, #0
_08238BEE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08238bf4
FUN_08238bf4: @ 0x08238BF4
	push {lr}
	ldr r0, _08238C04 @ =0x030046CC
	ldr r0, [r0]
	cmp r0, #0
	bne _08238C08
	bl FUN_0823869c
	b _08238C0C
	.align 2, 0
_08238C04: .4byte 0x030046CC
_08238C08:
	bl FUN_0823869c
_08238C0C:
	ldr r1, _08238C20 @ =0x030046C4
	ldr r0, [r1]
	cmp r0, #1
	bne _08238C18
	movs r0, #0
	str r0, [r1]
_08238C18:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08238C20: .4byte 0x030046C4

	thumb_func_start FUN_08238c24
FUN_08238c24: @ 0x08238C24
	push {r4, r5, lr}
	bl FUN_082389c8
	ldr r0, _08238CA8 @ =0x0300082C
	movs r2, #0
	str r2, [r0]
	ldr r0, _08238CAC @ =0x03000826
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	strh r1, [r0]
	ldr r0, _08238CB0 @ =0x03000824
	strh r1, [r0]
	ldr r1, _08238CB4 @ =0x03004720
	ldr r0, _08238CB8 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	ldr r0, _08238CBC @ =0x03000828
	str r2, [r0]
	ldr r1, _08238CC0 @ =0x030046F0
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	ldr r0, _08238CC4 @ =0x03000830
	str r2, [r0]
	ldr r0, _08238CC8 @ =0x030046E0
	strh r2, [r0]
	ldr r0, _08238CCC @ =0x03004730
	strh r2, [r0]
	movs r1, #0
	ldr r5, _08238CD0 @ =0x03004700
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
_08238C86:
	lsls r0, r1, #3
	adds r3, r1, #1
	adds r1, r0, r5
	movs r2, #3
_08238C8E:
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08238C8E
	adds r1, r3, #0
	cmp r1, #3
	ble _08238C86
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08238CA8: .4byte 0x0300082C
_08238CAC: .4byte 0x03000826
_08238CB0: .4byte 0x03000824
_08238CB4: .4byte 0x03004720
_08238CB8: .4byte 0x0000FFFF
_08238CBC: .4byte 0x03000828
_08238CC0: .4byte 0x030046F0
_08238CC4: .4byte 0x03000830
_08238CC8: .4byte 0x030046E0
_08238CCC: .4byte 0x03004730
_08238CD0: .4byte 0x03004700

	thumb_func_start FUN_08238cd4
FUN_08238cd4: @ 0x08238CD4
	push {r4, r5, lr}
	bl FUN_08238a30
	ldr r0, _08238D58 @ =0x0300082C
	movs r2, #0
	str r2, [r0]
	ldr r0, _08238D5C @ =0x03000826
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	strh r1, [r0]
	ldr r0, _08238D60 @ =0x03000824
	strh r1, [r0]
	ldr r1, _08238D64 @ =0x03004720
	ldr r0, _08238D68 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	ldr r0, _08238D6C @ =0x03000828
	str r2, [r0]
	ldr r1, _08238D70 @ =0x030046F0
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	ldr r0, _08238D74 @ =0x03000830
	str r2, [r0]
	ldr r0, _08238D78 @ =0x030046E0
	strh r2, [r0]
	ldr r0, _08238D7C @ =0x03004730
	strh r2, [r0]
	movs r1, #0
	ldr r5, _08238D80 @ =0x03004700
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
_08238D36:
	lsls r0, r1, #3
	adds r3, r1, #1
	adds r1, r0, r5
	movs r2, #3
_08238D3E:
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08238D3E
	adds r1, r3, #0
	cmp r1, #3
	ble _08238D36
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08238D58: .4byte 0x0300082C
_08238D5C: .4byte 0x03000826
_08238D60: .4byte 0x03000824
_08238D64: .4byte 0x03004720
_08238D68: .4byte 0x0000FFFF
_08238D6C: .4byte 0x03000828
_08238D70: .4byte 0x030046F0
_08238D74: .4byte 0x03000830
_08238D78: .4byte 0x030046E0
_08238D7C: .4byte 0x03004730
_08238D80: .4byte 0x03004700

	thumb_func_start FUN_08238d84
FUN_08238d84: @ 0x08238D84
	push {lr}
	ldr r0, _08238DA4 @ =0x030046D4
	ldr r1, [r0]
	cmp r1, #0
	bge _08238D96
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	bgt _08238D9E
_08238D96:
	cmp r1, #0
	bne _08238D9E
	bl FUN_08238624
_08238D9E:
	pop {r0}
	bx r0
	.align 2, 0
_08238DA4: .4byte 0x030046D4

	thumb_func_start FUN_08238da8
FUN_08238da8: @ 0x08238DA8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08238DF0 @ =0x030046D4
	ldr r0, [r0]
	cmp r0, #0
	blt _08238E0E
	bl FUN_0823860c
	ldr r3, _08238DF4 @ =0x0300082C
	ldr r0, [r3]
	cmp r0, #0
	beq _08238E04
	ldr r2, _08238DF8 @ =0x03004720
	ldr r0, _08238DFC @ =0x03000828
	ldr r1, [r0]
	lsls r1, r1, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r2, #2
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r4, #2]
	adds r0, r2, #4
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r4, #4]
	adds r2, #6
	adds r1, r1, r2
	ldrh r0, [r1]
	strh r0, [r4, #6]
	movs r0, #0
	str r0, [r3]
	ldr r0, _08238E00 @ =0x030046CC
	ldr r4, [r0]
	b _08238E08
	.align 2, 0
_08238DF0: .4byte 0x030046D4
_08238DF4: .4byte 0x0300082C
_08238DF8: .4byte 0x03004720
_08238DFC: .4byte 0x03000828
_08238E00: .4byte 0x030046CC
_08238E04:
	movs r4, #3
	rsbs r4, r4, #0
_08238E08:
	bl FUN_08238618
	adds r0, r4, #0
_08238E0E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08238e14
FUN_08238e14: @ 0x08238E14
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl FUN_0823860c
	ldr r2, _08238E34 @ =0x03000824
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	beq _08238E38
	strh r4, [r2]
	movs r4, #0
	b _08238E3C
	.align 2, 0
_08238E34: .4byte 0x03000824
_08238E38:
	movs r4, #4
	rsbs r4, r4, #0
_08238E3C:
	bl FUN_08238618
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08238e48
FUN_08238e48: @ 0x08238E48
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08238E6C @ =0x030046D4
	ldr r1, [r0]
	cmp r1, #0
	bge _08238E74
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	ble _08238E74
	ldr r2, _08238E70 @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r4]
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	strh r0, [r4, #6]
	adds r0, r1, #0
	b _08238EA6
	.align 2, 0
_08238E6C: .4byte 0x030046D4
_08238E70: .4byte 0x0000FFFF
_08238E74:
	bl FUN_0823860c
	ldr r2, _08238EAC @ =0x030046F0
	ldr r0, _08238EB0 @ =0x03000830
	ldr r1, [r0]
	lsls r1, r1, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r2, #2
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r4, #2]
	adds r0, r2, #4
	adds r0, r1, r0
	ldrh r0, [r0]
	strh r0, [r4, #4]
	adds r2, #6
	adds r1, r1, r2
	ldrh r0, [r1]
	strh r0, [r4, #6]
	bl FUN_08238618
	ldr r0, _08238EB4 @ =0x030046CC
	ldr r0, [r0]
_08238EA6:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08238EAC: .4byte 0x030046F0
_08238EB0: .4byte 0x03000830
_08238EB4: .4byte 0x030046CC

	thumb_func_start sub_08238EB8
sub_08238EB8: @ 0x08238EB8
	push {r4, lr}
	bl FUN_082491b8
	adds r4, r0, #0
	ldr r0, _08238EFC @ =0x00008001
	cmp r4, r0
	bne _08238ECC
	ldr r1, _08238F00 @ =0x03004740
	movs r0, #1
	strb r0, [r1, #8]
_08238ECC:
	ldr r0, _08238F00 @ =0x03004740
	ldrb r2, [r0, #4]
	adds r1, r0, #0
	cmp r2, #0x17
	beq _08238EE0
	cmp r2, #1
	beq _08238EE0
	movs r0, #0
	strb r0, [r1, #5]
	strb r0, [r1, #4]
_08238EE0:
	movs r0, #0
	strb r0, [r1, #7]
	strb r0, [r1, #0xd]
	strb r0, [r1, #1]
	strb r0, [r1]
	movs r0, #0xff
	strb r0, [r1, #6]
	bl FUN_0823a608
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08238EFC: .4byte 0x00008001
_08238F00: .4byte 0x03004740

	thumb_func_start FUN_08238f04
FUN_08238f04: @ 0x08238F04
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _08238F24 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	bne _08238F2C
	ldr r0, _08238F28 @ =0x03004740
	ldrb r0, [r0, #2]
	movs r2, #0
	cmp r0, #1
	bne _08238F34
	movs r2, #1
	b _08238F34
	.align 2, 0
_08238F24: .4byte 0x03005800
_08238F28: .4byte 0x03004740
_08238F2C:
	ldr r0, _08238F40 @ =0x03004740
	ldrb r1, [r0, #3]
	movs r1, #0
	strb r1, [r0, #3]
_08238F34:
	adds r0, r2, #0
	bl FUN_0824ab54
	pop {r0}
	bx r0
	.align 2, 0
_08238F40: .4byte 0x03004740

	thumb_func_start FUN_08238f44
FUN_08238f44: @ 0x08238F44
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	cmp r5, #0
	beq _08238F8C
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r4, _08238F7C @ =0x03004740
	ldr r2, _08238F80 @ =0x01000024
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0xff
	strb r0, [r4, #6]
	str r5, [r4, #0x40]
	str r6, [r4, #0x44]
	ldr r0, _08238F84 @ =FUN_08239ea8
	bl FUN_08248f04
	ldr r0, _08238F88 @ =FUN_082397ac
	bl FUN_08248f10
	movs r0, #0
	b _08238F8E
	.align 2, 0
_08238F7C: .4byte 0x03004740
_08238F80: .4byte 0x01000024
_08238F84: .4byte FUN_08239ea8
_08238F88: .4byte FUN_082397ac
_08238F8C:
	movs r0, #4
_08238F8E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08238f98
FUN_08238f98: @ 0x08238F98
	push {r4, lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r4, _08238FBC @ =0x03004740
	ldr r2, _08238FC0 @ =0x01000020
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0xff
	strb r0, [r4, #6]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08238FBC: .4byte 0x03004740
_08238FC0: .4byte 0x01000020

	thumb_func_start FUN_08238fc4
FUN_08238fc4: @ 0x08238FC4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08238ff8
	ldr r1, _08238FF4 @ =0x03004740
	movs r2, #1
	strb r2, [r1, #4]
	movs r0, #2
	strb r0, [r1, #5]
	str r4, [r1, #0x3c]
	ldrb r0, [r4, #0x11]
	strb r0, [r1, #9]
	ldrh r0, [r4, #0x12]
	strh r0, [r1, #0x32]
	ldrh r0, [r4, #0x14]
	strh r0, [r1, #0x18]
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _08238FEC
	strb r2, [r1, #0xb]
_08238FEC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08238FF4: .4byte 0x03004740

	thumb_func_start FUN_08238ff8
FUN_08238ff8: @ 0x08238FF8
	push {r4, r5, lr}
	ldr r2, _0823903C @ =0x03004740
	movs r0, #0
	strb r0, [r2, #5]
	strb r0, [r2, #4]
	movs r1, #0xff
	strb r1, [r2, #6]
	strb r0, [r2, #7]
	strb r0, [r2, #0x10]
	strb r0, [r2, #0xc]
	adds r1, r2, #0
	adds r1, #0x24
	strb r0, [r1]
	adds r1, #0xc
	strb r0, [r1]
	movs r3, #0
	adds r5, r2, #0
	adds r5, #0x28
	movs r4, #0
	adds r2, #0x34
_08239020:
	lsls r1, r3, #1
	adds r0, r1, r5
	strh r4, [r0]
	adds r1, r1, r2
	strh r4, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls _08239020
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823903C: .4byte 0x03004740

	thumb_func_start FUN_08239040
FUN_08239040: @ 0x08239040
	ldr r1, _08239048 @ =0x03004740
	movs r0, #0x15
	strb r0, [r1, #4]
	bx lr
	.align 2, 0
_08239048: .4byte 0x03004740

	thumb_func_start FUN_0823904c
FUN_0823904c: @ 0x0823904C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r3, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	ldr r1, _08239084 @ =0x03004740
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _08239088
	cmp r0, #8
	bne _08239072
	cmp r5, #1
	beq _08239088
_08239072:
	movs r0, #1
	strh r0, [r1, #0x14]
	movs r0, #0xf3
	movs r1, #1
	bl FUN_0823a304
	movs r0, #1
	b _0823911A
	.align 2, 0
_08239084: .4byte 0x03004740
_08239088:
	bl FUN_0824a290
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _082390A8
	ldr r1, _082390A4 @ =0x03004740
	movs r0, #2
	strh r0, [r1, #0x14]
	movs r0, #0xf3
	movs r1, #1
	bl FUN_0823a304
	movs r0, #2
	b _0823911A
	.align 2, 0
_082390A4: .4byte 0x03004740
_082390A8:
	movs r2, #0
	ldrh r0, [r6]
	ldr r4, _082390DC @ =0x0000FFFF
	adds r1, r6, #2
	ldr r3, _082390E0 @ =0x03004740
	cmp r0, r4
	beq _082390C8
_082390B6:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xf
	bhi _082390C8
	ldrh r0, [r1]
	adds r1, #2
	cmp r0, r4
	bne _082390B6
_082390C8:
	cmp r2, #0x10
	bne _082390E4
	movs r0, #4
	strh r0, [r3, #0x14]
	movs r0, #0xf3
	movs r1, #1
	bl FUN_0823a304
	movs r0, #4
	b _0823911A
	.align 2, 0
_082390DC: .4byte 0x0000FFFF
_082390E0: .4byte 0x03004740
_082390E4:
	cmp r5, #1
	bls _082390F2
	movs r0, #1
	strb r0, [r3, #7]
	movs r5, #1
	movs r7, #0
	b _082390F6
_082390F2:
	movs r0, #0
	strb r0, [r3, #7]
_082390F6:
	cmp r5, #0
	beq _08239100
	movs r0, #5
	strb r0, [r3, #4]
	b _0823910E
_08239100:
	movs r0, #9
	strb r0, [r3, #4]
	ldrb r0, [r3, #0xb]
	cmp r0, #0
	beq _0823910E
	movs r0, #2
	strb r0, [r3, #0xb]
_0823910E:
	strb r5, [r3, #6]
	strh r7, [r3, #0x1a]
	mov r0, r8
	strh r0, [r3, #0x26]
	str r6, [r3, #0x20]
	movs r0, #0
_0823911A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08239124
FUN_08239124: @ 0x08239124
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	ldr r1, _08239158 @ =0x03004740
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _0823915C
	subs r0, #9
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0823915C
	movs r0, #1
	strh r0, [r1, #0x14]
	movs r0, #0xf3
	movs r1, #1
	bl FUN_0823a304
	movs r0, #1
	b _082391FC
	.align 2, 0
_08239158: .4byte 0x03004740
_0823915C:
	bl FUN_0824a290
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0823917C
	ldr r1, _08239178 @ =0x03004740
	movs r0, #2
	strh r0, [r1, #0x14]
	movs r0, #0xf3
	movs r1, #1
	bl FUN_0823a304
	movs r0, #2
	b _082391FC
	.align 2, 0
_08239178: .4byte 0x03004740
_0823917C:
	movs r2, #0
	ldr r0, _082391C8 @ =0x03005800
	ldr r1, [r0]
	ldrb r3, [r1, #8]
	ldr r5, _082391CC @ =0x03004740
	adds r7, r0, #0
	cmp r2, r3
	bhs _082391AA
	ldrh r0, [r1, #0x14]
	cmp r0, r6
	beq _082391AA
	adds r4, r1, #0
	adds r1, r3, #0
_08239196:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r1
	bhs _082391AA
	lsls r0, r2, #5
	adds r0, r4, r0
	ldrh r0, [r0, #0x14]
	cmp r0, r6
	bne _08239196
_082391AA:
	ldr r0, [r7]
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq _082391B6
	cmp r2, r0
	bne _082391D0
_082391B6:
	movs r0, #3
	strh r0, [r5, #0x14]
	movs r0, #0xf3
	movs r1, #1
	bl FUN_0823a304
	movs r0, #3
	b _082391FC
	.align 2, 0
_082391C8: .4byte 0x03005800
_082391CC: .4byte 0x03004740
_082391D0:
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _082391DA
	cmp r0, #9
	bne _082391E2
_082391DA:
	movs r0, #0xc
	strb r0, [r5, #4]
	movs r0, #0xd
	b _082391E8
_082391E2:
	movs r0, #0xb
	strb r0, [r5, #4]
	movs r0, #0xc
_082391E8:
	strb r0, [r5, #5]
	strh r6, [r5, #0x1e]
	mov r0, r8
	strh r0, [r5, #0x1a]
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _082391FA
	movs r0, #7
	strb r0, [r5, #7]
_082391FA:
	movs r0, #0
_082391FC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08239208:
	.byte 0xF0, 0xB5, 0x00, 0x06, 0x01, 0x0E, 0x17, 0x4E
	.byte 0x33, 0x1C, 0x30, 0x33, 0x1A, 0x78, 0x08, 0x1C, 0x10, 0x40, 0x00, 0x28, 0x22, 0xD0, 0x10, 0x1C
	.byte 0x88, 0x43, 0x18, 0x70, 0x00, 0x24, 0x12, 0x4F, 0x01, 0x25, 0x04, 0x33, 0x00, 0x22, 0x08, 0x1C
	.byte 0x20, 0x41, 0x28, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x60, 0x00, 0xC0, 0x18, 0x02, 0x80, 0x60, 0x1C
	.byte 0x00, 0x06, 0x04, 0x0E, 0x03, 0x2C, 0xF2, 0xD9, 0x38, 0x68, 0xC4, 0x78, 0x0C, 0x40, 0x00, 0x2C
	.byte 0x02, 0xD0, 0x20, 0x1C, 0x01, 0xF0, 0x6A, 0xF8, 0x04, 0x48, 0x84, 0x82, 0x33, 0x20, 0x21, 0x1C
	.byte 0x01, 0xF0, 0x50, 0xF8, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x40, 0x47, 0x00, 0x03
	.byte 0x00, 0x58, 0x00, 0x03

	thumb_func_start FUN_08239274
FUN_08239274: @ 0x08239274
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	movs r2, #0
	ldr r1, _08239290 @ =0x03004740
	strb r2, [r1, #7]
	adds r5, r1, #0
	cmp r0, #0
	beq _08239294
	bl FUN_08238ff8
	movs r0, #0x17
	strb r0, [r5, #4]
	b _0823935E
	.align 2, 0
_08239290: .4byte 0x03004740
_08239294:
	ldrb r0, [r5, #4]
	subs r0, #5
	cmp r0, #0xd
	bhi _0823934A
	lsls r0, r0, #2
	ldr r1, _082392A8 @ =_082392AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082392A8: .4byte _082392AC
_082392AC: @ jump table
	.4byte _082392E4 @ case 0
	.4byte _082392F0 @ case 1
	.4byte _082392F0 @ case 2
	.4byte _08239350 @ case 3
	.4byte _082392FA @ case 4
	.4byte _08239304 @ case 5
	.4byte _08239304 @ case 6
	.4byte _0823930E @ case 7
	.4byte _08239318 @ case 8
	.4byte _08239318 @ case 9
	.4byte _08239350 @ case 10
	.4byte _0823931E @ case 11
	.4byte _08239344 @ case 12
	.4byte _08239344 @ case 13
_082392E4:
	movs r1, #0
	movs r0, #8
	strb r0, [r5, #4]
	strb r1, [r5, #5]
	movs r2, #0x13
	b _08239350
_082392F0:
	movs r0, #7
	strb r0, [r5, #4]
	movs r0, #8
	strb r0, [r5, #5]
	b _08239350
_082392FA:
	movs r0, #0
	strb r0, [r5, #5]
	strb r0, [r5, #4]
	movs r2, #0x21
	b _08239350
_08239304:
	movs r1, #0
	movs r0, #0xb
	strb r0, [r5, #4]
	strb r1, [r5, #5]
	b _08239350
_0823930E:
	movs r0, #0
	strb r0, [r5, #5]
	strb r0, [r5, #4]
	movs r2, #0x23
	b _08239350
_08239318:
	movs r0, #0xe
	strb r0, [r5, #4]
	b _08239350
_0823931E:
	ldrb r0, [r5, #0x11]
	strb r0, [r5, #4]
	ldrb r0, [r5, #0x12]
	strb r0, [r5, #5]
	ldr r4, _08239340 @ =0x03005800
	ldr r0, [r4]
	ldrb r0, [r0, #3]
	bl FUN_0823a32c
	ldr r0, [r4]
	ldrb r0, [r0, #3]
	strh r0, [r5, #0x14]
	movs r0, #0x33
	movs r1, #1
	bl FUN_0823a304
	b _0823935E
	.align 2, 0
_08239340: .4byte 0x03005800
_08239344:
	movs r0, #0x12
	strb r0, [r5, #4]
	b _08239350
_0823934A:
	strb r2, [r5, #5]
	strb r2, [r5, #4]
	movs r2, #0x43
_08239350:
	ldrb r0, [r5, #4]
	cmp r0, #0
	bne _0823935E
	adds r0, r2, #0
	movs r1, #0
	bl FUN_0823a304
_0823935E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08239364
FUN_08239364: @ 0x08239364
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	mov r8, r1
	mov r5, sp
	adds r5, #1
	mov r4, sp
	adds r4, #2
	mov r1, sp
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_08249b00
	mov r0, sp
	ldrb r0, [r0]
	adds r7, r4, #0
	cmp r0, #0
	beq _08239436
	ldr r1, _08239400 @ =0x03004740
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r1, #0x14]
	ldrb r0, [r5]
	strh r0, [r1, #0x16]
	ldrb r0, [r1, #9]
	adds r6, r1, #0
	cmp r0, #0
	beq _0823941E
	movs r0, #1
	strb r0, [r6, #0xa]
	ldrb r0, [r6, #6]
	cmp r0, #0
	bne _082393BA
	ldrb r0, [r5]
	cmp r0, #0
	bne _082393BA
	movs r0, #4
	strb r0, [r6, #0xa]
_082393BA:
	ldrb r0, [r6, #0xa]
	cmp r0, #1
	bne _08239404
	movs r2, #0
	mov r4, sp
	movs r5, #1
	mov ip, r6
	mov r3, ip
	adds r3, #0x30
	movs r6, #0x34
	add r6, ip
	mov sb, r6
_082393D2:
	ldrb r0, [r4]
	asrs r0, r2
	ands r0, r5
	cmp r0, #0
	beq _082393F0
	adds r0, r5, #0
	lsls r0, r2
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r3]
	lsls r0, r2, #1
	add r0, sb
	mov r6, ip
	ldrh r1, [r6, #0x32]
	strh r1, [r0]
_082393F0:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _082393D2
	movs r0, #0x31
	b _08239416
	.align 2, 0
_08239400: .4byte 0x03004740
_08239404:
	movs r0, #0
	strb r0, [r6, #0xa]
	mov r0, sp
	ldrb r0, [r0]
	bl FUN_0823a32c
	movs r0, #1
	mov r8, r0
	movs r0, #0x33
_08239416:
	movs r1, #1
	bl FUN_0823a304
	b _08239432
_0823941E:
	mov r0, sp
	ldrb r0, [r0]
	bl FUN_0823a32c
	movs r1, #1
	mov r8, r1
	movs r0, #0x30
	movs r1, #2
	bl FUN_0823a304
_08239432:
	bl FUN_0823a608
_08239436:
	ldr r0, _08239520 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #1
	bne _08239510
	ldrb r0, [r7]
	cmp r0, #0
	beq _08239494
	movs r2, #0
	ldr r6, _08239524 @ =0x03004740
	movs r3, #1
	adds r4, r6, #0
	adds r4, #0x34
	adds r6, #0x30
	adds r5, r7, #0
_08239454:
	ldrb r0, [r6]
	asrs r0, r2
	ands r0, r3
	cmp r0, #0
	beq _08239470
	ldrb r0, [r5]
	asrs r0, r2
	ands r0, r3
	cmp r0, #0
	beq _08239470
	lsls r0, r2, #1
	adds r0, r0, r4
	movs r1, #0
	strh r1, [r0]
_08239470:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08239454
	ldr r3, _08239524 @ =0x03004740
	adds r2, r3, #0
	adds r2, #0x30
	ldrb r1, [r7]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	ldrb r0, [r7]
	strh r0, [r3, #0x14]
	movs r0, #0x32
	movs r1, #1
	bl FUN_0823a304
_08239494:
	ldr r0, _08239524 @ =0x03004740
	adds r3, r0, #0
	adds r3, #0x30
	ldrb r1, [r3]
	adds r6, r0, #0
	cmp r1, #0
	beq _0823950C
	movs r4, #0
	movs r2, #0
	movs r5, #1
_082394A8:
	ldrb r0, [r3]
	asrs r0, r2
	ands r0, r5
	cmp r0, #0
	beq _082394DA
	lsls r1, r2, #1
	adds r0, r6, #0
	adds r0, #0x34
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _082394DA
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _082394DA
	adds r0, r5, #0
	lsls r0, r2
	ldrb r1, [r3]
	bics r1, r0
	strb r1, [r3]
	orrs r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
_082394DA:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _082394A8
	cmp r4, #0
	beq _082394FE
	adds r0, r4, #0
	bl FUN_0823a32c
	movs r6, #1
	mov r8, r6
	ldr r0, _08239524 @ =0x03004740
	strh r4, [r0, #0x14]
	movs r0, #0x33
	movs r1, #1
	bl FUN_0823a304
_082394FE:
	ldr r0, _08239524 @ =0x03004740
	adds r1, r0, #0
	adds r1, #0x30
	ldrb r1, [r1]
	adds r6, r0, #0
	cmp r1, #0
	bne _08239510
_0823950C:
	movs r0, #0
	strb r0, [r6, #0xa]
_08239510:
	mov r0, r8
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08239520: .4byte 0x03005800
_08239524: .4byte 0x03004740

	thumb_func_start FUN_08239528
FUN_08239528: @ 0x08239528
	push {lr}
	bl FUN_08249a20
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08239540
	movs r0, #0xf1
	movs r1, #0
	bl FUN_0823a304
	bl FUN_0823a608
_08239540:
	pop {r0}
	bx r0

	thumb_func_start FUN_08239544
FUN_08239544: @ 0x08239544
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, _0823955C @ =0x03004740
	ldr r2, [r1, #0x40]
	cmp r2, #0
	bne _08239560
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _08239560
	strb r2, [r1, #4]
	b _0823972E
	.align 2, 0
_0823955C: .4byte 0x03004740
_08239560:
	ldr r0, _08239594 @ =0x03004740
	ldrb r0, [r0, #7]
	cmp r0, #0
	beq _0823956E
	adds r0, r3, #0
	bl FUN_0823973c
_0823956E:
	ldr r4, _08239594 @ =0x03004740
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _08239578
	b _082396F8
_08239578:
	bl FUN_08249008
	movs r0, #1
	strb r0, [r4, #0xe]
	ldrb r0, [r4, #4]
	subs r0, #1
	cmp r0, #0x16
	bls _0823958A
	b _082396EE
_0823958A:
	lsls r0, r0, #2
	ldr r1, _08239598 @ =_0823959C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08239594: .4byte 0x03004740
_08239598: .4byte _0823959C
_0823959C: @ jump table
	.4byte _0823961C @ case 0
	.4byte _08239654 @ case 1
	.4byte _0823965A @ case 2
	.4byte _08239670 @ case 3
	.4byte _08239688 @ case 4
	.4byte _0823968E @ case 5
	.4byte _08239694 @ case 6
	.4byte _082396EE @ case 7
	.4byte _0823969A @ case 8
	.4byte _082396A0 @ case 9
	.4byte _082396A6 @ case 10
	.4byte _082396AC @ case 11
	.4byte _082396BC @ case 12
	.4byte _082396C2 @ case 13
	.4byte _082396EE @ case 14
	.4byte _082396C8 @ case 15
	.4byte _082396D8 @ case 16
	.4byte _082396DE @ case 17
	.4byte _082396E4 @ case 18
	.4byte _082396EE @ case 19
	.4byte _082396EA @ case 20
	.4byte _082396EE @ case 21
	.4byte _082395F8 @ case 22
_082395F8:
	bl sub_08238EB8
	ldr r1, _08239614 @ =0x00008001
	movs r2, #0xff
	cmp r0, r1
	bne _08239606
	movs r2, #0x44
_08239606:
	ldr r1, _08239618 @ =0x03004740
	movs r0, #0
	strb r0, [r1, #5]
	strb r0, [r1, #4]
	adds r0, r2, #0
	b _08239646
	.align 2, 0
_08239614: .4byte 0x00008001
_08239618: .4byte 0x03004740
_0823961C:
	bl sub_08238EB8
	ldr r1, _08239634 @ =0x00008001
	cmp r0, r1
	bne _0823963C
	ldr r0, _08239638 @ =0x03004740
	ldrb r1, [r0, #5]
	strb r1, [r0, #4]
	movs r1, #3
	strb r1, [r0, #5]
	b _082396EE
	.align 2, 0
_08239634: .4byte 0x00008001
_08239638: .4byte 0x03004740
_0823963C:
	ldr r1, _08239650 @ =0x03004740
	movs r0, #0
	strb r0, [r1, #5]
	strb r0, [r1, #4]
	movs r0, #0xff
_08239646:
	movs r1, #0
	bl FUN_0823a304
	b _082396EE
	.align 2, 0
_08239650: .4byte 0x03004740
_08239654:
	bl FUN_082491f4
	b _082396EE
_0823965A:
	ldr r0, _0823966C @ =0x03004740
	ldr r2, [r0, #0x3c]
	ldrh r0, [r2, #2]
	ldrb r1, [r2]
	ldrb r2, [r2, #1]
	bl FUN_0824922c
	b _082396EE
	.align 2, 0
_0823966C: .4byte 0x03004740
_08239670:
	ldr r0, _08239684 @ =0x03004740
	ldr r3, [r0, #0x3c]
	ldrb r0, [r3, #4]
	ldrh r1, [r3, #6]
	ldr r2, [r3, #8]
	ldr r3, [r3, #0xc]
	bl FUN_08249294
	b _082396EE
	.align 2, 0
_08239684: .4byte 0x03004740
_08239688:
	bl FUN_082493bc
	b _082396EE
_0823968E:
	bl FUN_08249498
	b _082396EE
_08239694:
	bl FUN_082494ac
	b _082396EE
_0823969A:
	bl FUN_08249684
	b _082396EE
_082396A0:
	bl FUN_082496bc
	b _082396EE
_082396A6:
	bl FUN_082496f4
	b _082396EE
_082396AC:
	ldr r0, _082396B8 @ =0x03004740
	ldrh r0, [r0, #0x1e]
	bl sub_08249818
	b _082396EE
	.align 2, 0
_082396B8: .4byte 0x03004740
_082396BC:
	bl sub_08249880
	b _082396EE
_082396C2:
	bl FUN_082499e8
	b _082396EE
_082396C8:
	ldr r0, _082396D4 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	bl sub_0824A0DC
	b _082396EE
	.align 2, 0
_082396D4: .4byte 0x03005800
_082396D8:
	bl FUN_0824a138
	b _082396EE
_082396DE:
	bl sub_0824A220
	b _082396EE
_082396E4:
	bl FUN_0824a264
	b _082396EE
_082396EA:
	bl FUN_082490e4
_082396EE:
	bl FUN_08249008
	ldr r1, _08239734 @ =0x03004740
	movs r0, #0
	strb r0, [r1, #0xe]
_082396F8:
	ldr r0, _08239734 @ =0x03004740
	ldrb r0, [r0, #4]
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08239708
	b _0823956E
_08239708:
	ldr r0, _08239738 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #1
	bne _0823971E
	movs r0, #0
	bl FUN_08239364
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0823972E
_0823971E:
	bl FUN_08239f2c
	bl FUN_0823a150
	bl FUN_0823a260
	bl FUN_0823a42c
_0823972E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08239734: .4byte 0x03004740
_08239738: .4byte 0x03005800

	thumb_func_start FUN_0823973c
FUN_0823973c: @ 0x0823973C
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _08239760 @ =0x03004740
	ldrb r1, [r0, #7]
	adds r4, r0, #0
	cmp r1, #5
	bne _08239766
	movs r2, #1
	strb r2, [r4, #6]
	strb r1, [r4, #4]
	ldrh r0, [r4, #0x1c]
	strh r0, [r4, #0x1a]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08239764
	movs r0, #6
	strb r0, [r4, #7]
	b _08239766
	.align 2, 0
_08239760: .4byte 0x03004740
_08239764:
	strb r2, [r4, #7]
_08239766:
	ldrb r0, [r4, #7]
	cmp r0, #1
	bne _08239790
	strb r0, [r4, #6]
	movs r0, #5
	strb r0, [r4, #4]
	adds r0, r3, #0
	movs r1, #0x8c
	bl __umodsi3
	strh r0, [r4, #0x1a]
	movs r1, #0x8c
	subs r1, r1, r0
	strh r1, [r4, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0823978C
	movs r0, #2
	b _0823978E
_0823978C:
	movs r0, #3
_0823978E:
	strb r0, [r4, #7]
_08239790:
	ldrb r0, [r4, #7]
	cmp r0, #3
	bne _082397A6
	movs r0, #0
	strb r0, [r4, #6]
	movs r0, #0x28
	strh r0, [r4, #0x1a]
	movs r0, #4
	strb r0, [r4, #7]
	movs r0, #9
	strb r0, [r4, #4]
_082397A6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_082397ac
FUN_082397ac: @ 0x082397AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r0, _082397E4 @ =0x03004740
	ldrb r1, [r0, #0xe]
	adds r7, r0, #0
	cmp r1, #0
	bne _082397CA
	b _08239C90
_082397CA:
	movs r0, #0
	strb r0, [r7, #0xe]
	mov r0, r8
	subs r0, #0x10
	cmp r0, #0x2d
	bls _082397D8
	b _08239C82
_082397D8:
	lsls r0, r0, #2
	ldr r1, _082397E8 @ =_082397EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082397E4: .4byte 0x03004740
_082397E8: .4byte _082397EC
_082397EC: @ jump table
	.4byte _082398A4 @ case 0
	.4byte _08239C82 @ case 1
	.4byte _08239C82 @ case 2
	.4byte _08239C82 @ case 3
	.4byte _08239C82 @ case 4
	.4byte _08239C82 @ case 5
	.4byte _082398D0 @ case 6
	.4byte _082398BC @ case 7
	.4byte _08239C82 @ case 8
	.4byte _082398E4 @ case 9
	.4byte _082398F4 @ case 10
	.4byte _08239918 @ case 11
	.4byte _08239938 @ case 12
	.4byte _08239958 @ case 13
	.4byte _082399C8 @ case 14
	.4byte _082399FA @ case 15
	.4byte _08239A10 @ case 16
	.4byte _08239A58 @ case 17
	.4byte _08239C82 @ case 18
	.4byte _08239C82 @ case 19
	.4byte _08239C82 @ case 20
	.4byte _08239C82 @ case 21
	.4byte _08239C82 @ case 22
	.4byte _08239BD0 @ case 23
	.4byte _08239C82 @ case 24
	.4byte _08239C82 @ case 25
	.4byte _08239C82 @ case 26
	.4byte _08239C82 @ case 27
	.4byte _08239C82 @ case 28
	.4byte _08239C82 @ case 29
	.4byte _08239C82 @ case 30
	.4byte _08239C82 @ case 31
	.4byte _08239C82 @ case 32
	.4byte _08239C82 @ case 33
	.4byte _08239AC8 @ case 34
	.4byte _08239B14 @ case 35
	.4byte _08239B5C @ case 36
	.4byte _08239C82 @ case 37
	.4byte _08239C82 @ case 38
	.4byte _08239C82 @ case 39
	.4byte _08239C82 @ case 40
	.4byte _08239C82 @ case 41
	.4byte _08239C82 @ case 42
	.4byte _08239C82 @ case 43
	.4byte _08239C82 @ case 44
	.4byte _08239C70 @ case 45
_082398A4:
	cmp r6, #0
	beq _082398AA
	b _08239C82
_082398AA:
	ldr r0, _082398B8 @ =0x03004740
	ldrb r1, [r0, #5]
	strb r1, [r0, #4]
	movs r1, #4
	strb r1, [r0, #5]
	b _08239C82
	.align 2, 0
_082398B8: .4byte 0x03004740
_082398BC:
	cmp r6, #0
	beq _082398C2
	b _08239C82
_082398C2:
	ldr r0, _082398CC @ =0x03004740
	ldrb r1, [r0, #5]
	strb r1, [r0, #4]
	strb r6, [r0, #5]
	b _08239C82
	.align 2, 0
_082398CC: .4byte 0x03004740
_082398D0:
	cmp r6, #0
	beq _082398D6
	b _08239C82
_082398D6:
	ldr r0, _082398E0 @ =0x03004740
	strb r6, [r0, #5]
	strb r6, [r0, #4]
	movs r0, #0
	b _08239BEE
	.align 2, 0
_082398E0: .4byte 0x03004740
_082398E4:
	cmp r6, #0
	beq _082398EA
	b _08239C82
_082398EA:
	ldr r1, _082398F0 @ =0x03004740
	movs r0, #6
	b _08239A04
	.align 2, 0
_082398F0: .4byte 0x03004740
_082398F4:
	ldr r1, _08239914 @ =0x03004740
	ldrh r0, [r1, #0x1a]
	cmp r0, #0
	bne _082398FE
	b _08239C82
_082398FE:
	subs r0, #1
	strh r0, [r1, #0x1a]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0823990A
	b _08239C82
_0823990A:
	movs r0, #7
	strb r0, [r1, #4]
	movs r0, #8
	strb r0, [r1, #5]
	b _08239C82
	.align 2, 0
_08239914: .4byte 0x03004740
_08239918:
	cmp r6, #0
	beq _0823991E
	b _08239C82
_0823991E:
	ldr r0, _08239934 @ =0x03004740
	ldrb r1, [r0, #5]
	strb r1, [r0, #4]
	strb r6, [r0, #5]
	ldrb r0, [r0, #7]
	cmp r0, #0
	beq _0823992E
	b _08239C82
_0823992E:
	movs r0, #0x13
	b _08239BEE
	.align 2, 0
_08239934: .4byte 0x03004740
_08239938:
	cmp r6, #0
	beq _0823993E
	b _08239C82
_0823993E:
	ldrb r0, [r7, #0xb]
	cmp r0, #1
	bne _0823994E
	ldrh r0, [r7, #0x1a]
	cmp r0, #1
	bls _0823994E
	subs r0, #1
	strh r0, [r7, #0x1a]
_0823994E:
	ldr r1, _08239954 @ =0x03004740
	movs r0, #0xa
	b _08239A04
	.align 2, 0
_08239954: .4byte 0x03004740
_08239958:
	cmp r6, #0
	bne _0823999E
	bl FUN_0823a28c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, sp
	strb r0, [r1]
	ldr r4, _082399C0 @ =0x03004740
	strh r0, [r4, #0x14]
	cmp r0, #0
	beq _08239978
	movs r0, #0x20
	movs r1, #1
	bl FUN_0823a304
_08239978:
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	beq _0823999E
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	beq _0823999E
	ldr r0, _082399C4 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	cmp r0, #4
	bne _0823999E
	bl FUN_082496f4
	bl FUN_08249008
	movs r0, #9
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #0xb]
_0823999E:
	ldr r1, _082399C0 @ =0x03004740
	ldrh r0, [r1, #0x1a]
	cmp r0, #0
	bne _082399A8
	b _08239C82
_082399A8:
	subs r0, #1
	strh r0, [r1, #0x1a]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _082399B4
	b _08239C82
_082399B4:
	movs r0, #0xb
	strb r0, [r1, #4]
	movs r0, #0
	strb r0, [r1, #5]
	b _08239C82
	.align 2, 0
_082399C0: .4byte 0x03004740
_082399C4: .4byte 0x03005800
_082399C8:
	cmp r6, #0
	beq _082399CE
	b _08239C82
_082399CE:
	ldr r2, _082399E8 @ =0x03004740
	ldrb r0, [r2, #5]
	strb r0, [r2, #4]
	ldrb r1, [r2, #7]
	cmp r1, #0
	bne _082399EC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _082399E2
	b _08239C82
_082399E2:
	movs r0, #0x21
	b _08239BEE
	.align 2, 0
_082399E8: .4byte 0x03004740
_082399EC:
	cmp r1, #7
	bne _082399F2
	b _08239C82
_082399F2:
	movs r0, #5
	strb r0, [r2, #4]
	strb r0, [r2, #7]
	b _08239C82
_082399FA:
	cmp r6, #0
	beq _08239A00
	b _08239C82
_08239A00:
	ldr r1, _08239A0C @ =0x03004740
	movs r0, #0xd
_08239A04:
	strb r0, [r1, #5]
	strb r0, [r1, #4]
	b _08239C82
	.align 2, 0
_08239A0C: .4byte 0x03004740
_08239A10:
	cmp r6, #0
	bne _08239A34
	ldr r4, _08239A50 @ =0x03004750
	mov r0, sp
	adds r1, r4, #0
	bl FUN_082499b4
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08239A34
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _08239A34
	adds r1, r4, #0
	subs r1, #0x10
	movs r0, #0xe
	strb r0, [r1, #4]
_08239A34:
	ldr r1, _08239A54 @ =0x03004740
	ldrh r0, [r1, #0x1a]
	cmp r0, #0
	bne _08239A3E
	b _08239C82
_08239A3E:
	subs r0, #1
	strh r0, [r1, #0x1a]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08239A4A
	b _08239C82
_08239A4A:
	movs r0, #0xe
	strb r0, [r1, #4]
	b _08239C82
	.align 2, 0
_08239A50: .4byte 0x03004750
_08239A54: .4byte 0x03004740
_08239A58:
	cmp r6, #0
	beq _08239A5E
	b _08239C82
_08239A5E:
	ldr r4, _08239A90 @ =0x03004750
	mov r0, sp
	adds r1, r4, #0
	bl FUN_082499b4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08239A70
	b _08239C82
_08239A70:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _08239A94
	adds r1, r4, #0
	subs r1, #0x10
	movs r0, #0x13
	strb r0, [r1, #4]
	movs r0, #0xf
	strb r0, [r1, #5]
	movs r0, #0x22
	strh r0, [r1, #0x1e]
	ldrb r0, [r1, #0x10]
	strh r0, [r1, #0x14]
	b _08239AB4
	.align 2, 0
_08239A90: .4byte 0x03004750
_08239A94:
	adds r1, r4, #0
	subs r1, #0x10
	strb r6, [r1, #5]
	strb r6, [r1, #4]
	movs r0, #0x23
	strh r0, [r1, #0x1e]
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r1, #0x14]
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08239AB4
	movs r0, #3
	strb r0, [r1, #7]
	movs r0, #9
	strb r0, [r1, #4]
_08239AB4:
	ldr r4, _08239AC4 @ =0x03004740
	ldrb r0, [r4, #0x1e]
	movs r1, #1
	bl FUN_0823a304
	movs r0, #0
	strh r0, [r4, #0x1e]
	b _08239C82
	.align 2, 0
_08239AC4: .4byte 0x03004740
_08239AC8:
	cmp r6, #0
	beq _08239ACE
	b _08239C82
_08239ACE:
	ldr r2, _08239B10 @ =0x03005800
	ldr r3, [r2]
	ldrb r0, [r3, #3]
	movs r1, #0
	strh r0, [r7, #0x14]
	movs r0, #0x11
	strb r0, [r7, #5]
	strb r0, [r7, #4]
	strb r1, [r7, #0x10]
	ldrb r0, [r3, #3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08239AEC
	b _08239C82
_08239AEC:
	adds r1, r7, #0
	movs r3, #1
_08239AF0:
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _08239B00
	b _08239C82
_08239B00:
	ldr r0, [r2]
	ldrb r0, [r0, #3]
	ldrb r4, [r7, #0x10]
	asrs r0, r4
	ands r0, r3
	cmp r0, #0
	beq _08239AF0
	b _08239C82
	.align 2, 0
_08239B10: .4byte 0x03005800
_08239B14:
	cmp r6, #0
	bne _08239B32
	mov r0, sp
	bl FUN_0824a1f0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08239B32
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #1
	bhi _08239B32
	ldr r1, _08239B58 @ =0x03004740
	movs r0, #0x12
	strb r0, [r1, #4]
_08239B32:
	ldr r2, _08239B58 @ =0x03004740
	ldrb r0, [r2, #0x10]
	lsls r0, r0, #1
	adds r1, r2, #0
	adds r1, #0x34
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	bne _08239B46
	b _08239C82
_08239B46:
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08239B52
	b _08239C82
_08239B52:
	movs r0, #0x12
	strb r0, [r2, #4]
	b _08239C82
	.align 2, 0
_08239B58: .4byte 0x03004740
_08239B5C:
	cmp r6, #0
	beq _08239B62
	b _08239C82
_08239B62:
	mov r0, sp
	bl FUN_0824a1f0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08239B70
	b _08239C82
_08239B70:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _08239B8C
	ldr r1, _08239B88 @ =0x03004740
	movs r0, #0x13
	strb r0, [r1, #4]
	movs r0, #0x16
	strb r0, [r1, #5]
	movs r0, #0x32
	strh r0, [r1, #0x1e]
	b _08239BA0
	.align 2, 0
_08239B88: .4byte 0x03004740
_08239B8C:
	ldr r4, _08239BC8 @ =0x03004740
	strb r6, [r4, #5]
	strb r6, [r4, #4]
	ldr r0, _08239BCC @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	bl FUN_0823a32c
	movs r0, #0x33
	strh r0, [r4, #0x1e]
_08239BA0:
	ldr r5, _08239BC8 @ =0x03004740
	ldrb r0, [r5, #0x10]
	lsls r0, r0, #1
	adds r1, r5, #0
	adds r1, #0x34
	adds r0, r0, r1
	movs r1, #0
	movs r4, #0
	strh r4, [r0]
	adds r0, r5, #0
	adds r0, #0x30
	strb r1, [r0]
	strb r1, [r5, #0xa]
	ldrb r0, [r5, #0x1e]
	movs r1, #1
	bl FUN_0823a304
	strh r4, [r5, #0x1e]
	b _08239C82
	.align 2, 0
_08239BC8: .4byte 0x03004740
_08239BCC: .4byte 0x03005800
_08239BD0:
	cmp r6, #0
	bne _08239C82
	ldr r5, _08239BF8 @ =0x03004740
	ldrb r1, [r5, #5]
	adds r0, r1, #0
	cmp r0, #0x16
	bne _08239BFC
	ldrb r0, [r5, #0x11]
	strb r0, [r5, #4]
	ldrb r0, [r5, #0x12]
	strb r0, [r5, #5]
	ldrb r0, [r5, #2]
	movs r0, #1
	strb r0, [r5, #2]
	movs r0, #0x41
_08239BEE:
	movs r1, #0
	bl FUN_0823a304
	b _08239C82
	.align 2, 0
_08239BF8: .4byte 0x03004740
_08239BFC:
	cmp r0, #0xf
	bne _08239C82
	strb r1, [r5, #4]
	ldrb r0, [r5, #2]
	movs r4, #1
	strb r4, [r5, #2]
	movs r0, #0x41
	movs r1, #0
	bl FUN_0823a304
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r0, [r5, #0x10]
	lsls r4, r0
	ldrb r0, [r1]
	orrs r4, r0
	strb r4, [r1]
	ldrb r0, [r5, #0x10]
	lsls r0, r0, #1
	adds r1, #4
	adds r0, r0, r1
	ldrh r1, [r5, #0x26]
	movs r7, #0
	strh r1, [r0]
	ldrb r1, [r5, #0x10]
	movs r0, #4
	bl FUN_0824a3d4
	mov r4, sp
	ldrb r0, [r5, #0x10]
	movs r1, #0xe
	bl FUN_0824a658
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08239C82
	strb r7, [r5, #5]
	strb r7, [r5, #4]
	bl FUN_0823a608
	ldr r0, _08239C6C @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #2]
	ldrb r0, [r0, #3]
	orrs r0, r1
	bl FUN_0823a32c
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r5, #0x14]
	movs r0, #0x25
	movs r1, #1
	bl FUN_0823a304
	b _08239C82
	.align 2, 0
_08239C6C: .4byte 0x03005800
_08239C70:
	cmp r6, #0
	bne _08239C82
	ldr r0, _08239C8C @ =0x03004740
	strb r6, [r0, #5]
	strb r6, [r0, #4]
	movs r0, #0x42
	movs r1, #0
	bl FUN_0823a304
_08239C82:
	ldr r1, _08239C8C @ =0x03004740
	movs r0, #1
	strb r0, [r1, #0xe]
	b _08239CDE
	.align 2, 0
_08239C8C: .4byte 0x03004740
_08239C90:
	cmp r6, #3
	bne _08239CDE
	ldrb r0, [r7, #0xf]
	cmp r0, #0
	beq _08239CDE
	mov r3, r8
	cmp r3, #0x24
	beq _08239CA8
	cmp r3, #0x26
	beq _08239CA8
	cmp r3, #0x27
	bne _08239CDE
_08239CA8:
	bl FUN_0824901c
	bl FUN_08249008
	mov r0, sp
	bl FUN_08249030
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _08239CDE
	ldr r4, _08239CF4 @ =0x03005800
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, #0
	bne _08239CDE
	bl FUN_08248ef4
	ldr r1, [r4]
	ldrb r1, [r1, #2]
	strb r1, [r0, #4]
	movs r1, #1
	strb r1, [r0, #5]
	movs r0, #0x29
	bl FUN_08239364
	movs r6, #0
_08239CDE:
	mov r4, r8
	cmp r4, #0x26
	bne _08239CE6
	b _08239DFA
_08239CE6:
	cmp r4, #0x26
	bgt _08239CF8
	cmp r4, #0x10
	bne _08239CF0
	b _08239E18
_08239CF0:
	b _08239E36
	.align 2, 0
_08239CF4: .4byte 0x03005800
_08239CF8:
	mov r0, r8
	cmp r0, #0x30
	beq _08239D06
	cmp r0, #0x3d
	bne _08239D04
	b _08239E18
_08239D04:
	b _08239E36
_08239D06:
	cmp r6, #0
	beq _08239D0C
	b _08239E3A
_08239D0C:
	bl FUN_08248ef4
	ldr r4, _08239DBC @ =0x03004740
	ldrb r0, [r0, #8]
	strh r0, [r4, #0x14]
	bl FUN_0823a350
	adds r2, r4, #0
	adds r2, #0x30
	ldrb r1, [r2]
	cmp r1, #0
	beq _08239D62
	ldrb r0, [r4, #0x14]
	adds r3, r1, #0
	bics r3, r0
	adds r0, r3, #0
	strb r0, [r2]
	movs r3, #0
	adds r7, r4, #0
	adds r1, r7, #0
	movs r5, #1
	adds r4, r1, #0
	adds r4, #0x34
	movs r2, #0
_08239D3C:
	ldrh r0, [r1, #0x14]
	asrs r0, r3
	ands r0, r5
	cmp r0, #0
	beq _08239D4C
	lsls r0, r3, #1
	adds r0, r0, r4
	strh r2, [r0]
_08239D4C:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls _08239D3C
	ldr r1, _08239DBC @ =0x03004740
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _08239D62
	strb r0, [r1, #5]
	strb r0, [r1, #4]
_08239D62:
	mov r3, sp
	ldr r1, _08239DBC @ =0x03004740
	ldrb r2, [r1]
	ldrb r0, [r1, #0x14]
	ands r0, r2
	strb r0, [r3]
	movs r3, #0
	adds r7, r1, #0
	ldr r2, _08239DC0 @ =0x03005800
	mov r1, sp
	movs r5, #1
	adds r4, r7, #0
_08239D7A:
	ldrb r0, [r1]
	asrs r0, r3
	ands r0, r5
	cmp r0, #0
	beq _08239D8E
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08239D8E
	subs r0, #1
	strb r0, [r7, #1]
_08239D8E:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls _08239D7A
	ldrb r1, [r7, #0x14]
	ldrb r0, [r7]
	bics r0, r1
	strb r0, [r7]
	ldrb r1, [r7, #7]
	cmp r1, #0
	beq _08239DD8
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08239DEA
	cmp r1, #8
	bne _08239DC4
	ldrh r0, [r7, #0x1c]
	strh r0, [r7, #0x1a]
	movs r0, #6
	strb r0, [r7, #7]
	b _08239DD6
	.align 2, 0
_08239DBC: .4byte 0x03004740
_08239DC0: .4byte 0x03005800
_08239DC4:
	ldrb r0, [r7, #4]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08239DD8
	movs r0, #1
	strb r0, [r7, #7]
	movs r0, #5
_08239DD6:
	strb r0, [r7, #4]
_08239DD8:
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08239DEA
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _08239DEA
	movs r0, #0xff
	strb r0, [r7, #6]
_08239DEA:
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	bne _08239E36
	movs r0, #0x40
	movs r1, #1
	bl FUN_0823a304
	b _08239E36
_08239DFA:
	bl FUN_0823a204
	ldr r0, _08239E14 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08239E36
	movs r0, #0x50
	movs r1, #0
	bl FUN_0823a304
	b _08239E36
	.align 2, 0
_08239E14: .4byte 0x03005800
_08239E18:
	cmp r6, #0
	bne _08239E3A
	ldr r0, _08239E64 @ =0x03004740
	strb r6, [r0, #0xd]
	strb r6, [r0, #1]
	strb r6, [r0]
	movs r1, #0xff
	strb r1, [r0, #6]
	bl FUN_0823a608
	mov r4, r8
	cmp r4, #0x3d
	bne _08239E36
	bl FUN_08238f98
_08239E36:
	cmp r6, #0
	beq _08239E8A
_08239E3A:
	ldr r7, _08239E64 @ =0x03004740
	mov r0, r8
	cmp r0, #0x1c
	bne _08239E6C
	cmp r6, #0
	beq _08239E6C
	ldrb r0, [r7, #7]
	cmp r0, #4
	bne _08239E6C
	ldr r2, _08239E68 @ =0x03005800
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r2]
	movs r0, #0xf
	strb r0, [r1, #2]
	bl FUN_0823a32c
	bl FUN_08249008
	b _08239E9C
	.align 2, 0
_08239E64: .4byte 0x03004740
_08239E68: .4byte 0x03005800
_08239E6C:
	movs r1, #0
	mov r3, r8
	strh r3, [r7, #0x14]
	strh r6, [r7, #0x16]
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08239E7E
	strb r1, [r7, #5]
	strb r1, [r7, #4]
_08239E7E:
	movs r0, #0xf0
	movs r1, #2
	bl FUN_0823a304
	bl FUN_0823a608
_08239E8A:
	mov r4, r8
	cmp r4, #0xff
	bne _08239E9C
	movs r0, #0xf2
	movs r1, #0
	bl FUN_0823a304
	bl FUN_0823a608
_08239E9C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08239ea8
FUN_08239ea8: @ 0x08239EA8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r4, _08239EDC @ =0x03004740
	ldrb r7, [r4, #0xe]
	movs r0, #0
	strb r0, [r4, #0xe]
	movs r0, #1
	strb r0, [r4, #0xf]
	ldr r0, _08239EE0 @ =0x03005800
	ldr r0, [r0]
	ldrb r5, [r0]
	cmp r5, #0
	bne _08239EE4
	adds r0, r6, #0
	bl FUN_08239364
	ldrb r0, [r4, #2]
	cmp r0, #1
	beq _08239EFC
	bl FUN_0823a608
	strb r5, [r4, #0xf]
	strb r7, [r4, #0xe]
	b _08239F20
	.align 2, 0
_08239EDC: .4byte 0x03004740
_08239EE0: .4byte 0x03005800
_08239EE4:
	mov r0, sp
	bl FUN_08248e98
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08239EFC
	mov r1, sp
	ldrb r0, [r4, #3]
	ldrb r1, [r1]
	orrs r0, r1
	ldrb r1, [r4, #3]
	strb r0, [r4, #3]
_08239EFC:
	ldr r4, _08239F28 @ =0x03004740
	ldr r1, [r4, #0x44]
	cmp r1, #0
	beq _08239F18
	adds r0, r6, #0
	bl _call_via_r1
	bl FUN_08249008
	ldrb r0, [r4, #2]
	cmp r0, #2
	bne _08239F18
	bl FUN_0823a608
_08239F18:
	ldr r1, _08239F28 @ =0x03004740
	movs r0, #0
	strb r0, [r1, #0xf]
	strb r7, [r1, #0xe]
_08239F20:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08239F28: .4byte 0x03004740

	thumb_func_start FUN_08239f2c
FUN_08239f2c: @ 0x08239F2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r1, _08239FB0 @ =0x03004740
	ldrb r0, [r1, #4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r1, #0
	cmp r0, #3
	bls _08239F4A
	b _0823A13E
_08239F4A:
	ldr r0, _08239FB4 @ =0x03005800
	ldr r2, [r0]
	ldrb r1, [r2, #2]
	ldrb r0, [r3, #0xc]
	adds r4, r1, #0
	eors r4, r0
	ands r4, r1
	ldrb r0, [r2, #7]
	bics r4, r0
	mov r8, r4
	strb r1, [r3, #0xc]
	cmp r4, #0
	beq _08239F72
	strh r4, [r3, #0x14]
	movs r0, #0x10
	movs r1, #1
	str r3, [sp, #4]
	bl FUN_0823a304
	ldr r3, [sp, #4]
_08239F72:
	movs r0, #0
	str r0, [sp]
	movs r6, #0
	adds r7, r3, #0
	movs r1, #0x24
	adds r1, r1, r3
	mov sb, r1
_08239F80:
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r6
	lsrs r4, r0, #0x18
	movs r5, #0
	mov r0, r8
	ands r0, r4
	cmp r0, #0
	beq _08239FD2
	lsls r1, r6, #1
	adds r0, r7, #0
	adds r0, #0x28
	adds r1, r1, r0
	ldrh r0, [r7, #0x26]
	strh r0, [r1]
	mov r2, sb
	ldrb r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strb r0, [r2]
	adds r6, #1
	mov sl, r6
	b _0823A088
	.align 2, 0
_08239FB0: .4byte 0x03004740
_08239FB4: .4byte 0x03005800
_08239FB8:
	ldrb r1, [r7]
	adds r0, r4, #0
	orrs r0, r1
	strb r0, [r7]
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	ldr r0, [sp]
	orrs r0, r4
	str r0, [sp]
	movs r0, #1
	orrs r5, r0
	b _0823A01C
_08239FD2:
	mov r1, sb
	ldrb r0, [r1]
	ands r0, r4
	adds r2, r6, #1
	mov sl, r2
	cmp r0, #0
	beq _0823A088
	ldr r0, _0823A02C @ =0x030057F0
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r1, [r1]
	ldrh r0, [r1, #0x34]
	cmp r0, #0x46
	bne _0823A038
	adds r0, r1, #0
	adds r0, #0x61
	ldrb r0, [r0]
	cmp r0, #1
	bne _0823A050
	movs r5, #2
	ldr r3, [r3, #0x20]
	ldrh r2, [r3]
	ldr r0, _0823A030 @ =0x0000FFFF
	cmp r2, r0
	beq _0823A01C
	ldr r0, _0823A034 @ =0x03005800
	ldr r0, [r0]
	lsls r1, r6, #5
	adds r0, r0, r1
	ldrh r0, [r0, #0x18]
	ldr r1, _0823A030 @ =0x0000FFFF
_0823A010:
	cmp r0, r2
	beq _08239FB8
	adds r3, #2
	ldrh r2, [r3]
	cmp r2, r1
	bne _0823A010
_0823A01C:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	bne _0823A050
	movs r0, #4
	orrs r5, r0
	b _0823A050
	.align 2, 0
_0823A02C: .4byte 0x030057F0
_0823A030: .4byte 0x0000FFFF
_0823A034: .4byte 0x03005800
_0823A038:
	lsls r1, r6, #1
	adds r0, r3, #0
	adds r0, #0x28
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r1, _0823A10C @ =0x0000FFFF
	ands r0, r1
	cmp r0, #0
	bne _0823A050
	movs r5, #6
_0823A050:
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq _0823A076
	mov r2, sb
	ldrb r0, [r2]
	bics r0, r4
	movs r2, #0
	mov r1, sb
	strb r0, [r1]
	lsls r0, r6, #1
	adds r1, r7, #0
	adds r1, #0x28
	adds r0, r0, r1
	strh r2, [r0]
	movs r0, #8
	adds r1, r6, #0
	bl FUN_0824a3d4
_0823A076:
	movs r0, #4
	ands r5, r0
	ldr r3, _0823A110 @ =0x03004740
	cmp r5, #0
	beq _0823A088
	ldrb r1, [r7, #0xd]
	adds r0, r4, #0
	orrs r0, r1
	strb r0, [r7, #0xd]
_0823A088:
	mov r2, sl
	lsls r0, r2, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bhi _0823A094
	b _08239F80
_0823A094:
	ldr r4, [sp]
	cmp r4, #0
	beq _0823A0A6
	ldr r0, _0823A110 @ =0x03004740
	strh r4, [r0, #0x14]
	movs r0, #0x11
	movs r1, #1
	bl FUN_0823a304
_0823A0A6:
	ldr r1, _0823A110 @ =0x03004740
	ldrb r0, [r1, #0xd]
	cmp r0, #0
	beq _0823A0E2
	movs r5, #1
	ldr r0, _0823A114 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	cmp r0, #0
	beq _0823A0C6
	ldrb r0, [r1, #3]
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, r1
	beq _0823A0C6
	movs r5, #0
_0823A0C6:
	cmp r5, #0
	beq _0823A0E2
	ldr r4, _0823A110 @ =0x03004740
	ldrb r0, [r4, #0xd]
	bl FUN_0823a32c
	ldrb r0, [r4, #0xd]
	movs r1, #0
	strh r0, [r4, #0x14]
	strb r1, [r4, #0xd]
	movs r0, #0x12
	movs r1, #1
	bl FUN_0823a304
_0823A0E2:
	ldr r0, _0823A110 @ =0x03004740
	adds r1, r0, #0
	adds r1, #0x24
	ldrb r1, [r1]
	adds r3, r0, #0
	cmp r1, #0
	bne _0823A13E
	ldrb r0, [r3, #4]
	cmp r0, #8
	bne _0823A13E
	ldrb r0, [r3, #7]
	cmp r0, #0
	bne _0823A118
	strb r0, [r3, #5]
	strb r0, [r3, #4]
	movs r0, #0x14
	movs r1, #0
	bl FUN_0823a304
	b _0823A13E
	.align 2, 0
_0823A10C: .4byte 0x0000FFFF
_0823A110: .4byte 0x03004740
_0823A114: .4byte 0x03005800
_0823A118:
	cmp r0, #2
	bne _0823A124
	movs r0, #3
	strb r0, [r3, #7]
	movs r0, #9
	b _0823A12A
_0823A124:
	movs r0, #1
	strb r0, [r3, #7]
	movs r0, #5
_0823A12A:
	strb r0, [r3, #4]
	ldrb r0, [r3]
	cmp r0, #0
	beq _0823A13E
	movs r0, #0
	strh r0, [r3, #0x1a]
	movs r0, #8
	strb r0, [r3, #7]
	movs r0, #5
	strb r0, [r3, #4]
_0823A13E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823a150
FUN_0823a150: @ 0x0823A150
	push {r4, r5, r6, lr}
	ldr r1, _0823A1F4 @ =0x04000208
	ldrh r0, [r1]
	adds r6, r0, #0
	movs r0, #0
	strh r0, [r1]
	ldr r4, _0823A1F8 @ =0x03004740
	ldrb r0, [r4, #4]
	cmp r0, #0xf
	bne _0823A1B4
	ldrb r1, [r4, #0x10]
	lsls r1, r1, #1
	adds r5, r4, #0
	adds r5, #0x28
	adds r1, r1, r5
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0823A18A
	ldr r1, _0823A1FC @ =0x030057F0
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0x27
	bne _0823A1B4
_0823A18A:
	bl FUN_0823a628
	movs r0, #0x18
	strb r0, [r4, #4]
	ldrb r1, [r4, #0x10]
	movs r0, #4
	bl FUN_0824a3d4
	adds r2, r4, #0
	adds r2, #0x24
	movs r1, #1
	ldrb r0, [r4, #0x10]
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0]
_0823A1B4:
	ldr r0, _0823A1F4 @ =0x04000208
	strh r6, [r0]
	ldr r5, _0823A1F8 @ =0x03004740
	ldrb r0, [r5, #4]
	cmp r0, #0x18
	bne _0823A1EE
	ldrb r0, [r5, #2]
	cmp r0, #1
	bne _0823A1CA
	bl FUN_0823a628
_0823A1CA:
	ldrb r0, [r5, #2]
	adds r4, r0, #0
	cmp r4, #0
	bne _0823A1EE
	strb r4, [r5, #5]
	strb r4, [r5, #4]
	ldr r0, _0823A200 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #2]
	ldrb r0, [r0, #3]
	orrs r0, r1
	bl FUN_0823a32c
	strh r4, [r5, #0x14]
	movs r0, #0x25
	movs r1, #1
	bl FUN_0823a304
_0823A1EE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0823A1F4: .4byte 0x04000208
_0823A1F8: .4byte 0x03004740
_0823A1FC: .4byte 0x030057F0
_0823A200: .4byte 0x03005800

	thumb_func_start FUN_0823a204
FUN_0823a204: @ 0x0823A204
	push {r4, r5, lr}
	ldr r5, _0823A258 @ =0x03004740
	ldrb r0, [r5, #4]
	cmp r0, #0xf
	bne _0823A250
	ldr r1, _0823A25C @ =0x030057F0
	ldrb r2, [r5, #0x10]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0x26
	bne _0823A250
	movs r4, #0
	strb r4, [r5, #5]
	strb r4, [r5, #4]
	movs r0, #4
	adds r1, r2, #0
	bl FUN_0824a3d4
	adds r2, r5, #0
	adds r2, #0x24
	movs r1, #1
	ldrb r0, [r5, #0x10]
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	ldrb r0, [r5, #0x10]
	lsls r0, r0, #1
	adds r1, r5, #0
	adds r1, #0x28
	adds r0, r0, r1
	strh r4, [r0]
	movs r0, #0x24
	movs r1, #0
	bl FUN_0823a304
_0823A250:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823A258: .4byte 0x03004740
_0823A25C: .4byte 0x030057F0

	thumb_func_start FUN_0823a260
FUN_0823a260: @ 0x0823A260
	push {lr}
	ldr r1, _0823A288 @ =0x03004740
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _0823A284
	ldrb r0, [r1, #0xa]
	cmp r0, #1
	bne _0823A284
	ldrb r0, [r1, #4]
	strb r0, [r1, #0x11]
	ldrb r0, [r1, #5]
	strb r0, [r1, #0x12]
	movs r0, #0x10
	strb r0, [r1, #4]
	movs r0, #0x11
	strb r0, [r1, #5]
	movs r0, #2
	strb r0, [r1, #0xa]
_0823A284:
	pop {r0}
	bx r0
	.align 2, 0
_0823A288: .4byte 0x03004740

	thumb_func_start FUN_0823a28c
FUN_0823a28c: @ 0x0823A28C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r6, #0
	movs r5, #0
	ldr r1, _0823A2F8 @ =0x03005800
	ldr r0, [r1]
	ldrb r0, [r0, #8]
	cmp r6, r0
	bhs _0823A2E8
	mov r8, r0
	ldr r0, _0823A2FC @ =0x03004740
	mov sl, r0
	mov sb, r1
_0823A2AC:
	mov r1, sl
	ldr r3, [r1, #0x20]
	ldrh r2, [r3]
	adds r0, r5, #1
	mov ip, r0
	ldr r1, _0823A300 @ =0x0000FFFF
	cmp r2, r1
	beq _0823A2DE
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r5, #5
	adds r0, r0, r1
	ldrh r4, [r0, #0x18]
	ldr r7, _0823A300 @ =0x0000FFFF
	movs r1, #1
	lsls r1, r5
_0823A2CC:
	cmp r4, r2
	bne _0823A2D6
	orrs r6, r1
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
_0823A2D6:
	adds r3, #2
	ldrh r2, [r3]
	cmp r2, r7
	bne _0823A2CC
_0823A2DE:
	mov r1, ip
	lsls r0, r1, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r8
	blo _0823A2AC
_0823A2E8:
	adds r0, r6, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823A2F8: .4byte 0x03005800
_0823A2FC: .4byte 0x03004740
_0823A300: .4byte 0x0000FFFF

	thumb_func_start FUN_0823a304
FUN_0823a304: @ 0x0823A304
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _0823A328 @ =0x03004740
	ldr r2, [r4, #0x40]
	cmp r2, #0
	beq _0823A31A
	bl _call_via_r2
_0823A31A:
	movs r0, #0
	strh r0, [r4, #0x16]
	strh r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823A328: .4byte 0x03004740

	thumb_func_start FUN_0823a32c
FUN_0823a32c: @ 0x0823A32C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, _0823A34C @ =0x03004740
	ldrb r5, [r4, #0xe]
	movs r1, #1
	strb r1, [r4, #0xe]
	bl FUN_08249f6c
	bl FUN_08249008
	strb r5, [r4, #0xe]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823A34C: .4byte 0x03004740

	thumb_func_start FUN_0823a350
FUN_0823a350: @ 0x0823A350
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _0823A41C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _0823A398
	movs r4, #0
_0823A362:
	ldr r1, _0823A420 @ =0x030057F0
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0823A38E
	ldrb r1, [r2, #0x1a]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0823A38E
	adds r2, r1, #0
	bics r2, r5
	movs r0, #0x20
	adds r1, r4, #0
	bl FUN_0824a894
_0823A38E:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0823A362
_0823A398:
	ldr r0, _0823A41C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	cmp r0, #0
	beq _0823A3D6
	movs r4, #0
_0823A3A4:
	ldr r1, _0823A420 @ =0x030057F0
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r0, [r2, #0x34]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0823A3CC
	adds r0, r2, #0
	adds r0, #0x4e
	ldrb r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _0823A3CC
	adds r0, r4, #0
	bl FUN_0824a9fc
_0823A3CC:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0823A3A4
_0823A3D6:
	ldr r0, _0823A41C @ =0x03005800
	ldr r3, [r0]
	ldrb r2, [r3, #6]
	cmp r2, #0
	beq _0823A414
	mvns r1, r5
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #6]
	movs r4, #0
	ldr r7, _0823A424 @ =0x030057E0
	ldr r6, _0823A428 @ =0x00008024
_0823A3EE:
	lsls r0, r4, #2
	adds r0, r0, r7
	ldr r2, [r0]
	ldrh r0, [r2]
	cmp r0, r6
	bne _0823A40A
	ldrb r3, [r2, #3]
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _0823A40A
	adds r0, r1, #0
	ands r0, r3
	strb r0, [r2, #3]
_0823A40A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0823A3EE
_0823A414:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823A41C: .4byte 0x03005800
_0823A420: .4byte 0x030057F0
_0823A424: .4byte 0x030057E0
_0823A428: .4byte 0x00008024

	thumb_func_start FUN_0823a42c
FUN_0823a42c: @ 0x0823A42C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0823A518 @ =0x03004740
	ldrh r0, [r0, #0x18]
	cmp r0, #0
	beq _0823A508
	ldr r0, _0823A51C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _0823A4CC
	movs r6, #0
_0823A44C:
	ldr r3, _0823A520 @ =0x030057F0
	lsls r2, r6, #2
	adds r0, r2, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	ands r1, r0
	adds r7, r2, #0
	adds r0, r6, #1
	mov sb, r0
	cmp r1, #0
	beq _0823A4C2
	movs r5, #0
	movs r4, #0
	movs r1, #1
	mov r8, r1
	mov sl, r3
_0823A472:
	adds r0, r7, r3
	ldr r0, [r0]
	ldrb r0, [r0, #0x1a]
	asrs r0, r4
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _0823A49C
	lsls r0, r4, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r1, _0823A518 @ =0x03004740
	ldrh r0, [r0, #2]
	ldrh r1, [r1, #0x18]
	cmp r0, r1
	bls _0823A49C
	mov r0, r8
	lsls r0, r4
	orrs r5, r0
	lsls r0, r5, #0x18
	lsrs r5, r0, #0x18
_0823A49C:
	cmp r5, #0
	beq _0823A4B8
	mov r1, sl
	adds r0, r7, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0x1a]
	adds r2, r5, #0
	eors r2, r0
	movs r0, #0x20
	adds r1, r6, #0
	str r3, [sp]
	bl FUN_0824a894
	ldr r3, [sp]
_0823A4B8:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0823A472
_0823A4C2:
	mov r3, sb
	lsls r0, r3, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls _0823A44C
_0823A4CC:
	ldr r0, _0823A51C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	cmp r0, #0
	beq _0823A508
	movs r6, #0
_0823A4D8:
	ldr r1, _0823A520 @ =0x030057F0
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r0, [r2, #0x34]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r1, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0823A4FE
	ldr r1, _0823A518 @ =0x03004740
	ldrh r0, [r2, #0x36]
	ldrh r1, [r1, #0x18]
	cmp r0, r1
	bls _0823A4FE
	adds r0, r6, #0
	bl FUN_0824a9fc
_0823A4FE:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls _0823A4D8
_0823A508:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823A518: .4byte 0x03004740
_0823A51C: .4byte 0x03005800
_0823A520: .4byte 0x030057F0

	thumb_func_start FUN_0823a524
FUN_0823a524: @ 0x0823A524
	push {lr}
	ldr r1, _0823A534 @ =0x03004740
	str r0, [r1, #0x44]
	ldr r0, _0823A538 @ =FUN_08239ea8
	bl FUN_08248f04
	pop {r0}
	bx r0
	.align 2, 0
_0823A534: .4byte 0x03004740
_0823A538: .4byte FUN_08239ea8

	thumb_func_start FUN_0823a53c
FUN_0823a53c: @ 0x0823A53C
	ldr r1, _0823A544 @ =0x03004740
	str r0, [r1, #0x40]
	bx lr
	.align 2, 0
_0823A544: .4byte 0x03004740
_0823A548:
	.byte 0x30, 0xB5, 0x00, 0x06, 0x04, 0x0E, 0x09, 0x04
	.byte 0x0D, 0x0C, 0x06, 0x48, 0x41, 0x7A, 0x03, 0x1C, 0x00, 0x29, 0x09, 0xD0, 0x00, 0x2C, 0x07, 0xD1
	.byte 0x30, 0x30, 0x00, 0x78, 0x00, 0x28, 0x03, 0xD0, 0x05, 0x20, 0x09, 0xE0, 0x40, 0x47, 0x00, 0x03
	.byte 0x05, 0x4A, 0x11, 0x88, 0x00, 0x20, 0x10, 0x80, 0x5C, 0x72, 0x5D, 0x86, 0x11, 0x80, 0x00, 0x20
	.byte 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0x08, 0x02, 0x00, 0x04, 0x00, 0xB5, 0x00, 0x04
	.byte 0x02, 0x0C, 0x05, 0x48, 0x00, 0x68, 0x01, 0x79, 0x40, 0x79, 0x08, 0x43, 0x00, 0x28, 0x07, 0xD1
	.byte 0x02, 0x48, 0x02, 0x83, 0x00, 0x20, 0x0B, 0xE0, 0x00, 0x58, 0x00, 0x03, 0x40, 0x47, 0x00, 0x03
	.byte 0x04, 0x49, 0x06, 0x20, 0x88, 0x82, 0xF3, 0x20, 0x01, 0x21, 0xFF, 0xF7, 0xA3, 0xFE, 0x06, 0x20
	.byte 0x02, 0xBC, 0x08, 0x47, 0x40, 0x47, 0x00, 0x03, 0x00, 0xB5, 0x00, 0x06, 0x02, 0x0E, 0x13, 0x1C
	.byte 0x07, 0x49, 0x08, 0x79, 0x09, 0x38, 0x00, 0x06, 0x00, 0x0E, 0x02, 0x28, 0x0A, 0xD8, 0x07, 0x20
	.byte 0x88, 0x82, 0xF3, 0x20, 0x01, 0x21, 0xFF, 0xF7, 0x8D, 0xFE, 0x07, 0x20, 0x09, 0xE0, 0x00, 0x00
	.byte 0x40, 0x47, 0x00, 0x03, 0x00, 0x2A, 0x02, 0xD0, 0x01, 0x20, 0xC8, 0x72, 0x00, 0xE0, 0xCB, 0x72
	.byte 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_0823a608
FUN_0823a608: @ 0x0823A608
	push {lr}
	ldr r1, _0823A624 @ =0x03004740
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _0823A620
	ldrb r0, [r1, #2]
	movs r0, #0
	strb r0, [r1, #2]
	movs r0, #0x45
	movs r1, #0
	bl FUN_0823a304
_0823A620:
	pop {r0}
	bx r0
	.align 2, 0
_0823A624: .4byte 0x03004740

	thumb_func_start FUN_0823a628
FUN_0823a628: @ 0x0823A628
	push {lr}
	ldr r1, _0823A63C @ =0x03004740
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _0823A640
	movs r0, #0x45
	movs r1, #0
	bl FUN_0823a304
	b _0823A64C
	.align 2, 0
_0823A63C: .4byte 0x03004740
_0823A640:
	ldrb r0, [r1, #2]
	cmp r0, #1
	bne _0823A64C
	ldrb r0, [r1, #2]
	movs r0, #2
	strb r0, [r1, #2]
_0823A64C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0823a650
FUN_0823a650: @ 0x0823A650
	push {lr}
	ldr r0, _0823A670 @ =0x03004740
	ldrb r1, [r0, #7]
	adds r2, r0, #0
	cmp r1, #0
	beq _0823A6BA
	ldrb r0, [r2, #4]
	subs r0, #5
	cmp r0, #6
	bhi _0823A6BA
	lsls r0, r0, #2
	ldr r1, _0823A674 @ =_0823A678
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823A670: .4byte 0x03004740
_0823A674: .4byte _0823A678
_0823A678: @ jump table
	.4byte _0823A694 @ case 0
	.4byte _0823A69C @ case 1
	.4byte _0823A6A6 @ case 2
	.4byte _0823A6A6 @ case 3
	.4byte _0823A6AC @ case 4
	.4byte _0823A6AC @ case 5
	.4byte _0823A6B2 @ case 6
_0823A694:
	movs r0, #3
	strb r0, [r2, #7]
	movs r0, #9
	b _0823A6B8
_0823A69C:
	movs r0, #2
	strb r0, [r2, #7]
	movs r0, #1
	strh r0, [r2, #0x1a]
	b _0823A6BA
_0823A6A6:
	movs r0, #2
	strb r0, [r2, #7]
	b _0823A6BA
_0823A6AC:
	movs r0, #0x28
	strh r0, [r2, #0x1a]
	b _0823A6BA
_0823A6B2:
	movs r0, #0x28
	strh r0, [r2, #0x1a]
	movs r0, #0xa
_0823A6B8:
	strb r0, [r2, #4]
_0823A6BA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823a6c0
FUN_0823a6c0: @ 0x0823A6C0
	push {r4, lr}
	ldr r0, _0823A6E4 @ =0x03000838
	ldr r1, _0823A6E8 @ =0x00000E64
	ldr r4, _0823A6EC @ =0x03002CB4
	adds r2, r4, #0
	movs r3, #1
	bl FUN_08248cc0
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0823A6F0
	adds r1, r4, #4
	movs r0, #3
	bl FUN_08248ee0
	movs r0, #0
	b _0823A6F4
	.align 2, 0
_0823A6E4: .4byte 0x03000838
_0823A6E8: .4byte 0x00000E64
_0823A6EC: .4byte 0x03002CB4
_0823A6F0:
	movs r0, #1
	rsbs r0, r0, #0
_0823A6F4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823a6fc
FUN_0823a6fc: @ 0x0823A6FC
	push {lr}
	bl FUN_082491b8
	ldr r1, _0823A70C @ =0x00008001
	cmp r0, r1
	bne _0823A710
	movs r0, #1
	b _0823A72C
	.align 2, 0
_0823A70C: .4byte 0x00008001
_0823A710:
	ldr r0, _0823A720 @ =0x03003504
	ldr r1, [r0]
	ldr r0, _0823A724 @ =0x000001C1
	cmp r1, r0
	bhi _0823A728
	movs r0, #0
	b _0823A72C
	.align 2, 0
_0823A720: .4byte 0x03003504
_0823A724: .4byte 0x000001C1
_0823A728:
	movs r0, #1
	rsbs r0, r0, #0
_0823A72C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0823a730
FUN_0823a730: @ 0x0823A730
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r1, #4
	strb r1, [r6]
	movs r1, #0x28
	strb r1, [r6, #1]
	strb r4, [r6, #4]
	strh r2, [r6, #6]
	str r5, [r6, #8]
	movs r1, #1
	strb r1, [r6, #0x11]
	movs r1, #0xf0
	strh r1, [r6, #0x12]
	adds r1, #0xf0
	strh r1, [r6, #0x14]
	cmp r7, #0
	beq _0823A760
	strh r3, [r6, #2]
	b _0823A762
_0823A760:
	strh r7, [r6, #2]
_0823A762:
	ldr r1, [sp, #0x1c]
	str r1, [r6, #0xc]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823a76c
FUN_0823a76c: @ 0x0823A76C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r2, _0823A78C @ =0x05000081
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #1
	strb r0, [r4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823A78C: .4byte 0x05000081

	thumb_func_start FUN_0823a790
FUN_0823a790: @ 0x0823A790
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	bne _0823A7A8
	ldrb r0, [r4, #1]
	ldrb r1, [r4, #2]
	cmp r0, r1
	bne _0823A7A8
	movs r0, #1
	b _0823A7CC
_0823A7A8:
	ldrb r1, [r4, #2]
	lsls r1, r1, #4
	adds r1, #4
	adds r1, r4, r1
	ldr r2, _0823A7D4 @ =0x04000004
	adds r0, r3, #0
	bl CpuSet
	ldrb r1, [r4, #3]
	adds r1, #1
	movs r3, #0
	strb r1, [r4, #3]
	ldrb r1, [r4, #2]
	adds r1, #1
	movs r2, #0x1f
	ands r1, r2
	strb r1, [r4, #2]
	strb r3, [r4]
_0823A7CC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823A7D4: .4byte 0x04000004

	thumb_func_start FUN_0823a7d8
FUN_0823a7d8: @ 0x0823A7D8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r5, [r4]
	cmp r5, #0
	beq _0823A7E8
	movs r0, #0
	b _0823A82C
_0823A7E8:
	ldr r6, _0823A834 @ =0x04000208
	strh r5, [r6]
	ldrb r0, [r4, #1]
	lsls r0, r0, #4
	adds r0, #4
	adds r0, r4, r0
	ldr r2, _0823A838 @ =0x04000004
	bl CpuSet
	str r5, [sp]
	ldrb r1, [r4, #1]
	lsls r1, r1, #4
	adds r1, #4
	adds r1, r4, r1
	ldr r2, _0823A83C @ =0x05000004
	mov r0, sp
	bl CpuSet
	ldrb r0, [r4, #3]
	subs r0, #1
	strb r0, [r4, #3]
	ldrb r0, [r4, #1]
	adds r0, #1
	movs r1, #0x1f
	ands r0, r1
	strb r0, [r4, #1]
	ldrb r1, [r4, #2]
	cmp r0, r1
	bne _0823A826
	movs r0, #1
	strb r0, [r4]
_0823A826:
	movs r0, #1
	strh r0, [r6]
	movs r0, #1
_0823A82C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0823A834: .4byte 0x04000208
_0823A838: .4byte 0x04000004
_0823A83C: .4byte 0x05000004

	thumb_func_start FUN_0823a840
FUN_0823a840: @ 0x0823A840
	push {lr}
	adds r3, r1, #0
	ldr r1, _0823A864 @ =0x08DBD564
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0823A868
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0823A868
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	b _0823A86A
	.align 2, 0
_0823A864: .4byte 0x08DBD564
_0823A868:
	movs r0, #0
_0823A86A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823a870
FUN_0823a870: @ 0x0823A870
	ldr r1, _0823A878 @ =0x030047A8
	ldr r0, _0823A87C @ =0x030016C0
	str r0, [r1]
	bx lr
	.align 2, 0
_0823A878: .4byte 0x030047A8
_0823A87C: .4byte 0x030016C0

	thumb_func_start FUN_0823a880
FUN_0823a880: @ 0x0823A880
	push {lr}
	bl FUN_08231b58
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823a88c
FUN_0823a88c: @ 0x0823A88C
	push {lr}
	bl FUN_08231b58
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823a898
FUN_0823a898: @ 0x0823A898
	push {lr}
	bl FUN_082318ac
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823a8a4
FUN_0823a8a4: @ 0x0823A8A4
	push {lr}
	bl FUN_082318ac
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823a8b0
FUN_0823a8b0: @ 0x0823A8B0
	push {lr}
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _0823A8DC @ =0x030047A4
	ldr r1, _0823A8E0 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _0823A8EC
	ldr r0, _0823A8E4 @ =0x030047B0
	ldr r0, [r0]
	cmp r0, #0
	bne _0823A8EC
	ldr r0, _0823A8E8 @ =0x03004790
	ldr r0, [r0]
	cmp r0, #0
	bne _0823A8EC
	movs r0, #0
	b _0823A8EE
	.align 2, 0
_0823A8DC: .4byte 0x030047A4
_0823A8E0: .4byte 0x030047A0
_0823A8E4: .4byte 0x030047B0
_0823A8E8: .4byte 0x03004790
_0823A8EC:
	movs r0, #1
_0823A8EE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823a8f4
FUN_0823a8f4: @ 0x0823A8F4
	push {lr}
	cmp r0, #0
	bne _0823A908
	ldr r1, _0823A904 @ =0x03004798
	movs r0, #0xa0
	lsls r0, r0, #1
	str r0, [r1]
	b _0823A90C
	.align 2, 0
_0823A904: .4byte 0x03004798
_0823A908:
	bl FUN_0823a928
_0823A90C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0823a910
FUN_0823a910: @ 0x0823A910
	ldr r1, _0823A918 @ =0x03004788
	movs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_0823A918: .4byte 0x03004788

	thumb_func_start FUN_0823a91c
FUN_0823a91c: @ 0x0823A91C
	ldr r1, _0823A924 @ =0x03004788
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0823A924: .4byte 0x03004788

	thumb_func_start FUN_0823a928
FUN_0823a928: @ 0x0823A928
	push {lr}
	ldr r0, _0823A970 @ =0x03003518
	movs r1, #0
	str r1, [r0]
	ldr r0, _0823A974 @ =0x03002CA0
	str r1, [r0]
	ldr r0, _0823A978 @ =0x03003510
	strh r1, [r0]
	ldr r0, _0823A97C @ =0x03003514
	strh r1, [r0]
	ldr r0, _0823A980 @ =0x0300351C
	strh r1, [r0]
	bl m4aMPlayAllStop
	bl m4aSoundVSyncOff
	bl FUN_08229f34
	bl FUN_08229f34
	bl FUN_082477b4
	bl FUN_0824c5b0
	ldr r0, _0823A984 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0823A968
	ldr r0, _0823A988 @ =0x03002C64
	ldr r0, [r0]
	cmp r0, #0
	beq _0823A98C
_0823A968:
	bl FUN_08238bf4
	b _0823A998
	.align 2, 0
_0823A970: .4byte 0x03003518
_0823A974: .4byte 0x03002CA0
_0823A978: .4byte 0x03003510
_0823A97C: .4byte 0x03003514
_0823A980: .4byte 0x0300351C
_0823A984: .4byte 0x03002C68
_0823A988: .4byte 0x03002C64
_0823A98C:
	ldr r0, _0823A9B4 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _0823A998
	bl FUN_08237f54
_0823A998:
	movs r0, #0
	bl FUN_08248f10
	bl FUN_082490e4
	bl FUN_08249008
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0823A9B8
	movs r0, #0xdc
	bl FUN_0824c1f8
	b _0823A9BE
	.align 2, 0
_0823A9B4: .4byte 0x03002C6C
_0823A9B8:
	movs r0, #0xdc
	bl FUN_0824c1f8
_0823A9BE:
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0823a9c4
FUN_0823a9c4: @ 0x0823A9C4
	push {lr}
	ldr r1, _0823A9EC @ =0x030044AC
	movs r0, #0
	str r0, [r1]
	bl FUN_0822b778
	bl FUN_0823cd04
	bl FUN_082326d8
	bl FUN_08236ed0
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, _0823A9F0 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0823A9EC: .4byte 0x030044AC
_0823A9F0: .4byte 0x03003E78

	thumb_func_start FUN_0823a9f4
FUN_0823a9f4: @ 0x0823A9F4
	push {lr}
	bl FUN_0824082c
	ldr r2, _0823AA0C @ =0x030044BC
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0823AA0C: .4byte 0x030044BC

	thumb_func_start FUN_0823aa10
FUN_0823aa10: @ 0x0823AA10
	push {lr}
	movs r2, #1
	ldr r0, _0823AA38 @ =0x030047A4
	ldr r1, _0823AA3C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _0823AA32
	bl FUN_082407e0
	movs r2, #2
	ldr r1, _0823AA40 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0823AA32:
	pop {r0}
	bx r0
	.align 2, 0
_0823AA38: .4byte 0x030047A4
_0823AA3C: .4byte 0x030047A0
_0823AA40: .4byte 0x030044BC

	thumb_func_start FUN_0823aa44
FUN_0823aa44: @ 0x0823AA44
	push {lr}
	ldr r0, _0823AA64 @ =0x030044BC
	ldr r1, [r0]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r1
	cmp r0, #0
	bne _0823AA6C
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _0823AA68
	bl FUN_0823aa10
	b _0823AA6C
	.align 2, 0
_0823AA64: .4byte 0x030044BC
_0823AA68:
	bl FUN_0823a9f4
_0823AA6C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0823aa70
FUN_0823aa70: @ 0x0823AA70
	bx lr
	.align 2, 0

	thumb_func_start FUN_0823aa74
FUN_0823aa74: @ 0x0823AA74
	push {lr}
	movs r0, #0
	bl FUN_08230dc4
	bl FUN_0822d0e4
	pop {r0}
	bx r0

	thumb_func_start FUN_0823aa84
FUN_0823aa84: @ 0x0823AA84
	push {lr}
	bl FUN_0823b1ec
	bl FUN_0823b744
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823aa94
FUN_0823aa94: @ 0x0823AA94
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r1, _0823AAC8 @ =0x030047B8
	ldr r0, [r1]
	cmp r0, #0
	bne _0823AAD0
	ldr r0, _0823AACC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0823AAD4
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0823AAD4
	movs r0, #0xc
	ands r0, r1
	cmp r0, #0xc
	bne _0823AAD4
	bl FUN_0823a928
	b _0823AC94
	.align 2, 0
_0823AAC8: .4byte 0x030047B8
_0823AACC: .4byte 0x030044E0
_0823AAD0:
	movs r0, #0
	str r0, [r1]
_0823AAD4:
	ldr r5, [r6, #0x18]
	cmp r5, #0
	beq _0823AAE0
	cmp r5, #1
	beq _0823AB34
	b _0823AC4C
_0823AAE0:
	ldr r0, _0823AB20 @ =0x03004860
	str r5, [r0]
	ldr r7, _0823AB24 @ =0x03002CA8
	movs r0, #1
	mov r8, r0
	str r0, [r7]
	ldr r0, _0823AB28 @ =0x03004798
	str r5, [r0]
	str r5, [r6, #0x1c]
	bl FUN_0823a9c4
	bl FUN_08231c1c
	ldr r0, _0823AB2C @ =0x03002B28
	ldrh r4, [r0]
	cmp r4, #0
	beq _0823AB0E
	adds r0, r4, #0
	movs r1, #0
	bl FUN_082318ac
	cmp r4, #0
	bne _0823AB12
_0823AB0E:
	bl FUN_08231ba8
_0823AB12:
	str r5, [r7]
	mov r1, r8
	str r1, [r6, #0x18]
	ldr r0, _0823AB30 @ =0x030047AC
	str r5, [r0]
	b _0823AC4C
	.align 2, 0
_0823AB20: .4byte 0x03004860
_0823AB24: .4byte 0x03002CA8
_0823AB28: .4byte 0x03004798
_0823AB2C: .4byte 0x03002B28
_0823AB30: .4byte 0x030047AC
_0823AB34:
	ldr r0, [r6, #0x1c]
	cmp r0, #0
	bgt _0823ABCC
	ldr r0, _0823AB8C @ =0x03004798
	ldr r0, [r0]
	cmp r0, #0
	beq _0823ABAC
	ldr r4, _0823AB90 @ =0x030044BC
	ldr r0, [r4]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0823AB50
	b _0823AC4C
_0823AB50:
	bl FUN_0823a8b0
	adds r1, r0, #0
	cmp r1, #0
	bne _0823ABAC
	ldr r0, _0823AB94 @ =0x0300478C
	str r1, [r0]
	ldr r0, _0823AB98 @ =0x030047C4
	str r1, [r0]
	ldr r0, _0823AB9C @ =0x030047AC
	str r5, [r0]
	movs r1, #0xf
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r0, #1
	bl entity_08230ca4
	movs r0, #3
	str r0, [r6, #0x1c]
	ldr r2, _0823ABA0 @ =0x03003E78
	ldr r0, _0823ABA4 @ =0xFFFFF1FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0823ABA8 @ =0x03004460
	movs r0, #0x40
	str r0, [r1]
	b _0823AC4C
	.align 2, 0
_0823AB8C: .4byte 0x03004798
_0823AB90: .4byte 0x030044BC
_0823AB94: .4byte 0x0300478C
_0823AB98: .4byte 0x030047C4
_0823AB9C: .4byte 0x030047AC
_0823ABA0: .4byte 0x03003E78
_0823ABA4: .4byte 0xFFFFF1FF
_0823ABA8: .4byte 0x03004460
_0823ABAC:
	ldr r0, _0823ABC4 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0823AC4C
	ldr r1, _0823ABC8 @ =0x030047BC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0823AC4C
	.align 2, 0
_0823ABC4: .4byte 0x030044BC
_0823ABC8: .4byte 0x030047BC
_0823ABCC:
	subs r0, #1
	str r0, [r6, #0x1c]
	cmp r0, #0
	bgt _0823AC4C
	bl FUN_0823aa70
	bl FUN_0823aa74
	ldr r2, _0823AC18 @ =0x030047A4
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0823AC04
	ldr r0, _0823AC1C @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r2]
	ldr r2, _0823AC20 @ =0x030044BC
	ldr r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0823AC04
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_0823AC04:
	ldr r0, _0823AC24 @ =0x03004798
	ldr r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0823AC28
	bl FUN_08231cec
	b _0823AC48
	.align 2, 0
_0823AC18: .4byte 0x030047A4
_0823AC1C: .4byte 0xFFFFFDFF
_0823AC20: .4byte 0x030044BC
_0823AC24: .4byte 0x03004798
_0823AC28:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0823AC48
	bl FUN_08231d24
	ldr r0, _0823ACA0 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl FUN_08231be0
_0823AC48:
	movs r0, #0
	str r0, [r6, #0x18]
_0823AC4C:
	ldr r4, _0823ACA4 @ =0x030047B4
	ldr r0, [r4]
	cmp r0, #0
	beq _0823AC5C
	bl FUN_0823dd50
	movs r0, #0
	str r0, [r4]
_0823AC5C:
	ldr r0, _0823ACA8 @ =0x030047A8
	ldr r2, [r0]
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bhi _0823AC6E
	adds r0, r1, #1
	str r0, [r2]
_0823AC6E:
	ldr r1, _0823ACAC @ =0x03004794
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _0823ACB0 @ =0x03004788
	ldr r0, [r0]
	cmp r0, #0
	beq _0823AC94
	ldr r0, _0823ACA0 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xad
	lsls r1, r1, #2
	adds r2, r0, r1
	ldr r1, [r2]
	ldr r0, _0823ACB4 @ =0x7FFFFFFE
	cmp r1, r0
	bgt _0823AC94
	adds r0, r1, #1
	str r0, [r2]
_0823AC94:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823ACA0: .4byte 0x030046A0
_0823ACA4: .4byte 0x030047B4
_0823ACA8: .4byte 0x030047A8
_0823ACAC: .4byte 0x03004794
_0823ACB0: .4byte 0x03004788
_0823ACB4: .4byte 0x7FFFFFFE

	thumb_func_start FUN_0823acb8
FUN_0823acb8: @ 0x0823ACB8
	bx lr
	.align 2, 0

	thumb_func_start FUN_0823acbc
FUN_0823acbc: @ 0x0823ACBC
	push {r4, r5, lr}
	bl FUN_0823b158
	bl FUN_0823aa84
	bl FUN_0823b130
	bl FUN_082324b0
	ldr r0, _0823AD48 @ =0x030047A4
	movs r5, #0
	str r5, [r0]
	ldr r0, _0823AD4C @ =0x030047A0
	str r5, [r0]
	ldr r0, _0823AD50 @ =0x0300479C
	str r5, [r0]
	ldr r0, _0823AD54 @ =0x030047C0
	str r5, [r0]
	ldr r1, _0823AD58 @ =0x03004798
	ldr r0, _0823AD5C @ =0x0300478C
	str r5, [r0]
	ldr r0, _0823AD60 @ =0x030047C4
	str r5, [r0]
	ldr r0, _0823AD64 @ =0x030047B8
	str r5, [r0]
	ldr r0, _0823AD68 @ =0x030047B0
	str r5, [r0]
	ldr r0, _0823AD6C @ =0x03004790
	str r5, [r0]
	ldr r0, _0823AD70 @ =0x030047BC
	str r5, [r0]
	ldr r0, _0823AD74 @ =0x03004794
	str r5, [r0]
	ldr r0, _0823AD78 @ =0x030047AC
	str r5, [r0]
	ldr r0, _0823AD7C @ =0x03004788
	str r5, [r0]
	ldr r4, _0823AD80 @ =0x030046A0
	ldr r0, [r4]
	ldr r2, _0823AD84 @ =0x00000934
	adds r0, r0, r2
	strh r5, [r0]
	str r5, [r1]
	ldr r0, _0823AD88 @ =0x03004860
	str r5, [r0]
	bl FUN_0823d280
	bl FUN_08237410
	movs r1, #2
	ldr r0, [r4]
	strh r1, [r0, #0x12]
	ldr r4, _0823AD8C @ =0x030016A0
	ldr r1, _0823AD90 @ =FUN_0823aa94
	ldr r2, _0823AD94 @ =FUN_0823acb8
	adds r0, r4, #0
	bl SetEntityRoutine
	movs r0, #1
	strb r0, [r4, #0x14]
	strb r0, [r4, #0x16]
	strh r5, [r4, #0x10]
	adds r0, r4, #0
	bl AddEntity
	str r5, [r4, #0x18]
	str r5, [r4, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823AD48: .4byte 0x030047A4
_0823AD4C: .4byte 0x030047A0
_0823AD50: .4byte 0x0300479C
_0823AD54: .4byte 0x030047C0
_0823AD58: .4byte 0x03004798
_0823AD5C: .4byte 0x0300478C
_0823AD60: .4byte 0x030047C4
_0823AD64: .4byte 0x030047B8
_0823AD68: .4byte 0x030047B0
_0823AD6C: .4byte 0x03004790
_0823AD70: .4byte 0x030047BC
_0823AD74: .4byte 0x03004794
_0823AD78: .4byte 0x030047AC
_0823AD7C: .4byte 0x03004788
_0823AD80: .4byte 0x030046A0
_0823AD84: .4byte 0x00000934
_0823AD88: .4byte 0x03004860
_0823AD8C: .4byte 0x030016A0
_0823AD90: .4byte FUN_0823aa94
_0823AD94: .4byte FUN_0823acb8

	thumb_func_start FUN_0823ad98
FUN_0823ad98: @ 0x0823AD98
	push {lr}
	bl FUN_082316bc
	adds r1, r0, #0
	cmp r1, #0
	bne _0823ADB2
	bl FUN_08231cec
	b _0823ADB8
_0823ADAA:
	adds r0, r1, #0
	bl FUN_08232160
	adds r1, r0, #0
_0823ADB2:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0823ADAA
_0823ADB8:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823adc0
FUN_0823adc0: @ 0x0823ADC0
	push {lr}
	bl FUN_082316bc
	bl FUN_082321e0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823add0
FUN_0823add0: @ 0x0823ADD0
	push {r4, r5, lr}
	bl FUN_082410e8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0823AE04
	ldr r5, _0823AE0C @ =0x030047A8
	ldr r0, [r5]
	cmp r0, #0
	beq _0823ADEC
	movs r1, #0x28
	bl FUN_082309cc
_0823ADEC:
	movs r1, #5
	ldr r0, _0823AE10 @ =0x030046A0
	ldr r0, [r0]
	strh r1, [r0, #0x12]
	movs r1, #0xe6
	ldr r0, [r5]
	str r1, [r0, #4]
	strb r4, [r0, #8]
	ldr r0, [r5]
	strb r4, [r0, #9]
	ldr r0, [r5]
	strb r4, [r0, #0xa]
_0823AE04:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823AE0C: .4byte 0x030047A8
_0823AE10: .4byte 0x030046A0

	thumb_func_start FUN_0823ae14
FUN_0823ae14: @ 0x0823AE14
	push {r4, lr}
	ldr r2, _0823AE48 @ =0x03004798
	movs r1, #0
	str r1, [r2]
	str r1, [r0, #0x1c]
	bl FUN_0823a9c4
	bl FUN_08231c1c
	ldr r0, _0823AE4C @ =0x03002B28
	ldrh r4, [r0]
	cmp r4, #0
	beq _0823AE3A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_082318ac
	cmp r4, #0
	bne _0823AE3E
_0823AE3A:
	bl FUN_08231ba8
_0823AE3E:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823AE48: .4byte 0x03004798
_0823AE4C: .4byte 0x03002B28

