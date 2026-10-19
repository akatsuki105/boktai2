	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0820cbdc
FUN_0820cbdc: @ 0x0820CBDC
	ldr r1, _0820CBE8 @ =0x085AF034
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0820CBE8: .4byte 0x085AF034

	thumb_func_start FUN_0820cbec
FUN_0820cbec: @ 0x0820CBEC
	ldr r1, _0820CBF8 @ =0x085AF058
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0820CBF8: .4byte 0x085AF058

	thumb_func_start FUN_0820cbfc
FUN_0820cbfc: @ 0x0820CBFC
	ldr r1, _0820CC08 @ =0x085AF07C
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0820CC08: .4byte 0x085AF07C

	thumb_func_start FUN_0820cc0c
FUN_0820cc0c: @ 0x0820CC0C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r4, #0
	cmp r6, r5
	bge _0820CC26
_0820CC18:
	adds r0, r4, #0
	bl FUN_0820cbfc
	adds r6, r6, r0
	adds r4, #1
	cmp r4, r5
	blt _0820CC18
_0820CC26:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820cc30
FUN_0820cc30: @ 0x0820CC30
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r5, #0
	movs r0, #0x26
	add r0, r8
	mov sb, r0
	mov r7, sb
	mov r6, r8
	adds r6, #0x25
_0820CC48:
	ldrb r4, [r7]
	adds r0, r5, #0
	bl FUN_0820cbdc
	cmp r4, r0
	bge _0820CC62
	subs r0, r5, #1
	strb r0, [r6]
	ldrb r0, [r6]
	bl FUN_0820cbdc
	ldrb r1, [r7]
	b _0820CC78
_0820CC62:
	adds r5, #1
	cmp r5, #8
	ble _0820CC48
	mov r1, r8
	adds r1, #0x25
	movs r0, #8
	strb r0, [r1]
	bl FUN_0820cbdc
	mov r2, sb
	ldrb r1, [r2]
_0820CC78:
	subs r1, r1, r0
	mov r0, r8
	adds r0, #0x48
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820cc8c
FUN_0820cc8c: @ 0x0820CC8C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #3
	bl FUN_0820cbdc
	cmp r4, r0
	bge _0820CC9E
	movs r0, #0
	b _0820CCCA
_0820CC9E:
	movs r0, #4
	bl FUN_0820cbdc
	cmp r4, r0
	bge _0820CCAC
	movs r0, #1
	b _0820CCCA
_0820CCAC:
	movs r0, #6
	bl FUN_0820cbdc
	cmp r4, r0
	bge _0820CCBA
	movs r0, #2
	b _0820CCCA
_0820CCBA:
	movs r0, #8
	bl FUN_0820cbdc
	cmp r4, r0
	blt _0820CCC8
	movs r0, #4
	b _0820CCCA
_0820CCC8:
	movs r0, #3
_0820CCCA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820ccd0
FUN_0820ccd0: @ 0x0820CCD0
	push {lr}
	adds r2, r1, #0
	cmp r0, #0x1f
	bls _0820CCDA
	b _0820CF3C
_0820CCDA:
	lsls r0, r0, #2
	ldr r1, _0820CCE4 @ =_0820CCE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820CCE4: .4byte _0820CCE8
_0820CCE8: @ jump table
	.4byte _0820CF3C @ case 0
	.4byte _0820CD68 @ case 1
	.4byte _0820CD88 @ case 2
	.4byte _0820CDA4 @ case 3
	.4byte _0820CDC4 @ case 4
	.4byte _0820CDE4 @ case 5
	.4byte _0820CDF6 @ case 6
	.4byte _0820CDFA @ case 7
	.4byte _0820CDFE @ case 8
	.4byte _0820CE10 @ case 9
	.4byte _0820CE14 @ case 10
	.4byte _0820CE26 @ case 11
	.4byte _0820CE2A @ case 12
	.4byte _0820CE3C @ case 13
	.4byte _0820CE4E @ case 14
	.4byte _0820CF3C @ case 15
	.4byte _0820CF3C @ case 16
	.4byte _0820CE52 @ case 17
	.4byte _0820CE72 @ case 18
	.4byte _0820CE8E @ case 19
	.4byte _0820CEAA @ case 20
	.4byte _0820CECA @ case 21
	.4byte _0820CEF2 @ case 22
	.4byte _0820CF1A @ case 23
	.4byte _0820CF2C @ case 24
	.4byte _0820CF30 @ case 25
	.4byte _0820CF34 @ case 26
	.4byte _0820CF38 @ case 27
	.4byte _0820CF3C @ case 28
	.4byte _0820CF3C @ case 29
	.4byte _0820CF3C @ case 30
	.4byte _0820CF3C @ case 31
