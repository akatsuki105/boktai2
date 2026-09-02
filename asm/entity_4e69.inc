	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080220bc
FUN_080220bc: @ 0x080220BC
	push {r4, lr}
	adds r4, r1, #0
	ldr r3, [r0, #0x74]
	cmp r3, #0
	beq _080220DE
_080220C6:
	ldr r1, [r3, #0x30]
	ldrh r0, [r3]
	cmp r0, r4
	bne _080220D8
	ldrb r0, [r3, #2]
	cmp r0, r2
	bne _080220D8
	adds r0, r3, #0
	b _080220E0
_080220D8:
	adds r3, r1, #0
	cmp r3, #0
	bne _080220C6
_080220DE:
	movs r0, #0
_080220E0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080220e8
FUN_080220e8: @ 0x080220E8
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x74]
	cmp r0, #0
	beq _080220F4
	str r1, [r0, #0x2c]
_080220F4:
	movs r0, #0
	str r0, [r1, #0x2c]
	ldr r0, [r2, #0x74]
	str r0, [r1, #0x30]
	str r1, [r2, #0x74]
	movs r0, #0
	pop {r1}
	bx r1

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

	thumb_func_start FUN_080221fc
FUN_080221fc: @ 0x080221FC
	push {lr}
	movs r2, #1
	str r2, [r0, #0x70]
	adds r0, r1, #0
	movs r1, #1
	bl FUN_08022488
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08022210
FUN_08022210: @ 0x08022210
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x78
	movs r7, #0
	ldr r2, _08022260 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x7e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _080222A0
	mov r8, r2
_08022232:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #1
	beq _08022276
	cmp r0, #1
	bgt _08022264
	cmp r0, #0
	beq _0802226A
	b _0802228C
	.align 2, 0
_08022260: .4byte 0x03002B4C
_08022264:
	cmp r0, #2
	beq _08022282
	b _0802228C
_0802226A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080221b8
	b _0802228C
_08022276:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080221e0
	b _0802228C
_08022282:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080221fc
_0802228C:
	adds r7, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r5, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08022232
_080222A0:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity4E69_Update
Entity4E69_Update: @ 0x080222AC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	adds r0, #0x23
	ldrb r2, [r0]
	cmp r2, #1
	bne _0802232E
	strb r5, [r4, #0x1f]
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _080222D0
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0x1a]
	strh r5, [r4, #0x1c]
	strb r1, [r4, #0x1e]
	strb r2, [r4, #0x1f]
_080222D0:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _08022316
	strh r5, [r4, #0x1c]
	b _080222E6
_080222DA:
	adds r0, r4, #0
	bl FUN_08022128
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
_080222E6:
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	movs r2, #0x1a
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #0x1c]
	bl FUN_0823a840
	adds r1, r0, #0
	cmp r1, #0
	bne _080222DA
	ldrh r5, [r4, #0x1c]
	cmp r5, #0
	bne _08022314
	ldrh r0, [r4, #0x20]
	cmp r0, #0
	beq _0802230C
	movs r1, #0
	bl Script_ExecById
_0802230C:
	adds r0, r4, #0
	adds r0, #0x23
	strb r5, [r0]
	b _0802233E
_08022314:
	movs r5, #1
_08022316:
	ldr r0, [r4, #0x68]
	cmp r0, #0
	beq _0802232E
	subs r0, #1
	str r0, [r4, #0x68]
	cmp r0, #0
	bne _0802232E
	adds r0, r4, #0
	adds r0, #0x78
	movs r1, #1
	bl FUN_08022488
_0802232E:
	adds r0, r4, #0
	bl FUN_0802216c
	cmp r5, #0
	beq _0802233E
	adds r0, r4, #0
	bl FUN_08022210
_0802233E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity4E69_Destroy
Entity4E69_Destroy: @ 0x08022348
	.byte 0x00, 0xB5, 0x78, 0x30, 0x00, 0xF0, 0x6C, 0xF8
	.byte 0x02, 0x49, 0x00, 0x20, 0x08, 0x60, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0x4C, 0x2B, 0x00, 0x03

	thumb_func_start Entity4E69_Init
Entity4E69_Init: @ 0x08022360
	push {r4, lr}
	ldr r2, _0802239C @ =0x03002B4C
	str r0, [r2]
	adds r2, r0, #0
	adds r2, #0x23
	movs r3, #0
	strb r3, [r2]
	ldr r2, _080223A0 @ =0x0000FFFF
	strh r2, [r0, #0x18]
	movs r2, #1
	rsbs r2, r2, #0
	strh r2, [r0, #0x1a]
	movs r2, #0
	strh r3, [r0, #0x1c]
	strb r2, [r0, #0x1e]
	strb r2, [r0, #0x1f]
	strh r3, [r0, #0x20]
	movs r4, #0x22
	strb r2, [r4, r0]
	str r3, [r0, #0x6c]
	str r3, [r0, #0x74]
	adds r0, #0x78
	movs r2, #1
	bl FUN_080223f4
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802239C: .4byte 0x03002B4C
_080223A0: .4byte 0x0000FFFF

	thumb_func_start Entity4E69_Create
Entity4E69_Create: @ 0x080223A4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080223B4 @ =0x03002B4C
	ldr r0, [r0]
	cmp r0, #0
	beq _080223B8
	movs r0, #0
	b _080223EE
	.align 2, 0
_080223B4: .4byte 0x03002B4C
_080223B8:
	movs r0, #2
	movs r1, #0xac
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080223EC
	ldr r1, _080223E4 @ =Entity4E69_Update
	ldr r2, _080223E8 @ =Entity4E69_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity4E69_Init
	cmp r0, #0
	bge _080223EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080223EE
	.align 2, 0
_080223E4: .4byte Entity4E69_Update
_080223E8: .4byte Entity4E69_Destroy
_080223EC:
	adds r0, r4, #0
_080223EE:
	pop {r4, r5}
	pop {r1}
	bx r1
