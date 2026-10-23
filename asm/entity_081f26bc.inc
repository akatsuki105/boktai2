	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f17c8
FUN_081f17c8: @ 0x081F17C8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0x1c
	adds r0, r0, r6
	mov sb, r0
	movs r7, #0
	mov r8, r7
	movs r5, #0
	adds r3, r6, #0
	adds r3, #0x93
	adds r4, r6, #0
	adds r4, #0x93
	mov ip, sb
_081F17E8:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _081F17F8
	movs r0, #1
	b _081F17FA
_081F17F8:
	movs r0, #0
_081F17FA:
	cmp r0, #0
	beq _081F1836
	mov r0, sb
	adds r0, #0x6c
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081F1836
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F1818
	subs r0, #1
	strb r0, [r3]
	b _081F1836
_081F1818:
	mov r0, r8
	cmp r0, #5
	bgt _081F1836
	movs r0, #3
	strb r0, [r4]
	mov r2, ip
	adds r2, #0x6c
	ldrh r1, [r2]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r7, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	add r8, r0
_081F1836:
	adds r3, #0x78
	adds r4, #0x78
	movs r7, #0x78
	add ip, r7
	adds r5, #1
	cmp r5, #0x17
	ble _081F17E8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f1850
FUN_081f1850: @ 0x081F1850
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0x6c
	ldrh r2, [r0]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081F1880
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081F1880
	adds r4, r3, #0
	adds r4, #0x1c
	cmp r1, #0
	beq _081F187A
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
_081F187A:
	adds r0, r4, #0
	bl Hitbox_Register