_0820CD68:
	cmp r2, #1
	beq _0820CD80
	cmp r2, #1
	bgt _0820CD76
	cmp r2, #0
	beq _0820CD7C
	b _0820CF3C
_0820CD76:
	cmp r2, #2
	beq _0820CD84
	b _0820CF3C
_0820CD7C:
	movs r0, #0x18
	b _0820CF40
_0820CD80:
	movs r0, #0x19
	b _0820CF40
_0820CD84:
	movs r0, #0x1a
	b _0820CF40
_0820CD88:
	cmp r2, #1
	beq _0820CD9C
	cmp r2, #1
	bgt _0820CD96
	cmp r2, #0
	beq _0820CDA0
	b _0820CF3C
_0820CD96:
	cmp r2, #2
	beq _0820CDA0
	b _0820CF3C
_0820CD9C:
	movs r0, #1
	b _0820CF40
_0820CDA0:
	movs r0, #0
	b _0820CF40
_0820CDA4:
	cmp r2, #1
	beq _0820CDBC
	cmp r2, #1
	bgt _0820CDB2
	cmp r2, #0
	beq _0820CDB8
	b _0820CF3C
_0820CDB2:
	cmp r2, #3
	beq _0820CDC0
	b _0820CF3C
_0820CDB8:
	movs r0, #0x21
	b _0820CF40
_0820CDBC:
	movs r0, #0x22
	b _0820CF40
_0820CDC0:
	movs r0, #0x23
	b _0820CF40
_0820CDC4:
	cmp r2, #2
	beq _0820CDDC
	cmp r2, #2
	bgt _0820CDD2
	cmp r2, #1
	beq _0820CDD8
	b _0820CF3C
_0820CDD2:
	cmp r2, #3
	beq _0820CDE0
	b _0820CF3C
_0820CDD8:
	movs r0, #0x15
	b _0820CF40
_0820CDDC:
	movs r0, #0x16
	b _0820CF40
_0820CDE0:
	movs r0, #0x17
	b _0820CF40
_0820CDE4:
	cmp r2, #0
	beq _0820CDEE
	cmp r2, #5
	beq _0820CDF2
	b _0820CF3C
_0820CDEE:
	movs r0, #0x1b
	b _0820CF40
_0820CDF2:
	movs r0, #0x1e
	b _0820CF40
_0820CDF6:
	movs r0, #0x1c
	b _0820CF40
_0820CDFA:
	movs r0, #0x1d
	b _0820CF40
_0820CDFE:
	cmp r2, #2
	beq _0820CE08
	cmp r2, #8
	beq _0820CE0C
	b _0820CF3C
_0820CE08:
	movs r0, #0x1f
	b _0820CF40
_0820CE0C:
	movs r0, #0x20
	b _0820CF40
_0820CE10:
	movs r0, #9
	b _0820CF40
_0820CE14:
	cmp r2, #0
	beq _0820CE1E
	cmp r2, #1
	beq _0820CE22
	b _0820CF3C
_0820CE1E:
	movs r0, #0x11
	b _0820CF40
_0820CE22:
	movs r0, #0x12
	b _0820CF40
_0820CE26:
	movs r0, #0x24
	b _0820CF40
_0820CE2A:
	cmp r2, #0
	beq _0820CE34
	cmp r2, #1
	beq _0820CE38
	b _0820CF3C
_0820CE34:
	movs r0, #0x25
	b _0820CF40
_0820CE38:
	movs r0, #0x26
	b _0820CF40
_0820CE3C:
	cmp r2, #0
	beq _0820CE46
	cmp r2, #1
	beq _0820CE4A
	b _0820CF3C
_0820CE46:
	movs r0, #0x27
	b _0820CF40
_0820CE4A:
	movs r0, #0x28
	b _0820CF40
_0820CE4E:
	movs r0, #0x10
	b _0820CF40
_0820CE52:
	cmp r2, #1
	beq _0820CE6A
	cmp r2, #1
	bgt _0820CE60
	cmp r2, #0
	beq _0820CE66
	b _0820CF3C
_0820CE60:
	cmp r2, #2
	beq _0820CE6E
	b _0820CF3C
_0820CE66:
	movs r0, #0x29
	b _0820CF40
_0820CE6A:
	movs r0, #0x2a
	b _0820CF40
_0820CE6E:
	movs r0, #0x2b
	b _0820CF40
_0820CE72:
	cmp r2, #1
	beq _0820CE86
	cmp r2, #1
	bgt _0820CE80
	cmp r2, #0
	beq _0820CE8A
	b _0820CF3C
_0820CE80:
	cmp r2, #2
	beq _0820CE8A
	b _0820CF3C
_0820CE86:
	movs r0, #6
	b _0820CF40
