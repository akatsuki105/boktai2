	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08027ed0
FUN_08027ed0: @ 0x08027ED0
	push {lr}
	adds r1, r0, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027EF4
	ldr r2, _08027EF0 @ =0x00000824
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08027EFE
	cmp r0, #1
	bne _08027EFE
	movs r0, #0xc1
	b _08027F0A
	.align 2, 0
_08027EF0: .4byte 0x00000824
_08027EF4:
	ldr r2, _08027F04 @ =0x00000FD4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08027F08
_08027EFE:
	movs r0, #0xc3
	b _08027F0A
	.align 2, 0
_08027F04: .4byte 0x00000FD4
_08027F08:
	movs r0, #0xc8
_08027F0A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08027f10
FUN_08027f10: @ 0x08027F10
	push {lr}
	adds r1, r0, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _08027F3C
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08027F54
	ldr r2, _08027F38 @ =0x00000FD4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027F4A
	movs r0, #8
	b _08027F56
	.align 2, 0
_08027F38: .4byte 0x00000FD4
_08027F3C:
	ldr r2, _08027F50 @ =0x00000824
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08027F54
	cmp r0, #1
	beq _08027F54
_08027F4A:
	movs r0, #3
	b _08027F56
	.align 2, 0
_08027F50: .4byte 0x00000824
_08027F54:
	movs r0, #1
_08027F56:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08027f5c
FUN_08027f5c: @ 0x08027F5C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r7, r5, #0
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r0, r5, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08027FDC
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08236524
	ldrh r1, [r6, #0x3e]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r4, #6]
	ands r0, r1
	cmp r0, #0
	beq _08027FA4
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r3, _08027FA0 @ =0x00000179
	adds r1, r5, r3
	b _08027FC0
	.align 2, 0
_08027FA0: .4byte 0x00000179
_08027FA4:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r2, _08028010 @ =0x00000179
	adds r1, r5, r2
_08027FC0:
	strb r0, [r1]
	ldr r1, [r4, #0x34]
	adds r0, r7, #0
	adds r0, #0xb4
	str r1, [r0]
	ldr r1, [r4, #0x38]
	adds r0, #4
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xde
	ldrh r0, [r4, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3e]
_08027FDC:
	movs r2, #1
	ldr r0, [r4, #0x38]
	ands r0, r2
	cmp r0, #0
	beq _08027FEE
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r2, [r0]
_08027FEE:
	adds r0, r6, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0802801C
	ldr r1, _08028014 @ =0x00000167
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _08028018 @ =0x00000177
	adds r0, r5, r3
	strb r2, [r0]
	b _08028022
	.align 2, 0
_08028010: .4byte 0x00000179
_08028014: .4byte 0x00000167
_08028018: .4byte 0x00000177
_0802801C:
	ldr r2, _08028028 @ =0x00000177
	adds r1, r5, r2
	strb r0, [r1]
_08028022:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028028: .4byte 0x00000177
_0802802C:
	.byte 0x00, 0xB5, 0x00, 0x20
	.byte 0xC8, 0x87, 0x80, 0x21, 0x09, 0x03, 0x10, 0x1C, 0x98, 0x30, 0x00, 0x68, 0x08, 0x40, 0x00, 0x28
	.byte 0x04, 0xD0, 0xBC, 0x20, 0x40, 0x00, 0x11, 0x18, 0x01, 0x20, 0x08, 0x70, 0x01, 0xBC, 0x00, 0x47
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_08028054
FUN_08028054: @ 0x08028054
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08236424
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08028074
FUN_08028074: @ 0x08028074
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r0, r3
	adds r0, #0x94
	strh r1, [r0]
	strh r1, [r2, #0x3c]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08028084
FUN_08028084: @ 0x08028084
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, _080280C0 @ =0x0203B400
	ldr r3, _080280C4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080280C8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	movs r6, #0xb7
	lsls r6, r6, #1
	strb r1, [r6, r5]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #3
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080280C0: .4byte 0x0203B400
_080280C4: .4byte 0x030046B8
_080280C8: .4byte 0x000003FF

	thumb_func_start FUN_080280cc
FUN_080280cc: @ 0x080280CC
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080280E6
	adds r0, r2, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x40
	bgt _08028100
_080280E6:
	ldr r0, _08028104 @ =0x000008DD
	adds r5, r2, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08028100
	ldr r1, _08028108 @ =0x00000888
	adds r3, r2, r1
	ldrh r0, [r3]
	adds r4, r0, #0
	cmp r4, #0
	beq _0802810C
	subs r0, #1
	strh r0, [r3]
_08028100:
	movs r0, #0
	b _0802812C
	.align 2, 0
_08028104: .4byte 0x000008DD
_08028108: .4byte 0x00000888
_0802810C:
	ldr r1, _08028134 @ =0x000008D2
	adds r0, r2, r1
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r3]
	strb r1, [r5]
	movs r0, #0x11
	adds r1, r2, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xbc
	str r4, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
_0802812C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08028134: .4byte 0x000008D2

	thumb_func_start FUN_08028138
FUN_08028138: @ 0x08028138
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	adds r2, #0x48
	mov ip, r2
	ldrb r1, [r2, #5]
	subs r1, #0x20
	movs r2, #0x40
	rsbs r2, r2, #0
	ands r1, r2
	adds r5, r1, #0
	adds r5, #0x40
	movs r6, #0xa4
	ldr r3, _08028170 @ =0x085B0A08
	adds r1, r5, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r6, r1
	cmp r1, #0
	blt _08028174
	asrs r2, r1, #0xc
	b _0802817A
	.align 2, 0
_08028170: .4byte 0x085B0A08
_08028174:
	rsbs r1, r1, #0
	asrs r1, r1, #0xc
	rsbs r2, r1, #0
_0802817A:
	movs r1, #0
	strh r2, [r4]
	strh r1, [r4, #2]
	movs r1, #0xff
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r1, r6, r1
	cmp r1, #0
	blt _08028196
	asrs r1, r1, #0xc
	b _0802819C
_08028196:
	rsbs r1, r1, #0
	asrs r1, r1, #0xc
	rsbs r1, r1, #0
_0802819C:
	strh r1, [r4, #4]
	cmp r5, #0
	bne _080281A8
	subs r1, #0x20
	strh r1, [r4, #4]
	b _080281C6
_080281A8:
	cmp r5, #0x40
	bne _080281B2
	ldrh r1, [r4]
	subs r1, #0x20
	b _080281C4
_080281B2:
	cmp r5, #0x80
	bne _080281BC
	adds r1, #0x20
	strh r1, [r4, #4]
	b _080281C6
_080281BC:
	cmp r5, #0xc0
	bne _080281C6
	ldrh r1, [r4]
	adds r1, #0x20
_080281C4:
	strh r1, [r4]
_080281C6:
	mov r2, ip
	adds r2, #8
	mov r3, ip
	ldrh r1, [r3, #8]
	ldrh r3, [r4]
	adds r1, r1, r3
	strh r1, [r4]
	ldrh r1, [r2, #2]
	ldrh r3, [r4, #2]
	adds r1, r1, r3
	strh r1, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080281ec
FUN_080281ec: @ 0x080281EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	mov r1, sl
	adds r0, r1, #0
	str r0, [sp, #0x18]
	ldr r1, _080282E4 @ =0x00000898
	add r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08028304
	ldr r1, _080282E8 @ =0x00000896
	add r1, sl
	ldrh r0, [r1]
	cmp r0, #0
	bne _080282FE
	mov r6, sp
	mov r0, sl
	mov r1, sp
	bl FUN_08028138
	add r7, sp, #8
	movs r1, #0x92
	lsls r1, r1, #2
	add r1, sl
	mov r0, sp
	ldrh r3, [r1]
	ldrh r0, [r0]
	adds r2, r3, r0
	strh r2, [r7]
	ldrh r0, [r6, #2]
	ldrh r4, [r1, #2]
	mov sb, r4
	add r0, sb
	strh r0, [r7, #2]
	ldrh r5, [r1, #4]
	ldrh r1, [r6, #4]
	adds r1, r1, r5
	mov ip, r1
	movs r1, #0x94
	lsls r1, r1, #2
	add r1, sl
	ldrh r4, [r1]
	mov r8, r4
	mov r4, r8
	subs r2, r2, r4
	strh r2, [r7]
	ldrh r2, [r1, #2]
	subs r0, r0, r2
	strh r0, [r7, #2]
	ldrh r1, [r1, #4]
	mov r0, ip
	subs r4, r0, r1
	strh r4, [r7, #4]
	add r4, sp, #0x10
	mov r0, sp
	ldrh r0, [r0]
	adds r3, r3, r0
	strh r3, [r4]
	ldrh r0, [r6, #2]
	add r0, sb
	strh r0, [r4, #2]
	ldrh r6, [r6, #4]
	adds r5, r5, r6
	add r3, r8
	strh r3, [r4]
	adds r0, r0, r2
	strh r0, [r4, #2]
	adds r5, r5, r1
	strh r5, [r4, #4]
	movs r3, #0
	ldr r0, _080282EC @ =0x0000016B
	add r0, sl
	ldrb r0, [r0]
	cmp r3, r0
	bge _08028344
	adds r5, r7, #0
	movs r2, #0
	ldrsh r1, [r5, r2]
	mov r8, r1
	adds r6, r0, #0
_08028296:
	lsls r1, r3, #2
	ldr r7, [sp, #0x18]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r7, #0
	ldrsh r1, [r2, r7]
	cmp r1, r8
	blt _080282F0
	movs r7, #0
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bgt _080282F0
	ldrh r0, [r5, #2]
	movs r7, #2
	ldrsh r1, [r2, r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _080282F0
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _080282F0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt _080282F0
	movs r7, #4
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bgt _080282F0
	movs r0, #1
	b _080282F2
	.align 2, 0
_080282E4: .4byte 0x00000898
_080282E8: .4byte 0x00000896
_080282EC: .4byte 0x0000016B
_080282F0:
	movs r0, #0
_080282F2:
	cmp r0, #0
	bne _0802833C
	adds r3, #1
	cmp r3, r6
	blt _08028296
	b _08028344
_080282FE:
	subs r0, #1
	strh r0, [r1]
	b _08028344
_08028304:
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08028344
	movs r0, #4
	mov r1, sl
	adds r1, #0xa6
	strb r0, [r1]
	mov r0, sl
	adds r0, #0xbc
	str r2, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08028334 @ =0x000008D4
	add r0, sl
	ldrh r1, [r0]
	ldr r0, _08028338 @ =0x00000896
	add r0, sl
	strh r1, [r0]
	movs r0, #1
	b _08028346
	.align 2, 0
_08028334: .4byte 0x000008D4
_08028338: .4byte 0x00000896
_0802833C:
	ldr r1, _08028358 @ =0x00000898
	add r1, sl
	movs r0, #0x1e
	strb r0, [r1]
_08028344:
	movs r0, #0
_08028346:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08028358: .4byte 0x00000898

	thumb_func_start FUN_0802835c
FUN_0802835c: @ 0x0802835C
	push {lr}
	adds r1, r0, #0
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08028376
	ldr r2, _0802837C @ =0x00000893
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _08028380
_08028376:
	movs r0, #0
	b _08028382
	.align 2, 0
_0802837C: .4byte 0x00000893
_08028380:
	movs r0, #1
_08028382:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08028388
FUN_08028388: @ 0x08028388
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x48
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r0, [r0]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x15
	ldr r0, _080283B8 @ =0x00000884
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, r2
	ble _080283BC
	subs r0, #1
	b _080283C2
	.align 2, 0
_080283B8: .4byte 0x00000884
_080283BC:
	cmp r0, r2
	bge _080283C4
	adds r0, #1
_080283C2:
	strh r0, [r1]
_080283C4:
	ldr r1, _080283E0 @ =0x00000884
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r3, r0, r1
	ldr r2, _080283E4 @ =0x00000886
	adds r0, r4, r2
	ldrh r0, [r0]
	muls r0, r3, r0
	cmp r0, #0
	blt _080283E8
	asrs r0, r0, #7
	b _080283EE
	.align 2, 0
_080283E0: .4byte 0x00000884
_080283E4: .4byte 0x00000886
_080283E8:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_080283EE:
	adds r3, r0, #0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r2, #8
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	muls r0, r3, r0
	cmp r0, #0
	blt _08028404
	asrs r1, r0, #8
	b _0802840A
_08028404:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0802840A:
	ldrh r0, [r5]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08028440 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldrh r1, [r5, #2]
	adds r1, #0x78
	lsls r1, r1, #0x10
	ldr r0, _08028444 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r1, #4
	ldrsh r0, [r5, r1]
	movs r2, #0xc
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	muls r0, r3, r0
	cmp r0, #0
	blt _08028448
	asrs r1, r0, #8
	b _0802844E
	.align 2, 0
_08028440: .4byte 0xFFFF0000
_08028444: .4byte 0x0000FFFF
_08028448:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0802844E:
	ldrh r0, [r5, #4]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08028470 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	bl FUN_0823b8ac
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028470: .4byte 0xFFFF0000

	thumb_func_start FUN_08028474
FUN_08028474: @ 0x08028474
	push {r4, r5, r6, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	movs r2, #0
	ldrsh r3, [r1, r2]
	movs r4, #0
	ldrsh r2, [r0, r4]
	subs r3, r3, r2
	movs r2, #4
	ldrsh r1, [r1, r2]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r2, r1, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r4, r1, r0
	cmp r4, #0
	bne _080284A2
	strb r4, [r5]
	strh r4, [r6]
	b _080284B4
_080284A2:
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	strb r0, [r5]
	adds r0, r4, #0
	bl Sqrt
	strh r0, [r6]
_080284B4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080284bc
FUN_080284bc: @ 0x080284BC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	mov r3, sp
	ldr r2, _080284EC @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080284F0
	asrs r1, r0, #0xc
	b _080284F6
	.align 2, 0
_080284EC: .4byte 0x085B0A08
_080284F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080284F6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802850E
	asrs r0, r0, #0xc
	b _08028514
_0802850E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08028514:
	strh r0, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r5]
	mov r1, sp
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r4, [r4, #4]
	adds r0, r0, r4
	strh r0, [r5, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802853c
FUN_0802853c: @ 0x0802853C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r2, #0
	ldr r0, _080285AC @ =0x0000084C
	adds r2, r6, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080285B0 @ =0x00000844
	adds r0, r6, r1
	mov r4, sp
	adds r4, #2
	adds r1, r2, #0
	mov r2, sp
	adds r3, r4, #0
	bl FUN_08028474
	ldr r3, _080285B4 @ =0x0000082C
	adds r2, r6, r3
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #8
	str r0, [r2]
	ldr r0, _080285B8 @ =0x00000838
	adds r1, r6, r0
	ldrh r0, [r4]
	lsls r0, r0, #8
	str r0, [r1]
	adds r3, #0x14
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080285BC @ =0x00000842
	adds r0, r6, r1
	strh r5, [r0]
	subs r3, #0x18
	adds r0, r6, r3
	ldr r1, [r2]
	ldr r0, [r0]
	subs r2, r1, r0
	adds r1, r2, #0
	cmp r2, #0
	bge _08028598
	rsbs r1, r2, #0
_08028598:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	ble _080285D2
	cmp r2, #0
	bge _080285C0
	movs r0, #0x80
	lsls r0, r0, #9
	adds r2, r2, r0
	b _080285C4
	.align 2, 0
_080285AC: .4byte 0x0000084C
_080285B0: .4byte 0x00000844
_080285B4: .4byte 0x0000082C
_080285B8: .4byte 0x00000838
_080285BC: .4byte 0x00000842
_080285C0:
	ldr r1, _080285F4 @ =0xFFFF0000
	adds r2, r2, r1
_080285C4:
	ldr r3, _080285F8 @ =0x0000082C
	adds r1, r6, r3
	subs r3, #4
	adds r0, r6, r3
	ldr r0, [r0]
	adds r0, r0, r2
	str r0, [r1]
_080285D2:
	movs r0, #0x83
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r2, _080285FC @ =0x00000828
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r3, _08028600 @ =0x0000083C
	adds r1, r6, r3
	adds r2, #0xc
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080285F4: .4byte 0xFFFF0000
_080285F8: .4byte 0x0000082C
_080285FC: .4byte 0x00000828
_08028600: .4byte 0x0000083C

	thumb_func_start FUN_08028604
FUN_08028604: @ 0x08028604
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _0802863C @ =0x00000844
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x50
	mov r5, sp
	adds r5, #2
	mov r2, sp
	adds r3, r5, #0
	bl FUN_08028474
	ldr r0, _08028640 @ =0x00000828
	adds r1, r4, r0
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #8
	str r0, [r1]
	ldr r1, _08028644 @ =0x00000834
	adds r4, r4, r1
	ldrh r0, [r5]
	lsls r0, r0, #8
	str r0, [r4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802863C: .4byte 0x00000844
_08028640: .4byte 0x00000828
_08028644: .4byte 0x00000834

	thumb_func_start FUN_08028648
FUN_08028648: @ 0x08028648
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0x84
	lsls r0, r0, #4
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldr r1, _080286C4 @ =0x00000842
	adds r1, r1, r4
	mov r8, r1
	ldrh r1, [r1]
	ldrh r3, [r5]
	subs r6, r1, r3
	movs r2, #0x83
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	muls r0, r6, r0
	ldr r7, _080286C8 @ =0x0000082C
	adds r2, r4, r7
	ldr r2, [r2]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	ldr r1, _080286CC @ =0x00000828
	adds r7, r4, r1
	str r0, [r7]
	ldr r2, _080286D0 @ =0x0000083C
	adds r0, r4, r2
	ldr r0, [r0]
	muls r0, r6, r0
	subs r2, #4
	adds r1, r4, r2
	ldrh r2, [r5]
	ldr r1, [r1]
	muls r1, r2, r1
	adds r0, r0, r1
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	ldr r1, _080286D4 @ =0x00000834
	adds r4, r4, r1
	str r0, [r4]
	ldr r0, [r7]
	cmp r0, #0
	bge _080286B6
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	str r0, [r7]
_080286B6:
	ldrh r0, [r7]
	str r0, [r7]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080286C4: .4byte 0x00000842
_080286C8: .4byte 0x0000082C
_080286CC: .4byte 0x00000828
_080286D0: .4byte 0x0000083C
_080286D4: .4byte 0x00000834

	thumb_func_start FUN_080286d8
FUN_080286d8: @ 0x080286D8
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x50
	ldr r0, _080286F4 @ =0x00000844
	adds r1, r3, r0
	ldr r2, _080286F8 @ =0x00000828
	adds r0, r3, r2
	ldr r0, [r0]
	cmp r0, #0
	blt _080286FC
	asrs r0, r0, #8
	b _08028702
	.align 2, 0
_080286F4: .4byte 0x00000844
_080286F8: .4byte 0x00000828
_080286FC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08028702:
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	ldr r5, _0802871C @ =0x00000834
	adds r0, r3, r5
	ldr r3, [r0]
	lsls r3, r3, #8
	lsrs r3, r3, #0x10
	adds r0, r4, #0
	bl FUN_080284bc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802871C: .4byte 0x00000834

	thumb_func_start FUN_08028720
FUN_08028720: @ 0x08028720
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r6, r2, #0
	adds r5, r3, #0
	mov ip, r0
	movs r3, #0
	cmp r3, r8
	bge _08028780
_08028734:
	lsls r0, r3, #2
	movs r1, #0x86
	lsls r1, r1, #1
	add r1, ip
	adds r1, r1, r0
	ldr r0, [r1]
	adds r1, r0, #0
	cmp r1, #0
	beq _0802877A
	movs r0, #0
	ldrsh r2, [r1, r0]
	movs r4, #0
	ldrsh r0, [r6, r4]
	movs r4, #0
	cmp r2, r0
	blt _08028772
	movs r7, #0
	ldrsh r0, [r5, r7]
	cmp r2, r0
	bgt _08028772
	movs r0, #4
	ldrsh r1, [r1, r0]
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r1, r0
	blt _08028772
	movs r7, #4
	ldrsh r0, [r5, r7]
	cmp r1, r0
	bgt _08028772
	movs r4, #1
_08028772:
	cmp r4, #0
	beq _0802877A
	adds r0, r3, #0
	b _08028784
_0802877A:
	adds r3, #1
	cmp r3, r8
	blt _08028734
_08028780:
	movs r0, #1
	rsbs r0, r0, #0
_08028784:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08028790
FUN_08028790: @ 0x08028790
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xc7
	cmp r0, #0
	beq _080287AE
	movs r1, #0xc5
_080287AE:
	lsls r1, r1, #5
	mov r8, r1
	ldr r2, _08028808 @ =0x000008F4
	adds r4, r5, r2
	movs r7, #0
	movs r6, #2
_080287BA:
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sb
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	ldr r3, _0802880C @ =0x00000201
	bl FUN_0822f3fc
	movs r0, #0x82
	lsls r0, r0, #7
	strh r0, [r4, #0x3a]
	ldr r0, _08028810 @ =0x03003584
	ldr r1, [r0]
	add r1, r8
	ldr r2, _08028814 @ =0x0000093C
	adds r0, r5, r2
	adds r0, r0, r7
	str r1, [r0]
	adds r4, #0x60
	adds r7, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080287BA
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028808: .4byte 0x000008F4
_0802880C: .4byte 0x00000201
_08028810: .4byte 0x03003584
_08028814: .4byte 0x0000093C

	thumb_func_start FUN_08028818
FUN_08028818: @ 0x08028818
	push {r4, r5, lr}
	ldr r1, _08028834 @ =0x000008F4
	adds r4, r0, r1
	movs r5, #2
_08028820:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08028820
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08028834: .4byte 0x000008F4

	thumb_func_start FUN_08028838
FUN_08028838: @ 0x08028838
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r7, r1, #0
	mov r8, r2
	ldr r0, _08028898 @ =0x000008E6
	adds r5, r4, r0
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0802889C @ =0x000008FC
	adds r6, r4, r1
	adds r0, r6, r0
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r2, _080288A0 @ =0x000008F4
	adds r0, r0, r2
	adds r0, r4, r0
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #9
	bl FUN_0822f588
	ldrh r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080288A4
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	b _080288B4
	.align 2, 0
_08028898: .4byte 0x000008E6
_0802889C: .4byte 0x000008FC
_080288A0: .4byte 0x000008F4
_080288A4:
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
_080288B4:
	orrs r1, r2
	str r1, [r0]
	ldr r5, _08028900 @ =0x000008E6
	adds r3, r4, r5
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r1, _08028904 @ =0x00000914
	adds r0, r0, r1
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0]
	str r2, [r0, #4]
	ldrh r1, [r3]
	lsls r1, r1, #1
	adds r5, #8
	adds r0, r4, r5
	adds r0, r0, r1
	mov r1, r8
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08028908 @ =0x000008E8
	adds r1, r4, r2
	adds r1, r1, r0
	movs r0, #0xc
	strh r0, [r1]
	cmp r7, #0
	beq _0802890C
	cmp r7, #1
	bne _0802890C
	movs r1, #0xc8
	b _08028914
	.align 2, 0
_08028900: .4byte 0x000008E6
_08028904: .4byte 0x00000914
_08028908: .4byte 0x000008E8
_0802890C:
	adds r0, r4, #0
	bl FUN_08027ed0
	adds r1, r0, #0
_08028914:
	ldr r0, _08028954 @ =0x03003584
	lsls r1, r1, #5
	ldr r2, [r0]
	adds r2, r2, r1
	ldr r5, _08028958 @ =0x000008E6
	adds r3, r4, r5
	ldrh r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r5, #0x56
	adds r0, r4, r5
	adds r0, r0, r1
	str r2, [r0]
	ldrh r0, [r3]
	adds r0, #1
	movs r1, #0
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _08028942
	strh r1, [r3]
_08028942:
	ldr r2, _0802895C @ =0x000008E4
	adds r0, r4, r2
	strh r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028954: .4byte 0x03003584
_08028958: .4byte 0x000008E6
_0802895C: .4byte 0x000008E4

	thumb_func_start FUN_08028960
FUN_08028960: @ 0x08028960
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	add r2, sp, #4
	ldr r1, _080289F0 @ =0x00000868
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrh r0, [r2, #2]
	subs r0, #0x80
	strh r0, [r2, #2]
	movs r7, #0
	movs r2, #0
	mov r8, r2
	ldr r0, _080289F4 @ =0x00000914
	adds r5, r6, r0
_08028988:
	lsls r1, r7, #1
	ldr r2, _080289F8 @ =0x000008E8
	adds r0, r6, r2
	adds r4, r0, r1
	ldrh r0, [r4]
	cmp r0, #0
	beq _080289CC
	adds r2, #6
	adds r0, r6, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _080289B2
	movs r0, #6
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r5, #0
	add r2, sp, #4
	movs r3, #0x10
	bl FUN_08237970
_080289B2:
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080289CC
	ldr r1, _080289FC @ =0x000008FC
	adds r0, r6, r1
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080289CC:
	movs r2, #0x60
	add r8, r2
	adds r5, #0x60
	adds r7, #1
	cmp r7, #2
	ble _08028988
	ldr r0, _08028A00 @ =0x000008E4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080289F0: .4byte 0x00000868
_080289F4: .4byte 0x00000914
_080289F8: .4byte 0x000008E8
_080289FC: .4byte 0x000008FC
_08028A00: .4byte 0x000008E4

	thumb_func_start FUN_08028a04
FUN_08028a04: @ 0x08028A04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r3, r0, #0
	adds r3, #0x48
	adds r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #1
	bhi _08028A44
	ldr r2, _08028A38 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	movs r1, #0x40
	orrs r0, r1
	ldr r1, _08028A3C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0x10
	adds r4, r0, #0
	orrs r4, r1
	ands r2, r5
	ldr r0, _08028A40 @ =0x0000FF80
	b _08028A5E
	.align 2, 0
_08028A38: .4byte 0xFFFF0000
_08028A3C: .4byte 0x0000FFFF
_08028A40: .4byte 0x0000FF80
_08028A44:
	ldr r2, _08028AEC @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	ldr r1, _08028AF0 @ =0x0000FF80
	orrs r0, r1
	adds r1, #0x7f
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0x10
	adds r4, r0, #0
	orrs r4, r1
	ands r2, r5
	movs r0, #0x40
_08028A5E:
	adds r5, r2, #0
	orrs r5, r0
	adds r3, #8
	str r3, [sp, #0x10]
	ldr r0, _08028AF4 @ =0x030046B8
	mov sl, r0
	ldr r1, _08028AF8 @ =0x000003FF
	mov sb, r1
	movs r2, #0x7f
	mov r8, r2
	movs r7, #3
	add r6, sp, #8
_08028A76:
	mov r0, sl
	ldr r1, [r0]
	adds r1, #1
	mov r2, sb
	ands r1, r2
	lsls r0, r1, #1
	ldr r2, _08028AFC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, r4, r0
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r2, r4, #0x10
	lsls r2, r2, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r2
	str r0, [sp, #8]
	adds r1, #1
	mov r0, sb
	ands r1, r0
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _08028AFC @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	adds r0, r5, r0
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r6, #4]
	ldr r2, _08028AEC @ =0xFFFF0000
	ands r1, r2
	orrs r1, r0
	str r1, [r6, #4]
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	add r1, sp, #8
	movs r2, #0
	movs r3, #0
	bl FUN_080dc0a0
	subs r7, #1
	cmp r7, #0
	bge _08028A76
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028AEC: .4byte 0xFFFF0000
_08028AF0: .4byte 0x0000FF80
_08028AF4: .4byte 0x030046B8
_08028AF8: .4byte 0x000003FF
_08028AFC: .4byte 0x0203B400

	thumb_func_start FUN_08028b00
FUN_08028b00: @ 0x08028B00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r1, r0, r1
	str r1, [sp, #0x1c]
	add r0, sp, #0x10
	mov sl, r0
	ldr r7, _08028BF4 @ =0x0203B400
	movs r1, #2
	str r1, [sp, #0x18]
	ldr r0, _08028BF8 @ =0x030046B8
	mov sb, r0
	ldr r6, _08028BFC @ =0x000003FF
	movs r1, #3
	mov r8, r1
_08028B28:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r1, #0xa4
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r1, sl
	ldr r0, [r1, #4]
	ldr r1, _08028C00 @ =0xFFFF0000
	ands r0, r1
	movs r1, #0xa4
	orrs r0, r1
	mov r1, sl
	str r0, [r1, #4]
	mov r0, sb
	ldr r1, [r0]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r3, [r0]
	movs r0, #0xff
	ands r3, r0
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	ands r2, r0
	adds r2, #2
	adds r1, #1
	ands r1, r6
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	adds r0, #0x14
	ldr r5, [sp, #0x1c]
	adds r5, #0x20
	str r2, [sp]
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #3
	add r2, sp, #0x10
	bl FUN_080ddcc8
	mov r0, sb
	ldr r1, [r0]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r3, [r0]
	movs r0, #0xff
	ands r3, r0
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	ands r2, r0
	adds r2, #2
	adds r1, #1
	ands r1, r6
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	adds r0, #0x14
	str r2, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #3
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r0, [sp, #0x18]
	subs r0, #1
	str r0, [sp, #0x18]
	cmp r0, #0
	bge _08028B28
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028BF4: .4byte 0x0203B400
_08028BF8: .4byte 0x030046B8
_08028BFC: .4byte 0x000003FF
_08028C00: .4byte 0xFFFF0000

	thumb_func_start FUN_08028c04
FUN_08028c04: @ 0x08028C04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r1, r0, r1
	str r1, [sp, #0x18]
	movs r0, #0xa4
	mov sl, r0
	add r4, sp, #0x10
	ldr r7, _08028CA0 @ =0x0203B400
	movs r6, #1
	ldr r1, _08028CA4 @ =0x030046B8
	mov sb, r1
	ldr r5, _08028CA8 @ =0x000003FF
	movs r0, #3
	mov r8, r0
_08028C2C:
	movs r0, #0x80
	lsls r0, r0, #0xd
	mov r1, sl
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [r4, #4]
	ldr r1, _08028CAC @ =0xFFFF0000
	ands r0, r1
	mov r1, sl
	orrs r0, r1
	str r0, [r4, #4]
	mov r0, sb
	ldr r1, [r0]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrb r3, [r0]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	ands r2, r0
	adds r2, #2
	adds r1, #1
	ands r1, r5
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	adds r0, #0x14
	str r2, [sp]
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x18]
	adds r0, #0x20
	movs r1, #3
	add r2, sp, #0x10
	bl FUN_080ddcc8
	subs r6, #1
	cmp r6, #0
	bge _08028C2C
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028CA0: .4byte 0x0203B400
_08028CA4: .4byte 0x030046B8
_08028CA8: .4byte 0x000003FF
_08028CAC: .4byte 0xFFFF0000

	thumb_func_start FUN_08028cb0
FUN_08028cb0: @ 0x08028CB0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	add r2, sp, #0x10
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r0, [r2, #2]
	adds r0, #0x40
	strh r0, [r2, #2]
	add r5, sp, #0x18
	ldr r7, _08028DAC @ =0x0203B400
	movs r0, #2
	mov sl, r0
	ldr r1, _08028DB0 @ =0x030046B8
	mov sb, r1
	ldr r6, _08028DB4 @ =0x000003FF
	movs r0, #3
	mov r8, r0
_08028CE4:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r5, #4]
	ldr r1, _08028DB8 @ =0xFFFF0000
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r5, #4]
	mov r0, sb
	ldr r1, [r0]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r3, [r0]
	movs r0, #0xff
	ands r3, r0
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	ands r2, r0
	adds r2, #2
	adds r1, #1
	ands r1, r6
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	adds r0, #0x14
	str r2, [sp]
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #3
	adds r2, r5, #0
	bl FUN_080ddcc8
	mov r0, sb
	ldr r1, [r0]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r3, [r0]
	movs r0, #0xff
	ands r3, r0
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	ands r2, r0
	adds r2, #2
	adds r1, #1
	ands r1, r6
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	adds r0, #0x14
	str r2, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #3
	adds r2, r5, #0
	bl FUN_080ddcc8
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r1, sl
	cmp r1, #0
	bge _08028CE4
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028DAC: .4byte 0x0203B400
_08028DB0: .4byte 0x030046B8
_08028DB4: .4byte 0x000003FF
_08028DB8: .4byte 0xFFFF0000

	thumb_func_start FUN_08028dbc
FUN_08028dbc: @ 0x08028DBC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #4
	adds r0, r0, r7
	mov r8, r0
	ldr r0, _08028E28 @ =0x0000CB05
	ldr r1, _08028E2C @ =0x0000DE23
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r0, r7, r2
	adds r3, r0, #0
	adds r2, r1, #0
	ldm r2!, {r4, r5, r6}
	stm r3!, {r4, r5, r6}
	ldm r2!, {r4, r5, r6}
	stm r3!, {r4, r5, r6}
	ldm r2!, {r4, r5}
	stm r3!, {r4, r5}
	bl OpenSpriteSetFile
	movs r6, #0xc5
	lsls r6, r6, #2
	adds r0, r7, r6
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r6, r7, r0
	add r5, sp, #0x10
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08028E30
	asrs r0, r0, #8
	b _08028E36
	.align 2, 0
_08028E28: .4byte 0x0000CB05
_08028E2C: .4byte 0x0000DE23
_08028E30:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08028E36:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08028E48
	asrs r0, r0, #8
	b _08028E4E
_08028E48:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08028E4E:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r5, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08028E62
	asrs r0, r0, #8
	b _08028E68
_08028E62:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08028E68:
	subs r2, r4, r0
	movs r5, #0
	adds r4, r4, r0
	ldr r3, _08028EB4 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r4, #0xa2
	lsls r4, r4, #4
	adds r1, r7, r4
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r5, sp, #0x10
	str r5, [sp, #0xc]
	mov r0, r8
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028EB4: .4byte 0x030047C8

	thumb_func_start FUN_08028eb8
FUN_08028eb8: @ 0x08028EB8
	push {lr}
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r0, r0, r1
	bl FUN_0822f1c0
	pop {r0}
	bx r0

	thumb_func_start FUN_08028ec8
FUN_08028ec8: @ 0x08028EC8
	push {lr}
	adds r2, r0, #0
	ldr r0, _08028EF8 @ =0x00000173
	adds r1, r2, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08028EFC
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0xf7
	cmp r0, #0
	bne _08028F00
	movs r1, #0x30
	b _08028F00
	.align 2, 0
_08028EF8: .4byte 0x00000173
_08028EFC:
	movs r1, #0xe7
	lsls r1, r1, #1
_08028F00:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08028f08
FUN_08028f08: @ 0x08028F08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	adds r4, r6, #0
	adds r0, #0x48
	str r0, [sp, #0x18]
	ldr r1, _08028F54 @ =0x0000104C
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08028F28
	b _08029150
_08028F28:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08028F3A
	movs r0, #0
	strb r0, [r1]
_08028F3A:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _08028F44
	b _08029068
_08028F44:
	ldr r3, _08028F58 @ =0x00000864
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08028F5C
	movs r3, #1
	b _08028F62
	.align 2, 0
_08028F54: .4byte 0x0000104C
_08028F58: .4byte 0x00000864
_08028F5C:
	ldr r1, _08028FB4 @ =0x00000899
	adds r0, r6, r1
	ldrb r3, [r0]
_08028F62:
	movs r2, #0
	mov sb, r2
	ldr r2, _08028FB8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08028FBC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08028FC0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r0, #0xc0
	ands r5, r0
	lsls r0, r3, #2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r2, r4, r3
	add r4, sp, #8
	movs r1, #0xc8
	lsls r1, r1, #1
	mov sl, r1
	adds r7, r2, r0
	movs r2, #2
	mov r8, r2
_08028F94:
	ldr r2, _08028FC4 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08028FC8
	asrs r1, r0, #0xc
	b _08028FCE
	.align 2, 0
_08028FB4: .4byte 0x00000899
_08028FB8: .4byte 0x030046B8
_08028FBC: .4byte 0x000003FF
_08028FC0: .4byte 0x0203B400
_08028FC4: .4byte 0x085B0A08
_08028FC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08028FCE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	ldr r2, _08028FF0 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08028FF4
	asrs r3, r0, #0xc
	b _08028FFA
	.align 2, 0
_08028FF0: .4byte 0x085B0A08
_08028FF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08028FFA:
	strh r3, [r4, #4]
	ldr r2, [r7]
	ldrh r0, [r2]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	adds r0, r3, r0
	strh r0, [r4, #4]
	ldr r2, [sp, #0x18]
	ldrh r0, [r2, #0xa]
	adds r0, #0xa4
	strh r0, [r4, #2]
	ldr r2, [r7]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #0
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r3, [r7]
	ldr r1, _08029064 @ =0x0000104C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xf
	str r1, [sp]
	mov r2, sb
	str r2, [sp, #4]
	add r1, sp, #8
	movs r2, #0
	bl FUN_0805a360
	adds r5, #0x55
	movs r3, #0x40
	add sb, r3
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _08028F94
	b _08029146
	.align 2, 0
_08029064: .4byte 0x0000104C
_08029068:
	ldr r2, _080290C0 @ =0x00000899
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r0, r6, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	adds r0, #5
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x18
	adds r5, r0, #0
	subs r5, #0x30
	movs r0, #0
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov sl, r1
	movs r0, #0x86
	lsls r0, r0, #1
	adds r2, r6, r0
	add r4, sp, #0x10
	adds r7, r6, #0
	adds r7, #0x50
	movs r1, #6
	mov r8, r1
	lsls r0, r3, #2
	adds r2, r2, r0
	str r2, [sp, #0x1c]
_0802909E:
	ldr r2, _080290C4 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _080290C8
	asrs r1, r0, #0xc
	b _080290CE
	.align 2, 0
_080290C0: .4byte 0x00000899
_080290C4: .4byte 0x085B0A08
_080290C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080290CE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	ldr r1, _080290F0 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _080290F4
	asrs r0, r0, #0xc
	b _080290FA
	.align 2, 0
_080290F0: .4byte 0x085B0A08
_080290F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080290FA:
	strh r0, [r4, #4]
	add r1, sp, #0x10
	ldr r2, [sp, #0x18]
	ldrh r0, [r2, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r1, [r4, #2]
	ldrh r0, [r7, #2]
	adds r1, r1, r0
	ldrh r0, [r7, #4]
	ldrh r2, [r4, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	adds r1, #0xa4
	strh r1, [r4, #2]
	ldr r0, [sp, #0x1c]
	ldr r3, [r0]
	ldr r1, _08029160 @ =0x0000104C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xc
	str r1, [sp]
	mov r2, sb
	str r2, [sp, #4]
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0805a360
	movs r3, #0x18
	add sb, r3
	adds r5, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0802909E
_08029146:
	movs r2, #0xba
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
_08029150:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029160: .4byte 0x0000104C

	thumb_func_start FUN_08029164
FUN_08029164: @ 0x08029164
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r3, r1, #0
	movs r0, #0x48
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _080291E4 @ =0x00001050
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08029186
	b _080292A2
_08029186:
	ldr r2, _080291E8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080291EC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080291F0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r5, [r0]
	movs r0, #0x1f
	ands r5, r0
	adds r0, #0xe1
	mov sl, r0
	lsls r3, r3, #2
	str r3, [sp, #0x14]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x18]
	add r4, sp, #8
	movs r2, #2
	mov sb, r2
	adds r3, r7, #0
	adds r3, #0x50
	str r3, [sp, #0x10]
_080291BA:
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x14]
	adds r0, r1, r2
	ldr r6, [r0]
	ldr r2, _080291F4 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080291F8
	asrs r1, r0, #0xc
	b _080291FE
	.align 2, 0
_080291E4: .4byte 0x00001050
_080291E8: .4byte 0x030046B8
_080291EC: .4byte 0x000003FF
_080291F0: .4byte 0x0203B400
_080291F4: .4byte 0x085B0A08
_080291F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080291FE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	ldr r2, _08029220 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08029224
	asrs r1, r0, #0xc
	b _0802922A
	.align 2, 0
_08029220: .4byte 0x085B0A08
_08029224:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802922A:
	mov r2, r8
	ldrh r0, [r2, #8]
	ldrh r3, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldr r2, [sp, #0x10]
	ldrh r0, [r2, #4]
	adds r0, r1, r0
	strh r0, [r4, #4]
	mov r3, r8
	ldrh r0, [r3, #0xa]
	adds r0, #0xa4
	strh r0, [r4, #2]
	adds r5, #0x56
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r2, #0
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r6, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _080292B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080292B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080292BC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r3, r3, r0
	subs r3, #0x10
	ldr r2, _080292C0 @ =0x00001050
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xf
	str r1, [sp]
	ldr r2, _080292C4 @ =0x000008BE
	adds r1, r7, r2
	ldrh r1, [r1]
	str r1, [sp, #4]
	add r1, sp, #8
	adds r2, r6, #0
	bl FUN_0805b0b0
	movs r3, #1
	rsbs r3, r3, #0
	add sb, r3
	mov r0, sb
	cmp r0, #0
	bge _080291BA
_080292A2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080292B4: .4byte 0x030046B8
_080292B8: .4byte 0x000003FF
_080292BC: .4byte 0x0203B400
_080292C0: .4byte 0x00001050
_080292C4: .4byte 0x000008BE

	thumb_func_start FUN_080292c8
FUN_080292c8: @ 0x080292C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	str r1, [sp, #0x28]
	str r7, [sp, #0x2c]
	adds r0, #0x48
	str r0, [sp, #0x30]
	add r2, sp, #0x10
	ldr r0, [r7, #0x50]
	ldr r1, [r7, #0x54]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r0, r7, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	add r6, sp, #0x18
	cmp r0, #1
	beq _08029324
	cmp r0, #1
	bgt _08029302
	cmp r0, #0
	beq _0802930C
	b _08029368
_08029302:
	cmp r0, #2
	beq _0802933A
	cmp r0, #3
	beq _0802934E
	b _08029368
_0802930C:
	ldrh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	subs r0, #0xa0
	strh r0, [r2, #4]
	ldrh r0, [r6, #4]
	subs r0, #0x60
	strh r0, [r6, #4]
	b _08029368
_08029324:
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #0x80
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r6]
	adds r0, #0x40
	b _08029366
_0802933A:
	ldrh r0, [r2, #2]
	adds r0, #0xf0
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r2, #4]
	ldrh r0, [r6, #4]
	adds r0, #0x40
	strh r0, [r6, #4]
	b _08029368
_0802934E:
	ldrh r0, [r2, #2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	strh r0, [r2, #2]
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xa0
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r6]
	subs r0, #0x60
_08029366:
	strh r0, [r6]
_08029368:
	add r0, sp, #0x10
	ldrh r0, [r0, #2]
	subs r0, #0x20
	strh r0, [r6, #2]
	ldr r3, _08029480 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r3
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _08029484 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x20]
	mov r0, sp
	adds r0, #0x20
	str r0, [sp, #0x34]
	ldr r0, [r0, #4]
	ands r0, r3
	orrs r0, r2
	ldr r1, [sp, #0x34]
	str r0, [r1, #4]
	ldr r2, [sp, #0x30]
	ldrb r2, [r2, #5]
	mov r8, r2
	movs r3, #0x80
	add r8, r3
	ldr r0, _08029488 @ =0x0203B400
	mov sl, r0
	ldr r1, _0802948C @ =0x030046B8
	ldr r2, [r1]
	adds r2, #1
	ldr r3, _08029490 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	movs r0, #1
	ands r1, r0
	adds r1, #2
	adds r2, #1
	ands r2, r3
	lsls r0, r2, #1
	add r0, sl
	ldrh r3, [r0]
	movs r0, #0x1f
	ands r3, r0
	add r3, r8
	subs r3, #0x10
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	ldrh r4, [r0]
	movs r0, #3
	ands r4, r0
	adds r4, #4
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	ldr r0, _0802948C @ =0x030046B8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	movs r2, #1
	mov sb, r2
	ands r0, r2
	adds r0, #1
	str r4, [sp]
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r6, #0
	ldr r2, [sp, #0x34]
	bl FUN_080ddcc8
	ldr r3, _0802948C @ =0x030046B8
	ldr r2, [r3]
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	movs r3, #1
	ands r1, r3
	adds r1, #2
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	movs r3, #0x1f
	ands r0, r3
	add r8, r0
	movs r0, #0x10
	rsbs r0, r0, #0
	add r8, r0
	adds r2, #1
	ldr r3, _08029490 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	add r0, sl
	ldrh r3, [r0]
	movs r0, #3
	ands r3, r0
	adds r3, #4
	adds r2, #1
	ldr r0, _08029490 @ =0x000003FF
	ands r2, r0
	ldr r0, _0802948C @ =0x030046B8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	mov r2, sb
	ands r0, r2
	adds r0, #1
	str r3, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r6, #0
	ldr r2, [sp, #0x34]
	mov r3, r8
	bl FUN_080ddcc8
	ldr r3, [sp, #0x28]
	cmp r3, #1
	beq _080294E8
	cmp r3, #1
	bgt _08029494
	cmp r3, #0
	beq _080294A2
	b _0802960C
	.align 2, 0
_08029480: .4byte 0xFFFF0000
_08029484: .4byte 0x0000FFFF
_08029488: .4byte 0x0203B400
_0802948C: .4byte 0x030046B8
_08029490: .4byte 0x000003FF
_08029494:
	ldr r0, [sp, #0x28]
	cmp r0, #2
	beq _0802952C
	cmp r0, #3
	bne _080294A0
	b _080295D8
_080294A0:
	b _0802960C
_080294A2:
	ldr r1, _080294DC @ =0x00000899
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r1, r1, #2
	ldr r2, [sp, #0x2c]
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, _080294E0 @ =0x00001054
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _080294E4 @ =0x000008DA
	adds r1, r7, r3
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, #0x20
	str r1, [sp, #4]
	subs r3, #0x26
	adds r1, r7, r3
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0
	b _080295BA
	.align 2, 0
_080294DC: .4byte 0x00000899
_080294E0: .4byte 0x00001054
_080294E4: .4byte 0x000008DA
_080294E8:
	ldr r1, _08029520 @ =0x00000899
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r1, r1, #2
	ldr r2, [sp, #0x2c]
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, _08029524 @ =0x00001054
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, [sp, #0x30]
	ldrb r1, [r3, #5]
	str r1, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	ldr r3, _08029528 @ =0x000008B6
	adds r1, r7, r3
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #1
	b _080295BA
	.align 2, 0
_08029520: .4byte 0x00000899
_08029524: .4byte 0x00001054
_08029528: .4byte 0x000008B6
_0802952C:
	ldr r0, _080295C8 @ =0x00000899
	adds r5, r7, r0
	ldrb r0, [r5]
	lsls r0, r0, #2
	ldr r1, [sp, #0x2c]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r4, r1, r2
	adds r0, r4, r0
	ldr r2, [r0]
	ldr r3, _080295CC @ =0x00001054
	adds r3, r7, r3
	str r3, [sp, #0x38]
	ldr r0, [r3]
	ldr r1, _080295D0 @ =0x000008DA
	adds r1, r1, r7
	mov sb, r1
	ldrb r1, [r1]
	subs r1, #0x20
	str r1, [sp]
	movs r3, #0x18
	mov r8, r3
	str r3, [sp, #4]
	ldr r1, _080295D4 @ =0x000008B8
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r7, #0xa
	str r7, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #2
	bl FUN_0805b7d4
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r2, [r0]
	ldr r3, [sp, #0x38]
	ldr r0, [r3]
	mov r3, sb
	ldrb r1, [r3]
	str r1, [sp]
	mov r1, r8
	str r1, [sp, #4]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3]
	str r1, [sp, #8]
	str r7, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #2
	bl FUN_0805b7d4
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r2, [r4]
	ldr r1, [sp, #0x38]
	ldr r0, [r1]
	mov r3, sb
	ldrb r1, [r3]
	adds r1, #0x20
	str r1, [sp]
	mov r1, r8
	str r1, [sp, #4]
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3]
	str r1, [sp, #8]
	str r7, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #2
_080295BA:
	bl FUN_0805b7d4
	movs r0, #0xcd
	bl PlaySound_0824078c
	b _0802960C
	.align 2, 0
_080295C8: .4byte 0x00000899
_080295CC: .4byte 0x00001054
_080295D0: .4byte 0x000008DA
_080295D4: .4byte 0x000008B8
_080295D8:
	ldr r1, _0802961C @ =0x000008DA
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r3, #0x10
	movs r0, #0xff
	ands r3, r0
	asrs r3, r3, #5
	adds r3, #3
	movs r0, #7
	ands r3, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r2, _08029620 @ =0x000008CC
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp, #8]
	add r0, sp, #0x10
	movs r1, #0x2c
	movs r2, #2
	bl FUN_080c0fa0
	ldr r0, _08029624 @ =0x00000345
	bl PlaySound_0824078c
_0802960C:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802961C: .4byte 0x000008DA
_08029620: .4byte 0x000008CC
_08029624: .4byte 0x00000345

	thumb_func_start FUN_08029628
FUN_08029628: @ 0x08029628
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov r5, sb
	movs r0, #0x48
	add r0, sb
	mov sl, r0
	ldr r0, _08029698 @ =0x00000899
	add r0, sb
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r2, _0802969C @ =0x00000868
	add r2, sb
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r7, r0, #0
	movs r0, #0x40
	rsbs r0, r0, #0
	ands r7, r0
	mov r3, sp
	movs r4, #0xc0
	lsls r4, r4, #2
	ldr r2, _080296A0 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080296A4
	asrs r1, r0, #0xc
	b _080296AA
	.align 2, 0
_08029698: .4byte 0x00000899
_0802969C: .4byte 0x00000868
_080296A0: .4byte 0x085B0A08
_080296A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080296AA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _080296C8 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080296CC
	asrs r0, r0, #0xc
	b _080296D2
	.align 2, 0
_080296C8: .4byte 0x085B0A08
_080296CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080296D2:
	strh r0, [r3, #4]
	ldr r0, _08029780 @ =0x00000899
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r3, r3, r5
	mov r8, r3
	add r0, r8
	ldr r2, [r0]
	mov r6, sp
	mov r1, sp
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r4, [r6, #4]
	adds r0, r0, r4
	strh r0, [r6, #4]
	ldr r5, _08029784 @ =0x00000868
	add r5, sb
	movs r1, #0
	ldrsh r0, [r5, r1]
	mov r2, sl
	movs r3, #8
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r5, r4]
	movs r3, #0xc
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #0
	ldrsh r0, [r5, r1]
	mov r1, sp
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r5, r3]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r4, r4, r0
	mov r5, r8
	cmp r4, #0
	bge _08029756
	rsbs r4, r4, #0
_08029756:
	cmp r4, #0x1f
	bgt _0802975C
	adds r7, #0x40
_0802975C:
	ldr r3, _08029788 @ =0x0000084C
	add r3, sb
	movs r4, #0xc0
	lsls r4, r4, #2
	ldr r2, _0802978C @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08029790
	asrs r1, r0, #0xc
	b _08029796
	.align 2, 0
_08029780: .4byte 0x00000899
_08029784: .4byte 0x00000868
_08029788: .4byte 0x0000084C
_0802978C: .4byte 0x085B0A08
_08029790:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08029796:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080297B2
	asrs r0, r0, #0xc
	b _080297B8
_080297B2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080297B8:
	strh r0, [r3, #4]
	ldr r0, _080297F4 @ =0x00000899
	add r0, sb
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r5, r0
	ldr r2, [r0]
	ldr r1, _080297F8 @ =0x0000084C
	add r1, sb
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080297F4: .4byte 0x00000899
_080297F8: .4byte 0x0000084C

	thumb_func_start FUN_080297fc
FUN_080297fc: @ 0x080297FC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	bl FUN_08022a2c
	adds r3, r0, #0
	cmp r3, #0
	beq _08029836
	movs r1, #0
	movs r2, #0x1d
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x50]
	str r1, [r3, #0x54]
	ldr r0, _0802983C @ =0x00000347
	bl PlaySound_0824078c
_08029836:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802983C: .4byte 0x00000347

	thumb_func_start FUN_08029840
FUN_08029840: @ 0x08029840
	push {lr}
	movs r0, #1
	bl FUN_08022a2c
	cmp r0, #0
	beq _0802985A
	ldr r1, _08029860 @ =0x00001058
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0802985A
	bl FUN_0805d5d4
_0802985A:
	pop {r0}
	bx r0
	.align 2, 0
_08029860: .4byte 0x00001058

	thumb_func_start FUN_08029864
FUN_08029864: @ 0x08029864
	push {r4, lr}
	adds r4, r0, #0
	cmp r4, #0
	ble _080298AE
	movs r0, #1
	bl FUN_08022a2c
	adds r3, r0, #0
	cmp r3, #0
	beq _080298AE
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	adds r0, r3, #0
	adds r0, #0x90
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	cmp r1, #1
	ble _080298AA
	ldr r2, _080298B4 @ =0x000008D8
	adds r0, r3, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r0, r1, r0
	cmp r0, #0
	bge _080298A6
	rsbs r0, r0, #0
_080298A6:
	cmp r0, #0x31
	bgt _080298AE
_080298AA:
	bl FUN_08029840
_080298AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080298B4: .4byte 0x000008D8

	thumb_func_start FUN_080298b8
FUN_080298b8: @ 0x080298B8
	push {r4, lr}
	adds r4, r0, #0
	cmp r4, #0
	ble _080298D6
	movs r0, #1
	bl FUN_08022a2c
	cmp r0, #0
	beq _080298D6
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_080298D6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080298dc
FUN_080298dc: @ 0x080298DC
	push {lr}
	movs r0, #4
	bl FUN_08022a2c
	cmp r0, #0
	beq _080298F4
	movs r1, #0x80
	lsls r1, r1, #0xf
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	b _080298F6
_080298F4:
	movs r0, #0
_080298F6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080298fc
FUN_080298fc: @ 0x080298FC
	push {lr}
	ldr r1, _08029914 @ =0x00000FD4
	adds r2, r0, r1
	movs r1, #1
	strb r1, [r2]
	ldr r2, _08029918 @ =0x000008A4
	adds r1, r0, r2
	ldrh r1, [r1]
	bl FUN_08028074
	pop {r0}
	bx r0
	.align 2, 0
_08029914: .4byte 0x00000FD4
_08029918: .4byte 0x000008A4

	thumb_func_start FUN_0802991c
FUN_0802991c: @ 0x0802991C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x18
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r6, _080299CC @ =0x0203B400
	ldr r2, _080299D0 @ =0x030046B8
	mov sb, r2
	ldr r1, [r2]
	adds r1, #1
	ldr r5, _080299D4 @ =0x000003FF
	ands r1, r5
	lsls r2, r1, #1
	adds r2, r2, r6
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080299D8 @ =0xFFFF0000
	mov r8, r2
	ldr r4, [sp, #0x10]
	ands r4, r2
	orrs r4, r0
	str r4, [sp, #0x10]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	asrs r3, r4, #0x10
	movs r2, #0x3f
	ands r0, r2
	adds r3, r3, r0
	lsls r3, r3, #0x10
	ldr r0, _080299DC @ =0x0000FFFF
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	adds r1, #1
	ands r1, r5
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	movs r2, #0xc0
	lsls r2, r2, #6
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #2
	movs r3, #0x40
	bl FUN_08015d3c
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080299CC: .4byte 0x0203B400
_080299D0: .4byte 0x030046B8
_080299D4: .4byte 0x000003FF
_080299D8: .4byte 0xFFFF0000
_080299DC: .4byte 0x0000FFFF

	thumb_func_start FUN_080299e0
FUN_080299e0: @ 0x080299E0
	push {lr}
	adds r1, r0, #0
	ldr r0, _080299F0 @ =0x03002BF0
	ldrh r0, [r0]
	cmp r0, #0
	beq _080299F4
	movs r0, #4
	b _08029A10
	.align 2, 0
_080299F0: .4byte 0x03002BF0
_080299F4:
	adds r0, r1, #0
	adds r0, #0x50
	bl FUN_0809df78
	cmp r0, #0
	bne _08029A04
	movs r0, #0
	b _08029A10
_08029A04:
	ldr r0, _08029A14 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08029A18 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
_08029A10:
	pop {r1}
	bx r1
	.align 2, 0
_08029A14: .4byte 0x030046A0
_08029A18: .4byte 0x00000942

	thumb_func_start FUN_08029a1c
FUN_08029a1c: @ 0x08029A1C
	push {lr}
	adds r2, r0, #0
	cmp r1, #0x5f
	ble _08029A60
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029A3C
	ldr r1, _08029A38 @ =0x00000824
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #2
	bne _08029AAE
	b _08029A52
	.align 2, 0
_08029A38: .4byte 0x00000824
_08029A3C:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08029AAE
	ldr r1, _08029A5C @ =0x00000FD4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029AAE
_08029A52:
	movs r0, #0xd2
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _08029AAE
	.align 2, 0
_08029A5C: .4byte 0x00000FD4
_08029A60:
	cmp r1, #0x3f
	ble _08029AA8
	adds r0, r2, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029A80
	ldr r1, _08029A7C @ =0x00000824
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #2
	bne _08029AAE
	b _08029A96
	.align 2, 0
_08029A7C: .4byte 0x00000824
_08029A80:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08029AAE
	ldr r1, _08029AA0 @ =0x00000FD4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029AAE
_08029A96:
	ldr r0, _08029AA4 @ =0x00000349
	bl PlaySound_0824078c
	b _08029AAE
	.align 2, 0
_08029AA0: .4byte 0x00000FD4
_08029AA4: .4byte 0x00000349
_08029AA8:
	ldr r0, _08029AB4 @ =0x0000034A
	bl PlaySound_0824078c
_08029AAE:
	pop {r0}
	bx r0
	.align 2, 0
_08029AB4: .4byte 0x0000034A

	thumb_func_start FUN_08029ab8
FUN_08029ab8: @ 0x08029AB8
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xfe
	lsls r0, r0, #4
	adds r0, r0, r4
	mov sb, r0
	add r6, sp, #0x14
	movs r5, #0
	str r5, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r6, #0
	ldr r2, _08029B24 @ =0x05000002
	bl CpuSet
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r1, r1, r4
	mov r8, r1
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sb
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3fc
	str r5, [sp]
	mov r0, sb
	mov r1, r8
	movs r2, #0x16
	movs r3, #2
	bl FUN_082370cc
	ldr r1, _08029B28 @ =0x00000FD5
	adds r0, r4, r1
	strb r5, [r0]
	ldr r0, _08029B2C @ =0x00000FD6
	adds r4, r4, r0
	strb r5, [r4]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08029B24: .4byte 0x05000002
_08029B28: .4byte 0x00000FD5
_08029B2C: .4byte 0x00000FD6

	thumb_func_start FUN_08029b30
FUN_08029b30: @ 0x08029B30
	push {lr}
	movs r1, #0xfe
	lsls r1, r1, #4
	adds r0, r0, r1
	bl FUN_0822f1c0
	pop {r0}
	bx r0

	thumb_func_start FUN_08029b40
FUN_08029b40: @ 0x08029B40
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xfe
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r1, _08029BBC @ =0x00000FD4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029C1C
	movs r6, #0x80
	lsls r6, r6, #5
	adds r2, r5, r6
	adds r1, #4
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r4, #0
	bl FUN_082372cc
	subs r6, #0x2a
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029C02
	ldr r2, _08029BC0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08029BC4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08029BC8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	ldr r2, _08029BCC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08029BD0
	asrs r1, r0, #0xc
	b _08029BD6
	.align 2, 0
_08029BBC: .4byte 0x00000FD4
_08029BC0: .4byte 0x030046B8
_08029BC4: .4byte 0x000003FF
_08029BC8: .4byte 0x0203B400
_08029BCC: .4byte 0x085B0A08
_08029BD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08029BD6:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08029BF6
	asrs r2, r0, #0xc
	b _08029BFC
_08029BF6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08029BFC:
	ldrh r0, [r4, #0x24]
	adds r0, r0, r2
	strh r0, [r4, #0x24]
_08029C02:
	ldr r6, _08029C18 @ =0x00000FD5
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029C24
	ldrh r0, [r4, #0x14]
	cmp r0, #0xa
	bne _08029C24
	movs r0, #2
	strh r0, [r4, #0x14]
	b _08029C24
	.align 2, 0
_08029C18: .4byte 0x00000FD5
_08029C1C:
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
_08029C24:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08029c2c
FUN_08029c2c: @ 0x08029C2C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xfe
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0x16
	movs r3, #1
	bl FUN_082370cc
	movs r1, #0xc1
	strh r1, [r5, #0x3a]
	ldr r0, _08029C6C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r5, #0x48]
	ldr r0, _08029C70 @ =0x00000FD4
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08029C6C: .4byte 0x03003584
_08029C70: .4byte 0x00000FD4

	thumb_func_start FUN_08029c74
FUN_08029c74: @ 0x08029C74
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xfe
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0x48
	movs r3, #1
	bl FUN_082370cc
	movs r2, #0
	movs r0, #0xc3
	strh r0, [r5, #0x3a]
	ldr r0, _08029CBC @ =0x03003584
	ldr r0, [r0]
	movs r1, #0xc3
	lsls r1, r1, #5
	adds r0, r0, r1
	str r0, [r5, #0x48]
	ldr r0, _08029CC0 @ =0x00000FD5
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08029CC4 @ =0x00000FD6
	adds r4, r4, r1
	strb r2, [r4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08029CBC: .4byte 0x03003584
_08029CC0: .4byte 0x00000FD5
_08029CC4: .4byte 0x00000FD6

	thumb_func_start FUN_08029cc8
FUN_08029cc8: @ 0x08029CC8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xfe
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0x16
	movs r3, #1
	bl FUN_082370cc
	movs r2, #0
	movs r1, #0xc1
	strh r1, [r5, #0x3a]
	ldr r0, _08029D10 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r5, #0x48]
	ldr r1, _08029D14 @ =0x00000FD5
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _08029D18 @ =0x00000FD6
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08029D10: .4byte 0x03003584
_08029D14: .4byte 0x00000FD5
_08029D18: .4byte 0x00000FD6

	thumb_func_start FUN_08029d1c
FUN_08029d1c: @ 0x08029D1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _08029DC8 @ =0x00000B48
	adds r4, r7, r0
	movs r6, #1
_08029D2C:
	adds r0, r4, #0
	ldr r1, _08029DCC @ =0x00003668
	bl Video_GetActorSprite
	adds r4, #0x1c
	subs r6, #1
	cmp r6, #0
	bge _08029D2C
	ldr r1, _08029DC8 @ =0x00000B48
	adds r0, r7, r1
	movs r1, #0xc4
	bl FUN_0822b20c
	ldr r2, _08029DD0 @ =0x00000B64
	adds r0, r7, r2
	movs r1, #0xc8
	bl FUN_0822b20c
	ldr r0, _08029DD4 @ =0x0000922E
	ldr r1, _08029DD8 @ =0x000078E1
	bl GetFile
	movs r2, #0xfd
	lsls r2, r2, #4
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #0xb9
	lsls r0, r0, #4
	adds r4, r7, r0
	movs r1, #0
	mov r8, r1
	movs r2, #0xe5
	lsls r2, r2, #4
	adds r5, r7, r2
	movs r6, #0xf
_08029D72:
	adds r0, r4, #0
	ldr r2, _08029DC8 @ =0x00000B48
	adds r1, r7, r2
	movs r2, #0x11
	bl FUN_0822a470
	movs r1, #0xfd
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_08237098
	movs r0, #1
	strb r0, [r4, #7]
	adds r1, r4, #0
	adds r1, #0x1c
	mov r0, r8
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r2, _08029DDC @ =0x05000002
	bl CpuSet
	adds r5, #0x10
	subs r6, #1
	adds r4, #0x2c
	cmp r6, #0
	bge _08029D72
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029DC8: .4byte 0x00000B48
_08029DCC: .4byte 0x00003668
_08029DD0: .4byte 0x00000B64
_08029DD4: .4byte 0x0000922E
_08029DD8: .4byte 0x000078E1
_08029DDC: .4byte 0x05000002

	thumb_func_start FUN_08029de0
FUN_08029de0: @ 0x08029DE0
	push {r4, r5, lr}
	movs r1, #0xb9
	lsls r1, r1, #4
	adds r4, r0, r1
	movs r5, #0xf
_08029DEA:
	adds r0, r4, #0
	bl FUN_0822a4e0
	subs r5, #1
	adds r4, #0x2c
	cmp r5, #0
	bge _08029DEA
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08029e00
FUN_08029e00: @ 0x08029E00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov r5, sp
	mov r2, sl
	adds r2, #0x50
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08029E30
	asrs r0, r0, #8
	b _08029E36
_08029E30:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08029E36:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08029E48
	asrs r0, r0, #8
	b _08029E4E
_08029E48:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08029E4E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08029E62
	asrs r0, r0, #8
	b _08029E68
_08029E62:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08029E68:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08029F18 @ =0x030047C8
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
	movs r1, #0
	mov sb, r1
	mov r8, sp
	movs r5, #0xb9
	lsls r5, r5, #4
	add r5, sl
	movs r2, #0xb8
	lsls r2, r2, #4
	add r2, sl
	mov ip, r2
	mov r7, sl
_08029E9C:
	mov r4, ip
	ldrb r0, [r4]
	cmp r0, #0
	bne _08029EA6
	b _08029FE6
_08029EA6:
	mov r1, sb
	lsls r0, r1, #3
	movs r2, #0xf5
	lsls r2, r2, #4
	adds r0, r0, r2
	mov r4, sl
	adds r2, r4, r0
	ldr r1, _08029F1C @ =0x00000E5E
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08029ECA
	ldrh r0, [r2, #2]
	subs r0, #1
	strh r0, [r2, #2]
_08029ECA:
	mov r4, r8
	ldrh r0, [r4]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #2]
	ldrh r4, [r2, #2]
	adds r0, r0, r4
	strh r0, [r5, #0x1e]
	mov r1, r8
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r5, #0x20]
	movs r2, #0xe5
	lsls r2, r2, #4
	adds r3, r7, r2
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r3, #4]
	adds r2, r6, #0
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r6
	cmp r2, r0
	beq _08029F20
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08029F28
	.align 2, 0
_08029F18: .4byte 0x030047C8
_08029F1C: .4byte 0x00000E5E
_08029F20:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08029F28:
	str r0, [r5]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r4, #2
	ands r0, r4
	cmp r1, r0
	beq _08029F4C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08029F54
_08029F4C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08029F54:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _08029F8C @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _08029FD2
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08029F96
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _08029F90
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _08029FAC
	.align 2, 0
_08029F8C: .4byte 0x0000FFFF
_08029F90:
	subs r0, #1
	strh r0, [r3, #8]
	b _08029FAA
_08029F96:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _08029FAA
	strh r1, [r3, #8]
	movs r2, #1
	b _08029FAC
_08029FAA:
	movs r2, #0
_08029FAC:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08029FD4
	movs r0, #1
	strb r0, [r3, #7]
	b _08029FD4
_08029FD2:
	movs r2, #0
_08029FD4:
	cmp r2, #0
	beq _08029FE6
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r0, #0
	mov r4, ip
	strb r0, [r4]
_08029FE6:
	movs r0, #1
	add ip, r0
	adds r7, #0x10
	add sb, r0
	adds r5, #0x2c
	mov r1, sb
	cmp r1, #0xf
	bgt _08029FF8
	b _08029E9C
_08029FF8:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802a008
FUN_0802a008: @ 0x0802A008
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #4]
	adds r7, r2, #0
	adds r5, r3, #0
	cmp r7, #0xc
	ble _0802A022
	b _0802A1F8
_0802A022:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0802A02A
	adds r7, #0x10
_0802A02A:
	movs r1, #0
	str r1, [sp, #8]
	ldr r4, _0802A0A0 @ =0x030046B8
	ldr r2, _0802A0A4 @ =0x000003FF
	mov ip, r2
	movs r0, #7
	mov sl, r0
	movs r1, #0xe5
	lsls r1, r1, #4
	adds r1, r1, r6
	mov r8, r1
	ldr r1, _0802A0A8 @ =0x085AABD8
_0802A042:
	movs r2, #0xb8
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r2, [sp, #8]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A054
	b _0802A1E8
_0802A054:
	movs r0, #0x2c
	muls r0, r2, r0
	movs r2, #0xb9
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, r0, r6
	mov sb, r0
	ldr r2, [sp, #8]
	lsls r0, r2, #3
	movs r2, #0xf5
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r3, r6, r0
	subs r0, r5, #2
	cmp r0, #1
	bhi _0802A0B0
	ldr r0, [r4]
	adds r0, #1
	mov r2, ip
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0802A0AC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r2, r7, #1
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r1, [sp, #0xc]
	mov r1, sl
	ands r0, r1
	ldr r1, [sp, #0xc]
	subs r0, r0, r1
	subs r0, #0xe
	b _0802A0D8
	.align 2, 0
_0802A0A0: .4byte 0x030046B8
_0802A0A4: .4byte 0x000003FF
_0802A0A8: .4byte 0x085AABD8
_0802A0AC: .4byte 0x0203B400
_0802A0B0:
	ldr r0, [r4]
	adds r0, #1
	mov r2, ip
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0802A100 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r2, r7, #1
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r1, [sp, #0xc]
	mov r1, sl
	ands r0, r1
	ldr r1, [sp, #0xc]
	adds r0, r0, r1
	adds r0, #6
_0802A0D8:
	strh r0, [r3]
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0802A104
	cmp r5, #0
	beq _0802A0E8
	cmp r5, #3
	bne _0802A144
_0802A0E8:
	ldr r0, [r4]
	adds r0, #1
	mov r1, ip
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0802A100 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r7, #0
	subs r0, #0x10
	b _0802A122
	.align 2, 0
_0802A100: .4byte 0x0203B400
_0802A104:
	cmp r5, #0
	beq _0802A10C
	cmp r5, #3
	bne _0802A144
_0802A10C:
	ldr r0, [r4]
	adds r0, #1
	mov r1, ip
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0802A13C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x10
_0802A122:
	lsls r0, r0, #1
	ldr r4, _0802A140 @ =0x085AABD9
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r2, sl
	ands r1, r2
	adds r1, r1, r0
	subs r1, #0x28
	strh r1, [r3, #2]
	b _0802A16A
	.align 2, 0
_0802A13C: .4byte 0x0203B400
_0802A140: .4byte 0x085AABD9
_0802A144:
	ldr r0, [r4]
	adds r0, #1
	mov r1, ip
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r4, _0802A194 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r4, _0802A198 @ =0x085AABD9
	adds r1, r2, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov r2, sl
	ands r0, r2
	adds r0, r0, r1
	subs r0, #0x28
	strh r0, [r3, #2]
_0802A16A:
	movs r4, #0
	strh r4, [r3, #4]
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0802A1A0
	mov r0, sb
	ldr r2, _0802A19C @ =0x00000B48
	adds r1, r6, r2
	bl FUN_0822a4fc
	movs r1, #0xfd
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	str r4, [sp]
	mov r0, r8
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	b _0802A1BE
	.align 2, 0
_0802A194: .4byte 0x0203B400
_0802A198: .4byte 0x085AABD9
_0802A19C: .4byte 0x00000B48
_0802A1A0:
	mov r0, sb
	ldr r2, _0802A1E4 @ =0x00000B64
	adds r1, r6, r2
	bl FUN_0822a4fc
	movs r1, #0xfd
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	str r4, [sp]
	mov r0, r8
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
_0802A1BE:
	mov r0, r8
	movs r1, #0x20
	bl FUN_08237098
	mov r2, sb
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r4, #0xb8
	lsls r4, r4, #4
	adds r0, r6, r4
	ldr r1, [sp, #8]
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	b _0802A1F8
	.align 2, 0
_0802A1E4: .4byte 0x00000B64
_0802A1E8:
	movs r2, #0x10
	add r8, r2
	ldr r0, [sp, #8]
	adds r0, #1
	str r0, [sp, #8]
	cmp r0, #0xf
	bgt _0802A1F8
	b _0802A042
_0802A1F8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802a208
FUN_0802a208: @ 0x0802A208
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0xaa
	lsls r0, r0, #4
	adds r6, r4, r0
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r1, r1, r4
	mov r8, r1
	movs r0, #2
	str r0, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r0, r4, r2
	str r0, [sp, #0xc]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3fc
	str r5, [sp]
	adds r0, r6, #0
	mov r1, r8
	movs r2, #0x4e
	movs r3, #2
	bl FUN_082370cc
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0802A2C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0802A2C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0802A2C8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x70
	ldr r2, _0802A2CC @ =0x00000B01
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0802A2D0 @ =0x00000B02
	adds r1, r4, r0
	movs r0, #4
	strb r0, [r1]
	adds r2, #2
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802A2D4 @ =0x00000B04
	adds r0, r4, r1
	strh r5, [r0]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _0802A2D8 @ =0x00000B06
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0802A2DC @ =0x00000B08
	adds r5, r4, r0
	movs r1, #0xac
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0801385c
	adds r0, r5, #0
	bl FUN_080136b4
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802A2C0: .4byte 0x030046B8
_0802A2C4: .4byte 0x000003FF
_0802A2C8: .4byte 0x0203B400
_0802A2CC: .4byte 0x00000B01
_0802A2D0: .4byte 0x00000B02
_0802A2D4: .4byte 0x00000B04
_0802A2D8: .4byte 0x00000B06
_0802A2DC: .4byte 0x00000B08

	thumb_func_start FUN_0802a2e0
FUN_0802a2e0: @ 0x0802A2E0
	push {r4, lr}
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r4, r0, r1
	adds r1, #0x68
	adds r0, r0, r1
	bl FUN_080138fc
	adds r0, r4, #0
	bl FUN_0822f1c0
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802a2fc
FUN_0802a2fc: @ 0x0802A2FC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0xaa
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0802A320
	cmp r0, #1
	bgt _0802A31A
	b _0802A4FC
_0802A31A:
	cmp r0, #2
	beq _0802A3FC
	b _0802A4FC
_0802A320:
	ldr r2, _0802A34C @ =0x00000B01
	adds r0, r4, r2
	ldr r7, _0802A350 @ =0x00000B02
	adds r1, r4, r7
	add r3, sp, #4
	ldrb r6, [r0]
	ldrb r7, [r1]
	ldr r2, _0802A354 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802A358
	asrs r1, r0, #0xc
	b _0802A35E
	.align 2, 0
_0802A34C: .4byte 0x00000B01
_0802A350: .4byte 0x00000B02
_0802A354: .4byte 0x085B0A08
_0802A358:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802A35E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802A376
	asrs r0, r0, #0xc
	b _0802A37C
_0802A376:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802A37C:
	strh r0, [r3, #4]
	ldr r7, _0802A39C @ =0x00000B04
	adds r0, r4, r7
	ldrh r0, [r0]
	lsls r0, r0, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802A3A0
	asrs r3, r0, #0xc
	b _0802A3A6
	.align 2, 0
_0802A39C: .4byte 0x00000B04
_0802A3A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0802A3A6:
	add r2, sp, #4
	movs r6, #0
	strh r3, [r2, #2]
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r2, #0
	ldrh r0, [r0]
	ldrh r7, [r5, #0x20]
	adds r0, r0, r7
	strh r0, [r5, #0x20]
	ldrh r0, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldr r7, _0802A3F8 @ =0x00000B04
	adds r2, r4, r7
	ldrh r0, [r2]
	cmp r0, #0x41
	bhi _0802A3D4
	b _0802A4FC
_0802A3D4:
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	strh r6, [r2]
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r4, r2
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x4f
	movs r3, #1
	bl FUN_082370cc
	b _0802A4FC
	.align 2, 0
_0802A3F8: .4byte 0x00000B04
_0802A3FC:
	ldr r7, _0802A454 @ =0x00000B04
	adds r0, r4, r7
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #7
	bne _0802A42A
	ldr r0, _0802A458 @ =0x00000B02
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bls _0802A418
	subs r0, #1
	strb r0, [r1]
_0802A418:
	ldr r2, _0802A45C @ =0x00000B03
	adds r1, r4, r2
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #7
	bgt _0802A42A
	adds r0, r2, #1
	strb r0, [r1]
_0802A42A:
	ldr r7, _0802A460 @ =0x00000B01
	adds r0, r4, r7
	ldr r2, _0802A458 @ =0x00000B02
	adds r1, r4, r2
	add r3, sp, #4
	ldrb r6, [r0]
	ldrb r7, [r1]
	ldr r2, _0802A464 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802A468
	asrs r1, r0, #0xc
	b _0802A46E
	.align 2, 0
_0802A454: .4byte 0x00000B04
_0802A458: .4byte 0x00000B02
_0802A45C: .4byte 0x00000B03
_0802A460: .4byte 0x00000B01
_0802A464: .4byte 0x085B0A08
_0802A468:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802A46E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802A486
	asrs r0, r0, #0xc
	b _0802A48C
_0802A486:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802A48C:
	movs r6, #0
	strh r0, [r3, #4]
	ldr r7, _0802A528 @ =0x00000B03
	adds r0, r4, r7
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	add r3, sp, #4
	strh r1, [r3, #2]
	adds r2, r5, #0
	adds r2, #0x20
	adds r0, r3, #0
	ldrh r0, [r0]
	ldrh r7, [r5, #0x20]
	adds r0, r0, r7
	strh r0, [r5, #0x20]
	ldrh r0, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	movs r2, #0x22
	ldrsh r1, [r5, r2]
	ldr r7, _0802A52C @ =0x00000B06
	adds r0, r4, r7
	ldrh r0, [r0]
	cmp r1, r0
	bge _0802A4FC
	strh r0, [r5, #0x22]
	movs r0, #0xb0
	lsls r0, r0, #4
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _0802A530 @ =0x00000B04
	adds r0, r4, r1
	strh r6, [r0]
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r4, r2
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x50
	movs r3, #2
	bl FUN_082370cc
	adds r7, #2
	adds r0, r4, r7
	bl FUN_080136b4
	ldr r0, _0802A534 @ =0x000002A7
	bl PlaySound_082406e0
_0802A4FC:
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A514
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r5, #0
	bl FUN_082372cc
_0802A514:
	ldr r7, _0802A530 @ =0x00000B04
	adds r1, r4, r7
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A528: .4byte 0x00000B03
_0802A52C: .4byte 0x00000B06
_0802A530: .4byte 0x00000B04
_0802A534: .4byte 0x000002A7

	thumb_func_start FUN_0802a538
FUN_0802a538: @ 0x0802A538
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r2, #0xac
	lsls r2, r2, #4
	adds r3, r4, r2
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r3]
	str r2, [r3, #4]
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	movs r3, #0x96
	lsls r3, r3, #1
	adds r1, r3, #0
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	movs r5, #0
	strh r1, [r0, #0x22]
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r3, #1
	strb r3, [r1]
	ldr r1, _0802A5C8 @ =0x00000B01
	adds r2, r4, r1
	movs r1, #0x60
	strb r1, [r2]
	ldr r1, _0802A5CC @ =0x00000B02
	adds r2, r4, r1
	movs r1, #4
	strb r1, [r2]
	ldr r2, _0802A5D0 @ =0x00000B03
	adds r1, r4, r2
	strb r3, [r1]
	ldr r3, _0802A5D4 @ =0x00000B04
	adds r1, r4, r3
	strh r5, [r1]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r2, [r1]
	adds r3, #2
	adds r1, r4, r3
	strh r2, [r1]
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r4, r2
	str r5, [sp]
	movs r2, #0x4e
	movs r3, #1
	bl FUN_082370cc
	ldr r3, _0802A5D8 @ =0x00000B08
	adds r4, r4, r3
	adds r0, r4, #0
	bl FUN_08013698
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802A5C8: .4byte 0x00000B01
_0802A5CC: .4byte 0x00000B02
_0802A5D0: .4byte 0x00000B03
_0802A5D4: .4byte 0x00000B04
_0802A5D8: .4byte 0x00000B08

	thumb_func_start FUN_0802a5dc
FUN_0802a5dc: @ 0x0802A5DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r7, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp]
	movs r1, #0
	mov sl, r1
	ldr r0, _0802A608 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0802AB18
	.align 2, 0
_0802A608: .4byte 0x03002B4C
_0802A60C:
	ldr r0, _0802A640 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, sl
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, [sp]
	adds r0, #8
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r0, [sp]
	adds r1, r6, #0
	bl FUN_08022474
	ldrb r0, [r6, #6]
	cmp r0, #0x20
	bls _0802A634
	b _0802AB0A
_0802A634:
	lsls r0, r0, #2
	ldr r1, _0802A644 @ =_0802A648
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A640: .4byte 0x03002B4C
_0802A644: .4byte _0802A648
_0802A648: @ jump table
	.4byte _0802A6CC @ case 0
	.4byte _0802A710 @ case 1
	.4byte _0802A6E4 @ case 2
	.4byte _0802A758 @ case 3
	.4byte _0802A77A @ case 4
	.4byte _0802A7B8 @ case 5
	.4byte _0802A7E0 @ case 6
	.4byte _0802A808 @ case 7
	.4byte _0802A810 @ case 8
	.4byte _0802A818 @ case 9
	.4byte _0802AB0A @ case 10
	.4byte _0802A828 @ case 11
	.4byte _0802A830 @ case 12
	.4byte _0802A87C @ case 13
	.4byte _0802A924 @ case 14
	.4byte _0802A92C @ case 15
	.4byte _0802A968 @ case 16
	.4byte _0802A970 @ case 17
	.4byte _0802A998 @ case 18
	.4byte _0802A9A0 @ case 19
	.4byte _0802A9C8 @ case 20
	.4byte _0802A9D0 @ case 21
	.4byte _0802AB0A @ case 22
	.4byte _0802A9D8 @ case 23
	.4byte _0802A9E0 @ case 24
	.4byte _0802A9E8 @ case 25
	.4byte _0802A9F0 @ case 26
	.4byte _0802A9F8 @ case 27
	.4byte _0802AA00 @ case 28
	.4byte _0802AA08 @ case 29
	.4byte _0802AA4C @ case 30
	.4byte _0802AA10 @ case 31
	.4byte _0802AA32 @ case 32
_0802A6CC:
	movs r2, #2
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	b _0802AA28
_0802A6E4:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #1
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _0802AB0A
_0802A710:
	ldrh r0, [r6, #8]
	adds r1, r7, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrh r0, [r6, #0xa]
	adds r3, r7, #0
	adds r3, #0x52
	strh r0, [r3]
	ldrh r0, [r6, #0xc]
	adds r2, r7, #0
	adds r2, #0x54
	strh r0, [r2]
	ldrh r1, [r1]
	movs r4, #0xc5
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r3, [r3]
	adds r0, r0, r3
	ldr r3, _0802A754 @ =0x00000316
	adds r1, r5, r3
	strh r0, [r1]
	ldrh r1, [r2]
	adds r4, #4
	adds r0, r5, r4
	strh r1, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0802AA40
	.align 2, 0
_0802A754: .4byte 0x00000316
_0802A758:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	strb r0, [r1]
	movs r1, #2
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	b _0802AA24
_0802A77A:
	ldrh r1, [r6, #8]
	ldr r3, _0802A7B0 @ =0x0000084C
	adds r0, r5, r3
	movs r3, #0
	strh r1, [r0]
	ldrh r1, [r6, #0xa]
	ldr r4, _0802A7B4 @ =0x0000084E
	adds r0, r5, r4
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r2, #0x85
	lsls r2, r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #2
	movs r2, #3
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	movs r3, #0
	str r3, [r0]
	b _0802AA28
	.align 2, 0
_0802A7B0: .4byte 0x0000084C
_0802A7B4: .4byte 0x0000084E
_0802A7B8:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #4
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _0802AA28
_0802A7E0:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #5
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _0802AA28
_0802A808:
	movs r1, #2
	movs r2, #0
	movs r3, #6
	b _0802AA16
_0802A810:
	movs r1, #2
	movs r2, #0
	movs r3, #7
	b _0802AA16
_0802A818:
	movs r3, #8
	ldrsh r1, [r6, r3]
	adds r0, r7, #0
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080230d8
	b _0802AA3A
_0802A828:
	movs r1, #2
	movs r2, #0
	movs r3, #8
	b _0802AA16
_0802A830:
	ldrh r1, [r6, #8]
	ldr r2, _0802A870 @ =0x0000084C
	adds r0, r5, r2
	movs r4, #0
	strh r1, [r0]
	ldrh r1, [r6, #0xa]
	ldr r3, _0802A874 @ =0x0000084E
	adds r0, r5, r3
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _0802A878 @ =0x00000171
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	movs r1, #2
	movs r2, #9
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r4, [r0]
	subs r0, #0x14
	strb r3, [r0]
	b _0802AB0A
	.align 2, 0
_0802A870: .4byte 0x0000084C
_0802A874: .4byte 0x0000084E
_0802A878: .4byte 0x00000171
_0802A87C:
	ldrh r0, [r6, #8]
	ldr r2, _0802A91C @ =0x0000084C
	adds r3, r5, r2
	movs r4, #0
	mov r8, r4
	movs r1, #0
	mov sb, r1
	strh r0, [r3]
	ldrh r1, [r6, #0xa]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r4, #0x85
	lsls r4, r4, #4
	adds r0, r5, r4
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x50
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r7, r4
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r3, r7, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	ldr r1, _0802A920 @ =0x00000171
	adds r0, r5, r1
	mov r2, r8
	strb r2, [r0]
	movs r1, #2
	movs r2, #9
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	mov r3, r8
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	mov r4, sb
	str r4, [r0]
	b _0802AA28
	.align 2, 0
_0802A91C: .4byte 0x0000084C
_0802A920: .4byte 0x00000171
_0802A924:
	movs r1, #2
	movs r2, #0
	movs r3, #0xa
	b _0802AA16
_0802A92C:
	ldrh r1, [r6, #8]
	ldr r2, _0802A960 @ =0x0000084C
	adds r0, r5, r2
	movs r3, #0
	strh r1, [r0]
	ldrh r1, [r6, #0xa]
	ldr r4, _0802A964 @ =0x0000084E
	adds r0, r5, r4
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #2
	movs r2, #0xb
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	movs r3, #0
	str r3, [r0]
	b _0802AA28
	.align 2, 0
_0802A960: .4byte 0x0000084C
_0802A964: .4byte 0x0000084E
_0802A968:
	movs r1, #2
	movs r2, #0
	movs r3, #0xc
	b _0802AA16
_0802A970:
	ldrh r1, [r6, #8]
	ldr r4, _0802A994 @ =0x000008CC
	adds r0, r5, r4
	movs r3, #0
	strb r1, [r0]
	movs r1, #2
	movs r2, #0xd
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _0802AA28
	.align 2, 0
_0802A994: .4byte 0x000008CC
_0802A998:
	movs r1, #2
	movs r2, #0
	movs r3, #0xe
	b _0802AA16
_0802A9A0:
	ldrh r0, [r6, #8]
	ldr r1, _0802A9C4 @ =0x0000018B
	adds r2, r5, r1
	movs r3, #0
	strb r0, [r2]
	movs r1, #2
	movs r2, #0xf
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _0802AA28
	.align 2, 0
_0802A9C4: .4byte 0x0000018B
_0802A9C8:
	movs r1, #2
	movs r2, #0
	movs r3, #0x10
	b _0802AA16
_0802A9D0:
	movs r1, #2
	movs r2, #0
	movs r3, #0x11
	b _0802AA16
_0802A9D8:
	movs r1, #2
	movs r2, #0
	movs r3, #0x12
	b _0802AA16
_0802A9E0:
	movs r1, #2
	movs r2, #0
	movs r3, #0x13
	b _0802AA16
_0802A9E8:
	movs r1, #2
	movs r2, #0
	movs r3, #0x14
	b _0802AA16
_0802A9F0:
	movs r1, #2
	movs r2, #0
	movs r3, #0x15
	b _0802AA16
_0802A9F8:
	movs r1, #2
	movs r2, #0
	movs r3, #0x16
	b _0802AA16
_0802AA00:
	movs r1, #2
	movs r2, #0
	movs r3, #0x17
	b _0802AA16
_0802AA08:
	movs r1, #2
	movs r2, #0
	movs r3, #0x18
	b _0802AA16
_0802AA10:
	movs r1, #2
	movs r2, #0
	movs r3, #0x19
_0802AA16:
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
_0802AA24:
	adds r0, #0x16
	str r2, [r0]
_0802AA28:
	adds r1, r7, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802AB0A
_0802AA32:
	ldrh r0, [r6, #8]
	ldr r3, _0802AA48 @ =0x0000018B
	adds r2, r5, r3
	strb r0, [r2]
_0802AA3A:
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r0, r7, r4
_0802AA40:
	movs r1, #1
	bl FUN_08022488
	b _0802AB0A
	.align 2, 0
_0802AA48: .4byte 0x0000018B
_0802AA4C:
	movs r0, #8
	ldrsh r1, [r6, r0]
	cmp r1, #0
	bne _0802AAB8
	ldr r2, _0802AA88 @ =0x00000878
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _0802AA8C @ =0x0000087C
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	ldr r4, _0802AA90 @ =0x0000087A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _0802AA94
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r5, r2
	b _0802AAA2
	.align 2, 0
_0802AA88: .4byte 0x00000878
_0802AA8C: .4byte 0x0000087C
_0802AA90: .4byte 0x0000087A
_0802AA94:
	ldr r0, _0802AAB4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
_0802AAA2:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r5, r4
	ldr r0, [r0]
	str r0, [r1]
	b _0802AAFE
	.align 2, 0
_0802AAB4: .4byte 0x03003584
_0802AAB8:
	movs r0, #5
	movs r2, #0xce
	ldr r3, _0802AADC @ =0x0000087C
	adds r1, r5, r3
	movs r3, #0
	strb r0, [r1]
	ldr r4, _0802AAE0 @ =0x0000087A
	adds r0, r5, r4
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0802AAE8
	ldr r0, _0802AAE4 @ =0x00000878
	adds r1, r5, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _0802AAFE
	.align 2, 0
_0802AADC: .4byte 0x0000087C
_0802AAE0: .4byte 0x0000087A
_0802AAE4: .4byte 0x00000878
_0802AAE8:
	cmp r0, #0
	bne _0802AAF8
	ldr r1, _0802AAF4 @ =0x00000878
	adds r0, r5, r1
	b _0802AAFC
	.align 2, 0
_0802AAF4: .4byte 0x00000878
_0802AAF8:
	ldr r2, _0802AB34 @ =0x00000878
	adds r0, r5, r2
_0802AAFC:
	strh r3, [r0]
_0802AAFE:
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #1
	bl FUN_08022488
_0802AB0A:
	movs r4, #1
	add sl, r4
	ldr r0, _0802AB38 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	ldr r0, [sp]
	adds r0, #6
_0802AB18:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp sl, r0
	bge _0802AB24
	b _0802A60C
_0802AB24:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802AB34: .4byte 0x00000878
_0802AB38: .4byte 0x03002B4C

	thumb_func_start FUN_0802ab3c
FUN_0802ab3c: @ 0x0802AB3C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xca
	lsls r0, r0, #1
	adds r5, r4, r0
	ldr r2, _0802ABCC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _0802ABD0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0802ABD4 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r4, r0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0802ABD8 @ =0x08028051
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r1, _0802ABDC @ =0x000008A8
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0802ABE0 @ =0x000008AA
	adds r0, r4, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	str r0, [sp]
	ldr r0, _0802ABE4 @ =0x000008AC
	adds r4, r4, r0
	movs r3, #0
	ldrsh r0, [r4, r3]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802ABCC: .4byte 0xFFFF0000
_0802ABD0: .4byte 0x0000FFFF
_0802ABD4: .4byte 0x00002001
_0802ABD8: .4byte 0x08028051
_0802ABDC: .4byte 0x000008A8
_0802ABE0: .4byte 0x000008AA
_0802ABE4: .4byte 0x000008AC

	thumb_func_start FUN_0802abe8
FUN_0802abe8: @ 0x0802ABE8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r2, _0802AC7C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x90
	orrs r0, r3
	ldr r1, _0802AC80 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0802AC84 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r4, r0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0802AC88 @ =0x08028051
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r1, _0802AC8C @ =0x000008AE
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0x8b
	lsls r3, r3, #4
	adds r0, r4, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldr r0, _0802AC90 @ =0x000008B2
	adds r4, r4, r0
	movs r3, #0
	ldrsh r0, [r4, r3]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802AC7C: .4byte 0xFFFF0000
_0802AC80: .4byte 0x0000FFFF
_0802AC84: .4byte 0x00002001
_0802AC88: .4byte 0x08028051
_0802AC8C: .4byte 0x000008AE
_0802AC90: .4byte 0x000008B2

	thumb_func_start FUN_0802ac94
FUN_0802ac94: @ 0x0802AC94
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0xf2
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, _0802AD14 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x60
	orrs r0, r3
	ldr r1, _0802AD18 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0802AD1C @ =0x00005101
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0802AD20 @ =FUN_08027f5c
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	ldr r2, _0802AD24 @ =0x00000802
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802AD14: .4byte 0xFFFF0000
_0802AD18: .4byte 0x0000FFFF
_0802AD1C: .4byte 0x00005101
_0802AD20: .4byte FUN_08027f5c
_0802AD24: .4byte 0x00000802

	thumb_func_start FUN_0802ad28
FUN_0802ad28: @ 0x0802AD28
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r2, _0802ADA8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	lsls r3, r3, #1
	orrs r0, r3
	ldr r1, _0802ADAC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0802ADB0 @ =0x00004003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0802ADB4 @ =0x0802802D
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802ADA8: .4byte 0xFFFF0000
_0802ADAC: .4byte 0x0000FFFF
_0802ADB0: .4byte 0x00004003
_0802ADB4: .4byte 0x0802802D

	thumb_func_start FUN_0802adb8
FUN_0802adb8: @ 0x0802ADB8
	push {r4, r5, r6, lr}
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0
	strb r3, [r1]
	ldr r6, _0802AE30 @ =0x00000175
	adds r1, r0, r6
	strb r3, [r1]
	adds r2, #0xc
	adds r1, r0, r2
	strb r3, [r1]
	adds r6, #3
	adds r1, r0, r6
	strb r3, [r1]
	adds r2, #4
	adds r1, r0, r2
	strb r3, [r1]
	adds r6, #3
	adds r2, r0, r6
	movs r1, #3
	strb r1, [r2]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r4, #0
	movs r5, #0x40
	strh r5, [r1]
	adds r6, #7
	adds r1, r0, r6
	strh r3, [r1]
	ldr r2, _0802AE34 @ =0x00000893
	adds r1, r0, r2
	strb r4, [r1]
	ldr r6, _0802AE38 @ =0x000008D4
	adds r1, r0, r6
	movs r2, #0xf0
	strh r2, [r1]
	subs r6, #0x3e
	adds r1, r0, r6
	strh r2, [r1]
	ldr r2, _0802AE3C @ =0x00000899
	adds r1, r0, r2
	strb r4, [r1]
	ldr r6, _0802AE40 @ =0x00000FD4
	adds r1, r0, r6
	strb r4, [r1]
	ldr r2, _0802AE44 @ =0x00001048
	adds r1, r0, r2
	str r5, [r1]
	adds r6, #0x70
	adds r1, r0, r6
	str r3, [r1]
	ldr r1, _0802AE48 @ =0x000008DD
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802AE30: .4byte 0x00000175
_0802AE34: .4byte 0x00000893
_0802AE38: .4byte 0x000008D4
_0802AE3C: .4byte 0x00000899
_0802AE40: .4byte 0x00000FD4
_0802AE44: .4byte 0x00001048
_0802AE48: .4byte 0x000008DD

	thumb_func_start FUN_0802ae4c
FUN_0802ae4c: @ 0x0802AE4C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	mov sb, r7
	adds r4, r7, #0
	adds r4, #0x48
	bl FUN_0802a5dc
	bl FUN_08084710
	adds r1, r0, #0
	ldr r2, _0802AEFC @ =0x00000864
	adds r0, r7, r2
	str r1, [r0]
	cmp r1, #0
	bne _0802AE78
	ldr r3, _0802AF00 @ =0x0000087E
	adds r0, r7, r3
	strb r1, [r0]
_0802AE78:
	adds r0, r4, #0
	bl FUN_0823b4b8
	movs r5, #0xbd
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r7, r0
	adds r0, r7, #0
	bl FUN_08022dfc
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #8]
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	ldrh r5, [r4, #0xa]
	adds r0, r0, r5
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r1, [r4, #0xc]
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r0, r7, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0802AF50
	ldr r2, _0802AF04 @ =0x085B0A08
	movs r4, #0xb7
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0802AF08
	asrs r3, r0, #0xc
	b _0802AF0E
	.align 2, 0
_0802AEFC: .4byte 0x00000864
_0802AF00: .4byte 0x0000087E
_0802AF04: .4byte 0x085B0A08
_0802AF08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0802AF0E:
	movs r4, #0xc5
	lsls r4, r4, #2
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r5, #0xb7
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0802AF3E
	asrs r2, r0, #0xc
	b _0802AF44
_0802AF3E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0802AF44:
	movs r4, #0xc6
	lsls r4, r4, #2
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_0802AF50:
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r3, r7, r5
	ldrb r0, [r3]
	cmp r0, #0
	beq _0802AFF0
	ldr r2, _0802AF90 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0802AF94 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0802AF98 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r2, _0802AF9C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrb r0, [r3]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0802AFA0
	asrs r3, r0, #0xc
	b _0802AFA6
	.align 2, 0
_0802AF90: .4byte 0x030046B8
_0802AF94: .4byte 0x000003FF
_0802AF98: .4byte 0x0203B400
_0802AF9C: .4byte 0x085B0A08
_0802AFA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0802AFA6:
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0802AFD2
	asrs r2, r0, #0xc
	b _0802AFD8
_0802AFD2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0802AFD8:
	movs r4, #0xc6
	lsls r4, r4, #2
	adds r0, r7, r4
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r1, r7, r5
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0802AFF0:
	mov r0, sb
	bl FUN_08022e20
	movs r3, #0
	ldr r1, _0802B070 @ =0x0000016B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r3, r0
	bge _0802B060
	movs r2, #0x48
	add r2, sb
	mov r8, r2
_0802B008:
	lsls r6, r3, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0802B054
	movs r4, #0
	ldrsh r5, [r1, r4]
	mov r2, r8
	movs r4, #8
	ldrsh r0, [r2, r4]
	subs r5, r5, r0
	movs r0, #4
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	str r3, [sp]
	bl FUN_0823785c
	mov r1, sb
	adds r1, #0xc8
	ldr r3, [sp]
	adds r1, r1, r3
	strb r0, [r1]
	mov r2, sb
	adds r2, #0xc0
	adds r2, r2, r6
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0802B054:
	adds r3, #1
	ldr r2, _0802B070 @ =0x0000016B
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r3, r0
	blt _0802B008
_0802B060:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802B070: .4byte 0x0000016B

	thumb_func_start FUN_0802b074
FUN_0802b074: @ 0x0802B074
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	str r0, [sp, #0x44]
	adds r6, r0, #0
	adds r0, #0x48
	mov sb, r0
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r7, r6, r1
	movs r2, #0
	ldrsh r0, [r7, r2]
	cmp r0, #0
	ble _0802B0EA
	adds r3, r0, #0
	mov r8, r3
	adds r4, r6, #0
	adds r4, #0x90
	movs r0, #0
	ldrsh r5, [r4, r0]
	adds r1, r5, r3
	adds r0, r6, #0
	bl FUN_08022bb0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r5, r0
	beq _0802B0E6
	ldr r2, [sp, #0x44]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r4, _0802B164 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	movs r3, #0x10
	orrs r1, r3
	ldr r2, _0802B168 @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, #0x18]
	ldr r3, [sp, #0x44]
	adds r3, #0x50
	add r4, sp, #0x14
	str r4, [sp]
	movs r1, #1
	str r1, [sp, #4]
	mov r1, r8
	movs r2, #1
	bl FUN_0805fe7c
_0802B0E6:
	movs r0, #0
	strh r0, [r7]
_0802B0EA:
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r3, [r2]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _0802B112
	ldr r1, [sp, #0x44]
	adds r1, #0x90
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0802B10E
	movs r0, #1
	strh r0, [r1]
_0802B10E:
	movs r0, #0
	strh r0, [r2]
_0802B112:
	ldr r0, [sp, #0x44]
	bl FUN_08022ec0
	adds r0, r6, #0
	bl FUN_08028960
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	ldr r4, [sp, #0x44]
	adds r4, #0x98
	mov r8, r4
	cmp r0, #0
	beq _0802B13E
	movs r0, #4
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_0802B13E:
	movs r0, #0xf2
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r1, #4
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0802B16C
	ldrh r0, [r5, #6]
	orrs r0, r1
	strh r0, [r5, #6]
	movs r3, #0xa1
	lsls r3, r3, #2
	adds r2, r6, r3
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	b _0802B18E
	.align 2, 0
_0802B164: .4byte 0xFFFF0000
_0802B168: .4byte 0x0000FFFF
_0802B16C:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r5, #6]
	ands r0, r1
	strh r0, [r5, #6]
	movs r4, #0xc5
	lsls r4, r4, #2
	adds r1, r6, r4
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	mov r0, sb
	ldrb r1, [r0, #5]
	ldr r2, _0802B1BC @ =0x00000226
	adds r0, r6, r2
	strb r1, [r0]
_0802B18E:
	movs r3, #0xa1
	lsls r3, r3, #2
	adds r5, r6, r3
	movs r1, #0x80
	lsls r1, r1, #0xc
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0802B1C0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r5, #6]
	ands r0, r1
	strh r0, [r5, #6]
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	b _0802B1C8
	.align 2, 0
_0802B1BC: .4byte 0x00000226
_0802B1C0:
	ldrh r1, [r5, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5, #6]
_0802B1C8:
	movs r1, #0xca
	lsls r1, r1, #1
	adds r5, r6, r1
	movs r1, #8
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0802B1FA
	movs r3, #0xc5
	lsls r3, r3, #2
	adds r1, r6, r3
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	mov r4, sb
	ldrb r0, [r4, #5]
	movs r2, #0xeb
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08236400
_0802B1FA:
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r5, r6, r3
	movs r1, #0x80
	lsls r1, r1, #0xd
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0802B23C
	add r4, sp, #0x1c
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08028138
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	mov r1, sb
	ldrb r0, [r1, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
	ldr r2, _0802B274 @ =0x00000276
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08236400
_0802B23C:
	movs r1, #0x10
	mov r3, r8
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0802B27C
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r2, r6, r4
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_080139a0
	ldr r1, _0802B278 @ =0xFFDFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r3, [sp, #0x44]
	adds r3, #0xab
	str r3, [sp, #0x54]
	b _0802B30A
	.align 2, 0
_0802B274: .4byte 0x00000276
_0802B278: .4byte 0xFFDFFFFF
_0802B27C:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r2, r6, r4
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	ldr r0, [sp, #0x44]
	adds r0, #0xab
	ldrb r1, [r0]
	str r0, [sp, #0x54]
	cmp r1, #0
	beq _0802B2CC
	movs r1, #0x80
	lsls r1, r1, #9
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0802B2B2
	movs r3, #0xed
	lsls r3, r3, #2
	adds r0, r6, r3
	bl FUN_080139a0
	b _0802B2BC
_0802B2B2:
	movs r4, #0xed
	lsls r4, r4, #2
	adds r0, r6, r4
	bl FUN_08013984
_0802B2BC:
	ldr r1, _0802B2C8 @ =0xFFDFFFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0802B30A
	.align 2, 0
_0802B2C8: .4byte 0xFFDFFFFF
_0802B2CC:
	ldr r3, _0802B2F0 @ =0x00000FD4
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802B2E4
	movs r1, #0x80
	lsls r1, r1, #9
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0802B2F4
_0802B2E4:
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_080139a0
	b _0802B2FE
	.align 2, 0
_0802B2F0: .4byte 0x00000FD4
_0802B2F4:
	movs r2, #0xed
	lsls r2, r2, #2
	adds r0, r6, r2
	bl FUN_08013984
_0802B2FE:
	movs r1, #0x80
	lsls r1, r1, #0xe
	mov r3, r8
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_0802B30A:
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802B326
	subs r0, #1
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0802B326:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	ble _0802B37C
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802B342
	b _0802B6DC
_0802B342:
	adds r0, r6, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _0802B35C
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r6, r2
	b _0802B36A
_0802B35C:
	ldr r0, _0802B378 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r6, r3
_0802B36A:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r6, r4
	b _0802B4BA
	.align 2, 0
_0802B378: .4byte 0x03003584
_0802B37C:
	adds r0, r6, #0
	bl FUN_08027f10
	adds r7, r0, #2
	adds r0, r6, #0
	bl FUN_08027f10
	adds r4, r0, #0
	adds r4, #0xc3
	adds r0, r6, #0
	bl FUN_08027ed0
	subs r0, #0xc1
	mov sb, r0
	ldr r0, _0802B400 @ =0x0000087C
	adds r0, r6, r0
	str r0, [sp, #0x48]
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0
	bne _0802B410
	ldr r0, _0802B404 @ =0x03003584
	lsls r1, r4, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r3, _0802B408 @ =0x0000087A
	adds r0, r6, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	lsls r0, r7, #5
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r6, r0
	ldr r4, _0802B40C @ =0x00000878
	adds r7, r6, r4
	movs r4, #0
	ldrsh r3, [r7, r4]
	movs r4, #5
	str r4, [sp]
	bl rgb555_08237468
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r5
	adds r0, r6, r0
	str r0, [r1]
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r6, r3
	str r0, [r1]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bgt _0802B3FA
	b _0802B6DC
_0802B3FA:
	movs r0, #0x20
	b _0802B6DA
	.align 2, 0
_0802B400: .4byte 0x0000087C
_0802B404: .4byte 0x03003584
_0802B408: .4byte 0x0000087A
_0802B40C: .4byte 0x00000878
_0802B410:
	cmp r5, #1
	bne _0802B4C4
	lsls r1, r4, #5
	ldr r4, _0802B498 @ =0x03003584
	ldr r2, [r4]
	adds r1, r2, r1
	ldr r0, _0802B49C @ =0x0000087A
	adds r0, r0, r6
	mov sl, r0
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	lsls r0, r7, #5
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r6, r0
	ldr r3, _0802B4A0 @ =0x00000878
	adds r7, r6, r3
	movs r4, #0
	ldrsh r3, [r7, r4]
	movs r4, #5
	str r4, [sp]
	bl rgb555_08237468
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r5
	adds r0, r6, r0
	str r0, [r1]
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r6, r3
	str r0, [r1]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0802B468
	b _0802B6DC
_0802B468:
	movs r0, #0
	strh r0, [r7]
	movs r0, #0xff
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	adds r0, r6, #0
	bl FUN_08027ed0
	mov r1, sl
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_08027ed0
	cmp r0, #0
	bne _0802B4A4
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x84
	lsls r3, r3, #3
	adds r0, r6, r3
	str r0, [r1]
	adds r0, r1, #0
	b _0802B4B4
	.align 2, 0
_0802B498: .4byte 0x03003584
_0802B49C: .4byte 0x0000087A
_0802B4A0: .4byte 0x00000878
_0802B4A4:
	lsls r0, r0, #5
	ldr r4, _0802B4C0 @ =0x03003584
	ldr r1, [r4]
	adds r1, r1, r0
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r0, r6, r2
	str r1, [r0]
_0802B4B4:
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r6, r3
_0802B4BA:
	ldr r0, [r0]
	str r0, [r1]
	b _0802B6DC
	.align 2, 0
_0802B4C0: .4byte 0x03003584
_0802B4C4:
	cmp r5, #2
	bne _0802B534
	ldr r0, _0802B528 @ =0x03003584
	lsls r1, r4, #5
	ldr r0, [r0]
	adds r0, r0, r1
	mov ip, r0
	ldr r4, _0802B52C @ =0x00000878
	adds r5, r6, r4
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r0, #0x20
	subs r3, r0, r1
	cmp r3, #0
	bge _0802B4E4
	rsbs r3, r3, #0
_0802B4E4:
	lsls r0, r7, #5
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r0, r6, r0
	ldr r2, _0802B530 @ =0x085AAC18
	movs r1, #5
	str r1, [sp]
	mov r1, ip
	bl rgb555_08237468
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r1, r6, r2
	mov r3, sb
	lsls r0, r3, #5
	adds r0, r0, r4
	adds r0, r6, r0
	str r0, [r1]
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r6, r4
	str r0, [r1]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	bgt _0802B522
	b _0802B6DC
_0802B522:
	movs r0, #0
	strh r0, [r5]
	b _0802B6DC
	.align 2, 0
_0802B528: .4byte 0x03003584
_0802B52C: .4byte 0x00000878
_0802B530: .4byte 0x085AAC18
_0802B534:
	cmp r5, #3
	bne _0802B588
	ldr r0, _0802B57C @ =0x03003584
	ldr r2, [r0]
	movs r0, #0xcb
	lsls r0, r0, #5
	adds r1, r2, r0
	ldr r3, _0802B580 @ =0x0000087A
	adds r0, r6, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	lsls r0, r7, #5
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r6, r0
	ldr r4, _0802B584 @ =0x00000878
	adds r7, r6, r4
	movs r4, #0
	ldrsh r3, [r7, r4]
	movs r4, #6
	str r4, [sp]
	bl rgb555_08237468
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r5
	adds r0, r6, r0
	str r0, [r1]
	movs r3, #0xe7
	lsls r3, r3, #2
	b _0802B6C6
	.align 2, 0
_0802B57C: .4byte 0x03003584
_0802B580: .4byte 0x0000087A
_0802B584: .4byte 0x00000878
_0802B588:
	cmp r5, #4
	bne _0802B5F0
	ldr r0, _0802B5E4 @ =0x03003584
	lsls r1, r4, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r4, _0802B5E8 @ =0x0000087A
	adds r0, r6, r4
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	lsls r0, r7, #5
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r0, r0, r5
	adds r0, r6, r0
	ldr r3, _0802B5EC @ =0x00000878
	adds r7, r6, r3
	movs r4, #0
	ldrsh r3, [r7, r4]
	movs r4, #7
	str r4, [sp]
	bl rgb555_08237468
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r6, r0
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r5
	adds r0, r6, r0
	str r0, [r1]
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r6, r3
	str r0, [r1]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7f
	bgt _0802B5E0
	b _0802B6DC
_0802B5E0:
	movs r0, #0x80
	b _0802B6DA
	.align 2, 0
_0802B5E4: .4byte 0x03003584
_0802B5E8: .4byte 0x0000087A
_0802B5EC: .4byte 0x00000878
_0802B5F0:
	cmp r5, #5
	bne _0802B680
	ldr r0, _0802B65C @ =0x03003584
	lsls r1, r4, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r4, _0802B660 @ =0x0000087A
	adds r0, r6, r4
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	mov ip, r2
	lsls r0, r7, #5
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r0, r6, r0
	ldr r2, _0802B664 @ =0x00000878
	adds r7, r6, r2
	movs r2, #0
	ldrsh r3, [r7, r2]
	mov sl, r3
	str r5, [sp]
	mov r2, ip
	bl rgb555_08237468
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r6, r3
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r4
	adds r0, r6, r0
	str r0, [r1]
	adds r3, #0x60
	adds r1, r6, r3
	str r0, [r1]
	ldr r4, _0802B668 @ =0x0000087D
	adds r1, r6, r4
	ldrb r0, [r1]
	cmp r0, #0
	bne _0802B66C
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _0802B6DC
	movs r0, #0x20
	strh r0, [r7]
	movs r0, #1
	strb r0, [r1]
	b _0802B6DC
	.align 2, 0
_0802B65C: .4byte 0x03003584
_0802B660: .4byte 0x0000087A
_0802B664: .4byte 0x00000878
_0802B668: .4byte 0x0000087D
_0802B66C:
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0802B6DC
	movs r0, #0
	strh r0, [r7]
	strb r0, [r1]
	b _0802B6DC
_0802B680:
	cmp r5, #6
	bne _0802B6DC
	ldr r0, _0802B744 @ =0x03003584
	lsls r1, r4, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldr r3, _0802B748 @ =0x0000087A
	adds r0, r6, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r2, r2, r0
	mov ip, r2
	lsls r0, r7, #5
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r0, r6, r0
	ldr r2, _0802B74C @ =0x00000878
	adds r7, r6, r2
	movs r2, #0
	ldrsh r3, [r7, r2]
	mov sl, r3
	str r5, [sp]
	mov r2, ip
	bl rgb555_08237468
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r6, r3
	mov r2, sb
	lsls r0, r2, #5
	adds r0, r0, r4
	adds r0, r6, r0
	str r0, [r1]
	adds r3, #0x60
_0802B6C6:
	adds r1, r6, r3
	str r0, [r1]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	ble _0802B6DC
	movs r0, #0x40
_0802B6DA:
	strh r0, [r7]
_0802B6DC:
	ldr r4, [sp, #0x54]
	ldrb r0, [r4]
	cmp r0, #0
	bne _0802B76C
	movs r0, #0x80
	lsls r0, r0, #0xe
	mov r2, r8
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0802B75C
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r1, r0
	cmp r1, #0
	bne _0802B75C
	movs r1, #4
	ldr r0, _0802B750 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0802B75C
	movs r3, #0x88
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrb r1, [r2]
	cmp r1, #0
	bne _0802B724
	movs r0, #1
	strb r0, [r2]
	ldr r4, _0802B754 @ =0x00000884
	adds r0, r6, r4
	strh r1, [r0]
	ldr r2, _0802B758 @ =0x00000886
	adds r0, r6, r2
	strh r1, [r0]
_0802B724:
	adds r0, r6, #0
	bl FUN_08028388
	ldr r3, _0802B758 @ =0x00000886
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x80
	bls _0802B76C
	movs r0, #0x80
	strh r0, [r1]
	b _0802B76C
	.align 2, 0
_0802B744: .4byte 0x03003584
_0802B748: .4byte 0x0000087A
_0802B74C: .4byte 0x00000878
_0802B750: .4byte 0x03002BC0
_0802B754: .4byte 0x00000884
_0802B758: .4byte 0x00000886
_0802B75C:
	movs r4, #0x88
	lsls r4, r4, #4
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x20
	bl FUN_0823b880
_0802B76C:
	mov r8, r6
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r0, r6, r0
	str r0, [sp, #0x4c]
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r7, r6, r1
	adds r0, r6, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _0802B78C
	cmp r0, #0x36
	beq _0802B78C
	b _0802BA12
_0802B78C:
	ldr r0, [r7, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0802B798
	b _0802BB90
_0802B798:
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	movs r3, #0xa6
	lsls r3, r3, #4
	adds r5, r6, r3
	add r2, sp, #0x24
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802B7CA
	asrs r0, r0, #8
	b _0802B7D0
_0802B7CA:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802B7D0:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802B7E2
	asrs r0, r0, #8
	b _0802B7E8
_0802B7E2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802B7E8:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802B7FC
	asrs r0, r0, #8
	b _0802B802
_0802B7FC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802B802:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0802B860 @ =0x030047C8
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
	mov r0, r8
	adds r0, #0xaf
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0802B86C
	ldr r1, _0802B864 @ =0x085AABBC
	ldr r3, _0802B868 @ =0x00000A16
	adds r2, r6, r3
	movs r4, #0
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r3, [r7, #0x20]
	adds r0, r0, r3
	strh r0, [r7, #0x20]
	movs r4, #0
	ldrsh r0, [r2, r4]
	lsls r0, r0, #1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r7, #0x22]
	adds r0, r0, r1
	strh r0, [r7, #0x22]
	mov sb, r2
	b _0802B89C
	.align 2, 0
_0802B860: .4byte 0x030047C8
_0802B864: .4byte 0x085AABBC
_0802B868: .4byte 0x00000A16
_0802B86C:
	ldr r2, _0802B8E0 @ =0x085AABBC
	ldr r4, _0802B8E4 @ =0x00000A16
	adds r3, r6, r4
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r7, #0x20]
	subs r0, r0, r1
	strh r0, [r7, #0x20]
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #1
	adds r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r7, #0x22]
	adds r0, r0, r1
	strh r0, [r7, #0x22]
	mov sb, r3
_0802B89C:
	ldr r2, _0802B8E8 @ =0x00000A14
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r4, sb
	movs r3, #0
	ldrsh r2, [r4, r3]
	str r0, [sp, #0x50]
	movs r0, #0xa2
	lsls r0, r0, #4
	adds r4, r6, r0
	cmp r1, r2
	bne _0802B8B8
	b _0802B9FA
_0802B8B8:
	ldr r1, [sp, #0x4c]
	ldrh r0, [r1, #0xc]
	cmp r0, #1
	beq _0802B8C2
	b _0802B9FA
_0802B8C2:
	cmp r2, #2
	beq _0802B8CE
	cmp r2, #5
	beq _0802B8CE
	cmp r2, #8
	bne _0802B9B0
_0802B8CE:
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802B8F0
	ldr r3, _0802B8EC @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r3
	movs r1, #0x20
	b _0802B8F8
	.align 2, 0
_0802B8E0: .4byte 0x085AABBC
_0802B8E4: .4byte 0x00000A16
_0802B8E8: .4byte 0x00000A14
_0802B8EC: .4byte 0xFFFF0000
_0802B8F0:
	ldr r3, _0802B9C4 @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r3
	ldr r1, _0802B9C8 @ =0x0000FFE0
_0802B8F8:
	orrs r0, r1
	str r0, [sp, #0x2c]
	add r2, sp, #0x2c
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r1, _0802B9CC @ =0x0000FFFF
	ldr r0, [sp, #0x2c]
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x2c]
	adds r3, r2, #0
	mov r0, r8
	adds r0, #0xab
	ldrb r2, [r0]
	cmp r2, #0
	bne _0802B9A2
	ldr r4, _0802B9D0 @ =0x00000173
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, _0802B9D4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp, #0x4c]
	adds r1, #0x20
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #1
	mov sl, r2
	str r2, [sp, #8]
	ldr r4, _0802B9D8 @ =0x000008C4
	adds r2, r6, r4
	ldrh r2, [r2]
	str r2, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	adds r2, r3, #0
	movs r3, #0
	bl FUN_0807ab64
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x90
	movs r0, #0
	ldrsh r5, [r4, r0]
	mov r2, r8
	adds r1, r5, r2
	adds r0, r6, #0
	bl FUN_08022bb0
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r5, r0
	beq _0802B9A2
	movs r4, #0xf2
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r4, _0802B9C4 @ =0xFFFF0000
	ldr r1, [sp, #0x34]
	ands r1, r4
	movs r3, #0x10
	orrs r1, r3
	ldr r2, _0802B9CC @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #0x34]
	add r2, sp, #0x34
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r3
	str r1, [r2, #4]
	adds r3, r6, #0
	adds r3, #0x50
	str r2, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r1, r8
	movs r2, #1
	bl FUN_0805fe7c
_0802B9A2:
	adds r0, r6, #0
	bl FUN_08028a04
	movs r0, #0xd3
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0802B9B0:
	adds r0, r6, #0
	bl FUN_08028ec8
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, #1
	ble _0802B9DC
	adds r0, #2
	b _0802B9E2
	.align 2, 0
_0802B9C4: .4byte 0xFFFF0000
_0802B9C8: .4byte 0x0000FFE0
_0802B9CC: .4byte 0x0000FFFF
_0802B9D0: .4byte 0x00000173
_0802B9D4: .4byte 0x03002BE0
_0802B9D8: .4byte 0x000008C4
_0802B9DC:
	cmp r1, #1
	bne _0802B9E2
	adds r0, #1
_0802B9E2:
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r4, r6, r1
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	movs r0, #4
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
_0802B9FA:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_082372cc
	mov r2, sb
	ldrh r0, [r2]
	ldr r3, [sp, #0x50]
	strh r0, [r3]
	ldr r4, [sp, #0x4c]
	ldrh r0, [r4, #0x14]
	strh r0, [r2]
	b _0802BB90
_0802BA12:
	cmp r0, #0x19
	beq _0802BA18
	b _0802BB90
_0802BA18:
	ldr r0, [r7, #8]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0802BA24
	b _0802BB40
_0802BA24:
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	movs r2, #0xa6
	lsls r2, r2, #4
	adds r5, r6, r2
	add r2, sp, #0x3c
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802BA56
	asrs r0, r0, #8
	b _0802BA5C
_0802BA56:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802BA5C:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802BA6E
	asrs r0, r0, #8
	b _0802BA74
_0802BA6E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802BA74:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802BA88
	asrs r0, r0, #8
	b _0802BA8E
_0802BA88:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802BA8E:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0802BB10 @ =0x030047C8
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
	ldr r2, _0802BB14 @ =0x085AABD0
	ldr r4, _0802BB18 @ =0x00000A16
	adds r3, r6, r4
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r4, [r7, #0x20]
	adds r0, r0, r4
	strh r0, [r7, #0x20]
	ldrh r1, [r7, #0x22]
	adds r1, #0x24
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #1
	adds r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	strh r0, [r7, #0x22]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0xa2
	lsls r2, r2, #4
	adds r4, r6, r2
	cmp r0, #1
	bne _0802BB36
	adds r0, r6, #0
	bl FUN_08028ec8
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r1, [r1]
	cmp r1, #0
	beq _0802BB1E
	cmp r1, #1
	beq _0802BB0A
	cmp r1, #3
	bne _0802BB1C
_0802BB0A:
	adds r0, #1
	b _0802BB1E
	.align 2, 0
_0802BB10: .4byte 0x030047C8
_0802BB14: .4byte 0x085AABD0
_0802BB18: .4byte 0x00000A16
_0802BB1C:
	adds r0, #2
_0802BB1E:
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r4, r6, r1
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	movs r0, #4
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
_0802BB36:
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_082372cc
	b _0802BB90
_0802BB40:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, [r0]
	ldr r0, _0802BBD8 @ =0x00040001
	cmp r1, r0
	bne _0802BB90
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r3, [r0]
	cmp r3, #0
	bne _0802BB88
	ldr r4, _0802BBDC @ =0x00000173
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, _0802BBE0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r4, #0xc5
	lsls r4, r4, #2
	adds r1, r6, r4
	str r3, [sp]
	str r3, [sp, #4]
	str r2, [sp, #8]
	ldr r4, _0802BBE4 @ =0x000008C6
	adds r2, r6, r4
	ldrh r2, [r2]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl FUN_0807ab64
_0802BB88:
	movs r0, #0xef
	lsls r0, r0, #1
	bl PlaySound_0824078c
_0802BB90:
	adds r0, r6, #0
	bl FUN_08029e00
	adds r0, r6, #0
	bl FUN_0802a2fc
	adds r0, r6, #0
	bl FUN_08029b40
	ldr r0, _0802BBE8 @ =0x00001044
	adds r1, r6, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _0802BC00
	subs r0, #1
	str r0, [r1]
	ldr r0, _0802BBEC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0802BBF0 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r2, r0, #0
	adds r2, #0x10
	cmp r2, #0x3f
	ble _0802BBC8
	movs r2, #0x40
_0802BBC8:
	ldr r3, _0802BBF4 @ =0x00001048
	adds r0, r6, r3
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, r2
	bls _0802BBF8
	subs r0, r1, #1
	b _0802BC16
	.align 2, 0
_0802BBD8: .4byte 0x00040001
_0802BBDC: .4byte 0x00000173
_0802BBE0: .4byte 0x03002BE0
_0802BBE4: .4byte 0x000008C6
_0802BBE8: .4byte 0x00001044
_0802BBEC: .4byte 0x030046A0
_0802BBF0: .4byte 0x00000942
_0802BBF4: .4byte 0x00001048
_0802BBF8:
	cmp r1, r2
	bhs _0802BC18
	adds r0, r1, #1
	b _0802BC16
_0802BC00:
	ldr r4, _0802BC10 @ =0x00001048
	adds r0, r6, r4
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0x3f
	bhi _0802BC14
	adds r0, r1, #1
	b _0802BC16
	.align 2, 0
_0802BC10: .4byte 0x00001048
_0802BC14:
	movs r0, #0x40
_0802BC16:
	str r0, [r3]
_0802BC18:
	ldr r1, _0802BC74 @ =0x03004460
	ldr r0, [r3]
	str r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, [sp, #0x54]
	ldrb r0, [r1]
	ldr r4, [sp, #0x44]
	adds r4, #0xe0
	cmp r0, #0
	beq _0802BC4E
	ldr r2, _0802BC78 @ =0x0000018B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BC4E
	ldr r0, [r4]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0802BC4E
	adds r0, r6, #0
	bl FUN_08028c04
_0802BC4E:
	ldr r0, [sp, #0x44]
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	ldr r0, [sp, #0x44]
	adds r0, #0xb8
	str r1, [r0]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BC74: .4byte 0x03004460
_0802BC78: .4byte 0x0000018B

	thumb_func_start FUN_0802bc7c
FUN_0802bc7c: @ 0x0802BC7C
	push {lr}
	adds r3, r0, #0
	ldr r1, _0802BC90 @ =0x00000864
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _0802BC94
	movs r0, #0
	b _0802BCBE
	.align 2, 0
_0802BC90: .4byte 0x00000864
_0802BC94:
	movs r0, #0xf
	adds r1, r3, #0
	adds r1, #0xa6
	movs r2, #0
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xbc
	str r2, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802BCC4 @ =0x00000894
	adds r0, r3, r1
	strh r2, [r0]
	ldr r2, _0802BCC8 @ =0x000008D2
	adds r0, r3, r2
	ldrh r1, [r0]
	subs r2, #0x4a
	adds r0, r3, r2
	strh r1, [r0]
	movs r0, #1
_0802BCBE:
	pop {r1}
	bx r1
	.align 2, 0
_0802BCC4: .4byte 0x00000894
_0802BCC8: .4byte 0x000008D2

	thumb_func_start FUN_0802bccc
FUN_0802bccc: @ 0x0802BCCC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r3, r5, #0
	adds r3, #0x48
	adds r0, #0xdd
	ldrb r7, [r0]
	ldr r2, _0802BD0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0802BD10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	ldr r0, _0802BD14 @ =0x0000088A
	adds r1, r5, r0
	ldrh r0, [r1]
	movs r2, #7
	ands r2, r0
	adds r0, #1
	strh r0, [r1]
	cmp r2, #3
	beq _0802BCFE
	cmp r2, #7
	bne _0802BD20
_0802BCFE:
	ldr r4, _0802BD18 @ =0x00000899
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802BD1C @ =0x000008DC
	b _0802BD2A
	.align 2, 0
_0802BD0C: .4byte 0x030046B8
_0802BD10: .4byte 0x000003FF
_0802BD14: .4byte 0x0000088A
_0802BD18: .4byte 0x00000899
_0802BD1C: .4byte 0x000008DC
_0802BD20:
	ldr r0, _0802BD50 @ =0x00000899
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0802BD54 @ =0x000008DB
_0802BD2A:
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r4, #0xbf
	lsls r4, r4, #1
	adds r1, r5, r4
	strh r0, [r1]
	ldr r1, _0802BD50 @ =0x00000899
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	bne _0802BE20
	cmp r7, #0x3f
	bgt _0802BD84
	cmp r2, #2
	ble _0802BD88
	cmp r2, #4
	bne _0802BD58
	movs r0, #0xe
	b _0802BDBA
	.align 2, 0
_0802BD50: .4byte 0x00000899
_0802BD54: .4byte 0x000008DB
_0802BD58:
	movs r0, #9
	ldr r2, _0802BD7C @ =0x00000169
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _0802BD80 @ =0x0000084C
	adds r0, r5, r1
	adds r1, r3, #0
	adds r1, #8
	subs r2, #0x69
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #1
	movs r3, #1
	bl FUN_0823585c
	b _0802BE04
	.align 2, 0
_0802BD7C: .4byte 0x00000169
_0802BD80: .4byte 0x0000084C
_0802BD84:
	cmp r2, #2
	bgt _0802BDB4
_0802BD88:
	movs r0, #5
	ldr r2, _0802BDAC @ =0x00000169
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _0802BDB0 @ =0x0000084C
	adds r0, r5, r1
	adds r1, r3, #0
	adds r1, #8
	subs r2, #0x69
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #3
	movs r3, #4
	bl FUN_0823585c
	b _0802BE04
	.align 2, 0
_0802BDAC: .4byte 0x00000169
_0802BDB0: .4byte 0x0000084C
_0802BDB4:
	cmp r2, #4
	bne _0802BDE4
	movs r0, #0xc
_0802BDBA:
	movs r2, #3
	movs r3, #0x40
	adds r1, r5, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xbc
	str r4, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r4, _0802BDE0 @ =0x0000017B
	adds r0, r5, r4
	strb r2, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
	b _0802BE7A
	.align 2, 0
_0802BDE0: .4byte 0x0000017B
_0802BDE4:
	movs r0, #8
	ldr r2, _0802BE18 @ =0x00000169
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _0802BE1C @ =0x0000084C
	adds r0, r5, r1
	adds r1, r3, #0
	adds r1, #8
	subs r2, #0x69
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #3
	movs r3, #1
	bl FUN_0823585c
_0802BE04:
	movs r2, #1
	adds r0, r6, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _0802BE7A
	.align 2, 0
_0802BE18: .4byte 0x00000169
_0802BE1C: .4byte 0x0000084C
_0802BE20:
	movs r0, #6
	ldr r2, _0802BE68 @ =0x00000169
	adds r1, r5, r2
	movs r4, #0
	strb r0, [r1]
	ldr r1, _0802BE6C @ =0x0000084C
	adds r0, r5, r1
	adds r1, r3, #0
	adds r1, #8
	subs r2, #0x69
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #2
	movs r3, #6
	bl FUN_0823585c
	movs r1, #1
	adds r0, r6, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r4, [r0]
	subs r0, #0x14
	strb r1, [r0]
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0802BE74
	ldr r0, _0802BE70 @ =0x0000030A
	bl PlaySound_0824078c
	b _0802BE7A
	.align 2, 0
_0802BE68: .4byte 0x00000169
_0802BE6C: .4byte 0x0000084C
_0802BE70: .4byte 0x0000030A
_0802BE74:
	ldr r0, _0802BE84 @ =0x0000035B
	bl PlaySound_0824078c
_0802BE7A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BE84: .4byte 0x0000035B

	thumb_func_start FUN_0802be88
FUN_0802be88: @ 0x0802BE88
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r3, r5, #0
	adds r3, #0x48
	adds r0, #0xdd
	ldrb r7, [r0]
	ldr r2, _0802BEC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0802BECC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	ldr r0, _0802BED0 @ =0x0000088A
	adds r1, r5, r0
	ldrh r0, [r1]
	movs r2, #7
	ands r2, r0
	adds r0, #1
	strh r0, [r1]
	cmp r2, #3
	beq _0802BEBA
	cmp r2, #7
	bne _0802BEDC
_0802BEBA:
	ldr r4, _0802BED4 @ =0x00000899
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802BED8 @ =0x000008DC
	b _0802BEE6
	.align 2, 0
_0802BEC8: .4byte 0x030046B8
_0802BECC: .4byte 0x000003FF
_0802BED0: .4byte 0x0000088A
_0802BED4: .4byte 0x00000899
_0802BED8: .4byte 0x000008DC
_0802BEDC:
	ldr r0, _0802BF3C @ =0x00000899
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0802BF40 @ =0x000008DB
_0802BEE6:
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r4, #0xbf
	lsls r4, r4, #1
	adds r1, r5, r4
	strh r0, [r1]
	ldr r1, _0802BF3C @ =0x00000899
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	bne _0802BFBC
	cmp r7, #0x3f
	bgt _0802BF4C
	movs r0, #7
	ldr r2, _0802BF44 @ =0x00000169
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _0802BF48 @ =0x0000084C
	adds r0, r5, r1
	adds r1, r3, #0
	adds r1, #8
	subs r2, #0x69
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #2
	movs r3, #5
	bl FUN_0823585c
	movs r2, #1
	adds r3, r6, #0
	adds r3, #0xa6
	strb r2, [r3]
	adds r1, r6, #0
	adds r1, #0xbc
	str r4, [r1]
	adds r0, r6, #0
	adds r0, #0xa8
	strb r2, [r0]
	adds r4, r3, #0
	adds r3, r1, #0
	adds r2, r0, #0
	b _0802BFA8
	.align 2, 0
_0802BF3C: .4byte 0x00000899
_0802BF40: .4byte 0x000008DB
_0802BF44: .4byte 0x00000169
_0802BF48: .4byte 0x0000084C
_0802BF4C:
	cmp r2, #2
	bgt _0802BF7C
	movs r0, #5
	ldr r2, _0802BF74 @ =0x00000169
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _0802BF78 @ =0x0000084C
	adds r0, r5, r1
	adds r1, r3, #0
	adds r1, #8
	subs r2, #0x69
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #3
	movs r3, #4
	bl FUN_0823585c
	b _0802BF9C
	.align 2, 0
_0802BF74: .4byte 0x00000169
_0802BF78: .4byte 0x0000084C
_0802BF7C:
	movs r0, #8
	ldr r2, _0802BFB4 @ =0x00000169
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _0802BFB8 @ =0x0000084C
	adds r0, r5, r1
	adds r1, r3, #0
	adds r1, #8
	subs r2, #0x69
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #3
	movs r3, #1
	bl FUN_0823585c
_0802BF9C:
	adds r4, r6, #0
	adds r4, #0xa6
	adds r3, r6, #0
	adds r3, #0xbc
	adds r2, r6, #0
	adds r2, #0xa8
_0802BFA8:
	movs r1, #1
	movs r0, #0
	strb r1, [r4]
	str r0, [r3]
	strb r1, [r2]
	b _0802C016
	.align 2, 0
_0802BFB4: .4byte 0x00000169
_0802BFB8: .4byte 0x0000084C
_0802BFBC:
	movs r0, #7
	ldr r2, _0802C004 @ =0x00000169
	adds r1, r5, r2
	movs r4, #0
	strb r0, [r1]
	ldr r1, _0802C008 @ =0x0000084C
	adds r0, r5, r1
	adds r1, r3, #0
	adds r1, #8
	subs r2, #0x69
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #2
	movs r3, #5
	bl FUN_0823585c
	movs r1, #1
	adds r0, r6, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r4, [r0]
	subs r0, #0x14
	strb r1, [r0]
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0802C010
	ldr r0, _0802C00C @ =0x0000030A
	bl PlaySound_0824078c
	b _0802C016
	.align 2, 0
_0802C004: .4byte 0x00000169
_0802C008: .4byte 0x0000084C
_0802C00C: .4byte 0x0000030A
_0802C010:
	ldr r0, _0802C020 @ =0x0000035B
	bl PlaySound_0824078c
_0802C016:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C020: .4byte 0x0000035B

	thumb_func_start FUN_0802c024
FUN_0802c024: @ 0x0802C024
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r2, _0802C080 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0802C084 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	ldr r0, _0802C088 @ =0x0000088A
	adds r2, r4, r0
	ldrh r0, [r2]
	movs r3, #7
	ands r3, r0
	adds r0, #1
	movs r1, #0
	movs r5, #0
	strh r0, [r2]
	ldr r2, _0802C08C @ =0x00000899
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _0802C090 @ =0x000008DB
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r2, #0xbf
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	cmp r3, #0
	beq _0802C064
	cmp r3, #4
	bne _0802C09C
_0802C064:
	movs r0, #0xb
	ldr r2, _0802C094 @ =0x00000169
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _0802C098 @ =0x0000084C
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x50
	subs r2, #0x69
	str r2, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r2, #2
	b _0802C0BE
	.align 2, 0
_0802C080: .4byte 0x030046B8
_0802C084: .4byte 0x000003FF
_0802C088: .4byte 0x0000088A
_0802C08C: .4byte 0x00000899
_0802C090: .4byte 0x000008DB
_0802C094: .4byte 0x00000169
_0802C098: .4byte 0x0000084C
_0802C09C:
	cmp r3, #1
	beq _0802C0A4
	cmp r3, #5
	bne _0802C0D0
_0802C0A4:
	ldr r2, _0802C0C8 @ =0x00000169
	adds r1, r4, r2
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0802C0CC @ =0x0000084C
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x50
	subs r2, #0x69
	str r2, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r2, #3
_0802C0BE:
	movs r3, #8
	bl FUN_0823585c
	b _0802C10E
	.align 2, 0
_0802C0C8: .4byte 0x00000169
_0802C0CC: .4byte 0x0000084C
_0802C0D0:
	cmp r3, #2
	beq _0802C0D8
	cmp r3, #6
	bne _0802C0EE
_0802C0D8:
	movs r0, #0x14
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	b _0802C120
_0802C0EE:
	movs r0, #8
	ldr r2, _0802C128 @ =0x00000169
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _0802C12C @ =0x0000084C
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x50
	subs r2, #0x69
	str r2, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r2, #3
	movs r3, #4
	bl FUN_0823585c
_0802C10E:
	movs r2, #1
	adds r0, r4, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
_0802C120:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C128: .4byte 0x00000169
_0802C12C: .4byte 0x0000084C

	thumb_func_start FUN_0802c130
FUN_0802c130: @ 0x0802C130
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	ldr r1, _0802C150 @ =0x00000169
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0xa
	bls _0802C144
	b _0802C292
_0802C144:
	lsls r0, r0, #2
	ldr r1, _0802C154 @ =_0802C158
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C150: .4byte 0x00000169
_0802C154: .4byte _0802C158
_0802C158: @ jump table
	.4byte _0802C184 @ case 0
	.4byte _0802C1B0 @ case 1
	.4byte _0802C1C4 @ case 2
	.4byte _0802C1C8 @ case 3
	.4byte _0802C1F8 @ case 4
	.4byte _0802C208 @ case 5
	.4byte _0802C21A @ case 6
	.4byte _0802C244 @ case 7
	.4byte _0802C256 @ case 8
	.4byte _0802C274 @ case 9
	.4byte _0802C278 @ case 10
_0802C184:
	movs r2, #0x5a
	movs r1, #0
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r5, _0802C1AC @ =0x0000089C
	adds r0, r4, r5
	strh r2, [r0]
	b _0802C2C2
	.align 2, 0
_0802C1AC: .4byte 0x0000089C
_0802C1B0:
	movs r0, #0xc
	movs r2, #3
	movs r3, #0x40
	movs r1, #0xa6
	adds r1, r1, r4
	mov ip, r1
	movs r1, #0
	mov r5, ip
	strb r0, [r5]
	b _0802C1D4
_0802C1C4:
	movs r0, #0xd
	b _0802C1CA
_0802C1C8:
	movs r0, #0xe
_0802C1CA:
	movs r2, #3
	movs r3, #0x40
	movs r5, #0xa6
	movs r1, #0
	strb r0, [r5, r4]
_0802C1D4:
	adds r0, r4, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802C1F4 @ =0x0000017B
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r3, [r0]
	b _0802C2C2
	.align 2, 0
_0802C1F4: .4byte 0x0000017B
_0802C1F8:
	movs r5, #0xba
	lsls r5, r5, #1
	adds r0, r4, r5
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xa
	b _0802C264
_0802C208:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0xa
	adds r2, r3, #0
	adds r2, #0xa6
	b _0802C280
_0802C21A:
	ldr r2, _0802C23C @ =0x00000899
	adds r0, r4, r2
	ldrb r1, [r0]
	ldr r5, _0802C240 @ =0x00000892
	adds r0, r4, r5
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xb
	adds r1, r3, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xbc
	str r2, [r0]
	adds r1, #2
	b _0802C28C
	.align 2, 0
_0802C23C: .4byte 0x00000899
_0802C240: .4byte 0x00000892
_0802C244:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #5
	adds r2, r3, #0
	adds r2, #0xa6
	b _0802C280
_0802C256:
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	movs r0, #5
_0802C264:
	movs r5, #0xa6
	strb r0, [r5, r3]
	adds r0, r3, #0
	adds r0, #0xbc
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _0802C2C2
_0802C274:
	movs r0, #0x14
	b _0802C27A
_0802C278:
	movs r0, #0x1b
_0802C27A:
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
_0802C280:
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
_0802C28C:
	movs r0, #1
	strb r0, [r1]
	b _0802C2C2
_0802C292:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0802C2BC
	ldr r2, _0802C2B0 @ =0x00000FD4
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C2B4
	adds r0, r4, #0
	bl FUN_0802c024
	b _0802C2C2
	.align 2, 0
_0802C2B0: .4byte 0x00000FD4
_0802C2B4:
	adds r0, r4, #0
	bl FUN_0802be88
	b _0802C2C2
_0802C2BC:
	adds r0, r4, #0
	bl FUN_0802bccc
_0802C2C2:
	ldr r5, _0802C2D0 @ =0x00000169
	adds r1, r4, r5
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C2D0: .4byte 0x00000169

	thumb_func_start FUN_0802c2d4
FUN_0802c2d4: @ 0x0802C2D4
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0x90
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _0802C340
	adds r0, r3, #0
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C340
	movs r2, #2
	adds r1, r3, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x82
	lsls r4, r4, #4
	adds r0, r3, r4
	ldr r4, [r0]
	cmp r4, #0
	beq _0802C324
	ldr r2, _0802C320 @ =dainn_08032f18
	movs r0, #0x22
	movs r1, #0xa3
	adds r1, r1, r3
	mov ip, r1
	movs r1, #0
	mov r4, ip
	strb r0, [r4]
	adds r0, r3, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	b _0802C338
	.align 2, 0
_0802C320: .4byte dainn_08032f18
_0802C324:
	ldr r1, _0802C370 @ =FUN_08032e1c
	movs r0, #0x21
	adds r2, r3, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
_0802C338:
	adds r1, r3, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_0802C340:
	adds r0, r3, #0
	adds r0, #0x96
	movs r2, #0
	strb r2, [r0]
	movs r1, #2
	adds r0, #2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0802C374
	movs r1, #1
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _0802C396
	.align 2, 0
_0802C370: .4byte FUN_08032e1c
_0802C374:
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne _0802C380
	movs r0, #0
	b _0802C398
_0802C380:
	adds r0, r3, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
_0802C396:
	movs r0, #1
_0802C398:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0802c3a0
FUN_0802c3a0: @ 0x0802C3A0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802C3C6
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0802C3C8
_0802C3C6:
	movs r0, #0
_0802C3C8:
	adds r1, r0, #0
	cmp r1, #1
	bne _0802C3D4
	adds r0, r5, #0
	adds r0, #0xa2
	strb r1, [r0]
_0802C3D4:
	adds r0, r4, #0
	bl FUN_0802bc7c
	cmp r0, #0
	beq _0802C3E0
	b _0802C55C
_0802C3E0:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802C3EE
	b _0802C510
_0802C3EE:
	ldr r2, _0802C450 @ =0x00000899
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0802C3FA
	b _0802C510
_0802C3FA:
	ldr r3, _0802C454 @ =0x00000FD4
	adds r0, r4, r3
	ldrb r6, [r0]
	cmp r6, #0
	beq _0802C406
	b _0802C510
_0802C406:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0802C484
	subs r2, #0xd
	adds r5, r4, r2
	ldrh r0, [r5]
	cmp r0, #2
	bls _0802C460
	movs r0, #5
	ldr r3, _0802C458 @ =0x00000169
	adds r1, r4, r3
	strb r0, [r1]
	ldr r1, _0802C45C @ =0x0000084C
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #1
	str r2, [sp]
	str r6, [sp, #4]
	str r6, [sp, #8]
	movs r2, #3
	movs r3, #1
	bl FUN_0823585c
	strh r6, [r5]
	movs r0, #2
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	str r6, [r0]
	b _0802C4C0
	.align 2, 0
_0802C450: .4byte 0x00000899
_0802C454: .4byte 0x00000FD4
_0802C458: .4byte 0x00000169
_0802C45C: .4byte 0x0000084C
_0802C460:
	movs r0, #3
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	str r6, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r0, #0xc4
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _0802C55C
_0802C484:
	ldr r2, _0802C4C8 @ =0x0000088C
	adds r6, r4, r2
	ldrh r0, [r6]
	cmp r0, #2
	bls _0802C4D4
	movs r0, #5
	ldr r3, _0802C4CC @ =0x00000169
	adds r1, r4, r3
	strb r0, [r1]
	ldr r1, _0802C4D0 @ =0x0000084C
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0x80
	lsls r2, r2, #1
	str r2, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r2, #3
	movs r3, #1
	bl FUN_0823585c
	strh r5, [r6]
	movs r0, #2
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
_0802C4C0:
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	b _0802C55C
	.align 2, 0
_0802C4C8: .4byte 0x0000088C
_0802C4CC: .4byte 0x00000169
_0802C4D0: .4byte 0x0000084C
_0802C4D4:
	movs r0, #0xc
	movs r1, #1
	movs r2, #0x20
	adds r3, r4, #0
	adds r3, #0xa6
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
	subs r0, #0x14
	strb r1, [r0]
	ldr r3, _0802C508 @ =0x0000017B
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	ldr r0, _0802C50C @ =0x0000035A
	bl PlaySound_0824078c
	b _0802C55C
	.align 2, 0
_0802C508: .4byte 0x0000017B
_0802C50C: .4byte 0x0000035A
_0802C510:
	adds r2, r5, #0
	adds r2, #0xbc
	ldr r3, _0802C540 @ =0x0000089C
	adds r0, r4, r3
	ldr r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bls _0802C558
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0802C550
	ldr r2, _0802C544 @ =0x00000FD4
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C548
	adds r0, r4, #0
	bl FUN_0802c024
	b _0802C55C
	.align 2, 0
_0802C540: .4byte 0x0000089C
_0802C544: .4byte 0x00000FD4
_0802C548:
	adds r0, r4, #0
	bl FUN_0802be88
	b _0802C55C
_0802C550:
	adds r0, r4, #0
	bl FUN_0802bccc
	b _0802C55C
_0802C558:
	adds r0, r1, #1
	str r0, [r2]
_0802C55C:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802c564
FUN_0802c564: @ 0x0802C564
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r2, r0, #0
	adds r4, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802C58A
	strb r3, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r3, [r0]
	movs r0, #1
	b _0802C58C
_0802C58A:
	movs r0, #0
_0802C58C:
	cmp r0, #0
	beq _0802C598
	movs r0, #2
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802C598:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802C5A6
	b _0802C6C4
_0802C5A6:
	ldr r3, _0802C608 @ =0x00000899
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #1
	bne _0802C5B2
	b _0802C6C4
_0802C5B2:
	ldr r1, _0802C60C @ =0x00000FD4
	adds r0, r4, r1
	ldrb r6, [r0]
	cmp r6, #0
	beq _0802C5BE
	b _0802C6C4
_0802C5BE:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r5, [r0]
	cmp r5, #0
	beq _0802C638
	subs r3, #0xd
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #2
	bls _0802C614
	movs r0, #5
	ldr r2, _0802C610 @ =0x00000169
	adds r1, r4, r2
	strb r0, [r1]
	subs r3, #0x40
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x50
	subs r2, #0x69
	str r2, [sp]
	str r6, [sp, #4]
	str r6, [sp, #8]
	movs r2, #3
	movs r3, #1
	bl FUN_0823585c
	strh r6, [r5]
	movs r0, #2
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	str r6, [r0]
	b _0802C672
	.align 2, 0
_0802C608: .4byte 0x00000899
_0802C60C: .4byte 0x00000FD4
_0802C610: .4byte 0x00000169
_0802C614:
	movs r0, #3
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	str r6, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r0, #0xc4
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _0802C6E0
_0802C638:
	ldr r0, _0802C67C @ =0x0000088C
	adds r6, r4, r0
	ldrh r0, [r6]
	cmp r0, #2
	bls _0802C688
	movs r0, #5
	ldr r2, _0802C680 @ =0x00000169
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0802C684 @ =0x0000084C
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x50
	subs r2, #0x69
	str r2, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r2, #3
	movs r3, #1
	bl FUN_0823585c
	strh r5, [r6]
	movs r0, #2
	adds r1, r4, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
_0802C672:
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	b _0802C6E0
	.align 2, 0
_0802C67C: .4byte 0x0000088C
_0802C680: .4byte 0x00000169
_0802C684: .4byte 0x0000084C
_0802C688:
	movs r0, #0xc
	movs r1, #1
	movs r2, #0x20
	adds r3, r4, #0
	adds r3, #0xa6
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
	subs r0, #0x14
	strb r1, [r0]
	ldr r3, _0802C6BC @ =0x0000017B
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	ldr r0, _0802C6C0 @ =0x0000035A
	bl PlaySound_0824078c
	b _0802C6E0
	.align 2, 0
_0802C6BC: .4byte 0x0000017B
_0802C6C0: .4byte 0x0000035A
_0802C6C4:
	adds r0, r2, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C6D6
	adds r0, r4, #0
	bl FUN_0802c130
	b _0802C6E0
_0802C6D6:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802C6E0:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802c6e8
FUN_0802c6e8: @ 0x0802C6E8
	push {lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802C704
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802C70A
_0802C704:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802C70A:
	cmp r0, #0
	beq _0802C720
	movs r0, #2
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
	movs r2, #0xbf
	lsls r2, r2, #1
	add r2, ip
	movs r0, #0x40
	strh r0, [r2]
_0802C720:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802C72E
	mov r0, ip
	bl FUN_0802c130
	b _0802C738
_0802C72E:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802C738:
	pop {r0}
	bx r0

	thumb_func_start FUN_0802c73c
FUN_0802c73c: @ 0x0802C73C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov r8, r0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802C766
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r7, r1, #0
	b _0802C76C
_0802C766:
	movs r0, #0
	adds r7, r5, #0
	adds r7, #0xa7
_0802C76C:
	cmp r0, #0
	beq _0802C79A
	movs r0, #4
	adds r1, r5, #0
	adds r1, #0xa2
	movs r4, #0
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_08029628
	ldr r1, _0802C7C4 @ =0x0000085C
	adds r0, r6, r1
	mov r1, r8
	adds r1, #8
	movs r2, #0x80
	lsls r2, r2, #1
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r2, #3
	movs r3, #4
	bl FUN_0823585c
_0802C79A:
	ldrb r0, [r7]
	cmp r0, #0
	beq _0802C7C8
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #5
	adds r2, r5, #0
	adds r2, #0xa6
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802C7D2
	.align 2, 0
_0802C7C4: .4byte 0x0000085C
_0802C7C8:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802C7D2:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802c7e0
FUN_0802c7e0: @ 0x0802C7E0
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802C806
	strb r3, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r3, [r0]
	movs r1, #1
	adds r3, r0, #0
	b _0802C80C
_0802C806:
	movs r1, #0
	adds r3, r2, #0
	adds r3, #0xa7
_0802C80C:
	cmp r1, #0
	beq _0802C818
	movs r0, #6
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802C818:
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r2, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0802C832
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
_0802C832:
	ldrb r0, [r3]
	cmp r0, #0
	beq _0802C86C
	adds r0, r4, #0
	bl FUN_0802bc7c
	adds r1, r0, #0
	cmp r1, #0
	bne _0802C876
	movs r2, #0x5a
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802C868 @ =0x0000089C
	adds r0, r4, r1
	strh r2, [r0]
	b _0802C876
	.align 2, 0
_0802C868: .4byte 0x0000089C
_0802C86C:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802C876:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802c87c
FUN_0802c87c: @ 0x0802C87C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802C8A0
	strb r3, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r3, [r0]
	movs r1, #1
	adds r3, r0, #0
	b _0802C8A6
_0802C8A0:
	movs r1, #0
	adds r3, r2, #0
	adds r3, #0xa7
_0802C8A6:
	cmp r1, #0
	beq _0802C8B2
	movs r0, #7
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802C8B2:
	ldrb r0, [r3]
	cmp r0, #0
	beq _0802C8D2
	movs r0, #6
	adds r3, r2, #0
	adds r3, #0xa6
	movs r1, #0
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r2, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802C8DC
_0802C8D2:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802C8DC:
	pop {r0}
	bx r0

	thumb_func_start FUN_0802c8e0
FUN_0802c8e0: @ 0x0802C8E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x38
	adds r7, r0, #0
	mov r8, r7
	adds r6, r7, #0
	adds r6, #0x48
	adds r1, r7, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802C90E
	strb r2, [r1]
	adds r0, r7, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0802C910
_0802C90E:
	movs r0, #0
_0802C910:
	cmp r0, #0
	beq _0802C91C
	movs r0, #8
	adds r1, r7, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802C91C:
	movs r0, #0xb9
	lsls r0, r0, #1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C92A
	b _0802CA24
_0802C92A:
	mov r3, sp
	ldrb r4, [r6, #5]
	movs r5, #0xc8
	ldr r2, _0802C94C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0802C950
	asrs r1, r0, #0xc
	b _0802C956
	.align 2, 0
_0802C94C: .4byte 0x085B0A08
_0802C950:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802C956:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0802C96E
	asrs r0, r0, #0xc
	b _0802C974
_0802C96E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802C974:
	strh r0, [r3, #4]
	mov r4, sp
	mov r1, sp
	ldrh r0, [r6, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r3, [r6, #0xa]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r6, #0xc]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	ldr r5, _0802CA18 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r5
	ldr r1, _0802CA1C @ =0x0000FF38
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r2, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, [sp, #0x10]
	ands r0, r5
	movs r1, #0xc8
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r4, [r3, #4]
	adds r0, r0, r4
	strh r0, [r3, #4]
	ldr r0, _0802CA20 @ =0x0000016B
	add r0, r8
	ldrb r1, [r0]
	mov r0, r8
	bl FUN_08028720
	adds r2, r0, #0
	cmp r2, #0
	bge _0802CA06
	b _0802CB44
_0802CA06:
	movs r0, #7
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r1, #0x16
	movs r0, #0
	str r0, [r1]
	subs r1, #0x14
	b _0802CC78
	.align 2, 0
_0802CA18: .4byte 0xFFFF0000
_0802CA1C: .4byte 0x0000FF38
_0802CA20: .4byte 0x0000016B
_0802CA24:
	add r3, sp, #0x18
	ldrb r4, [r6, #5]
	ldr r2, _0802CA48 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	mov ip, r3
	cmp r0, #0
	blt _0802CA4C
	asrs r1, r0, #0xc
	b _0802CA52
	.align 2, 0
_0802CA48: .4byte 0x085B0A08
_0802CA4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802CA52:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	muls r0, r1, r0
	cmp r0, #0
	blt _0802CA6C
	asrs r0, r0, #0xc
	b _0802CA72
_0802CA6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802CA72:
	strh r0, [r3, #4]
	add r5, sp, #0x18
	ldrh r0, [r6, #8]
	ldrh r3, [r5]
	adds r0, r0, r3
	strh r0, [r5]
	mov r4, ip
	ldrh r0, [r4, #2]
	ldrh r1, [r6, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r6, #0xc]
	ldrh r2, [r4, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	ldr r4, _0802CB30 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r4
	ldr r1, _0802CB34 @ =0x0000FF80
	orrs r0, r1
	str r0, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r2, #4]
	ldrh r0, [r5]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2, #2]
	mov r3, ip
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ands r0, r4
	movs r1, #0x80
	orrs r0, r1
	str r0, [sp, #0x28]
	add r3, sp, #0x28
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	ldrh r0, [r5]
	ldrh r4, [r3]
	adds r0, r0, r4
	strh r0, [r3]
	ldrh r0, [r3, #2]
	mov r4, ip
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	ldr r0, _0802CB38 @ =0x0000016B
	add r0, r8
	ldrb r1, [r0]
	mov r0, r8
	bl FUN_08028720
	adds r2, r0, #0
	cmp r2, #0
	blt _0802CB44
	ldr r1, _0802CB3C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r0, #0x20]
	ands r0, r1
	rsbs r0, r0, #0
	lsrs r3, r0, #0x1f
	cmp r3, #0
	bne _0802CB44
	ldr r0, _0802CB40 @ =0x00000173
	add r0, r8
	strb r2, [r0]
	movs r0, #8
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbc
	str r3, [r0]
	adds r1, #2
	b _0802CC78
	.align 2, 0
_0802CB30: .4byte 0xFFFF0000
_0802CB34: .4byte 0x0000FF80
_0802CB38: .4byte 0x0000016B
_0802CB3C: .4byte 0x03002BE0
_0802CB40: .4byte 0x00000173
_0802CB44:
	movs r2, #0xc8
	lsls r2, r2, #1
	mov ip, r2
	mov r4, r8
	adds r4, #0x48
	add r3, sp, #0x30
	ldrb r6, [r4, #5]
	ldr r2, _0802CB74 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r5, r3, #0
	cmp r0, #0
	blt _0802CB78
	asrs r1, r0, #0xc
	b _0802CB7E
	.align 2, 0
_0802CB74: .4byte 0x085B0A08
_0802CB78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802CB7E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0802CB9A
	asrs r0, r0, #0xc
	b _0802CBA0
_0802CB9A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802CBA0:
	strh r0, [r3, #4]
	add r1, sp, #0x30
	ldrh r0, [r4, #8]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r3, [r4, #0xa]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r1, [r4, #0xc]
	ldrh r4, [r5, #4]
	adds r1, r1, r4
	strh r1, [r5, #4]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0802CBDE
	cmp r1, #0
	blt _0802CBDE
	ldr r0, _0802CBE4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0802CBDE
	ldr r0, _0802CBE8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0802CBEC
_0802CBDE:
	movs r4, #0
	b _0802CBFA
	.align 2, 0
_0802CBE4: .4byte 0x030046A8
_0802CBE8: .4byte 0x030046AC
_0802CBEC:
	ldr r0, _0802CC0C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0802CBFA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0802CC10
	adds r0, #4
	b _0802CC1C
	.align 2, 0
_0802CC0C: .4byte 0x030046A4
_0802CC10:
	ldr r0, _0802CC30 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0802CC1C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0802CC34
	cmp r2, #2
	beq _0802CC38
	b _0802CC3C
	.align 2, 0
_0802CC30: .4byte 0x030046A4
_0802CC34:
	ldrb r0, [r5, #4]
	b _0802CC3A
_0802CC38:
	ldrb r0, [r5]
_0802CC3A:
	subs r1, r1, r0
_0802CC3C:
	movs r0, #0xb2
	lsls r0, r0, #1
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r1, r0
	ldr r3, _0802CC80 @ =0x000001FF
	adds r0, r0, r3
	ldr r1, _0802CC84 @ =0x000002FE
	movs r2, #0
	cmp r0, r1
	bls _0802CC56
	movs r2, #1
_0802CC56:
	cmp r2, #0
	bne _0802CC64
	adds r0, r7, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CC88
_0802CC64:
	movs r0, #9
	adds r2, r7, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa8
_0802CC78:
	movs r0, #1
	strb r0, [r1]
	b _0802CC92
	.align 2, 0
_0802CC80: .4byte 0x000001FF
_0802CC84: .4byte 0x000002FE
_0802CC88:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802CC92:
	add sp, #0x38
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802cca0
FUN_0802cca0: @ 0x0802CCA0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802CCC6
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0802CCCC
_0802CCC6:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0802CCCC:
	cmp r1, #0
	beq _0802CCD8
	movs r0, #9
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802CCD8:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802CD1C
	ldr r1, _0802CCF0 @ =0x00000FD4
	adds r0, r3, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _0802CCF4
	movs r2, #0xa
	movs r1, #0
	b _0802CCF6
	.align 2, 0
_0802CCF0: .4byte 0x00000FD4
_0802CCF4:
	movs r2, #0x5a
_0802CCF6:
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802CD18 @ =0x0000089C
	adds r0, r3, r1
	strh r2, [r0]
	b _0802CD26
	.align 2, 0
_0802CD18: .4byte 0x0000089C
_0802CD1C:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802CD26:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802cd2c
FUN_0802cd2c: @ 0x0802CD2C
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802CD52
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0802CD58
_0802CD52:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0802CD58:
	cmp r1, #0
	beq _0802CD64
	movs r0, #0xa
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802CD64:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802CD94
	movs r2, #0x5a
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802CD90 @ =0x0000089C
	adds r0, r3, r1
	strh r2, [r0]
	b _0802CD9E
	.align 2, 0
_0802CD90: .4byte 0x0000089C
_0802CD94:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802CD9E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802cda4
FUN_0802cda4: @ 0x0802CDA4
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802CDCA
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0802CDD0
_0802CDCA:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0802CDD0:
	cmp r1, #0
	beq _0802CDDC
	movs r0, #0xb
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802CDDC:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802CE20
	ldr r1, _0802CDF4 @ =0x00000FD4
	adds r0, r3, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _0802CDF8
	movs r2, #0x1e
	movs r1, #0
	b _0802CDFA
	.align 2, 0
_0802CDF4: .4byte 0x00000FD4
_0802CDF8:
	movs r2, #0x1e
_0802CDFA:
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802CE1C @ =0x0000089C
	adds r0, r3, r1
	strh r2, [r0]
	b _0802CE2A
	.align 2, 0
_0802CE1C: .4byte 0x0000089C
_0802CE20:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802CE2A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802ce30
FUN_0802ce30: @ 0x0802CE30
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802CE56
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0802CE5C
_0802CE56:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0802CE5C:
	cmp r1, #0
	beq _0802CE68
	movs r0, #0xc
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802CE68:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802CE98
	movs r2, #0xb4
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802CE94 @ =0x0000089C
	adds r0, r3, r1
	strh r2, [r0]
	b _0802CEA2
	.align 2, 0
_0802CE94: .4byte 0x0000089C
_0802CE98:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802CEA2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802cea8
FUN_0802cea8: @ 0x0802CEA8
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802CECE
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0802CED4
_0802CECE:
	movs r1, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0802CED4:
	cmp r1, #0
	beq _0802CEE0
	movs r0, #0xd
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802CEE0:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802CF24
	ldr r1, _0802CEF8 @ =0x00000FD4
	adds r0, r3, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _0802CEFC
	movs r2, #5
	movs r1, #0
	b _0802CEFE
	.align 2, 0
_0802CEF8: .4byte 0x00000FD4
_0802CEFC:
	movs r2, #0x96
_0802CEFE:
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802CF20 @ =0x0000089C
	adds r0, r3, r1
	strh r2, [r0]
	b _0802CF2E
	.align 2, 0
_0802CF20: .4byte 0x0000089C
_0802CF24:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802CF2E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802cf34
FUN_0802cf34: @ 0x0802CF34
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r1, r5, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802CF58
	strb r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0802CF5A
_0802CF58:
	movs r0, #0
_0802CF5A:
	cmp r0, #0
	beq _0802CF76
	adds r0, r4, #0
	bl FUN_08029628
	movs r0, #0xe
	adds r2, r5, #0
	adds r2, #0xa2
	movs r1, #0
	strb r0, [r2]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_0802CF76:
	adds r0, r4, #0
	bl FUN_0802bc7c
	adds r3, r0, #0
	cmp r3, #0
	bne _0802CFEC
	adds r0, r5, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CFE2
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r2, _0802CFCC @ =0x0000017B
	adds r1, r4, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0802CFD4
	movs r2, #0x5a
	adds r0, r4, #0
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x16
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]

	non_word_aligned_thumb_func_start FUN_0802cfc2
FUN_0802cfc2: @ 0x0802CFC2
	ldr r1, _0802CFD0 @ =0x0000089C
	adds r0, r4, r1
	strh r2, [r0]
	b _0802CFEC
	.align 2, 0
_0802CFCC: .4byte 0x0000017B
_0802CFD0: .4byte 0x0000089C
_0802CFD4:
	adds r0, r4, #0
	bl FUN_08029628
	movs r0, #0xe
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802CFE2:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802CFEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802cff4
FUN_0802cff4: @ 0x0802CFF4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D018
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0802D01A
_0802D018:
	movs r0, #0
_0802D01A:
	cmp r0, #0
	beq _0802D026
	movs r0, #0xf
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802D026:
	adds r0, r5, #0
	bl FUN_0802bc7c
	adds r1, r0, #0
	cmp r1, #0
	bne _0802D06E
	adds r0, r4, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D064
	movs r2, #0x5a
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802D060 @ =0x0000089C
	adds r0, r5, r1
	strh r2, [r0]
	b _0802D06E
	.align 2, 0
_0802D060: .4byte 0x0000089C
_0802D064:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D06E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802d074
FUN_0802d074: @ 0x0802D074
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r1, r5, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D098
	strb r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0802D09A
_0802D098:
	movs r0, #0
_0802D09A:
	cmp r0, #0
	beq _0802D0B6
	adds r0, r4, #0
	bl FUN_08029628
	movs r0, #0x10
	adds r2, r5, #0
	adds r2, #0xa2
	movs r1, #0
	strb r0, [r2]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_0802D0B6:
	adds r0, r4, #0
	bl FUN_0802bc7c
	adds r3, r0, #0
	cmp r3, #0
	bne _0802D12C
	adds r0, r5, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D122
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r2, _0802D10C @ =0x0000017B
	adds r1, r4, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0802D114
	movs r2, #0x5a
	adds r0, r4, #0
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x16
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802D110 @ =0x0000089C
	adds r0, r4, r1
	strh r2, [r0]
	b _0802D12C
	.align 2, 0
_0802D10C: .4byte 0x0000017B
_0802D110: .4byte 0x0000089C
_0802D114:
	adds r0, r4, #0
	bl FUN_08029628
	movs r0, #0x10
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802D122:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D12C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802d134
FUN_0802d134: @ 0x0802D134
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r1, r5, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D158
	strb r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0802D15A
_0802D158:
	movs r0, #0
_0802D15A:
	cmp r0, #0
	beq _0802D17A
	movs r0, #0x11
	adds r2, r5, #0
	adds r2, #0xa2
	movs r1, #0
	strb r0, [r2]
	ldr r2, _0802D1A8 @ =0x00000898
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _0802D1AC @ =0x000008D4
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_0802D17A:
	ldr r1, _0802D1B0 @ =0x00000864
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0802D1B8
	movs r2, #0x5a
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802D1B4 @ =0x0000089C
	adds r0, r4, r1
	strh r2, [r0]
	b _0802D28E
	.align 2, 0
_0802D1A8: .4byte 0x00000898
_0802D1AC: .4byte 0x000008D4
_0802D1B0: .4byte 0x00000864
_0802D1B4: .4byte 0x0000089C
_0802D1B8:
	adds r0, r5, #0
	adds r0, #0xa7
	ldrb r2, [r0]
	cmp r2, #0
	beq _0802D1D8
	movs r0, #0x12
	adds r2, r5, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa8
	b _0802D1F8
_0802D1D8:
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r5, #0
	adds r0, #0x98
	ldr r3, [r0]
	ands r3, r1
	cmp r3, #0
	beq _0802D1FE
	movs r0, #0x10
	adds r1, r5, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xbc
	str r2, [r0]
	adds r1, #2
_0802D1F8:
	movs r0, #1
	strb r0, [r1]
	b _0802D28E
_0802D1FE:
	ldr r2, _0802D244 @ =0x00000894
	adds r0, r4, r2
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r2, #0x42
	adds r0, r4, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _0802D270
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r6, [r0]
	cmp r6, #0
	beq _0802D248
	subs r2, #0x3d
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0
	strb r0, [r2]
	movs r0, #5
	adds r2, r5, #0
	adds r2, #0xa6
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r3, [r0]
	b _0802D266
	.align 2, 0
_0802D244: .4byte 0x00000894
_0802D248:
	ldr r1, _0802D26C @ =0x00000899
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #5
	adds r2, r5, #0
	adds r2, #0xa6
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r6, [r0]
_0802D266:
	subs r0, #0x14
	strb r1, [r0]
	b _0802D28E
	.align 2, 0
_0802D26C: .4byte 0x00000899
_0802D270:
	adds r0, r4, #0
	bl FUN_080280cc
	cmp r0, #0
	bne _0802D28E
	adds r0, r4, #0
	bl FUN_080281ec
	cmp r0, #0
	bne _0802D28E
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D28E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802d294
FUN_0802d294: @ 0x0802D294
	push {r4, r5, lr}
	adds r3, r0, #0
	mov ip, r3
	adds r4, r3, #0
	adds r4, #0x48
	adds r1, r3, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D2BC
	strb r2, [r1]
	adds r0, r3, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0802D2BE
_0802D2BC:
	movs r0, #0
_0802D2BE:
	cmp r0, #0
	beq _0802D2CA
	movs r0, #0x12
	adds r1, r3, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802D2CA:
	ldr r0, _0802D2F8 @ =0x00000864
	add r0, ip
	ldr r1, [r0]
	cmp r1, #0
	bne _0802D300
	movs r2, #0x5a
	mov r0, ip
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0802D2FC @ =0x0000089C
	add r0, ip
	strh r2, [r0]
	b _0802D364
	.align 2, 0
_0802D2F8: .4byte 0x00000864
_0802D2FC: .4byte 0x0000089C
_0802D300:
	adds r0, r3, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D35A
	ldr r1, _0802D338 @ =0x00000868
	add r1, ip
	movs r0, #0
	ldrsh r2, [r1, r0]
	movs r5, #8
	ldrsh r0, [r4, r5]
	subs r2, r2, r0
	movs r5, #4
	ldrsh r0, [r1, r5]
	movs r5, #0xc
	ldrsh r1, [r4, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0802D33C @ =0x000023FF
	cmp r1, r0
	bgt _0802D340
	movs r0, #0x12
	b _0802D342
	.align 2, 0
_0802D338: .4byte 0x00000868
_0802D33C: .4byte 0x000023FF
_0802D340:
	movs r0, #0xf
_0802D342:
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802D364
_0802D35A:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D364:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802d36c
FUN_0802d36c: @ 0x0802D36C
	push {r4, lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D392
	strb r2, [r1]
	adds r0, r3, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r1, #1
	adds r4, r0, #0
	b _0802D398
_0802D392:
	movs r1, #0
	adds r4, r3, #0
	adds r4, #0xa7
_0802D398:
	cmp r1, #1
	bne _0802D3D2
	movs r0, #0x82
	lsls r0, r0, #4
	add r0, ip
	ldr r2, [r0]
	cmp r2, #0
	bne _0802D3BA
	movs r0, #0xc
	adds r1, r3, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #1
	add r0, ip
	strb r2, [r0]
	b _0802D3C8
_0802D3BA:
	ldr r0, _0802D40C @ =0x00000892
	add r0, ip
	strb r1, [r0]
	movs r0, #0xd
	adds r1, r3, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802D3C8:
	movs r1, #0xbb
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0
	strb r0, [r1]
_0802D3D2:
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r3, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0802D3EC
	movs r1, #0xbb
	lsls r1, r1, #1
	add r1, ip
	movs r0, #8
	strb r0, [r1]
_0802D3EC:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802D410
	movs r0, #0xf
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802D41A
	.align 2, 0
_0802D40C: .4byte 0x00000892
_0802D410:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D41A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802d420
FUN_0802d420: @ 0x0802D420
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r1, r2, #0
	adds r1, #0x96
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D444
	strb r4, [r1]
	adds r0, r2, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r0, #1
	b _0802D446
_0802D444:
	movs r0, #0
_0802D446:
	cmp r0, #0
	beq _0802D452
	movs r0, #0x13
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802D452:
	ldr r1, _0802D480 @ =0x00000864
	adds r0, r3, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0802D488
	movs r2, #0x5a
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802D484 @ =0x0000089C
	adds r0, r3, r1
	strh r2, [r0]
	b _0802D4B6
	.align 2, 0
_0802D480: .4byte 0x00000864
_0802D484: .4byte 0x0000089C
_0802D488:
	adds r0, r2, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D4AC
	movs r0, #0x13
	adds r3, r2, #0
	adds r3, #0xa6
	movs r1, #0
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r2, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802D4B6
_0802D4AC:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D4B6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802d4bc
FUN_0802d4bc: @ 0x0802D4BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r5, #0
	adds r7, r5, #0
	adds r7, #0x48
	adds r1, r5, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D4E8
	strb r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r1, #1
	adds r3, r0, #0
	b _0802D4EE
_0802D4E8:
	movs r1, #0
	adds r3, r5, #0
	adds r3, #0xa7
_0802D4EE:
	adds r2, r1, #0
	cmp r2, #1
	bne _0802D512
	movs r0, #0x14
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _0802D50C
	ldr r1, _0802D590 @ =0x00000893
	adds r0, r6, r1
	strb r2, [r0]
_0802D50C:
	ldr r1, _0802D594 @ =0x000008DD
	adds r0, r6, r1
	strb r2, [r0]
_0802D512:
	ldrb r0, [r3]
	cmp r0, #0
	beq _0802D5C8
	adds r0, r6, #0
	bl FUN_0802835c
	adds r1, r0, #0
	cmp r1, #0
	beq _0802D5A0
	add r4, sp, #0xc
	adds r1, r7, #0
	adds r1, #8
	ldr r2, [r7, #8]
	ldr r3, [r7, #0xc]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldrh r0, [r4, #2]
	adds r0, #0xc8
	movs r7, #0
	strh r0, [r4, #2]
	add r4, sp, #0x14
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_0823585c
	ldr r1, _0802D598 @ =0x00001058
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0802D56A
	movs r0, #0xa
	str r0, [sp]
	adds r0, r1, #0
	add r1, sp, #0xc
	adds r2, r4, #0
	movs r3, #0xa
	bl FUN_0805d3a8
_0802D56A:
	movs r0, #0x1c
	adds r1, r5, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0802D590 @ =0x00000893
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0802D59C @ =0x00000346
	bl PlaySound_082406e0
	b _0802D5D2
	.align 2, 0
_0802D590: .4byte 0x00000893
_0802D594: .4byte 0x000008DD
_0802D598: .4byte 0x00001058
_0802D59C: .4byte 0x00000346
_0802D5A0:
	movs r2, #0x5a
	adds r0, r6, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r6, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802D5C4 @ =0x0000089C
	adds r0, r6, r1
	strh r2, [r0]
	b _0802D5D2
	.align 2, 0
_0802D5C4: .4byte 0x0000089C
_0802D5C8:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D5D2:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802d5dc
FUN_0802d5dc: @ 0x0802D5DC
	push {r4, lr}
	adds r2, r0, #0
	mov ip, r2
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D5FA
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r4, r1, #0
	b _0802D600
_0802D5FA:
	movs r0, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0802D600:
	cmp r0, #0
	beq _0802D614
	movs r0, #0x15
	adds r3, r2, #0
	adds r3, #0xa2
	movs r1, #0
	strb r0, [r3]
	ldr r0, _0802D634 @ =0x00000891
	add r0, ip
	strb r1, [r0]
_0802D614:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802D638
	movs r0, #0x15
	adds r3, r2, #0
	adds r3, #0xa6
	movs r1, #0
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r2, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802D642
	.align 2, 0
_0802D634: .4byte 0x00000891
_0802D638:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D642:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802d648
FUN_0802d648: @ 0x0802D648
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D664
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802D66A
_0802D664:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802D66A:
	cmp r0, #0
	beq _0802D676
	movs r0, #0x16
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802D676:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D6B8
	ldr r1, _0802D68C @ =0x00000891
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _0802D690
	movs r0, #0x16
	b _0802D692
	.align 2, 0
_0802D68C: .4byte 0x00000891
_0802D690:
	movs r0, #0x17
_0802D692:
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0802D6B4 @ =0x00000891
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802D6C2
	.align 2, 0
_0802D6B4: .4byte 0x00000891
_0802D6B8:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D6C2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802d6c8
FUN_0802d6c8: @ 0x0802D6C8
	push {lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D6E4
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802D6EA
_0802D6E4:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802D6EA:
	cmp r0, #0
	beq _0802D6F6
	movs r0, #0x17
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802D6F6:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D728
	movs r2, #0x1e
	movs r1, #0
	mov r0, ip
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0802D724 @ =0x0000089C
	add r0, ip
	strh r2, [r0]
	b _0802D732
	.align 2, 0
_0802D724: .4byte 0x0000089C
_0802D728:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D732:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802d738
FUN_0802d738: @ 0x0802D738
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	mov r8, r7
	adds r4, r7, #0
	adds r4, #0x48
	adds r1, r7, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D75E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802D764
_0802D75E:
	movs r0, #0
	adds r1, r7, #0
	adds r1, #0xa7
_0802D764:
	cmp r0, #0
	beq _0802D770
	movs r0, #0x18
	adds r2, r7, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802D770:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D846
	ldr r5, _0802D818 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r5
	ldr r1, _0802D81C @ =0x0000FF5C
	orrs r0, r1
	str r0, [sp]
	mov r2, sp
	ldr r0, [sp, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #4]
	adds r3, r4, #0
	adds r3, #8
	mov r0, sp
	ldrh r4, [r4, #8]
	ldrh r0, [r0]
	adds r1, r4, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r6, [r3, #2]
	adds r0, r0, r6
	strh r0, [r2, #2]
	ldrh r1, [r3, #4]
	ldrh r3, [r2, #4]
	adds r0, r1, r3
	strh r0, [r2, #4]
	ldr r0, [sp, #8]
	ands r0, r5
	movs r2, #0xa4
	orrs r0, r2
	str r0, [sp, #8]
	add r3, sp, #8
	ldr r0, [r3, #4]
	ands r0, r5
	orrs r0, r2
	str r0, [r3, #4]
	ldrh r0, [r3]
	adds r4, r4, r0
	strh r4, [r3]
	ldrh r0, [r3, #2]
	adds r0, r0, r6
	strh r0, [r3, #2]
	ldrh r0, [r3, #4]
	adds r1, r1, r0
	strh r1, [r3, #4]
	ldr r0, _0802D820 @ =0x0000016B
	add r0, r8
	ldrb r1, [r0]
	mov r0, r8
	mov r2, sp
	bl FUN_08028720
	adds r2, r0, #0
	cmp r2, #0
	blt _0802D82C
	ldr r1, _0802D824 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r0, #0x20]
	ands r0, r1
	rsbs r0, r0, #0
	lsrs r3, r0, #0x1f
	cmp r3, #0
	bne _0802D82C
	ldr r0, _0802D828 @ =0x00000173
	add r0, r8
	strb r2, [r0]
	movs r0, #0x18
	adds r1, r7, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbc
	str r3, [r0]
	adds r1, #2
	b _0802D840
	.align 2, 0
_0802D818: .4byte 0xFFFF0000
_0802D81C: .4byte 0x0000FF5C
_0802D820: .4byte 0x0000016B
_0802D824: .4byte 0x03002BE0
_0802D828: .4byte 0x00000173
_0802D82C:
	movs r0, #0x19
	adds r2, r7, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa8
_0802D840:
	movs r0, #1
	strb r0, [r1]
	b _0802D850
_0802D846:
	adds r1, r7, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D850:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802d85c
FUN_0802d85c: @ 0x0802D85C
	push {lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D878
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802D87E
_0802D878:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802D87E:
	cmp r0, #0
	beq _0802D88A
	movs r0, #0x19
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802D88A:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D8C2
	ldr r0, _0802D8A4 @ =0x00000173
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0802D8A8
	movs r0, #0x15
	b _0802D8AA
	.align 2, 0
_0802D8A4: .4byte 0x00000173
_0802D8A8:
	movs r0, #0x1a
_0802D8AA:
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802D8CC
_0802D8C2:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D8CC:
	pop {r0}
	bx r0

	thumb_func_start FUN_0802d8d0
FUN_0802d8d0: @ 0x0802D8D0
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D8EA
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802D8F0
_0802D8EA:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802D8F0:
	cmp r0, #0
	beq _0802D8FC
	movs r0, #0x1a
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802D8FC:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D91C
	movs r0, #0x15
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802D926
_0802D91C:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D926:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802d92c
FUN_0802d92c: @ 0x0802D92C
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D946
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802D94C
_0802D946:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802D94C:
	cmp r0, #0
	beq _0802D958
	movs r0, #0x1b
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802D958:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D978
	movs r0, #0x15
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802D982
_0802D978:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D982:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802d988
FUN_0802d988: @ 0x0802D988
	push {lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D9A4
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802D9AA
_0802D9A4:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802D9AA:
	cmp r0, #0
	beq _0802D9B6
	movs r0, #0x1c
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802D9B6:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D9E8
	movs r2, #5
	movs r1, #0
	mov r0, ip
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0802D9E4 @ =0x0000089C
	add r0, ip
	strh r2, [r0]
	b _0802D9F2
	.align 2, 0
_0802D9E4: .4byte 0x0000089C
_0802D9E8:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D9F2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802d9f8
FUN_0802d9f8: @ 0x0802D9F8
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DA12
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DA14
_0802DA12:
	movs r0, #0
_0802DA14:
	cmp r0, #0
	beq _0802DA20
	movs r0, #0x1d
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802DA20:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802da30
FUN_0802da30: @ 0x0802DA30
	push {lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DA4C
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DA52
_0802DA4C:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DA52:
	cmp r0, #0
	beq _0802DA5E
	movs r0, #0x1e
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DA5E:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DA90
	movs r2, #0x5a
	movs r1, #0
	mov r0, ip
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0802DA8C @ =0x0000089C
	add r0, ip
	strh r2, [r0]
	b _0802DA9A
	.align 2, 0
_0802DA8C: .4byte 0x0000089C
_0802DA90:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DA9A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802daa0
FUN_0802daa0: @ 0x0802DAA0
	push {r4, lr}
	mov ip, r0
	mov r3, ip
	mov r1, ip
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DABC
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DABE
_0802DABC:
	movs r0, #0
_0802DABE:
	cmp r0, #0
	beq _0802DAD2
	movs r0, #0x1f
	mov r2, ip
	adds r2, #0xa2
	movs r1, #0
	strb r0, [r2]
	ldr r2, _0802DB00 @ =0x0000088A
	adds r0, r3, r2
	strh r1, [r0]
_0802DAD2:
	movs r4, #1
	mov r0, ip
	adds r0, #0x98
	ldr r2, [r0]
	ands r2, r4
	cmp r2, #0
	bne _0802DB08
	movs r1, #0x3c
	adds r0, r3, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r4, [r0]
	ldr r2, _0802DB04 @ =0x0000089C
	adds r0, r3, r2
	strh r1, [r0]
	b _0802DB12
	.align 2, 0
_0802DB00: .4byte 0x0000088A
_0802DB04: .4byte 0x0000089C
_0802DB08:
	mov r1, ip
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DB12:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802db18
FUN_0802db18: @ 0x0802DB18
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DB2E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
_0802DB2E:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0

	thumb_func_start FUN_0802db3c
FUN_0802db3c: @ 0x0802DB3C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DB56
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DB58
_0802DB56:
	movs r0, #0
_0802DB58:
	cmp r0, #0
	beq _0802DB64
	movs r0, #0x23
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_0802DB64:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802db74
FUN_0802db74: @ 0x0802DB74
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DB8E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DB90
_0802DB8E:
	movs r0, #0
_0802DB90:
	cmp r0, #0
	beq _0802DBA8
	movs r0, #0x24
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0802DBA8:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802dbb8
FUN_0802dbb8: @ 0x0802DBB8
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DBD2
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DBD4
_0802DBD2:
	movs r0, #0
_0802DBD4:
	cmp r0, #0
	beq _0802DBEC
	movs r0, #0x25
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0802DBEC:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802dbfc
FUN_0802dbfc: @ 0x0802DBFC
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DC16
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DC1C
_0802DC16:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DC1C:
	cmp r0, #0
	beq _0802DC28
	movs r0, #0x26
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DC28:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DC4E
	movs r2, #1
	adds r0, r3, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DC58
_0802DC4E:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DC58:
	pop {r0}
	bx r0

	thumb_func_start FUN_0802dc5c
FUN_0802dc5c: @ 0x0802DC5C
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DC76
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DC7C
_0802DC76:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DC7C:
	cmp r0, #0
	beq _0802DC88
	movs r0, #0x27
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DC88:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DCAE
	movs r2, #1
	adds r0, r3, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DCB8
_0802DCAE:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DCB8:
	pop {r0}
	bx r0

	thumb_func_start FUN_0802dcbc
FUN_0802dcbc: @ 0x0802DCBC
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DCD6
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DCDC
_0802DCD6:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DCDC:
	cmp r0, #0
	beq _0802DCE8
	movs r0, #0x28
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DCE8:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DD14
	movs r0, #2
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DD1E
_0802DD14:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DD1E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802dd24
FUN_0802dd24: @ 0x0802DD24
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DD3E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DD44
_0802DD3E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DD44:
	cmp r0, #0
	beq _0802DD50
	movs r0, #0x29
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DD50:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DD76
	movs r2, #1
	adds r0, r3, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DD80
_0802DD76:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DD80:
	pop {r0}
	bx r0

	thumb_func_start FUN_0802dd84
FUN_0802dd84: @ 0x0802DD84
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DD9E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DDA4
_0802DD9E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DDA4:
	cmp r0, #0
	beq _0802DDB0
	movs r0, #0x2a
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DDB0:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DDD8
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DDE2
_0802DDD8:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DDE2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802dde8
FUN_0802dde8: @ 0x0802DDE8
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DE02
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DE04
_0802DE02:
	movs r0, #0
_0802DE04:
	cmp r0, #0
	beq _0802DE1C
	movs r0, #0x2b
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0802DE1C:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802de2c
FUN_0802de2c: @ 0x0802DE2C
	push {r4, lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DE48
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DE4E
_0802DE48:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DE4E:
	cmp r0, #0
	beq _0802DE6C
	ldr r4, _0802DE60 @ =0x00000171
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802DE64
	movs r0, #0x2c
	b _0802DE66
	.align 2, 0
_0802DE60: .4byte 0x00000171
_0802DE64:
	movs r0, #0x2d
_0802DE66:
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DE6C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DE92
	movs r2, #1
	adds r0, r3, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DE9C
_0802DE92:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DE9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802dea4
FUN_0802dea4: @ 0x0802DEA4
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DEBE
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DEC4
_0802DEBE:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DEC4:
	cmp r0, #0
	beq _0802DED0
	movs r0, #0x2e
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DED0:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DEF6
	movs r2, #1
	adds r0, r3, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DF00
_0802DEF6:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DF00:
	pop {r0}
	bx r0

	thumb_func_start FUN_0802df04
FUN_0802df04: @ 0x0802DF04
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DF1E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DF24
_0802DF1E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DF24:
	cmp r0, #0
	beq _0802DF30
	movs r0, #0x2f
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DF30:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DF56
	movs r2, #1
	adds r0, r3, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DF60
_0802DF56:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DF60:
	pop {r0}
	bx r0

	thumb_func_start FUN_0802df64
FUN_0802df64: @ 0x0802DF64
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DF7E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DF84
_0802DF7E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DF84:
	cmp r0, #0
	beq _0802DF90
	movs r0, #0x30
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DF90:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DFA4
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DFAE
_0802DFA4:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DFAE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802dfb4
FUN_0802dfb4: @ 0x0802DFB4
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DFCE
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802DFD4
_0802DFCE:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802DFD4:
	cmp r0, #0
	beq _0802DFE0
	movs r0, #0x31
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802DFE0:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802DFF4
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802DFFE
_0802DFF4:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802DFFE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802e004
FUN_0802e004: @ 0x0802E004
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E01E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E024
_0802E01E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802E024:
	cmp r0, #0
	beq _0802E030
	movs r0, #0x32
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802E030:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E044
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E04E
_0802E044:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E04E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802e054
FUN_0802e054: @ 0x0802E054
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E06E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E074
_0802E06E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802E074:
	cmp r0, #0
	beq _0802E080
	movs r0, #0x33
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802E080:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E094
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E09E
_0802E094:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E09E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802e0a4
FUN_0802e0a4: @ 0x0802E0A4
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E0BE
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E0C0
_0802E0BE:
	movs r0, #0
_0802E0C0:
	cmp r0, #0
	beq _0802E0D8
	movs r0, #0x34
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0802E0D8:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802e0e8
FUN_0802e0e8: @ 0x0802E0E8
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E102
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E108
_0802E102:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802E108:
	cmp r0, #0
	beq _0802E114
	movs r0, #0x35
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802E114:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E128
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E132
_0802E128:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E132:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802e138
FUN_0802e138: @ 0x0802E138
	push {r4, lr}
	adds r2, r0, #0
	mov ip, r2
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E156
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r4, r1, #0
	b _0802E15C
_0802E156:
	movs r0, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0802E15C:
	cmp r0, #0
	beq _0802E170
	movs r0, #0x36
	adds r3, r2, #0
	adds r3, #0xa2
	movs r1, #0
	strb r0, [r3]
	ldr r0, _0802E184 @ =0x00000173
	add r0, ip
	strb r1, [r0]
_0802E170:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802E188
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E192
	.align 2, 0
_0802E184: .4byte 0x00000173
_0802E188:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E192:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802e198
FUN_0802e198: @ 0x0802E198
	push {r4, lr}
	adds r2, r0, #0
	mov ip, r2
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E1B6
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r4, r1, #0
	b _0802E1BC
_0802E1B6:
	movs r0, #0
	adds r4, r2, #0
	adds r4, #0xa7
_0802E1BC:
	cmp r0, #0
	beq _0802E1D0
	movs r0, #0x37
	adds r3, r2, #0
	adds r3, #0xa2
	movs r1, #0
	strb r0, [r3]
	ldr r0, _0802E1FC @ =0x00000173
	add r0, ip
	strb r1, [r0]
_0802E1D0:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802E200
	movs r0, #2
	adds r3, r2, #0
	adds r3, #0xa6
	movs r1, #0
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r2, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E20A
	.align 2, 0
_0802E1FC: .4byte 0x00000173
_0802E200:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E20A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802e210
FUN_0802e210: @ 0x0802E210
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E22A
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E230
_0802E22A:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802E230:
	cmp r0, #0
	beq _0802E23C
	movs r0, #0x38
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802E23C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E264
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E26E
_0802E264:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E26E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802e274
FUN_0802e274: @ 0x0802E274
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E28E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E294
_0802E28E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802E294:
	cmp r0, #0
	beq _0802E2A0
	movs r0, #0x39
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802E2A0:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E2C8
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E2D2
_0802E2C8:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E2D2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802e2d8
FUN_0802e2d8: @ 0x0802E2D8
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E2F2
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E2F8
_0802E2F2:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802E2F8:
	cmp r0, #0
	beq _0802E304
	movs r0, #0x3a
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802E304:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E330
	movs r0, #2
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E33A
_0802E330:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E33A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802e340
FUN_0802e340: @ 0x0802E340
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E35A
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E35C
_0802E35A:
	movs r0, #0
_0802E35C:
	cmp r0, #0
	beq _0802E374
	movs r0, #0x3b
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0802E374:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802e384
FUN_0802e384: @ 0x0802E384
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E39E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E3A4
_0802E39E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802E3A4:
	cmp r0, #0
	beq _0802E3B0
	movs r0, #0x3c
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802E3B0:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E3D6
	movs r2, #1
	adds r0, r3, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E3E0
_0802E3D6:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E3E0:
	pop {r0}
	bx r0

	thumb_func_start FUN_0802e3e4
FUN_0802e3e4: @ 0x0802E3E4
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E3FE
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0802E404
_0802E3FE:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0802E404:
	cmp r0, #0
	beq _0802E410
	movs r0, #0x3d
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0802E410:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E424
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0802E42E
_0802E424:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802E42E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802e434
FUN_0802e434: @ 0x0802E434
	push {lr}
	ldr r2, _0802E44C @ =0x085AAC38
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0802E44C: .4byte 0x085AAC38

	thumb_func_start FUN_0802e450
FUN_0802e450: @ 0x0802E450
	push {lr}
	ldr r2, _0802E468 @ =0x085AACB0
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0802E468: .4byte 0x085AACB0

	thumb_func_start FUN_0802e46c
FUN_0802e46c: @ 0x0802E46C
	push {lr}
	ldr r2, _0802E484 @ =0x085AACB8
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0802E484: .4byte 0x085AACB8

	thumb_func_start FUN_0802e488
FUN_0802e488: @ 0x0802E488
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _0802E4BC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0802E4B6
	adds r0, r4, #0
	bl FUN_0802c2d4
	cmp r0, #0
	bne _0802E4B6
	ldr r0, _0802E4C0 @ =0x085AAD20
	adds r1, r4, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0802E4B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802E4BC: .4byte 0x03002BC0
_0802E4C0: .4byte 0x085AAD20

	thumb_func_start FUN_0802e4c4
FUN_0802e4c4: @ 0x0802E4C4
	push {lr}
	ldr r2, _0802E4DC @ =0x085AAD24
	adds r1, r0, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0802E4DC: .4byte 0x085AAD24

	thumb_func_start FUN_0802e4e0
FUN_0802e4e0: @ 0x0802E4E0
	push {lr}
	ldr r2, _0802E4F8 @ =0x085AAD28
	adds r1, r0, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0802E4F8: .4byte 0x085AAD28

	thumb_func_start FUN_0802e4fc
FUN_0802e4fc: @ 0x0802E4FC
	push {lr}
	adds r2, r0, #0
	adds r2, #0x9d
	movs r1, #0
	strb r1, [r2]
	ldr r2, _0802E51C @ =0x085AAD2C
	adds r1, r0, #0
	adds r1, #0xa4
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0802E51C: .4byte 0x085AAD2C

	thumb_func_start FUN_0802e520
FUN_0802e520: @ 0x0802E520
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r5, #0
	ldr r0, _0802E590 @ =0x00000899
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E5C4
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E598
	ldr r1, _0802E594 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802E5A8
	movs r3, #0
	b _0802E5A8
	.align 2, 0
_0802E590: .4byte 0x00000899
_0802E594: .4byte 0x00000824
_0802E598:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802E5A8
	movs r3, #5
_0802E5A8:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022d24
	b _0802E60C
_0802E5C4:
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E5E4
	ldr r1, _0802E5E0 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802E5F4
	movs r3, #0
	b _0802E5F4
	.align 2, 0
_0802E5E0: .4byte 0x00000824
_0802E5E4:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802E5F4
	movs r3, #5
_0802E5F4:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022d24
_0802E60C:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802E6A4
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802E6A4
	ldr r2, _0802E680 @ =0x00000FD4
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802E64A
	movs r2, #0x80
	lsls r2, r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0802E64A:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0802E660
	adds r0, r2, #2
	strh r0, [r3]
_0802E660:
	ldr r2, _0802E684 @ =0x085B0A08
	lsls r0, r6, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802E688
	asrs r1, r0, #0xc
	b _0802E68E
	.align 2, 0
_0802E680: .4byte 0x00000FD4
_0802E684: .4byte 0x085B0A08
_0802E688:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802E68E:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r4, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0802E6A4
	movs r0, #0
	strh r0, [r1]
_0802E6A4:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802e6ac
FUN_0802e6ac: @ 0x0802E6AC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r5, #0
	ldr r0, _0802E71C @ =0x00000899
	adds r1, r5, r0
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E78C
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E724
	ldr r1, _0802E720 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802E734
	movs r3, #0
	b _0802E734
	.align 2, 0
_0802E71C: .4byte 0x00000899
_0802E720: .4byte 0x00000824
_0802E724:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802E734
	movs r3, #5
_0802E734:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022d24
	ldr r1, _0802E780 @ =0x00000844
	adds r2, r6, r1
	ldr r3, _0802E784 @ =0x00000868
	adds r0, r6, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	bl FUN_08028604
	ldr r0, _0802E788 @ =0x0000084C
	adds r1, r6, r0
	movs r2, #0xbf
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrh r2, [r4]
	adds r0, r6, #0
	bl FUN_0802853c
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_08029a1c
	b _0802E7D6
	.align 2, 0
_0802E780: .4byte 0x00000844
_0802E784: .4byte 0x00000868
_0802E788: .4byte 0x0000084C
_0802E78C:
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E7AC
	ldr r3, _0802E7A8 @ =0x00000824
	adds r0, r5, r3
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802E7BC
	movs r3, #0
	b _0802E7BC
	.align 2, 0
_0802E7A8: .4byte 0x00000824
_0802E7AC:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802E7BC
	movs r3, #5
_0802E7BC:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022d24
_0802E7D6:
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0x3f
	bls _0802E7EE
	movs r2, #8
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0802E7EE:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802E8C8
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802E8C8
	ldr r3, _0802E860 @ =0x00000FD4
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802E82C
	movs r2, #0x80
	lsls r2, r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0802E82C:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0802E842
	adds r0, r2, #2
	strh r0, [r3]
_0802E842:
	ldr r2, _0802E864 @ =0x085B0A08
	lsls r0, r7, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802E868
	asrs r1, r0, #0xc
	b _0802E86E
	.align 2, 0
_0802E860: .4byte 0x00000FD4
_0802E864: .4byte 0x085B0A08
_0802E868:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802E86E:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0802E884
	movs r0, #0
	strh r0, [r1]
_0802E884:
	ldr r1, _0802E8B8 @ =0x000008E4
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802E898
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
_0802E898:
	movs r2, #0x84
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r3, _0802E8BC @ =0x00000842
	adds r1, r6, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0802E8C0
	adds r0, r6, #0
	bl FUN_08028648
	adds r0, r6, #0
	bl FUN_080286d8
	b _0802E8C8
	.align 2, 0
_0802E8B8: .4byte 0x000008E4
_0802E8BC: .4byte 0x00000842
_0802E8C0:
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802E8C8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802e8d0
FUN_0802e8d0: @ 0x0802E8D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	mov sb, r1
	adds r7, r6, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802E9C6
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0802E974 @ =0x00000899
	adds r5, r6, r1
	ldrb r0, [r5]
	adds r4, r6, #0
	adds r4, #0xc8
	adds r0, r4, r0
	ldrb r3, [r0]
	ldr r2, _0802E978 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0802E97C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0802E980 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x40
	adds r3, r3, r0
	ldr r1, _0802E984 @ =0x00000175
	adds r0, r6, r1
	strb r3, [r0]
	ldrb r0, [r5]
	adds r4, r4, r0
	ldrb r0, [r4]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E98C
	ldr r3, _0802E988 @ =0x00000824
	adds r0, r6, r3
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802E99C
	movs r3, #0
	b _0802E99C
	.align 2, 0
_0802E974: .4byte 0x00000899
_0802E978: .4byte 0x030046B8
_0802E97C: .4byte 0x000003FF
_0802E980: .4byte 0x0203B400
_0802E984: .4byte 0x00000175
_0802E988: .4byte 0x00000824
_0802E98C:
	movs r4, #0x82
	lsls r4, r4, #4
	adds r0, r6, r4
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802E99C
	movs r3, #5
_0802E99C:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_08022d24
	ldr r0, _0802EA2C @ =0x00000854
	adds r2, r7, r0
	mov r3, r8
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_0802E9C6:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0802EA30 @ =0x00000167
	adds r0, r7, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r4, #0x80
	adds r0, r6, r4
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802EAAA
	mov r0, sb
	cmp r0, #6
	bgt _0802EA9C
	ldr r1, _0802EA34 @ =0x00000175
	adds r0, r7, r1
	add r3, sp, #0xc
	ldrb r4, [r0]
	mov r0, sb
	lsls r5, r0, #5
	ldr r2, _0802EA38 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0802EA3C
	asrs r1, r0, #0xc
	b _0802EA42
	.align 2, 0
_0802EA2C: .4byte 0x00000854
_0802EA30: .4byte 0x00000167
_0802EA34: .4byte 0x00000175
_0802EA38: .4byte 0x085B0A08
_0802EA3C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802EA42:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _0802EA5A
	asrs r0, r0, #0xc
	b _0802EA60
_0802EA5A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802EA60:
	strh r0, [r3, #4]
	mov r3, r8
	adds r3, #8
	ldr r0, _0802EAB8 @ =0x00000854
	adds r1, r7, r0
	add r2, sp, #0xc
	adds r0, r2, #0
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	mov r4, r8
	strh r0, [r4, #8]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _0802EABC @ =0x000008E4
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802EA9C
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
_0802EA9C:
	mov r3, sb
	cmp r3, #0xf
	ble _0802EAAA
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802EAAA:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EAB8: .4byte 0x00000854
_0802EABC: .4byte 0x000008E4

	thumb_func_start FUN_0802eac0
FUN_0802eac0: @ 0x0802EAC0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	ldr r0, _0802EB30 @ =0x00000899
	adds r1, r6, r0
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802EBA0
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EB38
	ldr r1, _0802EB34 @ =0x00000824
	adds r0, r6, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802EB48
	movs r3, #0
	b _0802EB48
	.align 2, 0
_0802EB30: .4byte 0x00000899
_0802EB34: .4byte 0x00000824
_0802EB38:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802EB48
	movs r3, #5
_0802EB48:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_08022d24
	ldr r1, _0802EB94 @ =0x00000844
	adds r2, r5, r1
	ldr r3, _0802EB98 @ =0x00000868
	adds r0, r5, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r5, #0
	bl FUN_08028604
	ldr r0, _0802EB9C @ =0x0000084C
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0x20
	bl FUN_0802853c
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl FUN_08029a1c
	b _0802EBE8
	.align 2, 0
_0802EB94: .4byte 0x00000844
_0802EB98: .4byte 0x00000868
_0802EB9C: .4byte 0x0000084C
_0802EBA0:
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EBC0
	ldr r2, _0802EBBC @ =0x00000824
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802EBD0
	movs r3, #0
	b _0802EBD0
	.align 2, 0
_0802EBBC: .4byte 0x00000824
_0802EBC0:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r6, r3
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802EBD0
	movs r3, #5
_0802EBD0:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_08022d24
_0802EBE8:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, _0802EC6C @ =0x00000167
	adds r0, r5, r1
	strb r2, [r0]
	movs r1, #4
	adds r4, r6, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802ECD8
	ldr r3, _0802EC70 @ =0x00000FD4
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802EC36
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0802EC36:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0802EC4C
	adds r0, r2, #2
	strh r0, [r3]
_0802EC4C:
	ldr r2, _0802EC74 @ =0x085B0A08
	lsls r0, r7, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802EC78
	asrs r1, r0, #0xc
	b _0802EC7E
	.align 2, 0
_0802EC6C: .4byte 0x00000167
_0802EC70: .4byte 0x00000FD4
_0802EC74: .4byte 0x085B0A08
_0802EC78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802EC7E:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0802EC94
	movs r0, #0
	strh r0, [r1]
_0802EC94:
	ldr r1, _0802ECC8 @ =0x000008E4
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802ECA8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
_0802ECA8:
	movs r2, #0x84
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r3, _0802ECCC @ =0x00000842
	adds r1, r5, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0802ECD0
	adds r0, r5, #0
	bl FUN_08028648
	adds r0, r5, #0
	bl FUN_080286d8
	b _0802ECD8
	.align 2, 0
_0802ECC8: .4byte 0x000008E4
_0802ECCC: .4byte 0x00000842
_0802ECD0:
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802ECD8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802ece0
FUN_0802ece0: @ 0x0802ECE0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov r8, r1
	adds r7, r4, #0
	movs r0, #0x48
	adds r0, r0, r4
	mov sb, r0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802EDD6
	movs r0, #0
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x50
	ldr r1, _0802ED98 @ =0x0000085C
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, sb
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	ldr r5, _0802ED9C @ =0x00000854
	adds r2, r4, r5
	str r0, [r2]
	str r1, [r2, #4]
	ldr r6, _0802EDA0 @ =0x00000899
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	mov r6, sb
	movs r5, #8
	ldrsh r1, [r6, r5]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r2, r4, #0
	adds r2, #0xa1
	strb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	adds r5, r2, #0
	cmp r0, #0
	beq _0802EDA8
	ldr r6, _0802EDA4 @ =0x00000824
	adds r0, r4, r6
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802EDB8
	movs r3, #0
	b _0802EDB8
	.align 2, 0
_0802ED98: .4byte 0x0000085C
_0802ED9C: .4byte 0x00000854
_0802EDA0: .4byte 0x00000899
_0802EDA4: .4byte 0x00000824
_0802EDA8:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802EDB8
	movs r3, #5
_0802EDB8:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r6, #0xb5
	lsls r6, r6, #2
	adds r2, r7, r6
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
	b _0802EE62
_0802EDD6:
	ldr r0, _0802EE30 @ =0x00000899
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r2, r4, #0
	adds r2, #0xa1
	strb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	adds r5, r2, #0
	cmp r0, #0
	beq _0802EE38
	ldr r1, _0802EE34 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0802EE48
	movs r3, #0
	b _0802EE48
	.align 2, 0
_0802EE30: .4byte 0x00000899
_0802EE34: .4byte 0x00000824
_0802EE38:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0802EE48
	movs r3, #5
_0802EE48:
	movs r6, #0xbd
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
_0802EE62:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r6, #0xb3
	lsls r6, r6, #1
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _0802EEEC @ =0x00000167
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _0802EEF0 @ =0x0001000C
	adds r2, r4, #0
	adds r2, #0x98
	ldr r1, [r2]
	orrs r1, r0
	str r1, [r2]
	mov r6, r8
	cmp r6, #1
	bgt _0802EE94
	movs r0, #0x10
	orrs r1, r0
	str r1, [r2]
_0802EE94:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802EF56
	mov r2, r8
	cmp r2, #8
	bgt _0802EF48
	ldrb r0, [r5]
	adds r0, #5
	lsls r0, r0, #0x1d
	lsrs r2, r0, #0x18
	movs r0, #1
	mov r5, r8
	ands r0, r5
	adds r3, r2, #0
	adds r3, #0x60
	cmp r0, #0
	beq _0802EEC6
	subs r3, #0xc0
_0802EEC6:
	movs r0, #8
	mov r6, r8
	subs r0, r0, r6
	add r5, sp, #0xc
	lsls r6, r0, #4
	ldr r2, _0802EEF4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802EEF8
	asrs r1, r0, #0xc
	b _0802EEFE
	.align 2, 0
_0802EEEC: .4byte 0x00000167
_0802EEF0: .4byte 0x0001000C
_0802EEF4: .4byte 0x085B0A08
_0802EEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802EEFE:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802EF1A
	asrs r0, r0, #0xc
	b _0802EF20
_0802EF1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802EF20:
	strh r0, [r5, #4]
	mov r3, sb
	adds r3, #8
	ldr r5, _0802EF64 @ =0x00000854
	adds r1, r7, r5
	add r2, sp, #0xc
	adds r0, r2, #0
	ldrh r0, [r0]
	ldrh r6, [r1]
	adds r0, r0, r6
	mov r5, sb
	strh r0, [r5, #8]
	ldrh r0, [r2, #2]
	ldrh r6, [r1, #2]
	adds r0, r0, r6
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
_0802EF48:
	mov r0, r8
	cmp r0, #0xf
	ble _0802EF56
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802EF56:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EF64: .4byte 0x00000854

	thumb_func_start FUN_0802ef68
FUN_0802ef68: @ 0x0802EF68
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r4, #0
	adds r6, r4, #0
	adds r6, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802EFD0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EFA0
	ldr r1, _0802EF9C @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x29
	cmp r0, #0
	bne _0802EFB0
	movs r3, #0x25
	b _0802EFB0
	.align 2, 0
_0802EF9C: .4byte 0x00000824
_0802EFA0:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x25
	cmp r0, #0
	beq _0802EFB0
	movs r3, #0x29
_0802EFB0:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022c9c
	ldr r0, _0802F074 @ =0x0000034B
	bl PlaySound_0824078c
_0802EFD0:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802EFE4
	b _0802F128
_0802EFE4:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802EFFA
	b _0802F128
_0802EFFA:
	ldr r2, _0802F078 @ =0x00000864
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0802F0F2
	adds r0, r5, #0
	bl FUN_08028084
	movs r3, #0xbb
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802F0F2
	subs r0, #1
	strb r0, [r1]
	ldr r0, _0802F07C @ =0x00000868
	adds r1, r5, r0
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r1, r3]
	movs r3, #0xc
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	bls _0802F0F2
	ldr r3, _0802F080 @ =0x00000177
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F0A4
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r6, [r6, #5]
	movs r7, #0x18
	ldr r2, _0802F084 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802F088
	asrs r1, r0, #0xc
	b _0802F08E
	.align 2, 0
_0802F074: .4byte 0x0000034B
_0802F078: .4byte 0x00000864
_0802F07C: .4byte 0x00000868
_0802F080: .4byte 0x00000177
_0802F084: .4byte 0x085B0A08
_0802F088:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802F08E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	bge _0802F0E6
	b _0802F0EA
_0802F0A4:
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r6, [r6, #5]
	movs r7, #0xa
	ldr r2, _0802F0C8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802F0CC
	asrs r1, r0, #0xc
	b _0802F0D2
	.align 2, 0
_0802F0C8: .4byte 0x085B0A08
_0802F0CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802F0D2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802F0EA
_0802F0E6:
	asrs r0, r0, #0xc
	b _0802F0F0
_0802F0EA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802F0F0:
	strh r0, [r3, #4]
_0802F0F2:
	movs r3, #0xc2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0802F112
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0802F112:
	ldr r1, _0802F130 @ =0x00000311
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802F128
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802F128:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F130: .4byte 0x00000311

	thumb_func_start dainn_0802f134
dainn_0802f134: @ 0x0802F134
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r1
	adds r6, r4, #0
	adds r7, r4, #0
	adds r7, #0x48
	ldr r0, _0802F1B0 @ =0x00000899
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802F204
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F1B8
	ldr r1, _0802F1B4 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1f
	subs r1, #4
	adds r5, r4, r1
	cmp r0, #0
	bne _0802F1CA
	movs r3, #0x1a
	b _0802F1CA
	.align 2, 0
_0802F1B0: .4byte 0x00000899
_0802F1B4: .4byte 0x00000824
_0802F1B8:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r3, #0x1a
	adds r5, r0, #0
	cmp r1, #0
	beq _0802F1CA
	movs r3, #0x1f
_0802F1CA:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
	ldr r0, [r5]
	cmp r0, #0
	bne _0802F24E
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0802F24E
	ldr r0, _0802F200 @ =0x0000035D
	bl PlaySound_0824078c
	b _0802F24E
	.align 2, 0
_0802F200: .4byte 0x0000035D
_0802F204:
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F224
	ldr r1, _0802F220 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _0802F234
	movs r3, #0x1a
	b _0802F234
	.align 2, 0
_0802F220: .4byte 0x00000824
_0802F224:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _0802F234
	movs r3, #0x1f
_0802F234:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
_0802F24E:
	movs r2, #8
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F35C
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F35C
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0802F2F2
	mov r0, r8
	cmp r0, #0x1f
	bgt _0802F354
	movs r0, #0x20
	mov r1, r8
	subs r0, r0, r1
	asrs r0, r0, #2
	adds r3, r7, #0
	adds r3, #0x10
	ldrb r5, [r7, #5]
	rsbs r6, r0, #0
	ldr r2, _0802F2C0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F2C4
	asrs r1, r0, #0xc
	b _0802F2CA
	.align 2, 0
_0802F2C0: .4byte 0x085B0A08
_0802F2C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802F2CA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F2E2
	asrs r0, r0, #0xc
	b _0802F2E8
_0802F2E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802F2E8:
	strh r0, [r3, #4]
	mov r0, r8
	cmp r0, #0x1f
	ble _0802F35C
	b _0802F354
_0802F2F2:
	mov r1, r8
	cmp r1, #0x3f
	bgt _0802F354
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	adds r3, r7, #0
	adds r3, #0x10
	ldrb r5, [r7, #5]
	rsbs r6, r0, #0
	ldr r2, _0802F324 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F328
	asrs r1, r0, #0xc
	b _0802F32E
	.align 2, 0
_0802F324: .4byte 0x085B0A08
_0802F328:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802F32E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F346
	asrs r0, r0, #0xc
	b _0802F34C
_0802F346:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802F34C:
	strh r0, [r3, #4]
	mov r0, r8
	cmp r0, #0x3f
	ble _0802F35C
_0802F354:
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802F35C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802f368
FUN_0802f368: @ 0x0802F368
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r1
	adds r6, r4, #0
	adds r5, r4, #0
	adds r5, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802F3D8
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F3A8
	ldr r1, _0802F3A4 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x28
	cmp r0, #0
	bne _0802F3B8
	movs r3, #0x24
	b _0802F3B8
	.align 2, 0
_0802F3A4: .4byte 0x00000824
_0802F3A8:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x24
	cmp r0, #0
	beq _0802F3B8
	movs r3, #0x28
_0802F3B8:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022c9c
	ldr r0, _0802F430 @ =0x0000034A
	bl PlaySound_0824078c
_0802F3D8:
	movs r2, #8
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F49C
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F49C
	adds r3, r5, #0
	adds r3, #0x10
	ldrb r5, [r5, #5]
	movs r7, #0x28
	ldr r2, _0802F434 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802F438
	asrs r1, r0, #0xc
	b _0802F43E
	.align 2, 0
_0802F430: .4byte 0x0000034A
_0802F434: .4byte 0x085B0A08
_0802F438:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802F43E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802F456
	asrs r0, r0, #0xc
	b _0802F45C
_0802F456:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802F45C:
	strh r0, [r3, #4]
	ldr r1, _0802F480 @ =0x000008E4
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802F48E
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802F484
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
	b _0802F48E
	.align 2, 0
_0802F480: .4byte 0x000008E4
_0802F484:
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08028838
_0802F48E:
	mov r0, r8
	cmp r0, #0x9f
	ble _0802F49C
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802F49C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0802f4a8
FUN_0802f4a8: @ 0x0802F4A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r4, #0
	movs r0, #0x48
	adds r0, r0, r4
	mov r8, r0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802F518
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F4E8
	ldr r1, _0802F4E4 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x29
	cmp r0, #0
	bne _0802F4F8
	movs r3, #0x25
	b _0802F4F8
	.align 2, 0
_0802F4E4: .4byte 0x00000824
_0802F4E8:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x25
	cmp r0, #0
	beq _0802F4F8
	movs r3, #0x29
_0802F4F8:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022c9c
	ldr r0, _0802F594 @ =0x0000034B
	bl PlaySound_0824078c
_0802F518:
	movs r1, #8
	adds r5, r4, #0
	adds r5, #0x98
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F5D8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F5D8
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0802F566
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0802F566:
	cmp r6, #9
	bgt _0802F5C2
	movs r0, #0xa
	subs r0, r0, r6
	mov r3, r8
	adds r3, #0x10
	mov r1, r8
	ldrb r5, [r1, #5]
	lsls r6, r0, #2
	ldr r2, _0802F598 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F59C
	asrs r1, r0, #0xc
	b _0802F5A2
	.align 2, 0
_0802F594: .4byte 0x0000034B
_0802F598: .4byte 0x085B0A08
_0802F59C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802F5A2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F5BA
	asrs r0, r0, #0xc
	b _0802F5C0
_0802F5BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802F5C0:
	strh r0, [r3, #4]
_0802F5C2:
	ldr r1, _0802F5E4 @ =0x00000311
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802F5D8
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802F5D8:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F5E4: .4byte 0x00000311

	thumb_func_start FUN_0802f5e8
FUN_0802f5e8: @ 0x0802F5E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov r8, r0
	mov r5, r8
	mov r1, r8
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	bne _0802F604
	b _0802F894
_0802F604:
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0xb5
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	movs r3, #0x2c
	bl FUN_08022c34
	mov sl, r8
	movs r0, #0xbd
	lsls r0, r0, #2
	add r0, r8
	str r0, [sp, #0x24]
	movs r6, #0xa4
	lsls r6, r6, #4
	add r6, r8
	mov r0, r8
	bl FUN_08028ec8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #0xa2
	lsls r1, r1, #4
	add r1, r8
	str r4, [sp]
	adds r0, r6, #0
	movs r3, #1
	bl FUN_082370cc
	mov r0, r8
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802F660
	ldr r0, [r6, #8]
	orrs r0, r4
	b _0802F668
_0802F660:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0802F668:
	str r0, [r6, #8]
	ldr r1, _0802F6C0 @ =0x00000173
	adds r4, r5, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sl
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _0802F6C4 @ =0x00000A18
	adds r2, r5, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, [sp, #0x24]
	ldr r0, [r2, #0x20]
	ldr r1, [r2, #0x24]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r7, r6, #0
	adds r7, #0x20
	add r3, sp, #0x14
	mov ip, r3
	add r0, sp, #0x14
	ldrh r0, [r0]
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
	mov sb, r4
	cmp r0, #0
	blt _0802F6C8
	asrs r0, r0, #8
	b _0802F6CE
	.align 2, 0
_0802F6C0: .4byte 0x00000173
_0802F6C4: .4byte 0x00000A18
_0802F6C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802F6CE:
	strh r0, [r7]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0802F6E0
	asrs r0, r0, #8
	b _0802F6E6
_0802F6E0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802F6E6:
	adds r4, r0, #0
	mov r2, ip
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0802F6FC
	asrs r0, r0, #8
	b _0802F702
_0802F6FC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0802F702:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0802F744 @ =0x030047C8
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
	mov r0, sl
	adds r0, #0xaf
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _0802F74C
	ldr r0, _0802F748 @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r6, #0x20]
	adds r1, r1, r2
	strh r1, [r6, #0x20]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r6, #0x22]
	adds r0, r0, r1
	b _0802F760
	.align 2, 0
_0802F744: .4byte 0x030047C8
_0802F748: .4byte 0x085AABBC
_0802F74C:
	ldr r2, _0802F790 @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrh r0, [r6, #0x20]
	subs r0, r0, r1
	strh r0, [r6, #0x20]
	movs r0, #1
	ldrsb r0, [r2, r0]
	ldrh r2, [r6, #0x22]
	adds r0, r0, r2
_0802F760:
	strh r0, [r6, #0x22]
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r0, _0802F794 @ =0x00000A14
	adds r1, r5, r0
	ldr r0, _0802F798 @ =0x0000FFFF
	strh r0, [r1]
	ldr r2, [sp, #0x24]
	ldrh r1, [r2, #0x14]
	ldr r2, _0802F79C @ =0x00000A16
	adds r0, r5, r2
	strh r1, [r0]
	ldrb r0, [r3]
	cmp r0, #0
	bne _0802F7A4
	ldr r3, _0802F7A0 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	movs r1, #0x20
	b _0802F7AC
	.align 2, 0
_0802F790: .4byte 0x085AABBC
_0802F794: .4byte 0x00000A14
_0802F798: .4byte 0x0000FFFF
_0802F79C: .4byte 0x00000A16
_0802F7A0: .4byte 0xFFFF0000
_0802F7A4:
	ldr r3, _0802F824 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	ldr r1, _0802F828 @ =0x0000FFE0
_0802F7AC:
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r2, sp, #0x1c
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r1, _0802F82C @ =0x0000FFFF
	ldr r0, [sp, #0x1c]
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	adds r4, r2, #0
	mov r0, sl
	adds r0, #0xab
	ldrb r3, [r0]
	cmp r3, #0
	bne _0802F7FC
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _0802F830 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp, #0x24]
	adds r1, #0x20
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	adds r2, r4, #0
	movs r3, #0
	bl FUN_0807ab64
_0802F7FC:
	movs r0, #0x84
	lsls r0, r0, #7
	strh r0, [r6, #0x3a]
	mov r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	ldr r1, _0802F830 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r3, _0802F834 @ =0x00000359
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802F838
	adds r0, r1, #0
	adds r0, #0xd0
	ldr r0, [r0]
	b _0802F842
	.align 2, 0
_0802F824: .4byte 0xFFFF0000
_0802F828: .4byte 0x0000FFE0
_0802F82C: .4byte 0x0000FFFF
_0802F830: .4byte 0x03002BE0
_0802F834: .4byte 0x00000359
_0802F838:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
_0802F842:
	str r0, [r6, #0x48]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0802F8F4 @ =0x00000874
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	adds r3, #0x17
	adds r1, r5, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0802F886
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r3, _0802F8F8 @ =0x00000876
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
_0802F886:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _0802F8FC @ =0x0000016D
	adds r0, r5, r3
	strb r2, [r0]
_0802F894:
	mov r0, r8
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802F90C
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r2, _0802F900 @ =0x00000173
	adds r2, r2, r5
	mov sb, r2
	cmp r4, #0
	bne _0802F8EC
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _0802F8EC
	ldr r1, _0802F904 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, _0802F908 @ =0x00000A18
	adds r1, r5, r3
	adds r2, r5, #0
	adds r2, #0x4d
	ldrb r3, [r2]
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_0802F8EC:
	movs r0, #0xff
	mov r1, sb
	b _0802FA88
	.align 2, 0
_0802F8F4: .4byte 0x00000874
_0802F8F8: .4byte 0x00000876
_0802F8FC: .4byte 0x0000016D
_0802F900: .4byte 0x00000173
_0802F904: .4byte 0x03002BE0
_0802F908: .4byte 0x00000A18
_0802F90C:
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, r8
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0802F97C
	movs r2, #0xa4
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r3, _0802F970 @ =0x00000173
	adds r3, r3, r5
	mov sb, r3
	cmp r4, #0
	bne _0802F968
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _0802F968
	ldr r1, _0802F974 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _0802F978 @ =0x00000A18
	adds r1, r5, r2
	adds r2, r5, #0
	adds r2, #0x4d
	ldrb r3, [r2]
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_0802F968:
	movs r0, #0xff
	mov r3, sb
	strb r0, [r3]
	b _0802FA8A
	.align 2, 0
_0802F970: .4byte 0x00000173
_0802F974: .4byte 0x03002BE0
_0802F978: .4byte 0x00000A18
_0802F97C:
	ldr r0, _0802FA9C @ =0x00000173
	adds r0, r0, r5
	mov sb, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	movs r7, #0x82
	lsls r7, r7, #1
	add r7, r8
	adds r0, r7, r0
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrb r2, [r0]
	ldr r0, _0802FAA0 @ =0x00000877
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, r2
	beq _0802F9B2
	strb r2, [r1]
	ldr r2, _0802FAA4 @ =0x0000016D
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802F9B2:
	ldr r0, _0802FAA4 @ =0x0000016D
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #3
	bls _0802F9E0
	adds r0, r3, #0
	bl FUN_0807849c
	lsls r0, r0, #0x1d
	movs r1, #0xa0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0x10
	strb r0, [r1]
	strb r6, [r4]
_0802F9E0:
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r0, [r0]
	ldr r2, _0802FAA8 @ =0x00000876
	adds r1, r5, r2
	ldrb r1, [r1]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r0, [r0]
	ldr r2, _0802FAAC @ =0xFFFFFF00
	adds r1, r1, r2
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0xf
	ble _0802FA0E
	ldr r3, _0802FAB0 @ =0x00000874
	adds r0, r5, r3
	strh r6, [r0]
_0802FA0E:
	ldr r1, _0802FAB4 @ =0x00000311
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802FA50
	movs r1, #4
	ldr r0, _0802FAB8 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0802FA50
	ldr r2, _0802FAB0 @ =0x00000874
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	ble _0802FA50
	movs r0, #0xae
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #3
	bhi _0802FA50
	movs r3, #0xc2
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_0802FA50:
	ldr r1, _0802FAB4 @ =0x00000311
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802FA8A
	movs r1, #4
	ldr r0, _0802FAB8 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0802FA82
	ldr r2, _0802FAB0 @ =0x00000874
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _0802FA82
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802FA8A
_0802FA82:
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
_0802FA88:
	strb r0, [r1]
_0802FA8A:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802FA9C: .4byte 0x00000173
_0802FAA0: .4byte 0x00000877
_0802FAA4: .4byte 0x0000016D
_0802FAA8: .4byte 0x00000876
_0802FAAC: .4byte 0xFFFFFF00
_0802FAB0: .4byte 0x00000874
_0802FAB4: .4byte 0x00000311
_0802FAB8: .4byte 0x03002BC0

	thumb_func_start FUN_0802fabc
FUN_0802fabc: @ 0x0802FABC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r1
	adds r7, r4, #0
	adds r5, r4, #0
	adds r5, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802FB40
	movs r0, #0
	strb r0, [r1]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	ands r0, r1
	lsrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802FB14
	ldr r1, _0802FB10 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _0802FB24
	movs r3, #0x1a
	b _0802FB24
	.align 2, 0
_0802FB10: .4byte 0x00000824
_0802FB14:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _0802FB24
	movs r3, #0x1f
_0802FB24:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
_0802FB40:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802FBFC
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802FBFC
	mov r0, r8
	cmp r0, #0x13
	bgt _0802FBBE
	movs r0, #0x14
	adds r3, r5, #0
	adds r3, #0x10
	ldrb r5, [r5, #5]
	mov r1, r8
	subs r6, r0, r1
	ldr r2, _0802FB94 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802FB98
	asrs r1, r0, #0xc
	b _0802FB9E
	.align 2, 0
_0802FB94: .4byte 0x085B0A08
_0802FB98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802FB9E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802FBB6
	asrs r0, r0, #0xc
	b _0802FBBC
_0802FBB6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802FBBC:
	strh r0, [r3, #4]
_0802FBBE:
	ldr r1, _0802FBE0 @ =0x000008E4
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _0802FBEE
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802FBE4
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
	b _0802FBEE
	.align 2, 0
_0802FBE0: .4byte 0x000008E4
_0802FBE4:
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08028838
_0802FBEE:
	mov r0, r8
	cmp r0, #0x3b
	ble _0802FBFC
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802FBFC:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start dainn_0802fc08
dainn_0802fc08: @ 0x0802FC08
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	adds r4, r5, #0
	adds r6, r5, #0
	adds r6, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802FC74
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802FC48
	ldr r1, _0802FC44 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x46
	cmp r0, #0
	bne _0802FC58
	movs r3, #0x44
	b _0802FC58
	.align 2, 0
_0802FC44: .4byte 0x00000824
_0802FC48:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x44
	cmp r0, #0
	beq _0802FC58
	movs r3, #0x46
_0802FC58:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022c9c
_0802FC74:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802FC88
	b _0802FE8A
_0802FC88:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802FC9E
	b _0802FE8A
_0802FC9E:
	ldr r2, _0802FD18 @ =0x00000864
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0802FD92
	adds r0, r4, #0
	bl FUN_08028084
	movs r3, #0xbb
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802FD92
	subs r0, #1
	strb r0, [r1]
	ldr r0, _0802FD1C @ =0x00000868
	adds r1, r4, r0
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r1, r3]
	movs r3, #0xc
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	bls _0802FD92
	ldr r3, _0802FD20 @ =0x00000177
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802FD44
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r6, [r6, #5]
	movs r7, #0x18
	ldr r2, _0802FD24 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802FD28
	asrs r1, r0, #0xc
	b _0802FD2E
	.align 2, 0
_0802FD18: .4byte 0x00000864
_0802FD1C: .4byte 0x00000868
_0802FD20: .4byte 0x00000177
_0802FD24: .4byte 0x085B0A08
_0802FD28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802FD2E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	bge _0802FD86
	b _0802FD8A
_0802FD44:
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r6, [r6, #5]
	movs r7, #0xa
	ldr r2, _0802FD68 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802FD6C
	asrs r1, r0, #0xc
	b _0802FD72
	.align 2, 0
_0802FD68: .4byte 0x085B0A08
_0802FD6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802FD72:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0802FD8A
_0802FD86:
	asrs r0, r0, #0xc
	b _0802FD90
_0802FD8A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802FD90:
	strh r0, [r3, #4]
_0802FD92:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0802FDA6
	subs r0, r2, #4
	b _0802FDA8
_0802FDA6:
	movs r0, #0
_0802FDA8:
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0802FDBE
	subs r0, r2, #4
	b _0802FDC0
_0802FDBE:
	movs r0, #0
_0802FDC0:
	strh r0, [r1]
	movs r0, #0xc2
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0xb
	bls _0802FDD8
	cmp r0, #0xd
	bne _0802FE16
	mov r1, r8
	cmp r1, #0x13
	bgt _0802FE16
_0802FDD8:
	movs r2, #1
	cmp r0, #5
	bhi _0802FDE0
	movs r2, #7
_0802FDE0:
	adds r1, r2, #0
	mov r0, r8
	ands r1, r0
	cmp r1, #0
	bne _0802FDFE
	ldrh r2, [r3]
	adds r0, r5, #0
	adds r0, #0xa0
	ldrb r3, [r0]
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0802a008
	b _0802FE16
_0802FDFE:
	cmp r1, r2
	bne _0802FE16
	ldrh r2, [r3]
	adds r0, r5, #0
	adds r0, #0xa0
	ldrb r3, [r0]
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0802a008
_0802FE16:
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #8
	bne _0802FE54
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0802FE54
	adds r0, r4, #0
	bl FUN_08028f08
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _0802FE4C
	ldr r0, _0802FE48 @ =0x0000030B
	bl PlaySound_0824078c
	b _0802FE54
	.align 2, 0
_0802FE48: .4byte 0x0000030B
_0802FE4C:
	movs r0, #0xd7
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0802FE54:
	ldr r1, _0802FE98 @ =0x00000311
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0802FE74
	movs r2, #0xc2
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0xc
	bne _0802FE74
	ldr r0, _0802FE9C @ =0x0000034E
	bl PlaySound_0824078c
_0802FE74:
	ldr r3, _0802FE98 @ =0x00000311
	adds r0, r4, r3
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802FE8A
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802FE8A:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802FE98: .4byte 0x00000311
_0802FE9C: .4byte 0x0000034E

	thumb_func_start dainn_0802fea0
dainn_0802fea0: @ 0x0802FEA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	adds r4, r5, #0
	adds r6, r5, #0
	adds r6, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802FF0E
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802FEE0
	ldr r1, _0802FEDC @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x46
	cmp r0, #0
	bne _0802FEF0
	movs r3, #0x44
	b _0802FEF0
	.align 2, 0
_0802FEDC: .4byte 0x00000824
_0802FEE0:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x44
	cmp r0, #0
	beq _0802FEF0
	movs r3, #0x46
_0802FEF0:
	movs r7, #0xbd
	lsls r7, r7, #2
	adds r1, r4, r7
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022c9c
_0802FF0E:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802FF22
	b _08030132
_0802FF22:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0802FF3A
	b _08030132
_0802FF3A:
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r2, [r1]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #3
	ble _0802FF50
	subs r0, r2, #4
	strh r0, [r1]
	b _0802FF52
_0802FF50:
	strh r3, [r1]
_0802FF52:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0802FF66
	subs r0, r2, #4
	b _0802FF68
_0802FF66:
	movs r0, #0
_0802FF68:
	strh r0, [r1]
	movs r7, #0xc2
	lsls r7, r7, #2
	adds r3, r4, r7
	ldrh r0, [r3]
	cmp r0, #0xb
	bls _0802FF80
	cmp r0, #0xd
	bne _0802FFBE
	mov r1, r8
	cmp r1, #0x13
	bgt _0802FFBE
_0802FF80:
	movs r2, #1
	cmp r0, #5
	bhi _0802FF88
	movs r2, #7
_0802FF88:
	adds r1, r2, #0
	mov r7, r8
	ands r1, r7
	cmp r1, #0
	bne _0802FFA6
	ldrh r2, [r3]
	adds r0, r5, #0
	adds r0, #0xa0
	ldrb r3, [r0]
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0802a008
	b _0802FFBE
_0802FFA6:
	cmp r1, r2
	bne _0802FFBE
	ldrh r2, [r3]
	adds r0, r5, #0
	adds r0, #0xa0
	ldrb r3, [r0]
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0802a008
_0802FFBE:
	ldr r1, _08030038 @ =0x00000864
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080300B2
	adds r0, r4, #0
	bl FUN_08028084
	movs r2, #0xbb
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080300B2
	subs r0, #1
	strb r0, [r1]
	ldr r3, _0803003C @ =0x00000868
	adds r1, r4, r3
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	movs r3, #0xc
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r1, r0
	bls _080300B2
	ldr r1, _08030040 @ =0x00000177
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08030064
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r6, [r6, #5]
	movs r7, #0x18
	ldr r2, _08030044 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08030048
	asrs r1, r0, #0xc
	b _0803004E
	.align 2, 0
_08030038: .4byte 0x00000864
_0803003C: .4byte 0x00000868
_08030040: .4byte 0x00000177
_08030044: .4byte 0x085B0A08
_08030048:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803004E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	bge _080300A6
	b _080300AA
_08030064:
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r6, [r6, #5]
	movs r7, #0xa
	ldr r2, _08030088 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0803008C
	asrs r1, r0, #0xc
	b _08030092
	.align 2, 0
_08030088: .4byte 0x085B0A08
_0803008C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08030092:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080300AA
_080300A6:
	asrs r0, r0, #0xc
	b _080300B0
_080300AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080300B0:
	strh r0, [r3, #4]
_080300B2:
	movs r3, #0xc2
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #8
	bne _080300FC
	movs r7, #0xc0
	lsls r7, r7, #2
	adds r0, r4, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _080300FC
	ldr r1, _080300EC @ =0x00000892
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08029164
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080300F4
	ldr r0, _080300F0 @ =0x0000030B
	bl PlaySound_0824078c
	b _080300FC
	.align 2, 0
_080300EC: .4byte 0x00000892
_080300F0: .4byte 0x0000030B
_080300F4:
	movs r0, #0xd7
	lsls r0, r0, #2
	bl PlaySound_0824078c
_080300FC:
	ldr r3, _08030140 @ =0x00000311
	adds r0, r4, r3
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0803011C
	movs r7, #0xc2
	lsls r7, r7, #2
	adds r0, r4, r7
	ldrh r0, [r0]
	cmp r0, #0xc
	bne _0803011C
	ldr r0, _08030144 @ =0x0000034E
	bl PlaySound_0824078c
_0803011C:
	ldr r1, _08030140 @ =0x00000311
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08030132
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08030132:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030140: .4byte 0x00000311
_08030144: .4byte 0x0000034E

	thumb_func_start FUN_08030148
FUN_08030148: @ 0x08030148
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov r8, r6
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803020A
	movs r4, #0
	strb r4, [r1]
	ldr r0, _0803024C @ =0x00000899
	adds r5, r6, r0
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r5]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0x3a
	bl FUN_08022c9c
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r6, r3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _08030250 @ =0x00000844
	adds r2, r6, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	bl FUN_08028604
	ldr r0, _08030254 @ =0x0000084C
	adds r1, r6, r0
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrh r2, [r4]
	adds r0, r6, #0
	bl FUN_0802853c
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_08029a1c
_0803020A:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803021E
	b _080304B0
_0803021E:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08030236
	b _080304B0
_08030236:
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #3
	ble _08030258
	subs r0, r2, #4
	strh r0, [r1]
	b _0803025A
	.align 2, 0
_0803024C: .4byte 0x00000899
_08030250: .4byte 0x00000844
_08030254: .4byte 0x0000084C
_08030258:
	strh r3, [r1]
_0803025A:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0803026E
	subs r0, r2, #4
	b _08030270
_0803026E:
	movs r0, #0
_08030270:
	strh r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r7, r6, r4
	ldrh r5, [r7]
	cmp r5, #1
	beq _08030342
	cmp r5, #1
	bgt _08030288
	cmp r5, #0
	beq _08030296
	b _08030484
_08030288:
	cmp r5, #2
	bne _0803028E
	b _080303F8
_0803028E:
	cmp r5, #3
	bne _08030294
	b _08030468
_08030294:
	b _08030484
_08030296:
	ldr r0, _0803032C @ =0x00000899
	adds r1, r6, r0
	mov r0, r8
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r3, r8
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	mov r0, r8
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, r8
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r2, _08030330 @ =0x00000842
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08030338
	adds r0, r6, #0
	bl FUN_08028648
	adds r0, r6, #0
	bl FUN_080286d8
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x3a
	bl FUN_08022c9c
	ldr r1, _08030334 @ =0x000008E4
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bhi _0803031E
	b _08030484
_0803031E:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
	b _08030484
	.align 2, 0
_0803032C: .4byte 0x00000899
_08030330: .4byte 0x00000842
_08030334: .4byte 0x000008E4
_08030338:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	b _0803047E
_08030342:
	ldr r3, _080303D0 @ =0x00000899
	adds r1, r6, r3
	mov r0, r8
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r3, r8
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	mov r0, r8
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, r8
	adds r0, #0xa1
	strb r1, [r0]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r4, r6, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080303D8
	adds r0, r6, #0
	adds r0, #0x48
	ldrb r0, [r0, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
	ldr r2, _080303D4 @ =0x000008DA
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x3b
	bl FUN_08022c9c
	movs r0, #0
	strh r0, [r4]
	b _0803047E
	.align 2, 0
_080303D0: .4byte 0x00000899
_080303D4: .4byte 0x000008DA
_080303D8:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	str r5, [sp, #8]
	mov r0, r8
	movs r3, #0x3a
	bl FUN_08022c9c
	b _08030484
_080303F8:
	ldr r4, _08030440 @ =0x00000311
	adds r0, r6, r4
	ldrb r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08030484
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08030444 @ =0x0000017B
	adds r1, r6, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1]
	cmp r0, r1
	blo _08030448
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	subs r4, #0x3d
	adds r2, r6, r4
	str r5, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x3c
	bl FUN_08022c9c
	b _0803047E
	.align 2, 0
_08030440: .4byte 0x00000311
_08030444: .4byte 0x0000017B
_08030448:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r6, r3
	str r5, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, r8
	movs r3, #0x3b
	bl FUN_08022c9c
	b _08030484
_08030468:
	ldr r4, _080304BC @ =0x00000311
	adds r0, r6, r4
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08030484
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803047E:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_08030484:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080304B0
	movs r2, #0xc2
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _080304B0
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _080304B0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080292c8
_080304B0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080304BC: .4byte 0x00000311

	thumb_func_start FUN_080304c0
FUN_080304c0: @ 0x080304C0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08030546
	movs r4, #0
	strb r4, [r1]
	adds r3, r5, #0
	adds r3, #0xa0
	ldrb r0, [r3]
	lsls r0, r0, #0x1e
	movs r1, #0xc0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #0x4d
	adds r1, r1, r5
	mov ip, r1
	strb r0, [r1]
	ldrb r0, [r1]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r3]
	mov r3, ip
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x3a
	bl FUN_08022c9c
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
_08030546:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803055A
	b _08030678
_0803055A:
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08030572
	b _08030678
_08030572:
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #3
	ble _08030588
	subs r0, r2, #4
	strh r0, [r1]
	b _0803058A
_08030588:
	strh r3, [r1]
_0803058A:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0803059E
	subs r0, r2, #4
	b _080305A0
_0803059E:
	movs r0, #0
_080305A0:
	strh r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #1
	bne _080305CE
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _080305CE
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _080305CE
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080292c8
_080305CE:
	ldr r4, _080305F4 @ =0x00000311
	adds r0, r6, r4
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08030678
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	cmp r0, #1
	beq _0803061A
	cmp r0, #1
	bgt _080305F8
	cmp r0, #0
	beq _080305FE
	b _08030678
	.align 2, 0
_080305F4: .4byte 0x00000311
_080305F8:
	cmp r0, #2
	beq _08030670
	b _08030678
_080305FE:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x3b
	b _08030640
_0803061A:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #5
	bne _0803064C
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x3c
_08030640:
	bl FUN_08022c9c
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	b _08030678
_0803064C:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x3b
	bl FUN_08022c9c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _08030678
_08030670:
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08030678:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08030680
FUN_08030680: @ 0x08030680
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r7, r6, #0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803073E
	movs r4, #0
	strb r4, [r1]
	ldr r0, _08030780 @ =0x00000899
	adds r5, r6, r0
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r5]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0x3a
	bl FUN_08022c9c
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r6, r3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _08030784 @ =0x00000844
	adds r2, r6, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	bl FUN_08028604
	ldr r0, _08030788 @ =0x0000084C
	adds r1, r6, r0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_0802853c
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_08029a1c
_0803073E:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08030752
	b _08030952
_08030752:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0803076A
	b _08030952
_0803076A:
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #3
	ble _0803078C
	subs r0, r2, #4
	strh r0, [r1]
	b _0803078E
	.align 2, 0
_08030780: .4byte 0x00000899
_08030784: .4byte 0x00000844
_08030788: .4byte 0x0000084C
_0803078C:
	strh r3, [r1]
_0803078E:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _080307A2
	subs r0, r2, #4
	b _080307A4
_080307A2:
	movs r0, #0
_080307A4:
	strh r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r5, r6, r4
	ldrh r1, [r5]
	cmp r1, #1
	beq _080308A4
	cmp r1, #1
	bgt _080307BC
	cmp r1, #0
	beq _080307C4
	b _08030926
_080307BC:
	cmp r1, #2
	bne _080307C2
	b _0803090E
_080307C2:
	b _08030926
_080307C4:
	ldr r0, _08030858 @ =0x00000899
	adds r1, r6, r0
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r7, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r2, _0803085C @ =0x00000842
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08030864
	adds r0, r6, #0
	bl FUN_08028648
	adds r0, r6, #0
	bl FUN_080286d8
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x3a
	bl FUN_08022c9c
	ldr r1, _08030860 @ =0x000008E4
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _08030926
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
	b _08030926
	.align 2, 0
_08030858: .4byte 0x00000899
_0803085C: .4byte 0x00000842
_08030860: .4byte 0x000008E4
_08030864:
	adds r0, r6, #0
	adds r0, #0x48
	ldrb r0, [r0, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
	ldr r2, _080308A0 @ =0x000008DA
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x3b
	bl FUN_08022c9c
	ldrh r0, [r5]
	adds r0, #1
	b _08030924
	.align 2, 0
_080308A0: .4byte 0x000008DA
_080308A4:
	ldr r1, _080308E4 @ =0x00000311
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08030926
	movs r2, #0xae
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080308E8
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x3c
	bl FUN_08022c9c
	ldrh r0, [r5]
	adds r0, #1
	b _08030924
	.align 2, 0
_080308E4: .4byte 0x00000311
_080308E8:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x3b
	bl FUN_08022c9c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _08030926
_0803090E:
	ldr r2, _0803095C @ =0x00000311
	adds r0, r6, r2
	ldrb r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _08030926
	adds r0, r7, #0
	adds r0, #0xa7
	movs r1, #1
	strb r1, [r0]
	movs r0, #3
_08030924:
	strh r0, [r5]
_08030926:
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #1
	bne _08030952
	movs r4, #0xc2
	lsls r4, r4, #2
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #1
	bne _08030952
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08030952
	adds r0, r6, #0
	movs r1, #2
	bl FUN_080292c8
_08030952:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803095C: .4byte 0x00000311

	thumb_func_start dainn_08030960
dainn_08030960: @ 0x08030960
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r7, r5, #0
	adds r7, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08030A52
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080309E8 @ =0x00000868
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_08084734
	adds r2, r5, #0
	adds r2, #0x50
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r3, #8
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r4, #4
	ldrsh r2, [r2, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _080309F0
	ldr r1, _080309EC @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _08030A00
	movs r3, #0x1a
	b _08030A00
	.align 2, 0
_080309E8: .4byte 0x00000868
_080309EC: .4byte 0x00000824
_080309F0:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _08030A00
	movs r3, #0x1f
_08030A00:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022d24
	ldr r1, _08030A3C @ =0x0000087E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08030A52
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _08030A44
	ldr r0, _08030A40 @ =0x00000313
	bl PlaySound_082406e0
	b _08030A4A
	.align 2, 0
_08030A3C: .4byte 0x0000087E
_08030A40: .4byte 0x00000313
_08030A44:
	ldr r0, _08030AC0 @ =0x0000033D
	bl PlaySound_082406e0
_08030A4A:
	ldr r3, _08030AC4 @ =0x0000087E
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
_08030A52:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08030A66
	b _08030B78
_08030A66:
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08030A7C
	b _08030B78
_08030A7C:
	adds r0, r6, #0
	bl FUN_08028084
	ldr r0, _08030AC8 @ =0x00000868
	adds r3, r6, r0
	movs r1, #0
	ldrsh r2, [r3, r1]
	movs r4, #8
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r3, r1]
	movs r4, #0xc
	ldrsh r1, [r7, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	adds r2, r1, #0
	ldr r0, _08030ACC @ =0x000023FF
	cmp r1, r0
	bhi _08030AD0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #8]
	str r1, [r7, #0xc]
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08030B78
	.align 2, 0
_08030AC0: .4byte 0x0000033D
_08030AC4: .4byte 0x0000087E
_08030AC8: .4byte 0x00000868
_08030ACC: .4byte 0x000023FF
_08030AD0:
	ldr r0, _08030AFC @ =0x00003FFF
	cmp r1, r0
	bhi _08030B20
	adds r3, r7, #0
	adds r3, #0x10
	ldrb r4, [r7, #5]
	movs r5, #0xf
	ldr r2, _08030B00 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08030B04
	asrs r1, r0, #0xc
	b _08030B0A
	.align 2, 0
_08030AFC: .4byte 0x00003FFF
_08030B00: .4byte 0x085B0A08
_08030B04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08030B0A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	bge _08030B6C
	b _08030B70
_08030B20:
	movs r0, #0x80
	lsls r0, r0, #0xd
	cmp r2, r0
	bls _08030B78
	adds r3, r7, #0
	adds r3, #0x10
	ldrb r4, [r7, #5]
	ldr r2, _08030B4C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08030B50
	asrs r1, r0, #0xc
	b _08030B56
	.align 2, 0
_08030B4C: .4byte 0x085B0A08
_08030B50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08030B56:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _08030B70
_08030B6C:
	asrs r0, r0, #0xc
	b _08030B76
_08030B70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08030B76:
	strh r0, [r3, #4]
_08030B78:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08030b80
FUN_08030b80: @ 0x08030B80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	adds r7, r5, #0
	adds r6, r5, #0
	adds r6, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08030C44
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08030C10 @ =0x00000868
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_08084734
	adds r2, r5, #0
	adds r2, #0x50
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r3, #8
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r4, #4
	ldrsh r2, [r2, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _08030C18
	ldr r1, _08030C14 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _08030C28
	movs r3, #0x1a
	b _08030C28
	.align 2, 0
_08030C10: .4byte 0x00000868
_08030C14: .4byte 0x00000824
_08030C18:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _08030C28
	movs r3, #0x1f
_08030C28:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022d24
_08030C44:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08030C58
	b _08030D5E
_08030C58:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08030D5E
	ldr r2, _08030CA0 @ =0x00000868
	adds r3, r7, r2
	movs r4, #0
	ldrsh r2, [r3, r4]
	movs r1, #8
	ldrsh r0, [r6, r1]
	subs r2, r2, r0
	movs r4, #4
	ldrsh r0, [r3, r4]
	movs r4, #0xc
	ldrsh r1, [r6, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08030CA4 @ =0x000023FF
	cmp r1, r0
	bhi _08030CA8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	b _08030D56
	.align 2, 0
_08030CA0: .4byte 0x00000868
_08030CA4: .4byte 0x000023FF
_08030CA8:
	ldr r3, _08030CD4 @ =0x00000177
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08030CFA
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r4, [r6, #5]
	ldr r2, _08030CD8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08030CDC
	asrs r1, r0, #0xc
	b _08030CE2
	.align 2, 0
_08030CD4: .4byte 0x00000177
_08030CD8: .4byte 0x085B0A08
_08030CDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08030CE2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	bge _08030D3E
	b _08030D42
_08030CFA:
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r4, [r6, #5]
	movs r6, #0xc
	ldr r2, _08030D20 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08030D24
	asrs r1, r0, #0xc
	b _08030D2A
	.align 2, 0
_08030D20: .4byte 0x085B0A08
_08030D24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08030D2A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08030D42
_08030D3E:
	asrs r0, r0, #0xc
	b _08030D48
_08030D42:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08030D48:
	strh r0, [r3, #4]
	adds r0, r7, #0
	bl FUN_08028084
	mov r3, r8
	cmp r3, #9
	ble _08030D5E
_08030D56:
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08030D5E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start dainn_08030d6c
dainn_08030d6c: @ 0x08030D6C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r5
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08030E4E
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08030DAC
	ldr r1, _08030DA8 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x16
	movs r2, #0x82
	lsls r2, r2, #4
	adds r4, r5, r2
	cmp r0, #0
	bne _08030DBE
	movs r3, #0x12
	b _08030DBE
	.align 2, 0
_08030DA8: .4byte 0x00000824
_08030DAC:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r1, [r0]
	movs r3, #0x12
	adds r4, r0, #0
	cmp r1, #0
	beq _08030DBE
	movs r3, #0x16
_08030DBE:
	movs r7, #0xbd
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	bl FUN_08022da8
	movs r2, #0x87
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r0, [r4]
	cmp r0, #0
	beq _08030E00
	ldr r0, _08030DFC @ =0x00000313
	bl PlaySound_082406e0
	b _08030E06
	.align 2, 0
_08030DFC: .4byte 0x00000313
_08030E00:
	ldr r0, _08030E7C @ =0x0000033D
	bl PlaySound_082406e0
_08030E06:
	bl FUN_080846c8
	ldr r2, _08030E80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08030E84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r7, _08030E88 @ =0x0203B400
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x3c
	ldr r1, _08030E8C @ =0x0000016F
	adds r2, r5, r1
	movs r1, #0
	strb r0, [r2]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08030E90 @ =0x000008A2
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r0, r5, #0
	bl FUN_08028074
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r2, r5, r7
	ldr r0, _08030E94 @ =0xFFFFFEFF
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_08030E4E:
	mov r0, r8
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08030E98
	movs r1, #0x8a
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl FUN_08028074
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r2, #6]
	b _08030EC6
	.align 2, 0
_08030E7C: .4byte 0x0000033D
_08030E80: .4byte 0x030046B8
_08030E84: .4byte 0x000003FF
_08030E88: .4byte 0x0203B400
_08030E8C: .4byte 0x0000016F
_08030E90: .4byte 0x000008A2
_08030E94: .4byte 0xFFFFFEFF
_08030E98:
	movs r4, #0x80
	lsls r4, r4, #1
	mov r7, r8
	adds r0, r7, r4
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08030ECC
	movs r1, #0x8a
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl FUN_08028074
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2, #6]
	adds r0, r4, #0
_08030EC6:
	orrs r0, r1
	strh r0, [r2, #6]
	b _080310F6
_08030ECC:
	movs r1, #0x80
	lsls r1, r1, #0xa
	mov r6, r8
	adds r6, #0x98
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08030F32
	ldr r4, _08030FAC @ =0x0203B400
	ldr r3, _08030FB0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08030FB4 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	movs r7, #0xb7
	lsls r7, r7, #1
	strb r1, [r7, r5]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x1e
	ldr r2, _08030FB8 @ =0x0000016F
	adds r1, r5, r2
	strb r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08030F28
	adds r0, r5, #0
	bl FUN_08028b00
_08030F28:
	movs r7, #0xb4
	lsls r7, r7, #1
	adds r1, r5, r7
	movs r0, #0x3c
	strb r0, [r1]
_08030F32:
	ldr r0, _08030FB8 @ =0x0000016F
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _08030F3E
	b _08031080
_08030F3E:
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803103C
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r3, r5, r1
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r3]
	ldr r2, _08030FAC @ =0x0203B400
	mov ip, r2
	ldr r7, _08030FB0 @ =0x030046B8
	ldr r0, [r7]
	adds r2, r0, #1
	ldr r6, _08030FB4 @ =0x000003FF
	ands r2, r6
	str r2, [r7]
	lsls r0, r2, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0xb7
	lsls r1, r1, #1
	strb r0, [r1, r5]
	movs r1, #0x87
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bhi _08030FD2
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #8
	strb r1, [r0]
	ldrb r0, [r3]
	cmp r0, #3
	bne _08030FBC
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x3c
	strb r0, [r4]
	b _08031080
	.align 2, 0
_08030FAC: .4byte 0x0203B400
_08030FB0: .4byte 0x030046B8
_08030FB4: .4byte 0x000003FF
_08030FB8: .4byte 0x0000016F
_08030FBC:
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xa
	strb r0, [r4]
	b _08031080
_08030FD2:
	movs r0, #0xe1
	lsls r0, r0, #1
	cmp r1, r0
	bhi _08031000
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #8
	strb r1, [r0]
	ldrb r0, [r3]
	cmp r0, #3
	bne _08031026
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x1e
	strb r0, [r4]
	b _08031080
_08031000:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #6
	strb r1, [r0]
	ldrb r0, [r3]
	cmp r0, #3
	bne _08031026
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xf
	strb r0, [r4]
	b _08031080
_08031026:
	adds r0, r2, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r4]
	b _08031080
_0803103C:
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0803107C
	ldr r2, _08031070 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08031074 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08031078 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r7, #0xb7
	lsls r7, r7, #1
	adds r1, r5, r7
	strb r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #4
	b _0803107E
	.align 2, 0
_08031070: .4byte 0x030046B8
_08031074: .4byte 0x000003FF
_08031078: .4byte 0x0203B400
_0803107C:
	subs r0, #1
_0803107E:
	strb r0, [r1]
_08031080:
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08031094
	subs r0, r2, #4
	b _08031096
_08031094:
	movs r0, #0
_08031096:
	strh r0, [r1]
	movs r7, #0xb0
	lsls r7, r7, #1
	adds r1, r5, r7
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _080310AC
	subs r0, r2, #4
	b _080310AE
_080310AC:
	movs r0, #0
_080310AE:
	strh r0, [r1]
	ldr r7, _08031104 @ =0x00000311
	adds r0, r5, r7
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080310EA
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080310D4
	mov r0, r8
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #7
	ble _080310EA
_080310D4:
	movs r2, #0x87
	lsls r2, r2, #4
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r0, _08031108 @ =0x00000257
	cmp r1, r0
	bls _080310EA
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080310EA:
	movs r3, #0x87
	lsls r3, r3, #4
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080310F6:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031104: .4byte 0x00000311
_08031108: .4byte 0x00000257

	thumb_func_start dainn_0803110c
dainn_0803110c: @ 0x0803110C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803117E
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031144
	ldr r1, _08031140 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x17
	cmp r0, #0
	bne _08031154
	movs r3, #0x13
	b _08031154
	.align 2, 0
_08031140: .4byte 0x00000824
_08031144:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x13
	cmp r0, #0
	beq _08031154
	movs r3, #0x17
_08031154:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_08022da8
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_0803117E:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08031192
	b _0803140C
_08031192:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080311A8
	b _0803140C
_080311A8:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #1
	bhi _08031250
	ldr r0, _08031228 @ =0x0000016F
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031250
	subs r0, #1
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08031250
	ldr r6, _0803122C @ =0x030046B8
	ldr r0, [r6]
	adds r3, r0, #1
	ldr r7, _08031230 @ =0x000003FF
	ands r3, r7
	str r3, [r6]
	lsls r0, r3, #1
	ldr r2, _08031234 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	mov r8, r1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r2]
	cmp r0, #3
	bne _08031238
	adds r0, r3, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08031234 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #8
	mov r1, ip
	strb r0, [r1]
	b _08031250
	.align 2, 0
_08031228: .4byte 0x0000016F
_0803122C: .4byte 0x030046B8
_08031230: .4byte 0x000003FF
_08031234: .4byte 0x0203B400
_08031238:
	adds r0, r3, #1
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08031268 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r1, r8
	ands r0, r1
	adds r0, #8
	mov r2, ip
	strb r0, [r2]
_08031250:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _0803125E
	b _08031360
_0803125E:
	cmp r0, #1
	bgt _0803126C
	cmp r0, #0
	beq _08031274
	b _0803140C
	.align 2, 0
_08031268: .4byte 0x0203B400
_0803126C:
	cmp r0, #2
	bne _08031272
	b _080313D8
_08031272:
	b _0803140C
_08031274:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bhi _0803128A
	b _0803140C
_0803128A:
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080312B0
	ldr r1, _080312AC @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x18
	movs r2, #0x82
	lsls r2, r2, #4
	adds r6, r4, r2
	cmp r0, #0
	bne _080312C2
	movs r3, #0x14
	b _080312C2
	.align 2, 0
_080312AC: .4byte 0x00000824
_080312B0:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r3, #0x14
	adds r6, r0, #0
	cmp r1, #0
	beq _080312C2
	movs r3, #0x18
_080312C2:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_08022da8
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, [r6]
	cmp r0, #0
	beq _08031304
	ldr r0, _08031300 @ =0x0000030B
	bl PlaySound_082406e0
	b _0803130C
	.align 2, 0
_08031300: .4byte 0x0000030B
_08031304:
	movs r0, #0xd7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0803130C:
	adds r0, r4, #0
	bl FUN_0802835c
	cmp r0, #0
	bne _08031318
	b _0803140C
_08031318:
	movs r3, #0
	movs r2, #0xca
	ldr r5, _0803133C @ =0x0000087C
	adds r1, r4, r5
	strb r3, [r1]
	subs r5, #2
	adds r0, r4, r5
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _08031344
	ldr r0, _08031340 @ =0x00000878
	adds r1, r4, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _0803140C
	.align 2, 0
_0803133C: .4byte 0x0000087C
_08031340: .4byte 0x00000878
_08031344:
	cmp r0, #0
	bne _08031354
	ldr r1, _08031350 @ =0x00000878
	adds r0, r4, r1
	strh r3, [r0]
	b _0803140C
	.align 2, 0
_08031350: .4byte 0x00000878
_08031354:
	ldr r2, _0803135C @ =0x00000878
	adds r0, r4, r2
	strh r3, [r0]
	b _0803140C
	.align 2, 0
_0803135C: .4byte 0x00000878
_08031360:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _0803140C
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031394
	ldr r1, _08031390 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x19
	cmp r0, #0
	bne _080313A4
	movs r3, #0x15
	b _080313A4
	.align 2, 0
_08031390: .4byte 0x00000824
_08031394:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x15
	cmp r0, #0
	beq _080313A4
	movs r3, #0x19
_080313A4:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_08022da8
	bl FUN_080846f8
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	b _0803140C
_080313D8:
	adds r0, r4, #0
	bl FUN_0802835c
	cmp r0, #0
	beq _080313F6
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080313F6
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080313F6:
	ldr r2, _08031418 @ =0x00000311
	adds r0, r4, r2
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803140C
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803140C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031418: .4byte 0x00000311

	thumb_func_start dainn_0803141c
dainn_0803141c: @ 0x0803141C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r7, r1, #0
	mov sb, r6
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080314A6
	movs r4, #0
	strb r4, [r1]
	movs r0, #0x20
	movs r1, #0x4d
	adds r1, r1, r6
	mov ip, r1
	strb r0, [r1]
	movs r2, #0xff
	movs r5, #1
	movs r3, #2
	movs r1, #2
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	str r3, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x2d
	bl FUN_08022da8
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _080314F0 @ =0x00000872
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _080314F4 @ =0x0000030E
	bl PlaySound_0824078c
_080314A6:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080315CC
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r5, r6, r0
	ldrh r4, [r5]
	cmp r4, #0
	beq _080314F8
	cmp r4, #1
	beq _080315AC
	b _080315CC
	.align 2, 0
_080314F0: .4byte 0x00000872
_080314F4: .4byte 0x0000030E
_080314F8:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080315CC
	mov r1, r8
	ldrb r0, [r1, #5]
	adds r0, #0x20
	movs r1, #0x20
	rsbs r1, r1, #0
	ands r0, r1
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r4, r6, #0
	adds r4, #0xa1
	strb r1, [r4]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r2, r2, r6
	mov r8, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r7, r6, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	mov r1, r8
	adds r2, r7, #0
	movs r3, #5
	bl FUN_08022d24
	ldr r2, _080315A8 @ =0x00000872
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0803159C
	ldrb r0, [r4]
	cmp r0, #3
	bne _0803159C
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, r8
	adds r2, r7, #0
	movs r3, #0x2d
	bl FUN_08022da8
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_0803159C:
	movs r1, #0xae
	lsls r1, r1, #1
	add r1, sb
	movs r0, #0
	strh r0, [r1]
	b _080315CC
	.align 2, 0
_080315A8: .4byte 0x00000872
_080315AC:
	cmp r7, #0x14
	bne _080315B8
	movs r0, #0xd5
	lsls r0, r0, #2
	bl PlaySound_0824078c
_080315B8:
	ldr r1, _080315DC @ =0x00000311
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080315CC
	adds r0, r6, #0
	adds r0, #0xa7
	strb r4, [r0]
_080315CC:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080315DC: .4byte 0x00000311

	thumb_func_start FUN_080315e0
FUN_080315e0: @ 0x080315E0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r4, #0
	adds r6, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080315F8
	movs r0, #0
	strb r0, [r1]
_080315F8:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r2, r4, #0
	adds r2, #0x98
	ldr r0, [r2]
	orrs r0, r1
	movs r1, #0x1c
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08031662
	cmp r5, #0x3c
	bne _08031656
	ldr r1, _08031668 @ =0x00000899
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
_08031656:
	cmp r5, #0x4f
	ble _08031662
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08031662:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08031668: .4byte 0x00000899

	thumb_func_start FUN_0803166c
FUN_0803166c: @ 0x0803166C
	push {r4, r5, lr}
	sub sp, #8
	adds r3, r0, #0
	adds r4, r3, #0
	adds r2, r3, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	beq _080316BC
	movs r1, #0
	strb r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r2, #0
	strh r1, [r0]
	movs r5, #0xae
	lsls r5, r5, #1
	adds r0, r3, r5
	strh r1, [r0]
	ldr r1, _08031724 @ =0x00000872
	adds r0, r3, r1
	strb r2, [r0]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r5, #0xb5
	lsls r5, r5, #2
	adds r2, r3, r5
	movs r0, #2
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	adds r0, r3, #0
	movs r3, #0x2d
	bl FUN_08022da8
	ldr r0, _08031728 @ =0x00000353
	bl PlaySound_0824078c
_080316BC:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r5, _0803172C @ =0x00000167
	adds r0, r4, r5
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803171C
	subs r5, #9
	adds r2, r4, r5
	ldrh r0, [r2]
	cmp r0, #0
	bne _0803171C
	ldr r1, _08031730 @ =0x00000311
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803171C
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_0803171C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031724: .4byte 0x00000872
_08031728: .4byte 0x00000353
_0803172C: .4byte 0x00000167
_08031730: .4byte 0x00000311

	thumb_func_start FUN_08031734
FUN_08031734: @ 0x08031734
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	beq _08031782
	movs r1, #0
	strb r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _080317E0 @ =0x00000872
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0x2e
	bl FUN_08022da8
	ldr r0, _080317E4 @ =0x00000352
	bl PlaySound_0824078c
_08031782:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _080317E8 @ =0x00000167
	adds r0, r4, r3
	strb r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r2, r4, #0
	adds r2, #0x98
	ldr r0, [r2]
	orrs r0, r1
	movs r1, #0xc
	orrs r0, r1
	str r0, [r2]
	adds r1, #0xf4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080317D6
	ldr r2, _080317EC @ =0x00000311
	adds r0, r4, r2
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080317D6
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080317D6:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080317E0: .4byte 0x00000872
_080317E4: .4byte 0x00000352
_080317E8: .4byte 0x00000167
_080317EC: .4byte 0x00000311

	thumb_func_start FUN_080317f0
FUN_080317f0: @ 0x080317F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	mov sl, r7
	adds r2, r7, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	bne _0803180C
	b _08031A44
_0803180C:
	movs r1, #0
	strb r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	ldr r1, _080318A0 @ =0x00000873
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r6, #4
	str r6, [sp, #4]
	adds r0, r7, #0
	adds r2, r4, #0
	movs r3, #0x2f
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	str r6, [sp]
	adds r1, r4, #0
	movs r2, #0x30
	movs r3, #2
	bl FUN_082370cc
	mov sb, r7
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	movs r3, #0xa4
	lsls r3, r3, #4
	adds r5, r7, r3
	adds r0, r7, #0
	bl FUN_08028ec8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0xa2
	lsls r0, r0, #4
	adds r1, r7, r0
	str r6, [sp]
	adds r0, r5, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r7, #0
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _080318A4
	ldr r0, [r5, #8]
	orrs r0, r6
	b _080318AC
	.align 2, 0
_080318A0: .4byte 0x00000873
_080318A4:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080318AC:
	str r0, [r5, #8]
	ldr r1, _08031904 @ =0x00000173
	adds r3, r7, r1
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08031908 @ =0x00000A18
	adds r2, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, [sp, #0x1c]
	ldr r0, [r2, #0x20]
	ldr r1, [r2, #0x24]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r6, r5, #0
	adds r6, #0x20
	add r0, sp, #0x14
	mov ip, r0
	add r0, sp, #0x14
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	mov r1, ip
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov r8, r3
	cmp r0, #0
	blt _0803190C
	asrs r0, r0, #8
	b _08031912
	.align 2, 0
_08031904: .4byte 0x00000173
_08031908: .4byte 0x00000A18
_0803190C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08031912:
	strh r0, [r6]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08031924
	asrs r0, r0, #8
	b _0803192A
_08031924:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0803192A:
	adds r4, r0, #0
	mov r2, ip
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08031940
	asrs r0, r0, #8
	b _08031946
_08031940:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08031946:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08031988 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	mov r0, sb
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _08031990
	ldr r0, _0803198C @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r5, #0x20]
	adds r1, r1, r2
	strh r1, [r5, #0x20]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r3, [r5, #0x22]
	adds r0, r0, r3
	b _080319A4
	.align 2, 0
_08031988: .4byte 0x030047C8
_0803198C: .4byte 0x085AABBC
_08031990:
	ldr r2, _08031A1C @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrh r0, [r5, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	movs r0, #1
	ldrsb r0, [r2, r0]
	ldrh r1, [r5, #0x22]
	adds r0, r0, r1
_080319A4:
	strh r0, [r5, #0x22]
	ldr r0, [r5, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
	ldr r2, _08031A20 @ =0x00000A14
	adds r1, r7, r2
	ldr r0, _08031A24 @ =0x0000FFFF
	strh r0, [r1]
	ldr r3, [sp, #0x1c]
	ldrh r1, [r3, #0x14]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	mov r0, sb
	adds r0, #0xab
	ldrb r3, [r0]
	cmp r3, #0
	bne _080319F4
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _08031A28 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp, #0x1c]
	adds r1, #0x20
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl FUN_0807ab64
_080319F4:
	movs r0, #0x84
	lsls r0, r0, #7
	strh r0, [r5, #0x3a]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	ldr r1, _08031A28 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r1, _08031A2C @ =0x00000359
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08031A30
	adds r0, r3, #0
	adds r0, #0xd0
	ldr r0, [r0]
	b _08031A3A
	.align 2, 0
_08031A1C: .4byte 0x085AABBC
_08031A20: .4byte 0x00000A14
_08031A24: .4byte 0x0000FFFF
_08031A28: .4byte 0x03002BE0
_08031A2C: .4byte 0x00000359
_08031A30:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
_08031A3A:
	str r0, [r5, #0x48]
	ldr r3, _08031A88 @ =0x00000874
	adds r1, r7, r3
	movs r0, #0x78
	strh r0, [r1]
_08031A44:
	movs r1, #0x80
	lsls r1, r1, #0x11
	mov r0, sl
	adds r0, #0x98
	ldr r2, [r0]
	orrs r2, r1
	str r2, [r0]
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r1, [r1]
	adds r4, r0, #0
	cmp r1, #0
	beq _08031A64
	cmp r1, #5
	bne _08031A90
_08031A64:
	movs r0, #0xc
	orrs r2, r0
	str r2, [r4]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _08031A8C @ =0x00000167
	adds r0, r7, r3
	strb r2, [r0]
	b _08031AA4
	.align 2, 0
_08031A88: .4byte 0x00000874
_08031A8C: .4byte 0x00000167
_08031A90:
	mov r0, sl
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, sl
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08031AA4
	b _08031EFE
_08031AA4:
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	mov r0, sl
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08031AD4
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	b _08031EFE
_08031AD4:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _08031B46
	ldr r3, _08031B60 @ =0x00000173
	adds r0, r7, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, sl
	adds r0, r0, r1
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrb r2, [r0]
	ldr r0, _08031B64 @ =0x00000877
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, r2
	beq _08031B18
	strb r2, [r1]
	ldr r2, _08031B68 @ =0x0000016D
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08031B18:
	ldr r0, _08031B68 @ =0x0000016D
	adds r4, r7, r0
	ldrb r0, [r4]
	cmp r0, #3
	bls _08031B46
	adds r0, r3, #0
	bl FUN_0807849c
	lsls r0, r0, #0x1d
	movs r1, #0xa0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x10
	strb r0, [r1]
	strb r5, [r4]
_08031B46:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #5
	bls _08031B54
	b _08031EDA
_08031B54:
	lsls r0, r0, #2
	ldr r1, _08031B6C @ =_08031B70
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031B60: .4byte 0x00000173
_08031B64: .4byte 0x00000877
_08031B68: .4byte 0x0000016D
_08031B6C: .4byte _08031B70
_08031B70: @ jump table
	.4byte _08031B88 @ case 0
	.4byte _08031BCA @ case 1
	.4byte _08031C74 @ case 2
	.4byte _08031CCC @ case 3
	.4byte _08031D2A @ case 4
	.4byte _08031EC4 @ case 5
_08031B88:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r6, r7, r2
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031B9E
	b _08031EDA
_08031B9E:
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x31
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x32
	b _08031CB4
_08031BCA:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r6, r7, r3
	ldrh r0, [r6]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031BE4
	b _08031EDA
_08031BE4:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r5, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x33
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x34
	movs r3, #2
	bl FUN_082370cc
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r6]
	ldr r3, _08031C64 @ =0x00000173
	adds r1, r7, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08031C52
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, sl
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r2, _08031C68 @ =0x00000876
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08031C6C @ =0x00000877
	adds r0, r7, r3
	strb r1, [r0]
_08031C52:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	ldr r3, _08031C70 @ =0x0000016D
	adds r0, r7, r3
	strb r2, [r0]
	b _08031EDA
	.align 2, 0
_08031C64: .4byte 0x00000173
_08031C68: .4byte 0x00000876
_08031C6C: .4byte 0x00000877
_08031C70: .4byte 0x0000016D
_08031C74:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r6, r7, r0
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031C8A
	b _08031EDA
_08031C8A:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r5, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x35
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x36
_08031CB4:
	movs r3, #2
	bl FUN_082370cc
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r6]
	b _08031EDA
_08031CCC:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r5, r7, r3
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031CE2
	b _08031EDA
_08031CE2:
	movs r0, #0xa4
	lsls r0, r0, #4
	adds r4, r7, r0
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, sl
	movs r3, #0x37
	bl FUN_08022da8
	movs r0, #0xd5
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r4, #8]
	orrs r0, r2
	str r0, [r4, #8]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r5]
	b _08031EDA
_08031D2A:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031D40
	b _08031EDA
_08031D40:
	movs r1, #4
	ldr r0, _08031E04 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08031D7C
	ldr r1, _08031E08 @ =0x00000173
	adds r0, r7, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, sl
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _08031E0C @ =0x00000876
	adds r1, r7, r2
	ldrb r1, [r1]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r0, [r0]
	ldr r2, _08031E10 @ =0xFFFFFF00
	adds r1, r1, r2
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0xf
	ble _08031D84
_08031D7C:
	ldr r3, _08031E14 @ =0x00000874
	adds r1, r7, r3
	movs r0, #0
	strh r0, [r1]
_08031D84:
	ldr r1, _08031E14 @ =0x00000874
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08031E20
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, sl
	movs r3, #0x38
	bl FUN_08022da8
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	adds r0, r7, #0
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r2, _08031E08 @ =0x00000173
	adds r2, r2, r7
	mov r8, r2
	cmp r4, #0
	bne _08031DF6
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08031DF6
	adds r2, r0, #0
	ldr r1, _08031E18 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r7, #0
	adds r1, #0xc8
	adds r1, r1, r2
	ldrb r3, [r1]
	ldr r2, _08031E1C @ =0x00000A18
	adds r1, r7, r2
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_08031DF6:
	movs r0, #0xff
	mov r3, r8
	strb r0, [r3]
	adds r0, #0x5f
	adds r1, r7, r0
	b _08031E54
	.align 2, 0
_08031E04: .4byte 0x03002BC0
_08031E08: .4byte 0x00000173
_08031E0C: .4byte 0x00000876
_08031E10: .4byte 0xFFFFFF00
_08031E14: .4byte 0x00000874
_08031E18: .4byte 0x03002BE0
_08031E1C: .4byte 0x00000A18
_08031E20:
	ldr r2, _08031E5C @ =0x00000873
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08031E60
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, sl
	movs r3, #0x38
	bl FUN_08022da8
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r7, r2
_08031E54:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08031EB8
	.align 2, 0
_08031E5C: .4byte 0x00000873
_08031E60:
	movs r3, #0xa4
	lsls r3, r3, #4
	adds r3, r3, r7
	mov sb, r3
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r6, r7, r2
	movs r3, #2
	mov r8, r3
	str r3, [sp]
	movs r5, #4
	str r5, [sp, #4]
	mov r0, sl
	adds r2, r6, #0
	movs r3, #0x35
	bl FUN_08022da8
	movs r0, #0xd5
	lsls r0, r0, #2
	adds r4, r7, r0
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x36
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	mov r2, sb
	ldr r0, [r2, #8]
	ands r0, r1
	str r0, [r2, #8]
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r1, r8
	strh r1, [r0]
_08031EB8:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	b _08031EDA
_08031EC4:
	ldr r3, _08031F10 @ =0x00000311
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08031EDA
	mov r1, sl
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08031EDA:
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r7, r2
	bl FUN_082372cc
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_08031EFE:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031F10: .4byte 0x00000311

	thumb_func_start FUN_08031f14
FUN_08031f14: @ 0x08031F14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	mov r8, r6
	adds r2, r6, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	beq _08031F76
	movs r1, #0
	strb r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	subs r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r5, r6, r2
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x2f
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x30
	movs r3, #2
	bl FUN_082370cc
_08031F76:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r4, r6, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	movs r1, #0xc
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	orrs r0, r1
	str r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08031FCC
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	b _08032170
_08031FCC:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #4
	bls _08031FDA
	b _0803214E
_08031FDA:
	lsls r0, r0, #2
	ldr r1, _08031FE4 @ =_08031FE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031FE4: .4byte _08031FE8
_08031FE8: @ jump table
	.4byte _08031FFC @ case 0
	.4byte _0803203E @ case 1
	.4byte _0803207E @ case 2
	.4byte _080320D4 @ case 3
	.4byte _0803212E @ case 4
_08031FFC:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08032012
	b _0803214E
_08032012:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	adds r2, r5, #0
	movs r3, #0x31
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x32
	b _080320BC
_0803203E:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _0803214E
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	adds r2, r5, #0
	movs r3, #0x33
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x34
	b _080320BC
_0803207E:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _0803214E
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	adds r2, r5, #0
	movs r3, #0x35
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x36
_080320BC:
	movs r3, #2
	bl FUN_082370cc
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r7]
	b _0803214E
_080320D4:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r4, r6, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _0803214E
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0x38
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r2, r6, r1
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r4]
	b _0803214E
_0803212E:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _0803217C @ =0x00000311
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803214E
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803214E:
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r6, r2
	subs r2, #0x80
	adds r1, r6, r2
	bl FUN_082372cc
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_08032170:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803217C: .4byte 0x00000311

	thumb_func_start FUN_08032180
FUN_08032180: @ 0x08032180
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r6
	adds r2, r6, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	beq _080321AE
	movs r1, #0
	strb r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
_080321AE:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _0803220C @ =0x00000167
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r4, r6, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	movs r1, #0xc
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	orrs r0, r1
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080321F6
	b _080323B4
_080321F6:
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r7, [r2]
	cmp r7, #1
	beq _08032246
	cmp r7, #1
	bgt _08032210
	cmp r7, #0
	beq _08032218
	b _080323B4
	.align 2, 0
_0803220C: .4byte 0x00000167
_08032210:
	cmp r7, #2
	bne _08032216
	b _080323A0
_08032216:
	b _080323B4
_08032218:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	str r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _0803223C
	b _080323B4
_0803223C:
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r7, [r1]
	b _080323B4
_08032246:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ldr r1, [r4]
	orrs r1, r0
	movs r2, #0x10
	mov sl, r2
	orrs r1, r2
	str r1, [r4]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0x3c
	bhi _080322EE
	movs r4, #0xf
	ands r4, r0
	cmp r4, #0
	bne _080322EE
	adds r0, r6, #0
	movs r1, #4
	movs r2, #0x14
	bl FUN_08022c24
	ldr r1, _08032388 @ =0x00000173
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, _0803238C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r6, r2
	str r4, [sp]
	str r4, [sp, #4]
	str r7, [sp, #8]
	ldr r3, _08032390 @ =0x000008C8
	adds r2, r6, r3
	ldrh r2, [r2]
	str r2, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl FUN_0807ab64
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x90
	movs r0, #0
	ldrsh r5, [r4, r0]
	mov r2, sb
	adds r1, r5, r2
	adds r0, r6, #0
	bl FUN_08022bb0
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r5, r0
	beq _080322E8
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, _08032394 @ =0xFFFF0000
	mov r3, sl
	str r3, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ands r1, r2
	orrs r1, r3
	str r1, [sp, #0x18]
	adds r3, r6, #0
	adds r3, #0x50
	add r1, sp, #0x14
	str r1, [sp]
	str r7, [sp, #4]
	mov r1, sb
	movs r2, #1
	bl FUN_0805fe7c
_080322E8:
	movs r0, #0xe6
	bl PlaySound_0824078c
_080322EE:
	movs r2, #0xae
	lsls r2, r2, #1
	add r2, r8
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bhi _0803230E
	movs r1, #4
	ldr r0, _08032398 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080323B4
_0803230E:
	movs r1, #0xaf
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	movs r1, #0xbd
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0xb5
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x39
	bl FUN_08022da8
	movs r2, #0xa4
	lsls r2, r2, #4
	add r2, r8
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	mov r0, r8
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r5, _08032388 @ =0x00000173
	add r5, r8
	cmp r4, #0
	bne _08032382
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _08032382
	adds r2, r0, #0
	ldr r1, _0803238C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, r8
	adds r1, #0xc8
	adds r1, r1, r2
	ldrb r3, [r1]
	ldr r1, _0803239C @ =0x00000A18
	add r1, r8
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_08032382:
	movs r0, #0xff
	strb r0, [r5]
	b _080323B4
	.align 2, 0
_08032388: .4byte 0x00000173
_0803238C: .4byte 0x03002BE0
_08032390: .4byte 0x000008C8
_08032394: .4byte 0xFFFF0000
_08032398: .4byte 0x03002BC0
_0803239C: .4byte 0x00000A18
_080323A0:
	ldr r2, _080323C4 @ =0x00000311
	adds r0, r6, r2
	ldrb r0, [r0]
	ands r7, r0
	cmp r7, #0
	beq _080323B4
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080323B4:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080323C4: .4byte 0x00000311

	thumb_func_start dainn_080323c8
dainn_080323c8: @ 0x080323C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	ldr r0, _08032438 @ =0x00000899
	adds r1, r6, r0
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080324A4
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032440
	ldr r1, _0803243C @ =0x00000824
	adds r0, r6, r1
	ldr r0, [r0]
	movs r3, #0x17
	cmp r0, #0
	bne _08032450
	movs r3, #0x13
	b _08032450
	.align 2, 0
_08032438: .4byte 0x00000899
_0803243C: .4byte 0x00000824
_08032440:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #0x13
	cmp r0, #0
	beq _08032450
	movs r3, #0x17
_08032450:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	bl FUN_08022da8
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _080324F0 @ =0x03004494
	ldr r3, _080324F4 @ =0x00001084
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, _080324F8 @ =0x03004454
	ldr r4, _080324FC @ =0x00001FFF
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _08032500 @ =0x00001044
	adds r1, r5, r0
	movs r0, #0xe1
	lsls r0, r0, #2
	str r0, [r1]
	subs r0, #0x33
	bl PlaySound_0824078c
	movs r0, #0xc3
	lsls r0, r0, #2
	bl PlaySound_0824078c
_080324A4:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _08032530
	ldr r2, _08032504 @ =0x00000878
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	ldr r3, _08032508 @ =0x0000087C
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	ldr r4, _0803250C @ =0x0000087A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _08032510
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r5, r2
	b _0803251E
	.align 2, 0
_080324F0: .4byte 0x03004494
_080324F4: .4byte 0x00001084
_080324F8: .4byte 0x03004454
_080324FC: .4byte 0x00001FFF
_08032500: .4byte 0x00001044
_08032504: .4byte 0x00000878
_08032508: .4byte 0x0000087C
_0803250C: .4byte 0x0000087A
_08032510:
	ldr r0, _0803252C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
_0803251E:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r5, r4
	b _08032808
	.align 2, 0
_0803252C: .4byte 0x03003584
_08032530:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080325A4
	ldr r2, _08032578 @ =0x00000878
	adds r0, r5, r2
	strh r4, [r0]
	ldr r3, _0803257C @ =0x0000087C
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	ldr r4, _08032580 @ =0x0000087A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _08032584
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r5, r2
	b _08032592
	.align 2, 0
_08032578: .4byte 0x00000878
_0803257C: .4byte 0x0000087C
_08032580: .4byte 0x0000087A
_08032584:
	ldr r0, _080325A0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
_08032592:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r5, r4
	b _08032808
	.align 2, 0
_080325A0: .4byte 0x03003584
_080325A4:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _080325BA
	adds r0, r2, #2
	strh r0, [r3]
_080325BA:
	ldr r2, _080325DC @ =0x085B0A08
	lsls r0, r7, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	mov ip, r2
	cmp r0, #0
	blt _080325E0
	asrs r1, r0, #0xc
	b _080325E6
	.align 2, 0
_080325DC: .4byte 0x085B0A08
_080325E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080325E6:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080325FC
	strh r3, [r1]
_080325FC:
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r2]
	cmp r0, #1
	beq _080326AC
	cmp r0, #1
	bgt _08032612
	cmp r0, #0
	beq _08032620
	b _0803292C
_08032612:
	cmp r0, #2
	bne _08032618
	b _08032722
_08032618:
	cmp r0, #3
	bne _0803261E
	b _08032908
_0803261E:
	b _0803292C
_08032620:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08032636
	b _0803292C
_08032636:
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032654
	ldr r1, _08032650 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x18
	cmp r0, #0
	bne _08032664
	movs r3, #0x14
	b _08032664
	.align 2, 0
_08032650: .4byte 0x00000824
_08032654:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x14
	cmp r0, #0
	beq _08032664
	movs r3, #0x18
_08032664:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r4, #2
	str r4, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	bl FUN_08022da8
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _080326A4 @ =0x0000087C
	adds r0, r5, r3
	strb r4, [r0]
	ldr r4, _080326A8 @ =0x00000878
	adds r1, r5, r4
	movs r0, #0x20
	strh r0, [r1]
	b _0803292C
	.align 2, 0
_080326A4: .4byte 0x0000087C
_080326A8: .4byte 0x00000878
_080326AC:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bhi _080326C2
	b _0803292C
_080326C2:
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080326E0
	ldr r1, _080326DC @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x19
	cmp r0, #0
	bne _080326F0
	movs r3, #0x15
	b _080326F0
	.align 2, 0
_080326DC: .4byte 0x00000824
_080326E0:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x15
	cmp r0, #0
	beq _080326F0
	movs r3, #0x19
_080326F0:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	bl FUN_08022da8
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	b _0803292C
_08032722:
	cmp r7, #0x7f
	ble _08032814
	movs r0, #0x20
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	movs r2, #0xff
	movs r1, #2
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803276C
	ldr r3, _08032768 @ =0x00000824
	adds r0, r5, r3
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _0803277C
	movs r3, #0
	b _0803277C
	.align 2, 0
_08032768: .4byte 0x00000824
_0803276C:
	movs r4, #0x82
	lsls r4, r4, #4
	adds r0, r5, r4
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _0803277C
	movs r3, #5
_0803277C:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r5, r4
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_08022d24
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _080327E4 @ =0x00000878
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _080327E8 @ =0x0000087C
	adds r1, r5, r4
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	ldr r2, _080327EC @ =0x0000087A
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _080327F0
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r4, #0x84
	lsls r4, r4, #3
	adds r0, r5, r4
	b _080327FE
	.align 2, 0
_080327E4: .4byte 0x00000878
_080327E8: .4byte 0x0000087C
_080327EC: .4byte 0x0000087A
_080327F0:
	ldr r0, _08032810 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r1, r5, r2
_080327FE:
	str r0, [r1]
	adds r0, r1, #0
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r1, r5, r3
_08032808:
	ldr r0, [r0]
	str r0, [r1]
	b _0803292C
	.align 2, 0
_08032810: .4byte 0x03003584
_08032814:
	movs r0, #3
	ands r0, r7
	cmp r0, #0

	non_word_aligned_thumb_func_start FUN_0803281a
FUN_0803281a: @ 0x0803281A
	beq _0803281E
	b _0803292C
_0803281E:
	ldr r4, _08032864 @ =0x00000899
	adds r1, r5, r4
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r3, _08032868 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0803286C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08032870 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r2, r2, r0
	adds r4, r2, #0
	subs r4, #0x10
	add r3, sp, #0x10
	adds r2, #0x30
	movs r0, #0xff
	ands r2, r0
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #8
	cmp r0, #0
	blt _08032874
	asrs r1, r0, #0xc
	b _0803287A
	.align 2, 0
_08032864: .4byte 0x00000899
_08032868: .4byte 0x030046B8
_0803286C: .4byte 0x000003FF
_08032870: .4byte 0x0203B400
_08032874:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803287A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0803289A
	asrs r0, r0, #0xc
	b _080328A0
_0803289A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080328A0:
	strh r0, [r3, #4]
	add r3, sp, #0x10
	adds r2, r6, #0
	adds r2, #0x50
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r2, [r3, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	adds r1, #0xa4
	strh r1, [r3, #2]
	ldr r3, _080328FC @ =0x00000899
	adds r0, r5, r3
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r6, r2
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r3, _08032900 @ =0x00001054
	adds r0, r5, r3
	ldr r0, [r0]
	str r4, [sp]
	movs r1, #0x14
	str r1, [sp, #4]
	ldr r4, _08032904 @ =0x000008CA
	adds r1, r5, r4
	ldrh r1, [r1]
	str r1, [sp, #8]
	movs r1, #0x32
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0
	bl FUN_0805b7d4
	b _0803292C
	.align 2, 0
_080328FC: .4byte 0x00000899
_08032900: .4byte 0x00001054
_08032904: .4byte 0x000008CA
_08032908:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _0803292C
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r3, [r1]
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803292C:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08032934
FUN_08032934: @ 0x08032934
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08032946
	movs r0, #0
	strb r0, [r1]
_08032946:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r3, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r3, r1
	strb r2, [r0]
	movs r1, #0xc
	adds r2, r3, #0
	adds r2, #0x98
	ldr r0, [r2]
	orrs r0, r1
	ldr r1, _08032984 @ =0x00010010
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_08032984: .4byte 0x00010010

	thumb_func_start FUN_08032988
FUN_08032988: @ 0x08032988
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08032A38
	movs r0, #0
	mov r8, r0
	mov r3, r8
	strb r3, [r1]
	movs r0, #0x40
	movs r1, #0x4d
	adds r1, r1, r5
	mov ip, r1
	movs r7, #0
	strb r0, [r1]
	movs r2, #0xff
	movs r4, #1
	movs r3, #2
	movs r1, #2
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x41
	bl FUN_08022c9c
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r7, [r0]
	movs r2, #0xca
	ldr r3, _08032A18 @ =0x0000087C
	adds r1, r5, r3
	strb r4, [r1]
	subs r3, #2
	adds r0, r5, r3
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _08032A20
	ldr r0, _08032A1C @ =0x00000878
	adds r1, r5, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _08032A38
	.align 2, 0
_08032A18: .4byte 0x0000087C
_08032A1C: .4byte 0x00000878
_08032A20:
	cmp r0, #0
	bne _08032A30
	ldr r1, _08032A2C @ =0x00000878
	adds r0, r5, r1
	strh r7, [r0]
	b _08032A38
	.align 2, 0
_08032A2C: .4byte 0x00000878
_08032A30:
	ldr r3, _08032AB0 @ =0x00000878
	adds r0, r5, r3
	mov r1, r8
	strh r1, [r0]
_08032A38:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	subs r3, #0x19
	adds r0, r6, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08032AC0
	ldr r3, _08032AB4 @ =0x00000311
	adds r0, r6, r3
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08032AC0
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08032AB8
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x40
	bl FUN_08022c9c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _08032AC0
	.align 2, 0
_08032AB0: .4byte 0x00000878
_08032AB4: .4byte 0x00000311
_08032AB8:
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08032AC0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08032acc
FUN_08032acc: @ 0x08032ACC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r1, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08032B3C
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032B04
	ldr r1, _08032B00 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x16
	cmp r0, #0
	bne _08032B14
	movs r3, #0x12
	b _08032B14
	.align 2, 0
_08032B00: .4byte 0x00000824
_08032B04:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x12
	cmp r0, #0
	beq _08032B14
	movs r3, #0x16
_08032B14:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022da8
	bl FUN_080846f8
	adds r0, r5, #0
	bl FUN_08029c2c
	ldr r0, _08032BA4 @ =0x000001C5
	bl PlaySound_0824078c
_08032B3C:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	movs r6, #0
	strh r6, [r0]
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #8
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #3
	ands r0, r7
	cmp r0, #0
	bne _08032B7A
	adds r0, r5, #0
	bl FUN_0802991c
_08032B7A:
	cmp r7, #0x77
	ble _08032B9A
	ldr r1, _08032BA8 @ =FUN_08032bac
	movs r0, #0x20
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08032B9A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032BA4: .4byte 0x000001C5
_08032BA8: .4byte FUN_08032bac

	thumb_func_start FUN_08032bac
FUN_08032bac: @ 0x08032BAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	str r1, [sp, #0x10]
	mov r7, sb
	movs r0, #0x48
	adds r0, r0, r7
	mov sl, r0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	bne _08032BD0
	b _08032D0E
_08032BD0:
	movs r0, #0
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_080298fc
	movs r0, #0x80
	adds r1, r7, #0
	adds r1, #0x4d
	strb r0, [r1]
	movs r2, #0xff
	movs r3, #3
	adds r0, r7, #0
	adds r0, #0xa0
	strb r3, [r0]
	ldrb r0, [r1]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r4, r7, #0
	adds r4, #0xa1
	strb r0, [r4]
	mov r5, sl
	ldrb r0, [r5, #5]
	adds r0, #0xa0
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	ands r0, r3
	lsls r0, r0, #0x1e
	movs r3, #0xc0
	lsls r3, r3, #0x18
	adds r0, r0, r3
	lsrs r0, r0, #0x18
	ands r0, r2
	lsrs r0, r0, #5
	adds r0, #3
	ands r1, r0
	strb r1, [r4]
	adds r0, r7, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032C40
	ldr r5, _08032C3C @ =0x00000824
	adds r0, r7, r5
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _08032C50
	movs r3, #0x1a
	b _08032C50
	.align 2, 0
_08032C3C: .4byte 0x00000824
_08032C40:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _08032C50
	movs r3, #0x1f
_08032C50:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r5, #0xb5
	lsls r5, r5, #2
	adds r2, r7, r5
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	mov r0, sb
	bl FUN_08022d24
	adds r0, r7, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _08032C88
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r7, r2
	b _08032C96
_08032C88:
	ldr r0, _08032D24 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r7, r3
_08032C96:
	str r0, [r1]
	adds r0, r1, #0
	movs r5, #0xe7
	lsls r5, r5, #2
	adds r1, r7, r5
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_08029c74
	movs r0, #1
	ldr r2, _08032D28 @ =0x0000016B
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0x82
	lsls r3, r3, #5
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _08032CD2
	movs r1, #4
	ldr r0, _08032D2C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08032CD2
	ldrh r0, [r2]
	movs r1, #0
	bl Script_ExecById
_08032CD2:
	mov r6, sl
	adds r6, #8
	movs r5, #0xc0
	lsls r5, r5, #6
	mov r8, r5
	movs r5, #0x40
	str r5, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r4, #0x80
	lsls r4, r4, #1
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r1, #3
	movs r2, #2
	mov r3, r8
	bl FUN_08015a90
	str r5, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r1, #5
	movs r2, #2
	mov r3, r8
	bl FUN_08015a90
_08032D0E:
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08032D30
	subs r0, r2, #4
	b _08032D32
	.align 2, 0
_08032D24: .4byte 0x03003584
_08032D28: .4byte 0x0000016B
_08032D2C: .4byte 0x03002BC0
_08032D30:
	movs r0, #0
_08032D32:
	strh r0, [r1]
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r1, r7, r5
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08032D48
	subs r0, r2, #4
	b _08032D4A
_08032D48:
	movs r0, #0
_08032D4A:
	strh r0, [r1]
	movs r2, #0xd
	mov r1, sb
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #3
	ldr r5, [sp, #0x10]
	ands r0, r5
	cmp r0, #0
	bne _08032D68
	adds r0, r7, #0
	bl FUN_0802991c
_08032D68:
	ldr r0, [sp, #0x10]
	cmp r0, #0xf
	bgt _08032DC2
	lsls r1, r0, #1
	movs r0, #0x2a
	mov r3, sl
	adds r3, #0x10
	mov r2, sl
	ldrb r6, [r2, #5]
	subs r4, r0, r1
	ldr r2, _08032D98 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r4, r0
	cmp r0, #0
	blt _08032D9C
	asrs r1, r0, #0xc
	b _08032DA2
	.align 2, 0
_08032D98: .4byte 0x085B0A08
_08032D9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08032DA2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08032DBA
	asrs r0, r0, #0xc
	b _08032DC0
_08032DBA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08032DC0:
	strh r0, [r3, #4]
_08032DC2:
	ldr r2, [sp, #0x10]
	cmp r2, #0x1e
	bne _08032DFE
	ldr r2, _08032E10 @ =FUN_0802e520
	movs r3, #1
	mov r0, sb
	adds r0, #0xa3
	movs r1, #0
	strb r3, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	ldr r3, _08032E14 @ =0x00001042
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _08032DFE
	movs r1, #4
	ldr r0, _08032E18 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08032DFE
	ldrh r0, [r2]
	movs r1, #0
	bl Script_ExecById
_08032DFE:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032E10: .4byte FUN_0802e520
_08032E14: .4byte 0x00001042
_08032E18: .4byte 0x03002BC0

	thumb_func_start FUN_08032e1c
FUN_08032e1c: @ 0x08032E1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r1
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08032EB6
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032E5C
	ldr r1, _08032E58 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x49
	subs r1, #4
	adds r6, r4, r1
	cmp r0, #0
	bne _08032E6E
	movs r3, #0x48
	b _08032E6E
	.align 2, 0
_08032E58: .4byte 0x00000824
_08032E5C:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r1, [r0]
	movs r3, #0x48
	adds r6, r0, #0
	cmp r1, #0
	beq _08032E6E
	movs r3, #0x49
_08032E6E:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r7, #0
	str r7, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022da8
	ldr r0, [r6]
	cmp r0, #0
	bne _08032E92
	adds r0, r5, #0
	bl FUN_0802a538
_08032E92:
	movs r1, #0x8e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_08023090
	movs r3, #0xc5
	lsls r3, r3, #2
	adds r1, r5, r3
	adds r0, r4, #0
	bl FUN_08022fb8
	bl FUN_080846f8
	ldr r1, _08032ECC @ =0x00001044
	adds r0, r5, r1
	str r7, [r0]
_08032EB6:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08032ED0
	subs r0, r2, #4
	b _08032ED2
	.align 2, 0
_08032ECC: .4byte 0x00001044
_08032ED0:
	movs r0, #0
_08032ED2:
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08032EE8
	subs r0, r2, #4
	b _08032EEA
_08032EE8:
	movs r0, #0
_08032EEA:
	strh r0, [r1]
	movs r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r8, r0
	bne _08032F0C
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_08023024
_08032F0C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start dainn_08032f18
dainn_08032f18: @ 0x08032F18
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	adds r4, r6, #0
	adds r4, #0x48
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08032FD8
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032F54
	ldr r1, _08032F50 @ =0x00000824
	adds r0, r6, r1
	ldr r0, [r0]
	movs r3, #0xe
	cmp r0, #0
	bne _08032F64
	movs r3, #0xa
	b _08032F64
	.align 2, 0
_08032F50: .4byte 0x00000824
_08032F54:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #0xa
	cmp r0, #0
	beq _08032F64
	movs r3, #0xe
_08032F64:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_08022c9c
	movs r1, #0x8e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl FUN_08023090
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r6, #0
	bl FUN_08022fb8
	ldr r3, _08032FEC @ =0x00001044
	adds r0, r5, r3
	movs r2, #0
	str r2, [r0]
	ldr r0, _08032FF0 @ =0x00000854
	adds r3, r5, r0
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	ldr r0, _08032FF4 @ =0x00000311
	bl PlaySound_0824078c
	ldr r0, _08032FF8 @ =0x000001C5
	bl PlaySound_0824078c
	ldr r1, _08032FFC @ =0x00001050
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08032FD8
	bl FUN_0805b1a0
_08032FD8:
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08033000
	subs r0, r2, #4
	b _08033002
	.align 2, 0
_08032FEC: .4byte 0x00001044
_08032FF0: .4byte 0x00000854
_08032FF4: .4byte 0x00000311
_08032FF8: .4byte 0x000001C5
_08032FFC: .4byte 0x00001050
_08033000:
	movs r0, #0
_08033002:
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08033018
	subs r0, r2, #4
	b _0803301A
_08033018:
	movs r0, #0
_0803301A:
	strh r0, [r1]
	movs r2, #0xd
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #4
	bls _08033036
	b _08033310
_08033036:
	lsls r0, r0, #2
	ldr r1, _08033040 @ =_08033044
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033040: .4byte _08033044
_08033044: @ jump table
	.4byte _08033058 @ case 0
	.4byte _080330B4 @ case 1
	.4byte _08033110 @ case 2
	.4byte _080331C4 @ case 3
	.4byte _080332D4 @ case 4
_08033058:
	movs r0, #8
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #3
	ands r0, r7
	cmp r0, #0
	bne _08033070
	adds r0, r5, #0
	bl FUN_0802991c
_08033070:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _08033086
	b _08033310
_08033086:
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_08029cc8
	ldr r0, _080330AC @ =0x00000355
	bl PlaySound_0824078c
	ldr r0, _080330B0 @ =0x000001C5
	bl PlaySound_0824078c
	b _08033310
	.align 2, 0
_080330AC: .4byte 0x00000355
_080330B0: .4byte 0x000001C5
_080330B4:
	movs r0, #8
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #3
	ands r0, r7
	cmp r0, #0
	bne _080330CC
	adds r0, r5, #0
	bl FUN_0802991c
_080330CC:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _080330E2
	b _08033310
_080330E2:
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x16
	bl FUN_08022da8
	b _08033310
_08033110:
	adds r0, r4, #0
	adds r0, #8
	ldr r4, _08033198 @ =0x00000854
	adds r1, r5, r4
	ldr r3, _0803319C @ =0x00000FD8
	adds r2, r5, r3
	movs r4, #0xae
	lsls r4, r4, #1
	adds r6, r5, r4
	ldrh r3, [r6]
	movs r4, #7
	str r4, [sp]
	bl FUN_08237970
	movs r0, #3
	ands r0, r7
	cmp r0, #0
	bne _0803313A
	adds r0, r5, #0
	bl FUN_0802991c
_0803313A:
	ldrh r0, [r6]
	adds r0, #1
	movs r2, #0
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x80
	bls _080331B8
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	strh r2, [r6]
	ldr r3, _080331A0 @ =0x00000FD4
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	ldr r4, _080331A4 @ =0x00000878
	adds r0, r5, r4
	strh r2, [r0]
	ldr r0, _080331A8 @ =0x0000087C
	adds r1, r5, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _080331AC @ =0x0000087A
	adds r1, r5, r2
	movs r0, #0xc1
	strh r0, [r1]
	ldr r1, _080331B0 @ =0x03003584
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _080331B4 @ =0x0000033B
	bl PlaySound_082406e0
	b _08033310
	.align 2, 0
_08033198: .4byte 0x00000854
_0803319C: .4byte 0x00000FD8
_080331A0: .4byte 0x00000FD4
_080331A4: .4byte 0x00000878
_080331A8: .4byte 0x0000087C
_080331AC: .4byte 0x0000087A
_080331B0: .4byte 0x03003584
_080331B4: .4byte 0x0000033B
_080331B8:
	movs r0, #8
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	b _08033310
_080331C4:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0x1f
	bhi _080331DA
	movs r0, #4
	movs r4, #0xc5
	lsls r4, r4, #1
	adds r1, r5, r4
	strb r0, [r1]
_080331DA:
	ldrh r0, [r2]
	cmp r0, #0x20
	bne _08033226
	movs r0, #3
	movs r2, #0xc6
	ldr r3, _08033204 @ =0x0000087C
	adds r1, r5, r3
	movs r3, #0
	strb r0, [r1]
	ldr r4, _08033208 @ =0x0000087A
	adds r0, r5, r4
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _08033210
	ldr r0, _0803320C @ =0x00000878
	adds r1, r5, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _08033226
	.align 2, 0
_08033204: .4byte 0x0000087C
_08033208: .4byte 0x0000087A
_0803320C: .4byte 0x00000878
_08033210:
	cmp r0, #0
	bne _08033220
	ldr r1, _0803321C @ =0x00000878
	adds r0, r5, r1
	b _08033224
	.align 2, 0
_0803321C: .4byte 0x00000878
_08033220:
	ldr r2, _08033264 @ =0x00000878
	adds r0, r5, r2
_08033224:
	strh r3, [r0]
_08033226:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x60
	bls _08033310
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803326C
	ldr r1, _08033268 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x49
	cmp r0, #0
	bne _0803327C
	movs r3, #0x48
	b _0803327C
	.align 2, 0
_08033264: .4byte 0x00000878
_08033268: .4byte 0x00000824
_0803326C:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x48
	cmp r0, #0
	beq _0803327C
	movs r3, #0x49
_0803327C:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r6, #0
	bl FUN_08022da8
	adds r0, r5, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _080332B0
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r3, #0x84
	lsls r3, r3, #3
	adds r0, r5, r3
	b _080332BE
_080332B0:
	ldr r0, _080332D0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r4, #0xcf
	lsls r4, r4, #2
	adds r1, r5, r4
_080332BE:
	str r0, [r1]
	adds r0, r1, #0
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r0, [r0]
	str r0, [r1]
	b _08033310
	.align 2, 0
_080332D0: .4byte 0x03003584
_080332D4:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _080332E6
	ldr r0, _08033318 @ =0x0000033A
	bl PlaySound_082406e0
_080332E6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x80
	bls _08033310
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r4]
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r6, #0
	bl FUN_08023024
_08033310:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033318: .4byte 0x0000033A

	thumb_func_start FUN_0803331c
FUN_0803331c: @ 0x0803331C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803332E
	movs r0, #0
	strb r0, [r1]
_0803332E:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _08033380 @ =0x00000167
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, #0x1c
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0803339E
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #3
	ble _08033384
	subs r0, r2, #4
	strh r0, [r1]
	b _08033386
	.align 2, 0
_08033380: .4byte 0x00000167
_08033384:
	strh r3, [r1]
_08033386:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0803339A
	subs r0, r2, #4
	b _0803339C
_0803339A:
	movs r0, #0
_0803339C:
	strh r0, [r1]
_0803339E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080333a4
FUN_080333a4: @ 0x080333A4
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803343E
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033414
	ldr r3, _08033410 @ =0x00000824
	adds r0, r4, r3
	ldr r0, [r0]
	movs r3, #0x4c
	cmp r0, #0
	bne _08033424
	movs r3, #0x4a
	b _08033424
	.align 2, 0
_08033410: .4byte 0x00000824
_08033414:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x4a
	cmp r0, #0
	beq _08033424
	movs r3, #0x4c
_08033424:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022c9c
_0803343E:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	subs r3, #0x19
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080334AA
	movs r5, #0xb1
	lsls r5, r5, #1
	adds r1, r4, r5
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #3
	ble _08033490
	subs r0, r2, #4
	strh r0, [r1]
	b _08033492
_08033490:
	strh r3, [r1]
_08033492:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _080334A6
	subs r0, r2, #4
	b _080334A8
_080334A6:
	movs r0, #0
_080334A8:
	strh r0, [r1]
_080334AA:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080334b4
FUN_080334b4: @ 0x080334B4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r5, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803354E
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033524
	ldr r2, _08033520 @ =0x00000824
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _08033534
	movs r3, #0
	b _08033534
	.align 2, 0
_08033520: .4byte 0x00000824
_08033524:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _08033534
	movs r3, #5
_08033534:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022d24
_0803354E:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r1, _080335BC @ =0x00000167
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080335E0
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803359C
	adds r0, r2, #2
	strh r0, [r3]
_0803359C:
	ldr r2, _080335C0 @ =0x085B0A08
	lsls r0, r6, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080335C4
	asrs r1, r0, #0xc
	b _080335CA
	.align 2, 0
_080335BC: .4byte 0x00000167
_080335C0: .4byte 0x085B0A08
_080335C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080335CA:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r4, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080335E0
	movs r0, #0
	strh r0, [r1]
_080335E0:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080335e8
FUN_080335e8: @ 0x080335E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r6, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033660
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033628
	ldr r1, _08033624 @ =0x00000824
	adds r0, r6, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _08033638
	movs r3, #0
	b _08033638
	.align 2, 0
_08033624: .4byte 0x00000824
_08033628:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _08033638
	movs r3, #5
_08033638:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_08022d24
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08029a1c
_08033660:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r1, _080336D0 @ =0x00000167
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803369A
	b _080337AA
_0803369A:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _080336B0
	adds r0, r2, #2
	strh r0, [r3]
_080336B0:
	ldr r2, _080336D4 @ =0x085B0A08
	lsls r0, r5, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080336D8
	asrs r1, r0, #0xc
	b _080336DE
	.align 2, 0
_080336D0: .4byte 0x00000167
_080336D4: .4byte 0x085B0A08
_080336D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080336DE:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r4, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080336F4
	movs r0, #0
	strh r0, [r1]
_080336F4:
	ldr r1, _08033750 @ =0x000008E4
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _08033708
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
_08033708:
	ldr r2, _08033754 @ =0x0000084C
	adds r5, r4, r2
	movs r3, #0
	ldrsh r0, [r5, r3]
	mov r4, r8
	movs r2, #8
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r5, r3]
	movs r3, #0xc
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r2, r1, #0
	muls r2, r1, r2
	adds r4, r4, r2
	bl FUN_0823785c
	adds r7, r0, #0
	movs r0, #0xe1
	lsls r0, r0, #2
	cmp r4, r0
	bgt _08033758
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	mov r4, r8
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	b _080337AA
	.align 2, 0
_08033750: .4byte 0x000008E4
_08033754: .4byte 0x0000084C
_08033758:
	mov r3, r8
	adds r3, #0x10
	movs r4, #0x14
	ldr r2, _0803377C @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08033780
	asrs r1, r0, #0xc
	b _08033786
	.align 2, 0
_0803377C: .4byte 0x085B0A08
_08033780:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08033786:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080337A2
	asrs r0, r0, #0xc
	b _080337A8
_080337A2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080337A8:
	strh r0, [r3, #4]
_080337AA:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080337b8
FUN_080337b8: @ 0x080337B8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r4, #0
	adds r6, r4, #0
	adds r6, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803381C
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080337F0
	ldr r1, _080337EC @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x4c
	cmp r0, #0
	bne _08033800
	movs r3, #0x4a
	b _08033800
	.align 2, 0
_080337EC: .4byte 0x00000824
_080337F0:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r3, #0x4a
	cmp r0, #0
	beq _08033800
	movs r3, #0x4c
_08033800:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022c9c
	b _08033864
_0803381C:
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803383C
	ldr r1, _08033838 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x4c
	cmp r0, #0
	bne _0803384C
	movs r3, #0x4a
	b _0803384C
	.align 2, 0
_08033838: .4byte 0x00000824
_0803383C:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r3, #0x4a
	cmp r0, #0
	beq _0803384C
	movs r3, #0x4c
_0803384C:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022c9c
_08033864:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	subs r3, #0x19
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033966
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrb r0, [r6, #5]
	ldrb r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #0
	bge _080338B6
	rsbs r1, r0, #0
_080338B6:
	cmp r1, #7
	bgt _080338F8
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08033936
_080338F8:
	cmp r0, #0
	bge _08033902
	ldrb r0, [r6, #5]
	adds r0, #8
	b _08033906
_08033902:
	ldrb r0, [r6, #5]
	subs r0, #8
_08033906:
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
_08033936:
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0803394A
	subs r0, r2, #4
	b _0803394C
_0803394A:
	movs r0, #0
_0803394C:
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08033962
	subs r0, r2, #4
	b _08033964
_08033962:
	movs r0, #0
_08033964:
	strh r0, [r1]
_08033966:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08033970
FUN_08033970: @ 0x08033970
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r4, #0
	adds r6, r4, #0
	adds r6, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080339D4
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080339A8
	ldr r1, _080339A4 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _080339B8
	movs r3, #0
	b _080339B8
	.align 2, 0
_080339A4: .4byte 0x00000824
_080339A8:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _080339B8
	movs r3, #5
_080339B8:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022d24
	b _08033A1C
_080339D4:
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080339F4
	ldr r1, _080339F0 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _08033A04
	movs r3, #0
	b _08033A04
	.align 2, 0
_080339F0: .4byte 0x00000824
_080339F4:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _08033A04
	movs r3, #5
_08033A04:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022d24
_08033A1C:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	subs r3, #0x19
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033B1E
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrb r0, [r6, #5]
	ldrb r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #0
	bge _08033A6E
	rsbs r1, r0, #0
_08033A6E:
	cmp r1, #7
	bgt _08033AB0
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08033AEE
_08033AB0:
	cmp r0, #0
	bge _08033ABA
	ldrb r0, [r6, #5]
	adds r0, #8
	b _08033ABE
_08033ABA:
	ldrb r0, [r6, #5]
	subs r0, #8
_08033ABE:
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
_08033AEE:
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08033B02
	subs r0, r2, #4
	b _08033B04
_08033B02:
	movs r0, #0
_08033B04:
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08033B1A
	subs r0, r2, #4
	b _08033B1C
_08033B1A:
	movs r0, #0
_08033B1C:
	strh r0, [r1]
_08033B1E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08033b28
FUN_08033b28: @ 0x08033B28
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r7, r4, #0
	adds r7, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033BA6
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033B64
	ldr r1, _08033B60 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _08033B74
	movs r3, #0
	b _08033B74
	.align 2, 0
_08033B60: .4byte 0x00000824
_08033B64:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _08033B74
	movs r3, #5
_08033B74:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
	movs r2, #0x10
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, r4, #0
	adds r2, #0xcc
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_08033BA6:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08033BFC @ =0x0001000C
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033C56
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #8]
	str r1, [r7, #0xc]
	cmp r6, #0x1f
	ble _08033C00
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08033C56
	.align 2, 0
_08033BFC: .4byte 0x0001000C
_08033C00:
	movs r1, #3
	bics r1, r6
	movs r0, #0x20
	subs r0, r0, r6
	adds r4, r7, #0
	adds r4, #0x10
	lsls r5, r1, #6
	lsls r6, r0, #3
	ldr r2, _08033C2C @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08033C30
	asrs r3, r0, #0xc
	b _08033C36
	.align 2, 0
_08033C2C: .4byte 0x085B0A08
_08033C30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08033C36:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08033C4E
	asrs r0, r0, #0xc
	b _08033C54
_08033C4E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08033C54:
	strh r0, [r4, #4]
_08033C56:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08033c60
FUN_08033c60: @ 0x08033C60
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r5, r4, #0
	adds r6, r4, #0
	adds r6, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033CD2
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033C9C
	ldr r1, _08033C98 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #5
	cmp r0, #0
	bne _08033CAC
	movs r3, #0
	b _08033CAC
	.align 2, 0
_08033C98: .4byte 0x00000824
_08033C9C:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _08033CAC
	movs r3, #5
_08033CAC:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
	adds r2, r4, #0
	adds r2, #0xcc
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_08033CD2:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08033D40 @ =0x0001000C
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033D7A
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	movs r0, #3
	ands r0, r7
	adds r3, r6, #0
	adds r3, #0x10
	lsls r5, r0, #6
	lsls r6, r7, #3
	ldr r2, _08033D44 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08033D48
	asrs r1, r0, #0xc
	b _08033D4E
	.align 2, 0
_08033D40: .4byte 0x0001000C
_08033D44: .4byte 0x085B0A08
_08033D48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08033D4E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08033D66
	asrs r0, r0, #0xc
	b _08033D6C
_08033D66:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08033D6C:
	strh r0, [r3, #4]
	cmp r7, #0x1f
	ble _08033D7A
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08033D7A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08033d84
FUN_08033d84: @ 0x08033D84
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r4, #0
	adds r6, r4, #0
	adds r6, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033DF2
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033DBC
	ldr r1, _08033DB8 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0xe
	cmp r0, #0
	bne _08033DCC
	movs r3, #0xa
	b _08033DCC
	.align 2, 0
_08033DB8: .4byte 0x00000824
_08033DBC:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0xa
	cmp r0, #0
	beq _08033DCC
	movs r3, #0xe
_08033DCC:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022c9c
	adds r2, r5, #0
	adds r2, #0xcc
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_08033DF2:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033E34
	movs r0, #4
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
_08033E34:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08033e3c
FUN_08033e3c: @ 0x08033E3C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r5, r4, #0
	adds r6, r4, #0
	adds r6, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033F08
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x50
	adds r0, r0, r4
	mov ip, r0
	ldr r1, _08033ED0 @ =0x0000084C
	adds r2, r4, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #8
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	mov r2, ip
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033ED8
	ldr r3, _08033ED4 @ =0x00000824
	adds r0, r4, r3
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _08033EE8
	movs r3, #0x1a
	b _08033EE8
	.align 2, 0
_08033ED0: .4byte 0x0000084C
_08033ED4: .4byte 0x00000824
_08033ED8:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _08033EE8
	movs r3, #0x1f
_08033EE8:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
	b _08033F52
_08033F08:
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033F28
	ldr r1, _08033F24 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _08033F38
	movs r3, #0x1a
	b _08033F38
	.align 2, 0
_08033F24: .4byte 0x00000824
_08033F28:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _08033F38
	movs r3, #0x1f
_08033F38:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
_08033F52:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, _08033FB8 @ =0x00000167
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034008
	cmp r7, #0x3f
	bgt _08033FEA
	movs r0, #0x40
	subs r0, r0, r7
	asrs r0, r0, #3
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r5, [r6, #5]
	rsbs r6, r0, #0
	ldr r2, _08033FBC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08033FC0
	asrs r1, r0, #0xc
	b _08033FC6
	.align 2, 0
_08033FB8: .4byte 0x00000167
_08033FBC: .4byte 0x085B0A08
_08033FC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08033FC6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08033FDE
	asrs r0, r0, #0xc
	b _08033FE4
_08033FDE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08033FE4:
	strh r0, [r3, #4]
	cmp r7, #0x3f
	ble _08034008
_08033FEA:
	ldr r2, _08034010 @ =FUN_08034014
	movs r0, #0x2d
	adds r3, r4, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08034008:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034010: .4byte FUN_08034014

	thumb_func_start FUN_08034014
FUN_08034014: @ 0x08034014
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r1, #0
	adds r4, r5, #0
	adds r6, r5, #0
	adds r6, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08034080
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034050
	ldr r1, _0803404C @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x28
	cmp r0, #0
	bne _08034060
	movs r3, #0x24
	b _08034060
	.align 2, 0
_0803404C: .4byte 0x00000824
_08034050:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x24
	cmp r0, #0
	beq _08034060
	movs r3, #0x28
_08034060:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022c9c
	ldr r0, _080340DC @ =0x0000034A
	bl PlaySound_0824078c
_08034080:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034192
	ldr r1, _080340E0 @ =0x000008E4
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #3
	bls _080340EE
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080340E4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
	b _080340EE
	.align 2, 0
_080340DC: .4byte 0x0000034A
_080340E0: .4byte 0x000008E4
_080340E4:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08028838
_080340EE:
	ldr r0, _0803412C @ =0x0000084C
	adds r3, r4, r0
	movs r1, #0
	ldrsh r2, [r3, r1]
	movs r4, #8
	ldrsh r0, [r6, r4]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r3, r1]
	movs r4, #0xc
	ldrsh r1, [r6, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08034130 @ =0x0000063F
	cmp r1, r0
	bgt _08034134
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08034182
	.align 2, 0
_0803412C: .4byte 0x0000084C
_08034130: .4byte 0x0000063F
_08034134:
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r4, [r6, #5]
	movs r6, #0x28
	ldr r2, _08034158 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803415C
	asrs r1, r0, #0xc
	b _08034162
	.align 2, 0
_08034158: .4byte 0x085B0A08
_0803415C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08034162:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803417A
	asrs r0, r0, #0xc
	b _08034180
_0803417A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08034180:
	strh r0, [r3, #4]
_08034182:
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r7, r0
	bne _08034192
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08034192:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803419c
FUN_0803419c: @ 0x0803419C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08034200
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080341D0
	ldr r1, _080341CC @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x29
	cmp r0, #0
	bne _080341E0
	movs r3, #0x25
	b _080341E0
	.align 2, 0
_080341CC: .4byte 0x00000824
_080341D0:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x25
	cmp r0, #0
	beq _080341E0
	movs r3, #0x29
_080341E0:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_08022c9c
	ldr r0, _08034274 @ =0x0000034B
	bl PlaySound_0824078c
_08034200:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	movs r1, #0xc
	adds r4, r5, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r1, #0xf4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803426A
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08034254
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08034254:
	ldr r1, _08034278 @ =0x00000311
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803426A
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803426A:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034274: .4byte 0x0000034B
_08034278: .4byte 0x00000311

	thumb_func_start FUN_0803427c
FUN_0803427c: @ 0x0803427C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r1
	adds r5, r4, #0
	adds r6, r4, #0
	adds r6, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803434A
	movs r0, #0
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x50
	ldr r0, _08034314 @ =0x0000084C
	adds r2, r4, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r7, #8
	ldrsh r1, [r6, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r2, r7]
	movs r7, #4
	ldrsh r2, [r3, r7]
	subs r1, r1, r2
	bl FUN_0823785c
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r0, #0x80
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803431C
	ldr r7, _08034318 @ =0x00000824
	adds r0, r4, r7
	ldr r0, [r0]
	movs r3, #0x1f
	cmp r0, #0
	bne _0803432C
	movs r3, #0x1a
	b _0803432C
	.align 2, 0
_08034314: .4byte 0x0000084C
_08034318: .4byte 0x00000824
_0803431C:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x1a
	cmp r0, #0
	beq _0803432C
	movs r3, #0x1f
_0803432C:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r7, #0xb5
	lsls r7, r7, #2
	adds r2, r5, r7
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl FUN_08022d24
_0803434A:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	ldr r7, _080343A4 @ =0x00000167
	adds r0, r5, r7
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803445E
	ldr r2, _080343A8 @ =0x000008E4
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #3
	bls _080343B6
	adds r7, #0xb
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _080343AC
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08028838
	b _080343B6
	.align 2, 0
_080343A4: .4byte 0x00000167
_080343A8: .4byte 0x000008E4
_080343AC:
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08028838
_080343B6:
	ldr r0, _080343F4 @ =0x0000084C
	adds r3, r5, r0
	movs r1, #0
	ldrsh r2, [r3, r1]
	movs r5, #8
	ldrsh r0, [r6, r5]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r3, r7]
	movs r5, #0xc
	ldrsh r1, [r6, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	ldr r0, _080343F8 @ =0x0000063F
	cmp r1, r0
	bgt _080343FC
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _0803444E
	.align 2, 0
_080343F4: .4byte 0x0000084C
_080343F8: .4byte 0x0000063F
_080343FC:
	adds r3, r6, #0
	adds r3, #0x10
	ldrb r5, [r6, #5]
	movs r6, #0x28
	rsbs r6, r6, #0
	ldr r2, _08034424 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08034428
	asrs r1, r0, #0xc
	b _0803442E
	.align 2, 0
_08034424: .4byte 0x085B0A08
_08034428:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803442E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08034446
	asrs r0, r0, #0xc
	b _0803444C
_08034446:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803444C:
	strh r0, [r3, #4]
_0803444E:
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r8, r0
	bne _0803445E
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803445E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803446c
FUN_0803446c: @ 0x0803446C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080344DE
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r6, #0xb5
	lsls r6, r6, #2
	adds r2, r4, r6
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x3a
	bl FUN_08022c9c
_080344DE:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _08034530 @ =0x00000167
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08034564
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #3
	ble _08034534
	subs r0, r2, #4
	strh r0, [r1]
	b _08034536
	.align 2, 0
_08034530: .4byte 0x00000167
_08034534:
	strh r3, [r1]
_08034536:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _0803454A
	subs r0, r2, #4
	b _0803454C
_0803454A:
	movs r0, #0
_0803454C:
	strh r0, [r1]
	ldr r6, _0803456C @ =0x00000311
	adds r0, r5, r6
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08034564
	adds r0, r4, #0
	adds r0, #0xa7
	strb r2, [r0]
_08034564:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803456C: .4byte 0x00000311

	thumb_func_start FUN_08034570
FUN_08034570: @ 0x08034570
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r7, r5, #0
	adds r7, #0x48
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080345BA
	movs r4, #0
	strb r4, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x3b
	bl FUN_08022c9c
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
_080345BA:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r4, #0xb3
	lsls r4, r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, _08034608 @ =0x00000167
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080346BA
	subs r4, #4
	adds r1, r5, r4
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #3
	ble _0803460C
	subs r0, r2, #4
	strh r0, [r1]
	b _0803460E
	.align 2, 0
_08034608: .4byte 0x00000167
_0803460C:
	strh r3, [r1]
_0803460E:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08034622
	subs r0, r2, #4
	b _08034624
_08034622:
	movs r0, #0
_08034624:
	strh r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r2, [r4]
	cmp r2, #0
	beq _08034638
	cmp r2, #1
	beq _0803466C
	b _08034686
_08034638:
	ldr r1, _08034668 @ =0x00000311
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08034686
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	str r3, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0x3c
	bl FUN_08022c9c
	b _08034680
	.align 2, 0
_08034668: .4byte 0x00000311
_0803466C:
	ldr r1, _080346C4 @ =0x00000311
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08034686
	adds r0, r6, #0
	adds r0, #0xa7
	strb r2, [r0]
_08034680:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_08034686:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080346BA
	movs r3, #0xc2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #1
	bne _080346BA
	movs r4, #0xc0
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _080346BA
	ldrb r1, [r7, #5]
	ldr r2, _080346C8 @ =0x000008DA
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080292c8
_080346BA:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080346C4: .4byte 0x00000311
_080346C8: .4byte 0x000008DA

	thumb_func_start FUN_080346cc
FUN_080346cc: @ 0x080346CC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08034754
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x20
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	movs r2, #0xff
	movs r1, #2
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034724
	ldr r1, _08034720 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x16
	cmp r0, #0
	bne _08034734
	movs r3, #0x12
	b _08034734
	.align 2, 0
_08034720: .4byte 0x00000824
_08034724:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x12
	cmp r0, #0
	beq _08034734
	movs r3, #0x16
_08034734:
	movs r6, #0xbd
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_08022da8
	ldr r0, _080347A8 @ =0x00000355
	bl PlaySound_0824078c
_08034754:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r6, _080347AC @ =0x00000167
	adds r0, r4, r6
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080347F6
	movs r2, #0xb1
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r2, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #3
	ble _080347B0
	subs r0, r2, #4
	strh r0, [r1]
	b _080347B2
	.align 2, 0
_080347A8: .4byte 0x00000355
_080347AC: .4byte 0x00000167
_080347B0:
	strh r3, [r1]
_080347B2:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _080347C6
	subs r0, r2, #4
	b _080347C8
_080347C6:
	movs r0, #0
_080347C8:
	strh r0, [r1]
	movs r0, #8
	movs r6, #0xc5
	lsls r6, r6, #1
	adds r1, r4, r6
	strb r0, [r1]
	ldr r1, _08034800 @ =0x00000311
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080347F6
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080347F6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034800: .4byte 0x00000311

	thumb_func_start FUN_08034804
FUN_08034804: @ 0x08034804
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803486C
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034838
	ldr r1, _08034834 @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x49
	cmp r0, #0
	bne _08034848
	movs r3, #0x48
	b _08034848
	.align 2, 0
_08034834: .4byte 0x00000824
_08034838:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r0, [r0]
	movs r3, #0x48
	cmp r0, #0
	beq _08034848
	movs r3, #0x49
_08034848:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	bl FUN_08022c34
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
_0803486C:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _080348BC @ =0x00000167
	adds r0, r5, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r4, #0x80
	adds r0, r6, r4
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08034954
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #3
	ble _080348C0
	subs r0, r2, #4
	strh r0, [r1]
	b _080348C2
	.align 2, 0
_080348BC: .4byte 0x00000167
_080348C0:
	strh r3, [r1]
_080348C2:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _080348D6
	subs r0, r2, #4
	b _080348D8
_080348D6:
	movs r0, #0
_080348D8:
	strh r0, [r1]
	ldr r4, _08034910 @ =0x00000311
	adds r0, r5, r4
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08034954
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08034954
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034918
	ldr r3, _08034914 @ =0x00000824
	adds r0, r5, r3
	ldr r0, [r0]
	movs r3, #0x52
	cmp r0, #0
	bne _08034928
	movs r3, #0x51
	b _08034928
	.align 2, 0
_08034910: .4byte 0x00000311
_08034914: .4byte 0x00000824
_08034918:
	movs r4, #0x82
	lsls r4, r4, #4
	adds r0, r5, r4
	ldr r0, [r0]
	movs r3, #0x51
	cmp r0, #0
	beq _08034928
	movs r3, #0x52
_08034928:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r2, r5, r4
	movs r4, #1
	str r4, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	bl FUN_08022c34
	adds r0, r6, #0
	adds r0, #0xa7
	strb r4, [r0]
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08034954:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803495c
FUN_0803495c: @ 0x0803495C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080349B8
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034990
	ldr r1, _0803498C @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x52
	cmp r0, #0
	bne _080349A0
	movs r3, #0x51
	b _080349A0
	.align 2, 0
_0803498C: .4byte 0x00000824
_08034990:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r3, #0x51
	cmp r0, #0
	beq _080349A0
	movs r3, #0x52
_080349A0:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_08022c34
_080349B8:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	subs r3, #0x19
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08034A24
	movs r5, #0xb1
	lsls r5, r5, #1
	adds r1, r4, r5
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #3
	ble _08034A0A
	subs r0, r2, #4
	strh r0, [r1]
	b _08034A0C
_08034A0A:
	strh r3, [r1]
_08034A0C:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08034A20
	subs r0, r2, #4
	b _08034A22
_08034A20:
	movs r0, #0
_08034A22:
	strh r0, [r1]
_08034A24:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08034a2c
FUN_08034a2c: @ 0x08034A2C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08034A8A
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034A60
	ldr r1, _08034A5C @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x54
	cmp r0, #0
	bne _08034A70
	movs r3, #0x52
	b _08034A70
	.align 2, 0
_08034A5C: .4byte 0x00000824
_08034A60:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r3, #0x52
	cmp r0, #0
	beq _08034A70
	movs r3, #0x54
_08034A70:
	movs r6, #0xbd
	lsls r6, r6, #2
	adds r1, r5, r6
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022c34
_08034A8A:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r6, #0xb3
	lsls r6, r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08034AD8 @ =0x00000167
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r3, #0x80
	adds r0, r4, r3
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08034B0C
	subs r6, #4
	adds r1, r5, r6
	ldrh r2, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #3
	ble _08034ADC
	subs r0, r2, #4
	strh r0, [r1]
	b _08034ADE
	.align 2, 0
_08034AD8: .4byte 0x00000167
_08034ADC:
	strh r3, [r1]
_08034ADE:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08034AF2
	subs r0, r2, #4
	b _08034AF4
_08034AF2:
	movs r0, #0
_08034AF4:
	strh r0, [r1]
	ldr r6, _08034B14 @ =0x00000311
	adds r0, r5, r6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08034B0C
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08034B0C:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034B14: .4byte 0x00000311

	thumb_func_start FUN_08034b18
FUN_08034b18: @ 0x08034B18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r6, r0, #0
	mov r8, r6
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	bne _08034B34
	b _08034D70
_08034B34:
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x57
	bl FUN_08022c34
	mov sb, r6
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r1, r1, r6
	mov sl, r1
	movs r2, #0xa4
	lsls r2, r2, #4
	adds r5, r6, r2
	adds r0, r6, #0
	bl FUN_08028ec8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0xa2
	lsls r0, r0, #4
	adds r1, r6, r0
	str r4, [sp]
	adds r0, r5, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r6, #0
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _08034B8E
	ldr r0, [r5, #8]
	orrs r0, r4
	b _08034B96
_08034B8E:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08034B96:
	str r0, [r5, #8]
	ldr r3, _08034BEC @ =0x00000173
	add r3, r8
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _08034BF0 @ =0x00000A18
	add r2, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	mov r2, sl
	ldr r0, [r2, #0x20]
	ldr r1, [r2, #0x24]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r7, r5, #0
	adds r7, #0x20
	add r0, sp, #0x14
	mov ip, r0
	add r0, sp, #0x14
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	mov r1, ip
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	str r3, [sp, #0x24]
	cmp r0, #0
	blt _08034BF4
	asrs r0, r0, #8
	b _08034BFA
	.align 2, 0
_08034BEC: .4byte 0x00000173
_08034BF0: .4byte 0x00000A18
_08034BF4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08034BFA:
	strh r0, [r7]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08034C0C
	asrs r0, r0, #8
	b _08034C12
_08034C0C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08034C12:
	adds r4, r0, #0
	mov r2, ip
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08034C28
	asrs r0, r0, #8
	b _08034C2E
_08034C28:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08034C2E:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08034C70 @ =0x030047C8
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
	mov r0, sb
	adds r0, #0xaf
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _08034C78
	ldr r0, _08034C74 @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r5, #0x20]
	adds r1, r1, r2
	strh r1, [r5, #0x20]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r5, #0x22]
	adds r0, r0, r1
	b _08034C8C
	.align 2, 0
_08034C70: .4byte 0x030047C8
_08034C74: .4byte 0x085AABBC
_08034C78:
	ldr r2, _08034CBC @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrh r0, [r5, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	movs r0, #1
	ldrsb r0, [r2, r0]
	ldrh r2, [r5, #0x22]
	adds r0, r0, r2
_08034C8C:
	strh r0, [r5, #0x22]
	ldr r0, [r5, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
	ldr r1, _08034CC0 @ =0x00000A14
	add r1, r8
	ldr r0, _08034CC4 @ =0x0000FFFF
	strh r0, [r1]
	mov r0, sl
	ldrh r1, [r0, #0x14]
	ldr r0, _08034CC8 @ =0x00000A16
	add r0, r8
	strh r1, [r0]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08034CD0
	ldr r3, _08034CCC @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	movs r1, #0x20
	b _08034CD8
	.align 2, 0
_08034CBC: .4byte 0x085AABBC
_08034CC0: .4byte 0x00000A14
_08034CC4: .4byte 0x0000FFFF
_08034CC8: .4byte 0x00000A16
_08034CCC: .4byte 0xFFFF0000
_08034CD0:
	ldr r3, _08034D50 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	ldr r1, _08034D54 @ =0x0000FFE0
_08034CD8:
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r2, sp, #0x1c
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r1, _08034D58 @ =0x0000FFFF
	ldr r0, [sp, #0x1c]
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	adds r4, r2, #0
	mov r0, sb
	adds r0, #0xab
	ldrb r3, [r0]
	cmp r3, #0
	bne _08034D28
	ldr r1, [sp, #0x24]
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _08034D5C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, sl
	adds r1, #0x20
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	adds r2, r4, #0
	movs r3, #0
	bl FUN_0807ab64
_08034D28:
	movs r0, #0x84
	lsls r0, r0, #7
	strh r0, [r5, #0x3a]
	ldr r2, [sp, #0x24]
	movs r0, #0
	ldrsb r0, [r2, r0]
	ldr r1, _08034D5C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r1, _08034D60 @ =0x00000359
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08034D64
	adds r0, r3, #0
	adds r0, #0xd0
	ldr r0, [r0]
	b _08034D6E
	.align 2, 0
_08034D50: .4byte 0xFFFF0000
_08034D54: .4byte 0x0000FFE0
_08034D58: .4byte 0x0000FFFF
_08034D5C: .4byte 0x03002BE0
_08034D60: .4byte 0x00000359
_08034D64:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
_08034D6E:
	str r0, [r5, #0x48]
_08034D70:
	movs r1, #0xc0
	lsls r1, r1, #1
	add r1, r8
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xb3
	lsls r0, r0, #1
	add r0, r8
	strb r2, [r0]
	ldr r0, _08034DD0 @ =0x00000167
	add r0, r8
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034DC0
	ldr r0, _08034DD4 @ =0x00000311
	add r0, r8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08034DC0
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08034DC0:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034DD0: .4byte 0x00000167
_08034DD4: .4byte 0x00000311

	thumb_func_start FUN_08034dd8
FUN_08034dd8: @ 0x08034DD8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08034E0A
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0x58
	bl FUN_08022c34
_08034E0A:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034EA4
	cmp r5, #5
	bne _08034E8E
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r5, [r0]
	ldr r2, _08034EAC @ =0x00000173
	adds r6, r4, r2
	cmp r5, #0
	bne _08034E8A
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _08034E8A
	ldr r1, _08034EB0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _08034EB4 @ =0x00000A18
	adds r1, r4, r2
	adds r2, r4, #0
	adds r2, #0x4d
	ldrb r3, [r2]
	movs r2, #0x32
	str r2, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	bl FUN_0807ac74
_08034E8A:
	movs r0, #0xff
	strb r0, [r6]
_08034E8E:
	ldr r1, _08034EB8 @ =0x00000311
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08034EA4
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08034EA4:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034EAC: .4byte 0x00000173
_08034EB0: .4byte 0x03002BE0
_08034EB4: .4byte 0x00000A18
_08034EB8: .4byte 0x00000311

	thumb_func_start FUN_08034ebc
FUN_08034ebc: @ 0x08034EBC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov r8, r6
	adds r2, r6, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	beq _08034F28
	movs r1, #0
	strb r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	subs r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _08034F74 @ =0x00000874
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x2f
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x30
	movs r3, #2
	bl FUN_082370cc
_08034F28:
	ldr r2, _08034F78 @ =0x0001000C
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034F7C
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	b _08035254
	.align 2, 0
_08034F74: .4byte 0x00000874
_08034F78: .4byte 0x0001000C
_08034F7C:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #5
	bls _08034F8A
	b _08035232
_08034F8A:
	lsls r0, r0, #2
	ldr r1, _08034F94 @ =_08034F98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08034F94: .4byte _08034F98
_08034F98: @ jump table
	.4byte _08034FB0 @ case 0
	.4byte _08034FF2 @ case 1
	.4byte _08035094 @ case 2
	.4byte _080350EC @ case 3
	.4byte _0803514A @ case 4
	.4byte _0803521C @ case 5
_08034FB0:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08034FC6
	b _08035232
_08034FC6:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	adds r2, r5, #0
	movs r3, #0x31
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x32
	b _080350D4
_08034FF2:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r7, r6, r0
	ldrh r0, [r7]
	adds r0, #1
	movs r1, #0
	mov sb, r1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _0803500C
	b _08035232
_0803500C:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	adds r2, r5, #0
	movs r3, #0x33
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x34
	movs r3, #2
	bl FUN_082370cc
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r7]
	ldr r0, _0803508C @ =0x00000173
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0803507A
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r2, _08035090 @ =0x00000876
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
_0803507A:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	b _08035232
	.align 2, 0
_0803508C: .4byte 0x00000173
_08035090: .4byte 0x00000876
_08035094:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r7, r6, r2
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080350AA
	b _08035232
_080350AA:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r5, r6, r2
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, r8
	adds r2, r5, #0
	movs r3, #0x35
	bl FUN_08022da8
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x36
_080350D4:
	movs r3, #2
	bl FUN_082370cc
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r7]
	b _08035232
_080350EC:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r6, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08035102
	b _08035232
_08035102:
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r4, r6, r1
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0x37
	bl FUN_08022da8
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r4, #8]
	orrs r0, r2
	str r0, [r4, #8]
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r5]
	b _08035232
_0803514A:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08035232
	ldr r1, _080351D8 @ =0x00000874
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _080351E8
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0x38
	bl FUN_08022da8
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r2, r6, r1
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r2, _080351DC @ =0x00000173
	adds r5, r6, r2
	cmp r4, #0
	bne _080351CC
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _080351CC
	adds r2, r0, #0
	ldr r1, _080351E0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #0xc8
	adds r1, r1, r2
	ldrb r3, [r1]
	ldr r2, _080351E4 @ =0x00000A18
	adds r1, r6, r2
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_080351CC:
	movs r0, #0xff
	strb r0, [r5]
	adds r0, #0x5f
	adds r1, r6, r0
	b _0803520A
	.align 2, 0
_080351D8: .4byte 0x00000874
_080351DC: .4byte 0x00000173
_080351E0: .4byte 0x03002BE0
_080351E4: .4byte 0x00000A18
_080351E8:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0x38
	bl FUN_08022da8
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
_0803520A:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	b _08035232
_0803521C:
	ldr r1, _08035264 @ =0x00000311
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08035232
	mov r1, r8
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08035232:
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r6, r2
	subs r2, #0x80
	adds r1, r6, r2
	bl FUN_082372cc
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_08035254:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035264: .4byte 0x00000311

	thumb_func_start FUN_08035268
FUN_08035268: @ 0x08035268
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803530A
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080352A0
	ldr r1, _0803529C @ =0x00000824
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0x16
	cmp r0, #0
	bne _080352B0
	movs r3, #0x12
	b _080352B0
	.align 2, 0
_0803529C: .4byte 0x00000824
_080352A0:
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x12
	cmp r0, #0
	beq _080352B0
	movs r3, #0x16
_080352B0:
	movs r7, #0xbd
	lsls r7, r7, #2
	adds r1, r4, r7
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_08022da8
	movs r3, #0
	movs r2, #0xca
	ldr r7, _080352EC @ =0x0000087C
	adds r1, r4, r7
	strb r3, [r1]
	subs r7, #2
	adds r0, r4, r7
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _080352F4
	ldr r0, _080352F0 @ =0x00000878
	adds r1, r4, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _0803530A
	.align 2, 0
_080352EC: .4byte 0x0000087C
_080352F0: .4byte 0x00000878
_080352F4:
	cmp r0, #0
	bne _08035304
	ldr r1, _08035300 @ =0x00000878
	adds r0, r4, r1
	b _08035308
	.align 2, 0
_08035300: .4byte 0x00000878
_08035304:
	ldr r2, _08035358 @ =0x00000878
	adds r0, r4, r2
_08035308:
	strh r3, [r0]
_0803530A:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r7, #0xb3
	lsls r7, r7, #1
	adds r0, r4, r7
	strb r2, [r0]
	ldr r1, _0803535C @ =0x00000167
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0803539E
	subs r7, #4
	adds r1, r4, r7
	ldrh r2, [r1]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #3
	ble _08035360
	subs r0, r2, #4
	strh r0, [r1]
	b _08035362
	.align 2, 0
_08035358: .4byte 0x00000878
_0803535C: .4byte 0x00000167
_08035360:
	strh r3, [r1]
_08035362:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08035376
	subs r0, r2, #4
	b _08035378
_08035376:
	movs r0, #0
_08035378:
	strh r0, [r1]
	movs r0, #8
	movs r7, #0xc5
	lsls r7, r7, #1
	adds r1, r4, r7
	strb r0, [r1]
	ldr r1, _080353A8 @ =0x00000311
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803539E
	cmp r6, #0x1f
	ble _0803539E
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803539E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080353A8: .4byte 0x00000311

	thumb_func_start FUN_080353ac
FUN_080353ac: @ 0x080353AC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803547E
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x20
	strb r1, [r0]
	adds r3, r5, #0
	adds r3, #0x4d
	strb r1, [r3]
	movs r2, #0xff
	movs r1, #2
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r0, #0xa
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035410
	ldr r2, _0803540C @ =0x00000824
	adds r0, r5, r2
	ldr r0, [r0]
	movs r3, #0x16
	cmp r0, #0
	bne _08035420
	movs r3, #0x12
	b _08035420
	.align 2, 0
_0803540C: .4byte 0x00000824
_08035410:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r0, [r0]
	movs r3, #0x12
	cmp r0, #0
	beq _08035420
	movs r3, #0x16
_08035420:
	movs r4, #0xbd
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	adds r0, r6, #0
	bl FUN_08022da8
	movs r2, #0xc6
	ldr r3, _0803545C @ =0x0000087C
	adds r1, r5, r3
	movs r3, #0
	strb r4, [r1]
	ldr r4, _08035460 @ =0x0000087A
	adds r0, r5, r4
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _08035468
	ldr r0, _08035464 @ =0x00000878
	adds r1, r5, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _0803547E
	.align 2, 0
_0803545C: .4byte 0x0000087C
_08035460: .4byte 0x0000087A
_08035464: .4byte 0x00000878
_08035468:
	cmp r0, #0
	bne _08035478
	ldr r1, _08035474 @ =0x00000878
	adds r0, r5, r1
	b _0803547C
	.align 2, 0
_08035474: .4byte 0x00000878
_08035478:
	ldr r2, _080354EC @ =0x00000878
	adds r0, r5, r2
_0803547C:
	strh r3, [r0]
_0803547E:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r4, #0xb3
	lsls r4, r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, _080354F0 @ =0x00000167
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08035580
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r2, [r0]
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _080354CC
	adds r0, r2, #2
	strh r0, [r3]
_080354CC:
	ldr r2, _080354F4 @ =0x085B0A08
	lsls r0, r7, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080354F8
	asrs r1, r0, #0xc
	b _080354FE
	.align 2, 0
_080354EC: .4byte 0x00000878
_080354F0: .4byte 0x00000167
_080354F4: .4byte 0x085B0A08
_080354F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080354FE:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08035514
	movs r0, #0
	strh r0, [r1]
_08035514:
	cmp r7, #0x3f
	bgt _08035522
	movs r0, #4
	movs r4, #0xc5
	lsls r4, r4, #1
	adds r1, r5, r4
	b _0803552E
_08035522:
	cmp r7, #0x7f
	bgt _08035530
	movs r0, #2
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r5, r2
_0803552E:
	strb r0, [r1]
_08035530:
	cmp r7, #0xa4
	bne _08035580
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	ldr r3, _08035560 @ =0x00000824
	adds r1, r5, r3
	movs r0, #2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _08035564
	movs r4, #0xcf
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r5, r2
	b _08035572
	.align 2, 0
_08035560: .4byte 0x00000824
_08035564:
	ldr r0, _08035588 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
_08035572:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r5, r4
	ldr r0, [r0]
	str r0, [r1]
_08035580:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035588: .4byte 0x03003584

	thumb_func_start FUN_0803558c
FUN_0803558c: @ 0x0803558C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080355BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0x55
	bl FUN_08022c34
_080355BC:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r1, r4, r5
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _0803560C @ =0x00000167
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r5, #0x80
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0803562A
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #3
	ble _08035610
	subs r0, r2, #4
	strh r0, [r1]
	b _08035612
	.align 2, 0
_0803560C: .4byte 0x00000167
_08035610:
	strh r3, [r1]
_08035612:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08035626
	subs r0, r2, #4
	b _08035628
_08035626:
	movs r0, #0
_08035628:
	strh r0, [r1]
_0803562A:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08035634
FUN_08035634: @ 0x08035634
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08035666
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0x56
	bl FUN_08022c34
_08035666:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r4, r6
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _080356B8 @ =0x00000167
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r6, #0x80
	adds r0, r4, r6
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080356EC
	movs r0, #0xb1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #3
	ble _080356BC
	subs r0, r2, #4
	strh r0, [r1]
	b _080356BE
	.align 2, 0
_080356B8: .4byte 0x00000167
_080356BC:
	strh r3, [r1]
_080356BE:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _080356D2
	subs r0, r2, #4
	b _080356D4
_080356D2:
	movs r0, #0
_080356D4:
	strh r0, [r1]
	ldr r6, _080356F4 @ =0x00000311
	adds r0, r5, r6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080356EC
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080356EC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080356F4: .4byte 0x00000311

	thumb_func_start FUN_080356f8
FUN_080356f8: @ 0x080356F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r5, #0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080357B2
	movs r0, #0
	strb r0, [r1]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035740
	ldr r7, _0803573C @ =0x00000824
	adds r0, r6, r7
	ldr r0, [r0]
	movs r3, #0x18
	cmp r0, #0
	bne _08035750
	movs r3, #0x14
	b _08035750
	.align 2, 0
_0803573C: .4byte 0x00000824
_08035740:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r3, #0x14
	cmp r0, #0
	beq _08035750
	movs r3, #0x18
_08035750:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r7, #0xb5
	lsls r7, r7, #2
	adds r2, r6, r7
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_08022da8
	movs r0, #6
	movs r2, #0xce
	ldr r3, _08035790 @ =0x0000087C
	adds r1, r6, r3
	movs r3, #0
	strb r0, [r1]
	ldr r7, _08035794 @ =0x0000087A
	adds r0, r6, r7
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0803579C
	ldr r0, _08035798 @ =0x00000878
	adds r1, r6, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _080357B2
	.align 2, 0
_08035790: .4byte 0x0000087C
_08035794: .4byte 0x0000087A
_08035798: .4byte 0x00000878
_0803579C:
	cmp r0, #0
	bne _080357AC
	ldr r1, _080357A8 @ =0x00000878
	adds r0, r6, r1
	b _080357B0
	.align 2, 0
_080357A8: .4byte 0x00000878
_080357AC:
	ldr r2, _08035820 @ =0x00000878
	adds r0, r6, r2
_080357B0:
	strh r3, [r0]
_080357B2:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r7, #0xb3
	lsls r7, r7, #1
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08035824 @ =0x00000167
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, #0xf4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080357EC
	b _08035A2A
_080357EC:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r2, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _08035802
	adds r0, r2, #2
	strh r0, [r3]
_08035802:
	ldr r2, _08035828 @ =0x085B0A08
	lsls r0, r4, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803582C
	asrs r1, r0, #0xc
	b _08035832
	.align 2, 0
_08035820: .4byte 0x00000878
_08035824: .4byte 0x00000167
_08035828: .4byte 0x085B0A08
_0803582C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08035832:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r7, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08035848
	strh r7, [r1]
_08035848:
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r4, r6, r0
	ldrh r2, [r4]
	cmp r2, #1
	beq _080358DA
	cmp r2, #1
	bgt _0803585E
	cmp r2, #0
	beq _08035864
	b _08035922
_0803585E:
	cmp r2, #2
	beq _08035918
	b _08035922
_08035864:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08035918
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035898
	ldr r3, _08035894 @ =0x00000824
	adds r0, r6, r3
	ldr r0, [r0]
	movs r3, #0x19
	cmp r0, #0
	bne _080358A8
	movs r3, #0x15
	b _080358A8
	.align 2, 0
_08035894: .4byte 0x00000824
_08035898:
	movs r7, #0x82
	lsls r7, r7, #4
	adds r0, r6, r7
	ldr r0, [r0]
	movs r3, #0x15
	cmp r0, #0
	beq _080358A8
	movs r3, #0x19
_080358A8:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r7, #0xb5
	lsls r7, r7, #2
	adds r2, r6, r7
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	bl FUN_08022da8
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	b _08035918
_080358DA:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb3
	bls _0803590A
	ldr r1, _08035914 @ =0x00000311
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803590A
	adds r0, r5, #0
	adds r0, #0xa7
	strb r2, [r0]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	strh r7, [r3]
_0803590A:
	movs r0, #4
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r6, r2
	b _08035920
	.align 2, 0
_08035914: .4byte 0x00000311
_08035918:
	movs r0, #4
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r6, r3
_08035920:
	strb r0, [r1]
_08035922:
	movs r7, #0xaf
	lsls r7, r7, #1
	adds r0, r6, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _08035944
	adds r0, r5, #0
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08035A2A
	adds r0, r6, #0
	bl FUN_08028cb0
	b _08035A2A
_08035944:
	adds r0, r5, #0
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08035A2A
	ldr r4, _0803599C @ =0x0203B400
	ldr r3, _080359A0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080359A4 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	mov ip, r5
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0x3f
	add r7, sp, #8
	adds r5, r1, #0
	ands r4, r0
	ldr r1, _080359A8 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _080359AC
	asrs r2, r0, #0xc
	b _080359B2
	.align 2, 0
_0803599C: .4byte 0x0203B400
_080359A0: .4byte 0x030046B8
_080359A4: .4byte 0x000003FF
_080359A8: .4byte 0x085B0A08
_080359AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080359B2:
	movs r0, #0
	strh r2, [r7]
	strh r0, [r7, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _080359CA
	asrs r0, r0, #0xc
	b _080359D0
_080359CA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080359D0:
	strh r0, [r7, #4]
	add r3, sp, #8
	movs r5, #0xc5
	lsls r5, r5, #2
	adds r2, r6, r5
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r7, [r3, #4]
	adds r0, r0, r7
	strh r0, [r3, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	strh r1, [r3, #2]
	ldr r3, _08035A34 @ =0x0203B400
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ldr r2, _08035A38 @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r1, #1
	ands r1, r2
	mov r5, ip
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r2, #0xf
	ands r1, r2
	adds r1, #0x10
	movs r2, #0x10
	add r3, sp, #8
	bl FUN_080604ec
_08035A2A:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035A34: .4byte 0x0203B400
_08035A38: .4byte 0x000003FF

	thumb_func_start FUN_08035a3c
FUN_08035a3c: @ 0x08035A3C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa7
	movs r0, #0
	strb r0, [r1]
	movs r1, #4
	ldr r0, _08035A60 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08035A5A
	adds r0, r2, #0
	bl FUN_08022f78
_08035A5A:
	pop {r0}
	bx r0
	.align 2, 0
_08035A60: .4byte 0x03002BC0

	thumb_func_start FUN_08035a64
FUN_08035a64: @ 0x08035A64
	push {lr}
	mov ip, r0
	mov r2, ip
	adds r2, #0xa2
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3d
	bhi _08035AA0
	ldr r1, _08035A9C @ =0x085AAD38
	ldrb r2, [r2]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	mov r0, ip
	adds r0, #0xa3
	movs r3, #0
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	mov r1, ip
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _08035AA2
	.align 2, 0
_08035A9C: .4byte 0x085AAD38
_08035AA0:
	movs r0, #0
_08035AA2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start PreDurathrorEvent_08035aa8
PreDurathrorEvent_08035aa8: @ 0x08035AA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r7, r0, #0
	mov sb, r7
	adds r0, #0x48
	str r0, [sp, #0x28]
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x2c]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r0, #0
	ldrsh r1, [r2, r0]
	str r1, [sp, #0x20]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r4, r7, r1
	ldrb r0, [r4]
	str r0, [sp, #0x24]
	adds r1, #1
	adds r3, r7, r1
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
	strb r1, [r4]
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x30]
	ldrh r0, [r2]
	cmp r0, #0
	beq _08035AF8
	b _08035C04
_08035AF8:
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08035B06
	b _08035C0A
_08035B06:
	adds r0, r7, #0
	bl FUN_080299e0
	cmp r0, #0
	beq _08035C0A
	ldr r0, _08035BE8 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08035BEC @ =0x00000942
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	adds r0, #0x92
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #5
	str r0, [sp, #0x20]
	ldr r3, _08035BF0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0xa4
	orrs r0, r2
	ldr r1, _08035BF4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	ldr r6, _08035BF8 @ =0x0203B400
	ldr r1, _08035BFC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r5, _08035C00 @ =0x000003FF
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r2, #3
	mov r8, r2
	ands r1, r2
	adds r1, #2
	adds r0, #1
	ands r0, r5
	ldr r2, _08035BFC @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #0x14
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sl, r2
	str r1, [sp]
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	movs r1, #3
	add r2, sp, #0x10
	bl FUN_080ddcc8
	ldr r1, _08035BFC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	mov r2, r8
	ands r1, r2
	adds r1, #2
	adds r0, #1
	ands r0, r5
	ldr r2, _08035BFC @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #0x14
	str r1, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	movs r1, #3
	add r2, sp, #0x10
	bl FUN_080ddcc8
	movs r0, #0x3c
	ldr r1, [sp, #0x30]
	strh r0, [r1]
	b _08035C0A
	.align 2, 0
_08035BE8: .4byte 0x030046A0
_08035BEC: .4byte 0x00000942
_08035BF0: .4byte 0xFFFF0000
_08035BF4: .4byte 0x0000FFFF
_08035BF8: .4byte 0x0203B400
_08035BFC: .4byte 0x030046B8
_08035C00: .4byte 0x000003FF
_08035C04:
	subs r0, #1
	ldr r2, [sp, #0x30]
	strh r0, [r2]
_08035C0A:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	bgt _08035C12
	b _08035E44
_08035C12:
	adds r1, r7, #0
	adds r1, #0x90
	ldrh r0, [r1]
	ldr r2, [sp, #0x20]
	subs r3, r0, r2
	strh r3, [r1]
	movs r0, #0
	mov sl, r0
	movs r0, #0x82
	lsls r0, r0, #4
	add r0, sb
	ldr r2, [r0]
	adds r4, r1, #0
	mov r8, r0
	cmp r2, #0
	beq _08035C88
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x11
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, r1
	bgt _08035C9C
	ldr r0, _08035C7C @ =0x00000FD4
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _08035C9C
	strh r1, [r4]
	adds r0, r7, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x13
	bne _08035C9C
	ldr r2, _08035C80 @ =0x00000FD8
	add r2, sb
	movs r0, #0xc5
	lsls r0, r0, #2
	add r0, sb
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _08035C84 @ =0x00000FD7
	add r1, sb
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #1
	mov sl, r0
	b _08035C9C
	.align 2, 0
_08035C7C: .4byte 0x00000FD4
_08035C80: .4byte 0x00000FD8
_08035C84: .4byte 0x00000FD7
_08035C88:
	adds r0, r7, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _08035C9C
	lsls r0, r3, #0x10
	cmp r0, #0
	bgt _08035C9C
	movs r0, #1
	strh r0, [r4]
_08035C9C:
	movs r1, #0xc4
	lsls r1, r1, #1
	add r1, sb
	movs r6, #0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #1
	add r1, sb
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #2
	add r0, sb
	movs r1, #0x84
	lsls r1, r1, #3
	add r1, sb
	str r1, [r0]
	movs r0, #0xe7
	lsls r0, r0, #2
	add r0, sb
	str r1, [r0]
	ldr r3, _08035D34 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08035D38 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldr r3, [sp, #0x28]
	adds r3, #8
	str r1, [sp]
	movs r5, #1
	str r5, [sp, #4]
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x20]
	movs r2, #0
	bl FUN_0805fe7c
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _08035D6C
	strh r6, [r4]
	movs r2, #2
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, r8
	ldr r0, [r2]
	cmp r0, #0
	beq _08035D44
	ldr r1, _08035D3C @ =dainn_08032f18
	movs r0, #0x22
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	adds r0, #0x1d
	strb r5, [r0]
	ldr r0, _08035D40 @ =0x000003CD
	bl PlaySound_0824078c
	b _08035E3C
	.align 2, 0
_08035D34: .4byte 0xFFFF0000
_08035D38: .4byte 0x0000FFFF
_08035D3C: .4byte dainn_08032f18
_08035D40: .4byte 0x000003CD
_08035D44:
	ldr r1, _08035D68 @ =FUN_08032e1c
	movs r0, #0x21
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	adds r0, #0x1d
	strb r5, [r0]
	movs r0, #0xd4
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _08035E3C
	.align 2, 0
_08035D68: .4byte FUN_08032e1c
_08035D6C:
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r7, #0
	adds r0, #0x98
	ldr r2, [r0]
	orrs r2, r1
	str r2, [r0]
	adds r4, r0, #0
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _08035D8A
	movs r0, #0x80
	lsls r0, r0, #0x10
	orrs r2, r0
	str r2, [r4]
_08035D8A:
	ldr r1, _08035DD4 @ =0x00000874
	add r1, sb
	ldrh r0, [r1]
	subs r0, #0x28
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08035D9C
	strh r6, [r1]
_08035D9C:
	movs r2, #0x87
	lsls r2, r2, #4
	add r2, sb
	ldrh r0, [r2]
	adds r0, #0x64
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _08035DD8 @ =0x02570000
	cmp r0, r1
	bls _08035DB6
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r2]
_08035DB6:
	movs r0, #8
	movs r1, #0xc5
	lsls r1, r1, #1
	add r1, sb
	strb r0, [r1]
	ldr r0, _08035DDC @ =0x00000FD4
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035DE0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_0824078c
	b _08035E14
	.align 2, 0
_08035DD4: .4byte 0x00000874
_08035DD8: .4byte 0x02570000
_08035DDC: .4byte 0x00000FD4
_08035DE0:
	adds r0, r7, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x13
	bne _08035E0C
	mov r1, r8
	ldr r0, [r1]
	cmp r0, #0
	beq _08035E00
	ldr r0, _08035DFC @ =0x0000030D
	bl PlaySound_0824078c
	b _08035E14
	.align 2, 0
_08035DFC: .4byte 0x0000030D
_08035E00:
	ldr r0, _08035E08 @ =0x0000034F
	bl PlaySound_0824078c
	b _08035E14
	.align 2, 0
_08035E08: .4byte 0x0000034F
_08035E0C:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08035E14:
	mov r2, sl
	cmp r2, #0
	beq _08035E44
	movs r3, #1
	ldr r0, [r4]
	orrs r0, r3
	str r0, [r4]
	ldr r2, _08035E40 @ =FUN_08032acc
	movs r0, #0x1f
	adds r4, r7, #0
	adds r4, #0xa3
	movs r1, #0
	strb r0, [r4]
	adds r0, r7, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
_08035E3C:
	movs r0, #1
	b _08035E46
	.align 2, 0
_08035E40: .4byte FUN_08032acc
_08035E44:
	movs r0, #0
_08035E46:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityBA4B_Update
EntityBA4B_Update: @ 0x08035E58
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0802ae4c
	adds r0, r4, #0
	bl FUN_0802e4fc
	adds r0, r4, #0
	bl FUN_08035a3c
	adds r0, r4, #0
	bl FUN_0802b074
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityBA4B_Destroy
EntityBA4B_Destroy: @ 0x08035E7C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
	adds r0, r4, #0
	bl FUN_08028054
	adds r0, r4, #0
	bl FUN_08028818
	adds r0, r4, #0
	bl FUN_08028eb8
	adds r0, r4, #0
	bl FUN_08029de0
	adds r0, r4, #0
	bl FUN_0802a2e0
	adds r0, r4, #0
	bl FUN_08029b30
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	adds r0, r4, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityBA4B_Init
EntityBA4B_Init: @ 0x08035ED0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r7
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x28]
	adds r0, r7, #0
	ldr r1, [sp, #0x28]
	bl FUN_08022a0c
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	movs r2, #0x82
	lsls r2, r2, #4
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, _08035F3C @ =0x00000824
	adds r1, r7, r3
	str r0, [r1]
	movs r0, #0x50
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r4, _08035F40 @ =0x0000016B
	adds r1, r7, r4
	strb r0, [r1]
	movs r4, #0
	cmp r4, r0
	bge _08035F58
	adds r3, r1, #0
	movs r5, #0x82
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r2, _08035F44 @ =0x03002BE0
_08035F30:
	ldr r0, [r2]
	cmp r0, #0
	beq _08035F48
	str r0, [r1]
	adds r0, #0x2c
	b _08035F4A
	.align 2, 0
_08035F3C: .4byte 0x00000824
_08035F40: .4byte 0x0000016B
_08035F44: .4byte 0x03002BE0
_08035F48:
	str r0, [r1]
_08035F4A:
	str r0, [r1, #8]
	adds r1, #4
	adds r2, #4
	adds r4, #1
	ldrb r6, [r3]
	cmp r4, r6
	blt _08035F30
_08035F58:
	ldr r0, _08035FCC @ =0x0000CB05
	ldr r1, _08035FD0 @ =0x0000D3DA
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _08035F6A
	bl _08036760
_08035F6A:
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08035FDC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08035FD4 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08035FD8 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	bl Script_GetValue
	adds r5, r0, #0
	b _08036004
	.align 2, 0
_08035FCC: .4byte 0x0000CB05
_08035FD0: .4byte 0x0000D3DA
_08035FD4: .4byte 0xFFFF0000
_08035FD8: .4byte 0x0000FFFF
_08035FDC:
	ldr r0, _08036070 @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _08036074 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _08036078 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x1c]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r5, #0x40
_08036004:
	ldr r0, [sp, #0x1c]
	asrs r0, r0, #0x10
	movs r6, #0xb2
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	ldr r0, _0803607C @ =0x00000868
	adds r4, r7, r0
	adds r0, r4, #0
	bl FUN_08084734
	ldr r1, _08036080 @ =0x00000844
	adds r2, r7, r1
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_08028604
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08036094
	bl Script_GetValue
	mov sl, r0
	bl Script_GetValue
	movs r2, #0x8a
	lsls r2, r2, #4
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08036084 @ =0x000008A2
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08036088 @ =0x000008A4
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r6, _0803608C @ =0x000008D2
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08036090 @ =0x000008D6
	adds r1, r7, r2
	b _080360C4
	.align 2, 0
_08036070: .4byte 0x030046A0
_08036074: .4byte 0xFFFF0000
_08036078: .4byte 0x0000FFFF
_0803607C: .4byte 0x00000868
_08036080: .4byte 0x00000844
_08036084: .4byte 0x000008A2
_08036088: .4byte 0x000008A4
_0803608C: .4byte 0x000008D2
_08036090: .4byte 0x000008D6
_08036094:
	movs r3, #0xfa
	lsls r3, r3, #2
	mov sl, r3
	movs r4, #0x8a
	lsls r4, r4, #4
	adds r1, r7, r4
	ldr r0, _08036154 @ =0x000003E7
	strh r0, [r1]
	ldr r6, _08036158 @ =0x000008A2
	adds r1, r7, r6
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _0803615C @ =0x000008A4
	adds r1, r7, r0
	movs r0, #0x64
	strh r0, [r1]
	ldr r2, _08036160 @ =0x000008D2
	adds r1, r7, r2
	adds r0, #0xc8
	strh r0, [r1]
	ldr r3, _08036164 @ =0x000008D6
	adds r1, r7, r3
	movs r0, #0x96
	lsls r0, r0, #2
_080360C4:
	strh r0, [r1]
	ldr r4, _08036168 @ =0x000008DB
	adds r2, r7, r4
	movs r0, #0x60
	strb r0, [r2]
	ldr r6, _0803616C @ =0x000008DC
	adds r1, r7, r6
	movs r0, #0x30
	strb r0, [r1]
	ldrb r0, [r2]
	movs r2, #0xbf
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08036180
	bl Script_GetValue
	ldr r3, _08036170 @ =0x000008A8
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	subs r4, #0x31
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	subs r6, #0x30
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08036174 @ =0x000008AE
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0x8b
	lsls r3, r3, #4
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #8
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r6, #0x18
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08036178 @ =0x000008C6
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0803617C @ =0x000008C8
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #0x18
	adds r1, r7, r4
	strh r0, [r1]
	b _080361C8
	.align 2, 0
_08036154: .4byte 0x000003E7
_08036158: .4byte 0x000008A2
_0803615C: .4byte 0x000008A4
_08036160: .4byte 0x000008D2
_08036164: .4byte 0x000008D6
_08036168: .4byte 0x000008DB
_0803616C: .4byte 0x000008DC
_08036170: .4byte 0x000008A8
_08036174: .4byte 0x000008AE
_08036178: .4byte 0x000008C6
_0803617C: .4byte 0x000008C8
_08036180:
	ldr r6, _080361F0 @ =0x000008A8
	adds r1, r7, r6
	movs r0, #0x19
	strh r0, [r1]
	ldr r1, _080361F4 @ =0x000008AA
	adds r0, r7, r1
	movs r2, #0x32
	strh r2, [r0]
	ldr r3, _080361F8 @ =0x000008AC
	adds r0, r7, r3
	movs r1, #0x3c
	strh r1, [r0]
	ldr r4, _080361FC @ =0x000008AE
	adds r0, r7, r4
	strh r2, [r0]
	adds r6, #8
	adds r0, r7, r6
	strh r2, [r0]
	adds r3, #6
	adds r0, r7, r3
	strh r1, [r0]
	adds r4, #0x16
	adds r1, r7, r4
	movs r0, #8
	strh r0, [r1]
	adds r6, #0x16
	adds r1, r7, r6
	movs r0, #0x10
	strh r0, [r1]
	ldr r0, _08036200 @ =0x000008C8
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r1, _08036204 @ =0x000008CA
	adds r0, r7, r1
	strh r2, [r0]
_080361C8:
	movs r0, #0x67
	bl prepare_08231510
	cmp r0, #0
	beq _08036214
	bl Script_GetValue
	ldr r2, _08036208 @ =0x000008B4
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0803620C @ =0x000008B6
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08036210 @ =0x000008B8
	adds r1, r7, r4
	b _0803622A
	.align 2, 0
_080361F0: .4byte 0x000008A8
_080361F4: .4byte 0x000008AA
_080361F8: .4byte 0x000008AC
_080361FC: .4byte 0x000008AE
_08036200: .4byte 0x000008C8
_08036204: .4byte 0x000008CA
_08036208: .4byte 0x000008B4
_0803620C: .4byte 0x000008B6
_08036210: .4byte 0x000008B8
_08036214:
	ldr r6, _08036260 @ =0x000008B4
	adds r1, r7, r6
	movs r0, #0x46
	strh r0, [r1]
	ldr r0, _08036264 @ =0x000008B6
	adds r1, r7, r0
	movs r0, #0x50
	strh r0, [r1]
	ldr r2, _08036268 @ =0x000008B8
	adds r1, r7, r2
	movs r0, #0x41
_0803622A:
	strh r0, [r1]
	movs r0, #0x55
	bl prepare_08231510
	cmp r0, #0
	beq _08036278
	bl Script_GetValue
	ldr r3, _0803626C @ =0x000008BA
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08036270 @ =0x000008BC
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r6, _08036274 @ =0x000008BE
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x8c
	lsls r2, r2, #4
	adds r1, r7, r2
	b _08036298
	.align 2, 0
_08036260: .4byte 0x000008B4
_08036264: .4byte 0x000008B6
_08036268: .4byte 0x000008B8
_0803626C: .4byte 0x000008BA
_08036270: .4byte 0x000008BC
_08036274: .4byte 0x000008BE
_08036278:
	ldr r3, _080362E8 @ =0x000008BA
	adds r1, r7, r3
	movs r0, #0x28
	strh r0, [r1]
	ldr r4, _080362EC @ =0x000008BC
	adds r1, r7, r4
	movs r0, #0x50
	strh r0, [r1]
	ldr r6, _080362F0 @ =0x000008BE
	adds r1, r7, r6
	movs r0, #0x32
	strh r0, [r1]
	movs r0, #0x8c
	lsls r0, r0, #4
	adds r1, r7, r0
	movs r0, #0x1e
_08036298:
	strh r0, [r1]
	ldr r2, _080362F4 @ =0x000008CE
	adds r1, r7, r2
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
	movs r3, #0x8d
	lsls r3, r3, #4
	adds r1, r7, r3
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	str r5, [sp]
	mov r0, sb
	mov r1, r8
	ldr r2, [sp, #0x28]
	add r3, sp, #0x1c
	bl Boss_Init_08022a70
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sb
	strb r5, [r0]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sb
	adds r1, #0xab
	strb r0, [r1]
	ldrb r0, [r1]
	str r1, [sp, #0x24]
	cmp r0, #0
	beq _080362F8
	movs r4, #0xb0
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	b _08036300
	.align 2, 0
_080362E8: .4byte 0x000008BA
_080362EC: .4byte 0x000008BC
_080362F0: .4byte 0x000008BE
_080362F4: .4byte 0x000008CE
_080362F8:
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0x40
_08036300:
	strh r0, [r1]
	movs r6, #0xbd
	lsls r6, r6, #2
	adds r6, r6, r7
	mov r8, r6
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r1, sp, #0x1c
	str r1, [sp, #0xc]
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r1, #3
	str r1, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x1c
	str r3, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3fc
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	mov r0, sb
	mov r1, r8
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08022da8
	adds r0, r7, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _08036374
	movs r4, #0xcf
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r5, #0x84
	lsls r5, r5, #3
	adds r0, r7, r5
	b _08036382
_08036374:
	ldr r0, _080363BC @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r6, #0xcf
	lsls r6, r6, #2
	adds r1, r7, r6
_08036382:
	str r0, [r1]
	adds r0, r1, #0
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0802a208
	adds r0, r7, #0
	bl FUN_08029ab8
	ldr r4, [sp, #0x24]
	ldrb r3, [r4]
	cmp r3, #0
	beq _08036474
	movs r0, #0x44
	movs r1, #1
	bl Script_GetKeywordValue
	adds r4, r0, #0
	cmp r4, #1
	beq _08036400
	cmp r4, #1
	bgt _080363C0
	cmp r4, #0
	beq _080363C6
	b _080364A8
	.align 2, 0
_080363BC: .4byte 0x03003584
_080363C0:
	cmp r4, #2
	beq _08036438
	b _080364A8
_080363C6:
	movs r1, #2
	mov r0, sb
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0x16
	str r4, [r0]
	subs r0, #0x14
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080363FC @ =FUN_0803331c
	movs r0, #0x23
	mov r3, sb
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, sb
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	b _080364A8
	.align 2, 0
_080363FC: .4byte FUN_0803331c
_08036400:
	movs r1, #2
	movs r2, #0
	mov r0, sb
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r4, [r0]
	ldr r1, _08036434 @ =FUN_080333a4
	movs r0, #0x24
	mov r3, sb
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, sb
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	b _080364A8
	.align 2, 0
_08036434: .4byte FUN_080333a4
_08036438:
	movs r1, #0
	movs r2, #0x10
	mov r0, sb
	adds r0, #0xa4
	strb r4, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	movs r3, #1
	strb r3, [r0]
	ldr r2, _08036470 @ =FUN_080333a4
	movs r0, #0x34
	mov r4, sb
	adds r4, #0xa3
	strb r0, [r4]
	mov r0, sb
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	b _080364A8
	.align 2, 0
_08036470: .4byte FUN_080333a4
_08036474:
	movs r2, #0x78
	adds r0, r7, #0
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	movs r1, #1
	strb r1, [r0]
	ldr r5, _0803650C @ =0x0000089C
	adds r0, r7, r5
	strh r2, [r0]
	ldr r2, _08036510 @ =FUN_0802e520
	mov r0, sb
	adds r0, #0xa3
	strb r1, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r1, [r0]
_080364A8:
	ldr r1, _08036514 @ =PreDurathrorEvent_08035aa8
	mov r0, sb
	adds r0, #0xfc
	str r1, [r0]
	ldr r1, _08036518 @ =FUN_08035a64
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, sb
	str r1, [r0]
	movs r6, #0x8a
	lsls r6, r6, #4
	adds r4, r7, r6
	ldrh r3, [r4]
	mov r0, sb
	mov r1, sl
	mov r2, sl
	bl FUN_08022b2c
	adds r0, r7, #0
	bl FUN_0802ab3c
	ldrh r1, [r4]
	adds r0, r7, #0
	bl FUN_0802ac94
	adds r0, r7, #0
	bl FUN_0802abe8
	adds r0, r7, #0
	bl FUN_0802ad28
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08036520
	bl Script_GetValue
	movs r2, #0x82
	lsls r2, r2, #5
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0803651C @ =0x00001042
	adds r1, r7, r3
	strh r0, [r1]
	b _0803652E
	.align 2, 0
_0803650C: .4byte 0x0000089C
_08036510: .4byte FUN_0802e520
_08036514: .4byte PreDurathrorEvent_08035aa8
_08036518: .4byte FUN_08035a64
_0803651C: .4byte 0x00001042
_08036520:
	movs r4, #0x82
	lsls r4, r4, #5
	adds r0, r7, r4
	strh r1, [r0]
	ldr r5, _08036550 @ =0x00001042
	adds r0, r7, r5
	strh r1, [r0]
_0803652E:
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08036554
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08022fac
	b _0803655E
	.align 2, 0
_08036550: .4byte 0x00001042
_08036554:
	mov r0, sb
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_0803655E:
	movs r0, #0x41
	bl prepare_08231510
	mov r6, sb
	adds r6, #0xde
	movs r1, #0x48
	add r1, sb
	mov r8, r1
	cmp r0, #0
	beq _08036592
	movs r4, #0
	b _08036586
_08036576:
	bl Script_GetValue
	lsls r2, r4, #2
	mov r1, sb
	adds r1, #0xe8
	adds r1, r1, r2
	str r0, [r1]
	adds r4, #1
_08036586:
	cmp r4, #3
	bgt _08036592
	bl VM_GetPC
	cmp r0, #0
	bne _08036576
_08036592:
	ldr r2, _080366BC @ =0x000008C2
	adds r1, r7, r2
	movs r5, #0
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x4b
	movs r1, #0
	bl Script_GetKeywordValue
	movs r3, #0x8e
	lsls r3, r3, #4
	adds r1, r7, r3
	str r0, [r1]
	movs r0, #0x78
	movs r1, #2
	bl Script_GetKeywordValue
	strb r0, [r6]
	ldr r4, _080366C0 @ =0x00000173
	adds r1, r7, r4
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0802adb8
	movs r6, #0xed
	lsls r6, r6, #2
	adds r4, r7, r6
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0x40
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xc8
	lsls r0, r0, #5
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_08013ba8
	ldr r1, _080366C4 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08013c94
	ldr r0, _080366C8 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0x99
	lsls r1, r1, #6
	adds r6, r0, r1
	movs r2, #0x84
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r4, #0xf
_08036610:
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, _080366CC @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _08036610
	ldr r0, _080366C8 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xc3
	lsls r3, r3, #5
	adds r6, r0, r3
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r5, r7, r4
	movs r4, #1
_08036634:
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, _080366CC @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _08036634
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r5, r7, r0
	movs r4, #0xd
_0803664E:
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, _080366CC @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _0803664E
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r7, #0
	bl FUN_08028790
	adds r0, r7, #0
	bl FUN_08028dbc
	adds r0, r7, #0
	bl FUN_08029d1c
	ldr r3, _080366D0 @ =0x0000087C
	adds r1, r7, r3
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08027ed0
	ldr r4, _080366D4 @ =0x0000087A
	adds r1, r7, r4
	movs r2, #0
	strh r0, [r1]
	movs r0, #0xc8
	lsls r0, r0, #1
	mov r5, r8
	strh r2, [r5, #0x30]
	strh r0, [r5, #0x32]
	strh r2, [r5, #0x34]
	ldr r6, [sp, #0x24]
	ldrb r0, [r6]
	cmp r0, #0
	beq _080366E4
	ldr r1, _080366D8 @ =0x0000104C
	adds r0, r7, r1
	str r2, [r0]
	ldr r3, _080366DC @ =0x00001050
	adds r0, r7, r3
	str r2, [r0]
	ldr r4, _080366E0 @ =0x00001058
	adds r0, r7, r4
	str r2, [r0]
	b _08036728
	.align 2, 0
_080366BC: .4byte 0x000008C2
_080366C0: .4byte 0x00000173
_080366C4: .4byte 0x00001C1B
_080366C8: .4byte 0x03003584
_080366CC: .4byte 0x04000008
_080366D0: .4byte 0x0000087C
_080366D4: .4byte 0x0000087A
_080366D8: .4byte 0x0000104C
_080366DC: .4byte 0x00001050
_080366E0: .4byte 0x00001058
_080366E4:
	ldr r5, _08036744 @ =0x000008BA
	adds r0, r7, r5
	ldrh r0, [r0]
	bl FUN_0805a31c
	ldr r6, _08036748 @ =0x0000104C
	adds r1, r7, r6
	str r0, [r1]
	cmp r0, #0
	beq _08036760
	ldr r1, _0803674C @ =0x000008BC
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r2, #0x8c
	lsls r2, r2, #4
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0805b068
	ldr r3, _08036750 @ =0x00001050
	adds r1, r7, r3
	str r0, [r1]
	cmp r0, #0
	beq _08036760
	ldr r4, _08036754 @ =0x0000016B
	adds r0, r7, r4
	ldrb r0, [r0]
	bl FUN_0805d364
	ldr r5, _08036758 @ =0x00001058
	adds r1, r7, r5
	str r0, [r1]
	cmp r0, #0
	beq _08036760
_08036728:
	movs r6, #0x82
	lsls r6, r6, #4
	adds r0, r7, r6
	ldr r0, [r0]
	bl FUN_0805b790
	ldr r2, _0803675C @ =0x00001054
	adds r1, r7, r2
	str r0, [r1]
	cmp r0, #0
	beq _08036760
	movs r0, #0
	b _08036764
	.align 2, 0
_08036744: .4byte 0x000008BA
_08036748: .4byte 0x0000104C
_0803674C: .4byte 0x000008BC
_08036750: .4byte 0x00001050
_08036754: .4byte 0x0000016B
_08036758: .4byte 0x00001058
_0803675C: .4byte 0x00001054
_08036760:
	movs r0, #1
	rsbs r0, r0, #0
_08036764:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EntityBA4B_Create
EntityBA4B_Create: @ 0x08036774
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x74
	movs r1, #1
	bl Script_GetKeywordValue
	bl FUN_08022a2c
	adds r4, r0, #0
	cmp r4, #0
	bne _080367C6
	ldr r1, _080367B8 @ =0x0000105C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080367C4
	ldr r1, _080367BC @ =EntityBA4B_Update
	ldr r2, _080367C0 @ =EntityBA4B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityBA4B_Init
	cmp r0, #0
	bge _080367C4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080367C6
	.align 2, 0
_080367B8: .4byte 0x0000105C
_080367BC: .4byte EntityBA4B_Update
_080367C0: .4byte EntityBA4B_Destroy
_080367C4:
	adds r0, r4, #0
_080367C6:
	pop {r4, r5}
	pop {r1}
	bx r1

