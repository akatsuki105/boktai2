	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08011110
FUN_08011110: @ 0x08011110
	adds r2, r0, #0
	ldr r1, [r2, #0x7c]
	ldr r0, _08011120 @ =0x6262C05D
	muls r0, r1, r0
	adds r0, #1
	str r0, [r2, #0x7c]
	bx lr
	.align 2, 0
_08011120: .4byte 0x6262C05D

	thumb_func_start FUN_08011124
FUN_08011124: @ 0x08011124
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08011174 @ =0x0000FFFF
	movs r5, #0
	adds r1, r7, #0
	adds r1, #0x88
	ldr r0, [r1]
	adds r0, #4
	cmp r5, r0
	bhs _0801114C
	adds r4, r1, #0
_0801113A:
	adds r0, r7, #0
	bl FUN_08011110
	eors r6, r0
	adds r5, #1
	ldr r0, [r4]
	adds r0, #4
	cmp r5, r0
	blo _0801113A
_0801114C:
	adds r4, r7, #4
	movs r5, #0x13
_08011150:
	ldrb r1, [r4]
	adds r0, r6, #0
	eors r0, r1
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r4]
	adds r0, r7, #0
	bl FUN_08011110
	eors r6, r0
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	bge _08011150
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011174: .4byte 0x0000FFFF

	thumb_func_start FUN_08011178
FUN_08011178: @ 0x08011178
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r1, #0
_08011180:
	ldrb r0, [r3]
	cmp r0, r4
	bne _08011190
	ldrb r0, [r3, #1]
	cmp r0, r2
	bne _08011190
	adds r0, r1, #0
	b _0801119C
_08011190:
	adds r1, #1
	adds r3, #2
	cmp r1, #0x3f
	ble _08011180
	movs r0, #1
	rsbs r0, r0, #0
_0801119C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080111a4
FUN_080111a4: @ 0x080111A4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #0
_080111AE:
	ldr r0, [r6, #0x74]
	ldrb r1, [r4]
	ldrb r2, [r4, #1]
	bl FUN_08011178
	adds r1, r0, #0
	cmp r1, #0x3f
	bls _080111C4
	movs r0, #1
	rsbs r0, r0, #0
	b _080111D2
_080111C4:
	adds r0, r6, r5
	strb r1, [r0]
	adds r5, #1
	adds r4, #2
	cmp r5, #0x17
	ble _080111AE
	movs r0, #0
_080111D2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080111d8
FUN_080111d8: @ 0x080111D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov r8, r1
	adds r7, r2, #0
	movs r0, #0
	mov sb, r0
	movs r6, #0
	cmp sb, r7
	bge _0801122A
	mov r5, r8
	cmp r5, #0x8f
	bgt _0801122A
_080111F8:
	adds r0, r5, #0
	movs r1, #6
	bl Div
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #6
	bl Mod
	add r4, sl
	ldrb r1, [r4]
	asrs r1, r0
	movs r0, #1
	ands r1, r0
	lsls r1, r6
	mov r0, sb
	orrs r0, r1
	mov sb, r0
	adds r6, #1
	cmp r6, r7
	bge _0801122A
	mov r0, r8
	adds r5, r0, r6
	cmp r5, #0x8f
	ble _080111F8
_0801122A:
	mov r0, sb
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start PasswordDecoder_IsIllegalName
PasswordDecoder_IsIllegalName: @ 0x0801123C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r0, #0
	mov sb, r0
	mov r6, r8
	adds r6, #0x60
_0801124E:
	ldrh r0, [r6]
	cmp r0, #0
	beq _0801129A
	movs r7, #0
	movs r4, #0
	adds r5, r6, #0
_0801125A:
	mov r1, r8
	ldr r0, [r1, #0x78]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	adds r1, r0, #0
	ldrb r0, [r1]
	adds r2, r4, #1
	b _08011274
_08011270:
	adds r1, #2
	ldrb r0, [r1]
_08011274:
	cmp r0, #0
	beq _08011282
	ldrb r0, [r1, #1]
	ldrh r3, [r5]
	cmp r0, r3
	bne _08011270
	movs r7, #1
_08011282:
	adds r4, r2, #0
	cmp r4, #1
	ble _0801125A
	cmp r7, #0
	bne _0801129A
	ldrh r0, [r6]
	cmp r0, #0xec
	beq _08011296
	movs r0, #1
	b _080112A8
_08011296:
	movs r0, #0xf0
	strh r0, [r6]
_0801129A:
	adds r6, #2
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #4
	ble _0801124E
	movs r0, #0
_080112A8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start PasswordDecoder_Parse
PasswordDecoder_Parse: @ 0x080112B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0x48
	adds r0, r0, r7
	mov r8, r0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #3
	bl FUN_080111d8
	adds r1, r7, #0
	adds r1, #0x80
	str r0, [r1]
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x10
	bl FUN_080111d8
	adds r4, r7, #0
	adds r4, #0x84
	str r0, [r4]
	adds r0, r7, #0
	movs r1, #0x13
	movs r2, #2
	bl FUN_080111d8
	adds r1, r7, #0
	adds r1, #0x88
	str r0, [r1]
	movs r6, #0x15
	ldr r2, _0801131C @ =0x0000FFFF
	movs r5, #4
	mov sb, r4
	movs r4, #0x80
	lsls r4, r4, #8
	ldr r1, _08011320 @ =0x00001021
_08011302:
	adds r0, r7, r5
	ldrb r0, [r0]
	lsls r0, r0, #8
	eors r2, r0
	movs r3, #0
	adds r5, #1
_0801130E:
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08011324
	lsls r2, r2, #1
	eors r2, r1
	b _08011326
	.align 2, 0
_0801131C: .4byte 0x0000FFFF
_08011320: .4byte 0x00001021
_08011324:
	lsls r2, r2, #1
_08011326:
	adds r3, #1
	cmp r3, #7
	bls _0801130E
	cmp r5, #0x17
	ble _08011302
	ldr r0, _08011344 @ =0x0000FFFF
	bics r0, r2
	mov r2, sb
	ldr r1, [r2]
	cmp r0, r1
	beq _08011348
	movs r0, #2
	rsbs r0, r0, #0
	b _0801148E
	.align 2, 0
_08011344: .4byte 0x0000FFFF
_08011348:
	adds r0, r7, #0
	bl FUN_08011124
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #9
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1]
	adds r6, #9
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #2]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #4]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #6]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #3
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #8]
	adds r6, #3
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0xa]
	adds r6, #5
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #3
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #0xc]
	adds r6, #3
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #4
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0xe]
	adds r6, #4
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #0x10]
	adds r6, #5
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #7
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0x12]
	adds r6, #7
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #4
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #0x14]
	adds r6, #4
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0x16]
	adds r6, #5
	movs r0, #0x80
	adds r0, r0, r7
	mov sb, r0
	mov r4, r8
	adds r4, #0x18
	movs r5, #4
_0801141A:
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #8
	bl FUN_080111d8
	strh r0, [r4]
	adds r6, #8
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0801141A
	mov r1, sb
	ldr r0, [r1]
	cmp r0, #1
	bne _08011466
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0x24]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #6
	bl FUN_080111d8
	mov r1, r8
	strh r0, [r1, #0x26]
	adds r6, #6
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #8
	bl FUN_080111d8
	mov r2, r8
	strh r0, [r2, #0x28]
_08011466:
	mov r1, r8
	ldrh r0, [r1, #0x18]
	cmp r0, #0
	beq _08011486
	adds r0, r7, #0
	bl PasswordDecoder_IsIllegalName
	cmp r0, #0
	bne _08011486
	mov r2, r8
	ldrh r0, [r2, #0xc]
	cmp r0, #0
	beq _08011486
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _0801148C
_08011486:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801148E
_0801148C:
	movs r0, #0
_0801148E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start PasswordDecoder_NOP
PasswordDecoder_NOP: @ 0x0801149C
	push {lr}
	movs r0, #4
_080114A0:
	subs r0, #1
	cmp r0, #0
	bge _080114A0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start PasswordDecoder_SaveChanges
PasswordDecoder_SaveChanges: @ 0x080114AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	adds r5, r6, #0
	adds r5, #0x60
	adds r4, r1, #0
	movs r7, #0
	b _080114F2
_080114C4:
	cmp r1, #0xf0
	bne _080114E2
	ldr r0, [r6, #0x78]
	bl VM_ParseStringRef
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r1, #0xa0
	ldrb r1, [r1]
	strb r1, [r4]
	adds r0, #0xa1
	ldrb r0, [r0]
	strb r0, [r4, #1]
	b _080114E8
_080114E2:
	movs r0, #0x80
	strb r0, [r4]
	strb r1, [r4, #1]
_080114E8:
	adds r7, #1
	adds r4, #2
	adds r5, #2
	cmp r7, #4
	bgt _080114F8
_080114F2:
	ldrh r1, [r5]
	cmp r1, #0
	bne _080114C4
_080114F8:
	movs r0, #0
	strb r0, [r4]
	ldr r1, _0801151C @ =0x030046A0
	ldr r2, [r1]
	mov r3, r8
	ldrh r0, [r3, #2]
	strh r0, [r2, #0xa]
	ldr r2, [r1]
	ldrh r0, [r3, #0x14]
	strh r0, [r2, #0xc]
	ldr r1, [r1]
	ldrh r0, [r3, #0x16]
	strh r0, [r1, #0xe]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801151C: .4byte 0x030046A0

	thumb_func_start PasswordDecoder_StripTags
PasswordDecoder_StripTags: @ 0x08011520
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	movs r6, #0
	movs r2, #0
	b _08011576
_0801152C:
	lsls r3, r0, #0x18
	cmp r3, #0
	blt _08011556
	lsrs r3, r3, #0x18
	cmp r3, #0x3c
	bne _0801153C
	movs r6, #1
	b _08011552
_0801153C:
	cmp r3, #0x3e
	bne _08011544
	movs r6, #0
	b _08011552
_08011544:
	cmp r6, #0
	bne _08011552
	strb r0, [r4]
	adds r4, #1
	adds r2, #1
	cmp r2, r5
	bge _0801157C
_08011552:
	adds r1, #1
	b _08011576
_08011556:
	movs r6, #0
	strb r0, [r4]
	adds r1, #1
	adds r4, #1
	adds r2, #1
	cmp r2, r5
	bge _0801157C
	ldrb r3, [r1]
	cmp r3, #0
	beq _0801157C
	strb r3, [r4]
	adds r1, #1
	adds r4, #1
	adds r2, #1
	cmp r2, r5
	bge _0801157C
_08011576:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801152C
_0801157C:
	adds r0, r2, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08011584
FUN_08011584: @ 0x08011584
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	mov r8, r3
	movs r0, #0x8c
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	bne _080115A4
	movs r0, #1
	rsbs r0, r0, #0
	b _080115F8
_080115A4:
	adds r0, r5, #0
	movs r1, #0x8c
	bl ClearMemory
	adds r0, r4, #0
	bl VM_ParseStringRef
	bl Textbox_LookupString
	str r0, [r5, #0x74]
	str r7, [r5, #0x78]
	ldr r0, _08011604 @ =0x0008C159
	str r0, [r5, #0x7c]
	adds r0, r5, #0
	adds r0, #0x18
	adds r1, r6, #0
	movs r2, #0x30
	bl PasswordDecoder_StripTags
	adds r0, r5, #0
	bl FUN_080111a4
	adds r4, r0, #0
	cmp r4, #0
	blt _080115F0
	adds r0, r5, #0
	bl PasswordDecoder_Parse
	adds r4, r0, #0
	cmp r4, #0
	blt _080115F0
	adds r0, r5, #0
	mov r1, r8
	bl PasswordDecoder_SaveChanges
	adds r0, r5, #0
	bl PasswordDecoder_NOP
_080115F0:
	adds r0, r5, #0
	bl Free
	adds r0, r4, #0
_080115F8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011604: .4byte 0x0008C159

	thumb_func_start FUN_08011608
FUN_08011608: @ 0x08011608
	push {r4, r5, lr}
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801165A
	bl VM_GetPC
	adds r5, r0, #0
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801165A
	bl VM_GetPC
	adds r4, r0, #0
	cmp r4, #0
	beq _0801165A
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801165A
	bl VM_GetPC
	cmp r0, #0
	beq _0801165A
	bl VM_ParseStringRef
	bl Textbox_LookupString
	ldr r1, _08011660 @ =0x030046A0
	ldr r3, [r1]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r3, r3, r1
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08011584
_0801165A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08011660: .4byte 0x030046A0

	thumb_func_start EntityB0BC_Update
EntityB0BC_Update: @ 0x08011664
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, [r4, #0x24]
	cmp r0, #0x77
	bgt _08011676
	ldr r1, _080116A0 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_08011676:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bge _080116BE
	ldr r0, [r4, #0x20]
	cmp r0, #0x3c
	bne _080116B8
	bl FUN_08241360
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r4, #0x24]
	cmp r0, #1
	bne _080116A8
	ldr r0, [r4, #0x18]
	movs r1, #0xe
	bl FUN_0804a2f8
	ldr r0, _080116A4 @ =0x000002AE
	bl PlaySound_082406e0
	b _080116B8
	.align 2, 0
_080116A0: .4byte 0x030047B8
_080116A4: .4byte 0x000002AE
_080116A8:
	ldr r0, [r4, #0x18]
	movs r1, #0xf
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080116B8:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	blt _080116D0
_080116BE:
	ldr r0, [r4, #0x20]
	cmp r0, #0x77
	ble _080116D0
	ldr r0, _0801171C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080116D8
_080116D0:
	ldr r1, [r4, #0x20]
	ldr r0, _08011720 @ =0x0000012B
	cmp r1, r0
	ble _0801170A
_080116D8:
	movs r0, #7
	bl FUN_0809c08c
	ldr r2, [r4, #0x1c]
	cmp r2, #0
	beq _08011704
	ldr r0, [r4, #0x24]
	str r0, [sp]
	ldr r1, _08011724 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
	movs r0, #0
	str r0, [r4, #0x1c]
_08011704:
	adds r0, r4, #0
	bl KillEntity
_0801170A:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	movs r0, #0
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801171C: .4byte 0x030044E0
_08011720: .4byte 0x0000012B
_08011724: .4byte 0xFFFF0000

	thumb_func_start EntityB0BC_Destroy
EntityB0BC_Destroy: @ 0x08011728
	push {lr}
	ldr r0, [r0, #0x18]
	bl FUN_0804a16c
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityB0BC_Init
EntityB0BC_Init: @ 0x08011738
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #3
	bl FUN_0809c08c
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r4, #0x1c]
	movs r0, #0
	str r0, [r4, #0x20]
	movs r5, #1
	rsbs r5, r5, #0
	str r5, [r4, #0x24]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08011794
	bl FUN_0823d340
	str r0, [r4, #0x28]
	cmp r0, #0
	beq _08011794
	movs r0, #1
	movs r1, #0xd
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	str r0, [r4, #0x18]
	cmp r0, #0
	blt _08011794
	ldr r1, [r4, #0x28]
	bl FUN_0804a240
	ldr r0, [r4, #0x18]
	movs r1, #0xb
	bl FUN_0804a2f8
	ldr r0, [r4, #0x18]
	bl FUN_0804a1f0
	movs r0, #0
	b _08011796
_08011794:
	adds r0, r5, #0
_08011796:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start EntityB0BC_Create
EntityB0BC_Create: @ 0x0801179C
	push {r4, lr}
	movs r0, #0xb
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080117D0
	ldr r1, _080117C8 @ =EntityB0BC_Update
	ldr r2, _080117CC @ =EntityB0BC_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB0BC_Init
	cmp r0, #0
	bge _080117D0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080117D2
	.align 2, 0
_080117C8: .4byte EntityB0BC_Update
_080117CC: .4byte EntityB0BC_Destroy
_080117D0:
	adds r0, r4, #0
_080117D2:
	pop {r4}
	pop {r1}
	bx r1
