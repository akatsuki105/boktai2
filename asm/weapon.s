	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08242d90
FUN_08242d90:
	.byte 0x30, 0xB5, 0x89, 0xB0, 0x77, 0x20, 0xEE, 0xF7, 0xBB, 0xFB, 0x00, 0x28, 0x01, 0xD1, 0x00, 0x20
	.byte 0x81, 0xE0, 0x2C, 0x4C, 0xEE, 0xF7, 0x9E, 0xFC, 0xC1, 0x00, 0x09, 0x18, 0x89, 0x00, 0x68, 0x46
	.byte 0x09, 0x19, 0x1C, 0xC9, 0x1C, 0xC0, 0x1C, 0xC9, 0x1C, 0xC0, 0x1C, 0xC9, 0x1C, 0xC0, 0x71, 0x20
	.byte 0xEE, 0xF7, 0xA6, 0xFB, 0x00, 0x28, 0x03, 0xD0, 0xEE, 0xF7, 0x8C, 0xFC, 0x69, 0x46, 0x08, 0x81
	.byte 0x00, 0x24, 0x68, 0x46, 0x00, 0x78, 0xFF, 0xF7, 0xD1, 0xFF, 0x00, 0x28, 0x0B, 0xD1, 0x6F, 0x20
	.byte 0xEE, 0xF7, 0x96, 0xFB, 0x00, 0x28, 0x02, 0xD0, 0xEE, 0xF7, 0x7C, 0xFC, 0x04, 0x1C, 0x00, 0x2C
	.byte 0x01, 0xD1, 0x68, 0x46, 0x04, 0x76, 0x73, 0x20, 0xEE, 0xF7, 0x8A, 0xFB, 0x00, 0x28, 0x0A, 0xD0
	.byte 0x01, 0xAC, 0x01, 0x25, 0xEE, 0xF7, 0x6E, 0xFC, 0x00, 0x28, 0x00, 0xDD, 0x20, 0x76, 0x04, 0x34
	.byte 0x01, 0x3D, 0x00, 0x2D, 0xF6, 0xDA, 0x6E, 0x20, 0xEE, 0xF7, 0x7A, 0xFB, 0x00, 0x28, 0x3F, 0xD0
	.byte 0xEE, 0xF7, 0x60, 0xFC, 0x04, 0x1C, 0x00, 0x2C, 0x18, 0xD1, 0x0B, 0x48, 0x00, 0x68, 0xF0, 0x21
	.byte 0x89, 0x00, 0x43, 0x18, 0x00, 0x25, 0x1A, 0x78, 0x03, 0xA9, 0x00, 0x2A, 0x2D, 0xD0, 0x0C, 0x1C
	.byte 0x60, 0x19, 0x02, 0x70, 0x01, 0x33, 0x01, 0x35, 0x1A, 0x78, 0x00, 0x2A, 0x25, 0xD0, 0x0A, 0x2D
	.byte 0xF6, 0xDD, 0x22, 0xE0, 0x68, 0x9E, 0xDA, 0x08, 0xA0, 0x46, 0x00, 0x03, 0x72, 0x20, 0xEE, 0xF7
	.byte 0x57, 0xFB, 0x00, 0x28, 0x1C, 0xD0, 0xFA, 0xF7, 0x6B, 0xFA, 0x03, 0x1C, 0x00, 0x2B, 0x17, 0xD0
	.byte 0xEE, 0xF7, 0xF6, 0xFB, 0x00, 0x19, 0xEE, 0xF7, 0x7F, 0xFD, 0x03, 0x1C, 0x00, 0x25, 0x1A, 0x78
	.byte 0x03, 0xA9, 0x00, 0x2A, 0x09, 0xD0, 0x0C, 0x1C, 0x60, 0x19, 0x02, 0x70, 0x01, 0x33, 0x01, 0x35
	.byte 0x1A, 0x78, 0x00, 0x2A, 0x01, 0xD0, 0x0A, 0x2D, 0xF6, 0xDD, 0x49, 0x19, 0x00, 0x20, 0x08, 0x70
	.byte 0x68, 0x46, 0xFF, 0xF7, 0x71, 0xFE, 0x09, 0xB0, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_08242eb0