_0820CE8A:
	movs r0, #5
	b _0820CF40
_0820CE8E:
	cmp r2, #1
	beq _0820CEA2
	cmp r2, #1
	bgt _0820CE9C
	cmp r2, #0
	beq _0820CEA6
	b _0820CF3C
_0820CE9C:
	cmp r2, #2
	beq _0820CEA6
	b _0820CF3C
_0820CEA2:
	movs r0, #8
	b _0820CF40
_0820CEA6:
	movs r0, #7
	b _0820CF40
_0820CEAA:
	cmp r2, #1
	beq _0820CEC2
	cmp r2, #1
	bgt _0820CEB8
	cmp r2, #0
	beq _0820CEBE
	b _0820CF3C
_0820CEB8:
	cmp r2, #2
	beq _0820CEC6
	b _0820CF3C
_0820CEBE:
	movs r0, #2
	b _0820CF40
_0820CEC2:
	movs r0, #4
	b _0820CF40
_0820CEC6:
	movs r0, #3
	b _0820CF40
_0820CECA:
	cmp r2, #1
	beq _0820CEE6
	cmp r2, #1
	bgt _0820CED8
	cmp r2, #0
	beq _0820CEE2
	b _0820CF3C
_0820CED8:
	cmp r2, #2
	beq _0820CEEA
	cmp r2, #4
	beq _0820CEEE
	b _0820CF3C
_0820CEE2:
	movs r0, #0xa
	b _0820CF40
_0820CEE6:
	movs r0, #0xc
	b _0820CF40
_0820CEEA:
	movs r0, #0xb
	b _0820CF40
_0820CEEE:
	movs r0, #0xd
	b _0820CF40
_0820CEF2:
	cmp r2, #1
	beq _0820CF0E
	cmp r2, #1
	bgt _0820CF00
	cmp r2, #0
	beq _0820CF0A
	b _0820CF3C
_0820CF00:
	cmp r2, #2
	beq _0820CF12
	cmp r2, #3
	beq _0820CF16
	b _0820CF3C
_0820CF0A:
	movs r0, #0x2c
	b _0820CF40
_0820CF0E:
	movs r0, #0x2d
	b _0820CF40
_0820CF12:
	movs r0, #0x2e
	b _0820CF40
_0820CF16:
	movs r0, #0x2f
	b _0820CF40
_0820CF1A:
	cmp r2, #0
	beq _0820CF24
	cmp r2, #1
	beq _0820CF28
	b _0820CF3C
_0820CF24:
	movs r0, #0x30
	b _0820CF40
_0820CF28:
	movs r0, #0x31
	b _0820CF40
_0820CF2C:
	movs r0, #0xe
	b _0820CF40
_0820CF30:
	movs r0, #0x13
	b _0820CF40
_0820CF34:
	movs r0, #0x14
	b _0820CF40
_0820CF38:
	movs r0, #0xf
	b _0820CF40
_0820CF3C:
	movs r0, #1
	rsbs r0, r0, #0
_0820CF40:
	pop {r1}
	bx r1

	thumb_func_start FUN_0820cf44
FUN_0820cf44: @ 0x0820CF44
	ldr r2, _0820CF68 @ =0x030046A0
	ldr r2, [r2]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r2, r2, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	lsrs r1, r0, #5
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0820CF68: .4byte 0x030046A0

	thumb_func_start FUN_0820cf6c
FUN_0820cf6c: @ 0x0820CF6C
	push {r4, r5, r6, lr}
	movs r0, #0x6b
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0820CF80
	bl VM_GetValue
	adds r6, r0, #0
	b _0820CF82
_0820CF80:
	movs r6, #0
_0820CF82:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0820CF94
	bl VM_GetValue
	adds r5, r0, #0
	b _0820CF96
_0820CF94:
	movs r5, #0
_0820CF96:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0820CFA8
	bl VM_GetValue
	adds r4, r0, #0
	b _0820CFAA
_0820CFA8:
	movs r4, #0
_0820CFAA:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0820ccd0
	adds r1, r4, #0
	bl FUN_0820cf44
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Cmd_D1C0
Cmd_D1C0: @ 0x0820CFC0
	push {lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6b
	bl VM_GetNamedArgValue
	adds r3, r0, #0
	cmp r3, #0x38
	bhi _0820D004
	cmp r3, #0x1f
	bgt _0820CFEC
	ldr r0, _0820CFE8 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #1
	lsls r1, r3
	b _0820CFFE
	.align 2, 0
_0820CFE8: .4byte 0x030046A0
_0820CFEC:
	ldr r0, _0820D008 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0820CFFE:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0820D004:
	pop {r0}
	bx r0
	.align 2, 0
_0820D008: .4byte 0x030046A0

