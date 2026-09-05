	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080091e8
FUN_080091e8: @ 0x080091E8
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x50
	ldr r1, _0800921C @ =0x0000A850
	adds r0, r6, #0
	bl Video_GetActorSprite
	cmp r0, #0
	beq _08009220
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #1
	strh r0, [r4, #0x10]
	adds r1, r5, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	movs r0, #0
	b _08009224
	.align 2, 0
_0800921C: .4byte 0x0000A850
_08009220:
	movs r0, #1
	rsbs r0, r0, #0
_08009224:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800922c
FUN_0800922c: @ 0x0800922C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	cmp r2, #0
	beq _0800923C
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r2]
_0800923C:
	ldr r3, [r4, #0x20]
	movs r1, #0
	ldrb r0, [r4, #0x18]
	cmp r1, r0
	bge _0800926E
	movs r7, #1
	ldr r5, [r4, #0x1c]
	adds r4, r0, #0
_0800924C:
	adds r0, r7, #0
	lsls r0, r1
	ands r0, r5
	cmp r0, #0
	beq _08009266
	ldrh r0, [r3]
	cmp r0, r6
	bne _08009266
	cmp r2, #0
	beq _08009262
	str r1, [r2]
_08009262:
	adds r0, r3, #0
	b _08009270
_08009266:
	adds r1, #1
	adds r3, #0x6c
	cmp r1, r4
	blt _0800924C
_0800926E:
	movs r0, #0
_08009270:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009278
FUN_08009278: @ 0x08009278
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	adds r4, r2, #0
	adds r4, #0x50
	ldrb r1, [r2, #4]
	cmp r1, #0
	bne _08009292
	adds r1, r3, #0
	adds r1, #0x4c
	adds r0, r4, #0
	bl FUN_0822b20c
_08009292:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08009298
FUN_08009298: @ 0x08009298
	push {r4, lr}
	adds r3, r1, #0
	adds r4, r3, #0
	adds r4, #0x24
	ldrh r1, [r2]
	strh r1, [r3, #0x1c]
	ldrh r1, [r2, #2]
	strh r1, [r3, #0x1e]
	ldrh r1, [r2, #4]
	strh r1, [r3, #0x20]
	ldrh r1, [r2]
	strh r1, [r4, #0x1c]
	ldrh r1, [r2, #2]
	strh r1, [r4, #0x1e]
	ldrh r1, [r2, #4]
	strh r1, [r4, #0x20]
	ldrb r1, [r3, #2]
	cmp r1, #0
	beq _080092CC
	ldrh r1, [r3, #0x1c]
	adds r1, #0x80
	strh r1, [r3, #0x1c]
	ldrh r1, [r4, #0x20]
	subs r1, #0x80
	strh r1, [r4, #0x20]
	b _080092D8
_080092CC:
	ldrh r1, [r3, #0x20]
	adds r1, #0x80
	strh r1, [r3, #0x20]
	ldrh r1, [r4, #0x1c]
	subs r1, #0x80
	strh r1, [r4, #0x1c]
_080092D8:
	ldrh r1, [r4, #0x1c]
	adds r1, #0x3c
	strh r1, [r4, #0x1c]
	ldrh r1, [r4, #0x20]
	adds r1, #0x3c
	strh r1, [r4, #0x20]
	ldrh r1, [r4, #0x1e]
	adds r1, #0x14
	strh r1, [r4, #0x1e]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080092f0
FUN_080092f0: @ 0x080092F0
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _0800935C
	ldrb r0, [r4, #5]
	cmp r0, #1
	beq _08009330
	cmp r0, #1
	bgt _0800930A
	cmp r0, #0
	beq _08009310
	b _0800935C
_0800930A:
	cmp r0, #2
	beq _08009350
	b _0800935C
_08009310:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08009320
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08009278
	b _0800935C
_08009320:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08009278
	ldrb r0, [r4, #7]
	subs r0, #1
	strb r0, [r4, #7]
	b _0800935C
_08009330:
	ldrb r0, [r4, #7]
	cmp r0, #4
	bls _08009340
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08009278
	b _0800935C
_08009340:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08009278
	ldrb r0, [r4, #7]
	adds r0, #1
	strb r0, [r4, #7]
	b _0800935C
_08009350:
	movs r0, #5
	strb r0, [r4, #7]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08009278
_0800935C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08009364
FUN_08009364: @ 0x08009364
	push {lr}
	adds r3, r0, #0
	ldr r2, [r3, #0x24]
	ldr r1, _0800938C @ =0x0000186C
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08009390
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08009390
	movs r0, #0x19
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _08009390
	movs r0, #1
	b _08009392
	.align 2, 0
_0800938C: .4byte 0x0000186C
_08009390:
	movs r0, #0
_08009392:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08009398
FUN_08009398: @ 0x08009398
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r2, #0
	cmp r5, #0
	beq _080093D4
	ldrh r0, [r1]
	str r0, [sp]
	movs r3, #0
	add r4, sp, #0x14
	adds r1, #0x14
	add r2, sp, #4
_080093AE:
	movs r6, #0
	ldrsh r0, [r1, r6]
	stm r2!, {r0}
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _080093AE
	ldr r0, _080093DC @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r0
	movs r0, #5
	orrs r1, r0
	str r1, [sp, #0x14]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	bl Script_ExecById
_080093D4:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080093DC: .4byte 0xFFFF0000

