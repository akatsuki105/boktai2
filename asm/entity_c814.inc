	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start EntityC814_Update
EntityC814_Update: @ 0x080CB4D8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0x24
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	adds r0, #0xd4
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	movs r3, #0x28
	ldrsh r1, [r4, r3]
	adds r0, r4, #0
	adds r0, #0xd8
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _080CB502
	cmp r1, #0
	beq _080CB562
_080CB502:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _080CB528 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CB52C
	asrs r0, r0, #0xc
	b _080CB532
	.align 2, 0
_080CB528: .4byte 0x085B0A08
_080CB52C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CB532:
	rsbs r0, r0, #0
	strh r0, [r4, #0x2c]
	ldr r1, _080CB554 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CB558
	asrs r0, r0, #0xc
	b _080CB55E
	.align 2, 0
_080CB554: .4byte 0x085B0A08
_080CB558:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CB55E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x30]
_080CB562:
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_0823b4b8
	adds r5, r4, #0
	adds r5, #0xb8
	adds r4, #0x24
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08236268
	ldr r0, _080CB5AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CB5A2
	ldr r0, _080CB5B0 @ =0x030046A0
	ldr r1, [r0]
	ldr r2, _080CB5B4 @ =0xFFFF0000
	ldrh r0, [r1, #0x30]
	str r0, [sp]
	ldrh r1, [r1, #0x34]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08235f40
_080CB5A2:
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080CB5AC: .4byte 0x030044E0
_080CB5B0: .4byte 0x030046A0
_080CB5B4: .4byte 0xFFFF0000

	thumb_func_start EntityC814_Destroy
EntityC814_Destroy: @ 0x080CB5B8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x60
	bl FUN_0822a4e0
	adds r4, #0x1c
	adds r0, r4, #0
	bl FUN_0823b284
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cb5d4
FUN_080cb5d4: @ 0x080CB5D4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CB620
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080CB618 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080CB61C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080CB62A
	.align 2, 0
_080CB618: .4byte 0xFFFF0000
_080CB61C: .4byte 0x0000FFFF
_080CB620:
	ldr r1, _080CB658 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080CB62A:
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CB652
	cmp r1, #0
	blt _080CB652
	ldr r0, _080CB65C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CB652
	ldr r0, _080CB660 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CB664
_080CB652:
	movs r4, #0
	b _080CB672
	.align 2, 0
_080CB658: .4byte 0xFFFF0000
_080CB65C: .4byte 0x030046A8
_080CB660: .4byte 0x030046AC
_080CB664:
	ldr r0, _080CB684 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CB672:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CB688
	adds r0, #4
	b _080CB694
	.align 2, 0
_080CB684: .4byte 0x030046A4
_080CB688:
	ldr r0, _080CB6A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CB694:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CB6AC
	cmp r2, #2
	beq _080CB6B0
	b _080CB6B4
	.align 2, 0
_080CB6A8: .4byte 0x030046A4
_080CB6AC:
	ldrb r0, [r5, #4]
	b _080CB6B2
_080CB6B0:
	ldrb r0, [r5]
_080CB6B2:
	subs r1, r1, r0
_080CB6B4:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x18]
	movs r2, #7
	str r2, [sp]
	str r6, [sp, #4]
	add r2, sp, #8
	movs r3, #0
	bl FUN_0823b400
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cb6d4
FUN_080cb6d4: @ 0x080CB6D4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x8c
	ldr r1, _080CB710 @ =0x00009DA7
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r6, #0
	adds r0, #0x1c
	adds r1, r5, #0
	bl FUN_0823b46c
	adds r2, r6, #0
	adds r2, #0x7c
	ldr r0, [r6, #0x24]
	ldr r1, [r6, #0x28]
	str r0, [r2]
	str r1, [r2, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CB710: .4byte 0x00009DA7

	thumb_func_start FUN_080cb714
FUN_080cb714: @ 0x080CB714
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xa8
	adds r1, r5, #0
	adds r1, #0x24
	adds r0, r4, #0
	bl FUN_0823280c
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cb73c
FUN_080cb73c: @ 0x080CB73C
	push {lr}
	adds r1, r0, #0
	adds r0, #0xb8
	adds r1, #0x24
	bl FUN_082362fc
	pop {r0}
	bx r0

	thumb_func_start EntityC814_Init
EntityC814_Init: @ 0x080CB74C
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl FUN_080cb5d4
	adds r0, r4, #0
	bl FUN_080cb6d4
	adds r0, r4, #0
	bl FUN_080cb714
	adds r0, r4, #0
	bl FUN_080cb73c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityC814_Create
EntityC814_Create: @ 0x080CB770
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0xdc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CB7AC
	ldr r1, _080CB7A4 @ =EntityC814_Update
	ldr r2, _080CB7A8 @ =EntityC814_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityC814_Init
	cmp r0, #0
	bge _080CB7AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CB7AE
	.align 2, 0
_080CB7A4: .4byte EntityC814_Update
_080CB7A8: .4byte EntityC814_Destroy
_080CB7AC:
	adds r0, r4, #0
_080CB7AE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
