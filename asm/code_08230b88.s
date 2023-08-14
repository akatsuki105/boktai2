	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08230e90
FUN_08230e90: @ 0x08230E90
	push {lr}
	bl FUN_08230e88
	ldr r2, _08230EB0 @ =0x03000740
	movs r1, #0
	str r1, [r2]
	str r1, [r0]
	str r1, [r0, #4]
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r0, r2
	str r1, [r0]
	str r1, [r0, #4]
	pop {r0}
	bx r0
	.align 2, 0
_08230EB0: .4byte 0x03000740

	thumb_func_start FUN_08230eb4
FUN_08230eb4: @ 0x08230EB4
	push {r4, lr}
	bl FUN_08230e88
	adds r4, r0, #0
	ldr r0, _08230EE4 @ =0x030044BC
	ldr r3, [r0]
	cmp r3, #0
	bne _08230EDE
	ldr r2, _08230EE8 @ =0x03000740
	ldr r1, [r2]
	movs r0, #1
	eors r1, r0
	str r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r4, r0
	str r3, [r0]
	str r3, [r0, #4]
_08230EDE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08230EE4: .4byte 0x030044BC
_08230EE8: .4byte 0x03000740

	thumb_func_start FUN_08230eec
FUN_08230eec: @ 0x08230EEC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl FUN_08230e88
	ldr r1, _08230F78 @ =0x03000740
	ldr r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r6, r0, r1
	adds r4, r6, #0
	adds r4, #8
	ldr r5, [r6]
	movs r3, #0
	cmp r3, r5
	bge _08230F28
	ldrh r0, [r7]
	mov ip, r0
	adds r2, r5, #0
_08230F16:
	ldrh r0, [r4]
	adds r1, r3, #1
	cmp r0, ip
	bne _08230F20
	adds r5, r1, #0
_08230F20:
	adds r3, r1, #0
	adds r4, #8
	cmp r3, r2
	blt _08230F16
_08230F28:
	ldr r3, [r6]
	lsls r4, r5, #3
	cmp r3, r5
	ble _08230F44
	lsls r0, r3, #3
	adds r2, r0, r6
_08230F34:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	subs r2, #8
	subs r3, #1
	cmp r3, r5
	bgt _08230F34
_08230F44:
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #8
	adds r4, r6, r0
	ldrh r0, [r7]
	movs r1, #0
	strh r0, [r4]
	strb r1, [r4, #2]
	ldrb r0, [r7, #3]
	strb r0, [r4, #3]
	ldr r5, [r7, #4]
	ldr r1, [r6, #4]
	lsls r0, r1, #1
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r2, r6, r0
	str r2, [r4, #4]
	ldrb r0, [r7, #3]
	adds r1, r1, r0
	str r1, [r6, #4]
	movs r3, #0
	b _08230F86
	.align 2, 0
_08230F78: .4byte 0x03000740
_08230F7C:
	ldrh r0, [r5]
	strh r0, [r2]
	adds r5, #2
	adds r2, #2
	adds r3, #1
_08230F86:
	ldrb r0, [r7, #3]
	cmp r3, r0
	blt _08230F7C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08230f94
FUN_08230f94: @ 0x08230F94
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	bl FUN_08230e88
	ldr r1, _08230FBC @ =0x03000740
	ldr r1, [r1]
	movs r2, #1
	subs r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r5, r0, r1
	adds r1, r5, #0
	adds r1, #8
	movs r3, #0
	b _08230FF2
	.align 2, 0
_08230FBC: .4byte 0x03000740
_08230FC0:
	ldrh r0, [r1]
	cmp r0, r6
	bne _08230FEE
	str r1, [r4]
	adds r1, #8
	adds r3, #1
	movs r4, #1
	cmp r3, r2
	bge _08230FEA
	ldrh r0, [r1]
	cmp r0, r6
	bne _08230FEA
	ldr r2, [r5]
_08230FDA:
	adds r3, #1
	adds r4, #1
	adds r1, #8
	cmp r3, r2
	bge _08230FEA
	ldrh r0, [r1]
	cmp r0, r6
	beq _08230FDA
_08230FEA:
	adds r0, r4, #0
	b _08230FFA
_08230FEE:
	adds r3, #1
	adds r1, #8
_08230FF2:
	ldr r2, [r5]
	cmp r3, r2
	blt _08230FC0
	movs r0, #0
_08230FFA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08231000
FUN_08231000: @ 0x08231000
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, [sp, #0xc]
_08231008:
	cmp r3, r1
	bge _08231022
	adds r0, r3, r1
	asrs r2, r0, #1
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r5
	bhs _0823101E
	adds r3, r2, #1
	b _08231008
_0823101E:
	adds r1, r2, #0
	b _08231008
_08231022:
	lsls r0, r3, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, r5
	beq _08231032
	movs r0, #1
	rsbs r0, r0, #0
	b _08231034
_08231032:
	adds r0, r3, #0
_08231034:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823103c
FUN_0823103c: @ 0x0823103C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r0, r2, #0
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	adds r1, r4, #0
	ldm r1!, {r5, r6, r7}
	stm r3!, {r5, r6, r7}
	ldr r1, [r1]
	str r1, [r3]
	ldr r1, [sp, #8]
	adds r1, r1, r4
	str r1, [sp, #8]
	ldr r3, [sp, #0xc]
	adds r3, r3, r4
	str r3, [sp, #0xc]
	ldr r3, [sp, #4]
	subs r3, #1
	str r3, [sp]
	movs r3, #0
	bl FUN_08231000
	adds r1, r0, #0
	cmp r1, #0
	blt _0823107E
	ldr r0, [sp, #4]
	cmp r1, r0
	blo _08231082
_0823107E:
	movs r0, #0
	b _0823108C
_08231082:
	ldr r0, [sp, #0xc]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, r0, r4
_0823108C:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08231094
FUN_08231094: @ 0x08231094
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
_0823109A:
	cmp r2, r3
	bge _082310B4
	adds r0, r2, r3
	asrs r1, r0, #1
	lsls r0, r1, #3
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, r5
	bhs _082310B0
	adds r2, r1, #1
	b _0823109A
_082310B0:
	adds r3, r1, #0
	b _0823109A
_082310B4:
	lsls r0, r2, #3
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, r5
	beq _082310C2
	movs r0, #0
	b _082310C4
_082310C2:
	ldr r0, [r1, #4]
_082310C4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082310cc
FUN_082310cc: @ 0x082310CC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r6, #0
	adds r7, r1, #0
	ldr r0, _082310F8 @ =0x0000A635
	cmp r4, r0
	beq _08231190
	cmp r4, r0
	bgt _08231118
	ldr r0, _082310FC @ =0x000092B3
	cmp r4, r0
	beq _08231160
	cmp r4, r0
	bgt _08231100
	subs r0, #0x85
	cmp r4, r0
	beq _08231150
	b _082311E6
	.align 2, 0
_082310F8: .4byte 0x0000A635
_082310FC: .4byte 0x000092B3
_08231100:
	ldr r0, _08231110 @ =0x000098F5
	cmp r4, r0
	beq _08231180
	ldr r0, _08231114 @ =0x00009B1B
	cmp r4, r0
	beq _08231170
	b _082311E6
	.align 2, 0
_08231110: .4byte 0x000098F5
_08231114: .4byte 0x00009B1B
_08231118:
	ldr r0, _08231130 @ =0x0000CB05
	cmp r4, r0
	beq _082311C0
	cmp r4, r0
	bgt _0823113C
	ldr r0, _08231134 @ =0x0000AE6C
	cmp r4, r0
	beq _082311A0
	ldr r0, _08231138 @ =0x0000C091
	cmp r4, r0
	beq _082311B0
	b _082311E6
	.align 2, 0
_08231130: .4byte 0x0000CB05
_08231134: .4byte 0x0000AE6C
_08231138: .4byte 0x0000C091
_0823113C:
	ldr r0, _0823114C @ =0x0000CEAA
	cmp r4, r0
	beq _082311E0
	adds r0, #0x45
	cmp r4, r0
	beq _082311D0
	b _082311E6
	.align 2, 0
_0823114C: .4byte 0x0000CEAA
_08231150:
	ldr r4, _08231158 @ =0x00009225
	ldr r1, _0823115C @ =0x00005130
	b _082311E4
	.align 2, 0
_08231158: .4byte 0x00009225
_0823115C: .4byte 0x00005130
_08231160:
	ldr r4, _08231168 @ =0x00009305
	ldr r1, _0823116C @ =0x0000D710
	b _082311E4
	.align 2, 0
_08231168: .4byte 0x00009305
_0823116C: .4byte 0x0000D710
_08231170:
	ldr r4, _08231178 @ =0x00009A65
	ldr r1, _0823117C @ =0x00004679
	b _082311E4
	.align 2, 0
_08231178: .4byte 0x00009A65
_0823117C: .4byte 0x00004679
_08231180:
	ldr r4, _08231188 @ =0x00009B05
	ldr r1, _0823118C @ =0x00002117
	b _082311E4
	.align 2, 0
_08231188: .4byte 0x00009B05
_0823118C: .4byte 0x00002117
_08231190:
	ldr r4, _08231198 @ =0x0000A705
	ldr r1, _0823119C @ =0x00006D24
	b _082311E4
	.align 2, 0
_08231198: .4byte 0x0000A705
_0823119C: .4byte 0x00006D24
_082311A0:
	ldr r4, _082311A8 @ =0x0000AF05
	ldr r1, _082311AC @ =0x0000AC2C
	b _082311E4
	.align 2, 0
_082311A8: .4byte 0x0000AF05
_082311AC: .4byte 0x0000AC2C
_082311B0:
	ldr r4, _082311B8 @ =0x0000C305
	ldr r1, _082311BC @ =0x0000E53E
	b _082311E4
	.align 2, 0
_082311B8: .4byte 0x0000C305
_082311BC: .4byte 0x0000E53E
_082311C0:
	ldr r4, _082311C8 @ =0x0000C8E5
	ldr r1, _082311CC @ =0x00005F29
	b _082311E4
	.align 2, 0
_082311C8: .4byte 0x0000C8E5
_082311CC: .4byte 0x00005F29
_082311D0:
	ldr r4, _082311D8 @ =0x0000CEE5
	ldr r1, _082311DC @ =0x00004F2D
	b _082311E4
	.align 2, 0
_082311D8: .4byte 0x0000CEE5
_082311DC: .4byte 0x00004F2D
_082311E0:
	ldr r4, _0823120C @ =0x0000CF05
	ldr r1, _08231210 @ =0x00000A4D
_082311E4:
	movs r6, #1
_082311E6:
	lsls r5, r4, #0x10
	orrs r5, r1
	ldr r1, _08231214 @ =0x085B0D90
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0xa
	bl FUN_08231094
	cmp r6, #1
	bne _08231206
	adds r2, r7, #0
	lsls r3, r5, #0x10
	lsrs r3, r3, #0x10
	adds r1, r4, #0
	bl FUN_0823103c
_08231206:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823120C: .4byte 0x0000CF05
_08231210: .4byte 0x00000A4D
_08231214: .4byte 0x085B0D90

	thumb_func_start ReadScriptOffset
ReadScriptOffset: @ 0x08231218
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrb r0, [r2]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0xe
	beq _08231240
	cmp r1, #0xe
	bgt _08231232
	cmp r1, #0xd
	beq _08231238
	b _08231264
_08231232:
	cmp r1, #0xf
	beq _0823124E
	b _08231264
_08231238:
	ldrb r0, [r2, #1]
	str r0, [r3]
	adds r0, r2, #2
	b _08231268
_08231240:
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	ldrb r1, [r2, #1]
	orrs r1, r0
	str r1, [r3]
	adds r0, r2, #3
	b _08231268
_0823124E:
	adds r0, r2, #1
	ldrb r1, [r0, #2]
	lsls r1, r1, #0x10
	ldrb r0, [r0, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #1]
	orrs r1, r0
	str r1, [r3]
	adds r0, r2, #4
	b _08231268
_08231264:
	str r1, [r3]
	adds r0, r2, #1
_08231268:
	pop {r1}
	bx r1

	thumb_func_start FUN_0823126c
FUN_0823126c: @ 0x0823126C
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08231284
	ldrb r0, [r2]
	str r0, [r3]
	adds r0, r2, #1
	b _08231294
_08231284:
	ldrb r1, [r2, #1]
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	ldr r1, _08231298 @ =0x00007FFF
	ands r0, r1
	str r0, [r3]
	adds r0, r2, #2
_08231294:
	pop {r1}
	bx r1
	.align 2, 0
_08231298: .4byte 0x00007FFF

	thumb_func_start VM_Step
VM_Step: @ 0x0823129C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r3, #0
	ldrb r2, [r4]
	movs r1, #0xf0
	ands r1, r2
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0xc0
	bne _082312C6
	movs r0, #9
	str r0, [r6]
	ldrb r0, [r4]
	movs r1, #0xc1
	rsbs r1, r1, #0
	ands r0, r1
	subs r0, #1
	b _0823135C
_082312C6:
	cmp r1, #0
	bne _08231382
	str r2, [r6]
	adds r4, #1
	cmp r2, #0xe
	bls _082312D4
	b _0823142E
_082312D4:
	lsls r0, r2, #2
	ldr r1, _082312E0 @ =_082312E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082312E0: .4byte _082312E4
_082312E4: @ jump table
	.4byte _08231320 @ case 0
	.4byte _08231324 @ case 1
	.4byte _0823135A @ case 2
	.4byte _0823135A @ case 3
	.4byte _0823135A @ case 4
	.4byte _0823142E @ case 5
	.4byte _0823134C @ case 6
	.4byte _08231362 @ case 7
	.4byte _08231324 @ case 8
	.4byte _08231332 @ case 9
	.4byte _08231332 @ case 10
	.4byte _0823142E @ case 11
	.4byte _0823142E @ case 12
	.4byte _08231332 @ case 13
	.4byte _0823136C @ case 14
_08231320:
	movs r4, #0
	b _0823142E
_08231324:
	ldrb r1, [r4, #1]
	lsls r1, r1, #8
	ldrb r0, [r4]
	orrs r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _08231354
_08231332:
	ldrb r1, [r4, #3]
	lsls r1, r1, #0x18
	ldrb r0, [r4, #2]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r4]
	orrs r1, r0
	str r1, [r5]
	adds r4, #4
	b _0823142E
_0823134C:
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	ldrb r1, [r4]
	orrs r0, r1
_08231354:
	str r0, [r5]
	adds r4, #2
	b _0823142E
_0823135A:
	ldrb r0, [r4]
_0823135C:
	str r0, [r5]
	adds r4, #1
	b _0823142E
_08231362:
	adds r0, r4, #1
	str r0, [r5]
	ldrb r0, [r4]
	adds r0, #1
	b _0823142C
_0823136C:
	ldrb r1, [r4, #1]
	lsls r1, r1, #8
	ldrb r0, [r4]
	orrs r0, r1
	bl FUN_08231978
	str r0, [r5]
	movs r0, #7
	str r0, [r6]
	adds r4, #2
	b _0823142E
_08231382:
	str r1, [r6]
	cmp r1, #0x40
	beq _082313C0
	cmp r1, #0x40
	bgt _082313A0
	cmp r1, #0x20
	beq _082313B4
	cmp r1, #0x20
	bgt _0823139A
	cmp r1, #0x10
	beq _082313B4
	b _0823142E
_0823139A:
	cmp r1, #0x30
	beq _08231402
	b _0823142E
_082313A0:
	cmp r1, #0x80
	beq _082313F4
	cmp r1, #0x80
	bgt _082313AE
	cmp r1, #0x50
	beq _08231412
	b _0823142E
_082313AE:
	cmp r1, #0x90
	beq _082313E0
	b _0823142E
_082313B4:
	adds r0, r3, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl ReadMemory
	b _08231430
_082313C0:
	ldrb r0, [r4]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0xf
	bne _082313D8
	ldrb r0, [r4, #1]
	adds r0, #0xf
	bl VM_ParseParameter
	str r0, [r5]
	adds r4, #1
	b _082313EC
_082313D8:
	adds r0, r1, #0
	bl VM_ParseParameter
	b _082313EA
_082313E0:
	ldrb r1, [r4]
	movs r0, #0xf
	ands r0, r1
	bl ParseInstructionVariable
_082313EA:
	str r0, [r5]
_082313EC:
	movs r0, #9
	str r0, [r6]
	adds r4, #1
	b _0823142E
_082313F4:
	adds r0, r4, #0
	mov r1, sp
	bl ReadScriptOffset
	adds r4, r0, #0
	str r4, [r5]
	b _0823142A
_08231402:
	adds r0, r4, #0
	mov r1, sp
	bl ReadScriptOffset
	adds r4, r0, #0
	bl FUN_08232600
	b _08231428
_08231412:
	adds r0, r4, #0
	mov r1, sp
	bl ReadScriptOffset
	adds r4, r0, #0
	ldrb r1, [r4]
	lsls r1, r1, #0x10
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #1
_08231428:
	str r0, [r5]
_0823142A:
	ldr r0, [sp]
_0823142C:
	adds r4, r4, r0
_0823142E:
	adds r0, r4, #0
_08231430:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08231438
FUN_08231438: @ 0x08231438
	ldr r1, _08231444 @ =0x030045A0
	adds r0, r1, #0
	adds r0, #0x70
	str r0, [r1, #0x6c]
	bx lr
	.align 2, 0
_08231444: .4byte 0x030045A0

	thumb_func_start FUN_08231448
FUN_08231448: @ 0x08231448
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r3, #0
	beq _08231464
	ldr r1, _08231460 @ =0x030045A0
	ldr r0, [r1, #0x6c]
	lsls r2, r2, #2
	adds r2, r0, r2
	stm r2!, {r3}
	str r2, [r1, #0x6c]
	b _08231466
	.align 2, 0
_08231460: .4byte 0x030045A0
_08231464:
	movs r0, #0
_08231466:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823146c
FUN_0823146c: @ 0x0823146C
	push {lr}
	adds r1, r0, #0
	cmp r1, #0
	beq _08231478
	ldr r0, _0823147C @ =0x030045A0
	str r1, [r0, #0x6c]
_08231478:
	pop {r0}
	bx r0
	.align 2, 0
_0823147C: .4byte 0x030045A0

	thumb_func_start VM_ParseParameter
VM_ParseParameter: @ 0x08231480
	push {lr}
	adds r2, r0, #0
	cmp r2, #0
	beq _082314A0
	ldr r0, _0823149C @ =0x030045A0
	ldr r0, [r0, #0x6c]
	subs r0, #4
	ldr r0, [r0]
	ldr r1, [r0, #4]
	lsls r0, r2, #2
	adds r0, r0, r1
	subs r0, #4
	ldr r0, [r0]
	b _082314A4
	.align 2, 0
_0823149C: .4byte 0x030045A0
_082314A0:
	ldr r0, _082314A8 @ =0x030045A0
	ldr r0, [r0, #4]
_082314A4:
	pop {r1}
	bx r1
	.align 2, 0
_082314A8: .4byte 0x030045A0

	thumb_func_start ParseInstructionVariable
ParseInstructionVariable: @ 0x082314AC
	ldr r1, _082314BC @ =0x030045A0
	lsls r0, r0, #2
	adds r0, #4
	ldr r1, [r1, #0x6c]
	subs r1, r1, r0
	ldr r0, [r1]
	bx lr
	.align 2, 0
_082314BC: .4byte 0x030045A0

	thumb_func_start FUN_082314c0
FUN_082314c0: @ 0x082314C0
	ldr r2, _082314D0 @ =0x030045A0
	lsls r0, r0, #2
	adds r0, #4
	ldr r2, [r2, #0x6c]
	subs r2, r2, r0
	str r1, [r2]
	bx lr
	.align 2, 0
_082314D0: .4byte 0x030045A0

	thumb_func_start FUN_082314d4
FUN_082314d4: @ 0x082314D4
	ldr r1, _082314E0 @ =0x030045A0
	adds r0, r1, #0
	adds r0, #0xc
	str r0, [r1, #8]
	bx lr
	.align 2, 0
_082314E0: .4byte 0x030045A0

	thumb_func_start FUN_082314e4
FUN_082314e4: @ 0x082314E4
	ldr r2, _082314F0 @ =0x030045A0
	ldr r1, [r2, #8]
	stm r1!, {r0}
	str r1, [r2, #8]
	bx lr
	.align 2, 0
_082314F0: .4byte 0x030045A0

	thumb_func_start FUN_082314f4
FUN_082314f4: @ 0x082314F4
	ldr r1, _08231500 @ =0x030045A0
	ldr r0, [r1, #8]
	subs r0, #4
	str r0, [r1, #8]
	bx lr
	.align 2, 0
_08231500: .4byte 0x030045A0

	thumb_func_start FUN_08231504
FUN_08231504: @ 0x08231504
	ldr r1, _0823150C @ =0x030045A0
	str r0, [r1]
	bx lr
	.align 2, 0
_0823150C: .4byte 0x030045A0

	thumb_func_start prepare_08231510
prepare_08231510: @ 0x08231510
	push {r4, r5, r6, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _0823154C @ =0x030045A0
	ldr r0, [r1, #8]
	subs r0, #4
	ldr r2, [r0]
	add r4, sp, #4
	adds r6, r1, #0
_08231524:
	adds r0, r2, #0
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	adds r2, r0, #0
	ldr r1, [sp]
	cmp r1, #0
	beq _08231550
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x50
	bne _08231524
	asrs r0, r1, #0x10
	cmp r0, r5
	bne _08231524
	ldr r0, [sp, #4]
	str r0, [r6]
	b _08231552
	.align 2, 0
_0823154C: .4byte 0x030045A0
_08231550:
	movs r0, #0
_08231552:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823155c
FUN_0823155c: @ 0x0823155C
	push {r4, lr}
	sub sp, #8
	ldr r0, _08231594 @ =0x030045A0
	ldr r1, [r0]
	cmp r1, #0
	beq _08231598
	ldrb r0, [r1]
	cmp r0, #0
	beq _08231598
	add r4, sp, #4
_08231570:
	adds r0, r1, #0
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	adds r1, r0, #0
	ldr r2, [sp]
	cmp r2, #0
	beq _08231598
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0x50
	bne _08231570
	ldr r0, _08231594 @ =0x030045A0
	ldr r1, [sp, #4]
	str r1, [r0]
	asrs r0, r2, #0x10
	b _0823159A
	.align 2, 0
_08231594: .4byte 0x030045A0
_08231598:
	movs r0, #0
_0823159A:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082315a4
FUN_082315a4: @ 0x082315A4
	push {lr}
	sub sp, #8
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	ldr r1, _082315BC @ =0x030045A0
	str r0, [r1]
	ldr r0, [sp, #4]
	add sp, #8
	pop {r1}
	bx r1
	.align 2, 0
_082315BC: .4byte 0x030045A0

	thumb_func_start FUN_082315c0
FUN_082315c0: @ 0x082315C0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r2, r0, #0
	add r5, sp, #4
	adds r6, r1, #0
	movs r4, #2
_082315CC:
	adds r0, r2, #0
	mov r1, sp
	adds r2, r5, #0
	bl VM_Step
	adds r2, r0, #0
	ldr r0, [sp, #4]
	stm r6!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _082315CC
	ldr r0, _082315F0 @ =0x030045A0
	str r2, [r0]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_082315F0: .4byte 0x030045A0

	thumb_func_start FUN_082315f4
FUN_082315f4: @ 0x082315F4
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r2, r0, #0
	add r6, sp, #4
	adds r4, r1, #0
	movs r5, #2
_08231600:
	adds r0, r2, #0
	mov r1, sp
	adds r2, r6, #0
	bl VM_Step
	adds r2, r0, #0
	ldr r0, [sp, #4]
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _08231600
	ldr r0, _08231628 @ =0x030045A0
	str r2, [r0]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08231628: .4byte 0x030045A0

	thumb_func_start FUN_0823162c
FUN_0823162c: @ 0x0823162C
	push {lr}
	sub sp, #8
	cmp r0, #0
	beq _0823164C
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	ldr r1, _08231648 @ =0x030045A0
	str r0, [r1]
	cmp r0, #0
	beq _0823164C
	ldr r0, [sp, #4]
	b _0823164E
	.align 2, 0
_08231648: .4byte 0x030045A0
_0823164C:
	movs r0, #0
_0823164E:
	add sp, #8
	pop {r1}
	bx r1

	thumb_func_start FUN_08231654
FUN_08231654: @ 0x08231654
	push {lr}
	bl FUN_0823162c
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08231660
FUN_08231660: @ 0x08231660
	adds r2, r0, #0
	ldrb r1, [r2, #2]
	lsls r1, r1, #8
	ldrb r0, [r2, #1]
	orrs r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, _08231678 @ =0x030045A0
	adds r2, #3
	str r2, [r1]
	bx lr
	.align 2, 0
_08231678: .4byte 0x030045A0

	thumb_func_start FUN_0823167c
FUN_0823167c: @ 0x0823167C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_082316bc
	adds r1, r4, #0
	bl FUN_0823201c
	ldr r1, _08231694 @ =0x030045A0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08231694: .4byte 0x030045A0

	thumb_func_start FUN_08231698
FUN_08231698: @ 0x08231698
	push {r4, r5, lr}
	sub sp, #8
	add r4, sp, #4
	ldr r5, _082316B8 @ =0x030045A0
_082316A0:
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	ldr r1, [sp]
	cmp r1, #0
	bne _082316A0
	str r1, [r5]
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_082316B8: .4byte 0x030045A0

	thumb_func_start FUN_082316bc
FUN_082316bc: @ 0x082316BC
	push {lr}
	ldr r0, _082316D8 @ =0x030045A0
	ldr r1, [r0]
	cmp r1, #0
	beq _082316D4
	ldrb r2, [r1]
	cmp r2, #0
	beq _082316D4
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0x50
	bne _082316DC
_082316D4:
	movs r0, #0
	b _082316DE
	.align 2, 0
_082316D8: .4byte 0x030045A0
_082316DC:
	adds r0, r1, #0
_082316DE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start fetch_082316e4
fetch_082316e4: @ 0x082316E4
	push {lr}
	bl FUN_082316bc
	bl FUN_082315a4
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082316f4
FUN_082316f4: @ 0x082316F4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_082316bc
	adds r1, r4, #0
	bl FUN_082315c0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08231708
FUN_08231708: @ 0x08231708
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_082316bc
	adds r1, r4, #0
	bl FUN_082315f4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823171c
FUN_0823171c: @ 0x0823171C
	push {lr}
	bl FUN_082316bc
	bl FUN_0823162c
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823172c
FUN_0823172c: @ 0x0823172C
	push {lr}
	bl FUN_082316bc
	bl FUN_0823162c
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823173c
FUN_0823173c: @ 0x0823173C
	push {lr}
	bl FUN_082316bc
	bl FUN_08231660
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823174c
FUN_0823174c: @ 0x0823174C
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl prepare_08231510
	cmp r0, #0
	bne _08231760
	adds r0, r4, #0
	b _08231768
_08231760:
	bl FUN_082316bc
	bl FUN_082315a4
_08231768:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08231770
FUN_08231770: @ 0x08231770
	push {lr}
	bl FUN_08231438
	bl FUN_082314d4
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08231780
FUN_08231780: @ 0x08231780
	ldr r1, _08231788 @ =0x03000768
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08231788: .4byte 0x03000768

	thumb_func_start FUN_0823178c
FUN_0823178c: @ 0x0823178C
	ldr r2, _08231798 @ =0x03000768
	ldr r1, [r2]
	str r1, [r0]
	str r0, [r2]
	movs r0, #0
	bx lr
	.align 2, 0
_08231798: .4byte 0x03000768

	thumb_func_start FUN_0823179c
FUN_0823179c: @ 0x0823179C
	push {lr}
	adds r2, r0, #0
	ldr r1, _082317C0 @ =0x03000768
	ldr r0, [r1]
	cmp r0, r2
	bne _082317AC
	ldr r0, [r2]
	str r0, [r1]
_082317AC:
	ldr r0, [r1]
	adds r1, r0, #0
	cmp r0, #0
	beq _082317CC
_082317B4:
	cmp r0, r2
	bne _082317C4
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0
	b _082317D0
	.align 2, 0
_082317C0: .4byte 0x03000768
_082317C4:
	adds r1, r0, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _082317B4
_082317CC:
	movs r0, #1
	rsbs r0, r0, #0
_082317D0:
	pop {r1}
	bx r1

	thumb_func_start FUN_082317d4
FUN_082317d4: @ 0x082317D4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _082317F4 @ =0x03000768
	ldr r3, [r0]
	cmp r3, #0
	beq _08231806
_082317E0:
	ldr r2, [r3, #8]
	ldr r1, [r3, #4]
	cmp r1, #0
	ble _08231800
_082317E8:
	ldr r0, [r2]
	cmp r0, r4
	bne _082317F8
	adds r0, r2, #0
	b _08231808
	.align 2, 0
_082317F4: .4byte 0x03000768
_082317F8:
	adds r2, #8
	subs r1, #1
	cmp r1, #0
	bgt _082317E8
_08231800:
	ldr r3, [r3]
	cmp r3, #0
	bne _082317E0
_08231806:
	movs r0, #0
_08231808:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08231810
FUN_08231810: @ 0x08231810
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	ldrb r1, [r4]
	orrs r0, r1
	adds r4, #2
	bl FUN_082317d4
	adds r5, r0, #0
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0823126c
	adds r4, r0, #0
	ldr r0, [sp]
	adds r0, r4, r0
	bl FUN_082314e4
	adds r0, r4, #0
	bl FUN_08231504
	ldr r1, [r5, #4]
	adds r0, r4, #0
	bl _call_via_r1
	adds r4, r0, #0
	bl FUN_082314f4
	adds r0, r4, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08231858
FUN_08231858: @ 0x08231858
	push {r4, lr}
	adds r4, r1, #0
	movs r3, #0
	adds r2, r0, #0
	ldr r0, [r2]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _08231874
_0823186A:
	adds r2, #4
	adds r3, #1
	ldr r0, [r2]
	cmp r0, r1
	bne _0823186A
_08231874:
	str r3, [r4]
	adds r0, r2, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08231880
FUN_08231880: @ 0x08231880
	ldr r2, _082318A0 @ =0x7FFFFFFF
	ands r2, r0
	subs r2, #1
	ldr r3, _082318A4 @ =0x03000748
	lsls r2, r2, #2
	ldr r0, [r3]
	adds r0, r0, r2
	ldrb r2, [r0, #3]
	str r2, [r1]
	ldr r1, [r0]
	ldr r0, _082318A8 @ =0x00FFFFFF
	ands r1, r0
	ldr r0, [r3, #8]
	adds r0, r0, r1
	bx lr
	.align 2, 0
_082318A0: .4byte 0x7FFFFFFF
_082318A4: .4byte 0x03000748
_082318A8: .4byte 0x00FFFFFF

	thumb_func_start FUN_082318ac
FUN_082318ac: @ 0x082318AC
	push {r4, lr}
	sub sp, #8
	adds r4, r1, #0
	mov r1, sp
	bl FUN_08231880
	add r1, sp, #4
	bl ReadScriptOffset
	ldr r2, [sp]
	adds r1, r4, #0
	bl FUN_08231b7c
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082318d0
FUN_082318d0: @ 0x082318D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x50
	adds r2, r0, #0
	ldrb r1, [r2, #1]
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	adds r2, #2
	movs r4, #0
	add r6, sp, #0x40
	add r5, sp, #0x44
	add r7, sp, #0x48
	b _08231900
_082318F4:
	lsls r0, r4, #2
	mov r3, sp
	adds r1, r3, r0
	ldr r0, [sp, #0x44]
	str r0, [r1]
	adds r4, #1
_08231900:
	adds r0, r2, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl VM_Step
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	cmp r0, #0
	bne _082318F4
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08231938 @ =0xFFFF0000
	ldr r0, [sp, #0x48]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x48]
	mov r0, sp
	str r0, [r7, #4]
	mov r0, r8
	adds r1, r7, #0
	bl FUN_082318ac
	add sp, #0x50
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08231938: .4byte 0xFFFF0000

	thumb_func_start FUN_0823193c
FUN_0823193c: @ 0x0823193C
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r0, #0
	movs r1, #0
	subs r2, #1
_08231946:
	cmp r1, r2
	bge _08231960
	adds r0, r1, r2
	asrs r3, r0, #1
	lsls r0, r3, #3
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, r5
	bhs _0823195C
	adds r1, r3, #1
	b _08231946
_0823195C:
	adds r2, r3, #0
	b _08231946
_08231960:
	lsls r0, r1, #3
	adds r2, r0, r4
	ldr r0, [r2]
	cmp r0, r5
	beq _0823196E
	movs r0, #0
	b _08231970
_0823196E:
	adds r0, r2, #0
_08231970:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08231978
FUN_08231978: @ 0x08231978
	ldr r3, _082319A0 @ =0x03000758
	lsls r0, r0, #2
	ldr r1, [r3, #4]
	adds r0, r0, r1
	ldrb r2, [r0, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r0, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r0, [r0]
	orrs r2, r0
	ldr r0, _082319A4 @ =0x7FFFFFFF
	ands r2, r0
	ldr r0, [r3, #8]
	adds r0, r0, r2
	bx lr
	.align 2, 0
_082319A0: .4byte 0x03000758
_082319A4: .4byte 0x7FFFFFFF

	thumb_func_start FUN_082319a8
FUN_082319a8: @ 0x082319A8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, _08231A68 @ =0x03000748
	ldrb r1, [r4, #3]
	lsls r1, r1, #0x18
	ldrb r0, [r4, #2]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r4]
	orrs r1, r0
	ldr r0, _08231A6C @ =0x03004594
	str r1, [r0]
	adds r4, #4
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08231858
	str r4, [r5]
	ldr r1, [sp]
	str r1, [r5, #4]
	ldr r4, _08231A70 @ =0x03000758
	str r0, [r4]
	adds r3, r0, #4
	ldrb r2, [r3, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r3, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r3, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0, #4]
	orrs r2, r1
	adds r2, r0, r2
	str r2, [r4, #4]
	adds r3, #4
	ldrb r2, [r3, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r3, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r3, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0, #8]
	orrs r2, r1
	adds r2, r0, r2
	str r2, [r4, #8]
	adds r3, #4
	ldrb r2, [r3, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r3, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r3, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0, #0xc]
	orrs r2, r1
	adds r2, r0, r2
	str r2, [r4, #0xc]
	ldrb r2, [r0, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r0, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0]
	orrs r2, r1
	adds r0, r0, r2
	adds r1, r0, #4
	str r1, [r5, #8]
	ldrb r2, [r0, #3]
	lsls r2, r2, #0x18
	ldrb r1, [r0, #2]
	lsls r1, r1, #0x10
	orrs r2, r1
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	orrs r2, r1
	ldrb r1, [r0]
	orrs r2, r1
	adds r2, r2, r0
	adds r2, #8
	str r2, [r5, #0xc]
	movs r0, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08231A68: .4byte 0x03000748
_08231A6C: .4byte 0x03004594
_08231A70: .4byte 0x03000758
_08231A74:
	.byte 0x01, 0x48, 0xC0, 0x68, 0x04, 0x30, 0x70, 0x47, 0x58, 0x07, 0x00, 0x03
	.byte 0x30, 0xB5, 0x02, 0x1C, 0x06, 0x49, 0x38, 0xC9, 0x38, 0xC2, 0x09, 0x68, 0x11, 0x60, 0x10, 0x30
	.byte 0x04, 0x49, 0x1C, 0xC9, 0x1C, 0xC0, 0x09, 0x68, 0x01, 0x60, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0x48, 0x07, 0x00, 0x03, 0x58, 0x07, 0x00, 0x03, 0x30, 0xB5, 0x07, 0x4A, 0x01, 0x1C, 0x38, 0xC9
	.byte 0x38, 0xC2, 0x09, 0x68, 0x11, 0x60, 0x05, 0x49, 0x10, 0x30, 0x1C, 0xC8, 0x1C, 0xC1, 0x00, 0x68
	.byte 0x08, 0x60, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x48, 0x07, 0x00, 0x03, 0x58, 0x07, 0x00, 0x03

	thumb_func_start FUN_08231ad0
FUN_08231ad0: @ 0x08231AD0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	bl FUN_08231448
	adds r5, r0, #0
_08231AE0:
	cmp r4, #0
	beq _08231B44
	ldrb r0, [r4]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0x60
	beq _08231B02
	cmp r1, #0x60
	bgt _08231AFC
	cmp r1, #0
	beq _08231B44
	cmp r1, #0x30
	beq _08231B28
	b _08231AE0
_08231AFC:
	cmp r1, #0x70
	beq _08231B18
	b _08231AE0
_08231B02:
	adds r0, r4, #0
	mov r1, sp
	bl ReadScriptOffset
	adds r4, r0, #0
	bl FUN_08231810
	cmp r0, #1
	bne _08231B3A
	movs r4, #1
	b _08231B46
_08231B18:
	adds r0, r4, #0
	mov r1, sp
	bl ReadScriptOffset
	adds r4, r0, #0
	bl FUN_082318d0
	b _08231B36
_08231B28:
	adds r0, r4, #0
	mov r1, sp
	bl ReadScriptOffset
	adds r4, r0, #0
	bl FUN_08232600
_08231B36:
	ldr r1, _08231B40 @ =0x030045A0
	str r0, [r1, #4]
_08231B3A:
	ldr r0, [sp]
	adds r4, r4, r0
	b _08231AE0
	.align 2, 0
_08231B40: .4byte 0x030045A0
_08231B44:
	movs r4, #0
_08231B46:
	adds r0, r5, #0
	bl FUN_0823146c
	adds r0, r4, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08231b58
FUN_08231b58: @ 0x08231B58
	push {lr}
	movs r2, #0
	bl FUN_08231ad0
	cmp r0, #1
	beq _08231B70
	ldr r1, _08231B6C @ =0x030045A0
	movs r0, #0
	str r0, [r1, #4]
	b _08231B74
	.align 2, 0
_08231B6C: .4byte 0x030045A0
_08231B70:
	ldr r0, _08231B78 @ =0x030045A0
	ldr r0, [r0, #4]
_08231B74:
	pop {r1}
	bx r1
	.align 2, 0
_08231B78: .4byte 0x030045A0

	thumb_func_start FUN_08231b7c
FUN_08231b7c: @ 0x08231B7C
	push {lr}
	cmp r1, #0
	bne _08231B84
	ldr r1, _08231B94 @ =0x085B01C8
_08231B84:
	bl FUN_08231ad0
	cmp r0, #1
	beq _08231B9C
	ldr r1, _08231B98 @ =0x030045A0
	movs r0, #0
	str r0, [r1, #4]
	b _08231BA0
	.align 2, 0
_08231B94: .4byte 0x085B01C8
_08231B98: .4byte 0x030045A0
_08231B9C:
	ldr r0, _08231BA4 @ =0x030045A0
	ldr r0, [r0, #4]
_08231BA0:
	pop {r1}
	bx r1
	.align 2, 0
_08231BA4: .4byte 0x030045A0

	thumb_func_start FUN_08231ba8
FUN_08231ba8: @ 0x08231BA8
	push {lr}
	sub sp, #4
	ldr r0, _08231BC4 @ =0x03000748
	ldr r0, [r0, #0xc]
	mov r1, sp
	bl ReadScriptOffset
	ldr r1, _08231BC8 @ =0x085B01C8
	bl FUN_08231b58
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08231BC4: .4byte 0x03000748
_08231BC8: .4byte 0x085B01C8

	thumb_func_start FUN_08231bcc
FUN_08231bcc: @ 0x08231BCC
	push {lr}
	bl fetch_082316e4
	cmp r0, #0
	bne _08231BDA
	bl FUN_0823171c
_08231BDA:
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08231be0
FUN_08231be0: @ 0x08231BE0
	ldr r1, _08231BE8 @ =0x03002B28
	strh r0, [r1]
	bx lr
	.align 2, 0
_08231BE8: .4byte 0x03002B28

	thumb_func_start FUN_08231bec
FUN_08231bec: @ 0x08231BEC
	push {lr}
	bl FUN_08231770
	bl FUN_08231c80
	bl FUN_08231780
	bl FUN_082324b0
	ldr r0, _08231C14 @ =0x0000A8D9
	ldr r1, _08231C18 @ =0x0000A41E
	bl FUN_082310cc
	bl FUN_082319a8
	movs r0, #0
	bl FUN_08231be0
	pop {r0}
	bx r0
	.align 2, 0
_08231C14: .4byte 0x0000A8D9
_08231C18: .4byte 0x0000A41E

	thumb_func_start FUN_08231c1c
FUN_08231c1c: @ 0x08231C1C
	push {lr}
	bl FUN_08231d98
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08231c28
FUN_08231c28: @ 0x08231C28
	ldr r0, _08231C64 @ =0x0400010C
	ldrh r2, [r0]
	ldr r1, _08231C68 @ =0x0203C400
	movs r0, #0x7f
	ands r0, r2
	lsls r0, r0, #3
	adds r1, r0, r1
	ldr r0, _08231C6C @ =0x030046A0
	str r1, [r0]
	ldr r2, _08231C70 @ =0x0300469C
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r0, r1, r3
	str r0, [r2]
	ldr r2, _08231C74 @ =0x03004698
	movs r3, #0xb0
	lsls r3, r3, #5
	adds r0, r1, r3
	str r0, [r2]
	ldr r2, _08231C78 @ =0x03004694
	movs r3, #0xd0
	lsls r3, r3, #5
	adds r0, r1, r3
	str r0, [r2]
	ldr r0, _08231C7C @ =0x03004690
	movs r2, #0xf0
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_08231C64: .4byte 0x0400010C
_08231C68: .4byte 0x0203C400
_08231C6C: .4byte 0x030046A0
_08231C70: .4byte 0x0300469C
_08231C74: .4byte 0x03004698
_08231C78: .4byte 0x03004694
_08231C7C: .4byte 0x03004690

	thumb_func_start FUN_08231c80
FUN_08231c80: @ 0x08231C80
	push {lr}
	ldr r0, _08231C9C @ =0x03004698
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	bl FUN_082309cc
	ldr r0, _08231CA0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08231CA4 @ =0x00000958
	bl FUN_082309cc
	pop {r0}
	bx r0
	.align 2, 0
_08231C9C: .4byte 0x03004698
_08231CA0: .4byte 0x030046A0
_08231CA4: .4byte 0x00000958

	thumb_func_start FUN_08231ca8
FUN_08231ca8: @ 0x08231CA8
	push {r4, r5, r6, lr}
	ldr r4, _08231CDC @ =0x030046A0
	ldr r0, [r4]
	ldr r5, _08231CE0 @ =0x00000246
	adds r0, r0, r5
	ldrh r6, [r0]
	ldr r0, _08231CE4 @ =0x03004698
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	bl FUN_082309cc
	ldr r0, [r4]
	adds r0, #0x30
	ldr r1, _08231CE8 @ =0x0000038A
	bl FUN_082309cc
	ldr r0, [r4]
	adds r0, r0, r5
	strh r6, [r0]
	bl FUN_08231cec
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08231CDC: .4byte 0x030046A0
_08231CE0: .4byte 0x00000246
_08231CE4: .4byte 0x03004698
_08231CE8: .4byte 0x0000038A

	thumb_func_start FUN_08231cec
FUN_08231cec: @ 0x08231CEC
	push {lr}
	ldr r0, _08231D10 @ =0x0300469C
	ldr r0, [r0]
	ldr r1, _08231D14 @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _08231D18 @ =0x00000958
	bl FUN_08230ab0
	ldr r0, _08231D1C @ =0x03004694
	ldr r0, [r0]
	ldr r1, _08231D20 @ =0x03004698
	ldr r1, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_08230ab0
	pop {r0}
	bx r0
	.align 2, 0
_08231D10: .4byte 0x0300469C
_08231D14: .4byte 0x030046A0
_08231D18: .4byte 0x00000958
_08231D1C: .4byte 0x03004694
_08231D20: .4byte 0x03004698

	thumb_func_start FUN_08231d24
FUN_08231d24: @ 0x08231D24
	push {lr}
	ldr r0, _08231D48 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08231D4C @ =0x0300469C
	ldr r1, [r1]
	ldr r2, _08231D50 @ =0x00000958
	bl FUN_08230ab0
	ldr r0, _08231D54 @ =0x03004698
	ldr r0, [r0]
	ldr r1, _08231D58 @ =0x03004694
	ldr r1, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_08230ab0
	pop {r0}
	bx r0
	.align 2, 0
_08231D48: .4byte 0x030046A0
_08231D4C: .4byte 0x0300469C
_08231D50: .4byte 0x00000958
_08231D54: .4byte 0x03004698
_08231D58: .4byte 0x03004694

	thumb_func_start FUN_08231d5c
FUN_08231d5c: @ 0x08231D5C
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08231D78 @ =0x030046A0
	ldr r1, [r0]
	subs r1, r3, r1
	ldr r0, _08231D7C @ =0x0300469C
	ldr r0, [r0]
	adds r0, r0, r1
	adds r1, r3, #0
	bl FUN_08230ab0
	pop {r0}
	bx r0
	.align 2, 0
_08231D78: .4byte 0x030046A0
_08231D7C: .4byte 0x0300469C

	thumb_func_start FUN_08231d80
FUN_08231d80: @ 0x08231D80
	adds r1, r0, #0
	ldr r0, _08231D90 @ =0x030046A0
	ldr r0, [r0]
	subs r1, r1, r0
	ldr r0, _08231D94 @ =0x0300469C
	ldr r0, [r0]
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08231D90: .4byte 0x030046A0
_08231D94: .4byte 0x0300469C

	thumb_func_start FUN_08231d98
FUN_08231d98: @ 0x08231D98
	push {lr}
	ldr r0, _08231DAC @ =0x03004690
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	bl FUN_082309cc
	pop {r0}
	bx r0
	.align 2, 0
_08231DAC: .4byte 0x03004690

	thumb_func_start FUN_08231db0
FUN_08231db0: @ 0x08231DB0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	asrs r0, r5, #0x18
	movs r1, #0xf
	ands r0, r1
	subs r0, #1
	cmp r0, #8
	bhi _08231E4E
	lsls r0, r0, #2
	ldr r1, _08231DCC @ =_08231DD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08231DCC: .4byte _08231DD0
_08231DD0: @ jump table
	.4byte _08231E1E @ case 0
	.4byte _08231E28 @ case 1
	.4byte _08231E28 @ case 2
	.4byte _08231E2E @ case 3
	.4byte _08231E4E @ case 4
	.4byte _08231E1E @ case 5
	.4byte _08231E4E @ case 6
	.4byte _08231E10 @ case 7
	.4byte _08231DF4 @ case 8
_08231DF4:
	lsls r0, r2, #2
	adds r4, r4, r0
	ldrb r1, [r4, #3]
	lsls r1, r1, #0x18
	ldrb r0, [r4, #2]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r4]
	orrs r1, r0
	str r1, [r3]
	b _08231E4E
_08231E10:
	lsls r0, r2, #2
	adds r4, r4, r0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	ldrb r1, [r4]
	orrs r0, r1
	b _08231E4C
_08231E1E:
	lsls r0, r2, #1
	adds r0, r4, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _08231E4C
_08231E28:
	adds r4, r4, r2
	ldrb r0, [r4]
	b _08231E4C
_08231E2E:
	asrs r0, r5, #0x10
	movs r1, #0xf
	ands r0, r1
	adds r2, r2, r0
	asrs r1, r2, #3
	adds r1, r4, r1
	movs r0, #7
	ands r0, r2
	movs r2, #1
	lsls r2, r0
	ldrb r1, [r1]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
_08231E4C:
	str r0, [r3]
_08231E4E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start ReadMemory
ReadMemory: @ 0x08231E54
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r3, r0, #0
	adds r7, r2, #0
	ldrb r0, [r3]
	lsls r5, r0, #0x18
	ldrb r0, [r3, #1]
	lsls r0, r0, #0x10
	orrs r5, r0
	ldrb r0, [r3, #2]
	lsls r0, r0, #8
	orrs r5, r0
	ldrb r0, [r3, #3]
	orrs r5, r0
	lsrs r0, r5, #0x18
	movs r2, #0xf
	ands r0, r2
	str r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #0x10
	ands r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x10
	cmp r1, r0
	bne _08231E90
	ldr r0, _08231E8C @ =0x030046A0
	b _08231EA2
	.align 2, 0
_08231E8C: .4byte 0x030046A0
_08231E90:
	movs r0, #0x80
	lsls r0, r0, #0xd
	cmp r1, r0
	bne _08231EA0
	ldr r0, _08231E9C @ =0x03004690
	b _08231EA2
	.align 2, 0
_08231E9C: .4byte 0x03004690
_08231EA0:
	ldr r0, _08231ECC @ =0x03004698
_08231EA2:
	ldr r6, [r0]
	ldr r0, _08231ED0 @ =0x0000FFFF
	ands r0, r5
	adds r6, r6, r0
	lsrs r0, r5, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08231ED4
	adds r0, r3, #4
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	adds r4, r0, #0
	add r2, sp, #8
	mov r1, sp
	bl VM_Step
	adds r4, r0, #0
	b _08231EDA
	.align 2, 0
_08231ECC: .4byte 0x03004698
_08231ED0: .4byte 0x0000FFFF
_08231ED4:
	movs r0, #0
	str r0, [sp, #8]
	adds r4, r3, #4
_08231EDA:
	ldr r2, [sp, #8]
	adds r0, r6, #0
	adds r1, r5, #0
	adds r3, r7, #0
	bl FUN_08231db0
	adds r0, r4, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08231ef0
FUN_08231ef0: @ 0x08231EF0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	asrs r0, r5, #0x18
	movs r1, #0xf
	ands r0, r1
	subs r0, #1
	cmp r0, #8
	bhi _08231F80
	lsls r0, r0, #2
	ldr r1, _08231F0C @ =_08231F10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08231F0C: .4byte _08231F10
_08231F10: @ jump table
	.4byte _08231F4C @ case 0
	.4byte _08231F54 @ case 1
	.4byte _08231F54 @ case 2
	.4byte _08231F5A @ case 3
	.4byte _08231F80 @ case 4
	.4byte _08231F4C @ case 5
	.4byte _08231F80 @ case 6
	.4byte _08231F3C @ case 7
	.4byte _08231F34 @ case 8
_08231F34:
	lsls r0, r2, #2
	adds r0, r4, r0
	str r3, [r0]
	b _08231F80
_08231F3C:
	lsls r0, r2, #2
	adds r0, r4, r0
	asrs r1, r3, #0x10
	strb r1, [r0, #2]
	asrs r1, r3, #8
	strb r1, [r0, #1]
	strb r3, [r0]
	b _08231F80
_08231F4C:
	lsls r0, r2, #1
	adds r0, r4, r0
	strh r3, [r0]
	b _08231F80
_08231F54:
	adds r0, r4, r2
	strb r3, [r0]
	b _08231F80
_08231F5A:
	asrs r0, r5, #0x10
	movs r1, #0xf
	ands r0, r1
	adds r2, r2, r0
	asrs r0, r2, #3
	adds r4, r4, r0
	movs r0, #7
	ands r0, r2
	movs r1, #1
	lsls r1, r0
	cmp r3, #0
	beq _08231F7A
	ldrb r0, [r4]
	orrs r1, r0
	strb r1, [r4]
	b _08231F80
_08231F7A:
	ldrb r0, [r4]
	bics r0, r1
	strb r0, [r4]
_08231F80:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08231f88
FUN_08231f88: @ 0x08231F88
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r2, r0, #0
	adds r7, r1, #0
	ldrb r0, [r2]
	lsls r5, r0, #0x18
	ldrb r0, [r2, #1]
	lsls r0, r0, #0x10
	orrs r5, r0
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r5, r0
	ldrb r0, [r2, #3]
	orrs r5, r0
	movs r1, #0xf0
	lsls r1, r1, #0x10
	ands r1, r5
	movs r0, #0x80
	lsls r0, r0, #0x10
	cmp r1, r0
	bne _08231FBC
	ldr r0, _08231FB8 @ =0x030046A0
	b _08231FCE
	.align 2, 0
_08231FB8: .4byte 0x030046A0
_08231FBC:
	movs r0, #0x80
	lsls r0, r0, #0xd
	cmp r1, r0
	bne _08231FCC
	ldr r0, _08231FC8 @ =0x03004690
	b _08231FCE
	.align 2, 0
_08231FC8: .4byte 0x03004690
_08231FCC:
	ldr r0, _08231FF8 @ =0x03004698
_08231FCE:
	ldr r6, [r0]
	ldr r0, _08231FFC @ =0x0000FFFF
	ands r0, r5
	adds r6, r6, r0
	lsrs r0, r5, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08232000
	adds r0, r2, #4
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	adds r4, r0, #0
	add r2, sp, #8
	mov r1, sp
	bl VM_Step
	adds r4, r0, #0
	b _08232006
	.align 2, 0
_08231FF8: .4byte 0x03004698
_08231FFC: .4byte 0x0000FFFF
_08232000:
	movs r0, #0
	str r0, [sp, #8]
	adds r4, r2, #4
_08232006:
	ldr r2, [sp, #8]
	adds r0, r6, #0
	adds r1, r5, #0
	adds r3, r7, #0
	bl FUN_08231ef0
	adds r0, r4, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823201c
FUN_0823201c: @ 0x0823201C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #4
	bl FUN_08230ab0
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08232058
	adds r0, r4, #4
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	adds r3, r0, #0
	add r2, sp, #8
	mov r1, sp
	bl VM_Step
	adds r3, r0, #0
	ldr r0, [sp, #4]
	strh r0, [r5, #4]
	ldr r0, [sp, #8]
	strh r0, [r5, #6]
	b _08232062
_08232058:
	adds r3, r4, #4
	movs r1, #0
	movs r0, #1
	strh r0, [r5, #4]
	strh r1, [r5, #6]
_08232062:
	adds r0, r3, #0
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0823206c
FUN_0823206c: @ 0x0823206C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4]
	lsls r2, r0, #0x18
	ldrb r0, [r4, #1]
	lsls r0, r0, #0x10
	orrs r2, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r4, #3]
	orrs r2, r0
	movs r1, #0xf0
	lsls r1, r1, #0x10
	ands r1, r2
	movs r0, #0x80
	lsls r0, r0, #0x10
	cmp r1, r0
	bne _082320A0
	ldr r0, _0823209C @ =0x030046A0
	b _082320B2
	.align 2, 0
_0823209C: .4byte 0x030046A0
_082320A0:
	movs r0, #0x80
	lsls r0, r0, #0xd
	cmp r1, r0
	bne _082320B0
	ldr r0, _082320AC @ =0x03004690
	b _082320B2
	.align 2, 0
_082320AC: .4byte 0x03004690
_082320B0:
	ldr r0, _082320DC @ =0x03004698
_082320B2:
	ldr r3, [r0]
	ldr r0, _082320E0 @ =0x0000FFFF
	ands r0, r2
	adds r3, r3, r0
	lsrs r0, r2, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _082320C8
	ldrh r0, [r4, #6]
	adds r5, r5, r0
_082320C8:
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_08231ef0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082320DC: .4byte 0x03004698
_082320E0: .4byte 0x0000FFFF

	thumb_func_start FUN_082320e4
FUN_082320e4: @ 0x082320E4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4]
	lsls r3, r0, #0x18
	ldrb r0, [r4, #1]
	lsls r0, r0, #0x10
	orrs r3, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r3, r0
	ldrb r0, [r4, #3]
	orrs r3, r0
	movs r1, #0xf0
	lsls r1, r1, #0x10
	ands r1, r3
	movs r0, #0x80
	lsls r0, r0, #0x10
	cmp r1, r0
	bne _08232118
	ldr r0, _08232114 @ =0x030046A0
	b _0823212A
	.align 2, 0
_08232114: .4byte 0x030046A0
_08232118:
	movs r0, #0x80
	lsls r0, r0, #0xd
	cmp r1, r0
	bne _08232128
	ldr r0, _08232124 @ =0x03004690
	b _0823212A
	.align 2, 0
_08232124: .4byte 0x03004690
_08232128:
	ldr r0, _08232158 @ =0x03004698
_0823212A:
	ldr r2, [r0]
	ldr r0, _0823215C @ =0x0000FFFF
	ands r0, r3
	adds r2, r2, r0
	lsrs r0, r3, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08232140
	ldrh r0, [r4, #6]
	adds r5, r5, r0
_08232140:
	adds r0, r2, #0
	adds r1, r3, #0
	adds r2, r5, #0
	mov r3, sp
	bl FUN_08231db0
	ldr r0, [sp]
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08232158: .4byte 0x03004698
_0823215C: .4byte 0x0000FFFF

	thumb_func_start FUN_08232160
FUN_08232160: @ 0x08232160
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov r4, sp
	movs r5, #0
	mov r1, sp
	bl FUN_0823201c
	adds r7, r0, #0
	mov r0, sp
	movs r1, #0
	bl FUN_082320e4
	adds r6, r0, #0
	mov r0, sp
	ldrb r0, [r0]
	lsls r2, r0, #0x18
	ldrb r0, [r4, #1]
	lsls r0, r0, #0x10
	orrs r2, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r4, #3]
	orrs r2, r0
	movs r0, #0xf0
	lsls r0, r0, #0x10
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #0x10
	cmp r0, r1
	bne _082321A8
	ldr r0, _082321A4 @ =0x0300469C
	b _082321AA
	.align 2, 0
_082321A4: .4byte 0x0300469C
_082321A8:
	ldr r0, _082321D8 @ =0x03004694
_082321AA:
	ldr r3, [r0]
	ldr r0, _082321DC @ =0x0000FFFF
	ands r0, r2
	adds r3, r3, r0
	lsrs r0, r2, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _082321C0
	ldrh r0, [r4, #6]
	adds r5, r5, r0
_082321C0:
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_08231ef0
	adds r0, r7, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082321D8: .4byte 0x03004694
_082321DC: .4byte 0x0000FFFF

	thumb_func_start FUN_082321e0
FUN_082321e0: @ 0x082321E0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	mov r5, sp
	movs r6, #0
	mov r1, sp
	bl FUN_0823201c
	mov r0, sp
	ldrb r0, [r0]
	lsls r2, r0, #0x18
	ldrb r0, [r5, #1]
	lsls r0, r0, #0x10
	orrs r2, r0
	ldrb r0, [r5, #2]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r5, #3]
	orrs r2, r0
	movs r0, #0xf0
	lsls r0, r0, #0x10
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #0x10
	cmp r0, r1
	bne _0823221C
	ldr r0, _08232218 @ =0x0300469C
	b _0823221E
	.align 2, 0
_08232218: .4byte 0x0300469C
_0823221C:
	ldr r0, _0823224C @ =0x03004694
_0823221E:
	ldr r4, [r0]
	ldr r0, _08232250 @ =0x0000FFFF
	ands r0, r2
	adds r4, r4, r0
	lsrs r0, r2, #0x18
	movs r1, #0xf0
	ands r0, r1
	cmp r0, #0x20
	bne _08232234
	ldrh r0, [r5, #6]
	adds r6, r6, r0
_08232234:
	add r3, sp, #8
	adds r0, r4, #0
	adds r1, r2, #0
	adds r2, r6, #0
	bl FUN_08231db0
	ldr r0, [sp, #8]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0823224C: .4byte 0x03004694
_08232250: .4byte 0x0000FFFF

	thumb_func_start FUN_08232254
FUN_08232254: @ 0x08232254
	ldr r0, _0823225C @ =0x0300469C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0823225C: .4byte 0x0300469C

	thumb_func_start FUN_08232260
FUN_08232260: @ 0x08232260
	ldr r0, _08232268 @ =0x03004694
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08232268: .4byte 0x03004694

	thumb_func_start FUN_0823226c
FUN_0823226c: @ 0x0823226C
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r6, r0, #0
	b _082322CC
_08232274:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _082322B8
	ldrb r0, [r5]
	adds r1, r0, #0
	subs r1, #0x80
	ldrb r2, [r5, #1]
	adds r5, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0823229A
	adds r4, r2, #0
	subs r4, #0x61
	cmp r4, #0x7e
	ble _0823229C
	adds r4, #1
	b _0823229C
_0823229A:
	subs r4, r2, #2
_0823229C:
	adds r0, r1, #0
	subs r0, #0x21
	movs r1, #2
	bl Div
	adds r1, r0, #0
	adds r1, #0x81
	cmp r1, #0x9f
	ble _082322B0
	adds r1, #0x40
_082322B0:
	strb r1, [r6]
	strb r4, [r6, #1]
	adds r6, #1
	b _082322BA
_082322B8:
	strb r1, [r6]
_082322BA:
	ldrb r0, [r5]
	cmp r0, #0xd
	bne _082322C8
	ldrb r0, [r5, #1]
	cmp r0, #0xa
	bne _082322C8
	adds r5, #1
_082322C8:
	adds r5, #1
	adds r6, #1
_082322CC:
	ldrb r1, [r5]
	cmp r1, #0
	bne _08232274
	movs r0, #0
	strb r0, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_082322dc
FUN_082322dc: @ 0x082322DC
	push {r4, r5, lr}
	sub sp, #0xc
	adds r1, r0, #0
	add r4, sp, #4
	add r5, sp, #8
_082322E6:
	adds r0, r1, #0
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	adds r1, r0, #0
_082322F2:
	adds r0, r1, #0
	mov r1, sp
	adds r2, r5, #0
	bl VM_Step
	adds r1, r0, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _08232308
	ldr r0, [sp, #8]
	b _08232330
_08232308:
	adds r0, r1, #0
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	adds r1, r0, #0
	cmp r1, #0
	beq _0823232E
	ldr r0, [sp]
	asrs r0, r0, #0x10
	str r0, [sp]
	ldr r1, [sp, #4]
	cmp r0, #0x65
	bne _0823232A
	movs r0, #1
	str r0, [sp, #4]
	b _082322F2
_0823232A:
	cmp r0, #0x69
	beq _082322E6
_0823232E:
	movs r0, #0
_08232330:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
_08232338:
	.byte 0x00, 0xB5, 0xFF, 0xF7, 0xCF, 0xFF, 0x00, 0x28
	.byte 0x01, 0xD1, 0x00, 0x20, 0x03, 0xE0, 0x00, 0x21, 0x00, 0x22, 0xFF, 0xF7, 0xC1, 0xFB, 0x02, 0xBC
	.byte 0x08, 0x47, 0x00, 0x00, 0x00, 0xB5, 0x83, 0xB0, 0x00, 0x21, 0x02, 0x91, 0x01, 0xAA, 0x69, 0x46
	.byte 0xFE, 0xF7, 0x9C, 0xFF, 0xFF, 0xF7, 0xCE, 0xF8, 0xFF, 0xF7, 0xF8, 0xF8, 0x00, 0x28, 0x01, 0xD1
	.byte 0x00, 0x20, 0x1A, 0xE0, 0x63, 0x28, 0x0B, 0xD1, 0xFF, 0xF7, 0xB4, 0xF9, 0x01, 0x99, 0x88, 0x42
	.byte 0xF2, 0xD1, 0xFF, 0xF7, 0x9B, 0xF9, 0x69, 0x46, 0x02, 0xAA, 0xFE, 0xF7, 0x87, 0xFF, 0x07, 0xE0
	.byte 0x64, 0x28, 0xE9, 0xD1, 0xFF, 0xF7, 0x92, 0xF9, 0x69, 0x46, 0x02, 0xAA, 0xFE, 0xF7, 0x7E, 0xFF
	.byte 0x02, 0x98, 0x00, 0x21, 0x00, 0x22, 0xFF, 0xF7, 0x93, 0xFB, 0x03, 0xB0, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_082323b0
FUN_082323b0: @ 0x082323B0
	push {lr}
	sub sp, #8
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	ldr r1, _082323CC @ =0x030045A0
	ldr r0, [sp, #4]
	str r0, [r1, #4]
	movs r0, #0
	add sp, #8
	pop {r1}
	bx r1
	.align 2, 0
_082323CC: .4byte 0x030045A0
_082323D0:
	.byte 0x00, 0xB5, 0xFF, 0xF7, 0x73, 0xF9, 0x01, 0x1C, 0x00, 0x29, 0x07, 0xD0, 0xFF, 0xF7, 0x82, 0xF9
	.byte 0x01, 0x49, 0x48, 0x60, 0x04, 0xE0, 0x00, 0x00, 0xA0, 0x45, 0x00, 0x03, 0x02, 0x48, 0x41, 0x60
	.byte 0x01, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0xA0, 0x45, 0x00, 0x03

	thumb_func_start FUN_082323fc
FUN_082323fc: @ 0x082323FC
	push {r4, r5, lr}
	ldr r4, _08232408 @ =0xFFFFFDF8
	add sp, r4
	adds r4, r0, #0
	add r5, sp, #0x204
	b _0823242A
	.align 2, 0
_08232408: .4byte 0xFFFFFDF8
_0823240C:
	cmp r0, #7
	bne _0823241A
	ldr r1, [r5]
	mov r0, sp
	bl FUN_0823226c
	b _0823242A
_0823241A:
	cmp r0, #0xe
	bne _0823242A
	ldr r1, [r5]
	b _08232424
_08232422:
	adds r1, #1
_08232424:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08232422
_0823242A:
	cmp r4, #0
	beq _08232442
	adds r0, r4, #0
	add r1, sp, #0x200
	add r2, sp, #0x204
	bl VM_Step
	adds r4, r0, #0
	add r0, sp, #0x200
	ldr r0, [r0]
	cmp r0, #0
	bne _0823240C
_08232442:
	movs r0, #0
	movs r3, #0x82
	lsls r3, r3, #2
	add sp, r3
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08232450
FUN_08232450: @ 0x08232450
	push {r4, r5, r6, lr}
	sub sp, #0x50
	bl fetch_082316e4
	adds r6, r0, #0
	bl FUN_082316bc
	adds r3, r0, #0
	movs r4, #0
	add r5, sp, #0x48
	b _08232472
_08232466:
	lsls r0, r4, #2
	mov r2, sp
	adds r1, r2, r0
	ldr r0, [sp, #0x44]
	str r0, [r1]
	adds r4, #1
_08232472:
	cmp r3, #0
	beq _08232488
	add r1, sp, #0x40
	add r2, sp, #0x44
	adds r0, r3, #0
	bl VM_Step
	adds r3, r0, #0
	ldr r0, [sp, #0x40]
	cmp r0, #0
	bne _08232466
_08232488:
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _082324AC @ =0xFFFF0000
	ldr r0, [sp, #0x48]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x48]
	mov r0, sp
	str r0, [r5, #4]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_082318ac
	add sp, #0x50
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_082324AC: .4byte 0xFFFF0000

	thumb_func_start FUN_082324b0
FUN_082324b0: @ 0x082324B0
	push {r4, lr}
	ldr r4, _082324D4 @ =0x03000770
	movs r0, #0
	str r0, [r4]
	movs r0, #0x30
	movs r1, #8
	bl Div
	str r0, [r4, #4]
	ldr r0, _082324D8 @ =0x085B01D0
	str r0, [r4, #8]
	adds r0, r4, #0
	bl FUN_0823178c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082324D4: .4byte 0x03000770
_082324D8: .4byte 0x085B01D0
