	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0823cd04
FUN_0823cd04: @ 0x0823CD04
	ldr r0, _0823CD20 @ =0x030047A4
	movs r1, #0
	str r1, [r0]
	ldr r0, _0823CD24 @ =0x030047A0
	str r1, [r0]
	ldr r0, _0823CD28 @ =0x0300479C
	str r1, [r0]
	ldr r0, _0823CD2C @ =0x030047C0
	str r1, [r0]
	ldr r0, _0823CD30 @ =0x0300478C
	str r1, [r0]
	ldr r0, _0823CD34 @ =0x030047C4
	str r1, [r0]
	bx lr
	.align 2, 0
_0823CD20: .4byte 0x030047A4
_0823CD24: .4byte 0x030047A0
_0823CD28: .4byte 0x0300479C
_0823CD2C: .4byte 0x030047C0
_0823CD30: .4byte 0x0300478C
_0823CD34: .4byte 0x030047C4

	thumb_func_start FUN_0823cd38
FUN_0823cd38: @ 0x0823CD38
	ldr r0, _0823CD44 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0823CD44: .4byte 0x030046A0

	thumb_func_start FUN_0823cd48
FUN_0823cd48: @ 0x0823CD48
	push {r4, lr}
	sub sp, #4
	bl FUN_0823cd38
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r2, _0823CD98 @ =0x05000004
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823CD9C
	bl VM_GetPC
	bl VM_GetValueAtSafe_Proxy
	adds r1, r0, #0
	cmp r1, #0
	beq _0823CDB6
	movs r3, #0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0823CDB6
	adds r2, r1, #0
_0823CD82:
	adds r0, r4, r3
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _0823CDB6
	cmp r3, #0xf
	ble _0823CD82
	b _0823CDB6
	.align 2, 0
_0823CD98: .4byte 0x05000004
_0823CD9C:
	movs r1, #0x80
	strb r1, [r4]
	movs r0, #0xa2
	strb r0, [r4, #1]
	strb r1, [r4, #2]
	movs r0, #0x98
	strb r0, [r4, #3]
	strb r1, [r4, #4]
	movs r0, #0x91
	strb r0, [r4, #5]
	strb r1, [r4, #6]
	movs r0, #0x9f
	strb r0, [r4, #7]
_0823CDB6:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0823cdc0
FUN_0823cdc0: @ 0x0823CDC0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
_0823CDC6:
	cmp r2, r3
	bge _0823CDE0
	adds r0, r2, r3
	asrs r1, r0, #1
	lsls r0, r1, #2
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r5
	bhs _0823CDDC
	adds r2, r1, #1
	b _0823CDC6
_0823CDDC:
	adds r3, r1, #0
	b _0823CDC6
_0823CDE0:
	lsls r0, r2, #2
	adds r1, r0, r4
	ldrh r0, [r1]
	cmp r0, r5
	beq _0823CDEE
	movs r0, #0
	b _0823CDF0
_0823CDEE:
	ldrh r0, [r1, #2]
_0823CDF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823cdf8
FUN_0823cdf8: @ 0x0823CDF8
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0823CE0C @ =0x08DBD83C
	movs r2, #0
	movs r3, #0xaa
	bl FUN_0823cdc0
	pop {r1}
	bx r1
	.align 2, 0
_0823CE0C: .4byte 0x08DBD83C

	thumb_func_start FUN_0823ce10
FUN_0823ce10: @ 0x0823CE10
	push {r4, lr}
	ldr r3, _0823CE34 @ =0x08DBD798
	ldr r4, _0823CE38 @ =gClock
	ldrb r2, [r4, #0xe]
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrb r2, [r2]
	strh r2, [r0]
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #1
	adds r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823CE34: .4byte 0x08DBD798
_0823CE38: .4byte gClock

	thumb_func_start FUN_0823ce3c
FUN_0823ce3c: @ 0x0823CE3C
	push {r4, lr}
	ldr r3, _0823CE60 @ =0x08DBD798
	ldr r4, _0823CE64 @ =gClock
	ldrb r2, [r4, #0xe]
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrb r2, [r2]
	strh r2, [r0]
	ldrb r0, [r4, #0xe]
	lsls r0, r0, #1
	adds r3, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823CE60: .4byte 0x08DBD798
_0823CE64: .4byte gClock

