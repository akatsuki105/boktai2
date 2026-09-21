	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08018990
FUN_08018990: @ 0x08018990
	push {r4, r5, lr}
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080189AA
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	b _080189B0
_080189AA:
	movs r4, #0x96
	lsls r4, r4, #3
	adds r5, r4, #0
_080189B0:
	movs r0, #0x69
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080189C2
	bl Script_GetValue
	b _080189E4
_080189C2:
	ldr r1, _080189F4 @ =0x03000078
	ldr r3, [r1]
	cmp r3, #0
	ble _080189E4
	ldr r2, _080189F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080189FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08018A00 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	bl Mod
_080189E4:
	ldr r1, _08018A04 @ =0x03000074
	str r5, [r1]
	ldr r1, _080189F4 @ =0x03000078
	str r4, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080189F4: .4byte 0x03000078
_080189F8: .4byte 0x030046B8
_080189FC: .4byte 0x000003FF
_08018A00: .4byte 0x0203B400
_08018A04: .4byte 0x03000074

	thumb_func_start FUN_08018a08
FUN_08018a08: @ 0x08018A08
	ldr r0, _08018A10 @ =0x0300007C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08018A10: .4byte 0x0300007C

	thumb_func_start FUN_08018a14
FUN_08018a14: @ 0x08018A14
	push {lr}
	bl FUN_08018a08
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08018a20
FUN_08018a20: @ 0x08018A20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	mov sb, r3
	lsls r3, r4, #1
	ldr r1, _08018A60 @ =0x030042B0
	adds r6, r3, r1
	mov ip, r6
	subs r1, #0x20
	adds r7, r3, r1
	mov r1, sb
	cmp r1, #0x1f
	ble _08018A64
	adds r6, r4, #0
	cmp r6, r2
	bge _08018ACE
	subs r6, r2, r6
_08018A4A:
	mov r2, ip
	ldrh r1, [r2]
	strh r1, [r7]
	movs r3, #2
	add ip, r3
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _08018A4A
	b _08018ACE
	.align 2, 0
_08018A60: .4byte 0x030042B0
_08018A64:
	adds r1, r3, #0
	adds r1, #0x28
	adds r5, r5, r1
	mov r8, r5
	movs r1, #0x20
	mov r6, sb
	subs r6, r1, r6
	mov sl, r6
	adds r6, r4, #0
	cmp r6, r2
	bge _08018ACE
	subs r6, r2, r6
_08018A7C:
	mov r2, r8
	ldrh r1, [r2]
	ldr r4, _08018ADC @ =0x00007C1F
	ands r4, r1
	movs r5, #0xf8
	lsls r5, r5, #2
	ands r5, r1
	mov r3, ip
	ldrh r2, [r3]
	adds r1, r2, #0
	ldr r3, _08018ADC @ =0x00007C1F
	ands r1, r3
	mov r3, sb
	muls r3, r1, r3
	mov r1, sl
	muls r1, r4, r1
	adds r3, r3, r1
	ldr r1, _08018AE0 @ =0x000F83E0
	ands r3, r1
	movs r1, #0xf8
	lsls r1, r1, #2
	ands r2, r1
	mov r1, sb
	muls r1, r2, r1
	adds r2, r1, #0
	mov r1, sl
	muls r1, r5, r1
	adds r2, r2, r1
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r2, r1
	orrs r3, r2
	lsrs r3, r3, #5
	strh r3, [r7]
	movs r2, #2
	add r8, r2
	add ip, r2
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _08018A7C
_08018ACE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08018ADC: .4byte 0x00007C1F
_08018AE0: .4byte 0x000F83E0

	thumb_func_start FUN_08018ae4
FUN_08018ae4: @ 0x08018AE4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	lsls r3, r1, #1
	adds r2, r3, #0
	adds r2, #0x28
	adds r4, r4, r2
	ldr r2, _08018B14 @ =0x03004290
	adds r3, r3, r2
	adds r2, r1, #0
	cmp r2, r5
	bge _08018B0C
	subs r2, r5, r2