FUN_08242eb0: @ 0x08242EB0
	push {r4, r5, r6, lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _08242F00
	bl fetch_082316e4
	adds r6, r0, #0
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	bne _08242EE8
	b _08242F00
_08242ECE:
	lsls r1, r5, #3
	adds r1, r1, r5
	lsls r1, r1, #2
	ldr r0, _08242EE4 @ =0x08DA9E68
	adds r1, r1, r0
	adds r0, r4, #0
	bl FUN_08242b6c
	movs r0, #1
	b _08242F02
	.align 2, 0
_08242EE4: .4byte 0x08DA9E68
_08242EE8:
	bl fetch_082316e4
	adds r5, r0, #0
	movs r4, #0
_08242EF0:
	adds r0, r4, #0
	bl GetWeaponID
	cmp r0, r6
	beq _08242ECE
	adds r4, #1
	cmp r4, #0xf
	ble _08242EF0
_08242F00:
	movs r0, #0
_08242F02:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08242f08
FUN_08242f08: @ 0x08242F08
	push {lr}
	ldr r0, _08242F3C @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl FUN_08242c08
	ldr r0, _08242F40 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _08242F36
	movs r1, #0
	bl weapon_08064664
	bl FUN_0809c464
_08242F36:
	pop {r0}
	bx r0
	.align 2, 0
_08242F3C: .4byte 0x030046A0
_08242F40: .4byte 0x03002BE0

	thumb_func_start FUN_08242f44
FUN_08242f44: @ 0x08242F44
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	mov ip, r1
	movs r2, #0
	ldr r7, _08242F80 @ =0x030046A0
	adds r5, r7, #0
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
_08242F56:
	ldr r0, [r5]
	lsls r1, r2, #1
	adds r1, r1, r0
	adds r1, #0x60
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, r3
	bne _08242F68
	strh r4, [r1]
_08242F68:
	adds r2, #1
	cmp r2, #3
	ble _08242F56
	ldr r1, [r7]
	mov r2, ip
	lsls r0, r2, #1
	adds r0, r0, r1
	adds r0, #0x60
	strh r3, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08242F80: .4byte 0x030046A0

	thumb_func_start FUN_08242f84
FUN_08242f84: @ 0x08242F84
	ldr r1, _08242F98 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_08242F98: .4byte 0x030046A0

	thumb_func_start FUN_08242f9c
FUN_08242f9c: @ 0x08242F9C
	push {r4, r5, r6, lr}
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _08242FE2
	bl fetch_082316e4
	adds r6, r0, #0
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _08242FCA
	bl fetch_082316e4
	movs r5, #0x10
	cmp r0, #0
	beq _08242FCC
	movs r5, #0x30
	b _08242FCC
_08242FC6:
	movs r0, #1
	b _08242FE4
_08242FCA:
	movs r5, #0x10
_08242FCC:
	movs r4, #0
	cmp r4, r5
	bge _08242FE2
_08242FD2:
	adds r0, r4, #0
	bl GetWeaponID
	cmp r0, r6
	beq _08242FC6
	adds r4, #1
	cmp r4, r5
	blt _08242FD2
_08242FE2:
	movs r0, #0
_08242FE4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08242fec
FUN_08242fec: @ 0x08242FEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	movs r4, #0
	ldr r5, _08243050 @ =0x030046A0
	movs r3, #0x92
	lsls r3, r3, #4
	movs r2, #0
_08242FFA:
	ldr r1, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	adds r0, r0, r3
	str r2, [r0]
	adds r4, #1
	cmp r4, #1
	ble _08242FFA
	movs r4, #0
_0824300C:
	adds r0, r4, #0
	ldr r1, _08243054 @ =0x08DA9E68
	bl FUN_08242b6c
	adds r4, #1
	cmp r4, #0x2f
	ble _0824300C
	movs r4, #0
	ldr r5, _08243050 @ =0x030046A0
	adds r3, r5, #0
	movs r0, #1
	rsbs r0, r0, #0
	adds r2, r0, #0
_08243026:
	ldr r1, [r3]
	lsls r0, r4, #1
	adds r0, r0, r1
	adds r0, #0x60
	strh r2, [r0]
	adds r4, #1
	cmp r4, #3
	ble _08243026
	ldr r0, [r5]
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08243058
	bl fetch_082316e4
	adds r4, r0, #0
	b _0824305A
	.align 2, 0
_08243050: .4byte 0x030046A0
_08243054: .4byte 0x08DA9E68
_08243058:
	movs r4, #0
_0824305A:
	cmp r4, #0
	ble _082430C4
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _082430A2
	cmp r4, #0
	ble _082430A2
	ldr r6, _082430CC @ =0x08DA9E68
	mov r5, sp
_08243070:
	bl fetch_082316e4
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	mov r0, sp
	adds r1, r1, r6
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldrb r0, [r5]
	bl IsSpecialWeapon
	cmp r0, #0
	bne _08243096
	strb r0, [r5, #0x18]
_08243096:
	mov r0, sp
	bl FUN_08242b88
	subs r4, #1
	cmp r4, #0
	bne _08243070
_082430A2:
	movs r0, #0x71
	bl prepare_08231510
	cmp r0, #0
	beq _082430C4
	movs r4, #0
	ldr r5, _082430D0 @ =0x030046A0
_082430B0:
	bl fetch_082316e4
	ldr r2, [r5]
	lsls r1, r4, #1
	adds r1, r1, r2
	adds r1, #0x60
	strh r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _082430B0
_082430C4:
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082430CC: .4byte 0x08DA9E68
_082430D0: .4byte 0x030046A0

	thumb_func_start FUN_082430d4
FUN_082430d4: @ 0x082430D4
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r0, _082430F0 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x60
_082430E2:
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _082430F4
	movs r0, #1
	b _082430FE
	.align 2, 0
_082430F0: .4byte 0x030046A0
_082430F4:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _082430E2
	movs r0, #0
_082430FE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08243104
FUN_08243104: @ 0x08243104
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r4, #0
	ldr r6, _0824313C @ =0x08DA9E68
_0824310C:
	adds r0, r4, #0
	bl GetWeaponID
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r6
	ldrh r0, [r1, #0xa]
	cmp r0, #0
	beq _0824312C
	adds r0, r4, #0
	bl FUN_082430d4
	cmp r0, #0
	bne _0824312C
	adds r5, #1
_0824312C:
	adds r4, #1
	cmp r4, #0xf
	ble _0824310C
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0824313C: .4byte 0x08DA9E68

	thumb_func_start FUN_08243140
FUN_08243140: @ 0x08243140
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r4, #0
	ldr r6, _0824317C @ =0x08DA9E68
_08243148:
	adds r0, r4, #0
	bl GetWeaponID
	adds r1, r0, #0
	cmp r1, #0
	beq _08243162
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrh r0, [r0, #0xa]
	cmp r0, #0
	beq _0824316E
_08243162:
	adds r0, r4, #0
	bl FUN_082430d4
	cmp r0, #0
	bne _0824316E
	adds r5, #1
_0824316E:
	adds r4, #1
	cmp r4, #0xf
	ble _08243148
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0824317C: .4byte 0x08DA9E68

	thumb_func_start FUN_08243180
FUN_08243180: @ 0x08243180
	push {r4, lr}
	adds r4, r0, #0
	bl GetWeaponID
	adds r2, r0, #0
	cmp r2, #0
	beq _082431B0
	ldr r0, _082431AC @ =0x08DA9E68
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1, #0xa]
	cmp r0, #0
	beq _082431B0
	adds r0, r4, #0
	bl FUN_082430d4
	cmp r0, #0
	bne _082431B0
	movs r0, #1
	b _082431B2
	.align 2, 0
_082431AC: .4byte 0x08DA9E68
_082431B0:
	movs r0, #0
_082431B2:
	pop {r4}
	pop {r1}
	bx r1

