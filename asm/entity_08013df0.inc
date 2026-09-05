	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08013c94
FUN_08013c94: @ 0x08013C94
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r2, #0
	adds r5, r4, #0
	adds r5, #0x38
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r4, #0xc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a4fc
	strh r6, [r4, #0x10]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013cb8
FUN_08013cb8: @ 0x08013CB8
	push {lr}
	adds r3, r0, #0
	cmp r1, #0
	beq _08013CC8
	ldr r1, [r3, #0xc]
	movs r2, #2
	orrs r1, r2
	b _08013CD0
_08013CC8:
	ldr r1, [r3, #0xc]
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
_08013CD0:
	str r1, [r3, #0xc]
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013cd8
FUN_08013cd8: @ 0x08013CD8
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	ldr r6, [sp, #0x1c]
	ldr r7, [sp, #0x20]
	adds r0, #0x54
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strh r5, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #2
	strh r7, [r0]
	adds r0, #2
	mov r1, sp
	ldrh r1, [r1, #0x24]
	strh r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08013d10
FUN_08013d10: @ 0x08013D10
	push {lr}
	ldr r0, _08013D24 @ =0x03002B40
	ldr r0, [r0]
	cmp r0, #0
	bne _08013D1E
	bl Entity08013df0_Create
_08013D1E:
	pop {r1}
	bx r1
	.align 2, 0
_08013D24: .4byte 0x03002B40

	thumb_func_start FUN_08013d28
FUN_08013d28: @ 0x08013D28
	push {lr}
	ldr r2, [r0, #0x18]
	cmp r2, #0
	beq _08013D40
_08013D30:
	ldrh r0, [r2]
	cmp r0, r1
	bne _08013D3A
	adds r0, r2, #0
	b _08013D42
_08013D3A:
	ldr r2, [r2, #0x50]
	cmp r2, #0
	bne _08013D30
_08013D40:
	movs r0, #0
_08013D42:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013d48
FUN_08013d48: @ 0x08013D48
	push {lr}
	ldrb r2, [r1, #2]
	cmp r2, #0
	beq _08013D56
	movs r0, #1
	rsbs r0, r0, #0
	b _08013D6A
_08013D56:
	str r2, [r1, #0x4c]
	ldr r2, [r0, #0x18]
	str r2, [r1, #0x50]
	cmp r2, #0
	beq _08013D62
	str r1, [r2, #0x4c]
_08013D62:
	str r1, [r0, #0x18]
	movs r0, #1
	strb r0, [r1, #2]
	movs r0, #0
_08013D6A:
	pop {r1}
	bx r1
	.align 2, 0


