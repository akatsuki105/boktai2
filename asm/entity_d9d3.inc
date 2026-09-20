	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start EntityD9D3_Update
EntityD9D3_Update: @ 0x0801B5BC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _0801B5CE
	adds r0, r4, #0
	bl FUN_0801b5a0
_0801B5CE:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	cmp r0, #3
	ble _0801B606
	movs r1, #0
	str r1, [r4, #0x18]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	cmp r0, #6
	ble _0801B5E8
	str r1, [r4, #0x1c]
_0801B5E8:
	movs r1, #0
	adds r3, r4, #0
	adds r3, #0x20
	ldr r2, _0801B610 @ =0x03004250
_0801B5F0:
	ldr r0, [r4, #0x1c]
	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r3, r0
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #0xf
	ble _0801B5F0
_0801B606:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801B610: .4byte 0x03004250

	thumb_func_start EntityD9D3_Destroy
EntityD9D3_Destroy: @ 0x0801B614
	movs r0, #0
	bx lr

	thumb_func_start EntityD9D3_Init
EntityD9D3_Init: @ 0x0801B618
	push {lr}
	bl FUN_0801b5a0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start EntityD9D3_Create
EntityD9D3_Create: @ 0x0801B624
	push {r4, lr}
	movs r1, #0x88
	lsls r1, r1, #2
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B65C
	ldr r1, _0801B654 @ =EntityD9D3_Update
	ldr r2, _0801B658 @ =EntityD9D3_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityD9D3_Init
	cmp r0, #0
	bge _0801B65C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B65E
	.align 2, 0
_0801B654: .4byte EntityD9D3_Update
_0801B658: .4byte EntityD9D3_Destroy
_0801B65C:
	adds r0, r4, #0
_0801B65E:
	pop {r4}
	pop {r1}
	bx r1
