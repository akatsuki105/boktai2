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
	bl TextPanel_Create
	adds r2, r0, #0
	str r2, [r5]
	cmp r2, #0
	blt _0804AD90
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl TextPanel_SetScript
	ldr r0, [r5]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r0, [r5]
	bl TextPanel_Start
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
	bl VM_ExecByID
_0804AFAA:
	ldr r0, [r4, #0x34]
	adds r0, #1
	str r0, [r4, #0x34]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start EntityB88C_Update
EntityB88C_Update: @ 0x0804AFB8
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

	thumb_func_start EntityB88C_Destroy
EntityB88C_Destroy: @ 0x0804B030
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
	bl TextPanel_Destroy
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start EntityB88C_Init
EntityB88C_Init: @ 0x0804B060
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
	bl VM_GetValue
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

	thumb_func_start EntityB88C_Create
EntityB88C_Create: @ 0x0804B220
	push {r4, lr}
	movs r1, #0xa1
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804B258
	ldr r1, _0804B250 @ =EntityB88C_Update
	ldr r2, _0804B254 @ =EntityB88C_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB88C_Init
	cmp r0, #0
	bge _0804B258
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804B25A
	.align 2, 0
_0804B250: .4byte EntityB88C_Update
_0804B254: .4byte EntityB88C_Destroy
_0804B258:
	adds r0, r4, #0
_0804B25A:
	pop {r4}
	pop {r1}
	bx r1