_081F1880:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f1888
FUN_081f1888: @ 0x081F1888
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f188c
FUN_081f188c: @ 0x081F188C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r2, _081F1918 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _081F191C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r7, r6, #0
	adds r7, #0x1c
	ldr r2, _081F1920 @ =0x00002001
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	str r4, [sp]
	ldr r0, [sp, #0x34]
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081F1924 @ =FUN_081f1888
	adds r0, r7, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081F1928
	ldr r1, [r6]
	adds r1, #0x1c
	adds r0, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	b _081F1934
	.align 2, 0
_081F1918: .4byte 0xFFFF0000
_081F191C: .4byte 0x0000FFFF
_081F1920: .4byte 0x00002001
_081F1924: .4byte FUN_081f1888
_081F1928:
	ldr r1, [r6]
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
_081F1934:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f1940
FUN_081f1940: @ 0x081F1940
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f1944
FUN_081f1944: @ 0x081F1944
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r3, #1
	adds r6, r2, #0
	adds r6, #0x8b
	adds r4, r2, #0
	adds r4, #0x1c
_081F1954:
	adds r0, r3, #0
	lsls r0, r5
	ldr r1, [r2, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _081F1964
	movs r0, #1
	b _081F1966
_081F1964:
	movs r0, #0
_081F1966:
	cmp r0, #0
	bne _081F1980
	adds r0, r3, #0
	lsls r0, r5
	orrs r0, r1
	str r0, [r2, #0x18]
	adds r0, r4, #0
	movs r1, #0x78
	bl ClearMemory
	strb r5, [r6]
	adds r0, r4, #0
	b _081F198C
_081F1980:
	adds r6, #0x78
	adds r4, #0x78
	adds r5, #1
	cmp r5, #0x17
	ble _081F1954
	movs r0, #0
_081F198C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f1994
FUN_081f1994: @ 0x081F1994
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0x76
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F19C6
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	ldr r0, [r6]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, r6, #0
	adds r0, #0x74
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strb r2, [r0]
_081F19C6:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_081f1850
	adds r2, r6, #0
	adds r2, #0x6c
	ldrh r1, [r2]
	movs r0, #8
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	bne _081F19E0
	b _081F1AE6
_081F19E0:
	mov ip, r6
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	ldm r0!, {r4}
	ldrh r0, [r0, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	mov r1, ip
	ldrb r0, [r1, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1A1A
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F1A22
_081F1A1A:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F1A22:
	str r0, [r4]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1A48
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F1A50
_081F1A48:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F1A50:
	str r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldr r4, _081F1A8C @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r3, #7]
	cmp r0, r1
	blo _081F1ADA
	movs r0, #0
	strh r0, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F1A98
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F1A90
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _081F1AB0
	.align 2, 0
_081F1A8C: .4byte 0x0000FFFF
_081F1A90:
	subs r0, #1
	mov r2, ip
	strh r0, [r2, #8]
	b _081F1AAE
_081F1A98:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r4, [r3, #5]
	cmp r0, r4
	blo _081F1AAE
	strh r1, [r3, #8]
	movs r2, #1
	b _081F1AB0
_081F1AAE:
	movs r2, #0
_081F1AB0:
	mov r1, ip
	ldrh r0, [r1, #8]
	lsls r0, r0, #1
	ldr r1, [r1]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	mov r3, ip
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F1ADC
	movs r0, #1
	strb r0, [r3, #7]
	b _081F1ADC
_081F1ADA:
	movs r2, #0
_081F1ADC:
	adds r3, r2, #0
	ldr r0, [r6]
	adds r2, r0, #0
	adds r2, #0x1c
	b _081F1BEE
_081F1AE6:
	mov ip, r6
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	ldm r0!, {r4}
	ldr r3, [r4, #0x28]
	ldrh r0, [r0, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #8]
	mov r1, ip
	ldrb r0, [r1, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1B32
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F1B3A
_081F1B32:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F1B3A:
	str r0, [r4]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1B60
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F1B68
_081F1B60:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F1B68:
	str r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldr r4, _081F1BA4 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r3, #7]
	cmp r0, r1
	blo _081F1BE4
	movs r0, #0
	strh r0, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F1BB0
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F1BA8
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _081F1BC8
	.align 2, 0
_081F1BA4: .4byte 0x0000FFFF
_081F1BA8:
	subs r0, #1
	mov r2, ip
	strh r0, [r2, #8]
	b _081F1BC6
_081F1BB0:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r4, [r3, #5]
	cmp r0, r4
	blo _081F1BC6
	strh r1, [r3, #8]
	movs r2, #1
	b _081F1BC8
_081F1BC6:
	movs r2, #0
_081F1BC8:
	mov r1, ip
	ldrh r0, [r1, #8]
	lsls r0, r0, #1
	ldr r1, [r1]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	mov r3, ip
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	b _081F1BE6
_081F1BE4:
	movs r2, #0
_081F1BE6:
	adds r3, r2, #0
	ldr r0, [r6]
	adds r2, r0, #0
	adds r2, #0x18
_081F1BEE:
	ldrh r1, [r7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081F1C14
	adds r1, r6, #0
	adds r1, #0x14
	ldrh r0, [r2]
	ldrh r4, [r6, #0x14]
	adds r0, r0, r4
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
_081F1C14:
	adds r1, r6, #0
	adds r1, #0x74
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r3, #0
	beq _081F1CB0
	adds r0, r6, #0
	adds r0, #0x70
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081F1CBC
	ldrh r1, [r7]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081F1C9E
	ldr r0, _081F1C7C @ =0x030001EC
	ldr r2, [r0]
	adds r3, r6, #0
	adds r3, #0x6f
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	adds r1, r6, #0
	adds r1, #0x6e
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r7]
	movs r0, #8
	ands r0, r1
	adds r4, r3, #0
	cmp r0, #0
	beq _081F1C80
	ldr r1, [r6]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F1C94
	adds r0, r1, #0
	bl AuxSprite_Remove
	ldr r0, [r6]
	bl Free
	b _081F1C94
	.align 2, 0
_081F1C7C: .4byte 0x030001EC
_081F1C80:
	ldr r1, [r6]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F1C94
	adds r0, r1, #0
	bl Particle_Remove
	ldr r0, [r6]
	bl Free
_081F1C94:
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	strh r0, [r7]
	b _081F1CA6
_081F1C9E:
	adds r1, r6, #0
	adds r1, #0x6e
	movs r0, #3
	strb r0, [r1]
_081F1CA6:
	adds r1, r6, #0
	adds r1, #0x76
	movs r0, #1
	strb r0, [r1]
	b _081F1CC2
_081F1CB0:
	adds r0, r6, #0
	adds r0, #0x70
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081F1CC2
_081F1CBC:
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_081F1CC2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f1cc8
FUN_081f1cc8: @ 0x081F1CC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r1, #0
	ldr r6, [r5]
	adds r3, r5, #0
	adds r3, #0x76
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F1CF4
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r5, #0
	adds r1, #0x74
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r3]
_081F1CF4:
	adds r2, r5, #0
	adds r2, #0x6c
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	movs r1, #0x74
	adds r1, r1, r5
	mov r8, r1
	mov sb, r2
	adds r7, r6, #0
	adds r7, #0x18
	cmp r0, #0
	bne _081F1D10
	b _081F1E2C
_081F1D10:
	subs r2, #0x58
	ldrh r0, [r6, #0x18]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r6, #0x18]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r1, [r7, #4]
	ldrh r3, [r2, #4]
	adds r1, r1, r3
	strh r1, [r7, #4]
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r2
	cmp r3, #0
	blt _081F1D4E
	cmp r1, #0
	blt _081F1D4E
	ldr r0, _081F1D54 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081F1D4E
	ldr r0, _081F1D58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F1D5C
_081F1D4E:
	movs r4, #0
	b _081F1D6A
	.align 2, 0
_081F1D54: .4byte 0x030046A8
_081F1D58: .4byte 0x030046AC
_081F1D5C:
	ldr r0, _081F1D7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081F1D6A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F1D80
	adds r0, #4
	b _081F1D8C
	.align 2, 0
_081F1D7C: .4byte 0x030046A4
_081F1D80:
	ldr r0, _081F1E0C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F1D8C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0x1a
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bgt _081F1E14
	strh r1, [r6, #0x1a]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0x14]
	movs r1, #0x16
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _081F1DB8
	rsbs r0, r0, #0
_081F1DB8:
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0x16]
	movs r2, #0x18
	ldrsh r1, [r5, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0x18]
	movs r3, #0x14
	ldrsh r0, [r5, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	mov r2, r8
	movs r3, #2
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov r3, r8
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	movs r2, #0x74
	adds r2, r2, r5
	mov r8, r2
	cmn r1, r0
	bne _081F1E2C
	mov r3, sb
	ldrh r1, [r3]
	ldr r0, _081F1E10 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r3]
	b _081F1E2C
	.align 2, 0
_081F1E0C: .4byte 0x030046A4
_081F1E10: .4byte 0x0000FF7F
_081F1E14:
	adds r4, r5, #0
	adds r4, #0x74
	ldrh r0, [r4]
	movs r1, #4
	bl Mod
	mov r8, r4
	cmp r0, #0
	beq _081F1E2C
	ldrh r0, [r5, #0x16]
	subs r0, #2
	strh r0, [r5, #0x16]
_081F1E2C:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_081f1850
	mov ip, r5
	mov r1, ip
	adds r1, #4
	mov ip, r1
	subs r1, #4
	ldm r1!, {r0}
	ldr r3, [r0, #0x28]
	ldrh r0, [r1, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #4]
	adds r4, r1, r0
	ldrh r2, [r4]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1E80
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081F1E88
_081F1E80:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F1E88:
	str r0, [r6]
	mov r3, ip
	ldrb r0, [r3, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1EAE
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081F1EB6
_081F1EAE:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F1EB6:
	str r0, [r6]
	mov r1, ip
	ldrh r0, [r1, #0xe]
	adds r0, #1
	strh r0, [r1, #0xe]
	ldr r3, _081F1EF4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1, #7]
	cmp r0, r1
	blo _081F1F32
	movs r0, #0
	mov r3, ip
	strh r0, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F1F00
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F1EF8
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _081F1F18
	.align 2, 0
_081F1EF4: .4byte 0x0000FFFF
_081F1EF8:
	subs r0, #1
	mov r1, ip
	strh r0, [r1, #8]
	b _081F1F16
_081F1F00:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F1F16
	strh r1, [r3, #8]
	movs r2, #1
	b _081F1F18
_081F1F16:
	movs r2, #0
_081F1F18:
	mov r3, ip
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	b _081F1F34
_081F1F32:
	movs r2, #0
_081F1F34:
	adds r3, r2, #0
	adds r0, r5, #0
	adds r0, #0x70
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081F1F5E
	ldrh r0, [r5, #0xc]
	cmp r0, #5
	bne _081F1F58
	ldrh r1, [r5, #0x12]
	ldrb r0, [r5, #0xb]
	subs r0, #1
	cmp r1, r0
	bne _081F1F58
	movs r0, #0
	strh r0, [r5, #0xc]
	strh r0, [r5, #0x12]
_081F1F58:
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_081F1F5E:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r3, #0
	beq _081F1FF0
	mov r2, sb
	ldrh r1, [r2]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081F1FE0
	ldr r0, _081F1FBC @ =0x030001EC
	ldr r2, [r0]
	adds r3, r5, #0
	adds r3, #0x6f
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	adds r1, r5, #0
	adds r1, #0x6e
	movs r0, #0
	strb r0, [r1]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	adds r4, r3, #0
	cmp r0, #0
	beq _081F1FC0
	ldr r1, [r5]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F1FD4
	adds r0, r1, #0
	bl AuxSprite_Remove
	ldr r0, [r5]
	bl Free
	b _081F1FD4
	.align 2, 0
_081F1FBC: .4byte 0x030001EC
_081F1FC0:
	ldr r1, [r5]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F1FD4
	adds r0, r1, #0
	bl Particle_Remove
	ldr r0, [r5]
	bl Free
_081F1FD4:
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	b _081F1FE8
_081F1FE0:
	adds r1, r5, #0
	adds r1, #0x6e
	movs r0, #3
	strb r0, [r1]
_081F1FE8:
	adds r1, r5, #0
	adds r1, #0x76
	movs r0, #1
	strb r0, [r1]
_081F1FF0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f1ffc
FUN_081f1ffc: @ 0x081F1FFC
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r2, r6, #0
	adds r2, #0x76
	ldrb r0, [r2]
	cmp r0, #0
	beq _081F2014
	movs r1, #0
	strb r1, [r2]
	adds r0, r6, #0
	adds r0, #0x74
	strh r1, [r0]
_081F2014:
	adds r2, r6, #0
	adds r2, #0x6c
	ldrh r1, [r2]
	movs r0, #8
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _081F2118
	mov ip, r6
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	ldm r0!, {r4}
	ldrh r0, [r0, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	mov r1, ip
	ldrb r0, [r1, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F205E
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F2066
_081F205E:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2066:
	str r0, [r4]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F208C
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F2094
_081F208C:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F2094:
	str r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldr r1, _081F20D4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r3, #7]
	cmp r0, r3
	bhs _081F20AE
	b _081F220E
_081F20AE:
	movs r0, #0
	mov r1, ip
	strh r0, [r1, #0xe]
	ldrb r1, [r1, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F20E0
	mov r2, ip
	ldrh r0, [r2, #8]
	cmp r0, #0
	bne _081F20D8
	ldrb r0, [r2, #5]
	subs r0, #1
	strh r0, [r2, #8]
	b _081F20F2
	.align 2, 0
_081F20D4: .4byte 0x0000FFFF
_081F20D8:
	subs r0, #1
	mov r3, ip
	strh r0, [r3, #8]
	b _081F20F2
_081F20E0:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F20F2
	strh r1, [r3, #8]
_081F20F2:
	mov r3, ip
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _081F220E
	movs r0, #1
	b _081F220C
_081F2118:
	mov ip, r6
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	ldm r0!, {r4}
	ldr r3, [r4, #0x28]
	ldrh r0, [r0, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #8]
	mov r1, ip
	ldrb r0, [r1, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F2164
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F216C
_081F2164:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F216C:
	str r0, [r4]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F2192
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F219A
_081F2192:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F219A:
	str r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldr r1, _081F21D8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r3, #7]
	cmp r0, r3
	blo _081F220E
	movs r0, #0
	mov r1, ip
	strh r0, [r1, #0xe]
	ldrb r1, [r1, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F21E4
	mov r2, ip
	ldrh r0, [r2, #8]
	cmp r0, #0
	bne _081F21DC
	ldrb r0, [r2, #5]
	subs r0, #1
	strh r0, [r2, #8]
	b _081F21F6
	.align 2, 0
_081F21D8: .4byte 0x0000FFFF
_081F21DC:
	subs r0, #1
	mov r3, ip
	strh r0, [r3, #8]
	b _081F21F6
_081F21E4:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F21F6
	strh r1, [r3, #8]
_081F21F6:
	mov r3, ip
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
_081F220C:
	strb r0, [r3, #7]
_081F220E:
	ldrh r1, [r7]
	movs r0, #8
	ands r0, r1
	ldr r0, [r6]
	adds r4, r6, #0
	adds r4, #0x74
	ldrh r1, [r4]
	movs r2, #0x3c
	movs r3, #0x28
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081F228E
	ldr r0, _081F226C @ =0x030001EC
	ldr r2, [r0]
	adds r3, r6, #0
	adds r3, #0x6f
	movs r0, #0
	ldrsb r0, [r3, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	adds r1, r6, #0
	adds r1, #0x6e
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r7]
	movs r0, #8
	ands r0, r1
	adds r4, r3, #0
	cmp r0, #0
	beq _081F2270
	ldr r1, [r6]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F2284
	adds r0, r1, #0
	bl AuxSprite_Remove
	ldr r0, [r6]
	bl Free
	b _081F2284
	.align 2, 0
_081F226C: .4byte 0x030001EC
_081F2270:
	ldr r1, [r6]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F2284
	adds r0, r1, #0
	bl Particle_Remove
	ldr r0, [r6]
	bl Free
_081F2284:
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	strh r0, [r7]
	b _081F2294
_081F228E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081F2294:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f229c
FUN_081f229c: @ 0x081F229C
	push {r4, lr}
	adds r4, r2, #0
	ldr r0, [r0]
	adds r0, #0x2c
	bl Video_GetAuxSprite
	ldr r0, _081F22BC @ =0x0000922E
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl GetFile
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F22BC: .4byte 0x0000922E

	thumb_func_start FUN_081f22c0
FUN_081f22c0: @ 0x081F22C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r4, r1, #0
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, _081F2318 @ =0x030001EC
	ldr r3, [r0]
	cmp r3, #0
	bne _081F22E6
	bl Entity081f26bc_Create
	adds r3, r0, #0
	cmp r3, #0
	beq _081F2312
_081F22E6:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F231C @ =0x030047A4
	ldr r1, _081F2320 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081F2312
	ldr r0, _081F2324 @ =0x03002BC0
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081F2312
	adds r0, r3, #0
	bl FUN_081f1944
	adds r7, r0, #0
	cmp r7, #0
	bne _081F2328
_081F2312:
	movs r0, #0
	b _081F2582
	.align 2, 0
_081F2318: .4byte 0x030001EC
_081F231C: .4byte 0x030047A4
_081F2320: .4byte 0x030047A0
_081F2324: .4byte 0x03002BC0
_081F2328:
	adds r2, r7, #0
	adds r2, #0x6c
	ldr r0, [sp, #0x34]
	strh r0, [r2]
	adds r0, r7, #0
	adds r0, #0x76
	movs r3, #1
	mov sb, r3
	mov r1, sb
	strb r1, [r0]
	movs r3, #0x6e
	adds r3, r3, r7
	mov sl, r3
	strb r1, [r3]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	mov r8, r2
	cmn r1, r0
	beq _081F2378
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
_081F2378:
	adds r1, r7, #0
	adds r1, #0x70
	ldr r0, [sp, #0x48]
	strh r0, [r1]
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081F238E
	b _081F24C8
_081F238E:
	movs r0, #0x48
	bl Malloc
	str r0, [r7]
	movs r1, #0x48
	bl ClearMemory
	ldr r5, [r7]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r0, r7, #0
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl FUN_081f229c
	adds r6, r0, #0
	adds r4, r7, #0
	ldm r4!, {r1}
	adds r1, #0x2c
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r1, [sp, #0x2c]
	lsls r2, r1, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x40]
	lsls r3, r0, #0x18
	lsrs r3, r3, #0x18
	ldr r1, [sp, #0x44]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl AuxAnim_SetAnim
	ldr r0, [r5, #0xc]
	ldr r1, [sp, #0x38]
	bl Video_SetAuxSpritePltt
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sb
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _081F2410
	ldr r0, [r5]
	movs r3, #4
	orrs r0, r3
	b _081F2418
_081F2410:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2418:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F243C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F2444
_081F243C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F2444:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F247C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081F24B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F2480
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F2474
	ldrb r0, [r4, #5]
_081F2474:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F2490
	.align 2, 0
_081F247C: .4byte 0x0000FFFF
_081F2480:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F2490
	strh r1, [r4, #8]
_081F2490:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F24B4
	movs r0, #1
	strb r0, [r4, #7]
_081F24B4:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	ldr r3, [sp, #0x30]
	orrs r0, r3
	str r0, [r5]
	add r0, sp, #0x3c
	ldrb r0, [r0]
	strb r0, [r5, #7]
	b _081F2560
_081F24C8:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081F2560
	movs r0, #0x2c
	bl Malloc
	str r0, [r7]
	movs r1, #0x2c
	bl ClearMemory
	ldr r5, [r7]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r4, [r7]
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl GetParticleGroup
	str r0, [r4, #0x28]
	ldr r0, _081F2594 @ =0x0000922E
	ldr r2, [sp, #8]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r6, r0, #0
	adds r4, r7, #0
	ldm r4!, {r0}
	ldr r1, [r0, #0x28]
	adds r0, r5, #0
	movs r2, #0
	bl Particle_Add
	ldr r1, [sp, #0x5c]
	rsbs r1, r1, #0
	ldr r2, [sp, #0x60]
	rsbs r2, r2, #0
	adds r0, r5, #0
	bl Particle_SetOffset
	ldr r3, [sp, #0x2c]
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x40]
	lsls r3, r0, #0x18
	lsrs r3, r3, #0x18
	ldr r1, [sp, #0x44]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl AuxAnim_SetAnim
	ldr r0, [r5]
	mov r2, sb
	orrs r0, r2
	ldr r3, [sp, #0x30]
	orrs r0, r3
	str r0, [r5]
	add r0, sp, #0x3c
	ldrb r0, [r0]
	strb r0, [r5, #0xf]
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081F2560
	movs r0, #2
	mov r3, sl
	strb r0, [r3]
_081F2560:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	ble _081F2580
	ldr r0, [sp, #0x58]
	str r0, [sp]
	adds r0, r7, #0
	ldr r1, [sp, #0x4c]
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl FUN_081f188c
	mov r2, r8
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081F2580:
	adds r0, r7, #0
_081F2582:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F2594: .4byte 0x0000922E

	thumb_func_start Entity081f26bc_Update
Entity081f26bc_Update: @ 0x081F2598
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x1c
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _081F261C
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F25EC @ =0x030047A4
	ldr r1, _081F25F0 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081F261C
	movs r1, #4
	ldr r0, _081F25F4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081F261C
	adds r0, r4, #0
	bl FUN_081f17c8
	movs r7, #0
	ldr r0, _081F25F8 @ =0x085AE538
	mov r8, r0
	adds r6, r4, #0
	adds r6, #0x8a
_081F25DA:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r4, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _081F25FC
	movs r0, #1
	b _081F25FE
	.align 2, 0
_081F25EC: .4byte 0x030047A4
_081F25F0: .4byte 0x030047A0
_081F25F4: .4byte 0x03002BC0
_081F25F8: .4byte 0x085AE538
_081F25FC:
	movs r0, #0
_081F25FE:
	cmp r0, #0
	beq _081F2612
	ldrb r0, [r6]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
_081F2612:
	adds r6, #0x78
	adds r5, #0x78
	adds r7, #1
	cmp r7, #0x17
	ble _081F25DA
_081F261C:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081f26bc_Destroy
Entity081f26bc_Destroy: @ 0x081F2628
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r7, #0
	mov r4, r8
	adds r4, #0x1c
	mov r6, r8
	adds r6, #0x88
	adds r5, r4, #0
_081F263C:
	movs r1, #1
	lsls r1, r7
	mov r2, r8
	ldr r0, [r2, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _081F264E
	movs r0, #1
	b _081F2650
_081F264E:
	movs r0, #0
_081F2650:
	cmp r0, #0
	beq _081F2688
	ldrh r1, [r6]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081F2674
	ldr r1, [r4]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F2688
	adds r0, r1, #0
	bl AuxSprite_Remove
	ldr r0, [r4]
	bl Free
	b _081F2688
_081F2674:
	ldr r1, [r5]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F2688
	adds r0, r1, #0
	bl Particle_Remove
	ldr r0, [r5]
	bl Free
_081F2688:
	adds r4, #0x78
	adds r6, #0x78
	adds r5, #0x78
	adds r7, #1
	cmp r7, #0x17
	ble _081F263C
	movs r1, #0
	ldr r0, _081F26A8 @ =0x030001EC
	str r1, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F26A8: .4byte 0x030001EC

	thumb_func_start Entity081f26bc_Init
Entity081f26bc_Init: @ 0x081F26AC
	movs r1, #0
	str r1, [r0, #0x18]
	ldr r1, _081F26B8 @ =0x030001EC
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_081F26B8: .4byte 0x030001EC

	thumb_func_start Entity081f26bc_Create
Entity081f26bc_Create: @ 0x081F26BC
	push {r4, lr}
	ldr r0, _081F26F0 @ =0x030001EC
	ldr r0, [r0]
	cmp r0, #0
	bne _081F2702
	ldr r1, _081F26F4 @ =0x00000B5C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F2700
	ldr r1, _081F26F8 @ =Entity081f26bc_Update
	ldr r2, _081F26FC @ =Entity081f26bc_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f26bc_Init
	cmp r0, #0
	bge _081F2700
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F2702
	.align 2, 0
_081F26F0: .4byte 0x030001EC
_081F26F4: .4byte 0x00000B5C
_081F26F8: .4byte Entity081f26bc_Update
_081F26FC: .4byte Entity081f26bc_Destroy
_081F2700:
	adds r0, r4, #0
_081F2702:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f2708
FUN_081f2708: @ 0x081F2708
	ldr r1, _081F2710 @ =0x030001EC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F2710: .4byte 0x030001EC
