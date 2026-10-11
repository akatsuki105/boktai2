	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c114c
FUN_080c114c: @ 0x080C114C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c1150
FUN_080c1150: @ 0x080C1150
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x96
	adds r0, #0x98
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bhi _080C116E
	movs r1, #1
	strh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x9e
	strh r1, [r0]
	b _080C1172
_080C116E:
	subs r0, r1, r0
	strh r0, [r3]
_080C1172:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c1178
FUN_080c1178: @ 0x080C1178
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _080C11EC @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _080C11E0
	mov r8, r2
_080C119A:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #2
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
	bl MsgQueue_BeginWait
	ldrb r0, [r4, #6]
	cmp r0, #6
	bne _080C11CC
	adds r1, r7, #0
	adds r1, #0xac
	ldr r0, _080C11F0 @ =FUN_080c1150
	str r0, [r1]
	ldr r0, _080C11F4 @ =0x0000025D
	bl PlaySound_082406e0
_080C11CC:
	adds r5, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _080C119A
_080C11E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C11EC: .4byte 0x03002B4C
_080C11F0: .4byte FUN_080c1150
_080C11F4: .4byte 0x0000025D

	thumb_func_start Entity3361_Update
Entity3361_Update: @ 0x080C11F8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080c1178
	adds r0, r4, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080C121E
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	b _080C1224
_080C121E:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
_080C1224:
	strh r0, [r1, #0x10]
	adds r0, r4, #0
	adds r0, #0x96
	ldrh r1, [r0]
	subs r0, #0x41
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080C124A
	movs r0, #0
	strh r0, [r1]
_080C124A:
	adds r0, r4, #0
	adds r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	beq _080C1264
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl MsgQueue_EndWait
	adds r0, r4, #0
	bl KillEntity
_080C1264:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity3361_Destroy
Entity3361_Destroy: @ 0x080C126C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl MsgQueue_Unregister
	adds r4, #0x4c
	adds r0, r4, #0
	bl AuxSprite_Remove
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity3361_Init
Entity3361_Init: @ 0x080C1288
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r2, r7, #0
	adds r2, #0x94
	strh r1, [r2]
	adds r0, #0x18
	ldrh r1, [r2]
	movs r2, #0xa
	bl MsgQueue_Register
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080C12D2
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0xa4
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xa6
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xa8
	strh r0, [r1]
	mov sl, r4
	b _080C12E4
_080C12D2:
	adds r1, r7, #0
	adds r1, #0xa4
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0xa6
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	mov sl, r1
_080C12E4:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C12F4
	bl VM_GetValue
	b _080C12F6
_080C12F4:
	movs r0, #2
_080C12F6:
	mov sb, r0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C131A
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0x9a
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r2, r4, #0
	b _080C132A
_080C131A:
	adds r2, r7, #0
	adds r2, #0x9a
	movs r0, #0x40
	strh r0, [r2]
	adds r1, r7, #0
	adds r1, #0x98
	movs r0, #2
	strh r0, [r1]
_080C132A:
	ldrh r0, [r2]
	movs r1, #0x96
	adds r1, r1, r7
	mov r8, r1
	movs r6, #0
	strh r0, [r1]
	adds r5, r7, #0
	adds r5, #0x4c
	adds r4, r7, #0
	adds r4, #0x78
	ldr r1, _080C139C @ =0x00003641
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #2
	bl AuxSprite_Add
	adds r0, r4, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	strh r6, [r5, #0x10]
	mov r2, r8
	ldrh r0, [r2]
	strb r0, [r5, #8]
	strb r0, [r5, #9]
	ldr r0, [r7, #0x4c]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x4c]
	mov r0, sb
	strb r0, [r5, #7]
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r0, r7, #0
	adds r0, #0x9c
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r1, r7, #0
	adds r1, #0xac
	ldr r0, _080C13A0 @ =FUN_080c114c
	str r0, [r1]
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C139C: .4byte 0x00003641
_080C13A0: .4byte FUN_080c114c

	thumb_func_start Entity3361_Create
Entity3361_Create: @ 0x080C13A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0xa
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C13E0
	ldr r1, _080C13D8 @ =Entity3361_Update
	ldr r2, _080C13DC @ =Entity3361_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity3361_Init
	cmp r0, #0
	bge _080C13E0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C13E2
	.align 2, 0
_080C13D8: .4byte Entity3361_Update
_080C13DC: .4byte Entity3361_Destroy
_080C13E0:
	adds r0, r4, #0
_080C13E2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
