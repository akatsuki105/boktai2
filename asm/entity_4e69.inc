	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08022104
FUN_08022104: @ 0x08022104
	push {lr}
	adds r3, r0, #0
	ldr r2, [r1, #0x2c]
	cmp r2, #0
	beq _08022114
	ldr r0, [r1, #0x30]
	str r0, [r2, #0x30]
	b _08022118
_08022114:
	ldr r0, [r1, #0x30]
	str r0, [r3, #0x74]
_08022118:
	ldr r2, [r1, #0x30]
	cmp r2, #0
	beq _08022122
	ldr r0, [r1, #0x2c]
	str r0, [r2, #0x2c]
_08022122:
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08022128
FUN_08022128: @ 0x08022128
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldrh r1, [r6]
	ldrb r2, [r6, #2]
	bl FUN_080220bc
	adds r5, r0, #0
	adds r4, #0x24
	ldrb r2, [r4]
	movs r1, #1
	subs r4, r1, r2
	cmp r5, #0
	beq _08022164
	adds r1, r5, #6
	adds r3, r1, r4
	ldrb r1, [r3]
	cmp r1, #3
	bhi _08022164
	adds r2, r1, #0
	lsls r2, r2, #2
	lsls r1, r4, #4
	adds r2, r2, r1
	adds r1, r5, #0
	adds r1, #8
	adds r1, r1, r2
	str r6, [r1]
	ldrb r1, [r3]
	adds r1, #1
	strb r1, [r3]
_08022164:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0802216c
FUN_0802216c: @ 0x0802216C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x74]
	cmp r1, #0
	beq _080221A4
	adds r4, r6, #0
	adds r4, #0x24
	movs r7, #0
_0802217C:
	ldr r5, [r1, #0x30]
	adds r0, r1, #6
	ldrb r2, [r4]
	adds r0, r0, r2
	strb r7, [r0]
	movs r3, #0
	adds r2, r1, #0
	adds r2, #8
_0802218C:
	lsls r1, r3, #2
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r2, r1
	str r7, [r1]
	adds r3, #1
	cmp r3, #3
	ble _0802218C
	adds r1, r5, #0
	cmp r1, #0
	bne _0802217C
_080221A4:
	adds r2, r6, #0
	adds r2, #0x24
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080221b8
FUN_080221b8: @ 0x080221B8
	push {r4, lr}
	adds r4, r1, #0
	ldrh r0, [r2, #8]
	bl FUN_080224a8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _080221D0
	movs r1, #0
	bl Script_ExecById
_080221D0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080221e0
FUN_080221e0: @ 0x080221E0
	push {r4, lr}
	adds r3, r1, #0
	movs r4, #8
	ldrsh r1, [r2, r4]
	str r1, [r0, #0x68]
	cmp r1, #0
	bne _080221F6
	adds r0, r3, #0
	movs r1, #1
	bl FUN_08022488
_080221F6:
	pop {r4}
	pop {r0}
	bx r0