_08018AFE:
	ldrh r1, [r4]
	strh r1, [r3]
	adds r3, #2
	adds r4, #2
	subs r2, #1
	cmp r2, #0
	bne _08018AFE
_08018B0C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08018B14: .4byte 0x03004290

	thumb_func_start FUN_08018b18
FUN_08018b18: @ 0x08018B18
	push {lr}
	adds r1, r0, #0
	ldr r0, _08018B2C @ =0x03004290
	adds r1, #0x28
	ldr r2, _08018B30 @ =0x04000008
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_08018B2C: .4byte 0x03004290
_08018B30: .4byte 0x04000008

	thumb_func_start Entity517B_Update
Entity517B_Update: @ 0x08018B34
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _08018B46
	adds r0, r5, #0
	bl FUN_08018b18
_08018B46:
	ldrb r0, [r5, #0x1c]
	cmp r0, #2
	bne _08018B68
	ldr r2, [r5, #0x24]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne _08018BC4
	ldrh r0, [r5, #0x20]
	ldrh r1, [r5, #0x22]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08018BC4
	strh r2, [r5, #0x20]
	b _08018BC4
_08018B68:
	cmp r0, #1
	bne _08018B8C
	ldr r0, [r5, #0x24]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08018BC4
	ldrh r0, [r5, #0x22]
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _08018BC4
	movs r0, #0x20
	strh r0, [r5, #0x20]
	b _08018BC4
_08018B8C:
	ldr r0, [r5, #0x24]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08018BC4
	ldrh r1, [r5, #0x22]
	ldrh r2, [r5, #0x20]
	adds r0, r1, r2
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _08018BB8
	movs r0, #0x20
	strh r0, [r5, #0x20]
	ldr r2, _08018BB4 @ =0x0000FFFF
	adds r0, r2, #0
	orrs r0, r1
	b _08018BC2
	.align 2, 0
_08018BB4: .4byte 0x0000FFFF
_08018BB8:
	cmp r0, #0x10
	bgt _08018BC4
	movs r0, #0x10
	strh r0, [r5, #0x20]
	movs r0, #1
_08018BC2:
	strh r0, [r5, #0x22]
_08018BC4:
	movs r2, #1
	ldrb r0, [r5, #0x1c]
	cmp r0, #1
	beq _08018C14
	cmp r0, #1
	bgt _08018BD6
	cmp r0, #0
	beq _08018BDC
	b _08018CB4
_08018BD6:
	cmp r0, #2
	beq _08018C64
	b _08018CB4
_08018BDC:
	movs r6, #0
_08018BDE:
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r5, #0x18]
	ands r0, r1
	cmp r0, #0
	bne _08018BF8
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018ae4
	b _08018C08
_08018BF8:
	adds r4, r2, #3
	movs r0, #0x20
	ldrsh r3, [r5, r0]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
_08018C08:
	adds r1, r4, #0
	adds r2, r1, #0
	adds r6, #1
	cmp r6, #3
	ble _08018BDE
	b _08018CB4
_08018C14:
	movs r6, #0
_08018C16:
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r5, #0x18]
	ands r0, r1
	cmp r0, #0
	bne _08018C4A
	ldrh r0, [r5, #0x1a]
	ands r0, r1
	cmp r0, #0
	bne _08018C38
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018ae4
	b _08018C58
_08018C38:
	adds r4, r2, #3
	movs r1, #0x20
	ldrsh r3, [r5, r1]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
	b _08018C58
_08018C4A:
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	movs r3, #0x20
	bl FUN_08018a20
_08018C58:
	adds r1, r4, #0
	adds r2, r1, #0
	adds r6, #1
	cmp r6, #3
	ble _08018C16
	b _08018CB4
_08018C64:
	movs r6, #0
_08018C66:
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r5, #0x18]
	ands r0, r1
	cmp r0, #0
	bne _08018C9A
	ldrh r0, [r5, #0x1a]
	ands r0, r1
	cmp r0, #0
	bne _08018C88
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018ae4
	b _08018CAA
_08018C88:
	adds r4, r2, #3
	movs r0, #0x20
	ldrsh r3, [r5, r0]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
	b _08018CAA
_08018C9A:
	adds r4, r2, #3
	movs r1, #0x20
	ldrsh r3, [r5, r1]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
_08018CAA:
	adds r1, r4, #0
	adds r2, r1, #0
	adds r6, #1
	cmp r6, #3
	ble _08018C66
_08018CB4:
	ldr r0, [r5, #0x24]
	adds r0, #1
	str r0, [r5, #0x24]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity517B_Destroy
Entity517B_Destroy: @ 0x08018CC4
	ldr r1, _08018CCC @ =0x03000088
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08018CCC: .4byte 0x03000088

	thumb_func_start Entity517B_Init
Entity517B_Init: @ 0x08018CD0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08018D10 @ =0x03000088
	str r5, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	ldrh r1, [r5, #0x18]
	orrs r4, r1
	strh r4, [r5, #0x18]
	ldrh r1, [r5, #0x1a]
	orrs r0, r1
	strh r0, [r5, #0x1a]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0x1c]
	ldrb r0, [r5, #0x1c]
	cmp r0, #1
	beq _08018D22
	cmp r0, #1
	bgt _08018D14
	cmp r0, #0
	beq _08018D1A
	b _08018D34
	.align 2, 0
_08018D10: .4byte 0x03000088
_08018D14:
	cmp r0, #2
	beq _08018D26
	b _08018D34
_08018D1A:
	movs r0, #0x10
	strh r0, [r5, #0x20]
	movs r0, #1
	b _08018D32
_08018D22:
	movs r0, #0
	b _08018D28
_08018D26:
	movs r0, #0x20
_08018D28:
	strh r0, [r5, #0x20]
	movs r0, #0x61
	movs r1, #2
	bl VM_GetKeywordValue
_08018D32:
	strh r0, [r5, #0x22]
_08018D34:
	adds r0, r5, #0
	bl FUN_08018b18
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity517B_Create
Entity517B_Create: @ 0x08018D44
	push {r4, lr}
	movs r0, #0xc
	movs r1, #0x48
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08018D78
	ldr r1, _08018D70 @ =Entity517B_Update
	ldr r2, _08018D74 @ =Entity517B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity517B_Init
	cmp r0, #0
	bge _08018D78
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08018D7A
	.align 2, 0
_08018D70: .4byte Entity517B_Update
_08018D74: .4byte Entity517B_Destroy
_08018D78:
	adds r0, r4, #0
_08018D7A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018d80
FUN_08018d80: @ 0x08018D80
	push {r4, lr}
	ldr r0, _08018DA4 @ =0x03000088
	ldr r4, [r0]
	cmp r4, #0
	beq _08018DCA
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r4, #0x1c]
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _08018DB6
	cmp r0, #1
	bgt _08018DA8
	cmp r0, #0
	beq _08018DAE
	b _08018DCA
	.align 2, 0
_08018DA4: .4byte 0x03000088
_08018DA8:
	cmp r0, #2
	beq _08018DC0
	b _08018DCA
_08018DAE:
	movs r0, #0x10
	strh r0, [r4, #0x20]
	movs r0, #1
	b _08018DC8
_08018DB6:
	movs r0, #0
	strh r0, [r4, #0x20]
	movs r0, #0x61
	movs r1, #2
	b _08018DC4
_08018DC0:
	movs r0, #0x61
	movs r1, #1
_08018DC4:
	bl VM_GetKeywordValue
_08018DC8:
	strh r0, [r4, #0x22]
_08018DCA:
	pop {r4}
	pop {r0}
	bx r0
