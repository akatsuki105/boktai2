	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08040d94
FUN_08040d94: @ 0x08040D94
	push {r4, lr}
	adds r4, r0, #0
	movs r3, #0
	ldr r2, _08040DAC @ =0x085AB210
_08040D9C:
	ldrh r0, [r2]
	cmp r0, r4
	bne _08040DB0
	ldrb r0, [r2, #2]
	cmp r0, r1
	bne _08040DB0
	ldr r0, [r2, #4]
	b _08040DBA
	.align 2, 0
_08040DAC: .4byte 0x085AB210
_08040DB0:
	adds r2, #8
	adds r3, #1
	cmp r3, #0x14
	ble _08040D9C
	movs r0, #0
_08040DBA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08040dc0
FUN_08040dc0: @ 0x08040DC0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0
	ldr r2, _08040DDC @ =0x085AB2B8
	adds r3, r2, #0
_08040DCC:
	ldrh r0, [r2]
	cmp r0, r5
	bne _08040DE0
	ldrb r0, [r2, #2]
	cmp r0, r4
	bne _08040DE0
	adds r0, r3, #0
	b _08040DEC
	.align 2, 0
_08040DDC: .4byte 0x085AB2B8
_08040DE0:
	adds r2, #8
	adds r3, #8
	adds r1, #1
	cmp r1, #0x14
	ble _08040DCC
	movs r0, #0
_08040DEC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08040df4
FUN_08040df4: @ 0x08040DF4
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	adds r5, r3, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08040d94
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	beq _08040E28
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08040dc0
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	beq _08040E28
	movs r0, #0
	b _08040E2C
_08040E28:
	movs r0, #1
	rsbs r0, r0, #0
_08040E2C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08040e34
FUN_08040e34: @ 0x08040E34
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, [r3, #0x1c]
	cmp r0, #0
	beq _08040E48
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	str r2, [r0]
_08040E48:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0
	str r0, [r1]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, [r3, #0x1c]
	str r0, [r1]
	str r2, [r3, #0x1c]
	movs r0, #1
	strb r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08040e68
FUN_08040e68: @ 0x08040E68
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08040E88
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r2, r0
	ldr r0, [r0]
	str r0, [r1]
	b _08040E92
_08040E88:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	str r0, [r3, #0x1c]
_08040E92:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08040EAA
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r2, r0
	ldr r0, [r0]
	str r0, [r1]
_08040EAA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08040eb0
FUN_08040eb0: @ 0x08040EB0
	push {lr}
	ldr r2, [r0, #0x1c]
	cmp r2, #0
	beq _08040ED2
	movs r3, #0xbb
	lsls r3, r3, #2
_08040EBC:
	adds r0, r2, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	cmp r0, r1
	bne _08040ECA
	adds r0, r2, #0
	b _08040ED4
_08040ECA:
	adds r0, r2, r3
	ldr r2, [r0]
	cmp r2, #0
	bne _08040EBC
_08040ED2:
	movs r0, #0
_08040ED4:
	pop {r1}
	bx r1

	thumb_func_start FUN_08040ed8
FUN_08040ed8: @ 0x08040ED8
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	ldr r0, _08040F00 @ =0x03002B50
	ldr r0, [r0]
	cmp r0, #0
	beq _08040F04
	movs r5, #0xbc
	lsls r5, r5, #2
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08040F04
	adds r1, r5, #0
	bl ClearMemory
	strb r6, [r4, #1]
	adds r0, r4, #0
	b _08040F06
	.align 2, 0
_08040F00: .4byte 0x03002B50
_08040F04:
	movs r0, #0
_08040F06:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08040f0c
FUN_08040f0c: @ 0x08040F0C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	strb r3, [r4, #0x1b]
	adds r5, r4, #0
	adds r5, #0x5c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #7
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	bl FUN_0823b400
	adds r4, #0xa0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823b464
	movs r1, #4
	ldrh r2, [r5, #2]
	orrs r1, r2
	strh r1, [r5, #2]
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08040f48
FUN_08040f48: @ 0x08040F48
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, [sp, #0x14]
	adds r5, r4, #0
	adds r5, #0xd0
	cmp r1, #2
	bne _08040F7A
	adds r3, r4, #0
	adds r3, #0x64
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r6, #0
	bl FUN_08055e34
	adds r6, r0, #0
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r0, [r1, #0x3a]
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x5c
	bl FUN_0823b474
	b _08040FA2
_08040F7A:
	adds r0, r4, #0
	adds r0, #0x64
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r3, #0
	adds r3, r6, #0
	bl FUN_08055dac
	adds r6, r0, #0
	adds r0, r4, #0
	adds r0, #0xdc
	ldrh r0, [r0, #6]
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x5c
	adds r1, r4, #0
	adds r1, #0xf8
	bl FUN_0823b46c
_08040FA2:
	ldrh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08055f5c
	cmp r6, #0
	bge _08040FB6
	movs r0, #1
	rsbs r0, r0, #0
_08040FB6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08040fc0
FUN_08040fc0: @ 0x08040FC0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r3, #0
	ldr r3, [sp, #0x2c]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r0, r4, r6
	strb r2, [r0]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r2, #1
	bne _08040FF0
	movs r0, #0x91
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_08013698
	b _0804102C
_08040FF0:
	cmp r2, #2
	bne _0804102C
	movs r6, #0x91
	lsls r6, r6, #2
	adds r4, r4, r6
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0xfa
	lsls r0, r0, #3
	str r0, [sp, #8]
	movs r0, #0xc8
	lsls r0, r0, #1
	str r0, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r0, #4
	str r0, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	adds r0, r4, #0
	adds r2, r3, #0
	bl FUN_08013ba8
	ldr r1, _08041038 @ =0x00001C1B
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08013c94
	adds r0, r4, #0
	bl FUN_08013984
_0804102C:
	movs r0, #0
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08041038: .4byte 0x00001C1B

	thumb_func_start FUN_0804103c
FUN_0804103c: @ 0x0804103C
	push {lr}
	adds r1, r0, #0
	movs r2, #0x85
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _08041056
	adds r2, #0x30
	adds r0, r1, r2
	bl FUN_080138fc
	b _08041064
_08041056:
	cmp r0, #2
	bne _08041064
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r1, r2
	bl FUN_08013c70
_08041064:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804106c
FUN_0804106c: @ 0x0804106C
	push {lr}
	adds r1, r0, #0
	movs r2, #0x85
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _08041086
	adds r2, #0x30
	adds r0, r1, r2
	bl FUN_080136b4
	b _08041094
_08041086:
	cmp r0, #2
	bne _08041094
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r1, r2
	bl FUN_080139a0
_08041094:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804109c
FUN_0804109c: @ 0x0804109C
	push {lr}
	adds r1, r0, #0
	movs r2, #0x85
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080410B6
	adds r2, #0x30
	adds r0, r1, r2
	bl FUN_08013698
	b _080410C4
_080410B6:
	cmp r0, #2
	bne _080410C4
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r1, r2
	bl FUN_08013984
_080410C4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080410cc
FUN_080410cc: @ 0x080410CC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x5c
	bl FUN_08002a48
	cmp r0, #0
	blt _080410E8
	movs r0, #0xf7
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _080410EC
_080410E8:
	movs r0, #1
	rsbs r0, r0, #0
_080410EC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080410f4
FUN_080410f4: @ 0x080410F4
	push {r4, lr}
	adds r1, r0, #0
	movs r0, #0xf7
	lsls r0, r0, #1
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08041112
	adds r0, r1, #0
	adds r0, #0x5c
	bl FUN_08002a58
	movs r0, #0
	strb r0, [r4]
	b _08041116
_08041112:
	movs r0, #1
	rsbs r0, r0, #0
_08041116:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804111c
FUN_0804111c: @ 0x0804111C
	push {lr}
	adds r2, r0, #0
	adds r2, #0xd0
	strh r1, [r0, #0x1e]
	ldrh r1, [r0, #0x1e]
	adds r0, r2, #0
	bl FUN_08055fbc
	pop {r1}
	bx r1

	thumb_func_start FUN_08041130
FUN_08041130: @ 0x08041130
	push {lr}
	strh r1, [r0, #0x1c]
	ldrh r1, [r0, #0x1c]
	bl FUN_0804111c
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08041140
FUN_08041140: @ 0x08041140
	push {lr}
	ldrh r1, [r0, #0x1c]
	bl FUN_0804111c
	pop {r1}
	bx r1

	thumb_func_start FUN_0804114c
FUN_0804114c: @ 0x0804114C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08041190 @ =0x03002B50
	ldr r1, [r0]
	cmp r1, #0
	beq _08041194
	ldrb r0, [r4]
	cmp r0, #0
	beq _08041194
	adds r0, r1, #0
	adds r1, r4, #0
	bl FUN_08040e68
	adds r0, r4, #0
	bl FUN_080410f4
	adds r0, r4, #0
	adds r0, #0x5c
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d7c
	adds r0, r4, #0
	bl FUN_0804103c
	movs r0, #0
	strb r0, [r4]
	adds r0, r4, #0
	bl Free
	movs r0, #0
	b _08041198
	.align 2, 0
_08041190: .4byte 0x03002B50
_08041194:
	movs r0, #1
	rsbs r0, r0, #0
_08041198:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080411a0
FUN_080411a0: @ 0x080411A0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080411B2
	movs r0, #1
	rsbs r0, r0, #0
	b _080411D2
_080411B2:
	movs r6, #0
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r4, r5, r0
_080411BA:
	ldr r2, [r4]
	cmp r2, #0
	beq _080411C8
	adds r0, r7, #0
	adds r1, r5, #0
	bl _call_via_r2
_080411C8:
	adds r4, #4
	adds r6, #1
	cmp r6, #3
	ble _080411BA
	movs r0, #0
_080411D2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080411d8
FUN_080411d8: @ 0x080411D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r0, #0xd0
	adds r0, r0, r5
	mov r8, r0
	adds r0, r7, #0
	bl FUN_0823b4b8
	movs r1, #0x80
	lsls r1, r1, #3
	ldrh r0, [r5, #0xe]
	ands r0, r1
	cmp r0, #0
	bne _08041282
	adds r6, r5, #0
	adds r6, #0x64
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08041224
	cmp r1, #0
	blt _08041224
	ldr r0, _08041228 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08041224
	ldr r0, _0804122C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08041230
_08041224:
	movs r4, #0
	b _0804123E
	.align 2, 0
_08041228: .4byte 0x030046A8
_0804122C: .4byte 0x030046AC
_08041230:
	ldr r0, _08041250 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0804123E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08041254
	adds r0, #4
	b _08041260
	.align 2, 0
_08041250: .4byte 0x030046A4
_08041254:
	ldr r0, _08041274 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08041260:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08041278
	cmp r2, #2
	beq _0804127C
	b _08041280
	.align 2, 0
_08041274: .4byte 0x030046A4
_08041278:
	ldrb r0, [r6, #4]
	b _0804127E
_0804127C:
	ldrb r0, [r6]
_0804127E:
	subs r1, r1, r0
_08041280:
	strh r1, [r7, #0xa]
_08041282:
	adds r1, r7, #0
	adds r1, #8
	mov r0, r8
	bl FUN_08055ed4
	mov r0, r8
	bl FUN_08055c04
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r3, r5, r1
	ldrh r2, [r3]
	movs r4, #0
	ldrsh r1, [r3, r4]
	cmp r1, #0
	ble _080412EA
	subs r1, r2, #1
	strh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	bgt _080412EA
	ldrb r1, [r5, #0xa]
	cmp r1, #0
	beq _080412D0
	ldr r1, _080412CC @ =0x030047A4
	ldr r1, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	cmp r1, #0
	bne _080412D0
	adds r2, #0xca
	adds r1, r5, r2
	ldrh r1, [r1]
	strh r1, [r3]
	b _080412EA
	.align 2, 0
_080412CC: .4byte 0x030047A4
_080412D0:
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r0, r5, r4
	movs r4, #0
	movs r1, #0
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080415cc
	strb r4, [r5, #0xa]
_080412EA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080412f4
FUN_080412f4: @ 0x080412F4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080412f8
FUN_080412f8: @ 0x080412F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080412fc
FUN_080412fc: @ 0x080412FC
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x5c
	ldrh r1, [r0]
	adds r0, #0x44
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0xa4
	adds r1, r4, #0
	adds r1, #0x64
	str r1, [r2]
	bl FUN_08234660
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r4, #0xe]
	ands r0, r1
	cmp r0, #0
	beq _08041330
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	b _08041346
_08041330:
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055f1c
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r4, #0xe]
	ands r0, r1
	cmp r0, #0
	beq _0804134E
_08041346:
	adds r0, r4, #0
	bl FUN_0804106c
	b _08041354
_0804134E:
	adds r0, r4, #0
	bl FUN_0804109c
_08041354:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804135c
FUN_0804135c: @ 0x0804135C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r4, #0
	adds r5, #0xd0
	ldr r0, [r5]
	cmp r0, #1
	bne _08041384
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bls _0804137E
	adds r1, r0, #0
	movs r0, #3
	subs r2, r0, r1
	b _0804139A
_0804137E:
	ldrb r2, [r4, #0x19]
	movs r3, #0
	b _0804139C
_08041384:
	ldrb r1, [r4, #0x19]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	cmp r0, #1
	bhi _08041394
	adds r2, r3, #0
_08041394:
	movs r3, #0
	cmp r1, #1
	bls _0804139C
_0804139A:
	movs r3, #1
_0804139C:
	str r6, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080413b8
FUN_080413b8: @ 0x080413B8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r1, r3, #0
	adds r1, #0xd0
	ldr r0, [r1]
	cmp r0, #1
	bne _080413D6
	ldrb r2, [r3, #0x19]
	movs r3, #0
	cmp r2, #1
	bls _080413E2
	b _080413E0
_080413D6:
	movs r2, #0
	ldrb r0, [r3, #0x19]
	movs r3, #0
	cmp r0, #1
	bls _080413E2
_080413E0:
	movs r3, #1
_080413E2:
	str r4, [sp]
	ldr r0, [sp, #0x18]
	str r0, [sp, #4]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #8]
	adds r0, r1, #0
	adds r1, r5, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080413fc
FUN_080413fc: @ 0x080413FC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	adds r0, #0xd0
	ldr r0, [r0]
	cmp r0, #1
	bne _08041426
	ldrb r0, [r4, #0x1a]
	cmp r0, #4
	bls _08041420
	adds r1, r0, #0
	movs r0, #8
	subs r2, r0, r1
	movs r3, #1
	b _08041442
_08041420:
	ldrb r2, [r4, #0x1a]
	movs r3, #0
	b _08041442
_08041426:
	ldrb r0, [r4, #0x1a]
	cmp r0, #4
	bls _08041436
	adds r1, r0, #0
	movs r0, #8
	subs r2, r0, r1
	movs r3, #1
	b _0804143C
_08041436:
	ldrb r2, [r4, #0x1a]
	movs r3, #0
	adds r1, r2, #0
_0804143C:
	adds r0, r1, #0
	muls r0, r5, r0
	strb r0, [r4, #0x1a]
_08041442:
	adds r0, r4, #0
	adds r0, #0xd0
	str r6, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	ldr r1, [sp, #0x24]
	str r1, [sp, #8]
	adds r1, r7, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08041460
FUN_08041460: @ 0x08041460
	push {r4, lr}
	sub sp, #0xc
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	adds r0, #0xd0
	str r2, [sp]
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08041480
FUN_08041480: @ 0x08041480
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r2, #0
	adds r2, r3, #0
	ldr r6, [sp, #0x18]
	movs r3, #0xae
	lsls r3, r3, #2
	adds r0, r4, r3
	lsls r1, r1, #2
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #1
	bne _080414B2
	ldrh r1, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	str r2, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080413b8
	b _080414F4
_080414B2:
	cmp r1, #2
	bne _080414CA
	ldrh r1, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	str r2, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0804135c
	b _080414F4
_080414CA:
	cmp r1, #3
	bne _080414E2
	ldrh r1, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	str r2, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080413fc
	b _080414F4
_080414E2:
	ldrh r1, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	str r2, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08041460
_080414F4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080414fc
FUN_080414fc: @ 0x080414FC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r2, _08041514 @ =0x00000212
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08041570
	cmp r1, #1
	bne _08041518
	movs r5, #0
	b _0804151E
	.align 2, 0
_08041514: .4byte 0x00000212
_08041518:
	cmp r1, #3
	bne _08041570
	movs r5, #2
_0804151E:
	adds r0, r4, #0
	adds r0, #0xd0
	mov r1, sp
	bl FUN_08055d48
	cmp r0, #0
	beq _08041570
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	adds r0, r2, #4
	adds r3, r0, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldr r1, [sp]
	cmp r0, r1
	bne _08041558
	ldr r0, _08041554 @ =0x085AB360
	ldrb r1, [r2, #3]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	bl PlaySound_082406e0
	b _08041570
	.align 2, 0
_08041554: .4byte 0x085AB360
_08041558:
	movs r0, #1
	ldrsb r0, [r3, r0]
	cmp r0, r1
	bne _08041570
	ldr r0, _08041578 @ =0x085AB360
	ldrb r1, [r2, #3]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	bl PlaySound_082406e0
_08041570:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08041578: .4byte 0x085AB360

	thumb_func_start FUN_0804157c
FUN_0804157c: @ 0x0804157C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08041592
	rsbs r1, r1, #0
_08041592:
	cmp r1, r2
	bge _080415C2
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r5, #2
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080415A6
	rsbs r1, r1, #0
_080415A6:
	cmp r1, #0xff
	bgt _080415C2
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _080415BA
	rsbs r0, r0, #0
_080415BA:
	cmp r0, r2
	bge _080415C2
	movs r0, #1
	b _080415C4
_080415C2:
	movs r0, #0
_080415C4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080415cc
FUN_080415cc: @ 0x080415CC
	push {r4, r5, lr}
	sub sp, #0x10
	mov ip, r0
	adds r5, r3, #0
	cmp r1, #8
	bls _080415DA
	b _080417D2
_080415DA:
	lsls r0, r1, #2
	ldr r1, _080415E4 @ =_080415E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080415E4: .4byte _080415E8
_080415E8: @ jump table
	.4byte _0804160C @ case 0
	.4byte _0804166A @ case 1
	.4byte _08041644 @ case 2
	.4byte _0804169E @ case 3
	.4byte _080416D4 @ case 4
	.4byte _08041710 @ case 5
	.4byte _08041754 @ case 6
	.4byte _0804177C @ case 7
	.4byte _080417A4 @ case 8
_0804160C:
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	str r2, [r0]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #1
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _08041640 @ =0x000001B1
	bl PlaySound_082406e0
	b _080417D2
	.align 2, 0
_08041640: .4byte 0x000001B1
_08041644:
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	str r2, [r0]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	b _0804168E
_0804166A:
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	str r2, [r0]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
_0804168E:
	bl FUN_080da9c4
	str r0, [r4]
	movs r0, #0xf6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080417D2
_0804169E:
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	str r2, [r0]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #2
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _080416D0 @ =0x000001ED
	bl PlaySound_082406e0
	b _080417D2
	.align 2, 0
_080416D0: .4byte 0x000001ED
_080416D4:
	movs r1, #0xb1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #1
	str r0, [r1]
	movs r3, #0xb2
	lsls r3, r3, #2
	add r3, ip
	movs r4, #0
	strh r2, [r3]
	ldr r2, _0804170C @ =0x000002CA
	add r2, ip
	strh r5, [r2]
	movs r5, #0xb0
	lsls r5, r5, #2
	add r5, ip
	ldr r0, [r5]
	mov r1, ip
	adds r1, #0x5c
	str r3, [sp]
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #1
	b _08041746
	.align 2, 0
_0804170C: .4byte 0x000002CA
_08041710:
	movs r1, #0xb1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #3
	str r0, [r1]
	movs r3, #0xb2
	lsls r3, r3, #2
	add r3, ip
	movs r4, #0
	strh r2, [r3]
	ldr r2, _08041750 @ =0x000002CA
	add r2, ip
	strh r5, [r2]
	movs r5, #0xb0
	lsls r5, r5, #2
	add r5, ip
	ldr r0, [r5]
	mov r1, ip
	adds r1, #0x5c
	str r3, [sp]
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #3
_08041746:
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r5]
	b _080417D2
	.align 2, 0
_08041750: .4byte 0x000002CA
_08041754:
	movs r1, #0xb1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #5
	str r0, [r1]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #5
	movs r3, #0
	b _080417CC
_0804177C:
	movs r1, #0xb1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #4
	str r0, [r1]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #4
	movs r3, #0
	b _080417CC
_080417A4:
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r3, [r4]
	cmp r3, #0
	beq _080417D2
	mov r1, ip
	adds r1, #0x5c
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #0x64
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r3, #0x7f
_080417CC:
	bl FUN_080da9c4
	str r0, [r4]
_080417D2:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080417dc
FUN_080417dc: @ 0x080417DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _08041874 @ =0x03002B50
	ldr r2, [r0]
	cmp r2, #0
	bne _080417F4
	b _08041906
_080417F4:
	ldr r0, _08041878 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08041804
	b _08041906
_08041804:
	ldr r2, [r2, #0x1c]
	mov r8, r2
	cmp r2, #0
	beq _08041906
	ldr r0, _0804187C @ =0x085B0A08
	mov sl, r0
	add r7, sp, #8
_08041812:
	movs r1, #0x80
	lsls r1, r1, #5
	mov r2, r8
	ldrh r0, [r2, #0xe]
	ands r0, r1
	cmp r0, #0
	beq _080418F8
	mov r6, r8
	adds r6, #0x64
	adds r2, r5, #0
	adds r2, #8
	movs r3, #8
	ldrsh r1, [r5, r3]
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r4, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r3, #4
	ldrsh r0, [r6, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08041880 @ =0x0000270F
	mov sb, r2
	cmp r1, r0
	bgt _080418F8
	adds r0, r4, #0
	adds r1, r3, #0
	bl ArcTan2_8
	add r2, sp, #8
	adds r3, r0, #0
	movs r4, #0x64
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08041884
	asrs r1, r0, #0xc
	b _0804188A
	.align 2, 0
_08041874: .4byte 0x03002B50
_08041878: .4byte 0x030047A4
_0804187C: .4byte 0x085B0A08
_08041880: .4byte 0x0000270F
_08041884:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0804188A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	add r0, sl
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _080418A6
	asrs r0, r0, #0xc
	b _080418AC
_080418A6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080418AC:
	strh r0, [r2, #4]
	ldrh r2, [r6]
	ldrh r0, [r7]
	adds r2, r2, r0
	strh r2, [r7]
	ldrh r3, [r7, #2]
	ldrh r0, [r6, #2]
	adds r3, r3, r0
	strh r3, [r7, #2]
	ldrh r1, [r6, #4]
	ldrh r0, [r7, #4]
	adds r1, r1, r0
	strh r1, [r7, #4]
	adds r4, r5, #0
	adds r4, #0x10
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	strh r2, [r5, #0x10]
	mov r2, sb
	ldrh r0, [r2, #2]
	subs r3, r3, r0
	strh r3, [r4, #2]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	ldr r1, [r5, #0x18]
	cmp r1, #0
	beq _080418F8
	ldrh r3, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	str r0, [sp]
	ldrb r0, [r5, #4]
	str r0, [sp, #4]
	adds r0, r1, #0
	mov r1, sb
	adds r2, r4, #0
	bl FUN_0823349c
_080418F8:
	movs r0, #0xbb
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _08041812
_08041906:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08041918
FUN_08041918: @ 0x08041918
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r0, _080419C0 @ =0x030044E0
	ldrh r0, [r0, #2]
	movs r1, #1
	mov sl, r1
	mov r2, sl
	ands r2, r0
	mov sl, r2
	movs r6, #0x87
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	cmp r0, #0
	beq _080419CC
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _080419CC
	movs r6, #0xe0
	lsls r6, r6, #2
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _080419CC
	ldr r2, _080419C4 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0804197A
	ldr r6, _080419C8 @ =0x00000442
	adds r0, r1, r6
	ldrh r0, [r0]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _080419CC
_0804197A:
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #1
	bls _0804198E
	cmp r0, #7
	beq _0804198E
	movs r1, #0
_0804198E:
	cmp r1, #0
	beq _080419CC
	movs r6, #0x87
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r2, #0
	mov r8, r2
	cmp r0, #0
	beq _080419D0
	movs r6, #1
	mov r8, r6
	cmp r0, #1
	beq _080419D0
	movs r1, #3
	mov r8, r1
	cmp r0, #5
	bne _080419D0
	movs r2, #2
	mov r8, r2
	b _080419D0
	.align 2, 0
_080419C0: .4byte 0x030044E0
_080419C4: .4byte 0x00000446
_080419C8: .4byte 0x00000442
_080419CC:
	movs r6, #3
	mov r8, r6
_080419D0:
	movs r5, #0
	bl FUN_0823d5f0
	cmp r0, #0
	beq _08041A3E
	ldr r0, _08041A78 @ =0x000F4240
	str r0, [sp, #0x20]
	ldr r4, [r7, #0x1c]
	cmp r4, #0
	beq _08041A3E
	movs r1, #0x80
	lsls r1, r1, #4
	mov sb, r1
	ldr r2, _08041A7C @ =0x00000434
	adds r2, r2, r7
	mov ip, r2
_080419F0:
	ldrh r0, [r4, #0xe]
	mov r6, sb
	ands r0, r6
	cmp r0, #0
	beq _08041A32
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _08041A32
	adds r3, r4, #0
	adds r3, #0x64
	mov r0, ip
	ldr r1, [r0]
	movs r6, #0
	ldrsh r2, [r1, r6]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r2, r2, r0
	movs r0, #4
	ldrsh r1, [r1, r0]
	movs r6, #4
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r0, #0
	adds r0, r1, #0
	muls r0, r1, r0
	adds r2, r2, r0
	ldr r1, [sp, #0x20]
	cmp r2, r1
	bge _08041A32
	str r2, [sp, #0x20]
	adds r5, r4, #0
_08041A32:
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r4, [r0]
	cmp r4, #0
	bne _080419F0
_08041A3E:
	cmp r5, #0
	beq _08041AA4
	mov r6, sl
	cmp r6, #0
	bne _08041AA4
	ldr r4, [r7, #0x1c]
	cmp r4, #0
	beq _08041ACC
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	mov r2, r8
	adds r6, r0, r2
_08041A58:
	cmp r4, r5
	bne _08041A80
	ldrb r0, [r5, #0xa]
	cmp r0, #0
	bne _08041A96
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r0, r5, #0
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080415cc
	movs r0, #1
	strb r0, [r5, #0xa]
	b _08041A96
	.align 2, 0
_08041A78: .4byte 0x000F4240
_08041A7C: .4byte 0x00000434
_08041A80:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	beq _08041A96
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080415cc
	movs r0, #0
	strb r0, [r4, #0xa]
_08041A96:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r4, [r0]
	cmp r4, #0
	bne _08041A58
	b _08041ACC
_08041AA4:
	ldr r4, [r7, #0x1c]
	cmp r4, #0
	beq _08041ACC
_08041AAA:
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	beq _08041AC0
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080415cc
	movs r0, #0
	strb r0, [r4, #0xa]
_08041AC0:
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r4, [r0]
	cmp r4, #0
	bne _08041AAA
_08041ACC:
	cmp r5, #0
	beq _08041B16
	mov r6, sl
	cmp r6, #0
	beq _08041B16
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #0x64
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r0, #0x66
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0x68
	movs r6, #0
	ldrsh r0, [r0, r6]
	str r0, [sp, #0xc]
	adds r3, r5, #0
	adds r3, #0x44
	add r2, sp, #0x10
	movs r1, #3
_08041B04:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08041B04
	ldr r0, [r5, #0x40]
	movs r1, #0
	bl Script_ExecById
_08041B16:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08041b28
FUN_08041b28: @ 0x08041B28
	push {r4, r5, r6, r7, lr}
	ldr r0, _08041B50 @ =0x03002B50
	ldr r6, [r0]
	cmp r6, #0
	beq _08041B4A
	ldr r3, [r6, #0x28]
	lsls r0, r3, #2
	adds r1, r6, #0
	adds r1, #0x2c
	adds r0, r1, r0
	ldr r2, [r0]
	lsls r0, r2, #2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r7, r1, #0
	cmp r0, #7
	bls _08041B54
_08041B4A:
	movs r0, #1
	rsbs r0, r0, #0
	b _08041BCE
	.align 2, 0
_08041B50: .4byte 0x03002B50
_08041B54:
	lsls r0, r3, #9
	adds r0, #0x34
	adds r0, r6, r0
	lsls r1, r2, #6
	adds r5, r0, r1
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r5]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #2]
	strb r4, [r5, #3]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #4]
	movs r0, #0x61
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #6]
	strb r4, [r5, #7]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08041BBA
_08041B96:
	bl VM_GetPC
	cmp r0, #0
	beq _08041BBA
	bl Script_GetValue
	ldrb r2, [r5, #7]
	adds r1, r2, #1
	strb r1, [r5, #7]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x17
	adds r1, r5, #0
	adds r1, #8
	adds r1, r1, r2
	strh r0, [r1]
	ldrb r0, [r5, #7]
	cmp r0, #7
	bls _08041B96
_08041BBA:
	adds r0, r5, #0
	bl FUN_080224f0
	ldr r1, [r6, #0x28]
	lsls r1, r1, #2
	adds r1, r7, r1
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
_08041BCE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08041bd4
FUN_08041bd4: @ 0x08041BD4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _08041C00 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08041BFA
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	adds r7, r0, #0
	cmp r7, #0
	bne _08041C04
_08041BFA:
	movs r0, #1
	rsbs r0, r0, #0
	b _08041D4E
	.align 2, 0
_08041C00: .4byte 0x03002B50
_08041C04:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08041C3C
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r7, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r7, #0x19]
_08041C3C:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08041C98
	bl Script_GetValue
	ldr r1, _08041D24 @ =0x000001EF
	adds r1, r1, r7
	mov r8, r1
	strb r0, [r1]
	bl Script_GetValue
	movs r2, #0x83
	lsls r2, r2, #2
	adds r4, r7, r2
	strh r0, [r4]
	bl Script_GetValue
	movs r3, #0x84
	lsls r3, r3, #2
	adds r6, r7, r3
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0x5c
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r7, r2
	mov r3, r8
	ldrb r2, [r3]
	ldrb r3, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_0823b490
	adds r0, r7, #0
	adds r0, #0x64
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r1, [r1]
	ldrb r2, [r6]
	bl FUN_08234f80
_08041C98:
	movs r0, #0x62
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08041CC4
	bl Script_GetValue
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl Script_GetValue
	ldr r2, _08041D28 @ =0x000001E9
	adds r1, r7, r2
	strb r0, [r1]
	bl Script_GetValue
	movs r3, #0xf5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
_08041CC4:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08041CD4
	bl Script_GetValue
	str r0, [r7, #0x40]
_08041CD4:
	movs r0, #0x48
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08041CFC
	bl Script_GetValue
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r1, r7, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _08041D2C @ =0x00000239
	adds r1, r7, r3
	strb r0, [r1]
	ldr r0, _08041D30 @ =0x0000023B
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
_08041CFC:
	movs r0, #0x75
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08041D0C
	bl Script_GetValue
	strb r0, [r7, #0xb]
_08041D0C:
	ldr r1, _08041D24 @ =0x000001EF
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08041D34
	adds r0, r7, #0
	bl FUN_08043510
	b _08041D36
	.align 2, 0
_08041D24: .4byte 0x000001EF
_08041D28: .4byte 0x000001E9
_08041D2C: .4byte 0x00000239
_08041D30: .4byte 0x0000023B
_08041D34:
	movs r0, #6
_08041D36:
	movs r1, #0
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
	movs r0, #1
	strb r0, [r7, #8]
	ldr r2, _08041D5C @ =0x00000217
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_08041D4E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08041D5C: .4byte 0x00000217

	thumb_func_start FUN_08041d60
FUN_08041d60: @ 0x08041D60
	push {r4, r5, lr}
	ldr r0, _08041D88 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08041D80
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	adds r4, r0, #0
	cmp r4, #0
	bne _08041D8C
_08041D80:
	movs r0, #1
	rsbs r0, r0, #0
	b _08041DC4
	.align 2, 0
_08041D88: .4byte 0x03002B50
_08041D8C:
	ldr r1, _08041DA8 @ =0x00000217
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	cmp r2, #0
	beq _08041DAC
	cmp r2, #1
	beq _08041DBA
	b _08041DC4
	.align 2, 0
_08041DA8: .4byte 0x00000217
_08041DAC:
	movs r1, #1
	strb r2, [r4, #2]
	strb r2, [r4, #3]
	strb r1, [r4, #4]
	str r2, [r4, #0x14]
	strb r1, [r4, #8]
	b _08041DC4
_08041DBA:
	strb r5, [r4, #2]
	strb r5, [r4, #3]
	strb r5, [r4, #4]
	str r5, [r4, #0x14]
	strb r2, [r4, #8]
_08041DC4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08041dcc
FUN_08041dcc: @ 0x08041DCC
	push {r4, lr}
	ldr r0, _08041E00 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08041DFA
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	cmp r0, #0
	beq _08041DFA
	ldr r1, _08041E04 @ =0x00000227
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #0xd
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08041E08
_08041DFA:
	movs r0, #0
	b _08041E0A
	.align 2, 0
_08041E00: .4byte 0x03002B50
_08041E04: .4byte 0x00000227
_08041E08:
	movs r0, #1
_08041E0A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08041e10
FUN_08041e10: @ 0x08041E10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r1, #0
	movs r0, #0x43
	movs r1, #1
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08041E2C
	adds r0, r7, #0
	bl FUN_080410cc
_08041E2C:
	adds r0, r7, #0
	adds r0, #0x61
	ldrb r1, [r0]
	ldr r2, _08041EA4 @ =0x00000215
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0x43
	movs r1, #1
	bl VM_GetKeywordValue
	ldr r3, _08041EA8 @ =0x00000216
	adds r1, r7, r3
	strb r0, [r1]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08041EB0
	bl Script_GetValue
	ldr r1, _08041EAC @ =0x000001EF
	adds r1, r1, r7
	mov r8, r1
	strb r0, [r1]
	bl Script_GetValue
	movs r2, #0x83
	lsls r2, r2, #2
	adds r4, r7, r2
	strh r0, [r4]
	bl Script_GetValue
	movs r3, #0x84
	lsls r3, r3, #2
	adds r6, r7, r3
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0x5c
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r7, r2
	mov r3, r8
	ldrb r2, [r3]
	ldrb r3, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_0823b490
	adds r0, r7, #0
	adds r0, #0x64
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r1, [r1]
	ldrb r2, [r6]
	bl FUN_08234f80
	b _08041EB8
	.align 2, 0
_08041EA4: .4byte 0x00000215
_08041EA8: .4byte 0x00000216
_08041EAC: .4byte 0x000001EF
_08041EB0:
	ldr r3, _08041EF0 @ =0x000001EF
	adds r1, r7, r3
	movs r0, #0xff
	strb r0, [r1]
_08041EB8:
	movs r0, #0x68
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08041EFC
	ldr r0, _08041EF4 @ =0x000001ED
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	bl Script_GetValue
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08041EF8 @ =0x0000023E
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x90
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	b _08041F10
	.align 2, 0
_08041EF0: .4byte 0x000001EF
_08041EF4: .4byte 0x000001ED
_08041EF8: .4byte 0x0000023E
_08041EFC:
	ldr r3, _08041F54 @ =0x000001ED
	adds r1, r7, r3
	strb r0, [r1]
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, [r7, #0x64]
	ldr r1, [r7, #0x68]
	str r0, [r2]
	str r1, [r2, #4]
_08041F10:
	movs r0, #0x54
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08041F64
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _08041F58 @ =0x00000231
	adds r1, r7, r3
	strb r0, [r1]
	bl Script_GetValue
	ldr r2, _08041F5C @ =0x00000232
	adds r1, r7, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _08041F60 @ =0x00000233
	adds r1, r7, r3
	strb r0, [r1]
	bl Script_GetValue
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	strb r0, [r1]
	b _08041F8A
	.align 2, 0
_08041F54: .4byte 0x000001ED
_08041F58: .4byte 0x00000231
_08041F5C: .4byte 0x00000232
_08041F60: .4byte 0x00000233
_08041F64:
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _08041FBC @ =0x00000231
	adds r1, r7, r0
	movs r0, #9
	strb r0, [r1]
	ldr r1, _08041FC0 @ =0x00000232
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #3
	adds r1, r7, r3
	movs r0, #0x15
	strb r0, [r1]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
_08041F8A:
	movs r0, #0x62
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08041FC8
	bl Script_GetValue
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _08041FC4 @ =0x000001E9
	adds r1, r7, r3
	strb r0, [r1]
	bl Script_GetValue
	movs r2, #0xf5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	b _08041FE0
	.align 2, 0
_08041FBC: .4byte 0x00000231
_08041FC0: .4byte 0x00000232
_08041FC4: .4byte 0x000001E9
_08041FC8:
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _08042010 @ =0x000001E9
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xf5
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r2, [r0]
_08041FE0:
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08042014
	bl Script_GetValue
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	bl Script_GetValue
	movs r3, #0x87
	lsls r3, r3, #2
	adds r1, r7, r3
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r7, r2
	b _08042030
	.align 2, 0
_08042010: .4byte 0x000001E9
_08042014:
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [r0]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r7, r2
	str r1, [r0]
	subs r3, #8
	adds r1, r7, r3
	movs r0, #0x80
	lsls r0, r0, #2
_08042030:
	str r0, [r1]
	movs r0, #0x48
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804206C
	bl Script_GetValue
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r1, r7, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _08042060 @ =0x00000239
	adds r1, r7, r3
	strb r0, [r1]
	ldr r0, _08042064 @ =0x0000023A
	adds r1, r7, r0
	movs r0, #4
	strb r0, [r1]
	ldr r2, _08042068 @ =0x0000023B
	adds r1, r7, r2
	b _08042088
	.align 2, 0
_08042060: .4byte 0x00000239
_08042064: .4byte 0x0000023A
_08042068: .4byte 0x0000023B
_0804206C:
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #6
	strb r1, [r0]
	ldr r2, _080420EC @ =0x00000239
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #2
	adds r1, r7, r3
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080420F0 @ =0x0000023B
	adds r1, r7, r0
_08042088:
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #0x42
	movs r1, #4
	bl VM_GetKeywordValue
	ldr r2, _080420F4 @ =0x0000023A
	adds r1, r7, r2
	strb r0, [r1]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r7, #0x40]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080420F8
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r4, [r1]
	movs r2, #0xf9
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	adds r3, #4
	adds r1, r7, r3
	str r4, [r1]
	adds r2, #6
	adds r1, r7, r2
	str r0, [r1]
	adds r3, #8
	adds r2, r7, r3
	adds r1, r4, #0
	muls r1, r4, r1
	str r1, [r2]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	b _0804212C
	.align 2, 0
_080420EC: .4byte 0x00000239
_080420F0: .4byte 0x0000023B
_080420F4: .4byte 0x0000023A
_080420F8:
	movs r1, #0x50
	movs r2, #0x60
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	adds r3, #2
	adds r0, r7, r3
	strh r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	str r1, [r0]
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0xc8
	lsls r0, r0, #5
	str r0, [r1]
	adds r3, #0xc
	adds r1, r7, r3
	movs r0, #0x90
	lsls r0, r0, #6
_0804212C:
	str r0, [r1]
	movs r0, #0x4d
	movs r1, #0xa
	bl VM_GetKeywordValue
	movs r2, #0x81
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	movs r3, #0x82
	lsls r3, r3, #2
	adds r1, r7, r3
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	str r0, [r1]
	movs r0, #0x75
	movs r1, #1
	bl VM_GetKeywordValue
	strb r0, [r7, #0xb]
	movs r0, #0x46
	movs r1, #1
	bl VM_GetKeywordValue
	ldr r3, _08042174 @ =0x00000212
	adds r1, r7, r3
	strb r0, [r1]
	movs r0, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08042174: .4byte 0x00000212

	thumb_func_start FUN_08042178
FUN_08042178: @ 0x08042178
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0804219A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
_0804219A:
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080421bc
FUN_080421bc: @ 0x080421BC
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _080421DE
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_080421DE:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08042200
FUN_08042200: @ 0x08042200
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08042228
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08042228:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08042240
	b _0804233E
_08042240:
	adds r3, r5, #0
	adds r3, #0x64
	adds r4, r5, #0
	adds r4, #0x54
	movs r6, #0
	ldrsh r2, [r4, r6]
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r6, #4
	ldrsh r0, [r4, r6]
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r6, #0x82
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r0, [r0]
	mov r8, r3
	mov ip, r4
	cmp r1, r0
	bhi _08042286
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	movs r0, #1
	strb r0, [r5, #7]
	b _08042336
_08042286:
	adds r3, r5, #0
	adds r3, #0x61
	adds r4, r5, #0
	adds r4, #0x6c
	ldrb r6, [r3]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _080422B8 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	mov sb, r3
	cmp r0, #0
	blt _080422BC
	asrs r1, r0, #0xc
	b _080422C2
	.align 2, 0
_080422B8: .4byte 0x085B0A08
_080422BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080422C2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080422DA
	asrs r0, r0, #0xc
	b _080422E0
_080422DA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080422E0:
	strh r0, [r4, #4]
	mov r3, ip
	movs r4, #0
	ldrsh r0, [r3, r4]
	mov r6, r8
	movs r2, #0
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #0x1b]
	ldrb r2, [r5, #0x1b]
	mov r4, sb
	strb r2, [r4]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08042336:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080414fc
_0804233E:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804234c
FUN_0804234c: @ 0x0804234C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0804236E
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_0804236E:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0804240C
	adds r1, r4, #0
	adds r1, #0x61
	ldrb r2, [r1]
	ldrb r0, [r4, #0x1b]
	subs r0, r0, r2
	lsls r0, r0, #0x18
	asrs r3, r0, #0x18
	adds r6, r1, #0
	cmp r3, #8
	ble _080423AC
	lsls r0, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x14
	adds r0, r0, r1
	b _080423C6
_080423AC:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _080423BE
	lsls r0, r2, #0x18
	movs r1, #0xf8
	lsls r1, r1, #0x18
	adds r0, r0, r1
	b _080423C6
_080423BE:
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r3
	lsls r0, r0, #0x18
_080423C6:
	lsrs r2, r0, #0x18
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	strb r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r4, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r4, #0x19]
	movs r5, #1
	str r5, [sp]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	ldrb r0, [r6]
	ldrb r1, [r4, #0x1b]
	cmp r0, r1
	bne _0804240C
	strb r5, [r4, #7]
_0804240C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08042414
FUN_08042414: @ 0x08042414
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r2, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0804244C
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	adds r4, r5, #0
	adds r4, #0xd0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08055ef8
	adds r0, r4, #0
	movs r1, #0x40
	movs r2, #0x40
	movs r3, #0
	bl FUN_08055f80
	ldr r0, _0804247C @ =0x00000201
	bl PlaySound_082406e0
_0804244C:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08042464
	b _0804262A
_08042464:
	movs r7, #0x40
	movs r3, #0
	mov r8, r3
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	beq _0804252C
	cmp r0, #1
	bgt _08042480
	cmp r0, #0
	beq _08042488
	b _080425F2
	.align 2, 0
_0804247C: .4byte 0x00000201
_08042480:
	cmp r0, #2
	bne _08042486
	b _080425E4
_08042486:
	b _080425F2
_08042488:
	movs r0, #8
	subs r0, r0, r6
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	mov r8, r0
	adds r1, #0x94
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080424BE
	cmp r1, #0
	blt _080424BE
	ldr r0, _080424C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080424BE
	ldr r0, _080424C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080424CC
_080424BE:
	movs r4, #0
	b _080424DA
	.align 2, 0
_080424C4: .4byte 0x030046A8
_080424C8: .4byte 0x030046AC
_080424CC:
	ldr r0, _080424EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080424DA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080424F0
	adds r0, #4
	b _080424FC
	.align 2, 0
_080424EC: .4byte 0x030046A4
_080424F0:
	ldr r0, _08042528 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080424FC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	mov r3, r8
	adds r0, r2, r3
	strh r0, [r1, #2]
	cmp r6, #7
	ble _0804251C
	ldrb r0, [r5, #0x18]
	adds r0, #1
	strb r0, [r5, #0x18]
_0804251C:
	adds r0, r5, #0
	adds r0, #0xd0
	movs r1, #1
	movs r2, #0x80
	b _080425D6
	.align 2, 0
_08042528: .4byte 0x030046A4
_0804252C:
	movs r0, #0xf
	subs r2, r0, r6
	lsls r1, r2, #2
	subs r0, r7, r1
	mov sb, r0
	cmp r6, #8
	ble _08042546
	movs r0, #0x18
	subs r0, r0, r6
	lsls r7, r0, #3
	adds r0, r1, r2
	lsls r0, r0, #2
	mov r8, r0
_08042546:
	cmp r6, #0xe
	ble _0804254E
	movs r0, #2
	strb r0, [r5, #0x18]
_0804254E:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0804257A
	cmp r1, #0
	blt _0804257A
	ldr r0, _08042580 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0804257A
	ldr r0, _08042584 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08042588
_0804257A:
	movs r4, #0
	b _08042596
	.align 2, 0
_08042580: .4byte 0x030046A8
_08042584: .4byte 0x030046AC
_08042588:
	ldr r0, _080425A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08042596:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080425AC
	adds r0, #4
	b _080425B8
	.align 2, 0
_080425A8: .4byte 0x030046A4
_080425AC:
	ldr r0, _080425E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080425B8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	mov r3, r8
	adds r0, r2, r3
	strh r0, [r1, #2]
	adds r0, r5, #0
	adds r0, #0xd0
	mov r1, sb
	adds r2, r7, #0
_080425D6:
	movs r3, #0
	bl FUN_08055f80
	b _080425F2
	.align 2, 0
_080425E0: .4byte 0x030046A4
_080425E4:
	adds r0, r5, #0
	adds r0, #0xd0
	movs r1, #2
	bl FUN_08055f1c
	movs r0, #1
	strb r0, [r5, #7]
_080425F2:
	ldrb r2, [r5, #0x1b]
	adds r0, r5, #0
	adds r0, #0x61
	movs r4, #0
	strb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	str r4, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
_0804262A:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08042638
FUN_08042638: @ 0x08042638
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r2, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08042682
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	adds r4, r5, #0
	adds r4, #0xd0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08055ef8
	adds r0, r4, #0
	movs r1, #0x40
	movs r2, #0x40
	movs r3, #0
	bl FUN_08055f80
	ldrb r0, [r5, #1]
	cmp r0, #0xe
	bne _0804267C
	ldr r0, _08042678 @ =0x0000015F
	bl PlaySound_082406e0
	b _08042682
	.align 2, 0
_08042678: .4byte 0x0000015F
_0804267C:
	ldr r0, _08042698 @ =0x00000327
	bl PlaySound_082406e0
_08042682:
	movs r7, #0x40
	movs r0, #0
	mov r8, r0
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	beq _08042758
	cmp r0, #1
	bgt _0804269C
	cmp r0, #0
	beq _080426A4
	b _0804280E
	.align 2, 0
_08042698: .4byte 0x00000327
_0804269C:
	cmp r0, #2
	bne _080426A2
	b _080427F8
_080426A2:
	b _0804280E
_080426A4:
	lsls r0, r6, #2
	subs r0, r7, r0
	mov sb, r0
	cmp r6, #8
	ble _080426BC
	lsls r7, r6, #3
	adds r1, r6, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r8, r0
_080426BC:
	cmp r6, #0xe
	ble _080426C4
	movs r0, #1
	strb r0, [r5, #0x18]
_080426C4:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080426F0
	cmp r1, #0
	blt _080426F0
	ldr r0, _080426F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080426F0
	ldr r0, _080426F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080426FC
_080426F0:
	movs r4, #0
	b _0804270A
	.align 2, 0
_080426F4: .4byte 0x030046A8
_080426F8: .4byte 0x030046AC
_080426FC:
	ldr r0, _0804271C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0804270A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08042720
	adds r0, #4
	b _0804272C
	.align 2, 0
_0804271C: .4byte 0x030046A4
_08042720:
	ldr r0, _08042754 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0804272C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	mov r3, r8
	adds r0, r2, r3
	strh r0, [r1, #2]
	adds r0, r5, #0
	adds r0, #0xd0
	mov r1, sb
	adds r2, r7, #0
	movs r3, #0
	bl FUN_08055f80
	b _0804280E
	.align 2, 0
_08042754: .4byte 0x030046A4
_08042758:
	movs r0, #0xc8
	muls r0, r6, r0
	adds r0, #0xa0
	mov r8, r0
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0804278C
	cmp r1, #0
	blt _0804278C
	ldr r0, _08042790 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0804278C
	ldr r0, _08042794 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08042798
_0804278C:
	movs r4, #0
	b _080427A6
	.align 2, 0
_08042790: .4byte 0x030046A8
_08042794: .4byte 0x030046AC
_08042798:
	ldr r0, _080427B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080427A6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080427BC
	adds r0, #4
	b _080427C8
	.align 2, 0
_080427B8: .4byte 0x030046A4
_080427BC:
	ldr r0, _080427F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080427C8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	mov r3, r8
	adds r0, r2, r3
	strh r0, [r1, #2]
	cmp r6, #7
	ble _0804280E
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	ldrb r0, [r5, #0x18]
	adds r0, #1
	strb r0, [r5, #0x18]
	b _0804280E
	.align 2, 0
_080427F4: .4byte 0x030046A4
_080427F8:
	movs r0, #1
	strb r0, [r5, #7]
	adds r0, #0xff
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xd0
	movs r1, #2
	bl FUN_08055f1c
_0804280E:
	ldrb r2, [r5, #0x1b]
	adds r0, r5, #0
	adds r0, #0x61
	strb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	ldrb r0, [r5, #1]
	cmp r0, #3
	beq _0804284C
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
_0804284C:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08042868
FUN_08042868: @ 0x08042868
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08042894
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _080428B4 @ =0x000001E9
	adds r0, r4, r2
	ldrb r2, [r0]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08041480
_08042894:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080428B4: .4byte 0x000001E9

	thumb_func_start FUN_080428b8
FUN_080428b8: @ 0x080428B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0x64
	movs r1, #0xd0
	adds r1, r1, r5
	mov sb, r1
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08042946
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	mov r3, r8
	ldr r2, [r3, #8]
	ldrh r0, [r2]
	movs r3, #0
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	ldrh r1, [r2, #2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r5, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r5, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r5, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _0804299C @ =0x00000213
	adds r0, r5, r2
	strb r4, [r0]
_08042946:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08042A38
	ldr r0, _0804299C @ =0x00000213
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080429F6
	mov r1, sb
	ldr r0, [r1]
	cmp r0, #2
	bne _080429CC
	adds r2, r5, #0
	adds r2, #0xfc
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080429EC
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080429A0
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	lsrs r0, r0, #1
	b _080429A8
	.align 2, 0
_0804299C: .4byte 0x00000213
_080429A0:
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
_080429A8:
	adds r1, r7, #0
	adds r1, #8
	adds r2, r7, #0
	adds r2, #0x10
	adds r3, r7, #5
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, r8
	bl FUN_08234e78
	ldr r2, _080429C8 @ =0x00000213
	adds r1, r5, r2
	strb r0, [r1]
	b _080429EC
	.align 2, 0
_080429C8: .4byte 0x00000213
_080429CC:
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r2, r5, #0
	adds r2, #0x6c
	adds r3, r5, #0
	adds r3, #0x61
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, r8
	adds r1, r6, #0
	bl FUN_08234e78
	strb r0, [r4]
_080429EC:
	ldr r1, _08042A0C @ =0x00000213
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08042A20
_080429F6:
	mov r2, sb
	ldr r1, [r2]
	cmp r1, #2
	bne _08042A10
	mov r0, sb
	adds r0, #0x2c
	ldrb r0, [r0, #0x1d]
	ands r1, r0
	cmp r1, #0
	beq _08042A20
	b _08042A1C
	.align 2, 0
_08042A0C: .4byte 0x00000213
_08042A10:
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08042A20
_08042A1C:
	movs r0, #1
	strb r0, [r5, #7]
_08042A20:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080414fc
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08042A38:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08042a48
FUN_08042a48: @ 0x08042A48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x64
	ldr r1, _08042AB4 @ =0x00000434
	adds r0, r6, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08042B00
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r7, #0
	ldrsh r1, [r5, r7]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r7, #4
	ldrsh r2, [r5, r7]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r4, #0
	adds r3, #0x61
	ldrb r1, [r3]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #8
	ble _08042AB8
	ldrb r2, [r3]
	adds r2, #8
	strb r2, [r3]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	b _08042AF0
	.align 2, 0
_08042AB4: .4byte 0x00000434
_08042AB8:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08042AC6
	ldrb r0, [r3]
	subs r0, #8
	b _08042ACA
_08042AC6:
	ldrb r0, [r3]
	adds r0, r0, r1
_08042ACA:
	strb r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r4, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r4, #0x19]
_08042AF0:
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	mov r8, r0
	b _08042B04
_08042B00:
	movs r2, #0
	mov r8, r2
_08042B04:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08042C02
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r1, [r0]
	ldr r7, _08042BE0 @ =0x00000225
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08042C12
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08042B94
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08042B94
	ldr r7, _08042BE4 @ =0x00000446
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0
	beq _08042B7C
	ldr r2, _08042BE8 @ =0x00000442
	adds r0, r1, r2
	ldrh r0, [r0]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08042B94
_08042B7C:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #1
	bls _08042B90
	cmp r0, #7
	beq _08042B90
	movs r1, #0
_08042B90:
	cmp r1, #0
	bne _08042C12
_08042B94:
	ldr r0, _08042BEC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08042C12
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	beq _08042C12
	movs r7, #0x87
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08042BC6
	bl FUN_080865c0
	movs r1, #1
	cmp r0, #0
	bne _08042BC8
_08042BC6:
	movs r1, #0
_08042BC8:
	cmp r1, #0
	bne _08042BD8
	movs r1, #4
	ldr r0, _08042BF0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08042BF4
_08042BD8:
	adds r0, r4, #0
	movs r1, #0
	b _08042BF8
	.align 2, 0
_08042BE0: .4byte 0x00000225
_08042BE4: .4byte 0x00000446
_08042BE8: .4byte 0x00000442
_08042BEC: .4byte 0x030047A4
_08042BF0: .4byte 0x03002BC0
_08042BF4:
	adds r0, r4, #0
	movs r1, #3
_08042BF8:
	movs r2, #0
	movs r3, #0
	bl FUN_080415cc
	b _08042C12
_08042C02:
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08042C12:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08042CDE
	ldr r3, _08042CEC @ =0x00000434
	adds r0, r6, r3
	ldr r2, [r0]
	movs r7, #0x8a
	lsls r7, r7, #2
	adds r0, r4, r7
	ldr r3, [r0]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r7, #0
	ldrsh r0, [r5, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _08042C50
	rsbs r1, r1, #0
_08042C50:
	cmp r1, r3
	bge _08042C7E
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r7, #2
	ldrsh r0, [r5, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _08042C64
	rsbs r1, r1, #0
_08042C64:
	cmp r1, #0xff
	bgt _08042C7E
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08042C78
	rsbs r0, r0, #0
_08042C78:
	movs r1, #1
	cmp r0, r3
	blt _08042C80
_08042C7E:
	movs r1, #0
_08042C80:
	cmp r1, #0
	beq _08042CDE
	ldr r3, _08042CEC @ =0x00000434
	adds r0, r6, r3
	ldr r2, [r0]
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r7, r8
	subs r0, r7, r0
	adds r1, r4, #0
	adds r1, #0x61
	ldrb r1, [r1]
	adds r1, #0x80
	subs r1, r7, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08042CC2
	rsbs r0, r0, #0
_08042CC2:
	cmp r0, #0x3f
	bgt _08042CDE
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08042CD0
	rsbs r0, r0, #0
_08042CD0:
	cmp r0, #0x1f
	bgt _08042CDE
	movs r0, #0x80
	lsls r0, r0, #4
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_08042CDE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08042CEC: .4byte 0x00000434

	thumb_func_start FUN_08042cf0
FUN_08042cf0: @ 0x08042CF0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r2, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08042D1E
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r0, #0xf6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08042D1E:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08042D46
	cmp r5, #7
	ble _08042D46
	movs r0, #1
	strb r0, [r4, #7]
_08042D46:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08042d50
FUN_08042d50: @ 0x08042D50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x5c
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0xd0
	adds r1, r1, r6
	mov sb, r1
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _08042DC4
	movs r5, #0
	strb r5, [r6, #9]
	strb r5, [r6, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	adds r4, r6, #0
	adds r4, #0x64
	mov r0, r8
	adds r1, r4, #0
	bl FUN_082362fc
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r2, r6, r3
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08235f40
	movs r4, #0x89
	lsls r4, r4, #2
	adds r0, r6, r4
	strb r5, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080415cc
_08042DC4:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r6, #0xe]
	orrs r0, r1
	strh r0, [r6, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08042DE6
	b _08042F22
_08042DE6:
	adds r3, r6, #0
	adds r3, #0x64
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r1, r6, r2
	mov r4, r8
	movs r0, #0xc
	ldrsh r2, [r4, r0]
	movs r4, #8
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r4, #4
	ldrsh r0, [r1, r4]
	movs r4, #4
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08042E2C @ =0x00001103
	mov sl, r3
	cmp r1, r0
	bgt _08042E30
	mov r3, r8
	ldrh r0, [r3, #0x1c]
	strh r0, [r7, #8]
	ldrh r0, [r3, #0x20]
	strh r0, [r7, #0xc]
	movs r0, #1
	strb r0, [r6, #7]
	b _08042F02
	.align 2, 0
_08042E2C: .4byte 0x00001103
_08042E30:
	mov r0, sb
	add r1, sp, #4
	bl FUN_08055d48
	cmp r0, #0
	beq _08042F02
	mov r4, sb
	ldr r0, [r4]
	cmp r0, #2
	bne _08042E54
	ldr r0, [sp, #4]
	movs r1, #1
	ands r0, r1
	movs r5, #0x40
	cmp r0, #0
	beq _08042E56
	movs r5, #0x20
	b _08042E56
_08042E54:
	movs r5, #0x10
_08042E56:
	mov r1, r8
	movs r2, #0x1c
	ldrsh r0, [r1, r2]
	movs r3, #8
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	mov r4, r8
	movs r2, #0x20
	ldrsh r1, [r4, r2]
	mov r3, sl
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r6, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r6, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r6, #0x19]
	add r2, sp, #8
	ldrb r4, [r7, #5]
	ldr r1, _08042EC0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r3, r2, #0
	cmp r0, #0
	blt _08042EC4
	asrs r1, r0, #0xc
	b _08042ECA
	.align 2, 0
_08042EC0: .4byte 0x085B0A08
_08042EC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08042ECA:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _08042EE4 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _08042EE8
	asrs r0, r0, #0xc
	b _08042EEE
	.align 2, 0
_08042EE4: .4byte 0x085B0A08
_08042EE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08042EEE:
	strh r0, [r2, #4]
	ldrh r0, [r3]
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	strh r0, [r7, #8]
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r2, [r7, #0xc]
	adds r0, r0, r2
	strh r0, [r7, #0xc]
_08042F02:
	mov r0, r8
	mov r1, sl
	bl FUN_08236268
	adds r0, r6, #0
	movs r1, #3
	bl FUN_080414fc
	movs r0, #1
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08042F22:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08042f34
FUN_08042f34: @ 0x08042F34
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x5c
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r1, #0xd0
	adds r1, r1, r5
	mov r8, r1
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08042F98
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r4, [r0]
	adds r4, r5, #0
	adds r4, #0x64
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_082362fc
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r2, r5, r3
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08235f40
	movs r4, #0x89
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
_08042F98:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08042FBA
	b _080430F8
_08042FBA:
	adds r2, r5, #0
	adds r2, #0x64
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r4, #0xc
	ldrsh r1, [r7, r4]
	movs r4, #8
	ldrsh r3, [r6, r4]
	mov ip, r3
	subs r1, r1, r3
	movs r4, #4
	ldrsh r3, [r0, r4]
	mov sb, r3
	movs r0, #4
	ldrsh r3, [r2, r0]
	mov r4, sb
	subs r0, r4, r3
	adds r4, r1, #0
	muls r4, r1, r4
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r4, r0
	ldr r0, _0804300C @ =0x000009C3
	mov sb, r2
	cmp r1, r0
	bgt _08043010
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r6, #8]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	movs r0, #1
	strb r0, [r5, #7]
	b _080430D8
	.align 2, 0
_0804300C: .4byte 0x000009C3
_08043010:
	mov r4, r8
	ldr r0, [r4]
	cmp r0, #2
	bne _080430D8
	adds r0, r5, #0
	adds r0, #0xfc
	ldrb r1, [r0, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080430D8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0x1c
	ldrsh r0, [r7, r2]
	mov r4, ip
	subs r0, r0, r4
	movs r2, #4
	ldrsh r1, [r1, r2]
	subs r1, r1, r3
	bl ArcTan2_8
	adds r1, r5, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r5, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r5, #0x19]
	add r2, sp, #4
	ldrb r4, [r6, #5]
	movs r0, #0x30
	mov ip, r0
	ldr r1, _08043090 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _08043094
	asrs r1, r0, #0xc
	b _0804309A
	.align 2, 0
_08043090: .4byte 0x085B0A08
_08043094:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0804309A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _080430B8 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080430BC
	asrs r0, r0, #0xc
	b _080430C2
	.align 2, 0
_080430B8: .4byte 0x085B0A08
_080430BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080430C2:
	strh r0, [r2, #4]
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r2, [r6, #8]
	adds r0, r0, r2
	strh r0, [r6, #8]
	add r0, sp, #4
	ldrh r0, [r0, #4]
	ldrh r3, [r6, #0xc]
	adds r0, r0, r3
	strh r0, [r6, #0xc]
_080430D8:
	adds r0, r7, #0
	mov r1, sb
	bl FUN_08236268
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080414fc
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_080430F8:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08043108
FUN_08043108: @ 0x08043108
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x5c
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sb, r0
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r7, r5, r1
	movs r2, #0xd0
	adds r2, r2, r5
	mov r8, r2
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _080431E0
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x64
	mov r0, sb
	adds r1, r4, #0
	bl FUN_082362fc
	ldr r1, _08043254 @ =0x000001EF
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x84
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r3, [r0]
	adds r0, r7, #0
	bl FUN_08234de8
	movs r7, #0xd0
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r1, [r0]
	add r0, sp, #4
	movs r2, #0
	bl FUN_08234f80
	mov r0, sb
	adds r1, r4, #0
	add r2, sp, #4
	bl FUN_08235f40
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	mov r1, sb
	movs r3, #0x1c
	ldrsh r0, [r1, r3]
	movs r7, #8
	ldrsh r1, [r6, r7]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r7, #4
	ldrsh r2, [r4, r7]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r1, r5, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r5, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r5, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_080431E0:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08043202
	b _08043350
_08043202:
	adds r2, r5, #0
	adds r2, #0x64
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r5, r3
	mov r4, sb
	movs r7, #0xc
	ldrsh r1, [r4, r7]
	movs r3, #8
	ldrsh r4, [r6, r3]
	subs r1, r1, r4
	movs r7, #4
	ldrsh r0, [r0, r7]
	movs r7, #4
	ldrsh r3, [r2, r7]
	subs r0, r0, r3
	adds r7, r1, #0
	muls r7, r1, r7
	adds r1, r7, #0
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	ldr r0, _08043258 @ =0x000009C3
	mov sl, r2
	cmp r1, r0
	bgt _0804325C
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r6, #8]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	movs r0, #1
	strb r0, [r5, #7]
	b _08043330
	.align 2, 0
_08043254: .4byte 0x000001EF
_08043258: .4byte 0x000009C3
_0804325C:
	mov r7, r8
	ldr r0, [r7]
	cmp r0, #2
	bne _08043330
	movs r0, #0xfc
	adds r0, r0, r5
	mov r8, r0
	ldrb r1, [r0, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08043330
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	mov r7, sb
	movs r2, #0x1c
	ldrsh r0, [r7, r2]
	subs r0, r0, r4
	movs r4, #4
	ldrsh r1, [r1, r4]
	subs r1, r1, r3
	bl ArcTan2_8
	adds r1, r5, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r7, #0xff
	ands r1, r7
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r5, #0x1a]
	adds r0, #0x20
	ands r0, r7
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r5, #0x19]
	mov r0, r8
	ldrh r1, [r0, #0x14]
	movs r0, #1
	ands r0, r1
	movs r1, #0x30
	mov ip, r1
	cmp r0, #0
	beq _080432CA
	movs r2, #0x18
	mov ip, r2
_080432CA:
	add r3, sp, #0xc
	ldrb r4, [r6, #5]
	ldr r0, _080432F0 @ =0x085B0A08
	adds r1, r4, #0
	adds r1, #0x40
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r7, #0
	ldrsh r1, [r1, r7]
	mov r2, ip
	muls r2, r1, r2
	adds r7, r3, #0
	adds r1, r0, #0
	cmp r2, #0
	blt _080432F4
	asrs r2, r2, #0xc
	b _080432FA
	.align 2, 0
_080432F0: .4byte 0x085B0A08
_080432F4:
	rsbs r0, r2, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080432FA:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08043316
	asrs r0, r0, #0xc
	b _0804331C
_08043316:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0804331C:
	strh r0, [r3, #4]
	ldrh r0, [r7]
	ldrh r3, [r6, #8]
	adds r0, r0, r3
	strh r0, [r6, #8]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	ldrh r4, [r6, #0xc]
	adds r0, r0, r4
	strh r0, [r6, #0xc]
_08043330:
	mov r0, sb
	mov r1, sl
	bl FUN_08236268
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080414fc
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08043350:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08043360
FUN_08043360: @ 0x08043360
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08043388
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08043388:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080433A0
	b _0804349E
_080433A0:
	adds r3, r5, #0
	adds r3, #0x64
	adds r4, r5, #0
	adds r4, #0x54
	movs r6, #0
	ldrsh r2, [r4, r6]
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r6, #4
	ldrsh r0, [r4, r6]
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r6, #0x82
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r0, [r0]
	mov r8, r3
	mov ip, r4
	cmp r1, r0
	bhi _080433E6
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	movs r0, #1
	strb r0, [r5, #7]
	b _08043496
_080433E6:
	adds r3, r5, #0
	adds r3, #0x61
	adds r4, r5, #0
	adds r4, #0x6c
	ldrb r6, [r3]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08043418 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	mov sb, r3
	cmp r0, #0
	blt _0804341C
	asrs r1, r0, #0xc
	b _08043422
	.align 2, 0
_08043418: .4byte 0x085B0A08
_0804341C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08043422:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0804343A
	asrs r0, r0, #0xc
	b _08043440
_0804343A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08043440:
	strh r0, [r4, #4]
	mov r3, ip
	movs r4, #0
	ldrsh r0, [r3, r4]
	mov r6, r8
	movs r2, #0
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #0x1b]
	ldrb r2, [r5, #0x1b]
	mov r4, sb
	strb r2, [r4]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08043496:
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080414fc
_0804349E:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080434ac
FUN_080434ac: @ 0x080434AC
	push {r4, r5, lr}
	adds r3, r0, #0
	ldrb r0, [r1, #6]
	lsrs r2, r0, #4
	ldrh r4, [r1, #4]
	ldr r0, _080434D0 @ =0x00000FFF
	ands r0, r4
	ldr r5, _080434D4 @ =0x0000020E
	adds r1, r3, r5
	strh r0, [r1]
	cmp r2, #1
	beq _080434D8
	cmp r2, #1
	ble _08043508
	cmp r2, #2
	beq _08043504
	b _08043508
	.align 2, 0
_080434D0: .4byte 0x00000FFF
_080434D4: .4byte 0x0000020E
_080434D8:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x1c
	ldr r1, _08043500 @ =0x00000226
	adds r2, r3, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x61
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	ldrb r2, [r2]
	cmp r0, r2
	beq _08043508
	movs r0, #8
	b _0804350A
	.align 2, 0
_08043500: .4byte 0x00000226
_08043504:
	movs r0, #9
	b _0804350A
_08043508:
	movs r0, #7
_0804350A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08043510
FUN_08043510: @ 0x08043510
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0, #8]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x64
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _0804352E
	rsbs r1, r1, #0
_0804352E:
	cmp r1, #0x28
	bgt _08043552
	ldrh r0, [r3, #2]
	adds r1, r2, #0
	adds r1, #0x68
	movs r4, #0
	ldrsh r1, [r1, r4]
	subs r0, r0, r1
	cmp r0, #0
	bge _08043544
	rsbs r0, r0, #0
_08043544:
	cmp r0, #0x28
	bgt _08043552
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_080434ac
	b _08043554
_08043552:
	movs r0, #9
_08043554:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804355c
FUN_0804355c: @ 0x0804355C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0804357C
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #1
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0804357C:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08043588
FUN_08043588: @ 0x08043588
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080435A8
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #2
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_080435A8:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080435b4
FUN_080435b4: @ 0x080435B4
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080435C8
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #3
	strb r0, [r4, #5]
_080435C8:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _080435E4
	movs r1, #1
	movs r0, #0
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_080435E4:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080435f0
FUN_080435f0: @ 0x080435F0
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043604
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #4
	strb r0, [r4, #5]
_08043604:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08043640
	ldr r1, _08043624 @ =0x00000217
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _0804362C
	ldr r1, _08043628 @ =0x00000227
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	movs r0, #1
	b _08043632
	.align 2, 0
_08043624: .4byte 0x00000217
_08043628: .4byte 0x00000227
_0804362C:
	movs r0, #1
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
_08043632:
	strb r0, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08043640:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804364c
FUN_0804364c: @ 0x0804364C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043660
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #5
	strb r0, [r4, #5]
_08043660:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _0804367C
	movs r1, #1
	movs r0, #0
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0804367C:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08043688
FUN_08043688: @ 0x08043688
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0804369C
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #6
	strb r0, [r4, #5]
_0804369C:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _080436B8
	movs r0, #0
	strb r0, [r4, #4]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_080436B8:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080436c4
FUN_080436c4: @ 0x080436C4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080436E6
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #2
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_080436E6:
	ldr r2, _08043760 @ =0x00000434
	adds r0, r5, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _08043742
	adds r3, r4, #0
	adds r3, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r4, r6
	ldr r5, [r0]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _0804370C
	rsbs r1, r1, #0
_0804370C:
	cmp r1, r5
	bge _0804373A
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043720
	rsbs r1, r1, #0
_08043720:
	cmp r1, #0xff
	bgt _0804373A
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043734
	rsbs r0, r0, #0
_08043734:
	movs r1, #1
	cmp r0, r5
	blt _0804373C
_0804373A:
	movs r1, #0
_0804373C:
	movs r0, #1
	cmp r1, #0
	bne _08043744
_08043742:
	movs r0, #0
_08043744:
	cmp r0, #0
	beq _08043768
	ldrb r1, [r4, #4]
	ldr r6, _08043764 @ =0x00000227
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r4, #4]
	str r2, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _0804376E
	.align 2, 0
_08043760: .4byte 0x00000434
_08043764: .4byte 0x00000227
_08043768:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_0804376E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08043774
FUN_08043774: @ 0x08043774
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043798
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #2
	strb r0, [r4, #5]
_08043798:
	ldr r0, [r4, #0x14]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08043890
	ldr r1, _080437F8 @ =0x000001ED
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov sb, r0
	cmp r1, #0
	beq _08043830
	bl FUN_080865c0
	adds r3, r0, #0
	movs r6, #0
	cmp r3, #0
	beq _080437E8
	adds r1, r4, #0
	adds r1, #0x64
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r7, #0
	ldrsh r0, [r3, r7]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r3, r7]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080437FC @ =0x000270FF
	cmp r1, r0
	bgt _080437E8
	movs r6, #1
_080437E8:
	cmp r6, #0
	beq _08043804
	ldr r6, _08043800 @ =0x00000236
	adds r1, r4, r6
	movs r0, #0xe1
	lsls r0, r0, #3
	b _08043820
	.align 2, 0
_080437F8: .4byte 0x000001ED
_080437FC: .4byte 0x000270FF
_08043800: .4byte 0x00000236
_08043804:
	mov r7, sb
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _08043830
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043830
	ldr r0, _0804382C @ =0x00000236
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #1
_08043820:
	strh r0, [r1]
	movs r0, #0xc
	movs r1, #0
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	b _08043902
	.align 2, 0
_0804382C: .4byte 0x00000236
_08043830:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043890
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043890
	adds r2, r5, #0
	adds r2, #0x22
	ldr r6, _0804388C @ =0x00000233
	adds r3, r4, r6
	ldrb r0, [r2]
	ldrb r7, [r3]
	cmp r0, r7
	bne _08043866
	adds r0, r5, #0
	adds r0, #0x23
	adds r6, #1
	adds r1, r4, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08043882
_08043866:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08043890
	adds r0, r5, #0
	adds r0, #0x23
	movs r7, #0x8d
	lsls r7, r7, #2
	adds r1, r4, r7
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08043890
_08043882:
	movs r0, #0xd
	movs r1, #0
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	b _08043902
	.align 2, 0
_0804388C: .4byte 0x00000233
_08043890:
	ldr r1, _08043908 @ =0x00000434
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080438EC
	adds r3, r4, #0
	adds r3, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r4, r6
	ldr r5, [r0]
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080438B6
	rsbs r1, r1, #0
_080438B6:
	cmp r1, r5
	bge _080438E4
	movs r7, #2
	ldrsh r1, [r2, r7]
	movs r6, #2
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080438CA
	rsbs r1, r1, #0
_080438CA:
	cmp r1, #0xff
	bgt _080438E4
	movs r7, #4
	ldrsh r1, [r2, r7]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080438DE
	rsbs r0, r0, #0
_080438DE:
	movs r1, #1
	cmp r0, r5
	blt _080438E6
_080438E4:
	movs r1, #0
_080438E6:
	movs r0, #1
	cmp r1, #0
	bne _080438EE
_080438EC:
	movs r0, #0
_080438EE:
	cmp r0, #0
	beq _08043910
	ldrb r1, [r4, #4]
	ldr r6, _0804390C @ =0x00000227
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r4, #4]
	str r2, [r4, #0x14]
_08043902:
	movs r0, #1
	strb r0, [r4, #8]
	b _08043952
	.align 2, 0
_08043908: .4byte 0x00000434
_0804390C: .4byte 0x00000227
_08043910:
	ldr r7, _08043940 @ =0x000001EF
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0804394C
	ldr r0, _08043944 @ =0x0000020E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r5, r0, #0
	cmp r5, #0
	bne _08043948
	mov r0, r8
	bl FUN_08234e3c
	adds r0, r4, #0
	bl FUN_08043510
	strb r0, [r4, #4]
	str r5, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _0804394C
	.align 2, 0
_08043940: .4byte 0x000001EF
_08043944: .4byte 0x0000020E
_08043948:
	subs r0, #1
	strh r0, [r1]
_0804394C:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_08043952:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08043960
FUN_08043960: @ 0x08043960
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrb r0, [r3, #8]
	cmp r0, #0
	beq _08043982
	movs r0, #0
	strb r0, [r3, #8]
	strb r0, [r3, #7]
	movs r0, #4
	strb r0, [r3, #5]
	ldr r1, _080439F8 @ =0x00000226
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #5
	lsls r0, r0, #5
	strb r0, [r3, #0x1b]
_08043982:
	ldr r6, _080439FC @ =0x00000434
	adds r0, r2, r6
	ldr r2, [r0]
	cmp r2, #0
	beq _080439DE
	adds r4, r3, #0
	adds r4, #0x64
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r5, [r0]
	movs r6, #0
	ldrsh r1, [r2, r6]
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080439A8
	rsbs r1, r1, #0
_080439A8:
	cmp r1, r5
	bge _080439D6
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080439BC
	rsbs r1, r1, #0
_080439BC:
	cmp r1, #0xff
	bgt _080439D6
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080439D0
	rsbs r0, r0, #0
_080439D0:
	movs r2, #1
	cmp r0, r5
	blt _080439D8
_080439D6:
	movs r2, #0
_080439D8:
	movs r1, #1
	cmp r2, #0
	bne _080439E0
_080439DE:
	movs r1, #0
_080439E0:
	cmp r1, #0
	beq _08043A04
	ldrb r1, [r3, #4]
	ldr r6, _08043A00 @ =0x00000227
	adds r0, r3, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r3, #4]
	str r2, [r3, #0x14]
	b _08043A10
	.align 2, 0
_080439F8: .4byte 0x00000226
_080439FC: .4byte 0x00000434
_08043A00: .4byte 0x00000227
_08043A04:
	ldrb r0, [r3, #7]
	cmp r0, #0
	beq _08043A16
	movs r0, #7
	strb r0, [r3, #4]
	str r1, [r3, #0x14]
_08043A10:
	movs r0, #1
	strb r0, [r3, #8]
	b _08043A1C
_08043A16:
	ldr r0, [r3, #0x14]
	adds r0, #1
	str r0, [r3, #0x14]
_08043A1C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08043a24
FUN_08043a24: @ 0x08043A24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043A3E
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #8
	strb r0, [r4, #5]
_08043A3E:
	ldr r0, [r4, #0x14]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08043B2C
	ldr r1, _08043A9C @ =0x000001ED
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r1, #0
	beq _08043AD0
	bl FUN_080865c0
	adds r3, r0, #0
	movs r6, #0
	cmp r3, #0
	beq _08043A8E
	adds r1, r4, #0
	adds r1, #0x64
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r7, #0
	ldrsh r0, [r3, r7]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r3, r7]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08043AA0 @ =0x000270FF
	cmp r1, r0
	bgt _08043A8E
	movs r6, #1
_08043A8E:
	cmp r6, #0
	beq _08043AA8
	ldr r6, _08043AA4 @ =0x00000236
	adds r1, r4, r6
	movs r0, #0xe1
	lsls r0, r0, #3
	b _08043AC4
	.align 2, 0
_08043A9C: .4byte 0x000001ED
_08043AA0: .4byte 0x000270FF
_08043AA4: .4byte 0x00000236
_08043AA8:
	mov r7, r8
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _08043AD0
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043AD0
	ldr r0, _08043ACC @ =0x00000236
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #1
_08043AC4:
	strh r0, [r1]
	movs r0, #0xc
	movs r1, #0
	b _08043BB0
	.align 2, 0
_08043ACC: .4byte 0x00000236
_08043AD0:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043B2C
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043B2C
	adds r2, r5, #0
	adds r2, #0x22
	ldr r6, _08043B28 @ =0x00000233
	adds r3, r4, r6
	ldrb r0, [r2]
	ldrb r7, [r3]
	cmp r0, r7
	bne _08043B06
	adds r0, r5, #0
	adds r0, #0x23
	adds r6, #1
	adds r1, r4, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08043B22
_08043B06:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08043B2C
	adds r0, r5, #0
	adds r0, #0x23
	movs r7, #0x8d
	lsls r7, r7, #2
	adds r1, r4, r7
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08043B2C
_08043B22:
	movs r0, #0xd
	movs r1, #0
	b _08043BB0
	.align 2, 0
_08043B28: .4byte 0x00000233
_08043B2C:
	ldr r1, _08043BA0 @ =0x00000434
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08043B88
	adds r3, r4, #0
	adds r3, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r4, r6
	ldr r5, [r0]
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043B52
	rsbs r1, r1, #0
_08043B52:
	cmp r1, r5
	bge _08043B80
	movs r7, #2
	ldrsh r1, [r2, r7]
	movs r6, #2
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043B66
	rsbs r1, r1, #0
_08043B66:
	cmp r1, #0xff
	bgt _08043B80
	movs r7, #4
	ldrsh r1, [r2, r7]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043B7A
	rsbs r0, r0, #0
_08043B7A:
	movs r2, #1
	cmp r0, r5
	blt _08043B82
_08043B80:
	movs r2, #0
_08043B82:
	movs r1, #1
	cmp r2, #0
	bne _08043B8A
_08043B88:
	movs r1, #0
_08043B8A:
	cmp r1, #0
	beq _08043BA8
	ldrb r1, [r4, #4]
	ldr r6, _08043BA4 @ =0x00000227
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r4, #4]
	str r2, [r4, #0x14]
	b _08043BB4
	.align 2, 0
_08043BA0: .4byte 0x00000434
_08043BA4: .4byte 0x00000227
_08043BA8:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08043BBA
	movs r0, #7
_08043BB0:
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
_08043BB4:
	movs r0, #1
	strb r0, [r4, #8]
	b _08043BC0
_08043BBA:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_08043BC0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08043bcc
FUN_08043bcc: @ 0x08043BCC
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	adds r6, r2, #0
	adds r6, #0x5c
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08043BE6
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #9
	strb r0, [r2, #5]
_08043BE6:
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08043C8E
	ldr r7, _08043C68 @ =0x00000434
	adds r0, r3, r7
	ldr r3, [r0]
	cmp r3, #0
	beq _08043C8E
	adds r4, r2, #0
	adds r4, #0x64
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r5, [r0]
	movs r7, #0
	ldrsh r1, [r3, r7]
	movs r7, #8
	ldrsh r0, [r6, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043C18
	rsbs r1, r1, #0
_08043C18:
	cmp r1, r5
	bge _08043C46
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043C2C
	rsbs r1, r1, #0
_08043C2C:
	cmp r1, #0xff
	bgt _08043C46
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043C40
	rsbs r0, r0, #0
_08043C40:
	movs r3, #1
	cmp r0, r5
	blt _08043C48
_08043C46:
	movs r3, #0
_08043C48:
	cmp r3, #0
	bne _08043C88
	ldr r6, _08043C6C @ =0x00000216
	adds r0, r2, r6
	ldrb r1, [r0]
	cmp r1, #0
	beq _08043C74
	ldr r7, _08043C70 @ =0x00000215
	adds r0, r2, r7
	ldrb r0, [r0]
	strb r0, [r2, #0x1b]
	movs r0, #3
	strb r0, [r2, #4]
	str r3, [r2, #0x14]
	b _08043C7E
	.align 2, 0
_08043C68: .4byte 0x00000434
_08043C6C: .4byte 0x00000216
_08043C70: .4byte 0x00000215
_08043C74:
	ldr r3, _08043C84 @ =0x00000227
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r2, #4]
	str r1, [r2, #0x14]
_08043C7E:
	movs r0, #1
	strb r0, [r2, #8]
	b _08043C8E
	.align 2, 0
_08043C84: .4byte 0x00000227
_08043C88:
	ldr r0, [r2, #0x14]
	adds r0, #1
	str r0, [r2, #0x14]
_08043C8E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08043c94
FUN_08043c94: @ 0x08043C94
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08043CA8
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0xa
	strb r0, [r2, #5]
_08043CA8:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08043CBA
	movs r0, #0xc
	movs r1, #0
	strb r0, [r2, #4]
	str r1, [r2, #0x14]
	movs r0, #1
	strb r0, [r2, #8]
_08043CBA:
	ldr r0, [r2, #0x14]
	adds r0, #1
	str r0, [r2, #0x14]
	pop {r0}
	bx r0

	thumb_func_start FUN_08043cc4
FUN_08043cc4: @ 0x08043CC4
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08043CD8
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0xb
	strb r0, [r2, #5]
_08043CD8:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08043CEA
	movs r0, #0xe
	movs r1, #0
	strb r0, [r2, #4]
	str r1, [r2, #0x14]
	movs r0, #1
	strb r0, [r2, #8]
_08043CEA:
	ldr r0, [r2, #0x14]
	adds r0, #1
	str r0, [r2, #0x14]
	pop {r0}
	bx r0

	thumb_func_start FUN_08043cf4
FUN_08043cf4: @ 0x08043CF4
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrb r0, [r3, #8]
	cmp r0, #0
	beq _08043D0A
	movs r0, #0
	strb r0, [r3, #8]
	strb r0, [r3, #7]
	movs r0, #0xc
	strb r0, [r3, #5]
_08043D0A:
	ldr r1, _08043D84 @ =0x00000434
	adds r0, r2, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08043D66
	adds r4, r3, #0
	adds r4, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r3, r6
	ldr r5, [r0]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043D30
	rsbs r1, r1, #0
_08043D30:
	cmp r1, r5
	bge _08043D5E
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043D44
	rsbs r1, r1, #0
_08043D44:
	cmp r1, #0xff
	bgt _08043D5E
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043D58
	rsbs r0, r0, #0
_08043D58:
	movs r2, #1
	cmp r0, r5
	blt _08043D60
_08043D5E:
	movs r2, #0
_08043D60:
	movs r1, #1
	cmp r2, #0
	bne _08043D68
_08043D66:
	movs r1, #0
_08043D68:
	cmp r1, #0
	beq _08043D8C
	ldrb r1, [r3, #4]
	ldr r6, _08043D88 @ =0x00000227
	adds r0, r3, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r3, #4]
	str r2, [r3, #0x14]
	movs r0, #1
	strb r0, [r3, #8]
	b _08043DA2
	.align 2, 0
_08043D84: .4byte 0x00000434
_08043D88: .4byte 0x00000227
_08043D8C:
	ldrb r0, [r3, #7]
	cmp r0, #0
	beq _08043D9C
	movs r0, #0xe
	strb r0, [r3, #4]
	str r1, [r3, #0x14]
	movs r0, #1
	strb r0, [r3, #8]
_08043D9C:
	ldr r0, [r3, #0x14]
	adds r0, #1
	str r0, [r3, #0x14]
_08043DA2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08043da8
FUN_08043da8: @ 0x08043DA8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043DCA
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #1
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08043DCA:
	ldr r2, _08043E38 @ =0x00000236
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _08043E44
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _08043E48
	adds r1, r5, #0
	adds r1, #0x22
	ldr r6, _08043E3C @ =0x00000231
	adds r0, r4, r6
	ldrb r2, [r1]
	ldrb r3, [r0]
	cmp r2, r3
	bne _08043DFE
	adds r0, r5, #0
	adds r0, #0x23
	adds r6, #1
	adds r1, r4, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08043E28
_08043DFE:
	cmp r2, r3
	bls _08043E0C
	ldr r1, _08043E40 @ =0x00000233
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r2, r0
	blo _08043E28
_08043E0C:
	ldr r6, _08043E40 @ =0x00000233
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r2, r0
	bne _08043E48
	adds r0, r5, #0
	adds r0, #0x23
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08043E48
_08043E28:
	movs r0, #0xf
	movs r1, #0
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _08043E4E
	.align 2, 0
_08043E38: .4byte 0x00000236
_08043E3C: .4byte 0x00000231
_08043E40: .4byte 0x00000233
_08043E44:
	subs r0, #1
	strh r0, [r1]
_08043E48:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_08043E4E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08043e54
FUN_08043e54: @ 0x08043E54
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043E6A
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0xd
	strb r0, [r4, #5]
_08043E6A:
	ldr r1, _08043EE4 @ =0x00000434
	adds r0, r2, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08043EC6
	adds r3, r4, #0
	adds r3, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r4, r6
	ldr r5, [r0]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043E90
	rsbs r1, r1, #0
_08043E90:
	cmp r1, r5
	bge _08043EBE
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043EA4
	rsbs r1, r1, #0
_08043EA4:
	cmp r1, #0xff
	bgt _08043EBE
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043EB8
	rsbs r0, r0, #0
_08043EB8:
	movs r1, #1
	cmp r0, r5
	blt _08043EC0
_08043EBE:
	movs r1, #0
_08043EC0:
	movs r5, #1
	cmp r1, #0
	bne _08043EC8
_08043EC6:
	movs r5, #0
_08043EC8:
	cmp r5, #0
	beq _08043EEC
	ldrb r1, [r4, #4]
	ldr r6, _08043EE8 @ =0x00000227
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r4, #4]
	str r2, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _08043F06
	.align 2, 0
_08043EE4: .4byte 0x00000434
_08043EE8: .4byte 0x00000227
_08043EEC:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08043F00
	adds r0, r4, #0
	bl FUN_08043510
	strb r0, [r4, #4]
	str r5, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
_08043F00:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_08043F06:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Entity286F_Update
Entity286F_Update: @ 0x08043F0C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08043F2C @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	cmp r2, #0
	beq _08043F34
	ldr r0, _08043F30 @ =0x00000434
	adds r1, r5, r0
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _08043F3A
	.align 2, 0
_08043F2C: .4byte 0x03002BE0
_08043F30: .4byte 0x00000434
_08043F34:
	ldr r1, _08043F70 @ =0x00000434
	adds r0, r5, r1
	str r2, [r0]
_08043F3A:
	bl FUN_08018a08
	adds r1, r5, #0
	adds r1, #0x24
	strb r0, [r1]
	bl GetHour
	adds r1, r5, #0
	adds r1, #0x22
	strb r0, [r1]
	bl GetMinute
	adds r2, r5, #0
	adds r2, #0x23
	strb r0, [r2]
	adds r1, r5, #0
	adds r1, #0x21
	ldrb r3, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r1, #0
	cmp r3, r0
	beq _08043F74
	subs r1, #1
	movs r0, #1
	b _08043F7A
	.align 2, 0
_08043F70: .4byte 0x00000434
_08043F74:
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0
_08043F7A:
	strb r0, [r1]
	ldrb r0, [r2]
	movs r2, #0
	strb r0, [r4]
	ldr r0, [r5, #0x28]
	movs r1, #1
	subs r1, r1, r0
	str r1, [r5, #0x28]
	lsls r1, r1, #2
	adds r0, r5, #0
	adds r0, #0x2c
	adds r0, r0, r1
	str r2, [r0]
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	beq _08043FAE
_08043F9A:
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r4, [r0]
	adds r0, r5, #0
	bl FUN_080411a0
	adds r1, r4, #0
	cmp r1, #0
	bne _08043F9A
_08043FAE:
	adds r0, r5, #0
	bl FUN_08041918
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08043FC6
	adds r0, #0x24
	bl FUN_080417dc
_08043FC6:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Entity286F_Destroy
Entity286F_Destroy: @ 0x08043FD4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #0x1c]
	cmp r4, #0
	beq _08044004
_08043FDE:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r5, [r0]
	subs r1, #0xc
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08043FF8
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_08043FF8:
	adds r0, r4, #0
	bl FUN_0804114c
	adds r4, r5, #0
	cmp r4, #0
	bne _08043FDE
_08044004:
	ldr r1, _08044010 @ =0x03002B50
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08044010: .4byte 0x03002B50

	thumb_func_start Entity286F_Init
Entity286F_Init: @ 0x08044014
	push {lr}
	adds r1, r0, #0
	ldr r0, _08044044 @ =0x03002B50
	str r1, [r0]
	movs r0, #0
	str r0, [r1, #0x18]
	str r0, [r1, #0x1c]
	str r0, [r1, #0x28]
	str r0, [r1, #0x2c]
	str r0, [r1, #0x30]
	ldr r0, _08044048 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x87
	lsls r3, r3, #3
	adds r0, r1, r3
	str r2, [r0]
	cmp r2, #0
	beq _08044050
	ldr r0, _0804404C @ =0x00000434
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _08044056
	.align 2, 0
_08044044: .4byte 0x03002B50
_08044048: .4byte 0x03002BE0
_0804404C: .4byte 0x00000434
_08044050:
	ldr r3, _0804405C @ =0x00000434
	adds r0, r1, r3
	str r2, [r0]
_08044056:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_0804405C: .4byte 0x00000434

	thumb_func_start Entity286F_Create
Entity286F_Create: @ 0x08044060
	push {r4, lr}
	ldr r0, _08044094 @ =0x03002B50
	ldr r0, [r0]
	cmp r0, #0
	bne _080440A6
	ldr r1, _08044098 @ =0x0000043C
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080440A4
	ldr r1, _0804409C @ =Entity286F_Update
	ldr r2, _080440A0 @ =Entity286F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity286F_Init
	cmp r0, #0
	bge _080440A4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080440A6
	.align 2, 0
_08044094: .4byte 0x03002B50
_08044098: .4byte 0x0000043C
_0804409C: .4byte Entity286F_Update
_080440A0: .4byte Entity286F_Destroy
_080440A4:
	adds r0, r4, #0
_080440A6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080440ac
FUN_080440ac: @ 0x080440AC
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080440CA
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #2
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_080440CA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080440d0
FUN_080440d0: @ 0x080440D0
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080440E2
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #3
	strb r0, [r1, #5]
_080440E2:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _080440FE
	movs r0, #0
	strb r0, [r1, #4]
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #8]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_080440FE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044104
FUN_08044104: @ 0x08044104
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08044116
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #4
	strb r0, [r1, #5]
_08044116:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08044132
	movs r0, #0
	strb r0, [r1, #4]
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #8]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08044132:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044138
FUN_08044138: @ 0x08044138
	push {lr}
	ldr r3, _0804414C @ =0x085AB36C
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_0804414C: .4byte 0x085AB36C

	thumb_func_start FUN_08044150
FUN_08044150: @ 0x08044150
	push {lr}
	bl FUN_08044138
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804415c
FUN_0804415c: @ 0x0804415C
	push {lr}
	bl FUN_08044150
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08044168
FUN_08044168: @ 0x08044168
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bhi _0804419C
	ldr r1, _08044198 @ =0x085AB378
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0804419E
	.align 2, 0
_08044198: .4byte 0x085AB378
_0804419C:
	movs r0, #0
_0804419E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080441a4
FUN_080441a4: @ 0x080441A4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _080441CE
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_080441CE:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080441d8
FUN_080441d8: @ 0x080441D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r4
	mov r8, r0
	movs r3, #0
	ldr r0, _08044284 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r3, r0
	bge _080442BE
	adds r6, r4, #0
	adds r6, #0x54
	str r6, [sp, #4]
	movs r7, #0
	movs r0, #1
	mov sl, r0
	movs r1, #0x64
	adds r1, r1, r4
	mov sb, r1
_08044218:
	ldr r0, _08044284 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, r8
	adds r0, #8
	adds r0, r0, r1
	ldr r5, [r0]
	ldrb r1, [r5, #6]
	cmp r1, #2
	beq _08044288
	cmp r1, #3
	bne _0804429C
	ldrh r0, [r5, #8]
	ldr r2, [sp, #4]
	strh r0, [r2]
	ldrh r0, [r5, #0xa]
	adds r1, r4, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r5, #0xc]
	adds r0, r4, #0
	adds r0, #0x58
	strh r1, [r0]
	movs r6, #0
	ldrsh r0, [r2, r6]
	mov r2, sb
	movs r6, #0
	ldrsh r1, [r2, r6]
	subs r0, r0, r1
	ldr r2, [sp, #4]
	movs r6, #4
	ldrsh r1, [r2, r6]
	mov r2, sb
	movs r6, #4
	ldrsh r2, [r2, r6]
	subs r1, r1, r2
	str r3, [sp]
	bl ArcTan2_8
	strb r0, [r4, #0x1b]
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	mov r1, sl
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r3, [sp]
	b _0804429C
	.align 2, 0
_08044284: .4byte 0x03002B4C
_08044288:
	ldrb r0, [r5, #8]
	adds r0, #5
	lsls r0, r0, #5
	strb r0, [r4, #0x1b]
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	mov r2, sl
	strb r2, [r4, #8]
_0804429C:
	mov r0, r8
	adds r1, r5, #0
	str r3, [sp]
	bl FUN_08022474
	ldr r3, [sp]
	adds r3, #1
	ldr r0, _080442D0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, r8
	adds r0, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r3, r0
	blt _08044218
_080442BE:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080442D0: .4byte 0x03002B4C

	thumb_func_start FUN_080442d4
FUN_080442d4: @ 0x080442D4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_080441d8
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080442f4
FUN_080442f4: @ 0x080442F4
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08044300
FUN_08044300: @ 0x08044300
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_08044310
FUN_08044310: @ 0x08044310
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldr r0, _0804437C @ =0x03002B50
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _08044328
	b _0804453C
_08044328:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08044388
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08044380 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08044384 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _08044392
	.align 2, 0
_0804437C: .4byte 0x03002B50
_08044380: .4byte 0xFFFF0000
_08044384: .4byte 0x0000FFFF
_08044388:
	ldr r1, _080444F8 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_08044392:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6f
	movs r1, #2
	bl VM_GetKeywordValue
	str r0, [sp, #0xc]
	ldr r1, _080444FC @ =0x0000DE23
	movs r0, #0x74
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x63
	bl VM_GetKeywordValue
	adds r7, r0, #0
	mov r0, sb
	adds r1, r5, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _080443D6
	b _0804453C
_080443D6:
	mov r1, sb
	add r2, sp, #4
	adds r3, r6, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _080443E6
	b _0804453C
_080443E6:
	movs r5, #0
	str r5, [sp]
	adds r0, r4, #0
	ldr r1, [sp, #0xc]
	mov r2, sl
	mov r3, r8
	bl FUN_08040f48
	cmp r0, #0
	bge _080443FC
	b _0804453C
_080443FC:
	cmp r7, #0
	blt _08044408
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_08041130
_08044408:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	mov r1, sb
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r6, [r0]
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	ldr r1, _08044500 @ =FUN_08044168
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08044504 @ =FUN_080442d4
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08044508 @ =FUN_0804415c
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0804450C @ =FUN_080441a4
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08044510 @ =FUN_080442f4
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08044514 @ =FUN_08044300
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	strb r5, [r4, #2]
	strb r5, [r4, #3]
	strb r5, [r4, #4]
	str r5, [r4, #0x14]
	movs r6, #1
	strb r6, [r4, #8]
	ldr r1, _08044518 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
	str r5, [r4, #0x10]
	strb r6, [r4, #9]
	strb r5, [r4, #0x18]
	mov r0, sl
	movs r1, #0
	bl FUN_08040d94
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r0, sl
	movs r1, #0
	bl FUN_08040dc0
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x62
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08044520
	bl Script_GetValue
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r2, _0804451C @ =0x000001E9
	adds r1, r4, r2
	strb r0, [r1]
	bl Script_GetValue
	movs r2, #0xf5
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	b _08044534
	.align 2, 0
_080444F8: .4byte 0xFFFF0000
_080444FC: .4byte 0x0000DE23
_08044500: .4byte FUN_08044168
_08044504: .4byte FUN_080442d4
_08044508: .4byte FUN_0804415c
_0804450C: .4byte FUN_080441a4
_08044510: .4byte FUN_080442f4
_08044514: .4byte FUN_08044300
_08044518: .4byte FUN_080421bc
_0804451C: .4byte 0x000001E9
_08044520:
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r6, [r0]
	adds r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_08044534:
	ldr r0, [sp, #0x10]
	adds r1, r4, #0
	bl FUN_08040e34
_0804453C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804454c
FUN_0804454c: @ 0x0804454C
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0804456A
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #1
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_0804456A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044570
FUN_08044570: @ 0x08044570
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08044582
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #2
	strb r0, [r1, #5]
_08044582:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _0804459E
	movs r0, #0
	strb r0, [r1, #4]
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #8]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_0804459E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080445a4
FUN_080445a4: @ 0x080445A4
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080445B6
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #3
	strb r0, [r1, #5]
_080445B6:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _080445D2
	movs r0, #0
	strb r0, [r1, #4]
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #8]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_080445D2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080445d8
FUN_080445d8: @ 0x080445D8
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080445F6
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #4
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_080445F6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080445fc
FUN_080445fc: @ 0x080445FC
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08044610
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #5
	strb r0, [r2, #5]
_08044610:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _0804462E
	movs r0, #5
	movs r1, #0
	strb r0, [r2, #4]
	str r1, [r2, #0x14]
	movs r0, #1
	strb r0, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_0804462E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044634
FUN_08044634: @ 0x08044634
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08044652
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #6
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08044652:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044658
FUN_08044658: @ 0x08044658
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _0804466C
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #7
	strb r0, [r2, #5]
_0804466C:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _0804468A
	movs r0, #7
	movs r1, #0
	strb r0, [r2, #4]
	str r1, [r2, #0x14]
	movs r0, #1
	strb r0, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_0804468A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044690
FUN_08044690: @ 0x08044690
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080446AE
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #8
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_080446AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080446b4
FUN_080446b4: @ 0x080446B4
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080446D2
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #9
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_080446D2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080446d8
FUN_080446d8: @ 0x080446D8
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080446EA
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xa
	strb r0, [r1, #5]
_080446EA:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08044706
	movs r0, #0
	strb r0, [r1, #4]
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #8]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08044706:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804470c
FUN_0804470c: @ 0x0804470C
	push {lr}
	ldr r3, _08044720 @ =0x085AB3B0
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08044720: .4byte 0x085AB3B0

	thumb_func_start FUN_08044724
FUN_08044724: @ 0x08044724
	push {lr}
	bl FUN_0804470c
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044730
FUN_08044730: @ 0x08044730
	push {lr}
	bl FUN_08044724
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0804473c
FUN_0804473c: @ 0x0804473C
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0804475E
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_0804475E:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08044784
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08044784:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804478c
FUN_0804478c: @ 0x0804478C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _080447B4
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_080447B4:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080448B8
	adds r3, r5, #0
	adds r3, #0x64
	adds r4, r5, #0
	adds r4, #0x54
	movs r6, #0
	ldrsh r2, [r4, r6]
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r6, #4
	ldrsh r0, [r4, r6]
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov ip, r3
	adds r7, r4, #0
	cmp r1, #0x64
	bgt _08044808
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	movs r0, #1
	strb r0, [r5, #7]
	b _080448B8
_08044808:
	adds r3, r5, #0
	adds r3, #0x61
	adds r4, r5, #0
	adds r4, #0x6c
	ldrb r6, [r3]
	movs r0, #5
	mov r8, r0
	ldr r2, _08044838 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov sb, r3
	cmp r0, #0
	blt _0804483C
	asrs r1, r0, #0xc
	b _08044842
	.align 2, 0
_08044838: .4byte 0x085B0A08
_0804483C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08044842:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _0804485E
	asrs r0, r0, #0xc
	b _08044864
_0804485E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08044864:
	strh r0, [r4, #4]
	movs r4, #0
	ldrsh r0, [r7, r4]
	mov r6, ip
	movs r2, #0
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r4, #4
	ldrsh r2, [r6, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #0x1b]
	ldrb r2, [r5, #0x1b]
	mov r6, sb
	strb r2, [r6]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_080448B8:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080448c8
FUN_080448c8: @ 0x080448C8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _080448EA
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_080448EA:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08044944
	ldrb r2, [r5, #0x1b]
	adds r6, r5, #0
	adds r6, #0x61
	movs r4, #0
	strb r2, [r6]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	str r4, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	ldrb r0, [r6]
	ldrb r1, [r5, #0x1b]
	cmp r0, r1
	bne _08044944
	movs r0, #1
	strb r0, [r5, #7]
_08044944:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804494c
FUN_0804494c: @ 0x0804494C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08044970
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	strh r4, [r5, #0x20]
_08044970:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080449B8
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _080449B8
	ldrh r0, [r5, #0x20]
	cmp r0, #0
	beq _0804499E
	cmp r0, #1
	beq _080449B0
	b _080449B8
_0804499E:
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	b _080449B2
_080449B0:
	strb r0, [r5, #7]
_080449B2:
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
_080449B8:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080449c0
FUN_080449c0: @ 0x080449C0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _080449E4
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	strh r4, [r5, #0x20]
_080449E4:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08044A4A
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08044A4A
	ldrh r0, [r5, #0x20]
	cmp r0, #1
	beq _08044A2E
	cmp r0, #1
	bgt _08044A16
	cmp r0, #0
	beq _08044A1C
	b _08044A4A
_08044A16:
	cmp r0, #2
	beq _08044A40
	b _08044A4A
_08044A1C:
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	b _08044A44
_08044A2E:
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	b _08044A44
_08044A40:
	movs r0, #1
	strb r0, [r5, #7]
_08044A44:
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
_08044A4A:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044a54
FUN_08044a54: @ 0x08044A54
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08044A78
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	strh r4, [r5, #0x20]
_08044A78:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044a90
FUN_08044a90: @ 0x08044A90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r1
	mov r7, sl
	adds r7, #0x20
	ldrb r0, [r1, #9]
	cmp r0, #0
	beq _08044B40
	movs r4, #0
	strb r4, [r1, #9]
	strb r4, [r1, #7]
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	movs r1, #8
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	mov r2, sl
	strh r4, [r2, #0x20]
	strh r4, [r7, #2]
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _08044B3C
	ldr r0, _08044AEC @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08044AF0 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _08044AF4 @ =0x0203B400
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0x54
	bgt _08044AFC
	ldr r0, _08044AF8 @ =0x000002DE
	bl PlaySound_082406e0
	b _08044B14
	.align 2, 0
_08044AEC: .4byte 0x030046B8
_08044AF0: .4byte 0x000003FF
_08044AF4: .4byte 0x0203B400
_08044AF8: .4byte 0x000002DE
_08044AFC:
	cmp r0, #0xa9
	bgt _08044B0C
	ldr r0, _08044B08 @ =0x000002DF
	bl PlaySound_082406e0
	b _08044B14
	.align 2, 0
_08044B08: .4byte 0x000002DF
_08044B0C:
	movs r0, #0xb8
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08044B14:
	ldr r2, _08044B30 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08044B34 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08044B38 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #1
	b _08044B3E
	.align 2, 0
_08044B30: .4byte 0x030046B8
_08044B34: .4byte 0x000003FF
_08044B38: .4byte 0x0203B400
_08044B3C:
	subs r0, #1
_08044B3E:
	strb r0, [r7, #4]
_08044B40:
	movs r0, #0xb9
	lsls r0, r0, #2
	add r0, sl
	ldr r1, [r0]
	mov r0, sl
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08044B58
	b _08044D8A
_08044B58:
	ldr r1, [r7]
	movs r0, #0xc0
	lsls r0, r0, #0xa
	cmp r1, r0
	beq _08044B64
	b _08044D3A
_08044B64:
	mov r2, sl
	ldr r0, [r2, #0x64]
	ldr r1, [r2, #0x68]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	adds r0, #0xc8
	add r1, sp, #0x1c
	strh r0, [r1]
	ldr r5, _08044D5C @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r2, #0xc
	mov sb, r2
	str r2, [sp, #4]
	movs r0, #0xa
	mov r8, r0
	str r0, [sp, #8]
	movs r6, #5
	str r6, [sp, #0xc]
	movs r4, #8
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_080149dc
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x40
	bl FUN_080149dc
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x80
	bl FUN_080149dc
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	str r6, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0xc0
	bl FUN_080149dc
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r6, #0xe
	str r6, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_080149dc
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	str r6, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x40
	bl FUN_080149dc
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	str r6, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x80
	bl FUN_080149dc
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08044D60 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08044D64 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	str r6, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0xc0
	bl FUN_080149dc
	bl FUN_0801dfe4
	adds r4, r0, #0
	bl FUN_0801e00c
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0801c0d8
	ldr r0, _08044D68 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #2
	bl FUN_0807c7c8
_08044D3A:
	ldrh r0, [r7, #2]
	adds r0, #1
	movs r4, #0
	strh r0, [r7, #2]
	mov r0, sl
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08044D8A
	ldrh r0, [r7]
	cmp r0, #0
	beq _08044D6C
	cmp r0, #1
	beq _08044D7E
	b _08044D8A
	.align 2, 0
_08044D5C: .4byte 0x030046B8
_08044D60: .4byte 0x000003FF
_08044D64: .4byte 0x0203B400
_08044D68: .4byte 0x03002BE0
_08044D6C:
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	movs r1, #6
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	b _08044D82
_08044D7E:
	mov r1, sl
	strb r0, [r1, #7]
_08044D82:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	strh r4, [r7, #2]
_08044D8A:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044d9c
FUN_08044d9c: @ 0x08044D9C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08044DC0
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	strh r4, [r5, #0x20]
_08044DC0:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044dd8
FUN_08044dd8: @ 0x08044DD8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08044DFC
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	strh r4, [r5, #0x20]
_08044DFC:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08044E62
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08044E62
	ldrh r0, [r5, #0x20]
	cmp r0, #1
	beq _08044E46
	cmp r0, #1
	bgt _08044E2E
	cmp r0, #0
	beq _08044E34
	b _08044E62
_08044E2E:
	cmp r0, #2
	beq _08044E58
	b _08044E62
_08044E34:
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	b _08044E5C
_08044E46:
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	b _08044E5C
_08044E58:
	movs r0, #1
	strb r0, [r5, #7]
_08044E5C:
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
_08044E62:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08044e6c
FUN_08044e6c: @ 0x08044E6C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08044E90
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	strh r4, [r5, #0x20]
_08044E90:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08044ED8
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08044ED8
	ldrh r0, [r5, #0x20]
	cmp r0, #0
	beq _08044EBE
	cmp r0, #1
	beq _08044ED0
	b _08044ED8
_08044EBE:
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	b _08044ED2
_08044ED0:
	strb r0, [r5, #7]
_08044ED2:
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
_08044ED8:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08044ee0
FUN_08044ee0: @ 0x08044EE0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bhi _08044F14
	ldr r1, _08044F10 @ =0x085AB3D8
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _08044F16
	.align 2, 0
_08044F10: .4byte 0x085AB3D8
_08044F14:
	movs r0, #0
_08044F16:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08044f1c
FUN_08044f1c: @ 0x08044F1C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _08044F46
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_08044F46:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08044f50
FUN_08044f50: @ 0x08044F50
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _08044F74 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _0804506A
	.align 2, 0
_08044F74: .4byte 0x03002B4C
_08044F78:
	ldr r0, _08044FAC @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	subs r0, #1
	cmp r0, #8
	bhi _0804505C
	lsls r0, r0, #2
	ldr r1, _08044FB0 @ =_08044FB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044FAC: .4byte 0x03002B4C
_08044FB0: .4byte _08044FB4
_08044FB4: @ jump table
	.4byte _0804501E @ case 0
	.4byte _08044FD8 @ case 1
	.4byte _08045034 @ case 2
	.4byte _08045038 @ case 3
	.4byte _0804503C @ case 4
	.4byte _08045040 @ case 5
	.4byte _08045044 @ case 6
	.4byte _08045048 @ case 7
	.4byte _0804504C @ case 8
_08044FD8:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0804505A
_0804501E:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08045058
_08045034:
	movs r1, #3
	b _0804504E
_08045038:
	movs r1, #4
	b _0804504E
_0804503C:
	movs r1, #5
	b _0804504E
_08045040:
	movs r1, #6
	b _0804504E
_08045044:
	movs r1, #7
	b _0804504E
_08045048:
	movs r1, #8
	b _0804504E
_0804504C:
	movs r1, #9
_0804504E:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
	str r0, [r6, #0x14]
_08045058:
	movs r0, #1
_0804505A:
	strb r0, [r6, #8]
_0804505C:
	movs r7, #1
	add r8, r7
	ldr r0, _08045084 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_0804506A:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _08045076
	b _08044F78
_08045076:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08045084: .4byte 0x03002B4C

	thumb_func_start FUN_08045088
FUN_08045088: @ 0x08045088
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08044f50
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080450a8
FUN_080450a8: @ 0x080450A8
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080450b4
FUN_080450b4: @ 0x080450B4
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_080450c4
FUN_080450c4: @ 0x080450C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08045130 @ =0x03002B50
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _080450DC
	b _080452BC
_080450DC:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804513C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08045134 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08045138 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _08045146
	.align 2, 0
_08045130: .4byte 0x03002B50
_08045134: .4byte 0xFFFF0000
_08045138: .4byte 0x0000FFFF
_0804513C:
	ldr r1, _08045278 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_08045146:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	ldr r0, _0804527C @ =0x0000DFCE
	mov sb, r0
	movs r6, #0
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _08045166
	b _080452BC
_08045166:
	adds r1, r7, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _08045176
	b _080452BC
_08045176:
	str r6, [sp]
	adds r0, r4, #0
	movs r1, #2
	mov r2, sb
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0804518A
	b _080452BC
_0804518A:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x20
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #7
	bl FUN_08040fc0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r1, r7, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	ldr r1, _08045280 @ =FUN_08044ee0
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08045284 @ =FUN_08045088
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08045288 @ =FUN_08044730
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0804528C @ =FUN_08044f1c
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08045290 @ =FUN_080450a8
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08045294 @ =FUN_080450b4
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r6, [r4, #0x14]
	movs r5, #1
	strb r5, [r4, #8]
	ldr r1, _08045298 @ =FUN_0804473c
	strb r5, [r4, #6]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
	str r6, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
	mov r0, sb
	movs r1, #0
	bl FUN_08040d94
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r0, sb
	movs r1, #0
	bl FUN_08040dc0
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x62
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080452A0
	bl Script_GetValue
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r2, _0804529C @ =0x000001E9
	adds r1, r4, r2
	strb r0, [r1]
	bl Script_GetValue
	movs r2, #0xf5
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	b _080452B4
	.align 2, 0
_08045278: .4byte 0xFFFF0000
_0804527C: .4byte 0x0000DFCE
_08045280: .4byte FUN_08044ee0
_08045284: .4byte FUN_08045088
_08045288: .4byte FUN_08044730
_0804528C: .4byte FUN_08044f1c
_08045290: .4byte FUN_080450a8
_08045294: .4byte FUN_080450b4
_08045298: .4byte FUN_0804473c
_0804529C: .4byte 0x000001E9
_080452A0:
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_080452B4:
	mov r0, sl
	adds r1, r4, #0
	bl FUN_08040e34
_080452BC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
