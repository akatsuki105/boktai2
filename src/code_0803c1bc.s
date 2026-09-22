	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804aa30
FUN_0804aa30: @ 0x0804AA30
	push {r4, lr}
	sub sp, #0x10
	str r1, [sp, #0xc]
	ldr r0, _0804AA84 @ =0x0000C091
	ldr r1, _0804AA88 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804AA8C @ =0x000092B3
	ldr r1, _0804AA90 @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804AA94 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	movs r0, #0
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804AA84: .4byte 0x0000C091
_0804AA88: .4byte 0x0000CD91
_0804AA8C: .4byte 0x000092B3
_0804AA90: .4byte 0x000026BB
_0804AA94: .4byte 0x03004250

	thumb_func_start FUN_0804aa98
FUN_0804aa98: @ 0x0804AA98
	push {r4, lr}
	sub sp, #0x10
	str r1, [sp, #0xc]
	ldr r0, _0804AAEC @ =0x0000C091
	ldr r1, _0804AAF0 @ =0x0000A413
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
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804AAF4 @ =0x000092B3
	ldr r1, _0804AAF8 @ =0x0000EFDA
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _0804AAFC @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
	movs r0, #0
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804AAEC: .4byte 0x0000C091
_0804AAF0: .4byte 0x0000A413
_0804AAF4: .4byte 0x000092B3
_0804AAF8: .4byte 0x0000EFDA
_0804AAFC: .4byte 0x030043F0

	thumb_func_start FUN_0804ab00
FUN_0804ab00: @ 0x0804AB00
	push {r4, r5, lr}
	adds r1, r0, #0
	adds r1, #0x58
	movs r2, #0
	adds r3, r0, #0
	adds r3, #0x2c
	movs r5, #2
	rsbs r5, r5, #0
	movs r4, #1
_0804AB12:
	ldrb r0, [r3]
	cmp r2, r0
	bge _0804AB1E
	ldr r0, [r1, #8]
	ands r0, r5
	b _0804AB22
_0804AB1E:
	ldr r0, [r1, #8]
	orrs r0, r4
_0804AB22:
	str r0, [r1, #8]
	adds r2, #1
	adds r1, #0x60
	cmp r2, #2
	ble _0804AB12
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ab34
FUN_0804ab34: @ 0x0804AB34
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0804AB5C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r4, #1
	movs r2, #1
	ands r2, r1
	cmp r2, #0
	beq _0804AB64
	ldr r1, _0804AB60 @ =0x030000D4
	adds r2, r3, #0
	adds r2, #0x2a
	movs r0, #0
	ldrsb r0, [r2, r0]
	str r0, [r1]
	ldrb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x2f
	movs r2, #0
	b _0804AB76
	.align 2, 0
_0804AB5C: .4byte 0x030044E0
_0804AB60: .4byte 0x030000D4
_0804AB64:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804AB70
	movs r0, #0
	b _0804AB88
_0804AB70:
	adds r1, r3, #0
	adds r1, #0x2f
	movs r0, #3
_0804AB76:
	strb r0, [r1]
	movs r1, #4
	adds r0, r3, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	str r2, [r3, #0x34]
	movs r0, #1
_0804AB88:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804ab90
FUN_0804ab90: @ 0x0804AB90
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _0804ABBC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804ABC0
	adds r4, r7, #0
	adds r4, #0x2a
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	movs r0, #0xdc
	bl PlaySound_082406e0
	adds r6, r4, #0
	b _0804ABD8
	.align 2, 0
_0804ABBC: .4byte 0x030044E0
_0804ABC0:
	movs r0, #0x80
	ands r0, r1
	adds r6, r7, #0
	adds r6, #0x2a
	cmp r0, #0
	beq _0804ABD8
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r0, #0xdc
	bl PlaySound_082406e0
_0804ABD8:
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bge _0804ABEE
	adds r1, r7, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r6]
	mov r8, r1
	b _0804AC02
_0804ABEE:
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r0, r7, #0
	adds r0, #0x2c
	mov r8, r0
	ldrb r0, [r0]
	cmp r1, r0
	blt _0804AC02
	movs r0, #0
	strb r0, [r6]
_0804AC02:
	adds r0, r7, #0
	adds r0, #0x2b
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r1, #0
	ldrsb r1, [r6, r1]
	mov sb, r0
	cmp r2, r1
	beq _0804AC6A
	adds r5, r7, #0
	adds r5, #0x58
	movs r4, #0
	mov r1, r8
	ldrb r1, [r1]
	cmp r4, r1
	bge _0804AC4E
_0804AC22:
	lsls r1, r4, #1
	adds r2, r1, #0
	adds r2, #0x1a
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r4, r0
	beq _0804AC32
	adds r2, #1
_0804AC32:
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #0
	bl MainSprite_SetPose
	adds r4, #1
	adds r5, #0x60
	mov r2, r8
	ldrb r2, [r2]
	cmp r4, r2
	blt _0804AC22
_0804AC4E:
	movs r4, #0
	ldrsb r4, [r6, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
_0804AC6A:
	ldrb r0, [r6]
	mov r2, sb
	strb r0, [r2]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804ac7c
FUN_0804ac7c: @ 0x0804AC7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x29
	ldrb r0, [r7]
	cmp r0, #0
	beq _0804AC96
	movs r0, #0
	strb r0, [r7]
_0804AC96:
	bl Save_ReadCurrentSlot
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0804AD24
	adds r6, r5, #0
	adds r6, #0x58
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x2c
	mov sl, r7
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x2a
	movs r0, #0x28
	adds r0, r0, r5
	mov sb, r0
	mov r1, r8
	ldrb r1, [r1]
	cmp r4, r1
	bge _0804ACEE
_0804ACC2:
	lsls r1, r4, #1
	adds r2, r1, #0
	adds r2, #0x1a
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r4, r0
	beq _0804ACD2
	adds r2, #1
_0804ACD2:
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	adds r1, #0x38
	movs r3, #0
	bl MainSprite_SetPose
	adds r4, #1
	adds r6, #0x60
	mov r2, r8
	ldrb r2, [r2]
	cmp r4, r2
	blt _0804ACC2
_0804ACEE:
	movs r4, #0
	ldrsb r4, [r7, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #3
	beq _0804AD14
	movs r0, #2
_0804AD14:
	movs r1, #0
	mov r2, sb
	strb r0, [r2]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	str r1, [r5, #0x34]
	b _0804AD30
_0804AD24:
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x28
	strb r1, [r0]
	strb r1, [r7]
	str r2, [r5, #0x34]
_0804AD30:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ad40
FUN_0804ad40: @ 0x0804AD40
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AD98
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804aa98
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	adds r2, r0, #0
	str r2, [r5]
	cmp r2, #0
	blt _0804AD90
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl FUN_0804a240
	ldr r0, [r5]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r5]
	bl FUN_0804a1f0
_0804AD90:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804AD98:
	ldr r2, [r4, #0x34]
	cmp r2, #0x1e
	bls _0804ADCC
	ldr r0, _0804ADC8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0804ADCC
	adds r1, r4, #0
	adds r1, #0x2f
	movs r2, #0
	movs r0, #3
	strb r0, [r1]
	movs r1, #4
	adds r0, r4, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x34]
	b _0804ADD0
	.align 2, 0
_0804ADC8: .4byte 0x030044E0
_0804ADCC:
	adds r0, r2, #1
	str r0, [r4, #0x34]
_0804ADD0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804add8
FUN_0804add8: @ 0x0804ADD8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AE2C
	movs r5, #0
	strb r5, [r1]
	adds r1, #3
	movs r0, #2
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0804aa30
	adds r0, r6, #0
	adds r0, #0x2a
	movs r4, #0
	ldrsb r4, [r0, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	bl FUN_08049f5c
	adds r0, r6, #0
	bl FUN_0804ab00
	adds r0, r6, #0
	adds r0, #0x2d
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_0804AE2C:
	ldr r0, [r6, #0x34]
	cmp r0, #0x1e
	bls _0804AE3C
	adds r0, r6, #0
	bl FUN_0804ab34
	cmp r0, #0
	bne _0804AEBA
_0804AE3C:
	adds r0, r6, #0
	bl FUN_0804ab90
	adds r2, r6, #0
	adds r2, #0x2d
	ldrb r3, [r2]
	ldr r0, [r6, #0x30]
	lsls r1, r3, #1
	adds r1, r1, r0
	ldr r0, _0804AE68 @ =0x030044E0
	ldrh r0, [r0, #2]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804AE6C
	adds r0, r3, #1
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x2e
	strb r1, [r0]
	adds r1, r0, #0
	b _0804AE7A
	.align 2, 0
_0804AE68: .4byte 0x030044E0
_0804AE6C:
	adds r1, r6, #0
	adds r1, #0x2e
	cmp r0, #0
	beq _0804AE7A
	movs r0, #0
	strb r0, [r2]
	strb r0, [r1]
_0804AE7A:
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x77
	bls _0804AE8E
	strb r3, [r2]
	strb r3, [r1]
_0804AE8E:
	ldrb r0, [r2]
	cmp r0, #0xf
	bls _0804AEB4
	movs r1, #3
	adds r0, r6, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r3, [r6, #0x34]
	ldr r1, _0804AEC0 @ =0x0000369F
	ldr r0, _0804AEC4 @ =gSystemSaveData
	ldr r0, [r0]
	str r1, [r0, #0x10]
	ldr r0, _0804AEC8 @ =0x00000296
	bl PlaySound_082406e0
_0804AEB4:
	ldr r0, [r6, #0x34]
	adds r0, #1
	str r0, [r6, #0x34]
_0804AEBA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804AEC0: .4byte 0x0000369F
_0804AEC4: .4byte gSystemSaveData
_0804AEC8: .4byte 0x00000296

	thumb_func_start FUN_0804aecc
FUN_0804aecc: @ 0x0804AECC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AF16
	movs r0, #0
	strb r0, [r1]
	adds r1, #3
	movs r0, #3
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0804aa30
	adds r0, r5, #0
	adds r0, #0x2a
	movs r4, #0
	ldrsb r4, [r0, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	bl FUN_08049f5c
	adds r0, r5, #0
	bl FUN_0804ab00
_0804AF16:
	ldr r0, [r5, #0x34]
	cmp r0, #0x1e
	bls _0804AF26
	adds r0, r5, #0
	bl FUN_0804ab34
	cmp r0, #0
	bne _0804AF32
_0804AF26:
	adds r0, r5, #0
	bl FUN_0804ab90
	ldr r0, [r5, #0x34]
	adds r0, #1
	str r0, [r5, #0x34]
_0804AF32:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804af38
FUN_0804af38: @ 0x0804AF38
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AF8A
	movs r5, #0
	strb r5, [r1]
	movs r0, #4
	str r0, [sp]
	ldr r0, _0804AF7C @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0804AF84
	ldr r0, _0804AF80 @ =0x0300481C
	str r5, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _0804AF8A
	.align 2, 0
_0804AF7C: .4byte 0x0000FFFF
_0804AF80: .4byte 0x0300481C
_0804AF84:
	movs r0, #0xdd
	bl PlaySound_082406e0
_0804AF8A:
	ldr r0, [r4, #0x34]
	cmp r0, #0x14
	bne _0804AFAA
	adds r0, r4, #0
	adds r0, #0x2f
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #2
	subs r0, #0x17
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804AFAA
	movs r1, #0
	bl Script_ExecById
_0804AFAA:
	ldr r0, [r4, #0x34]
	adds r0, #1
	str r0, [r4, #0x34]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804afb8
FUN_0804afb8: @ 0x0804AFB8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _0804B020 @ =0x085AB584
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r1, [r4]
	adds r1, #1
	movs r7, #0
	strh r1, [r4]
	ldr r2, _0804B024 @ =0x0000FFFF
	adds r6, r2, #0
	ldr r2, _0804B028 @ =0x085AB598
	adds r0, #2
	adds r3, r5, r0
	ldrh r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _0804B018
	strh r7, [r4]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ands r0, r6
	cmp r0, #5
	bls _0804B006
	strh r7, [r3]
_0804B006:
	ldr r1, _0804B02C @ =0x085AB5A4
	ldrh r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0804B018:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804B020: .4byte 0x085AB584
_0804B024: .4byte 0x0000FFFF
_0804B028: .4byte 0x085AB598
_0804B02C: .4byte 0x085AB5A4

	thumb_func_start FUN_0804b030
FUN_0804b030: @ 0x0804B030
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x58
	movs r5, #2
_0804B03A:
	adds r0, r4, #0
	bl MainSprite_Remove
	subs r5, #1
	adds r4, #0x60
	cmp r5, #0
	bge _0804B03A
	bl FUN_08049f84
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0804a16c
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b060
FUN_0804b060: @ 0x0804B060
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804B086
	bl FUN_0823d340
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	bne _0804B08C
_0804B086:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804B202
_0804B08C:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804B0AA
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #3
_0804B09C:
	bl Script_GetValue
	stm r4!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _0804B09C
	b _0804B0BC
_0804B0AA:
	adds r1, r6, #0
	adds r1, #0x18
	movs r2, #0
	adds r0, r6, #0
	adds r0, #0x24
_0804B0B4:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0804B0B4
_0804B0BC:
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	ldr r0, _0804B10C @ =0x0000CB05
	ldr r1, _0804B110 @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0804B086
	adds r1, r6, #0
	adds r1, #0x38
	adds r0, r2, #0
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x38
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r0, #0
	str r0, [r6, #0x34]
	ldr r0, _0804B114 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, _0804B118 @ =0x0000369F
	mov sb, r4
	cmp r1, r0
	bne _0804B11C
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #3
	b _0804B122
	.align 2, 0
_0804B10C: .4byte 0x0000CB05
_0804B110: .4byte 0x0000DCC1
_0804B114: .4byte gSystemSaveData
_0804B118: .4byte 0x0000369F
_0804B11C:
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #2
_0804B122:
	strb r0, [r1]
	ldr r0, _0804B138 @ =0x030000D4
	ldr r0, [r0]
	adds r3, r6, #0
	adds r3, #0x2a
	strb r0, [r3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _0804B13C
	movs r0, #0
	b _0804B148
	.align 2, 0
_0804B138: .4byte 0x030000D4
_0804B13C:
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldrb r2, [r1]
	cmp r0, r2
	blt _0804B14A
	subs r0, r2, #1
_0804B148:
	strb r0, [r3]
_0804B14A:
	adds r2, r6, #0
	adds r2, #0x2b
	movs r0, #0xff
	strb r0, [r2]
	cmp r5, #0
	beq _0804B168
	movs r0, #0
	adds r1, r6, #0
	adds r1, #0x28
	strb r0, [r1]
	subs r2, #2
	movs r1, #1
	strb r1, [r2]
	str r0, [r6, #0x34]
	b _0804B18A
_0804B168:
	ldrb r1, [r1]
	cmp r1, #3
	bne _0804B17A
	adds r0, r6, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x29
	b _0804B184
_0804B17A:
	movs r0, #2
	adds r1, r6, #0
	adds r1, #0x28
	strb r0, [r1]
	adds r1, #1
_0804B184:
	movs r0, #1
	strb r0, [r1]
	str r5, [r6, #0x34]
_0804B18A:
	ldr r2, _0804B210 @ =0xFFFF0000
	movs r1, #0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r0, _0804B214 @ =0x085AB564
	str r0, [r6, #0x30]
	adds r2, r6, #0
	adds r2, #0x2f
	movs r0, #3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x2d
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r1, _0804B218 @ =0x03003584
	ldr r1, [r1]
	ldr r2, _0804B21C @ =0x00005260
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #1
	bl CopyMemory
	adds r4, r6, #0
	adds r4, #0x58
	movs r3, #0
	mov r8, r3
	movs r7, #0xd8
	lsls r7, r7, #0xd
	movs r5, #2
_0804B1D0:
	lsrs r2, r7, #0x10
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r3, #0x11
	bl MainSprite_Add
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	str r0, [r4, #0x48]
	movs r3, #0x80
	lsls r3, r3, #0xa
	adds r7, r7, r3
	subs r5, #1
	adds r4, #0x60
	cmp r5, #0
	bge _0804B1D0
	movs r0, #0
_0804B202:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804B210: .4byte 0xFFFF0000
_0804B214: .4byte 0x085AB564
_0804B218: .4byte 0x03003584
_0804B21C: .4byte 0x00005260

	thumb_func_start FUN_0804b220
FUN_0804b220: @ 0x0804B220
	push {r4, lr}
	movs r1, #0xa1
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804B258
	ldr r1, _0804B250 @ =FUN_0804afb8
	ldr r2, _0804B254 @ =FUN_0804b030
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0804b060
	cmp r0, #0
	bge _0804B258
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804B25A
	.align 2, 0
_0804B250: .4byte FUN_0804afb8
_0804B254: .4byte FUN_0804b030
_0804B258:
	adds r0, r4, #0
_0804B25A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b260
FUN_0804b260: @ 0x0804B260
	push {lr}
	ldr r0, _0804B270 @ =0x030000D8
	ldr r0, [r0]
	cmp r0, #0
	bne _0804B274
	movs r0, #0
	b _0804B276
	.align 2, 0
_0804B270: .4byte 0x030000D8
_0804B274:
	movs r0, #1
_0804B276:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804b27c
FUN_0804b27c: @ 0x0804B27C
	push {r4, lr}
	ldr r0, _0804B2B4 @ =0x030000D8
	ldr r4, [r0]
	cmp r4, #0
	beq _0804B2AC
	adds r1, r4, #0
	adds r1, #0x39
	adds r2, r4, #0
	adds r2, #0x3a
	adds r3, r4, #0
	adds r3, #0x3b
	movs r0, #0
	bl rfu_REQBN_watchLink
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0804B2A8
	ldrb r1, [r4, #0x1a]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0x1a]
_0804B2A8:
	bl rfu_REQ_recvData
_0804B2AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804B2B4: .4byte 0x030000D8

	thumb_func_start FUN_0804b2b8
FUN_0804b2b8: @ 0x0804B2B8
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0804B2D8 @ =0x030000D8
	ldr r2, [r0]
	cmp r2, #0
	beq _0804B2D4
	cmp r1, #0
	beq _0804B2D4
	movs r0, #0xf0
	orrs r1, r0
	ldrb r0, [r2, #0x1a]
	orrs r1, r0
	strb r1, [r2, #0x1a]
_0804B2D4:
	pop {r0}
	bx r0
	.align 2, 0
_0804B2D8: .4byte 0x030000D8

	thumb_func_start FUN_0804b2dc
FUN_0804b2dc: @ 0x0804B2DC
	push {lr}
	bl FUN_0823a6c0
	cmp r0, #0
	blt _0804B33C
	ldr r0, _0804B328 @ =FUN_0804b2b8
	bl rfu_setREQCallback
	bl rfu_REQBN_softReset_and_checkID
	ldr r1, _0804B32C @ =0x00008001
	cmp r0, r1
	bne _0804B33C
	bl rfu_REQ_reset
	bl rfu_waitREQComplete
	movs r0, #0
	movs r1, #4
	movs r2, #0x20
	bl rfu_REQ_configSystem
	bl rfu_waitREQComplete
	ldr r2, _0804B330 @ =0x08251D30
	ldr r3, _0804B334 @ =0x08251D38
	movs r0, #0
	movs r1, #0x10
	bl rfu_REQ_configGameData
	bl rfu_waitREQComplete
	ldr r0, _0804B338 @ =FUN_0804b27c
	bl rfu_setMSCCallback
	movs r0, #0
	b _0804B340
	.align 2, 0
_0804B328: .4byte FUN_0804b2b8
_0804B32C: .4byte 0x00008001
_0804B330: .4byte 0x08251D30
_0804B334: .4byte 0x08251D38
_0804B338: .4byte FUN_0804b27c
_0804B33C:
	movs r0, #1
	rsbs r0, r0, #0
_0804B340:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b344
FUN_0804b344: @ 0x0804B344
	push {lr}
	movs r2, #0
	ldr r3, _0804B354 @ =0x03005800
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	movs r1, #1
	b _0804B368
	.align 2, 0
_0804B354: .4byte 0x03005800
_0804B358:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bhi _0804B36E
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r2
_0804B368:
	ands r0, r1
	cmp r0, #0
	beq _0804B358
_0804B36E:
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r2
	lsrs r0, r0, #0x18
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	bl rfu_clearAllSlot
	movs r0, #0
	bl rfu_setREQCallback
	bl rfu_REQ_stopMode
	bl rfu_waitREQComplete
	pop {r0}
	bx r0

	thumb_func_start FUN_0804b394
FUN_0804b394: @ 0x0804B394
	push {r4, lr}
	sub sp, #0x10
	str r1, [sp, #0xc]
	ldr r0, _0804B3E4 @ =0x0000C091
	ldr r1, _0804B3E8 @ =0x0000A413
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
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804B3EC @ =0x000092B3
	ldr r1, _0804B3F0 @ =0x0000EFDA
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804B3F4 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804B3E4: .4byte 0x0000C091
_0804B3E8: .4byte 0x0000A413
_0804B3EC: .4byte 0x000092B3
_0804B3F0: .4byte 0x0000EFDA
_0804B3F4: .4byte 0x03004250

	thumb_func_start FUN_0804b3f8
FUN_0804b3f8: @ 0x0804B3F8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #3
	bl FUN_0804b394
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	str r0, [r4, #0x30]
	adds r0, r4, #0
	bl FUN_0804b2dc
	cmp r0, #0
	blt _0804B448
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #0x18]
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B43E
	ldr r1, [r4, #0x28]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #2
	bl FUN_0804a2f8
	ldr r0, [r4, #0x30]
	bl FUN_0804a1f0
_0804B43E:
	bl rfu_REQ_startSearchParent
	bl rfu_waitREQComplete
	b _0804B46C
_0804B448:
	movs r1, #0
	strb r1, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B46C
	ldr r1, [r4, #0x28]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r4, #0x30]
	bl FUN_0804a1f0
_0804B46C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b474
FUN_0804b474: @ 0x0804B474
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B48A
	movs r0, #0
	strb r0, [r4, #0x19]
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B48A:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B4B4
	ldr r0, _0804B4B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B4B4
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B4B8
	.align 2, 0
_0804B4B0: .4byte 0x030044E0
_0804B4B4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B4B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b4c0
FUN_0804b4c0: @ 0x0804B4C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r6, _0804B4EC @ =0x085AB5B0
_0804B4C8:
	movs r3, #0
	movs r2, #0
	lsls r0, r4, #1
	adds r1, r0, r6
_0804B4D0:
	adds r0, r5, r2
	ldrb r0, [r0]
	ldrb r7, [r1]
	cmp r0, r7
	bne _0804B4DC
	adds r3, #1
_0804B4DC:
	adds r1, #1
	adds r2, #1
	cmp r2, #1
	ble _0804B4D0
	cmp r3, #2
	bne _0804B4F0
	adds r0, r4, #0
	b _0804B4FA
	.align 2, 0
_0804B4EC: .4byte 0x085AB5B0
_0804B4F0:
	adds r4, #1
	cmp r4, #3
	ble _0804B4C8
	movs r0, #1
	rsbs r0, r0, #0
_0804B4FA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b500
FUN_0804b500: @ 0x0804B500
	push {r4, r5, lr}
	lsls r2, r0, #1
	ldr r0, _0804B528 @ =0x085AB5B0
	ldr r5, _0804B52C @ =gSystemSaveData
	adds r3, r2, r0
	movs r4, #1
_0804B50C:
	ldrb r1, [r3]
	ldr r0, [r5]
	adds r0, #0x18
	adds r0, r0, r2
	strb r1, [r0]
	adds r3, #1
	subs r4, #1
	adds r2, #1
	cmp r4, #0
	bge _0804B50C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804B528: .4byte 0x085AB5B0
_0804B52C: .4byte gSystemSaveData

	thumb_func_start FUN_0804b530
FUN_0804b530: @ 0x0804B530
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x19]
	cmp r0, #0
	beq _0804B540
	movs r0, #0
	strb r0, [r5, #0x19]
	strb r0, [r5, #0x1b]
_0804B540:
	bl rfu_REQ_pollSearchParent
	bl rfu_waitREQComplete
	adds r4, r5, #0
	adds r4, #0x3c
	adds r2, r5, #0
	adds r2, #0x44
	movs r0, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Rfu_FindPartnerRecord
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	blt _0804B58C
	adds r0, r4, #0
	bl FUN_0804b4c0
	adds r1, r0, #0
	cmp r1, #0
	blt _0804B588
	adds r0, r5, #0
	adds r0, #0x20
	movs r4, #0
	strb r1, [r0]
	adds r0, r1, #0
	bl FUN_0804b500
	movs r0, #2
	strb r0, [r5, #0x18]
	movs r0, #1
	strb r0, [r5, #0x19]
	str r4, [r5, #0x24]
	b _0804B5E8
_0804B588:
	movs r0, #3
	b _0804B5D2
_0804B58C:
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0804B598
	movs r0, #1
	strb r0, [r5, #0x1b]
_0804B598:
	ldr r0, _0804B5AC @ =0x00000257
	ldr r2, [r5, #0x24]
	cmp r2, r0
	bls _0804B5B4
	ldrb r1, [r5, #0x1b]
	cmp r1, #0
	beq _0804B5B0
	movs r0, #3
	b _0804B5D2
	.align 2, 0
_0804B5AC: .4byte 0x00000257
_0804B5B0:
	movs r0, #4
	b _0804B5D4
_0804B5B4:
	cmp r2, #9
	bls _0804B5E4
	ldr r0, _0804B5E0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804B5E4
	adds r0, r5, #0
	bl FUN_0804b344
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
_0804B5D2:
	movs r1, #0
_0804B5D4:
	strb r0, [r5, #0x18]
	movs r0, #1
	strb r0, [r5, #0x19]
	str r1, [r5, #0x24]
	b _0804B5E8
	.align 2, 0
_0804B5E0: .4byte 0x030044E0
_0804B5E4:
	adds r0, r2, #1
	str r0, [r5, #0x24]
_0804B5E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b5f0
FUN_0804b5f0: @ 0x0804B5F0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B626
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r2, [r4, #0x30]
	movs r0, #7
_0804B602:
	subs r0, #1
	cmp r0, #0
	bge _0804B602
	cmp r2, #0
	blt _0804B61A
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r1, [r0]
	adds r1, #3
	adds r0, r2, #0
	bl FUN_0804a2f8
_0804B61A:
	ldr r0, _0804B648 @ =0x00000123
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0804b344
_0804B626:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B650
	ldr r0, _0804B64C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B650
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #5
	strb r1, [r4, #0x18]
	movs r1, #1
	strb r1, [r4, #0x19]
	b _0804B652
	.align 2, 0
_0804B648: .4byte 0x00000123
_0804B64C: .4byte 0x030044E0
_0804B650:
	adds r0, r2, #1
_0804B652:
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b65c
FUN_0804b65c: @ 0x0804B65C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B684
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B676
	movs r1, #7
	bl FUN_0804a2f8
_0804B676:
	adds r0, r4, #0
	bl FUN_0804b344
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B684:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B6B0
	ldr r0, _0804B6AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B6B0
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B6B4
	.align 2, 0
_0804B6AC: .4byte 0x030044E0
_0804B6B0:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B6B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b6bc
FUN_0804b6bc: @ 0x0804B6BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B6E4
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B6D6
	movs r1, #7
	bl FUN_0804a2f8
_0804B6D6:
	adds r0, r4, #0
	bl FUN_0804b344
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B6E4:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B710
	ldr r0, _0804B70C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B710
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B714
	.align 2, 0
_0804B70C: .4byte 0x030044E0
_0804B710:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B714:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b71c
FUN_0804b71c: @ 0x0804B71C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B73E
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B73E
	ldr r1, [r4, #0x2c]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #0xb
	bl FUN_0804a2f8
_0804B73E:
	ldr r0, [r4, #0x24]
	cmp r0, #0x3c
	bne _0804B76A
	bl Save_WriteSystemData
	movs r2, #0
	strb r0, [r4, #0x1f]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bne _0804B75E
	movs r0, #6
	strb r0, [r4, #0x18]
	strb r1, [r4, #0x19]
	str r2, [r4, #0x24]
	b _0804B76E
_0804B75E:
	movs r0, #7
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r2, [r4, #0x24]
	b _0804B76E
_0804B76A:
	adds r0, #1
	str r0, [r4, #0x24]
_0804B76E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804b774
FUN_0804b774: @ 0x0804B774
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B79C
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B79C
	ldr r1, [r4, #0x2c]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #0xe
	bl FUN_0804a2f8
	ldr r0, _0804B7BC @ =0x000002AE
	bl PlaySound_082406e0
_0804B79C:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B7C4
	ldr r0, _0804B7C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B7C4
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B7C8
	.align 2, 0
_0804B7BC: .4byte 0x000002AE
_0804B7C0: .4byte 0x030044E0
_0804B7C4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B7C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b7d0
FUN_0804b7d0: @ 0x0804B7D0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B7FA
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B7FA
	ldr r1, [r4, #0x2c]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #0xf
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B7FA:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B830
	ldr r0, _0804B820 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B830
	ldrb r0, [r4, #0x1e]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x1e]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0804B824
	movs r0, #8
	b _0804B826
	.align 2, 0
_0804B820: .4byte 0x030044E0
_0804B824:
	movs r0, #5
_0804B826:
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B834
_0804B830:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B834:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b83c
FUN_0804b83c: @ 0x0804B83C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B84A
	movs r0, #0
	strb r0, [r4, #0x19]
_0804B84A:
	ldr r1, [r4, #0x24]
	cmp r1, #0x14
	bne _0804B864
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _0804B864
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
	b _0804B868
_0804B864:
	adds r0, r1, #1
	str r0, [r4, #0x24]
_0804B868:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b870
FUN_0804b870: @ 0x0804B870
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B89A
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B892
	ldr r1, [r4, #0x28]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #0
	bl FUN_0804a2f8
_0804B892:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B89A:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B8C4
	ldr r0, _0804B8C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B8C4
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B8C8
	.align 2, 0
_0804B8C0: .4byte 0x030044E0
_0804B8C4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B8C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b8d0
FUN_0804b8d0: @ 0x0804B8D0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08241704
	ldr r0, _0804B920 @ =0x03002B54
	ldr r0, [r0]
	cmp r0, #0
	beq _0804B8E8
	ldrb r1, [r4, #0x1a]
	movs r0, #0x70
	orrs r0, r1
	strb r0, [r4, #0x1a]
_0804B8E8:
	ldrb r0, [r4, #0x18]
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0804B906
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804B906
	movs r0, #9
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
_0804B906:
	ldr r0, _0804B924 @ =0x085AB5B8
	ldrb r1, [r4, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804B920: .4byte 0x03002B54
_0804B924: .4byte 0x085AB5B8

	thumb_func_start FUN_0804b928
FUN_0804b928: @ 0x0804B928
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0824172c
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B940
	bl FUN_0804a210
	ldr r0, [r4, #0x30]
	bl FUN_0804a16c
_0804B940:
	ldr r1, _0804B94C @ =0x030000D8
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804B94C: .4byte 0x030000D8

	thumb_func_start FUN_0804b950
FUN_0804b950: @ 0x0804B950
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0804B990 @ =0x03002B54
	movs r0, #0
	str r0, [r1]
	ldr r0, _0804B994 @ =0x030000D8
	str r4, [r0]
	bl FUN_08241704
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804B98A
	bl FUN_0823d340
	str r0, [r4, #0x28]
	cmp r0, #0
	beq _0804B98A
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804B98A
	bl FUN_0823d340
	str r0, [r4, #0x2c]
	cmp r0, #0
	bne _0804B998
_0804B98A:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804B9B2
	.align 2, 0
_0804B990: .4byte 0x03002B54
_0804B994: .4byte 0x030000D8
_0804B998:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r4, #0x34]
	adds r0, r4, #0
	bl FUN_0804b3f8
	movs r0, #0
	movs r1, #0
	bl FUN_0804e9f4
	movs r0, #0
_0804B9B2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b9b8
FUN_0804b9b8: @ 0x0804B9B8
	push {r4, lr}
	movs r0, #2
	movs r1, #0x4c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804B9EC
	ldr r1, _0804B9E4 @ =FUN_0804b8d0
	ldr r2, _0804B9E8 @ =FUN_0804b928
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0804b950
	cmp r0, #0
	bge _0804B9EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804B9EE
	.align 2, 0
_0804B9E4: .4byte FUN_0804b8d0
_0804B9E8: .4byte FUN_0804b928
_0804B9EC:
	adds r0, r4, #0
_0804B9EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b9f4
FUN_0804b9f4: @ 0x0804B9F4
	push {r4, r5, r6, lr}
	bl Script_GetValue
	lsls r1, r0, #1
	movs r4, #0
	movs r3, #0
	ldr r0, _0804BA2C @ =gSystemSaveData
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #0x18
	ldr r0, _0804BA30 @ =0x085AB5B0
	adds r2, r1, r0
_0804BA0C:
	adds r0, r5, r1
	ldrb r0, [r0]
	ldrb r6, [r2]
	cmp r0, r6
	bne _0804BA18
	adds r4, #1
_0804BA18:
	adds r2, #1
	adds r3, #1
	adds r1, #1
	cmp r3, #1
	ble _0804BA0C
	cmp r4, #2
	beq _0804BA34
	movs r0, #0
	b _0804BA36
	.align 2, 0
_0804BA2C: .4byte gSystemSaveData
_0804BA30: .4byte 0x085AB5B0
_0804BA34:
	movs r0, #1
_0804BA36:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804ba3c
FUN_0804ba3c: @ 0x0804BA3C
	ldr r0, _0804BA44 @ =0x03002B58
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0804BA44: .4byte 0x03002B58

	thumb_func_start FUN_0804ba48
FUN_0804ba48: @ 0x0804BA48
	push {lr}
	ldr r0, _0804BA58 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	bne _0804BA5C
	movs r0, #0
	b _0804BA5E
	.align 2, 0
_0804BA58: .4byte 0x03002B58
_0804BA5C:
	movs r0, #1
_0804BA5E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804ba64
FUN_0804ba64: @ 0x0804BA64
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0
	strb r0, [r5, #0x1c]
	strb r0, [r5, #0x19]
	strb r0, [r5, #0x1a]
	strb r0, [r5, #0x1e]
	strb r0, [r5, #0x1f]
	adds r1, r5, #0
	adds r1, #0x20
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r1, #0
	strh r0, [r5, #0x22]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r6, _0804BB2C @ =0x030000DC
	movs r2, #0
	movs r1, #7
	adds r0, #8
_0804BA9C:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0804BA9C
	adds r0, r5, #0
	adds r0, #0x30
	movs r2, #0
	movs r3, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r4, r5, #0
	adds r4, #0x34
	strb r2, [r4]
	adds r0, #4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	strb r2, [r5, #0x1c]
	movs r1, #0
	strh r2, [r5, #0x38]
	str r2, [r5, #0x44]
	subs r0, #4
	strb r3, [r0]
	strh r2, [r5, #0x3a]
	adds r0, #0xa
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strh r2, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	str r2, [r5, #0x48]
	strb r1, [r6]
	adds r0, #0xb8
	strb r1, [r0]
	strb r1, [r4]
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r5, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r5, r1
	str r2, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x40
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #4
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0xa8
	movs r1, #0x10
	bl ClearMemory
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BB2C: .4byte 0x030000DC

	thumb_func_start FUN_0804bb30
FUN_0804bb30: @ 0x0804BB30
	push {lr}
	adds r2, r0, #0
	movs r0, #0
	strb r0, [r2, #0x1e]
	movs r1, #0
	strh r0, [r2, #0x22]
	adds r0, r2, #0
	adds r0, #0x35
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #6
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0x40
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804bb68
FUN_0804bb68: @ 0x0804BB68
	adds r2, r0, #0
	adds r2, #0xee
	strh r1, [r2]
	bx lr

	thumb_func_start FUN_0804bb70
FUN_0804bb70: @ 0x0804BB70
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xec
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0804BB8A
	movs r0, #1
	rsbs r0, r0, #0
	b _0804BB94
_0804BB8A:
	adds r0, r2, #0
	adds r0, #0xee
	ldrh r0, [r0]
	strh r0, [r3]
	movs r0, #0
_0804BB94:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804bb98
FUN_0804bb98: @ 0x0804BB98
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0xba
	lsls r2, r2, #1
	adds r0, r4, r2
	bl FUN_0823a7d8
	cmp r0, #0
	beq _0804BBE2
	movs r0, #0xfa
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x88
	lsls r2, r2, #1
	adds r3, r4, r2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r4, r0
	adds r4, #0xf0
	movs r5, #4
_0804BBC6:
	ldrh r0, [r3]
	strh r0, [r4]
	ldrh r0, [r2]
	ldrh r1, [r3]
	eors r0, r1
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0804BBC6
	movs r1, #0
	b _0804BBEA
_0804BBE2:
	movs r1, #2
	rsbs r1, r1, #0
	adds r4, #0xfa
	mov ip, r4
_0804BBEA:
	movs r0, #1
	mov r2, ip
	strb r0, [r2]
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804bbf8
FUN_0804bbf8: @ 0x0804BBF8
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x1b]
	cmp r0, #0
	bne _0804BC06
	movs r0, #0
	b _0804BC0C
_0804BC06:
	movs r0, #0
	strb r0, [r1, #0x1b]
	movs r0, #1
_0804BC0C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804bc10
FUN_0804bc10: @ 0x0804BC10
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	bne _0804BC1E
	movs r0, #0
	b _0804BC24
_0804BC1E:
	movs r0, #0
	strb r0, [r1, #0x1c]
	movs r0, #1
_0804BC24:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804bc28
FUN_0804bc28: @ 0x0804BC28
	push {r4, r5, lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0x27
	movs r0, #0
	strb r0, [r1]
	movs r2, #0
	ldr r4, _0804BCA0 @ =0x03005800
	ldr r0, [r4]
	adds r5, r4, #0
	ldrb r0, [r0, #8]
	cmp r2, r0
	bge _0804BC7C
	adds r3, r1, #0
_0804BC44:
	mov r0, ip
	adds r0, #0x26
	ldrb r0, [r0]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BC70
	ldr r0, [r4]
	lsls r1, r2, #5
	adds r0, r0, r1
	ldrb r0, [r0, #0x16]
	cmp r0, #3
	bhi _0804BC70
	mov r0, ip
	adds r0, #0x28
	ldrb r1, [r3]
	adds r0, r0, r1
	strb r2, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_0804BC70:
	adds r2, #1
	adds r4, r5, #0
	ldr r0, [r4]
	ldrb r0, [r0, #8]
	cmp r2, r0
	blt _0804BC44
_0804BC7C:
	mov r0, ip
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r0, #2
	adds r0, #3
	cmp r1, #0
	bge _0804BC96
	adds r2, r1, #0
_0804BC90:
	adds r2, #1
	cmp r2, #0
	blt _0804BC90
_0804BC96:
	adds r2, r1, #0
	cmp r2, #0
	bge _0804BCA6
	movs r2, #0
	b _0804BCA6
	.align 2, 0
_0804BCA0: .4byte 0x03005800
_0804BCA4:
	adds r2, #1
_0804BCA6:
	adds r1, r0, #0
	cmp r0, #8
	ble _0804BCAE
	movs r1, #8
_0804BCAE:
	cmp r2, r1
	blt _0804BCA4
	cmp r0, #7
	ble _0804BCC2
	cmp r2, r0
	bge _0804BCC2
	subs r2, r0, r2
_0804BCBC:
	subs r2, #1
	cmp r2, #0
	bne _0804BCBC
_0804BCC2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804bcc8
FUN_0804bcc8: @ 0x0804BCC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r0, sp
	movs r4, #0
	strh r4, [r0]
	ldr r2, _0804BD08 @ =0x01000020
	adds r1, r5, #0
	bl CpuSet
	ldrh r1, [r7, #0x22]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BD10
	movs r0, #1
	strb r0, [r5]
	ldrh r0, [r7, #0x22]
	movs r1, #8
	orrs r0, r1
	orrs r0, r4
	ldr r1, _0804BD0C @ =0x0000FEFF
	ands r0, r1
	strh r0, [r7, #0x22]
	b _0804BD12
	.align 2, 0
_0804BD08: .4byte 0x01000020
_0804BD0C: .4byte 0x0000FEFF
_0804BD10:
	strb r4, [r5]
_0804BD12:
	ldrh r1, [r7, #0x22]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _0804BD38
	movs r0, #1
	strb r0, [r5, #1]
	ldrh r1, [r7, #0x22]
	movs r0, #0x10
	orrs r0, r1
	ldr r1, _0804BD34 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r7, #0x22]
	b _0804BD3A
	.align 2, 0
_0804BD34: .4byte 0x0000FDFF
_0804BD38:
	strb r0, [r5, #1]
_0804BD3A:
	movs r0, #1
	strb r0, [r5, #3]
	movs r3, #0
	ldr r4, _0804BDD0 @ =0x03005800
	adds r2, r5, #4
	movs r1, #1
_0804BD46:
	ldrb r0, [r7, #0x19]
	asrs r0, r3
	ands r0, r1
	cmp r0, #0
	beq _0804BD56
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
_0804BD56:
	adds r3, #1
	cmp r3, #3
	ble _0804BD46
	ldrb r0, [r7, #0x19]
	lsls r0, r0, #1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #2]
	ldr r0, [r4]
	adds r0, #0xa9
	adds r1, r2, #0
	movs r2, #8
	bl StrCopyPadded
	ldr r1, [r4]
	adds r1, #0x94
	ldrh r1, [r1]
	strh r1, [r5, #0x36]
	movs r3, #0
	mov r8, r4
_0804BD7E:
	ldrb r2, [r7, #0x19]
	asrs r2, r3
	movs r1, #1
	ands r2, r1
	adds r6, r3, #1
	cmp r2, #0
	beq _0804BDBC
	lsls r4, r3, #5
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	adds r0, #0x15
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, #0xe
	adds r1, r5, r1
	movs r2, #8
	bl StrCopyPadded
	lsls r1, r6, #1
	adds r2, r5, #0
	adds r2, #0x36
	adds r2, r2, r1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r1, r4
	ldrh r1, [r1, #0x14]
	strh r1, [r2]
_0804BDBC:
	adds r3, r6, #0
	cmp r3, #3
	ble _0804BD7E
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804BDD0: .4byte 0x03005800

	thumb_func_start FUN_0804bdd4
FUN_0804bdd4: @ 0x0804BDD4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	ldrh r2, [r4, #0x22]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	bne _0804BDF8
	ldr r0, _0804BDFC @ =0x03005800
	ldr r1, [r0]
	ldrb r1, [r1, #3]
	adds r6, r0, #0
	cmp r1, #0
	bne _0804BDF8
	movs r0, #0xa0
	ands r0, r2
	cmp r0, #0
	beq _0804BE00
_0804BDF8:
	movs r0, #0
	b _0804BECC
	.align 2, 0
_0804BDFC: .4byte 0x03005800
_0804BE00:
	ldrh r0, [r4, #0x38]
	cmp r0, #9
	bne _0804BE18
	movs r0, #0x84
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	bne _0804BE18
	ldr r1, _0804BEB4 @ =0x00000205
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r4, #0x22]
_0804BE18:
	ldrb r0, [r4, #0x19]
	ldrb r1, [r4, #0x1a]
	adds r3, r0, #0
	cmp r1, r3
	beq _0804BE3A
	ldrh r1, [r4, #0x22]
	movs r0, #4
	movs r2, #0
	orrs r1, r0
	strh r1, [r4, #0x22]
	ldr r0, [r6]
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _0804BE3A
	movs r0, #1
	orrs r1, r0
	strh r1, [r4, #0x22]
_0804BE3A:
	strb r3, [r4, #0x1a]
	ldrh r1, [r4, #0x22]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0804BE56
	adds r0, r4, #0
	bl FUN_0804bcc8
	ldrh r1, [r4, #0x22]
	ldr r0, _0804BEB8 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4, #0x22]
	movs r7, #1
_0804BE56:
	ldrh r1, [r4, #0x22]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0804BECA
	ldrb r0, [r4, #0x19]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r1, #0x43
	movs r3, #0x40
	bl rfu_NI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804BEC4
	movs r2, #0
	ldr r0, _0804BEBC @ =0x03005800
	ldr r1, [r0]
	ldrb r1, [r1, #2]
	ands r1, r5
	adds r6, r0, #0
	adds r5, r4, #0
	adds r5, #0x20
	cmp r1, #0
	bne _0804BEA2
	adds r3, r6, #0
	movs r1, #1
_0804BE90:
	adds r2, #1
	cmp r2, #3
	bgt _0804BEA2
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r2
	ands r0, r1
	cmp r0, #0
	beq _0804BE90
_0804BEA2:
	strb r2, [r5]
	ldrh r0, [r4, #0x22]
	ldr r1, _0804BEC0 @ =0x0000FFFE
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strh r1, [r4, #0x22]
	b _0804BECA
	.align 2, 0
_0804BEB4: .4byte 0x00000205
_0804BEB8: .4byte 0x0000FFFB
_0804BEBC: .4byte 0x03005800
_0804BEC0: .4byte 0x0000FFFE
_0804BEC4:
	movs r0, #2
	bl FUN_0804e584
_0804BECA:
	adds r0, r7, #0
_0804BECC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804bed4
FUN_0804bed4: @ 0x0804BED4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804BF8A
	ldr r1, _0804BF3C @ =0x030057F0
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r3, [r0]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	cmp r0, #0x26
	bne _0804BF48
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	ldrb r0, [r2, #0x1a]
	adds r5, r0, #0
	eors r5, r1
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	ldrh r0, [r4, #0x22]
	ldr r2, _0804BF40 @ =0x0000FFFD
	ands r2, r0
	strh r2, [r4, #0x22]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0804BF24
	movs r1, #0x80
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4, #0x22]
_0804BF24:
	ldrh r1, [r4, #0x22]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0804BF7C
	ldr r0, _0804BF44 @ =0x0000FFF7
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r4, #0x22]
	b _0804BF7C
	.align 2, 0
_0804BF3C: .4byte 0x030057F0
_0804BF40: .4byte 0x0000FFFD
_0804BF44: .4byte 0x0000FFF7
_0804BF48:
	cmp r0, #0x27
	bne _0804BF7C
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	ldrb r0, [r2, #0x1a]
	adds r5, r0, #0
	eors r5, r1
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	movs r2, #0
	strh r2, [r4, #0x22]
	ldrh r0, [r4, #0x38]
	cmp r0, #9
	bne _0804BF7C
	movs r0, #7
	movs r1, #0
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r2, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804BF7C:
	cmp r5, #0
	beq _0804BF8A
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	orrs r5, r0
	strb r5, [r1]
_0804BF8A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804bf90
FUN_0804bf90: @ 0x0804BF90
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _0804BFC4 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	bne _0804BFA0
	b _0804C184
_0804BFA0:
	cmp r3, #0x33
	bne _0804BFA6
	b _0804C0C4
_0804BFA6:
	cmp r3, #0x33
	bgt _0804BFE6
	cmp r3, #0x13
	beq _0804C058
	cmp r3, #0x13
	bgt _0804BFCE
	cmp r3, #0x10
	bne _0804BFB8
	b _0804C184
_0804BFB8:
	cmp r3, #0x10
	bgt _0804BFC8
	cmp r3, #0
	beq _0804C036
	b _0804C184
	.align 2, 0
_0804BFC4: .4byte 0x03002B58
_0804BFC8:
	cmp r3, #0x11
	beq _0804C046
	b _0804C184
_0804BFCE:
	cmp r3, #0x30
	beq _0804C0C4
	cmp r3, #0x30
	bgt _0804BFDC
	cmp r3, #0x14
	beq _0804C06A
	b _0804C184
_0804BFDC:
	cmp r3, #0x31
	beq _0804C09A
	cmp r3, #0x32
	beq _0804C0B0
	b _0804C184
_0804BFE6:
	cmp r3, #0x44
	bne _0804BFEC
	b _0804C148
_0804BFEC:
	cmp r3, #0x44
	bgt _0804C010
	cmp r3, #0x41
	bne _0804BFF6
	b _0804C184
_0804BFF6:
	cmp r3, #0x41
	bgt _0804C002
	cmp r3, #0x40
	bne _0804C000
	b _0804C0F4
_0804C000:
	b _0804C184
_0804C002:
	cmp r3, #0x42
	bne _0804C008
	b _0804C124
_0804C008:
	cmp r3, #0x43
	bne _0804C00E
	b _0804C136
_0804C00E:
	b _0804C184
_0804C010:
	cmp r3, #0xf1
	bne _0804C016
	b _0804C166
_0804C016:
	cmp r3, #0xf1
	bgt _0804C028
	cmp r3, #0x50
	bne _0804C020
	b _0804C17E
_0804C020:
	cmp r3, #0xf0
	bne _0804C026
	b _0804C166
_0804C026:
	b _0804C184
_0804C028:
	cmp r3, #0xf2
	bne _0804C02E
	b _0804C166
_0804C02E:
	cmp r3, #0xff
	bne _0804C034
	b _0804C15A
_0804C034:
	b _0804C184
_0804C036:
	movs r0, #5
	strb r3, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r3, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C046:
	ldr r0, _0804C054 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r4, #0x19]
	orrs r0, r1
	strb r0, [r4, #0x19]
	b _0804C184
	.align 2, 0
_0804C054: .4byte 0x03004740
_0804C058:
	movs r1, #5
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C06A:
	ldr r0, _0804C084 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #1]
	cmp r1, #0
	bne _0804C088
	movs r0, #5
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
	.align 2, 0
_0804C084: .4byte 0x03005800
_0804C088:
	movs r1, #9
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C09A:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804C0AC @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804C184
	.align 2, 0
_0804C0AC: .4byte 0x03004740
_0804C0B0:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804C0C0 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804C184
	.align 2, 0
_0804C0C0: .4byte 0x03004740
_0804C0C4:
	ldr r2, _0804C0F0 @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r4, #0x19]
	bics r0, r1
	strb r0, [r4, #0x19]
	adds r3, r4, #0
	adds r3, #0x25
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0x19]
	cmp r1, #0
	bne _0804C184
	movs r0, #0xb
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
	.align 2, 0
_0804C0F0: .4byte 0x03004740
_0804C0F4:
	ldr r2, _0804C120 @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r4, #0x19]
	bics r0, r1
	strb r0, [r4, #0x19]
	adds r3, r4, #0
	adds r3, #0x25
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0x19]
	cmp r1, #0
	bne _0804C184
	movs r0, #0xb
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
	.align 2, 0
_0804C120: .4byte 0x03004740
_0804C124:
	movs r1, #0x20
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C136:
	movs r1, #5
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C148:
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C15A:
	ldrh r0, [r4, #0x38]
	cmp r0, #0x1c
	beq _0804C17E
	cmp r0, #1
	bls _0804C17E
	b _0804C16C
_0804C166:
	ldrh r0, [r4, #0x38]
	cmp r0, #0x1c
	beq _0804C17E
_0804C16C:
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804C17E:
	ldr r1, _0804C18C @ =0x030000DC
	movs r0, #0
_0804C182:
	strb r0, [r1]
_0804C184:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C18C: .4byte 0x030000DC

	thumb_func_start FUN_0804c190
FUN_0804c190: @ 0x0804C190
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _0804C1C0 @ =0x03002B58
	ldr r5, [r0]
	cmp r5, #0
	bne _0804C1A0
	b _0804C3A2
_0804C1A0:
	cmp r3, #0x33
	bne _0804C1A6
	b _0804C30C
_0804C1A6:
	cmp r3, #0x33
	bgt _0804C1EE
	cmp r3, #0x23
	beq _0804C290
	cmp r3, #0x23
	bgt _0804C1CE
	cmp r3, #0x20
	beq _0804C24E
	cmp r3, #0x20
	bgt _0804C1C4
	cmp r3, #0
	beq _0804C244
	b _0804C3A2
	.align 2, 0
_0804C1C0: .4byte 0x03002B58
_0804C1C4:
	cmp r3, #0x21
	beq _0804C260
	cmp r3, #0x22
	beq _0804C264
	b _0804C3A2
_0804C1CE:
	cmp r3, #0x30
	bne _0804C1D4
	b _0804C30C
_0804C1D4:
	cmp r3, #0x30
	bgt _0804C1E2
	cmp r3, #0x24
	beq _0804C294
	cmp r3, #0x25
	beq _0804C2BC
	b _0804C3A2
_0804C1E2:
	cmp r3, #0x31
	beq _0804C2C0
	cmp r3, #0x32
	bne _0804C1EC
	b _0804C2E8
_0804C1EC:
	b _0804C3A2
_0804C1EE:
	cmp r3, #0x45
	bne _0804C1F4
	b _0804C3A2
_0804C1F4:
	cmp r3, #0x45
	bgt _0804C218
	cmp r3, #0x42
	bne _0804C1FE
	b _0804C36C
_0804C1FE:
	cmp r3, #0x42
	bgt _0804C20A
	cmp r3, #0x40
	bne _0804C208
	b _0804C346
_0804C208:
	b _0804C3A2
_0804C20A:
	cmp r3, #0x43
	bne _0804C210
	b _0804C370
_0804C210:
	cmp r3, #0x44
	bne _0804C216
	b _0804C374
_0804C216:
	b _0804C3A2
_0804C218:
	cmp r3, #0xf1
	bne _0804C21E
	b _0804C378
_0804C21E:
	cmp r3, #0xf1
	bgt _0804C22E
	cmp r3, #0x50
	beq _0804C23C
	cmp r3, #0xf0
	bne _0804C22C
	b _0804C378
_0804C22C:
	b _0804C3A2
_0804C22E:
	cmp r3, #0xf2
	bne _0804C234
	b _0804C38A
_0804C234:
	cmp r3, #0xff
	bne _0804C23A
	b _0804C380
_0804C23A:
	b _0804C3A2
_0804C23C:
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	b _0804C3A2
_0804C244:
	movs r0, #6
	strb r3, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r3, [r5, #0x44]
	b _0804C39A
_0804C24E:
	ldr r0, _0804C25C @ =0x03004740
	ldrh r1, [r0, #0x14]
	adds r0, r5, #0
	adds r0, #0x26
	strb r1, [r0]
	b _0804C3A2
	.align 2, 0
_0804C25C: .4byte 0x03004740
_0804C260:
	movs r1, #6
	b _0804C392
_0804C264:
	ldr r0, _0804C28C @ =0x03004740
	ldrh r0, [r0, #0x14]
	adds r1, r5, #0
	adds r1, #0x21
	movs r4, #0
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r0, #0x20
	movs r3, #0x40
	bl rfu_setRecvBuffer
	movs r0, #0xe
	strb r4, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r4, [r5, #0x44]
	b _0804C39A
	.align 2, 0
_0804C28C: .4byte 0x03004740
_0804C290:
	movs r1, #6
	b _0804C392
_0804C294:
	adds r1, r5, #0
	adds r1, #0x43
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0804C2B8 @ =0x03005800
	ldr r0, [r0]
	ldrb r3, [r0, #2]
	subs r3, #1
	cmp r3, #0
	bne _0804C2AA
	b _0804C3A2
_0804C2AA:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	subs r3, #1
	cmp r3, #0
	bne _0804C2AA
	b _0804C3A2
	.align 2, 0
_0804C2B8: .4byte 0x03005800
_0804C2BC:
	movs r1, #6
	b _0804C392
_0804C2C0:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C2E4 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	movs r3, #0
	strb r0, [r2]
	ldrh r1, [r5, #0x38]
	adds r0, r5, #0
	adds r0, #0x40
	movs r2, #0
	strh r1, [r0]
	movs r0, #0x10
	strb r2, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r3, [r5, #0x44]
	b _0804C39A
	.align 2, 0
_0804C2E4: .4byte 0x03004740
_0804C2E8:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C308 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	b _0804C39A
	.align 2, 0
_0804C308: .4byte 0x03004740
_0804C30C:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C338 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	movs r1, #0
	strb r0, [r2]
	ldrh r0, [r5, #0x38]
	cmp r0, #0xf
	bls _0804C33C
	movs r0, #0x1d
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	bl rfu_LMAN_stopManager
	b _0804C3A2
	.align 2, 0
_0804C338: .4byte 0x03004740
_0804C33C:
	movs r0, #0xb
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	b _0804C39A
_0804C346:
	movs r1, #0xb
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C368 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804C3A2
	.align 2, 0
_0804C368: .4byte 0x03004740
_0804C36C:
	movs r1, #0x20
	b _0804C392
_0804C370:
	movs r1, #6
	b _0804C392
_0804C374:
	movs r1, #0x1e
	b _0804C392
_0804C378:
	ldrh r0, [r5, #0x38]
	cmp r0, #0x1c
	beq _0804C3A2
	b _0804C38A
_0804C380:
	ldrh r0, [r5, #0x38]
	cmp r0, #0x1c
	beq _0804C3A2
	cmp r0, #1
	bls _0804C3A2
_0804C38A:
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1c
_0804C392:
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
_0804C39A:
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804C3A2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804c3a8
FUN_0804c3a8: @ 0x0804C3A8
	push {lr}
	bl rfu_REQ_recvData
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804c3b4
FUN_0804c3b4: @ 0x0804C3B4
	push {lr}
	ldr r0, _0804C3C8 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804C3C2
	bl rfu_REQ_recvData
_0804C3C2:
	pop {r0}
	bx r0
	.align 2, 0
_0804C3C8: .4byte 0x03002B58

	thumb_func_start FUN_0804c3cc
FUN_0804c3cc: @ 0x0804C3CC
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804C3DE
	movs r1, #0
	strb r1, [r2]
_0804C3DE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c3e4
FUN_0804c3e4: @ 0x0804C3E4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804C3F6
	movs r0, #0
	strb r0, [r5]
_0804C3F6:
	ldr r0, _0804C418 @ =FUN_0804bf90
	ldr r1, _0804C41C @ =FUN_0804c3a8
	bl rfu_LMAN_initializeManager
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0804C420
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
	b _0804C42E
	.align 2, 0
_0804C418: .4byte FUN_0804bf90
_0804C41C: .4byte FUN_0804c3a8
_0804C420:
	movs r0, #2
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
	strb r0, [r4, #0x18]
_0804C42E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c438
FUN_0804c438: @ 0x0804C438
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x32
	ldrb r0, [r7]
	cmp r0, #0
	beq _0804C44C
	movs r0, #0
	strb r0, [r7]
_0804C44C:
	adds r4, r5, #0
	adds r4, #0x3c
	ldrb r0, [r4]
	adds r6, r0, #0
	cmp r6, #0
	beq _0804C45E
	subs r0, #1
	strb r0, [r4]
	b _0804C568
_0804C45E:
	bl FUN_0823a6fc
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C48A
	cmp r1, #0
	bgt _0804C476
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804C47C
	b _0804C568
_0804C476:
	cmp r1, #1
	beq _0804C490
	b _0804C568
_0804C47C:
	movs r0, #0x1b
	strb r6, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r6, [r5, #0x44]
	movs r0, #1
	strb r0, [r7]
	b _0804C568
_0804C48A:
	movs r0, #0x3c
	strb r0, [r4]
	b _0804C568
_0804C490:
	movs r4, #3
	strb r6, [r5, #0x1c]
	strh r4, [r5, #0x38]
	str r6, [r5, #0x44]
	strb r1, [r7]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r6, r0, #0
	ldr r2, _0804C4DC @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _0804C4E0 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	ldr r7, _0804C4E4 @ =0x0203B400
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _0804C4F2
	bl FUN_0823e1b0
	adds r4, r0, #0
	bl GetHour
	adds r1, r0, #0
	subs r4, #1
	cmp r4, #2
	bhi _0804C4E8
	movs r0, #1
	cmp r1, #0xb
	bgt _0804C504
	movs r0, #0
	b _0804C504
	.align 2, 0
_0804C4DC: .4byte 0x030046B8
_0804C4E0: .4byte 0x000003FF
_0804C4E4: .4byte 0x0203B400
_0804C4E8:
	movs r0, #3
	cmp r1, #0xb
	bgt _0804C504
	movs r0, #2
	b _0804C504
_0804C4F2:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0804C574 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ands r0, r4
	adds r0, #4
_0804C504:
	adds r0, r6, r0
	bl Textbox_LookupString
	adds r4, r0, #0
	ldr r0, _0804C578 @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0xf0
	lsls r7, r7, #2
	adds r0, r0, r7
	adds r7, r5, #0
	adds r7, #0x60
	adds r1, r7, #0
	movs r2, #8
	bl FUN_0804e6d8
	adds r6, r5, #0
	adds r6, #0x50
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xb
	bl FUN_0804e6d8
	adds r1, r5, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r2, r5, #0
	adds r2, #0x5b
	strb r0, [r2]
	ldrh r0, [r1]
	lsrs r0, r0, #8
	subs r1, #0x10
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r3, #0
	cmp r1, #0
	beq _0804C558
	movs r3, #3
_0804C558:
	movs r0, #0
	str r0, [sp]
	str r6, [sp, #4]
	str r7, [sp, #8]
	adds r0, r2, #0
	movs r2, #0x11
	bl FUN_0823a730
_0804C568:
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804C574: .4byte 0x0203B400
_0804C578: .4byte 0x030046A0

	thumb_func_start FUN_0804c57c
FUN_0804c57c: @ 0x0804C57C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804C58E
	movs r0, #0
	strb r0, [r5]
_0804C58E:
	ldr r0, [r4, #0x44]
	cmp r0, #0x3b
	bls _0804C5B2
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl rfu_LMAN_initializeRFU
	ldr r1, _0804C5BC @ =0x030000DC
	movs r0, #0
	strb r0, [r1]
	movs r1, #4
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
_0804C5B2:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804C5BC: .4byte 0x030000DC

	thumb_func_start FUN_0804c5c0
FUN_0804c5c0: @ 0x0804C5C0
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C5D0
	movs r0, #0
	strb r0, [r1]
_0804C5D0:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c5d8
FUN_0804c5d8: @ 0x0804C5D8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C604
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0xa8
_0804C5F0:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x20
	adds r2, r6, #0
	movs r3, #4
	bl rfu_setRecvBuffer
	adds r4, #1
	cmp r4, #3
	ble _0804C5F0
_0804C604:
	movs r2, #0x96
	lsls r2, r2, #2
	ldr r3, _0804C634 @ =0x08251D40
	movs r0, #1
	movs r1, #0
	bl rfu_LMAN_establishConnection
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0
	beq _0804C638
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	subs r0, #2
	b _0804C648
	.align 2, 0
_0804C634: .4byte 0x08251D40
_0804C638:
	movs r1, #7
	strb r2, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r2, [r5, #0x44]
	adds r2, r5, #0
	adds r2, #0x32
	movs r1, #1
	strb r1, [r2]
_0804C648:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c650
FUN_0804c650: @ 0x0804C650
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804C668
	movs r0, #0
	strb r0, [r5]
	adds r1, r4, #0
	adds r1, #0x26
	strb r0, [r1]
_0804C668:
	movs r2, #0x96
	lsls r2, r2, #2
	ldr r3, _0804C694 @ =0x08251D40
	movs r0, #0
	movs r1, #0
	bl rfu_LMAN_establishConnection
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0
	beq _0804C698
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
	subs r0, #2
	b _0804C6A4
	.align 2, 0
_0804C694: .4byte 0x08251D40
_0804C698:
	movs r1, #8
	strb r2, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r2, [r4, #0x44]
	movs r1, #1
	strb r1, [r5]
_0804C6A4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c6ac
FUN_0804c6ac: @ 0x0804C6AC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C6C2
	movs r0, #0
	strb r0, [r1]
	strb r0, [r4, #0x1b]
	strb r0, [r4, #0x1c]
_0804C6C2:
	adds r0, r4, #0
	bl FUN_0804bbf8
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C6F0
	ldr r2, _0804C76C @ =0x00000135
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _0804C6EC
	ldrh r2, [r4, #0x22]
	movs r1, #0x8e
	lsls r1, r1, #2
	ands r1, r2
	cmp r1, #0
	bne _0804C6EC
	ldr r3, _0804C770 @ =0x00000105
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r4, #0x22]
_0804C6EC:
	movs r1, #0
	strb r1, [r4, #0x1b]
_0804C6F0:
	ldrh r2, [r4, #0x22]
	movs r1, #0x40
	ands r1, r2
	cmp r1, #0
	beq _0804C70C
	movs r1, #0xce
	lsls r1, r1, #2
	ands r1, r2
	cmp r1, #0
	bne _0804C70C
	ldr r3, _0804C770 @ =0x00000105
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r4, #0x22]
_0804C70C:
	ldr r2, _0804C774 @ =0x030057F0
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r1, [r5]
	lsls r3, r1, #2
	adds r2, r3, r2
	ldr r1, [r2]
	ldrh r1, [r1, #0x34]
	cmp r1, #0x46
	bne _0804C740
	adds r0, r4, r3
	adds r1, r0, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C738
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r4, #0x22]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4, #0x22]
_0804C738:
	ldrb r1, [r5]
	movs r0, #8
	bl rfu_clearSlot
_0804C740:
	ldrh r2, [r4, #0x22]
	movs r1, #0x60
	ands r1, r2
	cmp r1, #0x60
	bne _0804C784
	ldr r0, _0804C778 @ =0x0000FFDF
	ands r0, r2
	ldr r1, _0804C77C @ =0x0000FFBF
	ands r0, r1
	strh r0, [r4, #0x22]
	adds r2, r4, #0
	adds r2, #0x35
	ldr r0, _0804C780 @ =0x03005800
	ldr r1, [r0]
	ldrb r0, [r1, #2]
	ldrb r1, [r1, #3]
	orrs r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0
	b _0804C7BC
	.align 2, 0
_0804C76C: .4byte 0x00000135
_0804C770: .4byte 0x00000105
_0804C774: .4byte 0x030057F0
_0804C778: .4byte 0x0000FFDF
_0804C77C: .4byte 0x0000FFBF
_0804C780: .4byte 0x03005800
_0804C784:
	ldrb r3, [r4, #0x19]
	cmp r3, #0
	beq _0804C7BC
	movs r5, #0xb4
	lsls r5, r5, #1
	ands r5, r2
	cmp r5, #0
	bne _0804C7BC
	ldr r1, _0804C7C4 @ =0x03005800
	ldr r1, [r1]
	ldrb r1, [r1, #2]
	cmp r3, r1
	bne _0804C7BC
	adds r0, r4, #0
	bl FUN_0804bc10
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C7BC
	movs r0, #9
	strb r5, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r5, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0804C7BC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804C7C4: .4byte 0x03005800

	thumb_func_start FUN_0804c7c8
FUN_0804c7c8: @ 0x0804C7C8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C7DA
	movs r0, #0
	strb r0, [r1]
_0804C7DA:
	adds r0, r4, #0
	bl FUN_0804bc28
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r2, [r1]
	adds r7, r1, #0
	cmp r2, #0
	beq _0804C87C
	adds r3, r4, #0
	adds r3, #0x24
	movs r6, #0
	ldrsb r6, [r3, r6]
	ldr r2, _0804C808 @ =0x030044E0
	ldrh r5, [r2, #2]
	movs r1, #0x40
	ands r1, r5
	cmp r1, #0
	beq _0804C80C
	ldrb r1, [r3]
	subs r1, #1
	b _0804C818
	.align 2, 0
_0804C808: .4byte 0x030044E0
_0804C80C:
	movs r1, #0x80
	ands r1, r5
	cmp r1, #0
	beq _0804C81A
	ldrb r1, [r3]
	adds r1, #1
_0804C818:
	strb r1, [r3]
_0804C81A:
	movs r1, #0
	ldrsb r1, [r3, r1]
	cmp r6, r1
	beq _0804C832
	cmp r1, #7
	ble _0804C82A
	movs r1, #7
	b _0804C830
_0804C82A:
	cmp r1, #0
	bge _0804C832
	movs r1, #0
_0804C830:
	strb r1, [r3]
_0804C832:
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	ldrb r5, [r7]
	ldrh r2, [r2, #2]
	movs r1, #1
	ands r1, r2
	cmp r1, #0
	beq _0804C87C
	cmp r3, r5
	bge _0804C87C
	adds r0, r4, #0
	adds r0, #0x28
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r0, _0804C884 @ =0x03005800
	ldr r0, [r0]
	lsls r1, r1, #5
	adds r0, r0, r1
	ldrh r0, [r0, #0x14]
	movs r1, #0
	bl rfu_LMAN_CHILD_connectParent
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0
	bne _0804C87C
	movs r0, #0xa
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0804C87C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804C884: .4byte 0x03005800

	thumb_func_start FUN_0804c888
FUN_0804c888: @ 0x0804C888
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804C8A0
	movs r0, #0
	strb r0, [r2]
	movs r0, #0xdd
	bl PlaySound_082406e0
_0804C8A0:
	ldrh r2, [r4, #0x22]
	movs r1, #0x80
	ands r1, r2
	cmp r1, #0
	beq _0804C8B6
	movs r0, #8
	bl FUN_08229f4c
	adds r0, r4, #0
	bl FUN_0804d868
_0804C8B6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804c8bc
FUN_0804c8bc: @ 0x0804C8BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r1, [r5]
	cmp r1, #0
	beq _0804C8CE
	movs r1, #0
	strb r1, [r5]
_0804C8CE:
	ldr r2, [r4, #0x44]
	ldr r1, _0804C8F0 @ =0x00000257
	cmp r2, r1
	bls _0804C8EA
	movs r0, #0
	bl rfu_LMAN_stopManager
	movs r2, #4
	movs r1, #0
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x38]
	str r1, [r4, #0x44]
	movs r1, #1
	strb r1, [r5]
_0804C8EA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804C8F0: .4byte 0x00000257

	thumb_func_start FUN_0804c8f4
FUN_0804c8f4: @ 0x0804C8F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r1, [r5]
	cmp r1, #0
	beq _0804C90C
	movs r0, #0
	strb r0, [r5]
	movs r0, #0xde
	bl PlaySound_082406e0
_0804C90C:
	ldr r1, [r4, #0x44]
	cmp r1, #0x59
	bls _0804C93A
	adds r0, r4, #0
	bl FUN_0804bb30
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r2, [r1]
	cmp r2, #0
	beq _0804C92E
	movs r2, #7
	movs r1, #0
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x38]
	str r1, [r4, #0x44]
	b _0804C936
_0804C92E:
	movs r1, #6
	strb r2, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r2, [r4, #0x44]
_0804C936:
	movs r1, #1
	strb r1, [r5]
_0804C93A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804c940
FUN_0804c940: @ 0x0804C940
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C950
	movs r0, #0
	strb r0, [r1]
_0804C950:
	bl rfu_getMasterSlave
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _0804C970
	ldr r0, _0804C974 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #2]
	ldrb r0, [r0, #3]
	orrs r0, r1
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_0804C970:
	pop {r1}
	bx r1
	.align 2, 0
_0804C974: .4byte 0x03005800

	thumb_func_start FUN_0804c978
FUN_0804c978: @ 0x0804C978
	push {lr}
	adds r3, r0, #0
	movs r1, #0x32
	adds r1, r1, r3
	mov ip, r1
	ldrb r1, [r1]
	cmp r1, #0
	beq _0804C98E
	movs r1, #0
	mov r2, ip
	strb r1, [r2]
_0804C98E:
	ldr r1, [r3, #0x44]
	cmp r1, #0x78
	bls _0804C9A4
	movs r2, #8
	movs r1, #0
	strb r1, [r3, #0x1c]
	strh r2, [r3, #0x38]
	str r1, [r3, #0x44]
	movs r1, #1
	mov r2, ip
	strb r1, [r2]
_0804C9A4:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804c9a8
FUN_0804c9a8: @ 0x0804C9A8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804C9BA
	movs r1, #0
	strb r1, [r2]
_0804C9BA:
	ldr r2, _0804CAA8 @ =0x030057F0
	adds r3, r6, #0
	adds r3, #0x21
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	ldrh r1, [r1, #0x34]
	adds r5, r3, #0
	cmp r1, #0x46
	bne _0804CA00
	ldr r1, _0804CAAC @ =0x00000135
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804C9E0
	adds r0, r6, #0
	bl FUN_0804dbe0
_0804C9E0:
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C9F8
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r6, #0x22]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r6, #0x22]
_0804C9F8:
	ldrb r1, [r5]
	movs r0, #8
	bl rfu_clearSlot
_0804CA00:
	ldr r1, _0804CAB0 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _0804CA1C
	ldrh r1, [r6, #0x22]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r3, #0
	orrs r2, r1
	movs r1, #1
	orrs r2, r1
	strh r2, [r6, #0x22]
_0804CA1C:
	ldrh r2, [r6, #0x22]
	movs r1, #0x40
	ands r1, r2
	cmp r1, #0
	beq _0804CA3C
	movs r1, #0x28
	ands r1, r2
	cmp r1, #0
	bne _0804CA3C
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r1, r2
	movs r2, #1
	orrs r1, r2
	strh r1, [r6, #0x22]
_0804CA3C:
	ldrh r2, [r6, #0x22]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	bne _0804CAD2
	ldr r1, _0804CAB4 @ =0x03005800
	ldr r1, [r1]
	ldrb r1, [r1, #3]
	cmp r1, #0
	bne _0804CAC8
	movs r7, #1
	adds r1, r7, #0
	ands r1, r2
	cmp r1, #0
	beq _0804CAC8
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	adds r4, r6, #0
	adds r4, #0xa4
	cmp r0, #0
	beq _0804CA78
	movs r0, #1
	strb r0, [r4]
	ldrh r1, [r6, #0x22]
	ldr r0, _0804CAB8 @ =0x0000FEFF
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r6, #0x22]
_0804CA78:
	ldrb r1, [r5]
	movs r0, #4
	bl rfu_clearSlot
	adds r0, r7, #0
	ldrb r1, [r5]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #6
	adds r2, r4, #0
	movs r3, #4
	bl rfu_NI_setSendData
	adds r1, r0, #0
	lsls r1, r1, #0x10
	cmp r1, #0
	beq _0804CABC
	movs r0, #2
	bl FUN_0804e584
	movs r0, #0
	b _0804CB5E
	.align 2, 0
_0804CAA8: .4byte 0x030057F0
_0804CAAC: .4byte 0x00000135
_0804CAB0: .4byte 0x030044E0
_0804CAB4: .4byte 0x03005800
_0804CAB8: .4byte 0x0000FEFF
_0804CABC:
	ldrh r1, [r6, #0x22]
	ldr r2, _0804CB10 @ =0x0000FFFE
	ands r2, r1
	movs r1, #2
	orrs r2, r1
	strh r2, [r6, #0x22]
_0804CAC8:
	ldrh r2, [r6, #0x22]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _0804CB30
_0804CAD2:
	ldr r1, _0804CB14 @ =0x030057F0
	ldrb r3, [r5]
	lsls r2, r3, #2
	adds r2, r2, r1
	ldr r1, [r2]
	ldrh r1, [r1]
	cmp r1, #0x26
	bne _0804CB20
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	ldrh r1, [r6, #0x22]
	ldr r2, _0804CB18 @ =0x0000FFFD
	ands r2, r1
	strh r2, [r6, #0x22]
	movs r1, #8
	ands r1, r2
	cmp r1, #0
	beq _0804CB30
	ldr r1, _0804CB1C @ =0x0000FFF7
	ands r1, r2
	movs r2, #0x20
	orrs r1, r2
	strh r1, [r6, #0x22]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0
	strb r1, [r2]
	b _0804CB30
	.align 2, 0
_0804CB10: .4byte 0x0000FFFE
_0804CB14: .4byte 0x030057F0
_0804CB18: .4byte 0x0000FFFD
_0804CB1C: .4byte 0x0000FFF7
_0804CB20:
	cmp r1, #0x27
	bne _0804CB30
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	movs r1, #0
	strh r1, [r6, #0x22]
_0804CB30:
	ldrh r2, [r6, #0x22]
	movs r1, #0x60
	ands r1, r2
	cmp r1, #0x60
	bne _0804CB5E
	ldr r0, _0804CB64 @ =0x0000FFDF
	ands r0, r2
	movs r4, #0
	movs r5, #0
	ldr r1, _0804CB68 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r6, #0x22]
	bl rfu_LMAN_requestChangeAgbClockMaster
	movs r0, #0xc
	strb r4, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r5, [r6, #0x44]
	adds r1, r6, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0804CB5E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804CB64: .4byte 0x0000FFDF
_0804CB68: .4byte 0x0000FFBF

	thumb_func_start FUN_0804cb6c
FUN_0804cb6c: @ 0x0804CB6C
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804CB7E
	movs r1, #0
	strb r1, [r2]
_0804CB7E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cb84
FUN_0804cb84: @ 0x0804CB84
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804CB96
	movs r1, #0
	strb r1, [r2]
_0804CB96:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cb9c
FUN_0804cb9c: @ 0x0804CB9C
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804CBAE
	movs r1, #0
	strb r1, [r2]
_0804CBAE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cbb4
FUN_0804cbb4: @ 0x0804CBB4
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804CBC6
	movs r1, #0
	strb r1, [r2]
_0804CBC6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cbcc
FUN_0804cbcc: @ 0x0804CBCC
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CBE2
	movs r0, #0
	strb r0, [r1]
	strb r0, [r4, #0x1b]
	strb r0, [r4, #0x1c]
_0804CBE2:
	adds r0, r4, #0
	bl FUN_0804bc10
	cmp r0, #0
	beq _0804CBF2
	adds r0, r4, #0
	bl FUN_0804ba64
_0804CBF2:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cbfc
FUN_0804cbfc: @ 0x0804CBFC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CC1E
	movs r4, #0
	strb r4, [r1]
	movs r0, #1
	bl FUN_0804e584
	movs r0, #1
	bl rfu_LMAN_stopManager
	strb r4, [r5, #0x1b]
	strb r4, [r5, #0x1c]
_0804CC1E:
	adds r0, r5, #0
	bl FUN_0804bc10
	cmp r0, #0
	beq _0804CC2E
	adds r0, r5, #0
	bl FUN_0804ba64
_0804CC2E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cc38
FUN_0804cc38: @ 0x0804CC38
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x32
	ldrb r0, [r6]
	cmp r0, #0
	beq _0804CC5A
	movs r4, #0
	strb r4, [r6]
	movs r0, #2
	bl FUN_0804e584
	movs r0, #1
	bl rfu_LMAN_stopManager
	strb r4, [r5, #0x1b]
	strb r4, [r5, #0x1c]
_0804CC5A:
	adds r0, r5, #0
	bl FUN_0804bc10
	cmp r0, #0
	beq _0804CC72
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
	movs r0, #1
	strb r0, [r6]
_0804CC72:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cc7c
FUN_0804cc7c: @ 0x0804CC7C
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CC90
	movs r0, #0
	strb r0, [r1]
	bl rfu_LMAN_powerDownRFU
_0804CC90:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cc98
FUN_0804cc98: @ 0x0804CC98
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CCB4
	movs r0, #0
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	bl rfu_LMAN_stopManager
_0804CCB4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804ccbc
FUN_0804ccbc: @ 0x0804CCBC
	push {r4, lr}
	adds r4, r0, #0
	bl rfu_clearAllSlot
	adds r0, r4, #0
	bl FUN_0804ba64
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804ccd0
FUN_0804ccd0: @ 0x0804CCD0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xe7
	ldr r0, _0804CD00 @ =0x03004740
	ldrb r0, [r0, #3]
	lsls r0, r0, #1
	ldrb r1, [r3]
	orrs r0, r1
	movs r4, #0
	strb r0, [r3]
	movs r3, #0x9b
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, r1
	bne _0804CD04
	adds r0, r2, #0
	adds r0, #0xe8
	strb r4, [r0]
	subs r0, #0xb2
	strb r4, [r0]
	b _0804CD14
	.align 2, 0
_0804CD00: .4byte 0x03004740
_0804CD04:
	adds r1, r2, #0
	adds r1, #0xe8
	movs r0, #1
	strb r0, [r1]
	subs r1, #8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804CD14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804cd1c
FUN_0804cd1c: @ 0x0804CD1C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r4
	mov sb, r0
	movs r3, #0
	ldr r1, _0804CD78 @ =0x030057E0
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r2, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #0
	beq _0804CDD4
	adds r5, r4, #0
	adds r5, #0x90
	adds r0, r2, #0
	bl rfu_UNI_clearRecvNewDataFlag
	adds r0, r4, #0
	adds r0, #0xd0
	ldrb r6, [r0]
	adds r1, r6, #1
	adds r2, r4, #0
	adds r2, #0x94
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r3, [r2]
	mov r8, r0
	adds r7, r2, #0
	cmp r1, r3
	bne _0804CD7C
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r7, #0
	bl FUN_0823a790
	b _0804CD94
	.align 2, 0
_0804CD78: .4byte 0x030057E0
_0804CD7C:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r3
	bne _0804CD8A
	adds r1, r4, #0
	adds r1, #0xd4
	b _0804CD8E
_0804CD8A:
	adds r1, r4, #0
	adds r1, #0xd8
_0804CD8E:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CD94:
	ldrb r0, [r7]
	movs r1, #0
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	strb r1, [r5, #1]
	adds r3, r4, #0
	adds r3, #0xec
	adds r2, r4, #0
	adds r2, #0xfa
	movs r4, #1
_0804CDAE:
	mov r6, sb
	ldrb r0, [r6, #2]
	asrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _0804CDC0
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_0804CDC0:
	adds r1, #1
	cmp r1, #4
	ble _0804CDAE
	ldrh r0, [r3]
	movs r1, #0
	strh r0, [r5, #2]
	ldr r0, _0804CDE4 @ =0x0000FFFF
	strh r0, [r3]
	strb r1, [r2]
	movs r3, #1
_0804CDD4:
	adds r0, r3, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804CDE4: .4byte 0x0000FFFF

	thumb_func_start FUN_0804cde8
FUN_0804cde8: @ 0x0804CDE8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804cd1c
	cmp r0, #0
	beq _0804CDFE
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r0, [r0]
	bl rfu_UNI_readySendData
_0804CDFE:
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ce0c
FUN_0804ce0c: @ 0x0804CE0C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xea
	ldr r0, _0804CE38 @ =0x0000FFFF
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	adds r3, r0, #0
	adds r1, #4
	movs r2, #4
_0804CE26:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0804CE26
	pop {r0}
	bx r0
	.align 2, 0
_0804CE38: .4byte 0x0000FFFF

	thumb_func_start FUN_0804ce3c
FUN_0804ce3c: @ 0x0804CE3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sl, r0
	adds r1, r5, #0
	adds r1, #0x3e
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x80
_0804CE5E:
	lsls r2, r4, #2
	movs r1, #2
	lsls r1, r4
	mov r3, sl
	ldrb r0, [r3, #2]
	ands r0, r1
	movs r3, #0xe6
	adds r3, r3, r5
	mov r8, r3
	cmp r0, #0
	beq _0804CEEC
	ldr r0, _0804CEC0 @ =0x030057E0
	adds r0, r2, r0
	ldr r0, [r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #0
	beq _0804CEEC
	ldrb r0, [r3]
	orrs r1, r0
	movs r0, #0
	mov sb, r0
	strb r1, [r3]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl rfu_UNI_clearRecvNewDataFlag
	adds r1, r5, #0
	adds r1, #0xd0
	adds r0, r1, r4
	ldrb r3, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r6]
	adds r7, r1, #0
	cmp r0, r2
	beq _0804CEE6
	adds r0, r3, #0
	cmp r0, r2
	bne _0804CEC4
	adds r1, #4
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r2, sb
	strh r2, [r6, #2]
	b _0804CEE6
	.align 2, 0
_0804CEC0: .4byte 0x030057E0
_0804CEC4:
	cmp r0, r2
	bhs _0804CEDA
	adds r1, r5, #0
	adds r1, #0xdc
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r3, sb
	strh r3, [r6, #2]
	b _0804CEE6
_0804CEDA:
	adds r1, r5, #0
	adds r1, #0xd8
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CEE6:
	adds r1, r7, r4
	ldrb r0, [r6]
	strb r0, [r1]
_0804CEEC:
	adds r6, #4
	adds r4, #1
	cmp r4, #3
	ble _0804CE5E
	mov r0, r8
	ldrb r1, [r0]
	mov r2, sl
	ldrb r0, [r2, #2]
	adds r3, r0, #0
	adds r2, r3, #0
	ands r2, r1
	adds r1, r0, #0
	adds r4, r5, #0
	adds r4, #0xe7
	cmp r2, r1
	bne _0804CF1E
	ldrb r0, [r4]
	ands r3, r0
	cmp r3, r2
	beq _0804CF2A
	adds r1, r5, #0
	adds r1, #0xe4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CF1E:
	ldrb r0, [r4]
	mov r3, sl
	ldrb r1, [r3, #2]
	ands r0, r1
	cmp r0, r1
	bne _0804CF3E
_0804CF2A:
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, r1
	beq _0804CF3E
	adds r1, r5, #0
	adds r1, #0xe5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CF3E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804cf4c
FUN_0804cf4c: @ 0x0804CF4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x70
	movs r1, #0xe7
	adds r1, r1, r5
	mov sb, r1
	ldrb r0, [r1]
	mov r2, r8
	ldrb r1, [r2, #2]
	ands r0, r1
	cmp r0, r1
	bne _0804D044
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r6, [r0]
	cmp r6, #0
	beq _0804CF92
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0804D044
	adds r1, r5, #0
	adds r1, #0x36
	movs r0, #1
	strb r0, [r1]
	b _0804D044
_0804CF92:
	ldrb r0, [r7]
	str r0, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r7, #0
	bl FUN_0823a790
	adds r4, r5, #0
	adds r4, #0x36
	strb r6, [r4]
	str r6, [sp]
	ldr r2, _0804D054 @ =0x05000004
	mov r0, sp
	adds r1, r7, #0
	bl CpuSet
	movs r2, #0
	mov r0, sb
	str r0, [sp, #0xc]
	str r4, [sp, #8]
	adds r6, r5, #0
	adds r6, #0xea
	movs r1, #0xec
	adds r1, r1, r5
	mov ip, r1
	movs r0, #0xe6
	adds r0, r0, r5
	mov sl, r0
	movs r1, #2
	mov sb, r1
	adds r3, r5, #0
	adds r3, #0x82
	adds r4, #0x40
_0804CFD6:
	mov r1, sb
	lsls r1, r2
	mov r5, r8
	ldrb r0, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0804CFE8
	ldrh r0, [r3]
	strh r0, [r4]
_0804CFE8:
	adds r3, #4
	adds r4, #2
	adds r2, #1
	cmp r2, #3
	ble _0804CFD6
	ldrh r0, [r6]
	strh r0, [r7, #4]
	mov r1, ip
	ldrh r0, [r1]
	strh r0, [r6]
	ldr r0, _0804D058 @ =0x0000FFFF
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #2]
	strb r0, [r7, #2]
	movs r0, #1
	strb r0, [r7, #1]
	movs r2, #0
	ldr r3, [sp, #4]
	adds r3, #1
	movs r5, #2
_0804D012:
	mov r0, r8
	ldrb r1, [r0, #2]
	adds r0, r5, #0
	lsls r0, r2
	ands r1, r0
	cmp r1, #0
	beq _0804D026
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
_0804D026:
	adds r2, #1
	cmp r2, #3
	ble _0804D012
	strb r3, [r7]
	movs r1, #1
	ldr r2, [sp, #0xc]
	strb r1, [r2]
	mov r5, sl
	strb r1, [r5]
	mov r2, r8
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0804D044
	ldr r5, [sp, #8]
	strb r1, [r5]
_0804D044:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D054: .4byte 0x05000004
_0804D058: .4byte 0x0000FFFF

	thumb_func_start FUN_0804d05c
FUN_0804d05c: @ 0x0804D05C
	push {r4, r5, lr}
	mov ip, r0
	movs r2, #0x9a
	lsls r2, r2, #1
	add r2, ip
	lsls r1, r1, #0x19
	lsrs r3, r1, #0x18
	movs r1, #0
	ldrb r4, [r2, #2]
	movs r5, #2
_0804D070:
	adds r0, r5, #0
	lsls r0, r1
	ands r0, r4
	ands r0, r3
	cmp r0, #0
	beq _0804D086
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0804D086
	subs r0, #1
	strb r0, [r2, #3]
_0804D086:
	adds r1, #1
	cmp r1, #4
	ble _0804D070
	ldrb r1, [r2, #2]
	bics r1, r3
	strb r1, [r2, #2]
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, r1
	bne _0804D0A6
	mov r1, ip
	adds r1, #0xe8
	movs r0, #0
	strb r0, [r1]
_0804D0A6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804d0ac
FUN_0804d0ac: @ 0x0804D0AC
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804D0E4 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	bne _0804D0BE
	b _0804D20A
_0804D0BE:
	cmp r3, #0x41
	bne _0804D0C4
	b _0804D20A
_0804D0C4:
	cmp r3, #0x41
	bgt _0804D0E8
	cmp r3, #0x30
	beq _0804D158
	cmp r3, #0x30
	bgt _0804D0D2
	b _0804D20A
_0804D0D2:
	cmp r3, #0x32
	beq _0804D144
	cmp r3, #0x32
	blt _0804D130
	cmp r3, #0x33
	beq _0804D158
	cmp r3, #0x40
	beq _0804D19C
	b _0804D20A
	.align 2, 0
_0804D0E4: .4byte 0x03002B58
_0804D0E8:
	cmp r3, #0x50
	beq _0804D118
	cmp r3, #0x50
	bgt _0804D100
	cmp r3, #0x43
	bne _0804D0F6
	b _0804D20A
_0804D0F6:
	cmp r3, #0x43
	blt _0804D1D0
	cmp r3, #0x44
	beq _0804D1D8
	b _0804D20A
_0804D100:
	cmp r3, #0xf1
	beq _0804D1EC
	cmp r3, #0xf1
	bgt _0804D10E
	cmp r3, #0xf0
	beq _0804D1EC
	b _0804D20A
_0804D10E:
	cmp r1, #0xf2
	beq _0804D1EC
	cmp r1, #0xff
	beq _0804D1EC
	b _0804D20A
_0804D118:
	adds r0, r4, #0
	bl FUN_0804ccd0
	adds r0, r4, #0
	bl FUN_0804ce3c
	ldr r1, _0804D12C @ =0x030000DC
	movs r0, #0
	strb r0, [r1]
	b _0804D20A
	.align 2, 0
_0804D12C: .4byte 0x030000DC
_0804D130:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D140 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804D20A
	.align 2, 0
_0804D140: .4byte 0x03004740
_0804D144:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D154 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804D20A
	.align 2, 0
_0804D154: .4byte 0x03004740
_0804D158:
	adds r3, r4, #0
	adds r3, #0x25
	ldr r2, _0804D194 @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	movs r6, #0
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0xe9
	movs r0, #1
	strb r0, [r1]
	ldrb r1, [r2, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D198 @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D20A
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r0, #0x1d
	strb r6, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r6, [r4, #0x44]
	b _0804D1C0
	.align 2, 0
_0804D194: .4byte 0x03004740
_0804D198: .4byte 0x00000137
_0804D19C:
	ldr r0, _0804D1C8 @ =0x03004740
	ldrb r1, [r0, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D1CC @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D20A
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1d
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
_0804D1C0:
	adds r0, r4, #0
	adds r0, #0x32
	strb r5, [r0]
	b _0804D20A
	.align 2, 0
_0804D1C8: .4byte 0x03004740
_0804D1CC: .4byte 0x00000137
_0804D1D0:
	adds r0, r4, #0
	bl FUN_0804ba64
	b _0804D20A
_0804D1D8:
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	b _0804D20A
_0804D1EC:
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r4, #0x1c]
	movs r2, #0
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0804D210 @ =0x030000DC
	strb r2, [r0]
_0804D20A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D210: .4byte 0x030000DC

	thumb_func_start FUN_0804d214
FUN_0804d214: @ 0x0804D214
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804D244 @ =0x03002B58
	ldr r5, [r0]
	cmp r5, #0
	beq _0804D2FE
	cmp r3, #0x41
	bgt _0804D248
	cmp r3, #0x40
	bge _0804D2FE
	cmp r3, #0x30
	beq _0804D2A0
	cmp r3, #0x30
	ble _0804D2FE
	cmp r3, #0x32
	beq _0804D28C
	cmp r3, #0x32
	blt _0804D276
	cmp r3, #0x33
	beq _0804D2A0
	b _0804D2FE
	.align 2, 0
_0804D244: .4byte 0x03002B58
_0804D248:
	cmp r3, #0x50
	beq _0804D26E
	cmp r3, #0x50
	bgt _0804D256
	cmp r3, #0x42
	beq _0804D2C4
	b _0804D2FE
_0804D256:
	cmp r3, #0xf1
	beq _0804D2E6
	cmp r3, #0xf1
	bgt _0804D264
	cmp r3, #0xf0
	beq _0804D2CC
	b _0804D2FE
_0804D264:
	cmp r1, #0xf2
	beq _0804D2E6
	cmp r1, #0xff
	beq _0804D2E6
	b _0804D2FE
_0804D26E:
	adds r0, r5, #0
	bl FUN_0804cde8
	b _0804D2FE
_0804D276:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804D288 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804D2FE
	.align 2, 0
_0804D288: .4byte 0x03004740
_0804D28C:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804D29C @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804D2FE
	.align 2, 0
_0804D29C: .4byte 0x03004740
_0804D2A0:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804D2C0 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	movs r4, #0
	strb r0, [r2]
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r0, #0x1d
	strb r4, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r4, [r5, #0x44]
	b _0804D2F6
	.align 2, 0
_0804D2C0: .4byte 0x03004740
_0804D2C4:
	adds r0, r5, #0
	bl FUN_0804ba64
	b _0804D2FE
_0804D2CC:
	ldr r0, _0804D304 @ =0x03004740
	ldrh r1, [r0, #0x14]
	adds r2, r0, #0
	cmp r1, #0x30
	bne _0804D2E0
	ldrh r0, [r2, #0x16]
	cmp r0, #3
	bne _0804D2E0
	movs r0, #0
	strh r0, [r2, #0x16]
_0804D2E0:
	ldrh r0, [r2, #0x16]
	cmp r0, #0
	beq _0804D2FE
_0804D2E6:
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
_0804D2F6:
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804D2FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D304: .4byte 0x03004740

	thumb_func_start FUN_0804d308
FUN_0804d308: @ 0x0804D308
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _0804D34C @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	beq _0804D364
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r4, r0
	mov r0, sp
	bl rfu_UNI_PARENT_getDRAC_ACK
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0804D360
	adds r2, r4, #0
	adds r2, #0xe7
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, r1
	bne _0804D350
	adds r0, r4, #0
	adds r0, #0xe8
	strb r3, [r0]
	subs r0, #0xb2
	strb r3, [r0]
	b _0804D360
	.align 2, 0
_0804D34C: .4byte 0x03002B58
_0804D350:
	adds r1, r4, #0
	adds r1, #0xe8
	movs r0, #1
	strb r0, [r1]
	subs r1, #8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804D360:
	bl rfu_REQ_recvData
_0804D364:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804d36c
FUN_0804d36c: @ 0x0804D36C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0804D388 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804D390
	cmp r1, #0x27
	bne _0804D38C
	bl rfu_REQ_changeMasterSlave
	bl rfu_waitREQComplete
	b _0804D390
	.align 2, 0
_0804D388: .4byte 0x03002B58
_0804D38C:
	bl rfu_REQ_recvData
_0804D390:
	pop {r0}
	bx r0

	thumb_func_start FUN_0804d394
FUN_0804d394: @ 0x0804D394
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r7, r6, r0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r4, #0
	strb r4, [r6, #0x1f]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_0823a76c
	adds r5, r6, #0
	adds r5, #0x70
	adds r0, r5, #0
	movs r1, #0x10
	bl ClearMemory
	adds r0, r6, #0
	adds r0, #0x80
	movs r1, #0x10
	bl ClearMemory
	adds r0, r6, #0
	bl FUN_0804ce0c
	adds r0, r6, #0
	adds r0, #0xe8
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	subs r0, #2
	movs r2, #1
	movs r1, #1
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	ldrb r0, [r7, #2]
	adds r3, r6, #0
	adds r3, #0x37
	strb r0, [r3]
	ldr r0, _0804D51C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #2]
	lsls r0, r0, #1
	orrs r0, r2
	strb r0, [r7, #2]
	adds r2, r6, #0
	adds r2, #0x72
	strb r0, [r2]
	strb r1, [r5]
	adds r0, r6, #0
	adds r0, #0x71
	strb r1, [r0]
	movs r5, #0
	movs r3, #2
	adds r2, r0, #0
_0804D416:
	ldrb r1, [r7, #2]
	adds r0, r3, #0
	lsls r0, r5
	ands r1, r0
	cmp r1, #0
	beq _0804D428
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
_0804D428:
	adds r5, #1
	cmp r5, #3
	ble _0804D416
	adds r1, r6, #0
	adds r1, #0x36
	movs r0, #1
	strb r0, [r1]
	movs r5, #0
	adds r2, r6, #0
	adds r2, #0x70
	str r2, [sp]
	movs r4, #0xe0
	adds r4, r4, r6
	mov r8, r4
	movs r0, #0xe4
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0xe5
	adds r1, r1, r6
	mov sl, r1
	subs r2, #0x3e
	str r2, [sp, #4]
	movs r4, #0xd0
	adds r4, r4, r6
	mov ip, r4
	movs r1, #0
	adds r0, r6, #0
	adds r0, #0xd4
	str r0, [sp, #8]
	adds r3, r6, #0
	adds r3, #0xd8
	adds r2, #0xaa
_0804D468:
	mov r4, ip
	adds r0, r4, r5
	strb r1, [r0]
	ldr r4, [sp, #8]
	adds r0, r4, r5
	strb r1, [r0]
	adds r0, r3, r5
	strb r1, [r0]
	adds r0, r2, r5
	strb r1, [r0]
	adds r5, #1
	cmp r5, #3
	ble _0804D468
	movs r0, #0
	mov r1, r8
	str r0, [r1]
	mov r2, sb
	strb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r0, _0804D520 @ =FUN_0804d0ac
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804D524 @ =FUN_0804d308
	bl rfu_LMAN_setMSCCallback
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x80
_0804D4A2:
	ldrb r1, [r7, #2]
	movs r0, #2
	mov r8, r0
	lsls r0, r5
	ands r1, r0
	cmp r1, #0
	beq _0804D4BE
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x10
	adds r2, r4, #0
	movs r3, #4
	bl rfu_setRecvBuffer
_0804D4BE:
	adds r4, #4
	adds r5, #1
	cmp r5, #3
	ble _0804D4A2
	ldrb r0, [r7, #2]
	lsrs r0, r0, #1
	ldr r1, [sp]
	movs r2, #0x10
	bl rfu_UNI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804D528
	movs r5, #0
	ldrb r1, [r7, #2]
	adds r0, r1, #0
	mov r2, r8
	ands r0, r2
	adds r2, r6, #0
	adds r2, #0x20
	adds r7, r6, #0
	adds r7, #0x34
	cmp r0, #0
	bne _0804D500
	movs r3, #2
_0804D4F0:
	adds r5, #1
	cmp r5, #3
	bgt _0804D500
	adds r0, r3, #0
	lsls r0, r5
	ands r0, r1
	cmp r0, #0
	beq _0804D4F0
_0804D500:
	movs r4, #0
	strb r5, [r2]
	ldrb r0, [r2]
	bl rfu_UNI_readySendData
	movs r1, #1
	strb r1, [r7]
	movs r0, #0x13
	strb r4, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r4, [r6, #0x44]
	ldr r4, [sp, #4]
	strb r1, [r4]
	b _0804D538
	.align 2, 0
_0804D51C: .4byte 0x03005800
_0804D520: .4byte FUN_0804d0ac
_0804D524: .4byte FUN_0804d308
_0804D528:
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r6, #0x1c]
	strh r1, [r6, #0x38]
	str r0, [r6, #0x44]
	movs r0, #1
	ldr r1, [sp, #4]
	strb r0, [r1]
_0804D538:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804d548
FUN_0804d548: @ 0x0804D548
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp]
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r3, #0
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _0804D650 @ =0x03005800
	ldr r0, [r2]
	adds r0, #0x94
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0804D596
	adds r4, r2, #0
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r2, r6, r0
_0804D582:
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	bgt _0804D596
	ldr r0, [r4]
	adds r0, #0x94
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _0804D582
_0804D596:
	strb r3, [r6, #0x1f]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_0823a76c
	adds r5, r6, #0
	adds r5, #0x90
	adds r0, r5, #0
	movs r1, #4
	bl ClearMemory
	adds r4, r6, #0
	adds r4, #0x94
	adds r0, r4, #0
	movs r1, #0x10
	bl ClearMemory
	adds r0, r6, #0
	bl FUN_0804ce0c
	movs r3, #0
	mov sb, r5
	mov sl, r4
	movs r2, #0x37
	adds r2, r2, r6
	mov ip, r2
	movs r0, #0x21
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0x32
	str r1, [sp, #4]
	adds r7, r6, #0
	adds r7, #0xd0
	movs r1, #0
	adds r5, #0x44
	adds r4, #0x44
	adds r2, r6, #0
	adds r2, #0xdc
_0804D5E6:
	adds r0, r7, r3
	strb r1, [r0]
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
	cmp r3, #3
	ble _0804D5E6
	ldr r2, [sp]
	ldrb r0, [r2, #2]
	movs r7, #0
	mov r1, ip
	strb r0, [r1]
	mov r2, sb
	strb r7, [r2]
	ldr r0, _0804D654 @ =FUN_0804d214
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804D658 @ =FUN_0804d36c
	bl rfu_LMAN_setMSCCallback
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #0x10
	mov r2, sl
	movs r3, #0x10
	bl rfu_setRecvBuffer
	movs r4, #1
	adds r0, r4, #0
	mov r1, r8
	ldrb r1, [r1]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, sb
	movs r2, #4
	bl rfu_UNI_setSendData
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0804D65C
	movs r0, #0x1b
	strb r7, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r7, [r6, #0x44]
	ldr r2, [sp, #4]
	strb r4, [r2]
	b _0804D66E
	.align 2, 0
_0804D650: .4byte 0x03005800
_0804D654: .4byte FUN_0804d214
_0804D658: .4byte FUN_0804d36c
_0804D65C:
	adds r0, r6, #0
	adds r0, #0x34
	strb r4, [r0]
	movs r0, #0x14
	strb r1, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r1, [r6, #0x44]
	ldr r0, [sp, #4]
	strb r4, [r0]
_0804D66E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804d680
FUN_0804d680: @ 0x0804D680
	push {lr}
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804D68E
	movs r0, #0
	b _0804D694
_0804D68E:
	bl rfu_clearAllSlot
	movs r0, #1
_0804D694:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804d698
FUN_0804d698: @ 0x0804D698
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804D6AE
	movs r0, #0
	strb r0, [r1]
	bl ClearBGTilemapBuffer
_0804D6AE:
	ldr r0, _0804D6CC @ =0x03004508
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r1, r0
	adds r0, r4, #0
	bl FUN_0804bb68
	adds r2, r4, #0
	adds r2, #0x31
	movs r1, #1
	strb r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804D6CC: .4byte 0x03004508

	thumb_func_start FUN_0804d6d0
FUN_0804d6d0: @ 0x0804D6D0
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804D6E6
	movs r0, #0
	strb r0, [r1]
	bl ClearBGTilemapBuffer
_0804D6E6:
	ldr r0, _0804D704 @ =0x03004508
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r1, r0
	adds r0, r4, #0
	bl FUN_0804bb68
	adds r2, r4, #0
	adds r2, #0x31
	movs r1, #1
	strb r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804D704: .4byte 0x03004508

	thumb_func_start FUN_0804d708
FUN_0804d708: @ 0x0804D708
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804D740 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	bne _0804D71A
	b _0804D850
_0804D71A:
	cmp r3, #0x41
	bne _0804D720
	b _0804D850
_0804D720:
	cmp r3, #0x41
	bgt _0804D744
	cmp r3, #0x30
	beq _0804D7A0
	cmp r3, #0x30
	bgt _0804D72E
	b _0804D850
_0804D72E:
	cmp r3, #0x32
	beq _0804D78C
	cmp r3, #0x32
	blt _0804D776
	cmp r3, #0x33
	beq _0804D7A0
	cmp r3, #0x40
	beq _0804D7E4
	b _0804D850
	.align 2, 0
_0804D740: .4byte 0x03002B58
_0804D744:
	cmp r3, #0x50
	bne _0804D74A
	b _0804D84A
_0804D74A:
	cmp r3, #0x50
	bgt _0804D75E
	cmp r3, #0x43
	bne _0804D754
	b _0804D850
_0804D754:
	cmp r3, #0x43
	blt _0804D818
	cmp r3, #0x44
	beq _0804D820
	b _0804D850
_0804D75E:
	cmp r3, #0xf1
	beq _0804D832
	cmp r3, #0xf1
	bgt _0804D76C
	cmp r3, #0xf0
	beq _0804D832
	b _0804D850
_0804D76C:
	cmp r1, #0xf2
	beq _0804D832
	cmp r1, #0xff
	beq _0804D832
	b _0804D850
_0804D776:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D788 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804D850
	.align 2, 0
_0804D788: .4byte 0x03004740
_0804D78C:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D79C @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804D850
	.align 2, 0
_0804D79C: .4byte 0x03004740
_0804D7A0:
	adds r3, r4, #0
	adds r3, #0x25
	ldr r2, _0804D7DC @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	movs r6, #0
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0xe9
	movs r0, #1
	strb r0, [r1]
	ldrb r1, [r2, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D7E0 @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D850
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r0, #0x1d
	strb r6, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r6, [r4, #0x44]
	b _0804D808
	.align 2, 0
_0804D7DC: .4byte 0x03004740
_0804D7E0: .4byte 0x00000137
_0804D7E4:
	ldr r0, _0804D810 @ =0x03004740
	ldrb r1, [r0, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D814 @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D850
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1d
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
_0804D808:
	adds r0, r4, #0
	adds r0, #0x32
	strb r5, [r0]
	b _0804D850
	.align 2, 0
_0804D810: .4byte 0x03004740
_0804D814: .4byte 0x00000137
_0804D818:
	adds r0, r4, #0
	bl FUN_0804ba64
	b _0804D850
_0804D820:
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804D84E
_0804D832:
	ldrh r0, [r4, #0x38]
	cmp r0, #0x1c
	beq _0804D84A
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804D84A:
	ldr r1, _0804D858 @ =0x030000DC
	movs r0, #0
_0804D84E:
	strb r0, [r1]
_0804D850:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D858: .4byte 0x030000DC

	thumb_func_start FUN_0804d85c
FUN_0804d85c: @ 0x0804D85C
	push {lr}
	bl rfu_REQ_recvData
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804d868
FUN_0804d868: @ 0x0804D868
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_0823a76c
	adds r0, r5, #0
	adds r0, #0xb8
	movs r1, #0xc
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0xc4
	movs r1, #0xc
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r1, [r0]
	movs r0, #8
	bl rfu_clearSlot
	ldr r0, _0804D904 @ =FUN_0804d708
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804D908 @ =FUN_0804d85c
	bl rfu_LMAN_setMSCCallback
	movs r4, #0
_0804D8B0:
	ldrb r1, [r7, #2]
	movs r6, #2
	adds r0, r6, #0
	lsls r0, r4
	ands r1, r0
	cmp r1, #0
	beq _0804D8CE
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x20
	adds r2, r5, #0
	adds r2, #0xc4
	movs r3, #0xc
	bl rfu_setRecvBuffer
_0804D8CE:
	adds r4, #1
	cmp r4, #3
	ble _0804D8B0
	adds r0, r5, #0
	adds r0, #0x34
	movs r1, #0
	strb r6, [r0]
	movs r0, #0x17
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x4c]
	cmp r0, #0
	beq _0804D8F8
	movs r1, #0
	bl Script_ExecById
_0804D8F8:
	movs r0, #4
	bl Sound_FadeOutBGM
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D904: .4byte FUN_0804d708
_0804D908: .4byte FUN_0804d85c

	thumb_func_start FUN_0804d90c
FUN_0804d90c: @ 0x0804D90C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrh r1, [r5, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804D996
	ldr r7, _0804D988 @ =0x03005800
	ldr r0, [r7]
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0804D996
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0804D99A
	adds r4, r5, #0
	adds r4, #0x20
	ldrb r1, [r4]
	movs r0, #4
	bl rfu_clearSlot
	adds r0, r6, #0
	ldrb r1, [r4]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r5, #0
	adds r2, #0xb8
	movs r1, #0xf
	movs r3, #0xc
	bl rfu_NI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804D990
	movs r1, #0
	ldr r0, [r7]
	ldrb r0, [r0, #2]
	ands r0, r6
	cmp r0, #0
	bne _0804D978
	adds r3, r7, #0
	movs r2, #1
_0804D966:
	adds r1, #1
	cmp r1, #3
	bgt _0804D978
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _0804D966
_0804D978:
	strb r1, [r4]
	ldrh r0, [r5, #0x22]
	ldr r1, _0804D98C @ =0x0000FFFE
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strh r1, [r5, #0x22]
	b _0804D99A
	.align 2, 0
_0804D988: .4byte 0x03005800
_0804D98C: .4byte 0x0000FFFE
_0804D990:
	movs r0, #2
	bl FUN_0804e584
_0804D996:
	movs r0, #0
	b _0804D99C
_0804D99A:
	movs r0, #1
_0804D99C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804d9a4
FUN_0804d9a4: @ 0x0804D9A4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r6, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804DA48
	ldr r7, _0804DA00 @ =0x030057F0
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0x26
	bne _0804DA08
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804D9DC
	adds r0, r4, #0
	adds r0, #0xb8
	bl _call_via_r1
_0804D9DC:
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r3, [r0]
	ldrb r0, [r2, #0x1a]
	adds r6, r0, #0
	eors r6, r3
	movs r0, #4
	bl rfu_clearSlot
	ldrh r1, [r4, #0x22]
	ldr r0, _0804DA04 @ =0x0000FFFD
	ands r0, r1
	b _0804DA38
	.align 2, 0
_0804DA00: .4byte 0x030057F0
_0804DA04: .4byte 0x0000FFFD
_0804DA08:
	cmp r0, #0x27
	bne _0804DA3A
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DA1C
	bl _call_via_r0
_0804DA1C:
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r3, [r0]
	ldrb r0, [r2, #0x1a]
	adds r6, r0, #0
	eors r6, r3
	movs r0, #4
	bl rfu_clearSlot
	movs r0, #0
_0804DA38:
	strh r0, [r4, #0x22]
_0804DA3A:
	cmp r6, #0
	beq _0804DA48
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	orrs r6, r0
	strb r6, [r1]
_0804DA48:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804da50
FUN_0804da50: @ 0x0804DA50
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x32
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804DA62
	movs r0, #0
	strb r0, [r3]
_0804DA62:
	movs r1, #0x17
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r1, [r2, #0x38]
	str r0, [r2, #0x44]
	movs r0, #1
	strb r0, [r3]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804da78
FUN_0804da78: @ 0x0804DA78
	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DA8A
	movs r0, #0
	strb r0, [r1]
_0804DA8A:
	ldr r0, _0804DABC @ =0x030057F0
	adds r4, r2, #0
	adds r4, #0x20
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldrh r0, [r0, #0x34]
	cmp r0, #0x46
	bne _0804DAC0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804DAB2
	adds r0, r2, #0
	adds r0, #0xc4
	bl _call_via_r1
_0804DAB2:
	ldrb r1, [r4]
	movs r0, #8
	bl rfu_clearSlot
	b _0804DADA
	.align 2, 0
_0804DABC: .4byte 0x030057F0
_0804DAC0:
	subs r0, #0x47
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0804DADA
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DADA
	bl _call_via_r0
_0804DADA:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804dae4
FUN_0804dae4: @ 0x0804DAE4
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DAF4
	movs r0, #0
	strb r0, [r1]
_0804DAF4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804dafc
FUN_0804dafc: @ 0x0804DAFC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804DB2C @ =0x03002B58
	ldr r2, [r0]
	cmp r2, #0
	beq _0804DBC4
	cmp r3, #0x41
	bgt _0804DB30
	cmp r3, #0x40
	bge _0804DBC4
	cmp r3, #0x30
	beq _0804DB84
	cmp r3, #0x30
	ble _0804DBC4
	cmp r3, #0x32
	beq _0804DB70
	cmp r3, #0x32
	blt _0804DB5E
	cmp r3, #0x33
	beq _0804DB84
	b _0804DBC4
	.align 2, 0
_0804DB2C: .4byte 0x03002B58
_0804DB30:
	cmp r3, #0x50
	beq _0804DB56
	cmp r3, #0x50
	bgt _0804DB3E
	cmp r3, #0x42
	beq _0804DBA4
	b _0804DBC4
_0804DB3E:
	cmp r3, #0xf1
	beq _0804DBAC
	cmp r3, #0xf1
	bgt _0804DB4C
	cmp r3, #0xf0
	beq _0804DBAC
	b _0804DBC4
_0804DB4C:
	cmp r1, #0xf2
	beq _0804DBAC
	cmp r1, #0xff
	beq _0804DBAC
	b _0804DBC4
_0804DB56:
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	b _0804DBC4
_0804DB5E:
	adds r2, #0x25
	ldr r0, _0804DB6C @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804DBC4
	.align 2, 0
_0804DB6C: .4byte 0x03004740
_0804DB70:
	adds r2, #0x25
	ldr r0, _0804DB80 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804DBC4
	.align 2, 0
_0804DB80: .4byte 0x03004740
_0804DB84:
	adds r3, r2, #0
	adds r3, #0x25
	ldr r0, _0804DBA0 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	movs r1, #0
	strb r0, [r3]
	movs r0, #0x1d
	strb r1, [r2, #0x1c]
	strh r0, [r2, #0x38]
	str r1, [r2, #0x44]
	b _0804DBBC
	.align 2, 0
_0804DBA0: .4byte 0x03004740
_0804DBA4:
	adds r0, r2, #0
	bl FUN_0804ba64
	b _0804DBC4
_0804DBAC:
	ldrh r0, [r2, #0x38]
	cmp r0, #0x1c
	beq _0804DBC4
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r1, [r2, #0x38]
	str r0, [r2, #0x44]
_0804DBBC:
	adds r1, r2, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804DBC4:
	pop {r0}
	bx r0

	thumb_func_start FUN_0804dbc8
FUN_0804dbc8: @ 0x0804DBC8
	push {lr}
	ldr r0, _0804DBDC @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DBD6
	bl rfu_REQ_recvData
_0804DBD6:
	pop {r0}
	bx r0
	.align 2, 0
_0804DBDC: .4byte 0x03002B58

	thumb_func_start FUN_0804dbe0
FUN_0804dbe0: @ 0x0804DBE0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r3, #0
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r2, _0804DC84 @ =0x03005800
	ldr r0, [r2]
	adds r0, #0x94
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0804DC1C
	adds r4, r2, #0
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r2, r6, r1
_0804DC08:
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	bgt _0804DC1C
	ldr r0, [r4]
	adds r0, #0x94
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _0804DC08
_0804DC1C:
	movs r5, #0
	strb r3, [r6, #0x1f]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_0823a76c
	adds r0, r6, #0
	adds r0, #0xb8
	movs r1, #0xc
	bl ClearMemory
	adds r4, r6, #0
	adds r4, #0xc4
	adds r0, r4, #0
	movs r1, #0xc
	bl ClearMemory
	ldr r0, _0804DC88 @ =FUN_0804dafc
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804DC8C @ =FUN_0804dbc8
	bl rfu_LMAN_setMSCCallback
	adds r0, r6, #0
	adds r0, #0x21
	ldrb r1, [r0]
	movs r0, #0x20
	adds r2, r4, #0
	movs r3, #0xc
	bl rfu_setRecvBuffer
	adds r1, r6, #0
	adds r1, #0x34
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x18
	strb r5, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r5, [r6, #0x44]
	subs r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x4c]
	cmp r0, #0
	beq _0804DC7E
	movs r1, #0
	bl Script_ExecById
_0804DC7E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804DC84: .4byte 0x03005800
_0804DC88: .4byte FUN_0804dafc
_0804DC8C: .4byte FUN_0804dbc8

	thumb_func_start FUN_0804dc90
FUN_0804dc90: @ 0x0804DC90
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804DD72
	ldr r0, _0804DCDC @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0804DD72
	ldr r1, _0804DCE0 @ =0x030057F0
	adds r2, r4, #0
	adds r2, #0x21
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #0x34]
	adds r5, r2, #0
	cmp r0, #0x46
	bne _0804DCE4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804DCD2
	adds r0, r4, #0
	adds r0, #0xc4
	bl _call_via_r1
_0804DCD2:
	ldrb r1, [r5]
	movs r0, #8
	bl rfu_clearSlot
	b _0804DCFE
	.align 2, 0
_0804DCDC: .4byte 0x03005800
_0804DCE0: .4byte 0x030057F0
_0804DCE4:
	subs r0, #0x47
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0804DCFE
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DCFE
	bl _call_via_r0
_0804DCFE:
	ldrh r1, [r4, #0x22]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0804DD76
	ldrb r1, [r5]
	movs r0, #4
	bl rfu_clearSlot
	adds r0, r6, #0
	ldrb r1, [r5]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r4, #0
	adds r2, #0xb8
	movs r1, #0xe
	movs r3, #0xc
	bl rfu_NI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804DD6C
	movs r1, #0
	ldr r2, _0804DD64 @ =0x03005800
	ldr r0, [r2]
	ldrb r0, [r0, #2]
	ands r0, r6
	cmp r0, #0
	bne _0804DD52
	adds r3, r2, #0
	movs r2, #1
_0804DD40:
	adds r1, #1
	cmp r1, #3
	bgt _0804DD52
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _0804DD40
_0804DD52:
	strb r1, [r5]
	ldrh r0, [r4, #0x22]
	ldr r1, _0804DD68 @ =0x0000FFFE
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strh r1, [r4, #0x22]
	b _0804DD76
	.align 2, 0
_0804DD64: .4byte 0x03005800
_0804DD68: .4byte 0x0000FFFE
_0804DD6C:
	movs r0, #2
	bl FUN_0804e584
_0804DD72:
	movs r0, #0
	b _0804DD78
_0804DD76:
	movs r0, #1
_0804DD78:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804dd80
FUN_0804dd80: @ 0x0804DD80
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r6, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804DE10
	ldr r7, _0804DDC8 @ =0x030057F0
	adds r5, r4, #0
	adds r5, #0x21
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0x26
	bne _0804DDD0
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804DDB8
	adds r0, r4, #0
	adds r0, #0xb8
	bl _call_via_r1
_0804DDB8:
	ldrb r1, [r5]
	movs r0, #4
	bl rfu_clearSlot
	ldrh r1, [r4, #0x22]
	ldr r0, _0804DDCC @ =0x0000FFFD
	ands r0, r1
	b _0804DE00
	.align 2, 0
_0804DDC8: .4byte 0x030057F0
_0804DDCC: .4byte 0x0000FFFD
_0804DDD0:
	cmp r0, #0x27
	bne _0804DE02
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DDE4
	bl _call_via_r0
_0804DDE4:
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r3, [r0]
	ldrb r0, [r2, #0x1a]
	adds r6, r0, #0
	eors r6, r3
	movs r0, #4
	bl rfu_clearSlot
	movs r0, #0
_0804DE00:
	strh r0, [r4, #0x22]
_0804DE02:
	cmp r6, #0
	beq _0804DE10
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	orrs r6, r0
	strb r6, [r1]
_0804DE10:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804de18
FUN_0804de18: @ 0x0804DE18
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x32
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804DE2A
	movs r0, #0
	strb r0, [r3]
_0804DE2A:
	movs r1, #0x17
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r1, [r2, #0x38]
	str r0, [r2, #0x44]
	movs r0, #1
	strb r0, [r3]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804de40
FUN_0804de40: @ 0x0804DE40
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DE50
	movs r0, #0
	strb r0, [r1]
_0804DE50:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804de58
FUN_0804de58: @ 0x0804DE58
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DE68
	movs r0, #0
	strb r0, [r1]
_0804DE68:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804de70
FUN_0804de70: @ 0x0804DE70
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x18]
	cmp r0, #0
	beq _0804DEB8
	ldr r1, _0804DEDC @ =0x030000DC
	ldrb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x35
	cmp r0, #1
	bne _0804DE8C
_0804DE86:
	ldrb r0, [r1]
	cmp r0, #1
	beq _0804DE86
_0804DE8C:
	movs r0, #0
	bl rfu_LMAN_manager_entity
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804DEA4
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	movs r0, #0
	strb r0, [r4]
_0804DEA4:
	ldr r0, _0804DEE0 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0]
	cmp r1, #1
	bne _0804DEB8
	ldr r0, _0804DEDC @ =0x030000DC
	strb r1, [r0]
	movs r0, #1
	bl rfu_REQ_sendData
_0804DEB8:
	adds r0, r5, #0
	bl FUN_0804bdd4
	adds r0, r5, #0
	bl FUN_0804bed4
	ldr r0, _0804DEE4 @ =0x085AB5E0
	ldrh r1, [r5, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804DEDC: .4byte 0x030000DC
_0804DEE0: .4byte 0x03005800
_0804DEE4: .4byte 0x085AB5E0

	thumb_func_start FUN_0804dee8
FUN_0804dee8: @ 0x0804DEE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _0804DEFE
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #0
	strb r0, [r1]
	bl rfu_LMAN_manager_entity
_0804DEFE:
	ldr r0, _0804DF14 @ =0x085AB5E0
	ldrh r1, [r4, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804DF14: .4byte 0x085AB5E0

	thumb_func_start FUN_0804df18
FUN_0804df18: @ 0x0804DF18
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0804DFA0 @ =0x030000DC
_0804DF26:
	ldrb r0, [r1]
	cmp r0, #1
	beq _0804DF26
	movs r0, #0
	bl rfu_LMAN_manager_entity
	adds r3, r4, #0
	adds r3, #0xe9
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804DF56
	adds r2, r4, #0
	adds r2, #0xe8
	ldrb r0, [r2]
	cmp r0, #0
	beq _0804DF56
	movs r1, #0
	strb r1, [r2]
	subs r2, #1
	movs r0, #1
	strb r0, [r2]
	subs r2, #1
	strb r0, [r2]
	strb r1, [r3]
_0804DF56:
	adds r0, r4, #0
	bl FUN_0804bb70
	adds r0, r4, #0
	bl FUN_0804cf4c
	ldr r0, _0804DFA4 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0804DFAC
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804DFAC
	ldr r1, _0804DFA0 @ =0x030000DC
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804DFA8
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x70
	movs r2, #0x10
	bl rfu_UNI_changeAndReadySendData
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	b _0804DFAC
	.align 2, 0
_0804DFA0: .4byte 0x030000DC
_0804DFA4: .4byte 0x03005800
_0804DFA8:
	bl rfu_REQ_PARENT_resumeRetransmitAndChange
_0804DFAC:
	adds r0, r4, #0
	bl FUN_0804bb98
	ldr r0, _0804DFF4 @ =0x085AB5E0
	ldrh r1, [r4, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0x31
	ldrb r2, [r1]
	cmp r2, #0
	beq _0804E01A
	ldr r2, _0804DFF8 @ =0x030044D0
	movs r1, #1
	str r1, [r2]
	movs r5, #0
	movs r1, #0x80
	lsls r1, r1, #6
	mov ip, r1
	ldr r7, _0804DFFC @ =0x00000FFF
	ldr r3, _0804E000 @ =0x03004510
	ldr r1, _0804E004 @ =0x0000FFFF
	adds r6, r1, #0
	adds r4, #0xf0
_0804DFE4:
	ldrh r2, [r4]
	mov r1, ip
	ands r1, r2
	cmp r1, #0
	beq _0804E008
	adds r1, r7, #0
	ands r1, r2
	b _0804E00C
	.align 2, 0
_0804DFF4: .4byte 0x085AB5E0
_0804DFF8: .4byte 0x030044D0
_0804DFFC: .4byte 0x00000FFF
_0804E000: .4byte 0x03004510
_0804E004: .4byte 0x0000FFFF
_0804E008:
	ldrh r1, [r3]
	orrs r1, r6
_0804E00C:
	strh r1, [r3]
	adds r3, #2
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _0804DFE4
	b _0804E01E
_0804E01A:
	ldr r1, _0804E024 @ =0x030044D0
	str r2, [r1]
_0804E01E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804E024: .4byte 0x030044D0

	thumb_func_start FUN_0804e028
FUN_0804e028: @ 0x0804E028
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x31
	movs r0, #0
	strb r0, [r5]
	bl rfu_LMAN_manager_entity
	bl rfu_getMasterSlave
	adds r0, r4, #0
	bl FUN_0804bb70
	adds r0, r4, #0
	bl FUN_0804bb98
	ldr r1, _0804E088 @ =0x085AB5E0
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r2, [r5]
	cmp r2, #0
	beq _0804E0AE
	ldr r2, _0804E08C @ =0x030044D0
	movs r1, #1
	str r1, [r2]
	movs r5, #0
	movs r1, #0x80
	lsls r1, r1, #6
	mov ip, r1
	ldr r7, _0804E090 @ =0x00000FFF
	ldr r3, _0804E094 @ =0x03004510
	ldr r1, _0804E098 @ =0x0000FFFF
	adds r6, r1, #0
	adds r4, #0xf0
_0804E076:
	ldrh r2, [r4]
	mov r1, ip
	ands r1, r2
	cmp r1, #0
	beq _0804E09C
	adds r1, r7, #0
	ands r1, r2
	b _0804E0A0
	.align 2, 0
_0804E088: .4byte 0x085AB5E0
_0804E08C: .4byte 0x030044D0
_0804E090: .4byte 0x00000FFF
_0804E094: .4byte 0x03004510
_0804E098: .4byte 0x0000FFFF
_0804E09C:
	ldrh r1, [r3]
	orrs r1, r6
_0804E0A0:
	strh r1, [r3]
	adds r3, #2
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _0804E076
	b _0804E0B2
_0804E0AE:
	ldr r1, _0804E0B8 @ =0x030044D0
	str r2, [r1]
_0804E0B2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804E0B8: .4byte 0x030044D0

	thumb_func_start FUN_0804e0bc
FUN_0804e0bc: @ 0x0804E0BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0804E11C @ =0x030000DC
_0804E0C2:
	ldrb r0, [r1]
	cmp r0, #1
	beq _0804E0C2
	movs r0, #0
	bl rfu_LMAN_manager_entity
	adds r4, r5, #0
	adds r4, #0x35
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804E0E4
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	movs r0, #0
	strb r0, [r4]
_0804E0E4:
	ldr r0, _0804E120 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0]
	cmp r1, #1
	bne _0804E0F8
	ldr r0, _0804E11C @ =0x030000DC
	strb r1, [r0]
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
_0804E0F8:
	adds r0, r5, #0
	bl FUN_0804d90c
	adds r0, r5, #0
	bl FUN_0804d9a4
	ldr r0, _0804E124 @ =0x085AB5E0
	ldrh r1, [r5, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E11C: .4byte 0x030000DC
_0804E120: .4byte 0x03005800
_0804E124: .4byte 0x085AB5E0

	thumb_func_start FUN_0804e128
FUN_0804e128: @ 0x0804E128
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #0
	strb r0, [r1]
	bl rfu_LMAN_manager_entity
	bl rfu_getMasterSlave
	adds r0, r4, #0
	bl FUN_0804dc90
	adds r0, r4, #0
	bl FUN_0804dd80
	ldr r1, _0804E160 @ =0x085AB5E0
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804E160: .4byte 0x085AB5E0

	thumb_func_start FUN_0804e164
FUN_0804e164: @ 0x0804E164
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_08241704
	ldr r0, _0804E18C @ =0x030000E0
	adds r1, r5, #0
	adds r1, #0x33
	ldrb r1, [r1]
	str r1, [r0]
	adds r0, r5, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804E1B0
	cmp r0, #1
	bgt _0804E190
	cmp r0, #0
	beq _0804E196
	b _0804E1E2
	.align 2, 0
_0804E18C: .4byte 0x030000E0
_0804E190:
	cmp r0, #2
	beq _0804E1CA
	b _0804E1E2
_0804E196:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E1A8
	adds r0, r5, #0
	bl FUN_0804de70
	b _0804E1E2
_0804E1A8:
	adds r0, r5, #0
	bl FUN_0804dee8
	b _0804E1E2
_0804E1B0:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E1C2
	adds r0, r5, #0
	bl FUN_0804df18
	b _0804E1E2
_0804E1C2:
	adds r0, r5, #0
	bl FUN_0804e028
	b _0804E1E2
_0804E1CA:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E1DC
	adds r0, r5, #0
	bl FUN_0804e0bc
	b _0804E1E2
_0804E1DC:
	adds r0, r5, #0
	bl FUN_0804e128
_0804E1E2:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804E204
	movs r4, #0
	strb r4, [r1]
	movs r0, #1
	bl rfu_LMAN_stopManager
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x38]
	str r4, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804E204:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _0804E230
	ldr r0, _0804E228 @ =0x0300481C
	movs r1, #0
	str r1, [r0]
	ldr r0, _0804E22C @ =0x03002B58
	str r1, [r0]
	adds r0, r5, #0
	bl RemoveEntity
	adds r0, r5, #0
	bl Free
	bl FUN_0824172c
	b _0804E24E
	.align 2, 0
_0804E228: .4byte 0x0300481C
_0804E22C: .4byte 0x03002B58
_0804E230:
	ldrh r0, [r5, #0x38]
	subs r0, #9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x11
	bhi _0804E242
	ldr r1, _0804E258 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_0804E242:
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x48]
	adds r0, #1
	str r0, [r5, #0x48]
_0804E24E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804E258: .4byte 0x030047B8

	thumb_func_start FUN_0804e25c
FUN_0804e25c: @ 0x0804E25C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x33
	movs r5, #0
	strb r5, [r0]
	ldr r0, _0804E2B4 @ =0x030000E0
	str r5, [r0]
	bl FUN_0823a6c0
	cmp r0, #0
	blt _0804E2AE
	strb r5, [r4, #0x1d]
	adds r0, r4, #0
	bl FUN_0804ba64
	movs r0, #1
	strb r5, [r4, #0x1c]
	movs r1, #1
	strh r0, [r4, #0x38]
	str r5, [r4, #0x44]
	adds r0, r4, #0
	adds r0, #0x32
	strb r1, [r0]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r4, #0x4c]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804E2AE
	bl FUN_0823d340
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _0804E2B8
_0804E2AE:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804E2BA
	.align 2, 0
_0804E2B4: .4byte 0x030000E0
_0804E2B8:
	movs r0, #0
_0804E2BA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e2c0
FUN_0804e2c0: @ 0x0804E2C0
	push {r4, r5, r6, r7, lr}
	ldr r7, _0804E2D0 @ =0x03002B58
	ldr r6, [r7]
	cmp r6, #0
	beq _0804E2D4
	adds r0, r6, #0
	b _0804E364
	.align 2, 0
_0804E2D0: .4byte 0x03002B58
_0804E2D4:
	bl FUN_08241704
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r0, r4, #0
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _0804E362
	adds r0, r5, #0
	adds r1, r4, #0
	bl ClearMemory
	bl GetSecond
	ldr r3, _0804E348 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0804E34C @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0804E350 @ =0x0203B400
	adds r1, r1, r2
	ldrh r3, [r1]
	ldr r1, _0804E354 @ =0x03002CF0
	movs r2, #0xff
	ldrb r1, [r1]
	adds r0, r0, r3
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	adds r0, r5, #0
	adds r0, #0x6c
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_0804e25c
	cmp r0, #0
	blt _0804E35C
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl SetEntityRoutine
	movs r4, #1
	strb r4, [r5, #0x14]
	strb r4, [r5, #0x16]
	strh r6, [r5, #0x10]
	adds r0, r5, #0
	bl AddEntity
	ldr r0, _0804E358 @ =0x0300481C
	str r4, [r0]
	str r5, [r7]
	adds r0, r5, #0
	b _0804E364
	.align 2, 0
_0804E348: .4byte 0x030046B8
_0804E34C: .4byte 0x000003FF
_0804E350: .4byte 0x0203B400
_0804E354: .4byte 0x03002CF0
_0804E358: .4byte 0x0300481C
_0804E35C:
	adds r0, r5, #0
	bl Free
_0804E362:
	movs r0, #0
_0804E364:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e36c
FUN_0804e36c: @ 0x0804E36C
	push {lr}
	ldr r0, _0804E380 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E37A
	bl FUN_0804e164
_0804E37A:
	pop {r0}
	bx r0
	.align 2, 0
_0804E380: .4byte 0x03002B58

	thumb_func_start FUN_0804e384
FUN_0804e384: @ 0x0804E384
	push {lr}
	ldr r0, _0804E39C @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E396
	adds r1, r0, #0
	adds r1, #0xfb
	movs r0, #1
	strb r0, [r1]
_0804E396:
	pop {r0}
	bx r0
	.align 2, 0
_0804E39C: .4byte 0x03002B58

	thumb_func_start FUN_0804e3a0
FUN_0804e3a0: @ 0x0804E3A0
	push {lr}
	ldr r0, _0804E3B4 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E3B8
	ldrb r0, [r0, #0x1f]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _0804E3BC
	.align 2, 0
_0804E3B4: .4byte 0x03002B58
_0804E3B8:
	movs r0, #1
	rsbs r0, r0, #0
_0804E3BC:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e3c0
FUN_0804e3c0: @ 0x0804E3C0
	push {lr}
	ldr r0, _0804E3D8 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E3D4
	ldr r0, _0804E3DC @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E3E0
_0804E3D4:
	movs r0, #0
	b _0804E3E6
	.align 2, 0
_0804E3D8: .4byte 0x03002B58
_0804E3DC: .4byte 0x03005800
_0804E3E0:
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
_0804E3E6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e3ec
FUN_0804e3ec: @ 0x0804E3EC
	push {lr}
	ldr r0, _0804E414 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E426
	adds r0, r1, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E41C
	ldrh r0, [r1, #0x38]
	cmp r0, #4
	bls _0804E426
	ldr r0, _0804E418 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _0804E426
	b _0804E430
	.align 2, 0
_0804E414: .4byte 0x03002B58
_0804E418: .4byte 0x03005800
_0804E41C:
	ldr r0, _0804E42C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E430
_0804E426:
	movs r0, #0
	b _0804E432
	.align 2, 0
_0804E42C: .4byte 0x03005800
_0804E430:
	movs r0, #1
_0804E432:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e438
FUN_0804e438: @ 0x0804E438
	push {lr}
	ldr r0, _0804E44C @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E450
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r0, r1
	b _0804E452
	.align 2, 0
_0804E44C: .4byte 0x03002B58
_0804E450:
	movs r0, #0
_0804E452:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e458
FUN_0804e458: @ 0x0804E458
	push {lr}
	ldr r0, _0804E468 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E46C
	adds r0, #0x30
	ldrb r0, [r0]
	b _0804E46E
	.align 2, 0
_0804E468: .4byte 0x03002B58
_0804E46C:
	movs r0, #0
_0804E46E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e474
FUN_0804e474: @ 0x0804E474
	push {lr}
	ldr r0, _0804E484 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E488
	ldrb r0, [r0, #0x19]
	b _0804E48A
	.align 2, 0
_0804E484: .4byte 0x03002B58
_0804E488:
	movs r0, #0
_0804E48A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e490
FUN_0804e490: @ 0x0804E490
	push {lr}
	ldr r0, _0804E4A0 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E4A4
	ldrh r0, [r0, #0x38]
	b _0804E4A6
	.align 2, 0
_0804E4A0: .4byte 0x03002B58
_0804E4A4:
	movs r0, #0
_0804E4A6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e4ac
FUN_0804e4ac: @ 0x0804E4AC
	push {lr}
	ldr r0, _0804E4C0 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E4BA
	movs r0, #1
	strb r0, [r1, #0x1b]
_0804E4BA:
	pop {r0}
	bx r0
	.align 2, 0
_0804E4C0: .4byte 0x03002B58

	thumb_func_start FUN_0804e4c4
FUN_0804e4c4: @ 0x0804E4C4
	push {lr}
	ldr r0, _0804E4D8 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E4D2
	movs r0, #1
	strb r0, [r1, #0x1c]
_0804E4D2:
	pop {r0}
	bx r0
	.align 2, 0
_0804E4D8: .4byte 0x03002B58

	thumb_func_start FUN_0804e4dc
FUN_0804e4dc: @ 0x0804E4DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804E510 @ =0x03002B58
	ldr r0, [r0]
	mov ip, r0
	cmp r0, #0
	beq _0804E50A
	movs r0, #0xde
	lsls r0, r0, #2
	add r0, ip
	str r4, [r0]
	movs r0, #0xdf
	lsls r0, r0, #2
	add r0, ip
	str r1, [r0]
	movs r0, #0xe0
	lsls r0, r0, #2
	add r0, ip
	str r2, [r0]
	movs r0, #0xe1
	lsls r0, r0, #2
	add r0, ip
	str r3, [r0]
_0804E50A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804E510: .4byte 0x03002B58

	thumb_func_start FUN_0804e514
FUN_0804e514: @ 0x0804E514
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0804E548 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	beq _0804E550
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804E550
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r2, _0804E54C @ =0x04000003
	adds r0, r3, #0
	bl CpuSet
	ldrh r1, [r4, #0x22]
	movs r0, #1
	orrs r0, r1
	strh r0, [r4, #0x22]
	movs r0, #0
	b _0804E554
	.align 2, 0
_0804E548: .4byte 0x03002B58
_0804E54C: .4byte 0x04000003
_0804E550:
	movs r0, #1
	rsbs r0, r0, #0
_0804E554:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e55c
FUN_0804e55c: @ 0x0804E55C
	push {lr}
	adds r1, r0, #0
	ldr r0, _0804E574 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E57C
	adds r0, #0xc4
	ldr r2, _0804E578 @ =0x04000003
	bl CpuSet
	movs r0, #0
	b _0804E580
	.align 2, 0
_0804E574: .4byte 0x03002B58
_0804E578: .4byte 0x04000003
_0804E57C:
	movs r0, #1
	rsbs r0, r0, #0
_0804E580:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e584
FUN_0804e584: @ 0x0804E584
	push {lr}
	adds r1, r0, #0
	ldr r0, _0804E598 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E594
	adds r0, #0x33
	strb r1, [r0]
_0804E594:
	pop {r0}
	bx r0
	.align 2, 0
_0804E598: .4byte 0x03002B58

	thumb_func_start FUN_0804e59c
FUN_0804e59c: @ 0x0804E59C
	push {lr}
	ldr r0, _0804E5AC @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E5B0
	adds r0, #0x33
	ldrb r0, [r0]
	b _0804E5B4
	.align 2, 0
_0804E5AC: .4byte 0x03002B58
_0804E5B0:
	ldr r0, _0804E5B8 @ =0x030000E0
	ldr r0, [r0]
_0804E5B4:
	pop {r1}
	bx r1
	.align 2, 0
_0804E5B8: .4byte 0x030000E0

	thumb_func_start FUN_0804e5bc
FUN_0804e5bc: @ 0x0804E5BC
	push {lr}
	ldr r0, _0804E5E4 @ =0x03002B58
	ldr r3, [r0]
	cmp r3, #0
	beq _0804E5DE
	adds r0, r3, #0
	adds r0, #0x3f
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	movs r0, #0x1f
	strb r1, [r3, #0x1c]
	strh r0, [r3, #0x38]
	str r1, [r3, #0x44]
	adds r0, r3, #0
	adds r0, #0x32
	strb r2, [r0]
_0804E5DE:
	pop {r0}
	bx r0
	.align 2, 0
_0804E5E4: .4byte 0x03002B58

	thumb_func_start FUN_0804e5e8
FUN_0804e5e8: @ 0x0804E5E8
	push {lr}
	ldr r0, _0804E600 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E5FA
	adds r1, r0, #0
	adds r1, #0x3d
	movs r0, #1
	strb r0, [r1]
_0804E5FA:
	pop {r0}
	bx r0
	.align 2, 0
_0804E600: .4byte 0x03002B58

	thumb_func_start FUN_0804e604
FUN_0804e604: @ 0x0804E604
	push {lr}
	ldr r0, _0804E618 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E612
	movs r0, #1
	strb r0, [r1, #0x1d]
_0804E612:
	pop {r0}
	bx r0
	.align 2, 0
_0804E618: .4byte 0x03002B58

	thumb_func_start FUN_0804e61c
FUN_0804e61c: @ 0x0804E61C
	push {lr}
	ldr r0, _0804E62C @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E630
	adds r0, #0x50
	b _0804E632
	.align 2, 0
_0804E62C: .4byte 0x03002B58
_0804E630:
	movs r0, #0
_0804E632:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e638
FUN_0804e638: @ 0x0804E638
	push {lr}
	ldr r0, _0804E648 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E64C
	adds r0, #0x6c
	ldrh r0, [r0]
	b _0804E64E
	.align 2, 0
_0804E648: .4byte 0x03002B58
_0804E64C:
	movs r0, #0
_0804E64E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e654
FUN_0804e654: @ 0x0804E654
	ldr r0, _0804E658 @ =0x0203FC00
	bx lr
	.align 2, 0
_0804E658: .4byte 0x0203FC00

	thumb_func_start FUN_0804e65c
FUN_0804e65c: @ 0x0804E65C
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl FUN_0804e654
	lsls r4, r4, #1
	adds r4, r4, r0
	ldrh r0, [r4]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e674
FUN_0804e674: @ 0x0804E674
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl FUN_0804e654
	adds r2, r0, #0
	movs r1, #0
_0804E682:
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r4
	beq _0804E694
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _0804E682
_0804E694:
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e69c
FUN_0804e69c: @ 0x0804E69C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r5, #0
	cmp r5, r6
	bge _0804E6CE
_0804E6AA:
	adds r0, r7, r5
	ldrb r0, [r0]
	bl FUN_0804e65c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x7f
	bhi _0804E6C0
	strb r1, [r4]
	adds r4, #1
	b _0804E6C8
_0804E6C0:
	strb r1, [r4]
	lsrs r0, r0, #0x18
	strb r0, [r4, #1]
	adds r4, #2
_0804E6C8:
	adds r5, #1
	cmp r5, r6
	blt _0804E6AA
_0804E6CE:
	movs r0, #0
	strb r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804e6d8
FUN_0804e6d8: @ 0x0804E6D8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r5, #0
	b _0804E706
_0804E6E4:
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _0804E6F0
	ldrb r1, [r4]
	adds r4, #1
	b _0804E6FA
_0804E6F0:
	ldrb r1, [r4]
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	orrs r1, r0
	adds r4, #2
_0804E6FA:
	adds r0, r1, #0
	bl FUN_0804e674
	adds r1, r7, r5
	strb r0, [r1]
	adds r5, #1
_0804E706:
	cmp r5, r6
	bge _0804E720
	ldrb r0, [r4]
	cmp r0, #0
	bne _0804E6E4
	cmp r5, r6
	bge _0804E720
	movs r1, #0
_0804E716:
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #1
	cmp r5, r6
	blt _0804E716
_0804E720:
	adds r1, r7, r6
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Crossover_LoadMappingBuf
Crossover_LoadMappingBuf: @ 0x0804E72C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804E744
	bl VM_GetPC
	adds r6, r0, #0
	b _0804E746
_0804E744:
	movs r6, #0
_0804E746:
	cmp r6, #0
	beq _0804E7A8
	bl FUN_0804e654
	adds r7, r0, #0
	movs r5, #0
	movs r4, #0
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
_0804E75A:
	adds r0, r6, #0
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	adds r2, r0, #0
	ldrb r1, [r2]
	adds r4, #1
	cmp r1, #0
	beq _0804E7A0
	cmp r5, r8
	beq _0804E7A0
	lsls r0, r5, #1
	adds r3, r0, r7
_0804E778:
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _0804E786
	ldrb r0, [r2]
	strh r0, [r3]
	adds r2, #1
	b _0804E792
_0804E786:
	ldrb r1, [r2, #1]
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	strh r0, [r3]
	adds r2, #2
_0804E792:
	adds r3, #2
	adds r5, #1
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804E7A0
	cmp r5, r8
	bne _0804E778
_0804E7A0:
	cmp r4, #4
	ble _0804E75A
	movs r0, #0
	strh r0, [r7]
_0804E7A8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
