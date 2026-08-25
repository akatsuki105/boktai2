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
	bl prepare_08231510
	cmp r0, #0
	beq _0801165A
	bl VM_GetPC
	adds r5, r0, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0801165A
	bl VM_GetPC
	adds r4, r0, #0
	cmp r4, #0
	beq _0801165A
	movs r0, #0x64
	bl prepare_08231510
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

	thumb_func_start FUN_08011664
FUN_08011664: @ 0x08011664
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

	thumb_func_start FUN_08011728
FUN_08011728: @ 0x08011728
	push {lr}
	ldr r0, [r0, #0x18]
	bl FUN_0804a16c
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08011738
FUN_08011738: @ 0x08011738
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #3
	bl FUN_0809c08c
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r4, #0x1c]
	movs r0, #0
	str r0, [r4, #0x20]
	movs r5, #1
	rsbs r5, r5, #0
	str r5, [r4, #0x24]
	movs r0, #0x73
	bl prepare_08231510
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

	thumb_func_start FUN_0801179c
FUN_0801179c: @ 0x0801179C
	push {r4, lr}
	movs r0, #0xb
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080117D0
	ldr r1, _080117C8 @ =FUN_08011664
	ldr r2, _080117CC @ =FUN_08011728
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08011738
	cmp r0, #0
	bge _080117D0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080117D2
	.align 2, 0
_080117C8: .4byte FUN_08011664
_080117CC: .4byte FUN_08011728
_080117D0:
	adds r0, r4, #0
_080117D2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080117d8
FUN_080117d8: @ 0x080117D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0
	movs r6, #0
	strb r1, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	strh r6, [r7, #4]
	strb r1, [r7, #6]
	adds r4, r7, #0
	adds r4, #0x6c
	ldr r1, _08011844 @ =0x0000DA6D
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	ldr r1, _08011848 @ =0x00000263
	bl FUN_0822b20c
	ldr r0, _0801184C @ =0x00000CA8
	adds r5, r5, r0
	str r5, [r4, #0xc]
	adds r5, r7, #0
	adds r5, #0x40
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #2
	strb r0, [r5, #7]
	adds r5, #0x1c
	str r6, [sp]
	mov r0, sp
	adds r1, r5, #0
	ldr r2, _08011850 @ =0x05000002
	bl CpuSet
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_080136b4
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011844: .4byte 0x0000DA6D
_08011848: .4byte 0x00000263
_0801184C: .4byte 0x00000CA8
_08011850: .4byte 0x05000002

	thumb_func_start FUN_08011854
FUN_08011854: @ 0x08011854
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x88
	bl FUN_080138fc
	adds r4, #0x40
	adds r0, r4, #0
	bl FUN_0822a4e0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08011870
FUN_08011870: @ 0x08011870
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #6
	ldrsb r0, [r5, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	add r4, sp, #4
	mov r3, sp
	adds r3, #5
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r3, #0
	cmp r0, #1
	bhi _080118A4
	movs r0, #1
	b _080118A6
_080118A4:
	movs r0, #0
_080118A6:
	strb r0, [r4]
	cmp r1, #1
	bls _080118B0
	movs r0, #1
	b _080118B2
_080118B0:
	movs r0, #0
_080118B2:
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x30
	ldr r1, [r6, #0x20]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r7]
	str r4, [sp]
	bl FUN_08236fac
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080118d4
FUN_080118d4: @ 0x080118D4
	push {r4, r5, r6, lr}
	mov ip, r0
	mov r6, ip
	adds r6, #0x40
	mov r2, ip
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [r2, #0x5c]
	str r1, [r2, #0x60]
	mov r4, ip
	adds r4, #0x30
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r2, #0x30]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08011918
	mov r1, ip
	ldr r0, [r1, #0x40]
	movs r1, #4
	orrs r0, r1
	b _08011922
_08011918:
	mov r1, ip
	ldr r0, [r1, #0x40]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08011922:
	mov r2, ip
	str r0, [r2, #0x40]
	ldrb r0, [r4, #4]
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
	beq _08011948
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08011950
_08011948:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08011950:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08011988 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080119CE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08011992
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0801198C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080119A8
	.align 2, 0
_08011988: .4byte 0x0000FFFF
_0801198C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080119A6
_08011992:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080119A6
	strh r1, [r4, #8]
	movs r2, #1
	b _080119A8
_080119A6:
	movs r2, #0
_080119A8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _080119D0
	movs r0, #1
	strb r0, [r4, #7]
	b _080119D0
_080119CE:
	movs r2, #0
_080119D0:
	mov r0, ip
	strb r2, [r0, #2]
	movs r2, #0x12
	ldrsh r1, [r0, r2]
	ldrh r0, [r0, #0xa]
	cmp r1, r0
	ble _080119E8
	mov r1, ip
	ldrh r0, [r1, #0x12]
	subs r0, #1
	strh r0, [r1, #0x12]
	b _080119F4
_080119E8:
	cmp r1, r0
	bge _080119F4
	mov r2, ip
	ldrh r0, [r2, #0x12]
	adds r0, #1
	strh r0, [r2, #0x12]
_080119F4:
	ldr r0, _08011A0C @ =0x085B0A08
	mov r2, ip
	ldrb r1, [r2, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08011A10
	asrs r1, r0, #0xc
	b _08011A16
	.align 2, 0
_08011A0C: .4byte 0x085B0A08
_08011A10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08011A16:
	ldrh r0, [r6, #0x1e]
	adds r0, r0, r1
	strh r0, [r6, #0x1e]
	mov r1, ip
	ldrb r0, [r1, #3]
	adds r0, #4
	strb r0, [r1, #3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08011a2c
FUN_08011a2c: @ 0x08011A2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov r8, r0
	ldr r3, _08011B28 @ =0xFFFF0000
	ldrh r1, [r2, #0xa]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #8]
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r1, [r2, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	str r0, [sp, #0x10]
	movs r5, #0x10
	ldrsh r3, [r2, r5]
	str r3, [sp, #0x14]
	movs r1, #0x12
	ldrsh r0, [r2, r1]
	str r0, [sp, #0x18]
	movs r5, #0x14
	ldrsh r3, [r2, r5]
	str r3, [sp, #0x1c]
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	str r0, [sp, #0x20]
	ldr r2, _08011B2C @ =0x00000CCC
	add r2, r8
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	mov r2, r8
	str r0, [r2, #0x1c]
	ldr r1, _08011B30 @ =0x00000CA4
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08011B34 @ =0x00000CA5
	add r1, r8
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, _08011B38 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _08011B3C @ =0x00004C60
	adds r1, r2, r3
	ldr r5, _08011B40 @ =0x00004CA0
	adds r2, r2, r5
	ldr r0, _08011B44 @ =0x00000CA8
	add r0, r8
	movs r3, #6
	str r3, [sp]
	movs r3, #0x3f
	bl rgb555_08237468
	mov r6, r8
	adds r6, #0x24
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _08011B48 @ =0x030046B8
	mov sl, r1
	add r7, sp, #4
	adds r4, r6, #0
	movs r2, #0xff
	mov sb, r2
_08011ABE:
	movs r0, #5
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r3, #0
	strh r3, [r4, #4]
	mov r5, sp
	ldrb r5, [r5, #0x1c]
	strb r5, [r4, #6]
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _08011AF6
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08011B4C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _08011B50 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x20]
	bl Mod
	ldrb r1, [r4, #6]
	adds r1, r1, r0
	strb r1, [r4, #6]
_08011AF6:
	mov r5, sp
	ldrh r5, [r5, #0x10]
	strh r5, [r4, #0xc]
	adds r3, r6, #0
	adds r3, #0x10
	movs r2, #6
	ldrsb r2, [r4, r2]
	ldr r0, _08011B54 @ =0x085B0A08
	adds r1, r2, #0
	adds r1, #0x40
	mov r5, sb
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r5, #0
	ldrsh r1, [r1, r5]
	ldr r5, [sp, #0x14]
	muls r1, r5, r1
	adds r5, r3, #0
	mov ip, r0
	cmp r1, #0
	blt _08011B58
	asrs r0, r1, #0xc
	b _08011B5E
	.align 2, 0
_08011B28: .4byte 0xFFFF0000
_08011B2C: .4byte 0x00000CCC
_08011B30: .4byte 0x00000CA4
_08011B34: .4byte 0x00000CA5
_08011B38: .4byte 0x03003584
_08011B3C: .4byte 0x00004C60
_08011B40: .4byte 0x00004CA0
_08011B44: .4byte 0x00000CA8
_08011B48: .4byte 0x030046B8
_08011B4C: .4byte 0x000003FF
_08011B50: .4byte 0x0203B400
_08011B54: .4byte 0x085B0A08
_08011B58:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011B5E:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	mov r1, sb
	ands r2, r1
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x14]
	muls r0, r1, r0
	cmp r0, #0
	blt _08011B7C
	asrs r0, r0, #0xc
	b _08011B82
_08011B7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011B82:
	strh r0, [r3, #4]
	ldrh r0, [r7]
	ldrh r2, [r4, #0x10]
	adds r0, r0, r2
	strh r0, [r4, #0x10]
	ldrh r0, [r7, #2]
	ldrh r3, [r5, #2]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	adds r2, r6, #0
	adds r2, #0x18
	movs r1, #6
	ldrsb r1, [r4, r1]
	adds r0, r1, #0
	adds r0, #0x40
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #1
	add r0, ip
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r3, [sp, #0x18]
	muls r0, r3, r0
	adds r3, r2, #0
	cmp r0, #0
	blt _08011BC2
	asrs r0, r0, #0xc
	b _08011BC8
_08011BC2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011BC8:
	strh r0, [r2]
	movs r5, #0
	strh r5, [r2, #2]
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, [sp, #0x18]
	muls r0, r5, r0
	cmp r0, #0
	blt _08011BE6
	asrs r0, r0, #0xc
	b _08011BEC
_08011BE6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011BEC:
	strh r0, [r2, #4]
	ldrh r0, [r7]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r7, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r7, #4]
	ldrh r5, [r3, #4]
	adds r0, r0, r5
	strh r0, [r3, #4]
	mov r0, sl
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08011C9C @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	ldr r3, _08011CA0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #3]
	ldr r5, [sp, #0xc]
	lsls r0, r5, #4
	ldrh r2, [r4, #0x12]
	adds r0, r0, r2
	strh r0, [r4, #0xa]
	adds r1, #1
	ldr r3, _08011C9C @ =0x000003FF
	ands r1, r3
	mov r5, sl
	str r1, [r5]
	lsls r1, r1, #1
	ldr r0, _08011CA0 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	strb r0, [r4, #8]
	ldr r0, [r4, #0x10]
	ldr r1, [r4, #0x14]
	str r0, [r4, #0x5c]
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x40]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08011870
	adds r0, r6, #0
	adds r0, #0x6c
	ldr r1, _08011CA4 @ =0x00000263
	bl FUN_0822b20c
	ldr r0, _08011CA8 @ =0x00000CA8
	add r0, r8
	str r0, [r4, #0x78]
	adds r0, r6, #0
	adds r0, #0x88
	bl FUN_08013698
	ldr r1, [sp, #0xc]
	adds r1, #1
	str r1, [sp, #0xc]
	adds r4, #0xc8
	adds r6, #0xc8
	cmp r1, #0xf
	bgt _08011C82
	b _08011ABE
_08011C82:
	movs r0, #1
	mov r2, r8
	str r0, [r2, #0x18]
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011C9C: .4byte 0x000003FF
_08011CA0: .4byte 0x0203B400
_08011CA4: .4byte 0x00000263
_08011CA8: .4byte 0x00000CA8

	thumb_func_start FUN_08011cac
FUN_08011cac: @ 0x08011CAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov r8, r0
	ldr r3, _08011DA8 @ =0xFFFF0000
	ldrh r1, [r2, #0xa]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #8]
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r1, [r2, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	str r0, [sp, #0x10]
	movs r5, #0x10
	ldrsh r3, [r2, r5]
	str r3, [sp, #0x14]
	movs r1, #0x12
	ldrsh r0, [r2, r1]
	str r0, [sp, #0x18]
	movs r5, #0x14
	ldrsh r3, [r2, r5]
	str r3, [sp, #0x1c]
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	str r0, [sp, #0x20]
	ldr r2, _08011DAC @ =0x00000CCC
	add r2, r8
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	mov r2, r8
	str r0, [r2, #0x1c]
	ldr r1, _08011DB0 @ =0x00000CA4
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08011DB4 @ =0x00000CA5
	add r1, r8
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, _08011DB8 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _08011DBC @ =0x00004C60
	adds r1, r2, r3
	ldr r5, _08011DC0 @ =0x00004CA0
	adds r2, r2, r5
	ldr r0, _08011DC4 @ =0x00000CA8
	add r0, r8
	movs r3, #6
	str r3, [sp]
	movs r3, #0x3f
	bl rgb555_08237468
	mov r6, r8
	adds r6, #0x24
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _08011DC8 @ =0x030046B8
	mov sl, r1
	add r7, sp, #4
	adds r4, r6, #0
	movs r2, #0xff
	mov sb, r2
_08011D3E:
	movs r3, #0
	strb r3, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r5, #0
	strh r5, [r4, #4]
	mov r0, sp
	ldrb r0, [r0, #0x1c]
	strb r0, [r4, #6]
	ldr r1, [sp, #0x20]
	cmp r1, #0
	beq _08011D76
	mov r2, sl
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _08011DCC @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _08011DD0 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	ldr r1, [sp, #0x20]
	bl Mod
	ldrb r1, [r4, #6]
	adds r1, r1, r0
	strb r1, [r4, #6]
_08011D76:
	mov r0, sp
	ldrh r0, [r0, #0x10]
	strh r0, [r4, #0xc]
	adds r3, r6, #0
	adds r3, #0x10
	movs r2, #6
	ldrsb r2, [r4, r2]
	ldr r0, _08011DD4 @ =0x085B0A08
	adds r1, r2, #0
	adds r1, #0x40
	mov r5, sb
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r5, #0
	ldrsh r1, [r1, r5]
	ldr r5, [sp, #0x14]
	muls r1, r5, r1
	adds r5, r3, #0
	mov ip, r0
	cmp r1, #0
	blt _08011DD8
	asrs r0, r1, #0xc
	b _08011DDE
	.align 2, 0
_08011DA8: .4byte 0xFFFF0000
_08011DAC: .4byte 0x00000CCC
_08011DB0: .4byte 0x00000CA4
_08011DB4: .4byte 0x00000CA5
_08011DB8: .4byte 0x03003584
_08011DBC: .4byte 0x00004C60
_08011DC0: .4byte 0x00004CA0
_08011DC4: .4byte 0x00000CA8
_08011DC8: .4byte 0x030046B8
_08011DCC: .4byte 0x000003FF
_08011DD0: .4byte 0x0203B400
_08011DD4: .4byte 0x085B0A08
_08011DD8:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011DDE:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	mov r1, sb
	ands r2, r1
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x14]
	muls r0, r1, r0
	cmp r0, #0
	blt _08011DFC
	asrs r0, r0, #0xc
	b _08011E02
_08011DFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011E02:
	strh r0, [r3, #4]
	ldrh r0, [r7]
	ldrh r2, [r4, #0x10]
	adds r0, r0, r2
	strh r0, [r4, #0x10]
	ldrh r0, [r7, #2]
	ldrh r3, [r5, #2]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	adds r2, r6, #0
	adds r2, #0x18
	movs r1, #6
	ldrsb r1, [r4, r1]
	adds r0, r1, #0
	adds r0, #0x40
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #1
	add r0, ip
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r3, [sp, #0x18]
	muls r0, r3, r0
	adds r3, r2, #0
	cmp r0, #0
	blt _08011E42
	asrs r0, r0, #0xc
	b _08011E48
_08011E42:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011E48:
	strh r0, [r2]
	movs r5, #0
	strh r5, [r2, #2]
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, [sp, #0x18]
	muls r0, r5, r0
	cmp r0, #0
	blt _08011E66
	asrs r0, r0, #0xc
	b _08011E6C
_08011E66:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08011E6C:
	strh r0, [r2, #4]
	ldrh r0, [r7]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r7, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r7, #4]
	ldrh r5, [r3, #4]
	adds r0, r0, r5
	strh r0, [r3, #4]
	mov r0, sl
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08011F1C @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	ldr r3, _08011F20 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #3]
	ldr r5, [sp, #0xc]
	lsls r0, r5, #4
	ldrh r2, [r4, #0x12]
	adds r0, r0, r2
	strh r0, [r4, #0xa]
	adds r1, #1
	ldr r3, _08011F1C @ =0x000003FF
	ands r1, r3
	mov r5, sl
	str r1, [r5]
	lsls r1, r1, #1
	ldr r0, _08011F20 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	strb r0, [r4, #8]
	ldr r0, [r4, #0x10]
	ldr r1, [r4, #0x14]
	str r0, [r4, #0x5c]
	str r1, [r4, #0x60]
	ldr r0, [r4, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x40]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08011870
	adds r0, r6, #0
	adds r0, #0x6c
	ldr r1, _08011F24 @ =0x00000263
	bl FUN_0822b20c
	ldr r0, _08011F28 @ =0x00000CA8
	add r0, r8
	str r0, [r4, #0x78]
	adds r0, r6, #0
	adds r0, #0x88
	bl FUN_08013698
	ldr r1, [sp, #0xc]
	adds r1, #1
	str r1, [sp, #0xc]
	adds r4, #0xc8
	adds r6, #0xc8
	cmp r1, #0xf
	bgt _08011F02
	b _08011D3E
_08011F02:
	movs r0, #1
	mov r2, r8
	str r0, [r2, #0x18]
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011F1C: .4byte 0x000003FF
_08011F20: .4byte 0x0203B400
_08011F24: .4byte 0x00000263
_08011F28: .4byte 0x00000CA8

	thumb_func_start FUN_08011f2c
FUN_08011f2c: @ 0x08011F2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r2, #0
	ldrh r1, [r4, #8]
	ldr r2, _08011F54 @ =0x00000CA6
	adds r0, r5, r2
	strh r1, [r0]
	ldrh r0, [r0]
	bl FUN_0823b2d0
	cmp r0, #0
	bne _08011F58
	movs r0, #1
	rsbs r0, r0, #0
	b _08011FEE
	.align 2, 0
_08011F54: .4byte 0x00000CA6
_08011F58:
	ldr r1, [r0, #8]
	ldr r2, [r0, #0xc]
	str r1, [sp, #4]
	str r2, [sp, #8]
	movs r3, #0xa
	ldrsh r2, [r4, r3]
	str r2, [sp]
	movs r0, #0
	str r0, [r5, #0x1c]
	ldr r0, _08012000 @ =0x0203B400
	mov sl, r0
	ldr r1, _08012004 @ =0x030046B8
	mov sb, r1
	ldr r2, _08012008 @ =0x000003FF
	mov r8, r2
	movs r6, #0xf
	adds r4, r5, #0
	adds r4, #0x24
_08011F7C:
	movs r0, #3
	strb r0, [r4, #1]
	movs r7, #1
	strb r7, [r4]
	movs r3, #0
	strh r3, [r4, #4]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x1c
	ldrsh r1, [r4, r3]
	movs r3, #0x14
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #6]
	mov r1, sb
	ldr r2, [r1]
	adds r2, #1
	mov r3, r8
	ands r2, r3
	lsls r1, r2, #1
	add r1, sl
	ldrh r3, [r1]
	subs r0, #0x10
	movs r1, #0x1f
	ands r3, r1
	adds r0, r0, r3
	strb r0, [r4, #6]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4, #0xc]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	mov r3, sb
	str r2, [r3]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	strb r0, [r4, #8]
	subs r6, #1
	adds r4, #0xc8
	cmp r6, #0
	bge _08011F7C
	str r7, [r5, #0x18]
	movs r0, #0
_08011FEE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08012000: .4byte 0x0203B400
_08012004: .4byte 0x030046B8
_08012008: .4byte 0x000003FF

	thumb_func_start FUN_0801200c
FUN_0801200c: @ 0x0801200C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08012024 @ =0x00000CD4
	adds r6, r5, r0
	movs r7, #0
	ldr r0, _08012028 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	ldr r2, _0801202C @ =0x00000CDA
	adds r0, r5, r2
	b _080120BA
	.align 2, 0
_08012024: .4byte 0x00000CD4
_08012028: .4byte 0x03002B4C
_0801202C: .4byte 0x00000CDA
_08012030:
	ldr r0, _08012060 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #1
	beq _08012080
	cmp r0, #1
	bgt _08012064
	cmp r0, #0
	beq _0801206A
	b _080120B0
	.align 2, 0
_08012060: .4byte 0x03002B4C
_08012064:
	cmp r0, #2
	beq _0801209C
	b _080120B0
_0801206A:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08011a2c
	ldr r1, _0801207C @ =0x00000CD4
	adds r0, r5, r1
	b _0801208E
	.align 2, 0
_0801207C: .4byte 0x00000CD4
_08012080:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08011cac
	ldr r2, _08012098 @ =0x00000CD4
	adds r0, r5, r2
_0801208E:
	movs r1, #1
	bl FUN_08022488
	b _080120B0
	.align 2, 0
_08012098: .4byte 0x00000CD4
_0801209C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08011f2c
	ldr r1, _080120CC @ =0x00000CD4
	adds r0, r5, r1
	movs r1, #1
	bl FUN_08022488
_080120B0:
	adds r7, #1
	ldr r0, _080120D0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
_080120BA:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08012030
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080120CC: .4byte 0x00000CD4
_080120D0: .4byte 0x03002B4C

	thumb_func_start FUN_080120d4
FUN_080120d4: @ 0x080120D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _080120EC
	movs r0, #0
	strb r0, [r4]
_080120EC:
	ldrh r0, [r4, #0xc]
	mov r5, sp
	movs r3, #6
	ldrsb r3, [r4, r3]
	lsls r6, r0, #1
	ldr r2, _08012114 @ =0x085B0A08
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
	blt _08012118
	asrs r1, r0, #0xc
	b _0801211E
	.align 2, 0
_08012114: .4byte 0x085B0A08
_08012118:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801211E:
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
	blt _0801213A
	asrs r0, r0, #0xc
	b _08012140
_0801213A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08012140:
	strh r0, [r5, #4]
	adds r1, r4, #0
	adds r1, #0x10
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x10]
	adds r0, r0, r3
	strh r0, [r4, #0x10]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08011870
	ldrh r1, [r4, #4]
	mov r0, r8
	adds r0, #2
	cmp r1, r0
	blt _08012180
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	movs r0, #0
	strh r0, [r4, #4]
_08012180:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08012194
FUN_08012194: @ 0x08012194
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08012236
	movs r0, #0
	strb r0, [r4]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x1c
	ldrsh r1, [r4, r3]
	movs r5, #0x14
	ldrsh r2, [r4, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #6]
	strb r0, [r4, #7]
	ldr r3, _080121F4 @ =0x030046B8
	ldr r0, [r3]
	adds r1, r0, #1
	ldr r2, _080121F8 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r0, r1, #1
	ldr r5, _080121FC @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08012200
	adds r0, r1, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrb r0, [r4, #7]
	adds r0, #0x40
	movs r1, #0x3f
	ands r2, r1
	subs r0, r0, r2
	b _08012218
	.align 2, 0
_080121F4: .4byte 0x030046B8
_080121F8: .4byte 0x000003FF
_080121FC: .4byte 0x0203B400
_08012200:
	adds r0, r1, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08012260 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	ldrb r0, [r4, #7]
	adds r0, #0x40
	movs r1, #0x3f
	ands r2, r1
	adds r0, r0, r2
_08012218:
	strb r0, [r4, #7]
	ldr r2, _08012264 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08012268 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08012260 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #4
	strb r0, [r4, #8]
_08012236:
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080122DE
	mov r5, sp
	movs r3, #7
	ldrsb r3, [r4, r3]
	ldrh r6, [r4, #0xc]
	ldr r2, _0801226C @ =0x085B0A08
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
	blt _08012270
	asrs r1, r0, #0xc
	b _08012276
	.align 2, 0
_08012260: .4byte 0x0203B400
_08012264: .4byte 0x030046B8
_08012268: .4byte 0x000003FF
_0801226C: .4byte 0x085B0A08
_08012270:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08012276:
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
	blt _08012292
	asrs r0, r0, #0xc
	b _08012298
_08012292:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08012298:
	strh r0, [r5, #4]
	adds r3, r4, #0
	adds r3, #0x10
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r4, #0x10]
	adds r0, r0, r5
	strh r0, [r4, #0x10]
	ldrh r0, [r1, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r5, [r3, #4]
	adds r0, r0, r5
	strh r0, [r3, #4]
	ldr r0, _08012308 @ =0x00000CCC
	adds r2, r7, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0x10
	ldrsh r1, [r4, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #6]
	ldrb r0, [r4, #8]
	subs r0, #1
	strb r0, [r4, #8]
_080122DE:
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08011870
	ldrh r0, [r4, #4]
	cmp r0, #0x5f
	bls _080122F8
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r1, [r4, #4]
_080122F8:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012308: .4byte 0x00000CCC

	thumb_func_start FUN_0801230c
FUN_0801230c: @ 0x0801230C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r6, r1, #0
	ldrb r0, [r6]
	cmp r0, #0
	beq _08012394
	movs r0, #0
	strb r0, [r6]
	adds r4, r6, #0
	adds r4, #0x10
	ldr r2, _080123CC @ =0x00000CCC
	add r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x10
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #6]
	movs r1, #0x18
	ldrsh r0, [r6, r1]
	movs r2, #0x10
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x1c
	ldrsh r1, [r6, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #7]
	ldr r5, _080123D0 @ =0x0203B400
	ldr r3, _080123D4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _080123D8 @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrb r0, [r6, #7]
	subs r0, #0x10
	movs r1, #0x1f
	ands r2, r1
	adds r0, r0, r2
	strb r0, [r6, #7]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r6, #8]
_08012394:
	adds r2, r6, #0
	adds r2, #0x10
	movs r0, #0x18
	ldrsh r1, [r6, r0]
	movs r3, #0x10
	ldrsh r0, [r6, r3]
	subs r4, r1, r0
	movs r0, #0x1c
	ldrsh r1, [r6, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _080123DC @ =0x00009C3F
	adds r7, r2, #0
	cmp r1, r0
	bgt _080123E0
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r1, [r6, #4]
	b _080124D0
	.align 2, 0
_080123CC: .4byte 0x00000CCC
_080123D0: .4byte 0x0203B400
_080123D4: .4byte 0x030046B8
_080123D8: .4byte 0x000003FF
_080123DC: .4byte 0x00009C3F
_080123E0:
	ldrb r0, [r6, #8]
	cmp r0, #0
	bne _08012430
	adds r0, r4, #0
	adds r1, r3, #0
	bl FUN_0823785c
	strb r0, [r6, #7]
	ldr r5, _08012424 @ =0x0203B400
	ldr r2, _08012428 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _0801242C @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r6, #7]
	subs r0, #0x10
	movs r3, #0x1f
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r6, #7]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x20
	b _08012432
	.align 2, 0
_08012424: .4byte 0x0203B400
_08012428: .4byte 0x030046B8
_0801242C: .4byte 0x000003FF
_08012430:
	subs r0, #1
_08012432:
	strb r0, [r6, #8]
	mov r4, sp
	movs r3, #7
	ldrsb r3, [r6, r3]
	ldrh r5, [r6, #0xc]
	ldr r2, _08012458 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0801245C
	asrs r1, r0, #0xc
	b _08012462
	.align 2, 0
_08012458: .4byte 0x085B0A08
_0801245C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08012462:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0801247E
	asrs r0, r0, #0xc
	b _08012484
_0801247E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08012484:
	strh r0, [r4, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r7, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
	ldr r2, _080124DC @ =0x00000CCC
	add r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x10
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #6]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08011870
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
_080124D0:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080124DC: .4byte 0x00000CCC

	thumb_func_start FUN_080124e0
FUN_080124e0: @ 0x080124E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r0
	adds r6, r1, #0
	ldr r0, _080125BC @ =0x00000CC8
	add r0, sb
	ldr r0, [r0]
	cmp r0, #0
	beq _08012500
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
_08012500:
	ldrb r0, [r6]
	adds r7, r6, #0
	adds r7, #0x10
	movs r1, #0x18
	adds r1, r1, r6
	mov r8, r1
	cmp r0, #0
	beq _08012566
	movs r0, #0
	strb r0, [r6]
	movs r2, #0x18
	ldrsh r0, [r6, r2]
	movs r3, #0x10
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	mov r2, r8
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #6]
	ldr r5, _080125C0 @ =0x0203B400
	ldr r3, _080125C4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _080125C8 @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrb r0, [r6, #6]
	subs r0, #0x10
	movs r1, #0x1f
	ands r2, r1
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r6, #8]
_08012566:
	ldrb r0, [r6, #8]
	cmp r0, #0
	bne _080125CC
	movs r1, #0x18
	ldrsh r0, [r6, r1]
	movs r2, #0x10
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	mov r3, r8
	movs r2, #4
	ldrsh r1, [r3, r2]
	movs r3, #4
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #6]
	ldr r5, _080125C0 @ =0x0203B400
	ldr r2, _080125C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _080125C8 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r6, #6]
	subs r0, #8
	movs r3, #0xf
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r6, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x10
	b _080125CE
	.align 2, 0
_080125BC: .4byte 0x00000CC8
_080125C0: .4byte 0x0203B400
_080125C4: .4byte 0x030046B8
_080125C8: .4byte 0x000003FF
_080125CC:
	subs r0, #1
_080125CE:
	strb r0, [r6, #8]
	movs r0, #0x18
	ldrsh r2, [r6, r0]
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	subs r2, r2, r0
	mov r3, r8
	movs r1, #4
	ldrsh r0, [r3, r1]
	movs r3, #4
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08012608 @ =0x00000FFF
	cmp r1, r0
	bgt _0801260C
	movs r0, #4
	movs r1, #0
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r1, [r6, #4]
	b _0801268A
	.align 2, 0
_08012608: .4byte 0x00000FFF
_0801260C:
	mov r4, sp
	movs r3, #6
	ldrsb r3, [r6, r3]
	ldrh r5, [r6, #0xc]
	ldr r2, _08012630 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08012634
	asrs r1, r0, #0xc
	b _0801263A
	.align 2, 0
_08012630: .4byte 0x085B0A08
_08012634:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801263A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08012656
	asrs r0, r0, #0xc
	b _0801265C
_08012656:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801265C:
	strh r0, [r4, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r7, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08011870
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
_0801268A:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08012698
FUN_08012698: @ 0x08012698
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r6, r1, #0
	adds r4, r2, #0
	ldr r0, _08012754 @ =0x00000CC8
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	beq _080126B8
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
_080126B8:
	ldrb r0, [r6]
	adds r7, r6, #0
	adds r7, #0x28
	cmp r0, #0
	beq _080126F0
	movs r3, #0
	strb r3, [r6]
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	str r0, [r6, #0x20]
	str r1, [r6, #0x24]
	ldr r2, _08012758 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801275C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08012760 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r6, #6]
	str r3, [sp, #4]
	add r0, sp, #4
	adds r1, r7, #0
	ldr r2, _08012764 @ =0x05000002
	bl CpuSet
_080126F0:
	adds r1, r6, #0
	adds r1, #0x20
	adds r2, r6, #0
	adds r2, #0x18
	adds r3, r4, #0
	adds r3, #8
	movs r0, #5
	str r0, [sp]
	adds r0, r1, #0
	bl FUN_08237970
	ldrb r0, [r6, #8]
	cmp r0, #0
	bne _08012768
	movs r2, #0x28
	ldrsh r0, [r6, r2]
	rsbs r0, r0, #0
	movs r2, #0x2c
	ldrsh r1, [r6, r2]
	rsbs r1, r1, #0
	bl FUN_0823785c
	strb r0, [r6, #6]
	ldr r5, _08012760 @ =0x0203B400
	ldr r3, _08012758 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _0801275C @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrb r0, [r6, #6]
	subs r0, #7
	movs r1, #0xf
	ands r2, r1
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	b _0801276A
	.align 2, 0
_08012754: .4byte 0x00000CC8
_08012758: .4byte 0x030046B8
_0801275C: .4byte 0x000003FF
_08012760: .4byte 0x0203B400
_08012764: .4byte 0x05000002
_08012768:
	subs r0, #1
_0801276A:
	strb r0, [r6, #8]
	add r4, sp, #8
	movs r3, #6
	ldrsb r3, [r6, r3]
	ldrh r5, [r6, #0xc]
	ldr r2, _08012794 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov ip, r4
	cmp r0, #0
	blt _08012798
	asrs r1, r0, #0xc
	b _0801279E
	.align 2, 0
_08012794: .4byte 0x085B0A08
_08012798:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801279E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080127BA
	asrs r0, r0, #0xc
	b _080127C0
_080127BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080127C0:
	strh r0, [r4, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r1, [r6, #0x28]
	adds r0, r0, r1
	strh r0, [r6, #0x28]
	mov r2, ip
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	strh r0, [r7, #4]
	ldrh r0, [r6, #0x28]
	ldrh r1, [r6, #0x20]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x2c]
	ldrh r2, [r6, #0x24]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08011870
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801280c
FUN_0801280c: @ 0x0801280C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _08012824
	movs r0, #0
	strb r0, [r4]
_08012824:
	ldrh r0, [r4, #0xc]
	mov r5, sp
	movs r3, #6
	ldrsb r3, [r4, r3]
	lsls r6, r0, #1
	ldr r2, _0801284C @ =0x085B0A08
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
	blt _08012850
	asrs r1, r0, #0xc
	b _08012856
	.align 2, 0
_0801284C: .4byte 0x085B0A08
_08012850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08012856:
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
	blt _08012872
	asrs r0, r0, #0xc
	b _08012878
_08012872:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08012878:
	strh r0, [r5, #4]
	adds r1, r4, #0
	adds r1, #0x10
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x10]
	adds r0, r0, r3
	strh r0, [r4, #0x10]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08011870
	ldrh r1, [r4, #4]
	mov r0, r8
	adds r0, #2
	cmp r1, r0
	blt _080128BA
	movs r0, #6
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	strh r0, [r4, #4]
_080128BA:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080128cc
FUN_080128cc: @ 0x080128CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r6, r1, #0
	ldrb r0, [r6]
	cmp r0, #0
	beq _08012932
	movs r0, #0
	strb r0, [r6]
	movs r1, #0x18
	ldrsh r0, [r6, r1]
	movs r2, #0x10
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x1c
	ldrsh r1, [r6, r3]
	movs r3, #0x14
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #6]
	ldr r5, _0801296C @ =0x0203B400
	ldr r3, _08012970 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _08012974 @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrb r0, [r6, #6]
	subs r0, #0x10
	movs r1, #0x1f
	ands r2, r1
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r6, #8]
_08012932:
	adds r2, r6, #0
	adds r2, #0x10
	movs r0, #0x18
	ldrsh r1, [r6, r0]
	movs r3, #0x10
	ldrsh r0, [r6, r3]
	subs r4, r1, r0
	movs r0, #0x1c
	ldrsh r1, [r6, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08012978 @ =0x00009C3F
	adds r7, r2, #0
	cmp r1, r0
	bgt _0801297C
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r1, [r6, #4]
	b _08012A4E
	.align 2, 0
_0801296C: .4byte 0x0203B400
_08012970: .4byte 0x030046B8
_08012974: .4byte 0x000003FF
_08012978: .4byte 0x00009C3F
_0801297C:
	ldrb r0, [r6, #8]
	cmp r0, #0
	bne _080129CC
	adds r0, r4, #0
	adds r1, r3, #0
	bl FUN_0823785c
	strb r0, [r6, #6]
	ldr r5, _080129C0 @ =0x0203B400
	ldr r2, _080129C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _080129C8 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r6, #6]
	subs r0, #0x10
	movs r3, #0x1f
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r6, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x20
	b _080129CE
	.align 2, 0
_080129C0: .4byte 0x0203B400
_080129C4: .4byte 0x030046B8
_080129C8: .4byte 0x000003FF
_080129CC:
	subs r0, #1
_080129CE:
	strb r0, [r6, #8]
	mov r4, sp
	movs r3, #6
	ldrsb r3, [r6, r3]
	ldrh r5, [r6, #0xc]
	ldr r2, _080129F4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080129F8
	asrs r1, r0, #0xc
	b _080129FE
	.align 2, 0
_080129F4: .4byte 0x085B0A08
_080129F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080129FE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08012A1A
	asrs r0, r0, #0xc
	b _08012A20
_08012A1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08012A20:
	strh r0, [r4, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r7, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08011870
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
_08012A4E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityE534_Update
EntityE534_Update: @ 0x08012A5C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_0801200c
	ldr r0, [r6, #0x18]
	cmp r0, #0
	beq _08012B4C
	ldr r0, _08012AA4 @ =0x00000CA6
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08012A80
	bl FUN_0823b2d0
	ldr r2, _08012AA8 @ =0x00000CC8
	adds r1, r6, r2
	str r0, [r1]
_08012A80:
	ldr r3, _08012AAC @ =0x00000CA4
	adds r2, r6, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _08012AB4
	ldr r4, _08012AB0 @ =0x00000CA5
	adds r1, r6, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3e
	ble _08012AEE
	movs r0, #0x3f
	b _08012AE8
	.align 2, 0
_08012AA4: .4byte 0x00000CA6
_08012AA8: .4byte 0x00000CC8
_08012AAC: .4byte 0x00000CA4
_08012AB0: .4byte 0x00000CA5
_08012AB4:
	cmp r0, #1
	bne _08012AD0
	ldr r0, _08012ACC @ =0x00000CA5
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _08012AEE
	movs r0, #0
	b _08012AE8
	.align 2, 0
_08012ACC: .4byte 0x00000CA5
_08012AD0:
	cmp r0, #2
	bne _08012AEE
	ldr r3, _08012B58 @ =0x00000CA5
	adds r1, r6, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	ble _08012AEE
	movs r0, #0x20
_08012AE8:
	strb r0, [r1]
	movs r0, #0xff
	strb r0, [r2]
_08012AEE:
	ldr r4, _08012B5C @ =0x00000CA4
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08012B1E
	ldr r0, _08012B60 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _08012B64 @ =0x00004C60
	adds r1, r2, r0
	ldr r3, _08012B68 @ =0x00004CA0
	adds r2, r2, r3
	adds r4, #4
	adds r0, r6, r4
	subs r4, #3
	adds r3, r6, r4
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #6
	str r4, [sp]
	bl rgb555_08237468
_08012B1E:
	adds r4, r6, #0
	adds r4, #0x24
	movs r5, #0
	ldr r7, _08012B6C @ =0x085AA81C
_08012B26:
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	adds r0, r4, #0
	bl FUN_080118d4
	adds r5, #1
	adds r4, #0xc8
	cmp r5, #0xf
	ble _08012B26
	ldr r0, [r6, #0x1c]
	adds r0, #1
	str r0, [r6, #0x1c]
_08012B4C:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08012B58: .4byte 0x00000CA5
_08012B5C: .4byte 0x00000CA4
_08012B60: .4byte 0x03003584
_08012B64: .4byte 0x00004C60
_08012B68: .4byte 0x00004CA0
_08012B6C: .4byte 0x085AA81C

	thumb_func_start EntityE534_Destroy
EntityE534_Destroy: @ 0x08012B70
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_08012B7A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08011854
	adds r4, #1
	adds r5, #0xc8
	cmp r4, #0xf
	ble _08012B7A
	ldr r1, _08012B9C @ =0x00000CD4
	adds r0, r6, r1
	bl FUN_08022428
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08012B9C: .4byte 0x00000CD4

	thumb_func_start EntityE534_Init
EntityE534_Init: @ 0x08012BA0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	movs r1, #0
	str r1, [r6, #0x18]
	ldr r2, _08012C0C @ =0x00000CA6
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, _08012C10 @ =0x00000CC8
	adds r0, r6, r3
	str r1, [r0]
	ldr r0, _08012C14 @ =0x0000922E
	ldr r1, _08012C18 @ =0x00005BB7
	bl GetFile
	str r0, [r6, #0x20]
	ldr r0, _08012C1C @ =0x03003584
	ldr r2, [r0]
	ldr r0, _08012C20 @ =0x00004C60
	adds r1, r2, r0
	ldr r3, _08012C24 @ =0x00004CA0
	adds r2, r2, r3
	ldr r3, _08012C28 @ =0x00000CA8
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x40
	bl rgb555_08237468
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_08012BE2:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080117d8
	adds r4, #1
	adds r5, #0xc8
	cmp r4, #0xf
	ble _08012BE2
	ldr r1, _08012C2C @ =0x00000CD4
	adds r0, r6, r1
	adds r1, r7, #0
	movs r2, #0xa
	bl FUN_080223f4
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08012C0C: .4byte 0x00000CA6
_08012C10: .4byte 0x00000CC8
_08012C14: .4byte 0x0000922E
_08012C18: .4byte 0x00005BB7
_08012C1C: .4byte 0x03003584
_08012C20: .4byte 0x00004C60
_08012C24: .4byte 0x00004CA0
_08012C28: .4byte 0x00000CA8
_08012C2C: .4byte 0x00000CD4

	thumb_func_start EntityE534_Create
EntityE534_Create: @ 0x08012C30
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08012C60 @ =0x00000D08
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08012C6C
	ldr r1, _08012C64 @ =EntityE534_Update
	ldr r2, _08012C68 @ =EntityE534_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityE534_Init
	cmp r0, #0
	bge _08012C6C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08012C6E
	.align 2, 0
_08012C60: .4byte 0x00000D08
_08012C64: .4byte EntityE534_Update
_08012C68: .4byte EntityE534_Destroy
_08012C6C:
	adds r0, r4, #0
_08012C6E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08012c74
FUN_08012c74: @ 0x08012C74
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _08012CD4 @ =0x0000C091
	ldr r1, _08012CD8 @ =0x000033B2
	bl GetFile
	adds r2, r0, #0
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _08012CDC @ =0x000092B3
	ldr r1, _08012CE0 @ =0x0000E9C3
	bl GetFile
	ldr r1, _08012CE4 @ =0x0000045C
	adds r5, r5, r1
	adds r0, #0x14
	str r0, [r5]
	ldr r1, _08012CE8 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08012CD4: .4byte 0x0000C091
_08012CD8: .4byte 0x000033B2
_08012CDC: .4byte 0x000092B3
_08012CE0: .4byte 0x0000E9C3
_08012CE4: .4byte 0x0000045C
_08012CE8: .4byte 0x03004250

	thumb_func_start FUN_08012cec
FUN_08012cec: @ 0x08012CEC
	adds r2, r0, #0
	ldr r1, [r2, #0x24]
	ldr r0, _08012CFC @ =0x6262C05D
	muls r0, r1, r0
	adds r0, #1
	str r0, [r2, #0x24]
	bx lr
	.align 2, 0
_08012CFC: .4byte 0x6262C05D

	thumb_func_start FUN_08012d00
FUN_08012d00: @ 0x08012D00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov sb, r1
	adds r6, r2, #0
	mov r8, r3
	movs r1, #1
	lsls r1, r3
	subs r1, #1
	cmp sb, r1
	bls _08012D1E
	mov sb, r1
_08012D1E:
	movs r7, #0
	cmp r7, r8
	bge _08012D5A
_08012D24:
	ldr r0, [r6]
	movs r1, #6
	bl Div
	adds r5, r0, #0
	ldr r0, [r6]
	movs r1, #6
	bl Mod
	adds r4, r0, #0
	mov r1, sb
	lsrs r1, r7
	movs r2, #1
	ands r1, r2
	mov r3, sl
	adds r3, #0x2a
	adds r3, r3, r5
	lsls r1, r4
	ldrb r2, [r3]
	orrs r1, r2
	strb r1, [r3]
	ldr r1, [r6]
	adds r1, #1
	str r1, [r6]
	adds r7, #1
	cmp r7, r8
	blt _08012D24
_08012D5A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08012d68
FUN_08012d68: @ 0x08012D68
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08012DBC @ =0x0000FFFF
	movs r5, #0
	adds r1, r7, #0
	adds r1, #0x20
	ldrb r0, [r1]
	adds r0, #4
	cmp r5, r0
	bge _08012D90
	adds r4, r1, #0
_08012D7E:
	adds r0, r7, #0
	bl FUN_08012cec
	eors r6, r0
	adds r5, #1
	ldrb r0, [r4]
	adds r0, #4
	cmp r5, r0
	blt _08012D7E
_08012D90:
	adds r4, r7, #0
	adds r4, #0x2e
	movs r5, #0x13
_08012D96:
	ldrb r1, [r4]
	adds r0, r6, #0
	eors r0, r1
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r4]
	adds r0, r7, #0
	bl FUN_08012cec
	eors r6, r0
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	bge _08012D96
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08012DBC: .4byte 0x0000FFFF

	thumb_func_start PasswordScreen_EncodeBits
PasswordScreen_EncodeBits: @ 0x08012DC0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	strh r0, [r6, #0x1e]
	movs r0, #1
	strh r0, [r6, #0x1c]
	ldr r2, _08012FA8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08012FAC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08012FB0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r4, r6, #0
	adds r4, #0x20
	strb r0, [r4]
	movs r0, #0x10
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0
	mov r2, sp
	movs r3, #2
	bl FUN_08012d00
	ldrh r1, [r6, #0x1c]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #3
	bl FUN_08012d00
	ldrb r1, [r4]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #3
	bl FUN_08012d00
	ldr r0, _08012FB4 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #6
	bl FUN_08012d00
	ldr r4, _08012FB8 @ =0x030046A0
	ldr r0, [r4]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #3
	bl FUN_08012d00
	ldr r0, [r4]
	ldr r1, _08012FBC @ =0x000002FA
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #4
	bl FUN_08012d00
	ldr r0, [r4]
	movs r1, #0xf8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	adds r0, r6, #0
	mov r2, sp
	movs r3, #8
	bl FUN_08012d00
	ldr r0, [r4]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #7
	bl FUN_08012d00
	ldr r0, [r4]
	ldr r1, _08012FC0 @ =0x00000914
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #6
	bl FUN_08012d00
	ldr r0, [r4]
	ldr r2, _08012FC4 @ =0x00000918
	adds r1, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	ldr r2, _08012FC8 @ =0x0000091A
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	adds r0, r6, #0
	mov r2, sp
	movs r3, #6
	bl FUN_08012d00
	ldr r0, [r4]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	asrs r1, r1, #0xc
	adds r0, r6, #0
	mov r2, sp
	movs r3, #0xa
	bl FUN_08012d00
	ldr r0, [r4]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, [r0]
	asrs r1, r1, #8
	adds r0, r6, #0
	mov r2, sp
	movs r3, #8
	bl FUN_08012d00
	ldr r0, [r4]
	movs r1, #0xad
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08012FCC @ =0x00034BC0
	bl Div
	adds r1, r0, #0
	adds r0, r6, #0
	mov r2, sp
	movs r3, #6
	bl FUN_08012d00
	ldr r0, [r4]
	movs r2, #0xf7
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #0x10
	bl FUN_08012d00
	ldr r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r4, r1, r0
	movs r5, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08012F4E
	ldr r2, _08012FD0 @ =0x000003C1
	adds r4, r1, r2
	ldrb r0, [r4]
	adds r7, r6, #0
	adds r7, #0x2a
	cmp r0, #0
	beq _08012F4E
_08012F2C:
	ldrb r1, [r4]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #8
	bl FUN_08012d00
	adds r4, #1
	adds r5, #1
	cmp r5, #4
	bgt _08012F68
	ldrb r0, [r4]
	cmp r0, #0
	beq _08012F4E
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0
	bne _08012F2C
_08012F4E:
	adds r7, r6, #0
	adds r7, #0x2a
	cmp r5, #4
	bgt _08012F68
_08012F56:
	adds r0, r6, #0
	movs r1, #0
	mov r2, sp
	movs r3, #8
	bl FUN_08012d00
	adds r5, #1
	cmp r5, #4
	ble _08012F56
_08012F68:
	ldr r0, [sp]
	movs r3, #0x90
	subs r3, r3, r0
	adds r0, r6, #0
	movs r1, #0
	mov r2, sp
	bl FUN_08012d00
	adds r0, r6, #0
	bl FUN_08012d68
	ldr r2, _08012FD4 @ =0x0000FFFF
	movs r5, #3
	mov ip, r7
	movs r7, #0x80
	lsls r7, r7, #8
	ldr r4, _08012FD8 @ =0x00001021
_08012F8A:
	mov r1, ip
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, r0, #8
	eors r2, r0
	movs r1, #0
	adds r3, r5, #1
_08012F98:
	adds r0, r2, #0
	ands r0, r7
	cmp r0, #0
	beq _08012FDC
	lsls r2, r2, #1
	eors r2, r4
	b _08012FDE
	.align 2, 0
_08012FA8: .4byte 0x030046B8
_08012FAC: .4byte 0x000003FF
_08012FB0: .4byte 0x0203B400
_08012FB4: .4byte gSystemSaveData
_08012FB8: .4byte 0x030046A0
_08012FBC: .4byte 0x000002FA
_08012FC0: .4byte 0x00000914
_08012FC4: .4byte 0x00000918
_08012FC8: .4byte 0x0000091A
_08012FCC: .4byte 0x00034BC0
_08012FD0: .4byte 0x000003C1
_08012FD4: .4byte 0x0000FFFF
_08012FD8: .4byte 0x00001021
_08012FDC:
	lsls r2, r2, #1
_08012FDE:
	adds r1, #1
	cmp r1, #7
	bls _08012F98
	adds r5, r3, #0
	cmp r5, #0x17
	ble _08012F8A
	ldr r1, _08013004 @ =0x0000FFFF
	bics r1, r2
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	mov r2, sp
	movs r3, #0x10
	bl FUN_08012d00
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08013004: .4byte 0x0000FFFF

	thumb_func_start PasswordScreen_Update
PasswordScreen_Update: @ 0x08013008
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x18]
	cmp r1, #0x28
	bhi _08013022
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08013022
	movs r0, #0x9d
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08013022:
	ldr r0, [r4, #0x18]
	cmp r0, #0x3b
	bls _0801304A
	ldr r0, _08013058 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801304A
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldrh r0, [r4, #0x28]
	cmp r0, #0
	beq _0801304A
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	strh r0, [r4, #0x28]
_0801304A:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08013058: .4byte 0x030044E0

	thumb_func_start PasswordScreen_Destroy
PasswordScreen_Destroy: @ 0x0801305C
	push {r4, r5, lr}
	ldr r1, _08013078 @ =0x0000044C
	adds r5, r0, r1
	movs r4, #2
_08013064:
	ldm r5!, {r0}
	bl FUN_0804a16c
	subs r4, #1
	cmp r4, #0
	bge _08013064
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08013078: .4byte 0x0000044C

	thumb_func_start PasswordScreen_Init
PasswordScreen_Init: @ 0x0801307C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0
	str r0, [r7, #0x18]
	ldr r0, _08013210 @ =0x000B8E6E
	str r0, [r7, #0x24]
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	bne _08013098
	b _08013238
_08013098:
	bl VM_GetPC
	bl VM_ParseStringRef
	bl Textbox_LookupString
	ldr r1, _08013214 @ =0x00000444
	adds r4, r7, r1
	str r0, [r4]
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	bne _080130B6
	b _08013238
_080130B6:
	bl VM_GetPC
	movs r2, #0x89
	lsls r2, r2, #3
	adds r1, r7, r2
	str r0, [r1]
	cmp r0, #0
	bne _080130C8
	b _08013238
_080130C8:
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r7, #0x28]
	adds r0, r7, #0
	bl PasswordScreen_EncodeBits
	adds r5, r7, #0
	adds r5, #0x2a
	movs r1, #0
	mov ip, r4
_080130E0:
	lsls r0, r1, #8
	adds r0, #0x42
	adds r2, r7, r0
	movs r4, #0
	adds r1, #1
	mov r8, r1
_080130EC:
	ldrb r0, [r5]
	lsls r1, r0, #1
	adds r5, #1
	adds r6, r4, #1
	cmp r1, #0x59
	ble _0801310A
	movs r3, #0
	ldr r4, _08013218 @ =0x085AA838
_080130FC:
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, #1
	adds r3, #1
	cmp r3, #7
	ble _080130FC
_0801310A:
	mov r3, ip
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, #1
	ldr r0, [r3]
	adds r0, r1, r0
	ldrb r0, [r0, #1]
	strb r0, [r2]
	adds r2, #1
	cmp r1, #0x59
	ble _08013136
	movs r3, #0
	ldr r4, _0801321C @ =0x085AA844
_08013128:
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, #1
	adds r3, #1
	cmp r3, #8
	ble _08013128
_08013136:
	adds r4, r6, #0
	cmp r4, #5
	ble _080130EC
	movs r0, #0
	strb r0, [r2]
	mov r1, r8
	cmp r1, #3
	ble _080130E0
	adds r0, r7, #0
	movs r1, #0xc
	bl FUN_08012c74
	ldr r0, _08013220 @ =0x0000044C
	adds r6, r7, r0
	movs r0, #2
	movs r1, #5
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	str r0, [r6]
	cmp r0, #0
	blt _08013238
	movs r4, #0
	adds r5, r7, #0
	adds r5, #0x42
_0801316A:
	ldr r0, [r6]
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0804a40c
	movs r1, #0x80
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r4, #1
	cmp r4, #3
	ble _0801316A
	ldr r0, [r6]
	movs r2, #0x89
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r1, [r4]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	movs r3, #0x8a
	lsls r3, r3, #3
	adds r6, r7, r3
	movs r0, #6
	movs r1, #0x11
	movs r2, #0x1c
	movs r3, #1
	bl FUN_0804a084
	str r0, [r6]
	cmp r0, #0
	blt _08013238
	ldr r1, [r4]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	ldr r0, _08013224 @ =0x00000454
	adds r6, r7, r0
	movs r0, #2
	movs r1, #0xb
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	str r0, [r6]
	cmp r0, #0
	blt _08013238
	ldr r1, [r4]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #2
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	ldr r0, _08013228 @ =0x000092B3
	ldr r1, _0801322C @ =0x0000519C
	bl GetFile
	cmp r0, #0
	beq _08013238
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _08013230 @ =0x03004430
	ldr r2, _08013234 @ =0x04000008
	bl CpuSet
	movs r0, #0
	b _0801323C
	.align 2, 0
_08013210: .4byte 0x000B8E6E
_08013214: .4byte 0x00000444
_08013218: .4byte 0x085AA838
_0801321C: .4byte 0x085AA844
_08013220: .4byte 0x0000044C
_08013224: .4byte 0x00000454
_08013228: .4byte 0x000092B3
_0801322C: .4byte 0x0000519C
_08013230: .4byte 0x03004430
_08013234: .4byte 0x04000008
_08013238:
	movs r0, #1
	rsbs r0, r0, #0
_0801323C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start PasswordScreen_Create
PasswordScreen_Create: @ 0x08013248
	push {r4, lr}
	movs r1, #0x8c
	lsls r1, r1, #3
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08013280
	ldr r1, _08013278 @ =PasswordScreen_Update
	ldr r2, _0801327C @ =PasswordScreen_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl PasswordScreen_Init
	cmp r0, #0
	bge _08013280
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08013282
	.align 2, 0
_08013278: .4byte PasswordScreen_Update
_0801327C: .4byte PasswordScreen_Destroy
_08013280:
	adds r0, r4, #0
_08013282:
	pop {r4}
	pop {r1}
	bx r1
