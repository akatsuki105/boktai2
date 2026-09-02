	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08050cb8
FUN_08050cb8: @ 0x08050CB8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D06
	adds r4, r0, #0
	adds r4, #0x3c
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08050D06
	movs r2, #0
	movs r1, #0
_08050CD6:
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	adds r1, #1
	cmp r1, #3
	ble _08050CD6
	cmp r2, #9
	bgt _08050D06
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_08051d18
	adds r0, r4, r5
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #2
	movs r1, #1
	bl FUN_08050e50
	ldr r0, _08050D0C @ =0x00000375
	bl PlaySound_082406e0
_08050D06:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08050D0C: .4byte 0x00000375

	thumb_func_start FUN_08050d10
FUN_08050d10: @ 0x08050D10
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D22
	adds r1, r0, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
_08050D22:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08050d28
FUN_08050d28: @ 0x08050D28
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D3A
	adds r1, r0, #0
	adds r1, #0x2e
	movs r0, #1
	strb r0, [r1]
_08050D3A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08050d40
FUN_08050d40: @ 0x08050D40
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D54
	adds r1, r0, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, #0
	bne _08050D58
_08050D54:
	movs r0, #0
	b _08050D5E
_08050D58:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_08050D5E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08050d64
FUN_08050d64: @ 0x08050D64
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D74
	adds r0, #0x48
	ldrb r0, [r0, #4]
	b _08050D76
_08050D74:
	movs r0, #0
_08050D76:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08050d7c
FUN_08050d7c: @ 0x08050D7C
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050D8C
	adds r0, #0x48
	ldrb r0, [r0, #5]
	b _08050D8E
_08050D8C:
	movs r0, #0
_08050D8E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08050d94
FUN_08050d94: @ 0x08050D94
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050DA4
	adds r0, #0x32
	ldrb r0, [r0]
	b _08050DA6
_08050DA4:
	movs r0, #0
_08050DA6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08050dac
FUN_08050dac: @ 0x08050DAC
	push {r4, lr}
	bl FUN_0804f820
	adds r4, r0, #0
	cmp r4, #0
	beq _08050DE0
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	beq _08050DE0
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050DE0
	adds r4, #0x3c
	ldrb r1, [r4, #6]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r4, #6]
	ldr r0, _08050DDC @ =0x0000010B
	bl PlaySound_082406e0
	ldrb r0, [r4, #6]
	b _08050DE2
	.align 2, 0
_08050DDC: .4byte 0x0000010B
_08050DE0:
	movs r0, #0
_08050DE2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08050de8
FUN_08050de8: @ 0x08050DE8
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050DF6
	ldrh r0, [r0, #0x1e]
	b _08050DF8
_08050DF6:
	movs r0, #0
_08050DF8:
	pop {r1}
	bx r1

	thumb_func_start FUN_08050dfc
FUN_08050dfc: @ 0x08050DFC
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050E0C
	ldrh r0, [r0, #0x1e]
	cmp r0, #0xa
	bhi _08050E10
_08050E0C:
	movs r0, #0
	b _08050E12
_08050E10:
	movs r0, #1
_08050E12:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08050e18
FUN_08050e18: @ 0x08050E18
	ldr r0, _08050E28 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
	orrs r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_08050E28: .4byte 0x030047A4

	thumb_func_start FUN_08050e2c
FUN_08050e2c: @ 0x08050E2C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl FUN_0804f820
	cmp r0, #0
	beq _08050E48
	ldr r0, [r0, #0x64]
	adds r1, r4, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_0805303c
_08050E48:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08050e50
FUN_08050e50: @ 0x08050E50
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_0804f820
	cmp r0, #0
	beq _08050E78
	adds r2, r0, #0
	adds r2, #0xc8
	lsls r1, r4, #1
	movs r3, #0xd7
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r5, r1
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
_08050E78:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08050e80
FUN_08050e80: @ 0x08050E80
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _08050E92
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #5
	beq _08050E96
_08050E92:
	movs r0, #0
	b _08050E98
_08050E96:
	movs r0, #1
_08050E98:
	pop {r1}
	bx r1

	thumb_func_start FUN_08050e9c
FUN_08050e9c: @ 0x08050E9C
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldrh r3, [r2, #0x1e]
	movs r6, #1
	movs r4, #1
	ands r4, r3
	cmp r4, #0
	beq _08050EC0
	ldr r0, _08050EBC @ =0x0000FFFE
	ands r0, r3
	movs r1, #0
	strh r0, [r2, #0x1e]
	movs r0, #3
	b _08050EE6
	.align 2, 0
_08050EBC: .4byte 0x0000FFFE
_08050EC0:
	movs r0, #2
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08050EE0
	ldr r0, _08050EDC @ =0x0000FFFD
	ands r0, r3
	strh r0, [r2, #0x1e]
	movs r0, #4
	strb r0, [r2, #0x1c]
	strb r6, [r2, #0x1d]
	str r4, [r2, #0x18]
	b _08050EF6
	.align 2, 0
_08050EDC: .4byte 0x0000FFFD
_08050EE0:
	cmp r5, #0
	beq _08050EEE
	movs r0, #5
_08050EE6:
	strb r0, [r2, #0x1c]
	strb r6, [r2, #0x1d]
	str r1, [r2, #0x18]
	b _08050EF6
_08050EEE:
	movs r0, #6
	strb r0, [r2, #0x1c]
	strb r6, [r2, #0x1d]
	str r5, [r2, #0x18]
_08050EF6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08050efc
FUN_08050efc: @ 0x08050EFC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08050F2C @ =0x0203B400
	ldr r5, _08050F30 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r4, _08050F34 @ =0x000003FF
	ands r0, r4
	lsls r3, r0, #1
	adds r3, r3, r6
	ldrh r3, [r3]
	ands r3, r2
	adds r1, r1, r3
	adds r0, #1
	ands r0, r4
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08050F38
	strh r1, [r7, #6]
	b _08050F3C
	.align 2, 0
_08050F2C: .4byte 0x0203B400
_08050F30: .4byte 0x030046B8
_08050F34: .4byte 0x000003FF
_08050F38:
	rsbs r0, r1, #0
	strh r0, [r7, #6]
_08050F3C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08050f44
FUN_08050f44: @ 0x08050F44
	push {r4, lr}
	adds r4, r0, #0
	lsls r1, r1, #2
	ldr r3, _08050F64 @ =0x085B0A08
	movs r0, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08050F68
	asrs r1, r0, #0xc
	b _08050F6E
	.align 2, 0
_08050F64: .4byte 0x085B0A08
_08050F68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08050F6E:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08050f80
FUN_08050f80: @ 0x08050F80
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _08050F9C
	movs r0, #0
	strb r0, [r2, #1]
	ldr r0, [r2, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x24]
	ldr r0, [r2, #0x50]
	orrs r0, r1
	str r0, [r2, #0x50]
_08050F9C:
	pop {r0}
	bx r0

	thumb_func_start FUN_08050fa0
FUN_08050fa0: @ 0x08050FA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r1
	mov r8, r2
	ldrb r0, [r1, #1]
	cmp r0, #0
	beq _0805101C
	movs r3, #0
	strb r3, [r1, #1]
	strb r3, [r1, #4]
	mov r7, ip
	adds r7, #0x50
	mov r2, ip
	adds r2, #0x6c
	movs r1, #3
	mov r0, r8
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x50
	strh r0, [r2]
	movs r0, #0x90
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	mov r1, ip
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _08051012
	ldr r6, _080510B0 @ =0x0203B400
	ldr r3, _080510B4 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _080510B8 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldrh r0, [r7, #0x1c]
	subs r0, #1
	movs r4, #3
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ldrh r0, [r7, #0x1e]
	subs r0, #1
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
_08051012:
	mov r2, ip
	ldr r0, [r2, #0x6c]
	ldr r1, [r2, #0x70]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_0805101C:
	mov r1, ip
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _080510BC
	strh r0, [r1, #0x34]
	ldrb r0, [r1, #2]
	mov r7, ip
	adds r7, #0x50
	strh r0, [r7, #0x10]
	ldr r0, [r1, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2, #0x24]
	ldr r0, [r2, #0x50]
	ands r0, r1
	str r0, [r2, #0x50]
	ldrb r0, [r2, #4]
	cmp r0, #0
	beq _080510CE
	subs r0, #1
	strb r0, [r2, #4]
	adds r2, #0x6c
	movs r1, #3
	mov r0, r8
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x50
	strh r0, [r2]
	movs r0, #0x90
	strh r0, [r2, #2]
	movs r0, #0
	strh r0, [r2, #4]
	mov r1, ip
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _080510A2
	ldr r6, _080510B0 @ =0x0203B400
	ldr r3, _080510B4 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _080510B8 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldrh r0, [r7, #0x1c]
	subs r0, #1
	movs r4, #3
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ldrh r0, [r7, #0x1e]
	subs r0, #1
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
_080510A2:
	mov r2, ip
	ldr r0, [r2, #0x6c]
	ldr r1, [r2, #0x70]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
	b _080510CE
	.align 2, 0
_080510B0: .4byte 0x0203B400
_080510B4: .4byte 0x030046B8
_080510B8: .4byte 0x000003FF
_080510BC:
	mov r1, ip
	ldr r0, [r1, #0x24]
	movs r1, #1
	orrs r0, r1
	mov r2, ip
	str r0, [r2, #0x24]
	ldr r0, [r2, #0x50]
	orrs r0, r1
	str r0, [r2, #0x50]
_080510CE:
	mov r1, ip
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080510e0
FUN_080510e0: @ 0x080510E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	adds r5, r1, #0
	mov r8, r2
	adds r7, r5, #0
	adds r7, #0x24
	adds r6, r5, #0
	adds r6, #0x50
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _0805113E
	movs r3, #0
	strb r3, [r5, #1]
	ldrb r0, [r5, #3]
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #2]
	strh r0, [r6, #0x10]
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	ldr r0, [r5, #0x50]
	ands r0, r1
	str r0, [r5, #0x50]
	adds r2, r5, #0
	adds r2, #0x14
	movs r1, #3
	mov r0, r8
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x50
	strh r0, [r5, #0x14]
	movs r0, #0x90
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	adds r0, r5, #0
	movs r1, #0x20
	movs r2, #0xf
	bl FUN_08050efc
_0805113E:
	adds r4, r5, #0
	adds r4, #0x6c
	adds r1, r5, #0
	adds r1, #0xc
	adds r2, r5, #0
	adds r2, #0x14
	ldr r3, [r5, #8]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237970
	ldr r1, [r5, #8]
	movs r0, #6
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	bl FUN_08050f44
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, [r5, #8]
	cmp r0, #0x1f
	bls _0805119C
	movs r0, #3
	mov r1, r8
	ands r0, r1
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, sb
	adds r3, r1, #0
	adds r3, #0xef
	ldrb r0, [r5, #3]
	ldrb r2, [r3]
	adds r0, r0, r2
	movs r2, #0
	strb r0, [r3]
	adds r1, #0xf0
	movs r0, #8
	strb r0, [r1]
	strb r2, [r5, #3]
	strb r2, [r5]
	movs r0, #1
	strb r0, [r5, #1]
	str r2, [r5, #8]
_0805119C:
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080511b0
FUN_080511b0: @ 0x080511B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	adds r6, r1, #0
	adds r3, r2, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r0, #0x50
	adds r0, r0, r6
	mov sl, r0
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _08051236
	movs r2, #0
	strb r2, [r6, #1]
	ldrb r0, [r6, #3]
	movs r1, #0
	mov sb, r1
	strh r0, [r5, #0x10]
	ldrb r0, [r6, #2]
	mov r7, sl
	strh r0, [r7, #0x10]
	ldr r0, [r6, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x24]
	ldr r0, [r6, #0x50]
	ands r0, r1
	str r0, [r6, #0x50]
	adds r1, r6, #0
	adds r1, #0xc
	movs r4, #3
	ands r4, r3
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r3, r0, #3
	adds r0, r3, #0
	adds r0, #0x50
	strh r0, [r6, #0xc]
	movs r0, #0x90
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	adds r1, #8
	movs r7, #0x88
	lsls r7, r7, #1
	adds r0, r3, r7
	strh r0, [r6, #0x14]
	movs r0, #0x20
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	adds r0, r6, #0
	movs r1, #0x20
	movs r2, #0xf
	bl FUN_08050efc
	lsls r0, r4, #5
	subs r0, r0, r4
	lsls r0, r0, #2
	add r0, r8
	adds r0, #0xef
	mov r1, sb
	strb r1, [r0]
_08051236:
	adds r4, r6, #0
	adds r4, #0x6c
	adds r1, r6, #0
	adds r1, #0xc
	adds r2, r6, #0
	adds r2, #0x14
	ldr r3, [r6, #8]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237970
	ldr r1, [r6, #8]
	movs r7, #6
	ldrsh r2, [r6, r7]
	adds r0, r4, #0
	bl FUN_08050f44
	mov r2, sl
	ldr r0, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldr r0, [r6, #8]
	cmp r0, #0x1f
	bls _08051274
	movs r1, #0
	strb r1, [r6]
	movs r0, #1
	strb r0, [r6, #1]
	str r1, [r6, #8]
_08051274:
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805128c
FUN_0805128c: @ 0x0805128C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	adds r5, r1, #0
	mov r8, r2
	adds r6, r5, #0
	adds r6, #0x50
	adds r7, r5, #0
	adds r7, #0x24
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _080512FA
	movs r3, #0
	strb r3, [r5, #1]
	ldrb r0, [r5, #3]
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #2]
	strh r0, [r6, #0x10]
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	ldr r0, [r5, #0x50]
	ands r0, r1
	str r0, [r5, #0x50]
	adds r2, r5, #0
	adds r2, #0xc
	movs r0, #3
	mov r1, r8
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r4, #0x88
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r0, [r5, #0xc]
	movs r0, #0x20
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	adds r2, #8
	adds r1, #0x50
	strh r1, [r5, #0x14]
	movs r0, #0x90
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	adds r0, r5, #0
	movs r1, #0x20
	movs r2, #0xf
	bl FUN_08050efc
_080512FA:
	adds r4, r5, #0
	adds r4, #0x6c
	adds r1, r5, #0
	adds r1, #0xc
	adds r2, r5, #0
	adds r2, #0x14
	ldr r3, [r5, #8]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237970
	ldr r1, [r5, #8]
	movs r0, #6
	ldrsh r2, [r5, r0]
	adds r0, r4, #0
	bl FUN_08050f44
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, [r5, #8]
	cmp r0, #0x1f
	bls _08051358
	movs r2, #0
	strb r2, [r5]
	movs r0, #1
	strb r0, [r5, #1]
	str r2, [r5, #8]
	movs r0, #3
	mov r1, r8
	ands r0, r1
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, sb
	adds r3, r1, #0
	adds r3, #0xef
	ldrb r0, [r5, #3]
	ldrb r4, [r3]
	adds r0, r0, r4
	strb r0, [r3]
	adds r1, #0xf0
	movs r0, #8
	strb r0, [r1]
	strb r2, [r5, #3]
_08051358:
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805136c
FUN_0805136c: @ 0x0805136C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r1, #0
	adds r3, r2, #0
	adds r7, r6, #0
	adds r7, #0x50
	movs r0, #0x24
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _08051478
	movs r2, #0
	strb r2, [r6, #1]
	ldrb r0, [r6, #3]
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r6, #2]
	strh r0, [r7, #0x10]
	ldr r0, [r6, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x24]
	ldr r0, [r6, #0x50]
	ands r0, r1
	str r0, [r6, #0x50]
	adds r5, r6, #0
	adds r5, #0xc
	movs r0, #3
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r3, #0x88
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r0, [r6, #0xc]
	movs r0, #0x20
	strh r0, [r5, #2]
	strh r2, [r5, #4]
	adds r4, r6, #0
	adds r4, #0x14
	adds r1, #0x50
	strh r1, [r6, #0x14]
	movs r0, #0x90
	strh r0, [r4, #2]
	strh r2, [r4, #4]
	adds r0, r6, #0
	movs r1, #0x20
	movs r2, #0xf
	bl FUN_08050efc
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	movs r2, #0x14
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #2
	ldrsh r1, [r5, r3]
	movs r3, #2
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r3, _08051434 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _08051438 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0805143C @ =0x0203B400
	adds r1, r1, r2
	ldrh r2, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #0x10
	movs r1, #0x1f
	ands r2, r1
	adds r0, r0, r2
	lsls r0, r0, #0x18
	adds r4, #8
	asrs r3, r0, #0x18
	ldr r2, _08051440 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08051444
	asrs r0, r0, #0xc
	b _0805144A
	.align 2, 0
_08051434: .4byte 0x030046B8
_08051438: .4byte 0x000003FF
_0805143C: .4byte 0x0203B400
_08051440: .4byte 0x085B0A08
_08051444:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805144A:
	strh r0, [r4]
	ldr r1, _08051468 @ =0x085B0A08
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _0805146C
	asrs r1, r0, #0xc
	b _08051472
	.align 2, 0
_08051468: .4byte 0x085B0A08
_0805146C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08051472:
	movs r0, #0
	strh r1, [r4, #2]
	strh r0, [r4, #4]
_08051478:
	ldr r3, [r6, #8]
	cmp r3, #0x1b
	bhi _080514A2
	adds r4, r7, #0
	adds r4, #0x1c
	adds r1, r6, #0
	adds r1, #0xc
	adds r2, r6, #0
	adds r2, #0x14
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237970
	ldr r1, [r6, #8]
	movs r3, #6
	ldrsh r2, [r6, r3]
	adds r0, r4, #0
	bl FUN_08050f44
	b _080514C2
_080514A2:
	adds r1, r7, #0
	adds r1, #0x1c
	adds r2, r6, #0
	adds r2, #0x1c
	ldrh r0, [r6, #0x1c]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r7, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
_080514C2:
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	mov r3, r8
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldr r0, [r6, #8]
	cmp r0, #0x2b
	bls _080514DC
	movs r1, #0
	strb r1, [r6]
	movs r0, #1
	strb r0, [r6, #1]
	str r1, [r6, #8]
_080514DC:
	ldr r0, [r6, #8]
	adds r0, #1
	str r0, [r6, #8]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080514f0
FUN_080514f0: @ 0x080514F0
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _0805151A
	movs r0, #0
	strb r0, [r2, #1]
	ldrb r0, [r2, #3]
	strh r0, [r2, #0x34]
	ldrb r1, [r2, #2]
	adds r0, r2, #0
	adds r0, #0x50
	strh r1, [r0, #0x10]
	ldr r0, [r2, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x24]
	ldr r0, [r2, #0x50]
	ands r0, r1
	str r0, [r2, #0x50]
_0805151A:
	ldr r0, [r2, #8]
	cmp r0, #0x1f
	bls _0805152A
	movs r1, #0
	strb r1, [r2]
	movs r0, #1
	strb r0, [r2, #1]
	str r1, [r2, #8]
_0805152A:
	ldr r0, [r2, #8]
	adds r0, #1
	str r0, [r2, #8]
	pop {r0}
	bx r0

	thumb_func_start FUN_08051534
FUN_08051534: @ 0x08051534
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r7, r1, #0
	mov sb, r2
	movs r0, #3
	mov r1, sb
	ands r1, r0
	mov sl, r1
	strb r1, [r7, #2]
	movs r0, #0
	strb r0, [r7, #3]
	adds r4, r7, #0
	adds r4, #0x24
	adds r1, r5, #0
	adds r1, #0x50
	ldr r0, _0805159C @ =0x00010011
	mov r8, r0
	adds r0, r4, #0
	mov r2, r8
	bl FUN_0822a470
	movs r6, #0
	strh r6, [r4, #0x10]
	adds r0, r7, #0
	adds r0, #0x2b
	strb r6, [r0]
	adds r4, #0x2c
	adds r5, #0x34
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, r8
	bl FUN_0822a470
	mov r1, sl
	strh r1, [r4, #0x10]
	adds r0, r7, #0
	adds r0, #0x57
	strb r6, [r0]
	mov r0, sb
	cmp r0, #3
	bgt _080515A0
	movs r0, #1
	strb r0, [r7]
	strb r0, [r7, #1]
	movs r1, #0
	str r1, [r7, #8]
	b _080515AA
	.align 2, 0
_0805159C: .4byte 0x00010011
_080515A0:
	strb r6, [r7]
	movs r0, #1
	strb r0, [r7, #1]
	movs r0, #0
	str r0, [r7, #8]
_080515AA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080515b8
FUN_080515b8: @ 0x080515B8
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0822a4e0
	adds r4, #0x50
	adds r0, r4, #0
	bl FUN_0822a4e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080515d4
FUN_080515d4: @ 0x080515D4
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r3, #0
	adds r4, #0x2c
	ldrb r0, [r4]
	cmp r0, #3
	bhi _08051612
	ldr r2, [r3, #0x18]
	movs r0, #7
	ands r2, r0
	cmp r2, #0
	bne _08051612
	ldrb r0, [r4]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r1, r3, r1
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _0805160C
	strb r5, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	str r2, [r1, #8]
_0805160C:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08051612:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08051618
FUN_08051618: @ 0x08051618
	push {r4, lr}
	adds r1, r0, #0
	adds r1, #0xec
	movs r4, #0
	movs r3, #1
	movs r2, #7
_08051624:
	strb r4, [r1, #3]
	ldr r0, [r1, #0x24]
	orrs r0, r3
	str r0, [r1, #0x24]
	ldr r0, [r1, #0x50]
	orrs r0, r3
	str r0, [r1, #0x50]
	subs r2, #1
	adds r1, #0x7c
	cmp r2, #0
	bge _08051624
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08051640
FUN_08051640: @ 0x08051640
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x1d]
	cmp r0, #0
	beq _08051654
	movs r0, #0
	strb r0, [r1, #0x1d]
	adds r0, r1, #0
	bl FUN_08051618
_08051654:
	pop {r0}
	bx r0

	thumb_func_start FUN_08051658
FUN_08051658: @ 0x08051658
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _0805166C
	movs r1, #0
	strb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
_0805166C:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080515d4
	ldr r0, [r4, #0x18]
	cmp r0, #0x4f
	bls _0805168E
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _08051684
	bl _call_via_r0
_08051684:
	movs r1, #0
	strb r1, [r4, #0x1c]
	movs r0, #1
	strb r0, [r4, #0x1d]
	str r1, [r4, #0x18]
_0805168E:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805169c
FUN_0805169c: @ 0x0805169C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080516EE
	movs r1, #0
	strb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r5, #0
	movs r6, #0
	adds r2, r4, #0
	adds r2, #0xec
_080516B8:
	movs r1, #3
	ands r1, r5
	cmp r5, #3
	bgt _080516C6
	strb r1, [r2, #2]
	strb r6, [r2, #3]
	b _080516E6
_080516C6:
	adds r0, r4, #0
	adds r0, #0x24
	adds r0, r0, r1
	adds r3, r2, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2, #2]
	cmp r0, #0xa
	ble _080516DE
	movs r0, #0xa
	b _080516E4
_080516DE:
	cmp r0, #0
	bge _080516E4
	movs r0, #0
_080516E4:
	strb r0, [r3, #3]
_080516E6:
	adds r2, #0x7c
	adds r5, #1
	cmp r5, #7
	ble _080516B8
_080516EE:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080515d4
	ldr r0, [r4, #0x18]
	cmp r0, #0x4f
	bls _08051704
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08050e9c
_08051704:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08051710
FUN_08051710: @ 0x08051710
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0x1d]
	cmp r0, #0
	beq _080517D2
	movs r1, #0
	strb r1, [r6, #0x1d]
	adds r0, r6, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r7, #0
	movs r0, #0x8c
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0x6c
	adds r1, r1, r6
	mov sl, r1
	adds r0, r6, #0
	adds r0, #0x2d
	str r0, [sp]
	movs r1, #3
	mov sb, r1
	movs r0, #0x28
	adds r0, r0, r6
	mov ip, r0
	adds r5, r6, #0
	adds r5, #0xec
_08051750:
	adds r4, r7, #0
	mov r1, sb
	ands r4, r1
	cmp r7, #3
	bgt _08051774
	mov r0, ip
	adds r3, r0, r4
	adds r0, r6, #0
	adds r0, #0x24
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r2, #0
	strb r1, [r3]
	strb r2, [r0]
	movs r0, #0
	strb r4, [r5, #2]
	strb r0, [r5, #3]
	b _080517A4
_08051774:
	mov r1, ip
	adds r0, r1, r4
	adds r1, r5, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r4, [r5, #2]
	cmp r0, #0xa
	ble _0805178A
	movs r0, #0xa
	b _08051790
_0805178A:
	cmp r0, #0
	bge _08051790
	movs r0, #0
_08051790:
	movs r2, #0
	strb r0, [r1, #3]
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _080517A4
	mov r0, sb
	strb r0, [r5]
	movs r0, #1
	strb r0, [r5, #1]
	str r2, [r5, #8]
_080517A4:
	adds r5, #0x7c
	adds r7, #1
	cmp r7, #7
	ble _08051750
	movs r4, #8
	mov r0, r8
	mov r1, sl
	movs r2, #0x31
	movs r3, #0
	bl Sprite_SetSprite
	mov r1, r8
	ldr r0, [r1, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r1, r8
	str r0, [r1, #8]
	ldr r0, [sp]
	strb r4, [r0]
	ldr r0, _0805182C @ =0x00000373
	bl PlaySound_082406e0
_080517D2:
	ldr r0, [r6, #0x18]
	cmp r0, #0x28
	bne _080517FC
	movs r1, #0
	movs r7, #0
	adds r2, r6, #0
	adds r2, #0x28
_080517E0:
	adds r0, r2, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	adds r7, #1
	cmp r7, #3
	ble _080517E0
	cmp r1, #0
	bne _080517FC
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080517FC:
	ldr r0, [r6, #0x18]
	cmp r0, #0x4f
	bls _08051816
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08050e9c
_08051816:
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805182C: .4byte 0x00000373

	thumb_func_start FUN_08051830
FUN_08051830: @ 0x08051830
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _08051870
	movs r1, #0
	strb r1, [r5, #0x1d]
	adds r0, r5, #0
	adds r0, #0x2c
	strb r1, [r0]
	adds r4, r5, #0
	adds r4, #0x8c
	adds r1, r5, #0
	adds r1, #0x6c
	adds r0, r4, #0
	movs r2, #0x32
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #8
	strb r0, [r1]
	movs r0, #0xf6
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08051870:
	ldr r0, [r5, #0x18]
	cmp r0, #0x4f
	bls _0805188A
	adds r0, r5, #0
	adds r0, #0x8c
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08050e9c
_0805188A:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08051898
FUN_08051898: @ 0x08051898
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _08051920
	movs r1, #0
	strb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r5, #0
	movs r6, #3
	movs r7, #0
	adds r2, r4, #0
	adds r2, #0xec
_080518B6:
	adds r1, r5, #0
	ands r1, r6
	cmp r5, #3
	bgt _080518E0
	adds r0, r4, #0
	adds r0, #0x24
	adds r0, r0, r1
	adds r3, r2, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2, #2]
	cmp r0, #0xa
	ble _080518D6
	movs r0, #0xa
	b _080518DC
_080518D6:
	cmp r0, #0
	bge _080518DC
	movs r0, #0
_080518DC:
	strb r0, [r3, #3]
	b _08051918
_080518E0:
	adds r0, r4, #0
	adds r0, #0x20
	adds r0, r0, r1
	adds r3, r2, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2, #2]
	cmp r0, #0xa
	ble _080518F8
	movs r0, #0xa
	b _080518FE
_080518F8:
	cmp r0, #0
	bge _080518FE
	movs r0, #0
_080518FE:
	strb r0, [r3, #3]
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r0, #0x88
	lsls r0, r0, #1
	adds r1, r1, r0
	strh r1, [r2, #0xc]
	movs r0, #0x20
	strh r0, [r2, #0xe]
	strh r7, [r2, #0x10]
_08051918:
	adds r2, #0x7c
	adds r5, #1
	cmp r5, #7
	ble _080518B6
_08051920:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080515d4
	ldr r0, [r4, #0x18]
	cmp r0, #0x59
	bls _08051942
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _08051938
	bl _call_via_r0
_08051938:
	movs r1, #0
	strb r1, [r4, #0x1c]
	movs r0, #1
	strb r0, [r4, #0x1d]
	str r1, [r4, #0x18]
_08051942:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08051950
FUN_08051950: @ 0x08051950
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080519A2
	movs r1, #0
	strb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r5, #0
	movs r6, #0
	adds r2, r4, #0
	adds r2, #0xec
_0805196C:
	movs r1, #3
	ands r1, r5
	cmp r5, #3
	bgt _08051996
	adds r0, r4, #0
	adds r0, #0x24
	adds r0, r0, r1
	adds r3, r2, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2, #2]
	cmp r0, #0xa
	ble _0805198C
	movs r0, #0xa
	b _08051992
_0805198C:
	cmp r0, #0
	bge _08051992
	movs r0, #0
_08051992:
	strb r0, [r3, #3]
	b _0805199A
_08051996:
	strb r1, [r2, #2]
	strb r6, [r2, #3]
_0805199A:
	adds r2, #0x7c
	adds r5, #1
	cmp r5, #7
	ble _0805196C
_080519A2:
	ldr r0, [r4, #0x18]
	cmp r0, #0x59
	bls _080519BC
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _080519B2
	bl _call_via_r0
_080519B2:
	movs r1, #0
	strb r1, [r4, #0x1c]
	movs r0, #1
	strb r0, [r4, #0x1d]
	str r1, [r4, #0x18]
_080519BC:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080519c8
FUN_080519c8: @ 0x080519C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl FUN_0804e59c
	cmp r0, #0
	bne _08051A56
	ldr r0, _08051A64 @ =0x085AB6F0
	ldrb r1, [r6, #0x1c]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r6, #0
	bl _call_via_r1
	adds r4, r6, #0
	adds r4, #0xec
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x2d
	ldr r0, _08051A68 @ =0x085AB6D4
	mov r8, r0
_080519F6:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, r8
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	adds r5, #1
	adds r4, #0x7c
	cmp r5, #7
	ble _080519F6
	ldrb r0, [r7]
	cmp r0, #0
	beq _08051A56
	adds r6, #0xac
	subs r0, #1
	movs r1, #0
	strb r0, [r7]
	strh r1, [r6]
	movs r0, #0x40
	strh r0, [r6, #2]
	ldrb r0, [r7]
	cmp r0, #0
	beq _08051A56
	ldr r5, _08051A6C @ =0x0203B400
	ldr r4, _08051A70 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r2, _08051A74 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #3
	ands r1, r3
	subs r1, #2
	strh r1, [r6]
	adds r0, #1
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x3e
	strh r0, [r6, #2]
_08051A56:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08051A64: .4byte 0x085AB6F0
_08051A68: .4byte 0x085AB6D4
_08051A6C: .4byte 0x0203B400
_08051A70: .4byte 0x030046B8
_08051A74: .4byte 0x000003FF

	thumb_func_start FUN_08051a78
FUN_08051a78: @ 0x08051A78
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0xec
	movs r4, #0
_08051A82:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080515b8
	adds r4, #1
	adds r5, #0x7c
	cmp r4, #7
	ble _08051A82
	adds r0, r6, #0
	adds r0, #0x8c
	bl FUN_0822f1c0
	ldr r1, _08051AA8 @ =0x03000118
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08051AA8: .4byte 0x03000118

	thumb_func_start FUN_08051aac
FUN_08051aac: @ 0x08051AAC
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _08051B04 @ =0x03000118
	str r6, [r0]
	ldr r0, _08051B08 @ =0x0000CB05
	ldr r1, _08051B0C @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _08051AFE
	adds r1, r6, #0
	adds r1, #0x6c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r5, r6, #0
	adds r5, #0x6c
	adds r0, r5, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	adds r0, r6, #0
	adds r0, #0x34
	ldr r1, _08051B10 @ =0x000018A8
	bl Video_GetActorSprite
	cmp r0, #0
	beq _08051AFE
	adds r0, r6, #0
	adds r0, #0x50
	ldr r1, _08051B14 @ =0x000018A9
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08051B18
_08051AFE:
	movs r0, #1
	rsbs r0, r0, #0
	b _08051B62
	.align 2, 0
_08051B04: .4byte 0x03000118
_08051B08: .4byte 0x0000CB05
_08051B0C: .4byte 0x0000DCC1
_08051B10: .4byte 0x000018A8
_08051B14: .4byte 0x000018A9
_08051B18:
	ldr r1, _08051B6C @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0xf
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r0, r6, #0
	adds r0, #0x8c
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0x31
	movs r3, #0x11
	bl FUN_0822f3fc
	strb r4, [r6, #0x1c]
	movs r0, #1
	strb r0, [r6, #0x1d]
	str r4, [r6, #0x18]
	adds r5, r6, #0
	adds r5, #0xec
_08051B4E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08051534
	adds r4, #1
	adds r5, #0x7c
	cmp r4, #7
	ble _08051B4E
	movs r0, #0
_08051B62:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08051B6C: .4byte 0xFFFF0000

@ EntityAF33 の子
	thumb_func_start FUN_08051b70
FUN_08051b70: @ 0x08051B70
	push {r4, lr}
	ldr r1, _08051B9C @ =0x000004CC
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08051BA8
	ldr r1, _08051BA0 @ =FUN_080519c8
	ldr r2, _08051BA4 @ =FUN_08051a78
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08051aac
	cmp r0, #0
	bge _08051BA8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08051BAA
	.align 2, 0
_08051B9C: .4byte 0x000004CC
_08051BA0: .4byte FUN_080519c8
_08051BA4: .4byte FUN_08051a78
_08051BA8:
	adds r0, r4, #0
_08051BAA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08051bb0
FUN_08051bb0: @ 0x08051BB0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0
	mov r8, r1
	ldr r0, _08051BCC @ =0x03000118
	ldr r4, [r0]
	cmp r4, #0
	bne _08051BD0
	movs r0, #1
	rsbs r0, r0, #0
	b _08051C44
	.align 2, 0
_08051BCC: .4byte 0x03000118
_08051BD0:
	str r2, [r4, #0x30]
	movs r0, #0
	strh r0, [r4, #0x1e]
	movs r3, #0
	movs r0, #0x20
	adds r0, r0, r4
	mov ip, r0
	mov sb, ip
	movs r2, #0
	adds r6, r4, #0
	adds r6, #0x24
	adds r5, r4, #0
	adds r5, #0x28
_08051BEA:
	mov r7, sb
	adds r1, r7, r3
	mov r7, r8
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r6, r3
	strb r2, [r0]
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	cmp r3, #3
	ble _08051BEA
	movs r3, #4
	movs r6, #3
	mov r5, ip
	ldr r0, _08051C24 @ =0x000002DE
	adds r2, r4, r0
_08051C0E:
	adds r1, r3, #0
	ands r1, r6
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2]
	cmp r0, #0xa
	ble _08051C28
	movs r0, #0xa
	b _08051C2E
	.align 2, 0
_08051C24: .4byte 0x000002DE
_08051C28:
	cmp r0, #0
	bge _08051C2E
	movs r0, #0
_08051C2E:
	strb r0, [r2, #1]
	adds r2, #0x7c
	adds r3, #1
	cmp r3, #7
	ble _08051C0E
	movs r1, #0
	movs r0, #1
	strb r0, [r4, #0x1c]
	strb r0, [r4, #0x1d]
	str r1, [r4, #0x18]
	movs r0, #0
_08051C44:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08051c50
FUN_08051c50: @ 0x08051C50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0
	mov ip, r1
	adds r7, r2, #0
	ldr r0, _08051C70 @ =0x03000118
	ldr r4, [r0]
	cmp r4, #0
	bne _08051C74
	movs r0, #1
	rsbs r0, r0, #0
	b _08051D08
	.align 2, 0
_08051C70: .4byte 0x03000118
_08051C74:
	str r3, [r4, #0x30]
	movs r0, #0
	strh r0, [r4, #0x1e]
	mov r1, ip
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq _08051C86
	movs r0, #1
	strh r0, [r4, #0x1e]
_08051C86:
	ldrb r0, [r7, #6]
	cmp r0, #0
	beq _08051C94
	ldrh r0, [r4, #0x1e]
	movs r1, #2
	orrs r0, r1
	strh r0, [r4, #0x1e]
_08051C94:
	movs r3, #0
	movs r6, #0x20
	adds r6, r6, r4
	mov r8, r6
	mov sl, r8
	mov sb, r3
	adds r5, r4, #0
	adds r5, #0x24
	adds r2, r4, #0
	adds r2, #0x28
_08051CA8:
	mov r0, sl
	adds r1, r0, r3
	mov r6, ip
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r5, r3
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, r3
	mov r1, sb
	strb r1, [r0]
	adds r3, #1
	cmp r3, #3
	ble _08051CA8
	movs r3, #4
	movs r6, #3
	mov r5, r8
	ldr r0, _08051CE8 @ =0x000002DE
	adds r2, r4, r0
_08051CD2:
	adds r1, r3, #0
	ands r1, r6
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2]
	cmp r0, #0xa
	ble _08051CEC
	movs r0, #0xa
	b _08051CF2
	.align 2, 0
_08051CE8: .4byte 0x000002DE
_08051CEC:
	cmp r0, #0
	bge _08051CF2
	movs r0, #0
_08051CF2:
	strb r0, [r2, #1]
	adds r2, #0x7c
	adds r3, #1
	cmp r3, #7
	ble _08051CD2
	movs r0, #0
	movs r1, #2
	strb r1, [r4, #0x1c]
	movs r1, #1
	strb r1, [r4, #0x1d]
	str r0, [r4, #0x18]
_08051D08:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08051d18
FUN_08051d18: @ 0x08051D18
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	ldr r0, _08051D30 @ =0x03000118
	ldr r2, [r0]
	cmp r2, #0
	bne _08051D34
	movs r0, #1
	rsbs r0, r0, #0
	b _08051DF2
	.align 2, 0
_08051D30: .4byte 0x03000118
_08051D34:
	lsls r0, r4, #5
	subs r0, r0, r4
	lsls r5, r0, #2
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r3, r2, r0
	ldrb r1, [r3, #3]
	cmp r1, #0
	beq _08051D56
	adds r0, r2, r5
	adds r0, #0xef
	ldrb r2, [r0]
	adds r1, r1, r2
	movs r2, #0
	strb r1, [r0]
	strb r2, [r3, #3]
_08051D56:
	adds r2, r7, #0
	strb r4, [r3, #2]
	cmp r2, #0xa
	ble _08051D62
	movs r2, #0xa
	b _08051D68
_08051D62:
	cmp r2, #0
	bge _08051D68
	movs r2, #0
_08051D68:
	movs r1, #0
	strb r2, [r3, #3]
	movs r0, #2
	strb r0, [r3]
	movs r0, #1
	strb r0, [r3, #1]
	str r1, [r3, #8]
	adds r5, r3, #0
	adds r5, #0xc
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08051D96
	asrs r0, r0, #8
	b _08051D9C
_08051D96:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08051D9C:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08051DAE
	asrs r0, r0, #8
	b _08051DB4
_08051DAE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08051DB4:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08051DC8
	asrs r0, r0, #8
	b _08051DCE
_08051DC8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08051DCE:
	subs r2, r4, r0
	strh r2, [r5, #2]
	adds r4, r4, r0
	strh r4, [r5, #4]
	ldr r3, _08051DF8 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	movs r0, #0
_08051DF2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08051DF8: .4byte 0x030047C8

	thumb_func_start FUN_08051dfc
FUN_08051dfc: @ 0x08051DFC
	push {r4, lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x1d]
	cmp r0, #0
	beq _08051E20
	movs r0, #0
	strb r0, [r3, #0x1d]
	adds r1, r3, #0
	adds r1, #0x40
	movs r4, #1
	movs r2, #3
_08051E12:
	ldr r0, [r1, #8]
	orrs r0, r4
	str r0, [r1, #8]
	subs r2, #1
	adds r1, #0x60
	cmp r2, #0
	bge _08051E12
_08051E20:
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _08051E2A
	movs r0, #0
	strb r0, [r3, #0x1e]
_08051E2A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08051e30
FUN_08051e30: @ 0x08051E30
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _08051E5A
	movs r0, #0
	strb r0, [r5, #0x1d]
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x45
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_08051E5A:
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08051E6E
	movs r1, #0
	strb r1, [r5, #0x1e]
	strb r1, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r1, [r5, #0x18]
	b _08051E74
_08051E6E:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
_08051E74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08051e7c
FUN_08051e7c: @ 0x08051E7C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _08051EA6
	movs r0, #0
	strb r0, [r5, #0x1d]
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x44
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_08051EA6:
	ldr r1, [r5, #0x18]
	movs r0, #0x7f
	ands r1, r0
	cmp r1, #0x3f
	bne _08051EC4
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x43
	movs r3, #0
	bl Sprite_SetSprite
	b _08051EDA
_08051EC4:
	cmp r1, #0x7f
	bne _08051EDA
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x44
	movs r3, #0
	bl Sprite_SetSprite
_08051EDA:
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08051EEE
	movs r1, #0
	strb r1, [r5, #0x1e]
	strb r1, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r1, [r5, #0x18]
	b _08051EF4
_08051EEE:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
_08051EF4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08051efc
FUN_08051efc: @ 0x08051EFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldrb r0, [r7, #0x1d]
	cmp r0, #0
	beq _08051FBC
	movs r0, #0
	strb r0, [r7, #0x1d]
	bl FUN_08050de8
	adds r5, r0, #0
	cmp r5, #1
	bne _08051F1E
	ldr r0, _08051FB0 @ =0x000002C2
	bl PlaySound_082406e0
_08051F1E:
	adds r6, r7, #0
	adds r6, #0x40
	adds r4, r7, #0
	adds r4, #0x20
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0x26
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r6, #8]
	adds r6, #0x60
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r2, r0, #0
	adds r2, #0x27
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r6, #8]
	mov r1, r8
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r7, r0
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	adds r2, #0x27
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r6, #8]
	mov r1, r8
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x10
	strh r0, [r6, #0x20]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r6, r7, r0
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0x4b
	movs r3, #0
	bl Sprite_SetSprite
	bl FUN_08050dfc
	cmp r0, #0
	beq _08051FB4
	ldr r0, [r6, #8]
	mov r1, r8
	ands r0, r1
	b _08051FBA
	.align 2, 0
_08051FB0: .4byte 0x000002C2
_08051FB4:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
_08051FBA:
	str r0, [r6, #8]
_08051FBC:
	ldr r0, [r7, #0x18]
	cmp r0, #0x5a
	bne _08052006
	adds r6, r7, #0
	adds r6, #0x40
	adds r1, r7, #0
	adds r1, #0x20
	adds r0, r6, #0
	movs r2, #0x24
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	adds r6, #0x60
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r7, r0
	ldr r0, [r6, #8]
	orrs r0, r1
	str r0, [r6, #8]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r6, r7, r0
	ldr r0, [r6, #8]
	orrs r0, r1
	str r0, [r6, #8]
	ldr r0, _08052064 @ =0x000002C3
	bl PlaySound_082406e0
_08052006:
	ldr r0, [r7, #0x18]
	subs r0, #0x5a
	cmp r0, #7
	bhi _08052040
	adds r6, r7, #0
	adds r6, #0x40
	ldr r5, _08052068 @ =0x0203B400
	ldr r2, _0805206C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _08052070 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #3
	ands r1, r3
	subs r1, #2
	strh r1, [r6, #0x20]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #2
	strh r0, [r6, #0x22]
_08052040:
	ldr r0, [r7, #0x18]
	cmp r0, #0x62
	bne _08052050
	adds r6, r7, #0
	adds r6, #0x40
	movs r0, #0
	strh r0, [r6, #0x20]
	strh r0, [r6, #0x22]
_08052050:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _08052074
	movs r1, #0
	strb r1, [r7, #0x1e]
	strb r1, [r7, #0x1c]
	movs r0, #1
	strb r0, [r7, #0x1d]
	str r1, [r7, #0x18]
	b _0805207A
	.align 2, 0
_08052064: .4byte 0x000002C3
_08052068: .4byte 0x0203B400
_0805206C: .4byte 0x030046B8
_08052070: .4byte 0x000003FF
_08052074:
	ldr r0, [r7, #0x18]
	adds r0, #1
	str r0, [r7, #0x18]
_0805207A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08052084
FUN_08052084: @ 0x08052084
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x1d]
	cmp r0, #0
	beq _080520B4
	movs r0, #0
	strb r0, [r6, #0x1d]
	adds r7, r6, #0
	adds r7, #0x40
	adds r1, r6, #0
	adds r1, #0x20
	adds r0, r7, #0
	movs r2, #0x24
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #8]
	ldr r0, _08052110 @ =0x000002C3
	bl PlaySound_082406e0
_080520B4:
	ldr r0, [r6, #0x18]
	cmp r0, #7
	bhi _080520EC
	adds r7, r6, #0
	adds r7, #0x40
	ldr r5, _08052114 @ =0x0203B400
	ldr r2, _08052118 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _0805211C @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #3
	ands r1, r3
	subs r1, #2
	strh r1, [r7, #0x20]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #2
	strh r0, [r7, #0x22]
_080520EC:
	ldr r0, [r6, #0x18]
	cmp r0, #8
	bne _080520FC
	adds r7, r6, #0
	adds r7, #0x40
	movs r0, #0
	strh r0, [r7, #0x20]
	strh r0, [r7, #0x22]
_080520FC:
	ldrb r0, [r6, #0x1e]
	cmp r0, #0
	beq _08052120
	movs r1, #0
	strb r1, [r6, #0x1e]
	strb r1, [r6, #0x1c]
	movs r0, #1
	strb r0, [r6, #0x1d]
	str r1, [r6, #0x18]
	b _08052126
	.align 2, 0
_08052110: .4byte 0x000002C3
_08052114: .4byte 0x0203B400
_08052118: .4byte 0x030046B8
_0805211C: .4byte 0x000003FF
_08052120:
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
_08052126:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805212c
FUN_0805212c: @ 0x0805212C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _0805215E
	movs r0, #0
	strb r0, [r5, #0x1d]
	adds r4, r5, #0
	adds r4, #0x40
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r4, #0
	movs r2, #0x25
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r0, #0xa5
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0805215E:
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08052172
	movs r1, #0
	strb r1, [r5, #0x1e]
	strb r1, [r5, #0x1c]
	movs r0, #1
	strb r0, [r5, #0x1d]
	str r1, [r5, #0x18]
	b _08052178
_08052172:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
_08052178:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08052180
FUN_08052180: @ 0x08052180
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804e59c
	cmp r0, #0
	bne _0805219C
	ldr r0, _080521A4 @ =0x085AB70C
	ldrb r1, [r4, #0x1c]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0805219C:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080521A4: .4byte 0x085AB70C

	thumb_func_start FUN_080521a8
FUN_080521a8: @ 0x080521A8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #3
_080521B0:
	adds r0, r4, #0
	bl FUN_0822f1c0
	subs r5, #1
	adds r4, #0x60
	cmp r5, #0
	bge _080521B0
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080521c8
FUN_080521c8: @ 0x080521C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080521E8 @ =0x0000CB05
	ldr r1, _080521EC @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _080521F0
	movs r0, #1
	rsbs r0, r0, #0
	b _08052244
	.align 2, 0
_080521E8: .4byte 0x0000CB05
_080521EC: .4byte 0x0000DCC1
_080521F0:
	adds r0, r6, #0
	adds r0, #0x20
	adds r1, r2, #0
	ldm r1!, {r3, r4, r5}
	stm r0!, {r3, r4, r5}
	ldm r1!, {r3, r4, r5}
	stm r0!, {r3, r4, r5}
	ldm r1!, {r3, r4}
	stm r0!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x20
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	adds r5, r6, #0
	adds r5, #0x40
	mov r8, r4
	movs r7, #0
	movs r4, #3
_08052218:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0x43
	movs r3, #0x11
	bl FUN_0822f3fc
	subs r4, #1
	adds r5, #0x60
	cmp r4, #0
	bge _08052218
	movs r1, #0
	strb r1, [r6, #0x1c]
	movs r0, #1
	strb r0, [r6, #0x1d]
	str r1, [r6, #0x18]
	strb r1, [r6, #0x1e]
	movs r0, #0
_08052244:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

@ EntityAF33 の子
	thumb_func_start FUN_08052250
FUN_08052250: @ 0x08052250
	push {r4, lr}
	movs r1, #0xe0
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08052288
	ldr r1, _08052280 @ =FUN_08052180
	ldr r2, _08052284 @ =FUN_080521a8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080521c8
	cmp r0, #0
	bge _08052288
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805228A
	.align 2, 0
_08052280: .4byte FUN_08052180
_08052284: .4byte FUN_080521a8
_08052288:
	adds r0, r4, #0
_0805228A:
	pop {r4}
	pop {r1}
	bx r1

