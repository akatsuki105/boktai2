	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804f820
FUN_0804f820: @ 0x0804F820
	ldr r0, _0804F828 @ =0x030000F0
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0804F828: .4byte 0x030000F0

	thumb_func_start FUN_0804f82c
FUN_0804f82c: @ 0x0804F82C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0804f820
	adds r5, r0, #0
	cmp r5, #0
	beq _0804F8E4
	adds r3, r5, #0
	adds r3, #0x48
	ldrb r0, [r4, #1]
	cmp r0, #5
	bhi _0804F8E4
	lsls r0, r0, #2
	ldr r1, _0804F850 @ =_0804F854
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F850: .4byte _0804F854
_0804F854: @ jump table
	.4byte _0804F86C @ case 0
	.4byte _0804F878 @ case 1
	.4byte _0804F87C @ case 2
	.4byte _0804F8A2 @ case 3
	.4byte _0804F8A6 @ case 4
	.4byte _0804F8C6 @ case 5
_0804F86C:
	ldr r0, [r4, #4]
	strb r0, [r3, #4]
	ldr r0, [r4, #4]
	lsrs r0, r0, #8
	strb r0, [r3, #5]
	b _0804F8E4
_0804F878:
	movs r1, #2
	b _0804F8DE
_0804F87C:
	movs r6, #0
	ldrh r0, [r4, #6]
	movs r1, #1
	ands r0, r1
	strb r0, [r3, #6]
	ldrh r4, [r4, #4]
	movs r2, #0
	movs r7, #0xf
_0804F88C:
	adds r1, r3, r2
	adds r0, r4, #0
	asrs r0, r6
	ands r0, r7
	strb r0, [r1]
	adds r2, #1
	adds r6, #4
	cmp r2, #3
	ble _0804F88C
	movs r1, #8
	b _0804F8DE
_0804F8A2:
	movs r1, #0x20
	b _0804F8DE
_0804F8A6:
	ldrh r0, [r4, #4]
	str r0, [r3, #8]
	ldrh r0, [r4, #6]
	movs r1, #3
	ands r0, r1
	movs r1, #0
	strb r0, [r3, #7]
	cmp r0, #1
	bne _0804F8BC
	strb r1, [r3, #5]
	b _0804F8C2
_0804F8BC:
	cmp r0, #2
	bne _0804F8C2
	strb r1, [r3, #4]
_0804F8C2:
	movs r1, #0x80
	b _0804F8DE
_0804F8C6:
	bl FUN_0804e458
	cmp r0, #0
	bne _0804F8DA
	ldr r0, [r4, #4]
	movs r1, #3
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x2f
	strb r0, [r1]
_0804F8DA:
	movs r1, #0x80
	lsls r1, r1, #2
_0804F8DE:
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
_0804F8E4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804f8ec
FUN_0804f8ec: @ 0x0804F8EC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804f820
	adds r2, r0, #0
	cmp r2, #0
	beq _0804F94A
	ldrb r0, [r4, #1]
	cmp r0, #5
	bhi _0804F942
	lsls r0, r0, #2
	ldr r1, _0804F90C @ =_0804F910
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F90C: .4byte _0804F910
_0804F910: @ jump table
	.4byte _0804F942 @ case 0
	.4byte _0804F928 @ case 1
	.4byte _0804F92C @ case 2
	.4byte _0804F930 @ case 3
	.4byte _0804F934 @ case 4
	.4byte _0804F938 @ case 5
_0804F928:
	movs r1, #1
	b _0804F93C
_0804F92C:
	movs r1, #4
	b _0804F93C
_0804F930:
	movs r1, #0x10
	b _0804F93C
_0804F934:
	movs r1, #0x40
	b _0804F93C
_0804F938:
	movs r1, #0x80
	lsls r1, r1, #1
_0804F93C:
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
_0804F942:
	adds r1, r2, #0
	adds r1, #0x2b
	movs r0, #1
	strb r0, [r1]
_0804F94A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804f950
FUN_0804f950: @ 0x0804F950
	push {lr}
	bl FUN_0804f820
	adds r1, r0, #0
	cmp r1, #0
	beq _0804F96C
	adds r0, #0x55
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804F96C
	adds r0, r1, #0
	adds r0, #0x54
	bl FUN_0804e514
_0804F96C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0804f970
FUN_0804f970: @ 0x0804F970
	push {lr}
	bl FUN_0804f820
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804f97c
FUN_0804f97c: @ 0x0804F97C
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	adds r7, r1, #0
	adds r7, #0x3c
	adds r4, r1, #0
	adds r4, #0x48
	movs r3, #0
	ldrb r0, [r7, #6]
	cmp r0, #0
	beq _0804F9B8
	movs r2, #0
	adds r5, r1, #0
	adds r5, #0x38
	adds r1, r5, #0
	movs r6, #0
_0804F99A:
	adds r0, r1, r2
	strb r6, [r0]
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r3, r3, r0
	adds r2, #1
	cmp r2, #3
	ble _0804F99A
	cmp r3, #0
	ble _0804F9CE
	movs r0, #3
	movs r1, #1
	bl FUN_08050e50
	b _0804F9CE
_0804F9B8:
	movs r2, #0
	adds r5, r1, #0
	adds r5, #0x38
	adds r3, r5, #0
_0804F9C0:
	adds r0, r3, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #3
	ble _0804F9C0
_0804F9CE:
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _0804F9EC
	movs r2, #0
	adds r3, r5, #0
_0804F9D8:
	adds r1, r3, r2
	adds r0, r7, r2
	ldrb r0, [r0]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	adds r2, #1
	cmp r2, #3
	ble _0804F9D8
	b _0804F9F4
_0804F9EC:
	movs r2, #3
_0804F9EE:
	subs r2, #1
	cmp r2, #0
	bge _0804F9EE
_0804F9F4:
	movs r2, #3
_0804F9F6:
	subs r2, #1
	cmp r2, #0
	bge _0804F9F6
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804fa04
FUN_0804fa04: @ 0x0804FA04
	push {lr}
	adds r1, r0, #0
	adds r3, r1, #0
	adds r3, #0x3c
	adds r2, r1, #0
	adds r2, #0x48
	ldrb r0, [r3, #6]
	cmp r0, #0
	bne _0804FA2E
	ldrb r0, [r2, #6]
	cmp r0, #0
	bne _0804FA28
	ldr r0, [r1, #0x3c]
	cmp r0, #0
	bne _0804FA28
	ldr r0, [r1, #0x48]
	cmp r0, #0
	beq _0804FA3E
_0804FA28:
	ldrb r0, [r3, #6]
	cmp r0, #0
	beq _0804FA3A
_0804FA2E:
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804FA3A
	subs r0, #1
	strb r0, [r1]
_0804FA3A:
	movs r0, #1
	b _0804FA40
_0804FA3E:
	movs r0, #0
_0804FA40:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804fa44
FUN_0804fa44: @ 0x0804FA44
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x54
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804FA60
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0804FA60
	movs r0, #1
	rsbs r0, r0, #0
	b _0804FA8E
_0804FA60:
	strb r1, [r4, #1]
	cmp r3, #0
	ble _0804FA72
	adds r1, r4, #4
_0804FA68:
	ldm r2!, {r0}
	stm r1!, {r0}
	subs r3, #1
	cmp r3, #0
	bne _0804FA68
_0804FA72:
	adds r0, r4, #0
	bl FUN_0804e514
	adds r2, r0, #0
	cmp r2, #0
	bge _0804FA8C
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0804FA8C
	adds r1, r5, #0
	adds r1, #0x2a
	movs r0, #1
	strb r0, [r1]
_0804FA8C:
	adds r0, r2, #0
_0804FA8E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804fa94
FUN_0804fa94: @ 0x0804FA94
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r5, #0x3c
	adds r4, r0, #0
	adds r4, #0x48
	ldrb r0, [r5, #7]
	cmp r0, #0
	bne _0804FAB0
	ldrb r0, [r4, #7]
	cmp r0, #1
	beq _0804FAFA
	cmp r0, #2
	beq _0804FACC
	b _0804FAF6
_0804FAB0:
	cmp r0, #1
	bne _0804FAD8
	ldrb r0, [r4, #7]
	cmp r0, #1
	bne _0804FAC8
	ldr r1, [r5, #8]
	ldr r0, [r4, #8]
	cmp r1, r0
	blo _0804FAD4
	cmp r1, r0
	bhi _0804FAFA
	b _0804FAF6
_0804FAC8:
	cmp r0, #2
	bne _0804FAD4
_0804FACC:
	movs r0, #1
	movs r1, #1
	bl FUN_08050e50
_0804FAD4:
	movs r0, #0
	b _0804FAFC
_0804FAD8:
	ldrb r0, [r4, #7]
	cmp r0, #1
	beq _0804FAFA
	cmp r0, #2
	bne _0804FAFA
	movs r0, #1
	movs r1, #1
	bl FUN_08050e50
	ldr r1, [r5, #8]
	ldr r0, [r4, #8]
	cmp r1, r0
	blo _0804FAFA
	cmp r1, r0
	bhi _0804FAD4
_0804FAF6:
	movs r0, #2
	b _0804FAFC
_0804FAFA:
	movs r0, #1
_0804FAFC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804fb04
FUN_0804fb04: @ 0x0804FB04
	push {lr}
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #2
	adds r2, #0x3c
	adds r1, r0, r2
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	adds r0, r1, #3
_0804FB18:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _0804FB18
	pop {r0}
	bx r0

	thumb_func_start FUN_0804fb24
FUN_0804fb24: @ 0x0804FB24
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _0804FB36
	adds r1, r0, #0
	adds r1, #0x33
	movs r0, #1
	strb r0, [r1]
_0804FB36:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804fb3c
FUN_0804fb3c: @ 0x0804FB3C
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x3c
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804FB50
	movs r0, #2
	b _0804FB5C
_0804FB50:
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804FB5C
	movs r0, #1
_0804FB5C:
	strb r0, [r2, #7]
	ldrh r1, [r1, #0x1c]
	movs r0, #0xb4
	lsls r0, r0, #2
	subs r0, r0, r1
	str r0, [r2, #8]
	pop {r0}
	bx r0

	thumb_func_start FUN_0804fb6c
FUN_0804fb6c: @ 0x0804FB6C
	push {r4, lr}
	sub sp, #0x10
	str r1, [sp, #0xc]
	ldr r0, _0804FBBC @ =0x0000C091
	ldr r1, _0804FBC0 @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804FBC4 @ =0x000092B3
	ldr r1, _0804FBC8 @ =0x0000EFDA
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804FBCC @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804FBBC: .4byte 0x0000C091
_0804FBC0: .4byte 0x0000A413
_0804FBC4: .4byte 0x000092B3
_0804FBC8: .4byte 0x0000EFDA
_0804FBCC: .4byte 0x03004250

	thumb_func_start FUN_0804fbd0
FUN_0804fbd0: @ 0x0804FBD0
	push {lr}
	ldr r0, [r0, #0x60]
	cmp r0, #0
	beq _0804FBDC
	bl FUN_08052290
_0804FBDC:
	pop {r0}
	bx r0

	thumb_func_start FUN_0804fbe0
FUN_0804fbe0: @ 0x0804FBE0
	push {lr}
	ldr r0, [r0, #0x60]
	cmp r0, #0
	beq _0804FBEC
	bl FUN_080522bc
_0804FBEC:
	pop {r0}
	bx r0

	thumb_func_start FUN_0804fbf0
FUN_0804fbf0: @ 0x0804FBF0
	push {lr}
	bl FUN_0804f820
	cmp r0, #0
	beq _0804FC02
	adds r1, r0, #0
	adds r1, #0x34
	movs r0, #1
	strb r0, [r1]
_0804FC02:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804fc08
FUN_0804fc08: @ 0x0804FC08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x68]
	cmp r1, #0
	bne _0804FC1E
	b _0804FD1C
_0804FC1E:
	ldr r0, _0804FC78 @ =0x03002CF0
	ldr r0, [r0]
	bl Mod
	adds r5, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r6, [r4, #0x70]
	movs r7, #0
	ldr r1, _0804FC7C @ =0x030046A0
	mov sl, r1
	movs r2, #0xf
	mov sb, r2
_0804FC38:
	mov r1, sl
	ldr r0, [r1]
	lsls r1, r7, #1
	adds r0, r1, r0
	adds r0, #0x60
	mov ip, r0
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	mov r2, ip
	strh r0, [r2]
	adds r4, r5, #0
	mov r8, r1
	adds r1, r5, #0
	adds r1, #0x10
	adds r7, #1
	cmp r5, r1
	bge _0804FCA6
	adds r2, r5, #0
	mov r0, sb
	ands r2, r0
	movs r3, #1
	lsls r3, r2
	adds r0, r6, #0
	ands r0, r3
	cmp r0, #0
	beq _0804FC80
	mov r1, ip
	strh r2, [r1]
	bics r6, r3
	b _0804FCA6
	.align 2, 0
_0804FC78: .4byte 0x03002CF0
_0804FC7C: .4byte 0x030046A0
_0804FC80:
	adds r4, #1
	cmp r4, r1
	bge _0804FCA6
	adds r2, r4, #0
	mov r0, sb
	ands r2, r0
	movs r3, #1
	lsls r3, r2
	adds r0, r6, #0
	ands r0, r3
	cmp r0, #0
	beq _0804FC80
	mov r1, sl
	ldr r0, [r1]
	add r0, r8
	adds r0, #0x60
	strh r2, [r0]
	bics r6, r3
	adds r5, r4, #0
_0804FCA6:
	mov r2, sl
	ldr r0, [r2]
	add r0, r8
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _0804FCBA
	movs r2, #1
	str r2, [sp]
_0804FCBA:
	ldr r1, _0804FD2C @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0804FD30 @ =0x000003FF
	ands r0, r1
	ldr r2, _0804FD2C @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0804FD34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	ands r0, r2
	adds r5, r5, r0
	cmp r7, #3
	ble _0804FC38
	ldr r0, [sp]
	cmp r0, #0
	beq _0804FD12
	movs r7, #0
	ldr r5, _0804FD38 @ =0x030046A0
_0804FCE4:
	ldr r0, [r5]
	lsls r4, r7, #1
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x60
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _0804FD0C
	bl GetWeaponID
	cmp r0, #0
	bne _0804FD0C
	ldr r0, [r5]
	adds r0, r4, r0
	adds r0, #0x60
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
_0804FD0C:
	adds r7, #1
	cmp r7, #3
	ble _0804FCE4
_0804FD12:
	ldr r1, _0804FD38 @ =0x030046A0
	ldr r0, [r1]
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
_0804FD1C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FD2C: .4byte 0x030046B8
_0804FD30: .4byte 0x000003FF
_0804FD34: .4byte 0x0203B400
_0804FD38: .4byte 0x030046A0

	thumb_func_start FUN_0804fd3c
FUN_0804fd3c: @ 0x0804FD3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x6c]
	cmp r1, #0
	beq _0804FE02
	ldr r0, _0804FDAC @ =0x03002CF0
	ldr r0, [r0]
	bl Mod
	adds r5, r0, #0
	ldr r6, [r4, #0x74]
	movs r2, #0
	movs r0, #0xf
	mov sl, r0
	adds r4, #0x98
	mov sb, r4
_0804FD66:
	ldr r1, _0804FDB0 @ =0x030046A0
	ldr r0, [r1]
	lsls r1, r2, #1
	adds r0, r1, r0
	adds r0, #0x68
	mov ip, r0
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r3, #0
	mov r3, ip
	strh r0, [r3]
	adds r4, r5, #0
	mov r8, r1
	adds r7, r5, #0
	adds r7, #0x10
	adds r2, #1
	str r2, [sp]
	cmp r5, r7
	bge _0804FDE0
	adds r2, r5, #0
	mov r0, sl
	ands r2, r0
	movs r3, #1
	lsls r3, r2
	adds r0, r6, #0
	ands r0, r3
	cmp r0, #0
	beq _0804FDB4
	lsls r0, r2, #1
	add r0, sb
	ldrh r0, [r0]
	mov r1, ip
	strh r0, [r1]
	bics r6, r3
	b _0804FDE0
	.align 2, 0
_0804FDAC: .4byte 0x03002CF0
_0804FDB0: .4byte 0x030046A0
_0804FDB4:
	adds r4, #1
	cmp r4, r7
	bge _0804FDE0
	adds r1, r4, #0
	mov r3, sl
	ands r1, r3
	movs r2, #1
	lsls r2, r1
	adds r0, r6, #0
	ands r0, r2
	cmp r0, #0
	beq _0804FDB4
	ldr r3, _0804FE14 @ =0x030046A0
	ldr r0, [r3]
	add r0, r8
	adds r0, #0x68
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	strh r1, [r0]
	bics r6, r2
	adds r5, r4, #0
_0804FDE0:
	ldr r1, _0804FE18 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0804FE1C @ =0x000003FF
	ands r0, r1
	ldr r3, _0804FE18 @ =0x030046B8
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _0804FE20 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, sl
	ands r0, r3
	adds r5, r5, r0
	ldr r2, [sp]
	cmp r2, #3
	ble _0804FD66
_0804FE02:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FE14: .4byte 0x030046A0
_0804FE18: .4byte 0x030046B8
_0804FE1C: .4byte 0x000003FF
_0804FE20: .4byte 0x0203B400

	thumb_func_start FUN_0804fe24
FUN_0804fe24: @ 0x0804FE24
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0804FE64 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #0
	blt _0804FE5E
	movs r0, #3
_0804FE44:
	subs r0, #1
	cmp r0, #0
	bge _0804FE44
	adds r0, r4, #0
	bl GetWeaponID
	cmp r0, #0
	beq _0804FE5E
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x70]
	bics r0, r1
	str r0, [r5, #0x70]
_0804FE5E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804FE64: .4byte 0x030046A0

	thumb_func_start FUN_0804fe68
FUN_0804fe68: @ 0x0804FE68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0804FEAC @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x5a
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x68
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r5, #0
	blt _0804FEA6
	movs r3, #0
	movs r6, #1
	adds r2, r4, #0
	adds r2, #0x98
_0804FE8E:
	ldrh r0, [r2]
	cmp r0, r5
	bne _0804FE9E
	adds r1, r6, #0
	lsls r1, r3
	ldr r0, [r4, #0x74]
	bics r0, r1
	str r0, [r4, #0x74]
_0804FE9E:
	adds r2, #2
	adds r3, #1
	cmp r3, #0xf
	ble _0804FE8E
_0804FEA6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804FEAC: .4byte 0x030046A0

	thumb_func_start FUN_0804feb0
FUN_0804feb0: @ 0x0804FEB0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0803cb24
	movs r0, #3
_0804FEBA:
	subs r0, #1
	cmp r0, #0
	bge _0804FEBA
	adds r4, r5, #0
	adds r4, #0x38
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FED2
	bl FUN_0803cb4c
	movs r0, #0
	strb r0, [r4]
_0804FED2:
	adds r4, r5, #0
	adds r4, #0x39
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FEE4
	bl FUN_0803cb6c
	movs r0, #0
	strb r0, [r4]
_0804FEE4:
	adds r4, r5, #0
	adds r4, #0x3a
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FEF6
	bl FUN_0803cbb4
	movs r0, #0
	strb r0, [r4]
_0804FEF6:
	adds r4, r5, #0
	adds r4, #0x3b
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FF08
	bl FUN_0803cc54
	movs r0, #0
	strb r0, [r4]
_0804FF08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ff10
FUN_0804ff10: @ 0x0804FF10
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x29
	ldrb r0, [r6]
	cmp r0, #0
	beq _0804FF50
	movs r4, #0
	strb r4, [r6]
	bl FUN_08016f84
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0804fb04
	str r4, [sp]
	adds r0, r5, #0
	movs r1, #1
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
	movs r2, #4
	ldr r1, _0804FF70 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0804fbd0
_0804FF50:
	movs r2, #0x80
	ldr r1, [r5, #0x20]
	ands r2, r1
	cmp r2, #0
	beq _0804FF74
	bl FUN_0809c58c
	movs r1, #6
	adds r0, r5, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	movs r0, #1
	strb r0, [r6]
	b _0804FF8E
	.align 2, 0
_0804FF70: .4byte 0x030044BC
_0804FF74:
	movs r0, #3
	ands r0, r1
	cmp r0, #3
	bne _0804FF98
	movs r0, #4
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x20]
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x28
	strb r1, [r0]
	strb r1, [r6]
_0804FF8E:
	str r2, [r5, #0x24]
	adds r0, r5, #0
	bl FUN_0804fbe0
	b _0804FF9E
_0804FF98:
	ldr r0, [r5, #0x24]
	adds r0, #1
	str r0, [r5, #0x24]
_0804FF9E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ffa8
FUN_0804ffa8: @ 0x0804FFA8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x29
	ldrb r0, [r6]
	cmp r0, #0
	beq _0804FFF2
	movs r4, #0
	strb r4, [r6]
	adds r0, r5, #0
	bl FUN_0804fc08
	adds r0, r5, #0
	bl FUN_0804fd3c
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	str r4, [r0]
	bl FUN_0808e420
	ldr r0, _08050058 @ =FUN_0804fb24
	adds r1, r5, #0
	adds r1, #0x3c
	bl FUN_08051bb0
	adds r0, r5, #0
	adds r0, #0x33
	strb r4, [r0]
	adds r1, r5, #0
	adds r1, #0x31
	movs r0, #8
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_0804fbd0
_0804FFF2:
	ldr r0, _0805005C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08050010
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #1
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x31
	movs r0, #8
	strb r0, [r1]
_08050010:
	adds r0, r5, #0
	adds r0, #0x33
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050064
	ldr r0, [r5, #0x24]
	cmp r0, #0x10
	bls _08050064
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08050064
	adds r1, r5, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	bne _08050060
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #2
	adds r1, r5, #0
	adds r1, #0x28
	strb r0, [r1]
	movs r0, #1
	strb r0, [r6]
	str r4, [r5, #0x24]
	bl FUN_0808e4f4
	adds r0, r5, #0
	bl FUN_0804fbe0
	b _0805006A
	.align 2, 0
_08050058: .4byte FUN_0804fb24
_0805005C: .4byte 0x030044E0
_08050060:
	subs r0, #1
	strb r0, [r1]
_08050064:
	ldr r0, [r5, #0x24]
	adds r0, #1
	str r0, [r5, #0x24]
_0805006A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08050070
FUN_08050070: @ 0x08050070
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _080500C6
	movs r0, #0
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x3c
	movs r5, #0
	ldrb r0, [r3, #6]
	lsls r0, r0, #0x10
	str r0, [sp]
	movs r2, #0
_08050092:
	adds r0, r3, r2
	ldrb r1, [r0]
	lsls r1, r5
	ldr r0, [sp]
	orrs r0, r1
	str r0, [sp]
	adds r2, #1
	adds r5, #4
	cmp r2, #3
	ble _08050092
	adds r0, r4, #0
	movs r1, #2
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0804fbd0
	adds r0, r4, #0
	bl FUN_0804fe24
	adds r0, r4, #0
	bl FUN_0804fe68
_080500C6:
	movs r1, #0xc
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0xc
	bne _080500FC
	adds r0, r4, #0
	bl FUN_0804f97c
	movs r1, #0xd
	rsbs r1, r1, #0
	ldr r0, [r4, #0x20]
	ands r0, r1
	str r0, [r4, #0x20]
	movs r1, #3
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_0804fbe0
	b _08050102
_080500FC:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
_08050102:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805010c
FUN_0805010c: @ 0x0805010C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0805016C
	movs r6, #0
	strb r6, [r1]
	adds r0, r5, #0
	bl FUN_0804fa04
	adds r1, r0, #0
	cmp r1, #0
	beq _08050158
	adds r0, r5, #0
	adds r0, #0x2c
	movs r7, #1
	strb r7, [r0]
	adds r4, r5, #0
	adds r4, #0x33
	strb r6, [r4]
	ldr r0, _08050154 @ =FUN_0804fb24
	adds r1, r5, #0
	adds r1, #0x3c
	adds r2, r5, #0
	adds r2, #0x48
	adds r3, r5, #0
	adds r3, #0x38
	bl FUN_08051c50
	cmp r0, #0
	beq _0805016C
	strb r7, [r4]
	b _0805016C
	.align 2, 0
_08050154: .4byte FUN_0804fb24
_08050158:
	adds r0, r5, #0
	adds r0, #0x2c
	strb r1, [r0]
	str r1, [sp]
	adds r0, r5, #0
	movs r1, #3
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
_0805016C:
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050192
	adds r6, r5, #0
	adds r6, #0x33
	ldrb r0, [r6]
	cmp r0, #0
	beq _08050192
	movs r4, #0
	str r4, [sp, #4]
	add r2, sp, #4
	adds r0, r5, #0
	movs r1, #3
	movs r3, #1
	bl FUN_0804fa44
	strb r4, [r6]
_08050192:
	movs r0, #0x30
	ldr r1, [r5, #0x20]
	ands r0, r1
	cmp r0, #0x30
	bne _080501BA
	movs r0, #0x31
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r5, #0x20]
	movs r1, #4
	adds r0, r5, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r5, #0x24]
	b _080501C0
_080501BA:
	ldr r0, [r5, #0x24]
	adds r0, #1
	str r0, [r5, #0x24]
_080501C0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080501c8
FUN_080501c8: @ 0x080501C8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_08050d64
	movs r2, #0
	cmp r0, #0x3c
	bgt _080501DE
	movs r2, #2
	cmp r0, #0x19
	ble _080501DE
	movs r2, #1
_080501DE:
	adds r0, r5, #0
	adds r0, #0xec
	adds r4, r5, #0
	adds r4, #0xcc
	adds r2, #0xd4
	adds r1, r4, #0
	movs r3, #0
	bl Sprite_SetSprite
	bl FUN_08050d7c
	movs r2, #0
	adds r1, r4, #0
	cmp r0, #0x3c
	bgt _08050204
	movs r2, #2
	cmp r0, #0x19
	ble _08050204
	movs r2, #1
_08050204:
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r0, r5, r3
	adds r2, #0xd7
	movs r3, #0
	bl Sprite_SetSprite
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08050218
FUN_08050218: @ 0x08050218
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _08050256
	movs r0, #0
	strb r0, [r1]
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x62
	bls _0805023C
	movs r0, #0x63
	strh r0, [r4, #0x1e]
_0805023C:
	ldrh r0, [r4, #0x1e]
	cmp r0, #0xb
	bne _08050246
	bl FUN_0803cc70
_08050246:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0804fb04
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804fbd0
_08050256:
	ldrh r0, [r4, #0x1e]
	cmp r0, #0xb
	bne _08050268
	ldr r0, [r4, #0x24]
	cmp r0, #0x14
	bne _08050268
	movs r0, #4
	bl sound_fadeout_08240440
_08050268:
	ldr r0, [r4, #0x24]
	cmp r0, #0x59
	bls _0805029C
	movs r1, #5
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	ldr r2, _08050298 @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0804fbe0
	b _080502A0
	.align 2, 0
_08050298: .4byte 0x030044BC
_0805029C:
	adds r0, #1
	str r0, [r4, #0x24]
_080502A0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080502a8
FUN_080502a8: @ 0x080502A8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _080502F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xb4
	lsls r0, r0, #2
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_0809c544
	adds r0, r4, #0
	movs r1, #4
	bl FUN_0804fbd0
	adds r0, r4, #0
	bl FUN_0804feb0
	ldrh r0, [r4, #0x1e]
	cmp r0, #0xb
	bne _080502E6
	movs r0, #0xaf
	bl sound_08240264
	b _080502F0
_080502E6:
	cmp r0, #1
	bne _080502F0
	movs r0, #0xad
	bl sound_08240264
_080502F0:
	adds r1, r4, #0
	adds r1, #0x37
	movs r0, #1
	strb r0, [r1]
_080502F8:
	adds r0, r4, #0
	bl FUN_080501c8
	ldr r0, [r4, #0x24]
	cmp r0, #0x1e
	bne _0805030A
	adds r0, r4, #0
	bl FUN_0804fbe0
_0805030A:
	ldr r0, [r4, #0x24]
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _080503B2
	ldr r0, _08050348 @ =0x03002BE0
	ldr r5, [r0]
	movs r0, #7
	bl FUN_08022a2c
	adds r7, r0, #0
	cmp r5, #0
	beq _08050350
	ldr r0, _0805034C @ =0x00000366
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _08050350
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldrh r1, [r2]
	bl Div
	adds r6, r0, #0
	b _08050352
	.align 2, 0
_08050348: .4byte 0x03002BE0
_0805034C: .4byte 0x00000366
_08050350:
	movs r6, #0
_08050352:
	cmp r6, #0
	bne _08050364
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08050364
	movs r6, #1
_08050364:
	cmp r7, #0
	beq _0805038C
	adds r2, r7, #0
	adds r2, #0x92
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	ble _0805038C
	adds r0, r7, #0
	adds r0, #0x90
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Div
	adds r1, r0, #0
	b _0805038E
_0805038C:
	movs r1, #0
_0805038E:
	cmp r1, #0
	bne _080503A0
	adds r0, r7, #0
	adds r0, #0x90
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _080503A0
	movs r1, #1
_080503A0:
	lsls r0, r1, #8
	orrs r0, r6
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
_080503B2:
	ldr r0, [r4, #0x2c]
	ldr r1, _080503E0 @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	bne _080503C6
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080503E4
_080503C6:
	bl FUN_0809c58c
	movs r1, #6
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	b _08050432
	.align 2, 0
_080503E0: .4byte 0x00FFFF00
_080503E4:
	ldrh r0, [r4, #0x1c]
	subs r0, #1
	movs r6, #0
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0805042C
	bl FUN_0803ca14
	bl FUN_0809c58c
	ldr r0, _08050424 @ =0x00000372
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0x28
	strb r6, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r5, [r4, #0x24]
	movs r2, #4
	ldr r1, _08050428 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x37
	strb r6, [r0]
	b _08050432
	.align 2, 0
_08050424: .4byte 0x00000372
_08050428: .4byte 0x030044BC
_0805042C:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
_08050432:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805043c
FUN_0805043c: @ 0x0805043C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0805049C
	movs r0, #0
	strb r0, [r1]
	bl FUN_08016f84
	adds r0, r4, #0
	bl FUN_0804fb3c
	adds r0, r4, #0
	adds r0, #0x3c
	ldrh r1, [r0, #8]
	ldrb r2, [r0, #7]
	movs r0, #3
	ands r0, r2
	lsls r0, r0, #0x10
	orrs r1, r0
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #4
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
	adds r0, r4, #0
	movs r1, #5
	bl FUN_0804fbd0
	movs r0, #4
	bl sound_fadeout_08240440
	movs r1, #4
	ldr r0, _080504CC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0805049C
	ldr r0, _080504D0 @ =0x03002BE0
	ldr r0, [r0]
	subs r1, #5
	bl FUN_0807b910
_0805049C:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _080504D4
	movs r0, #0xc0
	ldr r1, [r4, #0x20]
	ands r0, r1
	cmp r0, #0xc0
	bne _080504D4
	movs r0, #0xc1
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4, #0x20]
	movs r1, #7
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	b _080504D8
	.align 2, 0
_080504CC: .4byte 0x03002BC0
_080504D0: .4byte 0x03002BE0
_080504D4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_080504D8:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080504e0
FUN_080504e0: @ 0x080504E0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805051A
	movs r0, #0
	strb r0, [r5]
	adds r0, r4, #0
	bl FUN_0804fa94
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
	ldrb r0, [r1]
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	mov r2, sp
	movs r3, #1
	bl FUN_0804fa44
	movs r2, #4
	ldr r1, _08050540 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0805051A:
	movs r1, #0xc0
	lsls r1, r1, #2
	ldr r2, [r4, #0x20]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, r1
	bne _08050548
	ldr r0, _08050544 @ =0xFFFFFCFF
	ands r2, r0
	str r2, [r4, #0x20]
	movs r1, #8
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	movs r0, #1
	strb r0, [r5]
	str r2, [r4, #0x24]
	b _0805054E
	.align 2, 0
_08050540: .4byte 0x030044BC
_08050544: .4byte 0xFFFFFCFF
_08050548:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
_0805054E:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08050558
FUN_08050558: @ 0x08050558
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805056A
	movs r0, #0
	strb r0, [r5]
_0805056A:
	ldr r0, [r4, #0x24]
	cmp r0, #0x77
	bls _0805058C
	bl FUN_0804e5e8
	movs r1, #9
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	movs r0, #1
	strb r0, [r5]
	str r2, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_0804fbe0
	b _08050590
_0805058C:
	adds r0, #1
	str r0, [r4, #0x24]
_08050590:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08050598
FUN_08050598: @ 0x08050598
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0x29
	ldrb r0, [r2]
	cmp r0, #0
	beq _08050604
	movs r1, #0
	strb r1, [r2]
	adds r0, r6, #0
	adds r0, #0x34
	strb r1, [r0]
	ldrh r0, [r6, #0x1e]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r4, r1, #4
	subs r4, r4, r1
	lsls r4, r4, #4
	ldr r5, [r6, #0x44]
	adds r5, r4, r5
	ldr r0, [r6, #0x50]
	adds r4, r4, r0
	bl FUN_0804e458
	ldr r1, _0805066C @ =gSystemSaveData
	ldr r1, [r1]
	ldr r3, [r1, #0xc]
	adds r1, r6, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	adds r2, r6, #0
	adds r2, #0xc8
	ldr r2, [r2]
	str r2, [sp]
	str r3, [sp, #4]
	ldr r2, _08050670 @ =FUN_0804fbf0
	str r2, [sp, #8]
	adds r2, r5, #0
	adds r3, r4, #0
	bl FUN_08052b3c
	movs r3, #1
	adds r1, r6, #0
	adds r1, #0xf4
	movs r2, #1
_080505F6:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080505F6
_08050604:
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050662
	adds r4, r6, #0
	adds r4, #0xbc
	movs r1, #0xa
	adds r0, r6, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r6, #0x24]
	adds r0, r6, #0
	adds r0, #0x35
	strb r2, [r0]
	adds r0, r6, #0
	movs r1, #3
	bl FUN_0804fb6c
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	adds r3, r0, #0
	str r3, [r4]
	cmp r3, #0
	blt _08050662
	adds r0, r6, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r3, #0
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xb
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
_08050662:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805066C: .4byte gSystemSaveData
_08050670: .4byte FUN_0804fbf0

	thumb_func_start FUN_08050674
FUN_08050674: @ 0x08050674
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xbc
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _080506B6
	movs r0, #0
	strb r0, [r1]
	ldr r2, _080506A4 @ =gSystemSaveData
	ldr r0, [r2]
	ldr r1, [r0, #0xc]
	adds r0, r4, #0
	adds r0, #0xc8
	ldr r0, [r0]
	adds r1, r1, r0
	ldr r3, _080506A8 @ =0x0000270F
	cmp r1, r3
	ble _080506AC
	adds r1, r3, #0
	b _080506B2
	.align 2, 0
_080506A4: .4byte gSystemSaveData
_080506A8: .4byte 0x0000270F
_080506AC:
	cmp r1, #0
	bge _080506B2
	movs r1, #0
_080506B2:
	ldr r0, [r2]
	str r1, [r0, #0xc]
_080506B6:
	ldr r0, [r4, #0x24]
	cmp r0, #0x3c
	bne _080506F4
	bl FUN_082410bc
	adds r1, r4, #0
	adds r1, #0x36
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080506E4
	ldr r0, [r5]
	movs r1, #0xe
	bl FUN_0804a2f8
	ldr r0, _080506E0 @ =0x000002AE
	bl PlaySound_082406e0
	b _080506F4
	.align 2, 0
_080506E0: .4byte 0x000002AE
_080506E4:
	ldr r0, [r5]
	movs r1, #0xf
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080506F4:
	ldr r0, [r4, #0x24]
	cmp r0, #0xb4
	bne _08050748
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #1
	beq _08050716
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0805072C
_08050716:
	movs r1, #0xb
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	b _0805074C
_0805072C:
	ldr r0, [r5]
	movs r1, #0xb
	bl FUN_0804a2f8
	movs r1, #0xa
	adds r0, r4, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _0805074A
_08050748:
	adds r0, #1
_0805074A:
	str r0, [r4, #0x24]
_0805074C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08050754
FUN_08050754: @ 0x08050754
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x29
	ldrb r0, [r2]
	cmp r0, #0
	beq _0805077C
	movs r1, #0
	strb r1, [r2]
	str r1, [sp]
	ldr r0, _0805078C @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl FUN_0823ce68
_0805077C:
	ldr r0, [r4, #0x24]
	cmp r0, #0xa
	bne _08050790
	movs r0, #7
	bl FUN_0809c08c
	b _080507AE
	.align 2, 0
_0805078C: .4byte 0x0000FFFF
_08050790:
	cmp r0, #0x14
	bls _080507AE
	cmp r0, #0x28
	bne _0805079C
	bl FUN_0804e604
_0805079C:
	bl FUN_0804ba3c
	cmp r0, #0
	bne _080507AE
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #1
	str r0, [r1]
	b _080507B4
_080507AE:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
_080507B4:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start EntityAF33_Update
EntityAF33_Update: @ 0x080507BC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r0, [r1]
	cmp r0, #0
	beq _08050804
	movs r0, #0
	str r0, [r1]
	movs r0, #7
	bl FUN_0809c08c
	ldr r1, _080507F8 @ =FUN_0822db5c
	ldr r2, _080507FC @ =FUN_0822aaac
	ldr r3, _08050800 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	beq _080507F0
	movs r1, #0
	bl Script_ExecById
_080507F0:
	adds r0, r4, #0
	bl KillEntity
	b _0805083A
	.align 2, 0
_080507F8: .4byte FUN_0822db5c
_080507FC: .4byte FUN_0822aaac
_08050800: .4byte FUN_0822f204
_08050804:
	bl FUN_0804e59c
	adds r6, r0, #0
	cmp r6, #0
	bne _0805083A
	ldr r1, _08050844 @ =0x085AB6A4
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r5, r4, #0
	adds r5, #0x2a
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805083A
	adds r0, r4, #0
	adds r0, #0x54
	bl FUN_0804e514
	cmp r0, #0
	blt _0805083A
	strb r6, [r5]
_0805083A:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08050844: .4byte 0x085AB6A4

	thumb_func_start EntityAF33_Destroy
EntityAF33_Destroy: @ 0x08050848
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xec
	movs r5, #1
_08050852:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08050852
	movs r4, #0
	adds r0, r6, #0
	adds r0, #0xbc
	ldr r0, [r0]
	bl FUN_0804a16c
	ldr r0, _08050878 @ =0x030000F0
	str r4, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08050878: .4byte 0x030000F0

	thumb_func_start EntityAF33_Init
EntityAF33_Init: @ 0x0805087C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	adds r6, r0, #0
	ldr r0, _080508F4 @ =0x030000F0
	str r6, [r0]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xc4
	str r0, [r1]
	movs r0, #0
	str r0, [r6, #0x68]
	str r0, [r6, #0x70]
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _08050906
	adds r7, r6, #0
	adds r7, #0x78
	adds r0, r6, #0
	adds r0, #0x2b
	str r0, [sp, #0x34]
	adds r1, r6, #0
	adds r1, #0x2c
	str r1, [sp, #0x38]
	adds r2, r6, #0
	adds r2, #0x2d
	str r2, [sp, #0x3c]
	adds r3, r6, #0
	adds r3, #0x33
	str r3, [sp, #0x44]
	adds r5, r6, #0
	adds r5, #0x32
	str r5, [sp, #0x40]
	subs r0, #3
	str r0, [sp, #0x2c]
	subs r1, #3
	str r1, [sp, #0x30]
	adds r2, #0xb
	str r2, [sp, #0x48]
	adds r4, r7, #0
_080508DC:
	bl VM_GetPC
	cmp r0, #0
	beq _080508F8
	bl Script_GetValue
	strh r0, [r4]
	ldr r0, [r6, #0x68]
	adds r0, #1
	str r0, [r6, #0x68]
	b _080508FA
	.align 2, 0
_080508F4: .4byte 0x030000F0
_080508F8:
	strh r0, [r4]
_080508FA:
	adds r4, #2
	adds r0, r7, #0
	adds r0, #0x1e
	cmp r4, r0
	ble _080508DC
	b _08050942
_08050906:
	adds r7, r6, #0
	adds r7, #0x78
	adds r3, r6, #0
	adds r3, #0x2b
	str r3, [sp, #0x34]
	adds r5, r6, #0
	adds r5, #0x2c
	str r5, [sp, #0x38]
	adds r0, r6, #0
	adds r0, #0x2d
	str r0, [sp, #0x3c]
	adds r1, r6, #0
	adds r1, #0x33
	str r1, [sp, #0x44]
	adds r2, r6, #0
	adds r2, #0x32
	str r2, [sp, #0x40]
	subs r3, #3
	str r3, [sp, #0x2c]
	subs r5, #3
	str r5, [sp, #0x30]
	adds r0, #0xb
	str r0, [sp, #0x48]
	adds r1, r7, #0
	movs r2, #0
	adds r0, #0x5e
_0805093A:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0805093A
_08050942:
	ldr r1, [r6, #0x68]
	cmp r1, #0
	beq _080509BE
	ldr r0, _080509E8 @ =0x03002CF0
	ldrb r5, [r0]
	movs r2, #0
	mov r8, r2
	cmp r8, r1
	bhs _080509BE
	ldr r3, _080509EC @ =0x030046B8
	mov sl, r3
	mov sb, r7
_0805095A:
	movs r4, #0xf
	ands r4, r5
	movs r0, #1
	lsls r0, r4
	ldr r1, [r6, #0x70]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _08050980
	movs r7, #0xf
	movs r3, #1
_08050970:
	adds r4, r5, #0
	ands r4, r7
	adds r5, #1
	adds r0, r3, #0
	lsls r0, r4
	ands r0, r1
	cmp r0, #0
	bne _08050970
_08050980:
	movs r0, #1
	lsls r0, r4
	orrs r2, r0
	str r2, [r6, #0x70]
	mov r7, sb
	ldrh r0, [r7]
	bl FUN_0823d414
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08242b6c
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080509F0 @ =0x000003FF
	ands r0, r1
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080509F4 @ =0x0203B400
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r5, r5, r0
	movs r7, #2
	add sb, r7
	movs r0, #1
	add r8, r0
	ldr r0, [r6, #0x68]
	cmp r8, r0
	blo _0805095A
_080509BE:
	movs r0, #0
	str r0, [r6, #0x6c]
	str r0, [r6, #0x74]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _08050A08
	add r4, sp, #0x10
_080509D0:
	bl VM_GetPC
	cmp r0, #0
	beq _080509F8
	bl Script_GetValue
	strb r0, [r4]
	ldr r0, [r6, #0x6c]
	adds r0, #1
	str r0, [r6, #0x6c]
	b _080509FA
	.align 2, 0
_080509E8: .4byte 0x03002CF0
_080509EC: .4byte 0x030046B8
_080509F0: .4byte 0x000003FF
_080509F4: .4byte 0x0203B400
_080509F8:
	strb r0, [r4]
_080509FA:
	adds r4, #1
	mov r0, sp
	adds r0, #0x1f
	cmp r4, r0
	ble _080509D0
	ldr r1, [r6, #0x6c]
	b _08050A1A
_08050A08:
	ldr r1, [r6, #0x6c]
	movs r2, #0
	mov r0, sp
	adds r0, #0x1f
_08050A10:
	strb r2, [r0]
	subs r0, #1
	add r3, sp, #0x10
	cmp r0, r3
	bge _08050A10
_08050A1A:
	cmp r1, #0
	beq _08050A9C
	ldr r0, _08050B64 @ =0x03002CF0
	ldrb r3, [r0]
	movs r5, #0
	mov r8, r5
	cmp r8, r1
	bhs _08050A9C
	movs r7, #1
	mov sl, r7
	adds r0, r6, #0
	adds r0, #0x98
	str r0, [sp, #0x28]
	ldr r1, _08050B68 @ =0x030046B8
	mov sb, r1
	add r2, sp, #0x10
	mov ip, r2
_08050A3C:
	movs r1, #0xf
	ands r1, r3
	mov r0, sl
	lsls r0, r1
	ldr r2, [r6, #0x74]
	ands r0, r2
	adds r4, r2, #0
	cmp r0, #0
	beq _08050A62
	movs r7, #0xf
	movs r5, #1
_08050A52:
	adds r1, r3, #0
	ands r1, r7
	adds r3, #1
	adds r0, r5, #0
	lsls r0, r1
	ands r0, r2
	cmp r0, #0
	bne _08050A52
_08050A62:
	mov r0, sl
	lsls r0, r1
	orrs r4, r0
	str r4, [r6, #0x74]
	lsls r0, r1, #1
	ldr r5, [sp, #0x28]
	adds r0, r5, r0
	mov r7, ip
	ldrb r1, [r7]
	strh r1, [r0]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _08050B6C @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _08050B70 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r3, r3, r0
	movs r7, #1
	add ip, r7
	movs r0, #1
	add r8, r0
	ldr r0, [r6, #0x6c]
	cmp r8, r0
	blo _08050A3C
_08050A9C:
	movs r0, #0
	str r0, [r6, #0x18]
	movs r1, #0
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	str r0, [r6, #0x20]
	ldr r2, [sp, #0x34]
	strb r1, [r2]
	ldr r3, [sp, #0x38]
	strb r1, [r3]
	ldr r5, [sp, #0x3c]
	strb r1, [r5]
	ldr r7, [sp, #0x44]
	strb r1, [r7]
	movs r2, #1
	ldr r3, [sp, #0x40]
	strb r2, [r3]
	ldr r5, [sp, #0x2c]
	strb r1, [r5]
	ldr r7, [sp, #0x30]
	strb r2, [r7]
	str r0, [r6, #0x24]
	ldr r0, _08050B74 @ =FUN_0804f8ec
	ldr r1, _08050B78 @ =FUN_0804f82c
	ldr r2, _08050B7C @ =FUN_0804f950
	ldr r3, _08050B80 @ =FUN_0804f970
	bl FUN_0804e4dc
	movs r0, #0
	mov r8, r0
	movs r4, #0
	movs r5, #0x64
	adds r1, r6, #0
	adds r1, #0x40
	adds r3, r6, #0
	adds r3, #0x3c
_08050AE4:
	mov r7, r8
	adds r2, r3, r7
	movs r0, #3
_08050AEA:
	strb r4, [r2]
	subs r0, #1
	cmp r0, #0
	bge _08050AEA
	strb r5, [r1]
	strb r5, [r1, #1]
	strb r4, [r1, #2]
	strb r4, [r1, #3]
	str r4, [r1, #4]
	adds r1, #0xc
	adds r3, #0xc
	movs r0, #1
	add r8, r0
	mov r2, r8
	cmp r2, #1
	ble _08050AE4
	ldr r1, [sp, #0x48]
	movs r2, #0
	adds r0, r1, #3
_08050B10:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08050B10
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0804fb04
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0804fb04
	movs r0, #0
	movs r1, #0
	bl FUN_08051b70
	bl FUN_08052250
	str r0, [r6, #0x60]
	bl FUN_08052ffc
	str r0, [r6, #0x64]
	movs r0, #4
	movs r1, #0x18
	bl FUN_0804e9f4
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08050B5C
	bl FUN_0823d340
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	cmp r0, #0
	bne _08050B84
_08050B5C:
	movs r0, #1
	rsbs r0, r0, #0
	b _08050C60
	.align 2, 0
_08050B64: .4byte 0x03002CF0
_08050B68: .4byte 0x030046B8
_08050B6C: .4byte 0x000003FF
_08050B70: .4byte 0x0203B400
_08050B74: .4byte FUN_0804f8ec
_08050B78: .4byte FUN_0804f82c
_08050B7C: .4byte FUN_0804f950
_08050B80: .4byte FUN_0804f970
_08050B84:
	adds r1, r6, #0
	adds r1, #0xc8
	movs r0, #0
	str r0, [r1]
	movs r0, #0x4d
	movs r1, #0xb
	bl Script_GetKeywordValue
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08050B5C
	movs r5, #0xd7
	lsls r5, r5, #1
	adds r4, r6, r5
	movs r7, #3
	mov r8, r7
_08050BB0:
	bl Script_GetValue
	strh r0, [r4]
	adds r4, #2
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _08050BB0
	ldr r0, _08050C10 @ =0x0000CB05
	ldr r1, _08050C14 @ =0x00005D04
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _08050B5C
	adds r4, r6, #0
	adds r4, #0xcc
	adds r1, r4, #0
	adds r0, r2, #0
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r7, #0
	mov r8, r7
	mov sb, r4
	ldr r7, _08050C18 @ =0xFFFF0000
	add r5, sp, #0x20
	adds r4, #0x20
_08050BFA:
	mov r0, r8
	cmp r0, #0
	bne _08050C1C
	ldr r0, [sp, #0x20]
	ands r0, r7
	movs r1, #0x84
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r2, #0xd4
	b _08050C28
	.align 2, 0
_08050C10: .4byte 0x0000CB05
_08050C14: .4byte 0x00005D04
_08050C18: .4byte 0xFFFF0000
_08050C1C:
	ldr r0, [sp, #0x20]
	ands r0, r7
	movs r1, #0xdc
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r2, #0xd7
_08050C28:
	ldr r1, _08050C70 @ =0x0000FFFF
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r0, [r5, #4]
	ands r0, r7
	str r0, [r5, #4]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	ldr r3, _08050C74 @ =0x00010010
	bl FUN_0822f3fc
	adds r4, #0x60
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #1
	ble _08050BFA
	movs r0, #0
_08050C60:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08050C70: .4byte 0x0000FFFF
_08050C74: .4byte 0x00010010

	thumb_func_start EntityAF33_Create
EntityAF33_Create: @ 0x08050C78
	push {r4, lr}
	movs r1, #0xde
	lsls r1, r1, #1
	movs r0, #2
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08050CB0
	ldr r1, _08050CA8 @ =EntityAF33_Update
	ldr r2, _08050CAC @ =EntityAF33_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityAF33_Init
	cmp r0, #0
	bge _08050CB0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08050CB2
	.align 2, 0
_08050CA8: .4byte EntityAF33_Update
_08050CAC: .4byte EntityAF33_Destroy
_08050CB0:
	adds r0, r4, #0
_08050CB2:
	pop {r4}
	pop {r1}
	bx r1

