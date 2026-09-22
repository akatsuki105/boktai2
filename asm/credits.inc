	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804a5f8
FUN_0804a5f8: @ 0x0804A5F8
	ldr r1, _0804A600 @ =gCredits
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0804A600: .4byte gCredits

	thumb_func_start FUN_0804a604
FUN_0804a604: @ 0x0804A604
	push {r4, r5, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0x1a]
	lsls r4, r4, #1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r3, r1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r3, r2
	adds r1, r1, r4
	ldrh r1, [r1]
	movs r5, #0xad
	lsls r5, r5, #2
	adds r2, r3, r5
	adds r2, r2, r4
	ldrh r2, [r2]
	adds r5, #0x80
	adds r3, r3, r5
	adds r3, r3, r4
	ldrh r3, [r3]
	bl TextBox_SetRect
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804a63c
FUN_0804a63c: @ 0x0804A63C
	movs r2, #0
	strb r1, [r0, #0x18]
	movs r1, #1
	strb r1, [r0, #0x19]
	str r2, [r0, #0x20]
	bx lr

	thumb_func_start FUN_0804a648
FUN_0804a648: @ 0x0804A648
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x19]
	cmp r0, #0
	bne _0804A656
	movs r0, #0
	b _0804A65C
_0804A656:
	movs r0, #0
	strb r0, [r1, #0x19]
	movs r0, #1
_0804A65C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a660
FUN_0804a660: @ 0x0804A660
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804a648
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804A680
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_0804a604
	ldrb r0, [r4, #0x1a]
	bl TextBox_ShowLine
_0804A680:
	ldrb r1, [r4, #0x1a]
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0xb4
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, [r4, #0x20]
	cmp r0, r1
	blo _0804A6A8
	ldr r1, _0804A6A4 @ =0x03004040
	movs r0, #0x40
	str r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0804a63c
	b _0804A6B2
	.align 2, 0
_0804A6A4: .4byte 0x03004040
_0804A6A8:
	lsls r0, r0, #6
	bl Div
	ldr r1, _0804A6B8 @ =0x03004040
	str r0, [r1]
_0804A6B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A6B8: .4byte 0x03004040

	thumb_func_start FUN_0804a6bc
FUN_0804a6bc: @ 0x0804A6BC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804a648
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804A6D0
	ldr r1, _0804A6F4 @ =0x03004040
	movs r0, #0x40
	str r0, [r1]
_0804A6D0:
	ldrb r1, [r4, #0x1a]
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x20]
	cmp r0, r1
	blo _0804A6EC
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0804a63c
_0804A6EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A6F4: .4byte 0x03004040

	thumb_func_start FUN_0804a6f8
FUN_0804a6f8: @ 0x0804A6F8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804a648
	ldrb r1, [r4, #0x1a]
	lsls r1, r1, #1
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, [r4, #0x20]
	cmp r0, r1
	blo _0804A75E
	ldr r1, _0804A74C @ =0x03004040
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r4, #0x1a]
	ldrb r1, [r4, #0x1b]
	cmp r0, r1
	bne _0804A750
	bl TextBox_Close
	adds r0, r4, #0
	movs r1, #4
	bl FUN_0804a63c
	ldrh r0, [r4, #0x30]
	cmp r0, #0
	beq _0804A73A
	movs r1, #0
	bl Script_ExecById
_0804A73A:
	ldrh r1, [r4, #0x24]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804A76C
	adds r0, r4, #0
	bl KillEntity
	b _0804A76C
	.align 2, 0
_0804A74C: .4byte 0x03004040
_0804A750:
	adds r0, #1
	strb r0, [r4, #0x1a]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0804a63c
	b _0804A76C
_0804A75E:
	ldr r4, _0804A774 @ =0x03004040
	lsls r0, r0, #6
	bl Div
	movs r1, #0x40
	subs r1, r1, r0
	str r1, [r4]
_0804A76C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A774: .4byte 0x03004040

	thumb_func_start FUN_0804a778
FUN_0804a778: @ 0x0804A778
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0804a648
	ldrh r0, [r5, #0x32]
	cmp r0, #0
	beq _0804A7B8
	ldr r0, [r5, #0x20]
	cmp r0, #0xf
	bls _0804A7A8
	ldr r0, _0804A7A4 @ =0x03004040
	movs r4, #0
	str r4, [r0]
	ldrh r0, [r5, #0x32]
	movs r1, #0
	bl Script_ExecById
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	bl KillEntity
	b _0804A7B8
	.align 2, 0
_0804A7A4: .4byte 0x03004040
_0804A7A8:
	ldr r4, _0804A7C0 @ =0x03004040
	lsls r0, r0, #6
	movs r1, #0x10
	bl Div
	movs r1, #0x40
	subs r1, r1, r0
	str r1, [r4]
_0804A7B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804A7C0: .4byte 0x03004040

	thumb_func_start Credits_Update
Credits_Update: @ 0x0804A7C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0804A810 @ =0x085AB550
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804A7DC
	adds r0, r4, #0
	bl _call_via_r1
_0804A7DC:
	ldr r1, _0804A814 @ =0x03004250
	ldr r0, _0804A818 @ =0x00001084
	strh r0, [r1]
	ldr r0, _0804A81C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0804A802
	ldrh r0, [r4, #0x32]
	cmp r0, #0
	beq _0804A802
	ldrb r0, [r4, #0x18]
	cmp r0, #2
	bhi _0804A802
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804a63c
_0804A802:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A810: .4byte 0x085AB550
_0804A814: .4byte 0x03004250
_0804A818: .4byte 0x00001084
_0804A81C: .4byte 0x030044E0

	thumb_func_start Credits_Destroy
Credits_Destroy: @ 0x0804A820
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0804A848 @ =gCredits
	movs r0, #0
	str r0, [r1]
	bl TextBox_Close
	ldrh r1, [r4, #0x24]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804A83E
	ldr r1, _0804A84C @ =0x03003E78
	ldrh r0, [r4, #0x26]
	strh r0, [r1]
_0804A83E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A848: .4byte gCredits
_0804A84C: .4byte 0x03003E78

	thumb_func_start FUN_0804a850
FUN_0804a850: @ 0x0804A850
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r4, #0
	strb r4, [r5, #0x18]
	strb r4, [r5, #0x19]
	str r4, [r5, #0x20]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0x1a]
	str r4, [r5, #0x1c]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804A882
	bl FUN_0823d340
	str r0, [r5, #0x28]
	cmp r0, #0
	bne _0804A88E
_0804A882:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A978
_0804A888:
	subs r0, r7, #1
	strb r0, [r5, #0x1b]
	b _0804A924
_0804A88E:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804A924
	bl FUN_0823d34c
	str r0, [r5, #0x2c]
	bl VM_SetPC
	movs r7, #0
	movs r0, #1
	rsbs r0, r0, #0
	mov sb, r0
	adds r6, r5, #0
	adds r6, #0x34
	movs r1, #0xb4
	adds r1, r1, r5
	mov r8, r1
_0804A8B4:
	bl Script_GetValue
	lsls r4, r7, #1
	strh r0, [r6]
	bl Script_GetValue
	movs r2, #0xda
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xad
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xcd
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl Script_GetValue
	mov r1, r8
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	ldrb r0, [r5, #0x1a]
	cmp r7, r0
	blt _0804A918
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, sb
	beq _0804A888
_0804A918:
	adds r6, #2
	movs r2, #2
	add r8, r2
	adds r7, #1
	cmp r7, #0x3f
	ble _0804A8B4
_0804A924:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r5, #0x30]
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x32]
	ldr r0, [r5, #0x28]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, _0804A984 @ =0x0000539C
	bl TextBox_SetBgPltt
	ldrb r0, [r5, #0x1a]
	bl TextBox_ShowLine
	adds r0, r5, #0
	bl FUN_0804a604
	ldr r1, _0804A988 @ =0x03004494
	ldr r2, _0804A98C @ =0x00001084
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _0804A990 @ =0x03004454
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0804A994 @ =0x03004040
	str r4, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0804a63c
	movs r0, #0
_0804A978:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804A984: .4byte 0x0000539C
_0804A988: .4byte 0x03004494
_0804A98C: .4byte 0x00001084
_0804A990: .4byte 0x03004454
_0804A994: .4byte 0x03004040

	thumb_func_start Credits_Init
Credits_Init: @ 0x0804A998
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804A9D0 @ =gCredits
	str r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r4, #0x24]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0804A9C4
	ldr r2, _0804A9D4 @ =0x03003E78
	ldrh r1, [r2]
	strh r1, [r4, #0x26]
	ldr r0, _0804A9D8 @ =0xFFFFF1FF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	strh r0, [r2]
_0804A9C4:
	adds r0, r4, #0
	bl FUN_0804a850
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A9D0: .4byte gCredits
_0804A9D4: .4byte 0x03003E78
_0804A9D8: .4byte 0xFFFFF1FF

	thumb_func_start Credits_Create
Credits_Create: @ 0x0804A9DC
	push {r4, lr}
	ldr r4, _0804A9F0 @ =gCredits
	ldr r0, [r4]
	cmp r0, #0
	beq _0804A9F4
	bl FUN_0804a850
	ldr r0, [r4]
	b _0804AA2A
	.align 2, 0
_0804A9F0: .4byte gCredits
_0804A9F4:
	movs r1, #0xed
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804AA28
	ldr r1, _0804AA20 @ =Credits_Update
	ldr r2, _0804AA24 @ =Credits_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Credits_Init
	cmp r0, #0
	bge _0804AA28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804AA2A
	.align 2, 0
_0804AA20: .4byte Credits_Update
_0804AA24: .4byte Credits_Destroy
_0804AA28:
	adds r0, r4, #0
_0804AA2A:
	pop {r4}
	pop {r1}
	bx r1
