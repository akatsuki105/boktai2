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
_08041140:
	.byte 0x00, 0xB5, 0x81, 0x8B, 0xFF, 0xF7, 0xEA, 0xFF, 0x02, 0xBC, 0x08, 0x47

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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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

	thumb_func_start FUN_08043f0c
FUN_08043f0c: @ 0x08043F0C
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

	thumb_func_start FUN_08043fd4
FUN_08043fd4: @ 0x08043FD4
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

	thumb_func_start FUN_08044014
FUN_08044014: @ 0x08044014
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

	thumb_func_start FUN_08044060
FUN_08044060: @ 0x08044060
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
	ldr r1, _0804409C @ =FUN_08043f0c
	ldr r2, _080440A0 @ =FUN_08043fd4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08044014
	cmp r0, #0
	bge _080440A4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080440A6
	.align 2, 0
_08044094: .4byte 0x03002B50
_08044098: .4byte 0x0000043C
_0804409C: .4byte FUN_08043f0c
_080440A0: .4byte FUN_08043fd4
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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

	thumb_func_start FUN_080452cc
FUN_080452cc: @ 0x080452CC
	push {lr}
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #0
	movs r3, #0xc0
	lsls r3, r3, #1
_080452DA:
	ldrb r0, [r1, #9]
	cmp r0, #0
	bne _080452E4
	adds r0, r1, #0
	b _080452EE
_080452E4:
	adds r2, #1
	adds r1, r1, r3
	cmp r2, #0xf
	ble _080452DA
	movs r0, #0
_080452EE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080452f4
FUN_080452f4: @ 0x080452F4
	push {r4, r5, lr}
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	bne _08045304
	movs r0, #1
	rsbs r0, r0, #0
	b _0804532A
_08045304:
	adds r4, r5, #0
	adds r4, #0x60
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_080138fc
	adds r0, r5, #0
	adds r0, #0xa4
	bl FUN_0822f1c0
	movs r1, #0
	strb r1, [r5, #9]
_0804532A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08045330
FUN_08045330: @ 0x08045330
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldrb r0, [r1, #6]
	lsrs r3, r0, #4
	ldrh r1, [r1, #4]
	ldr r0, _08045354 @ =0x00000FFF
	ands r0, r1
	movs r5, #0
	movs r4, #0
	strh r0, [r2, #0x20]
	cmp r3, #1
	beq _08045362
	cmp r3, #1
	bgt _08045358
	cmp r3, #0
	beq _0804535E
	b _080453A0
	.align 2, 0
_08045354: .4byte 0x00000FFF
_08045358:
	cmp r3, #2
	beq _08045396
	b _080453A0
_0804535E:
	strb r5, [r2, #4]
	b _08045398
_08045362:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x1c
	movs r1, #0x23
	adds r1, r1, r2
	mov ip, r1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	mov r6, ip
	ldrb r6, [r6]
	cmp r0, r6
	bne _0804538E
	strb r5, [r2, #4]
	b _08045390
_0804538E:
	strb r3, [r2, #4]
_08045390:
	strb r3, [r2, #5]
	str r4, [r2, #0x10]
	b _080453AA
_08045396:
	strb r3, [r2, #4]
_08045398:
	movs r0, #1
	strb r0, [r2, #5]
	str r4, [r2, #0x10]
	b _080453AA
_080453A0:
	movs r1, #0
	strb r1, [r2, #4]
	movs r0, #1
	strb r0, [r2, #5]
	str r1, [r2, #0x10]
_080453AA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080453b0
FUN_080453b0: @ 0x080453B0
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0, #8]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x68
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _080453CE
	rsbs r1, r1, #0
_080453CE:
	ldr r4, [r2, #0x38]
	cmp r1, r4
	bhi _080453F4
	ldrh r0, [r3, #2]
	adds r1, r2, #0
	adds r1, #0x6c
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _080453E6
	rsbs r0, r0, #0
_080453E6:
	cmp r0, r4
	bhi _080453F4
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_08045330
	b _08045400
_080453F4:
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #4]
	movs r0, #1
	strb r0, [r2, #5]
	str r1, [r2, #0x10]
_08045400:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08045408
FUN_08045408: @ 0x08045408
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov sb, r0
	ldr r1, _08045514 @ =0x000F4240
	movs r4, #0x96
	lsls r4, r4, #1
	add r4, sb
	movs r7, #0
	movs r2, #0xc0
	lsls r2, r2, #1
	movs r6, #0xf
_08045426:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08045440
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045440
	ldr r0, [r4, #0x44]
	cmp r0, r1
	bhs _08045440
	adds r1, r0, #0
	adds r7, r4, #0
_08045440:
	subs r6, #1
	adds r4, r4, r2
	cmp r6, #0
	bge _08045426
	cmp r7, #0
	beq _0804551C
	mov r1, sb
	ldrh r0, [r1, #0x1c]
	cmp r0, #0
	beq _0804551C
	movs r4, #0x96
	lsls r4, r4, #1
	add r4, sb
	movs r2, #0xc4
	adds r2, r2, r7
	mov sl, r2
	adds r3, r7, #0
	adds r3, #0xc6
	str r3, [sp, #0x40]
	adds r0, r7, #0
	adds r0, #0xc8
	str r0, [sp, #0x44]
	adds r1, r7, #0
	adds r1, #0x48
	str r1, [sp, #0x38]
	mov r2, sp
	adds r2, #0x30
	str r2, [sp, #0x3c]
	movs r3, #0
	mov r8, r3
	movs r6, #0xf
	movs r5, #0xa8
	lsls r5, r5, #2
	add r5, sb
_08045484:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _080454B8
	ldr r0, [r5, #8]
	adds r1, r4, #0
	adds r1, #0x60
	ldrb r2, [r5, #2]
	str r2, [sp, #0x48]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r3, r3, r4
	str r3, [sp]
	movs r3, #6
	ldrsh r2, [r5, r3]
	str r2, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	movs r3, #0x64
	str r3, [sp, #0xc]
	ldr r2, [sp, #0x48]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r5, #8]
	mov r3, r8
	strh r3, [r5]
_080454B8:
	subs r6, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	cmp r6, #0
	bge _08045484
	ldrh r0, [r7]
	str r0, [sp, #0x10]
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	str r0, [sp, #0x14]
	ldr r3, [sp, #0x40]
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [sp, #0x18]
	ldr r2, [sp, #0x44]
	movs r3, #0
	ldrsh r0, [r2, r3]
	str r0, [sp, #0x1c]
	mov r0, sb
	ldrh r3, [r0, #0x1c]
	ldr r2, [sp, #0x38]
	add r1, sp, #0x20
	movs r6, #3
_080454EC:
	ldm r2!, {r0}
	stm r1!, {r0}
	subs r6, #1
	cmp r6, #0
	bge _080454EC
	ldr r0, _08045518 @ =0xFFFF0000
	ldr r1, [sp, #0x30]
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	str r1, [sp, #0x30]
	add r1, sp, #0x10
	ldr r2, [sp, #0x3c]
	str r1, [r2, #4]
	adds r0, r3, #0
	ldr r1, [sp, #0x3c]
	bl Script_ExecById
	movs r0, #1
	b _0804551E
	.align 2, 0
_08045514: .4byte 0x000F4240
_08045518: .4byte 0xFFFF0000
_0804551C:
	movs r0, #0
_0804551E:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08045530
FUN_08045530: @ 0x08045530
	push {lr}
	adds r3, r1, #0
	cmp r2, #8
	bhi _080455F4
	lsls r0, r2, #2
	ldr r1, _08045544 @ =_08045548
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08045544: .4byte _08045548
_08045548: @ jump table
	.4byte _0804556C @ case 0
	.4byte _080455F4 @ case 1
	.4byte _08045584 @ case 2
	.4byte _08045598 @ case 3
	.4byte _080455B0 @ case 4
	.4byte _080455BC @ case 5
	.4byte _080455C8 @ case 6
	.4byte _080455D4 @ case 7
	.4byte _080455EC @ case 8
_0804556C:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08045580 @ =0x00000177
	adds r1, r3, r2
	movs r0, #1
	b _080455F2
	.align 2, 0
_08045580: .4byte 0x00000177
_08045584:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08045594 @ =0x00000177
	adds r1, r3, r2
	b _080455F2
	.align 2, 0
_08045594: .4byte 0x00000177
_08045598:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _080455AC @ =0x00000177
	adds r1, r3, r2
	movs r0, #2
	b _080455F2
	.align 2, 0
_080455AC: .4byte 0x00000177
_080455B0:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #1
	b _080455DE
_080455BC:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #3
	b _080455DE
_080455C8:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #5
	b _080455DE
_080455D4:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #4
_080455DE:
	strb r0, [r2]
	ldr r2, _080455E8 @ =0x00000177
	adds r0, r3, r2
	strb r1, [r0]
	b _080455F4
	.align 2, 0
_080455E8: .4byte 0x00000177
_080455EC:
	ldr r0, _080455F8 @ =0x00000177
	adds r1, r3, r0
	movs r0, #0x7f
_080455F2:
	strb r0, [r1]
_080455F4:
	pop {r0}
	bx r0
	.align 2, 0
_080455F8: .4byte 0x00000177

	thumb_func_start FUN_080455fc
FUN_080455fc: @ 0x080455FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r4, r1, #0
	str r2, [sp, #4]
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r0, r4, r0
	str r0, [sp, #8]
	movs r1, #0xc4
	adds r1, r1, r4
	mov sl, r1
	ldrb r3, [r4, #5]
	cmp r3, #0
	beq _080456C6
	movs r5, #0
	strb r5, [r4, #5]
	ldrb r0, [r4, #7]
	ldr r2, _0804567C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r3, _08045680 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov ip, r0
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	adds r1, r2, #0
	strb r2, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08045684
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, ip
	strb r2, [r0]
	b _08045690
	.align 2, 0
_0804567C: .4byte 0x085AB404
_08045680: .4byte 0x0000192C
_08045684:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
_08045690:
	adds r5, r0, #0
	ldrb r0, [r1]
	adds r0, r0, r3
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r1, [r5]
	cmp r1, #0
	beq _080456B6
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _080456BE
_080456B6:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080456BE:
	str r1, [r6, #8]
	movs r1, #0
	strb r1, [r4, #8]
	b _08045760
_080456C6:
	ldrb r0, [r4, #7]
	ldr r2, _0804571C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r0, _08045720 @ =0x0000192C
	adds r7, r7, r0
	ldrh r1, [r1]
	mov ip, r1
	movs r1, #1
	mov sb, r1
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	adds r1, r2, #0
	strb r2, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08045724
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, sb
	strb r2, [r0]
	b _08045730
	.align 2, 0
_0804571C: .4byte 0x085AB404
_08045720: .4byte 0x0000192C
_08045724:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r3, [r0]
_08045730:
	adds r5, r0, #0
	ldrb r0, [r1]
	add r0, ip
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	movs r3, #1
	mov r0, sb
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r1, [r5]
	cmp r1, #0
	beq _08045756
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _0804575E
_08045756:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804575E:
	str r1, [r6, #8]
_08045760:
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #0xf
	ands r1, r2
	ldr r3, [sp, #4]
	cmp r1, r3
	bne _080457F4
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _0804579C
	mov r1, r8
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _0804579C
	movs r0, #5
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	movs r0, #0
	str r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	b _0804587E
_0804579C:
	ldrb r1, [r4, #0x1f]
	cmp r1, #0
	beq _080457F4
	mov r6, r8
	ldrb r1, [r6, #0x1e]
	cmp r1, #0
	beq _080457F4
	mov r3, r8
	adds r3, #0x20
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r1, [r3]
	ldrb r7, [r5]
	cmp r1, r7
	bne _080457CA
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _080457E4
_080457CA:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r5, [r5]
	cmp r1, r5
	bne _080457F4
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhi _080457F4
_080457E4:
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #6
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _0804587E
_080457F4:
	mov r1, r8
	ldr r3, [r1, #0x18]
	ldr r5, [r4, #0x3c]
	movs r6, #0
	ldrsh r2, [r3, r6]
	mov r7, sl
	movs r6, #0
	ldrsh r1, [r7, r6]
	subs r2, r2, r1
	cmp r2, #0
	bge _0804580C
	rsbs r2, r2, #0
_0804580C:
	cmp r2, r5
	bge _0804583E
	movs r7, #2
	ldrsh r2, [r3, r7]
	mov r6, sl
	movs r7, #2
	ldrsh r1, [r6, r7]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045822
	rsbs r2, r2, #0
_08045822:
	cmp r2, #0xff
	bgt _0804583E
	movs r1, #4
	ldrsh r2, [r3, r1]
	mov r3, sl
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045838
	rsbs r2, r2, #0
_08045838:
	movs r1, #1
	cmp r2, r5
	blt _08045840
_0804583E:
	movs r1, #0
_08045840:
	cmp r1, #0
	beq _08045858
	ldrb r0, [r4, #4]
	movs r1, #0
	strb r0, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0x10]
	movs r0, #0
	b _0804587E
_08045858:
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _0804587E
	ldrh r1, [r4, #0x20]
	cmp r1, #0
	bne _0804587A
	ldr r0, [sp, #8]
	bl FUN_08234e3c
	adds r0, r4, #0
	bl FUN_080453b0
	b _0804587E
_0804587A:
	subs r1, #1
	strh r1, [r4, #0x20]
_0804587E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08045890
FUN_08045890: @ 0x08045890
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r4, r1, #0
	str r2, [sp, #4]
	adds r0, r4, #0
	adds r0, #0xc4
	str r0, [sp, #8]
	ldrb r5, [r4, #5]
	cmp r5, #0
	beq _08045968
	movs r5, #0
	strb r5, [r4, #5]
	ldrb r0, [r4, #7]
	ldr r2, _0804590C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r3, _08045910 @ =0x0000192C
	adds r7, r7, r3
	ldrh r1, [r1]
	mov ip, r1
	movs r0, #1
	mov sl, r0
	adds r2, r4, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r3, r1, #0
	ands r3, r0
	adds r1, r3, #0
	strb r3, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r2
	cmp r0, #2
	bhi _08045914
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, sl
	strb r2, [r0]
	b _08045920
	.align 2, 0
_0804590C: .4byte 0x085AB404
_08045910: .4byte 0x0000192C
_08045914:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
_08045920:
	adds r5, r0, #0
	ldrb r0, [r1]
	add r0, ip
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	mov r3, sl
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r1, [r5]
	cmp r1, #0
	beq _08045946
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _0804594E
_08045946:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804594E:
	str r1, [r6, #8]
	movs r1, #0
	strb r1, [r4, #8]
	adds r1, r4, #0
	adds r1, #0x23
	ldrb r1, [r1]
	adds r1, #5
	lsls r1, r1, #5
	adds r2, r4, #0
	adds r2, #0x22
	strb r1, [r2]
	adds r1, r2, #0
	b _08045A08
_08045968:
	ldrb r0, [r4, #7]
	ldr r2, _080459C0 @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r3, r8
	adds r7, r0, r3
	ldr r0, _080459C4 @ =0x0000192C
	adds r7, r7, r0
	ldrh r1, [r1]
	mov ip, r1
	movs r1, #1
	mov sl, r1
	adds r2, r4, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r3, r1, #0
	ands r3, r0
	adds r1, r3, #0
	strb r3, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r2
	cmp r0, #2
	bhi _080459C8
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, sl
	strb r2, [r0]
	b _080459D4
	.align 2, 0
_080459C0: .4byte 0x085AB404
_080459C4: .4byte 0x0000192C
_080459C8:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
_080459D4:
	adds r5, r0, #0
	ldrb r0, [r1]
	add r0, ip
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	movs r3, #1
	mov r0, sl
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r1, [r5]
	cmp r1, #0
	beq _080459FA
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _08045A02
_080459FA:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08045A02:
	str r1, [r6, #8]
	adds r1, r4, #0
	adds r1, #0x22
_08045A08:
	ldrb r1, [r1]
	mov r3, sb
	ldrb r2, [r3]
	subs r1, r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r5, r1, #0
	lsls r1, r5, #0x18
	asrs r3, r1, #0x18
	cmp r3, #8
	ble _08045A28
	adds r1, r2, #0
	adds r1, #8
	mov r6, sb
	strb r1, [r6]
	b _08045A40
_08045A28:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r3, r1
	bge _08045A3A
	adds r1, r2, #0
	subs r1, #8
	mov r7, sb
	strb r1, [r7]
	b _08045A40
_08045A3A:
	adds r1, r2, r5
	mov r2, sb
	strb r1, [r2]
_08045A40:
	mov r3, r8
	ldr r1, [r3, #0x28]
	movs r2, #0xf
	ands r1, r2
	ldr r6, [sp, #4]
	cmp r1, r6
	bne _08045AD4
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _08045A7C
	mov r1, r8
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _08045A7C
	movs r0, #5
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	movs r0, #0
	str r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	b _08045B5A
_08045A7C:
	ldrb r1, [r4, #0x1f]
	cmp r1, #0
	beq _08045AD4
	mov r7, r8
	ldrb r1, [r7, #0x1e]
	cmp r1, #0
	beq _08045AD4
	mov r3, r8
	adds r3, #0x20
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r1, [r3]
	ldrb r2, [r5]
	cmp r1, r2
	bne _08045AAA
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08045AC4
_08045AAA:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r5, [r5]
	cmp r1, r5
	bne _08045AD4
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhi _08045AD4
_08045AC4:
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #6
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _08045B5A
_08045AD4:
	mov r6, r8
	ldr r3, [r6, #0x18]
	ldr r5, [r4, #0x3c]
	movs r7, #0
	ldrsh r2, [r3, r7]
	ldr r6, [sp, #8]
	movs r7, #0
	ldrsh r1, [r6, r7]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045AEC
	rsbs r2, r2, #0
_08045AEC:
	cmp r2, r5
	bge _08045B1E
	movs r1, #2
	ldrsh r2, [r3, r1]
	ldr r6, [sp, #8]
	movs r7, #2
	ldrsh r1, [r6, r7]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045B02
	rsbs r2, r2, #0
_08045B02:
	cmp r2, #0xff
	bgt _08045B1E
	movs r1, #4
	ldrsh r2, [r3, r1]
	ldr r3, [sp, #8]
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045B18
	rsbs r2, r2, #0
_08045B18:
	movs r3, #1
	cmp r2, r5
	blt _08045B20
_08045B1E:
	movs r3, #0
_08045B20:
	cmp r3, #0
	beq _08045B34
	movs r0, #0
	strb r0, [r4, #0xc]
	movs r1, #3
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _08045B5A
_08045B34:
	mov r7, sb
	ldrb r1, [r7]
	adds r1, #0x10
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r1, r2
	adds r2, r4, #0
	adds r2, #0x23
	ldrb r2, [r2]
	cmp r1, r2
	bne _08045B5A
	strb r3, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r3, [r4, #0x10]
	movs r0, #0
_08045B5A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08045b6c
FUN_08045b6c: @ 0x08045B6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	adds r4, r1, #0
	str r2, [sp, #0xc]
	movs r0, #0x60
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r1, r4, r1
	str r1, [sp, #0x10]
	movs r2, #0x68
	adds r2, r2, r4
	mov sb, r2
	adds r3, r4, #0
	adds r3, #0xa4
	str r3, [sp, #0x14]
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08045C64
	movs r5, #0
	strb r5, [r4, #5]
	ldr r2, [r1, #8]
	ldrh r0, [r2]
	mov r6, sb
	movs r3, #0
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	ldrh r1, [r2, #2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	mov r6, sl
	strb r0, [r6, #5]
	ldrb r0, [r4, #7]
	ldr r2, _08045C04 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	ldr r6, [sp, #0x14]
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r3, _08045C08 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov ip, r0
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08045C0C
	adds r0, r4, #0
	adds r0, #0x2c
	mov r1, ip
	strb r1, [r0]
	b _08045C12
	.align 2, 0
_08045C04: .4byte 0x085AB414
_08045C08: .4byte 0x0000192C
_08045C0C:
	adds r0, r4, #0
	adds r0, #0x2c
	strb r5, [r0]
_08045C12:
	adds r2, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	bls _08045C22
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	b _08045C28
_08045C22:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0
_08045C28:
	strb r0, [r1]
	adds r5, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r0, [r5]
	cmp r0, #0
	beq _08045C50
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08045C58
_08045C50:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08045C58:
	str r0, [r6, #8]
	movs r0, #0
	strb r0, [r4, #8]
	adds r1, r4, #0
	adds r1, #0x36
	strb r0, [r1]
_08045C64:
	mov r2, r8
	ldr r0, [r2, #0x28]
	movs r1, #0xf
	ands r0, r1
	ldr r3, [sp, #0xc]
	cmp r0, r3
	bne _08045CF8
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08045CA0
	mov r0, r8
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	beq _08045CA0
	movs r0, #5
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	movs r0, #0
	str r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	b _08045E58
_08045CA0:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _08045CF8
	mov r5, r8
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08045CF8
	mov r2, r8
	adds r2, #0x20
	adds r3, r4, #0
	adds r3, #0x26
	ldrb r0, [r2]
	ldrb r6, [r3]
	cmp r0, r6
	bne _08045CCE
	mov r0, r8
	adds r0, #0x21
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08045CE8
_08045CCE:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08045CF8
	mov r0, r8
	adds r0, #0x21
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08045CF8
_08045CE8:
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #6
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _08045E58
_08045CF8:
	mov r0, r8
	ldr r2, [r0, #0x18]
	ldr r3, [r4, #0x3c]
	movs r5, #0
	ldrsh r1, [r2, r5]
	mov r6, sb
	movs r5, #0
	ldrsh r0, [r6, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08045D10
	rsbs r1, r1, #0
_08045D10:
	cmp r1, r3
	bge _08045D42
	movs r6, #2
	ldrsh r1, [r2, r6]
	mov r5, sb
	movs r6, #2
	ldrsh r0, [r5, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08045D26
	rsbs r1, r1, #0
_08045D26:
	cmp r1, #0xff
	bgt _08045D42
	movs r0, #4
	ldrsh r1, [r2, r0]
	mov r2, sb
	movs r5, #4
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08045D3C
	rsbs r1, r1, #0
_08045D3C:
	movs r0, #1
	cmp r1, r3
	blt _08045D44
_08045D42:
	movs r0, #0
_08045D44:
	cmp r0, #0
	beq _08045D54
	ldrb r0, [r4, #4]
	movs r1, #0
	strb r0, [r4, #0xc]
	movs r0, #3
	strb r0, [r4, #4]
	b _08045DAE
_08045D54:
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _08045D9E
	ldr r0, [sp, #0x14]
	ldrb r1, [r0, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08045D98
	ldr r2, [sp, #0x14]
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	movs r5, #0x20
	cmp r0, #0
	beq _08045D7C
	movs r5, #0x10
_08045D7C:
	mov r1, sl
	adds r1, #8
	mov r2, sl
	adds r2, #0x10
	mov r3, sl
	adds r3, #5
	movs r0, #0x28
	str r0, [sp]
	str r0, [sp, #4]
	str r5, [sp, #8]
	ldr r0, [sp, #0x10]
	bl FUN_08234e78
	strb r0, [r6]
_08045D98:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08045DB8
_08045D9E:
	ldr r3, [sp, #0x14]
	ldrb r1, [r3, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08045DB8
	movs r1, #0
	strb r1, [r4, #4]
_08045DAE:
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0x10]
	movs r0, #0
	b _08045E58
_08045DB8:
	ldrb r0, [r4, #7]
	ldr r2, _08045E00 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r5, r8
	adds r7, r0, r5
	ldr r0, _08045E04 @ =0x0000192C
	adds r7, r7, r0
	ldrh r3, [r1]
	movs r1, #1
	mov r8, r1
	adds r0, r4, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08045E08
	adds r0, r4, #0
	adds r0, #0x2c
	mov r2, r8
	strb r2, [r0]
	adds r2, r0, #0
	b _08045E12
	.align 2, 0
_08045E00: .4byte 0x085AB414
_08045E04: .4byte 0x0000192C
_08045E08:
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_08045E12:
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	bls _08045E20
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	b _08045E26
_08045E20:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0
_08045E26:
	strb r0, [r1]
	adds r5, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r1, [r5]
	cmp r1, #0
	beq _08045E4E
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _08045E56
_08045E4E:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08045E56:
	str r1, [r6, #8]
_08045E58:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08045e68
FUN_08045e68: @ 0x08045E68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r6, r1, #0
	str r2, [sp, #4]
	adds r7, r6, #0
	adds r7, #0xc4
	ldr r0, _08045EE4 @ =0x00001A2C
	add r0, r8
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	str r0, [sp, #8]
	mov r0, r8
	ldr r3, [r0, #0x18]
	movs r1, #0
	ldrsh r2, [r3, r1]
	movs r4, #0
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r4, #4
	ldrsh r0, [r7, r4]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r5, r1, #0
	muls r5, r1, r5
	adds r1, r5, #0
	adds r0, r0, r1
	str r0, [r6, #0x14]
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #0
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r5, #4
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r2, r6, #0
	adds r2, #0x65
	ldrb r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	lsls r0, r4, #0x18
	asrs r3, r0, #0x18
	cmp r3, #8
	ble _08045EE8
	adds r0, r1, #0
	adds r0, #8
	b _08045EF8
	.align 2, 0
_08045EE4: .4byte 0x00001A2C
_08045EE8:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08045EF6
	adds r0, r1, #0
	subs r0, #8
	b _08045EF8
_08045EF6:
	adds r0, r1, r4
_08045EF8:
	strb r0, [r2]
	ldrb r4, [r6, #5]
	cmp r4, #0
	beq _08045FAE
	movs r0, #0
	mov sb, r0
	mov r1, sb
	strb r1, [r6, #5]
	ldrb r0, [r6, #7]
	ldr r2, _08045F5C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	add r0, r8
	mov ip, r0
	ldr r2, _08045F60 @ =0x0000192C
	add ip, r2
	ldrh r3, [r1]
	adds r2, r6, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r4, r1, #0
	ands r4, r0
	adds r1, r4, #0
	strb r4, [r6, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r2
	cmp r0, #2
	bhi _08045F64
	movs r0, #8
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	movs r4, #1
	strb r4, [r0]
	b _08045F72
	.align 2, 0
_08045F5C: .4byte 0x085AB404
_08045F60: .4byte 0x0000192C
_08045F64:
	adds r1, r6, #0
	adds r1, #0x2c
	strb r4, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	mov r2, sb
	strb r2, [r0]
_08045F72:
	adds r4, r0, #0
	ldrb r0, [r1]
	adds r0, r0, r3
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	movs r3, #1
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	mov r1, ip
	bl FUN_082370cc
	ldrb r1, [r4]
	cmp r1, #0
	beq _08045F98
	ldr r1, [r5, #8]
	movs r2, #4
	orrs r1, r2
	b _08045FA0
_08045F98:
	ldr r1, [r5, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08045FA0:
	str r1, [r5, #8]
	movs r1, #1
	strb r1, [r6, #8]
	mov r3, sl
	ldrb r1, [r3]
	strb r1, [r6, #0xb]
	b _08046046
_08045FAE:
	ldrb r0, [r6, #7]
	ldr r2, _08046004 @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	add r0, r8
	mov ip, r0
	ldr r0, _08046008 @ =0x0000192C
	add ip, r0
	ldrh r1, [r1]
	mov sb, r1
	adds r2, r6, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r3, r1, #0
	ands r3, r0
	adds r1, r3, #0
	strb r3, [r6, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r2
	cmp r0, #2
	bhi _0804600C
	movs r0, #8
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	movs r2, #1
	strb r2, [r0]
	b _08046018
	.align 2, 0
_08046004: .4byte 0x085AB404
_08046008: .4byte 0x0000192C
_0804600C:
	adds r1, r6, #0
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	strb r4, [r0]
_08046018:
	adds r4, r0, #0
	ldrb r0, [r1]
	add r0, sb
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	movs r3, #1
	str r3, [sp]
	adds r0, r5, #0
	mov r1, ip
	bl FUN_082370cc
	ldrb r1, [r4]
	cmp r1, #0
	beq _0804603C
	ldr r1, [r5, #8]
	movs r2, #4
	orrs r1, r2
	b _08046044
_0804603C:
	ldr r1, [r5, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08046044:
	str r1, [r5, #8]
_08046046:
	mov r3, r8
	ldr r1, [r3, #0x28]
	movs r2, #0xf
	ands r1, r2
	ldr r4, [sp, #4]
	cmp r1, r4
	bne _080460DA
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _08046082
	mov r1, r8
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _08046082
	movs r0, #5
	strb r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #5]
	movs r0, #0
	str r0, [r6, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r6, #0x1c]
	movs r0, #0
	b _08046244
_08046082:
	ldrb r1, [r6, #0x1f]
	cmp r1, #0
	beq _080460DA
	mov r5, r8
	ldrb r1, [r5, #0x1e]
	cmp r1, #0
	beq _080460DA
	mov r3, r8
	adds r3, #0x20
	adds r4, r6, #0
	adds r4, #0x26
	ldrb r1, [r3]
	ldrb r2, [r4]
	cmp r1, r2
	bne _080460B0
	mov r1, r8
	adds r1, #0x21
	adds r2, r6, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _080460CA
_080460B0:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r4, [r4]
	cmp r1, r4
	bne _080460DA
	mov r1, r8
	adds r1, #0x21
	adds r2, r6, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhi _080460DA
_080460CA:
	movs r0, #0
	strb r0, [r6, #0x1e]
	movs r1, #6
	strb r1, [r6, #4]
	movs r1, #1
	strb r1, [r6, #5]
	str r0, [r6, #0x10]
	b _08046244
_080460DA:
	mov r4, r8
	ldr r3, [r4, #0x18]
	ldr r4, [r6, #0x3c]
	movs r5, #0
	ldrsh r2, [r3, r5]
	movs r5, #0
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _080460F0
	rsbs r2, r2, #0
_080460F0:
	cmp r2, r4
	bge _0804611E
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r5, #2
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _08046104
	rsbs r2, r2, #0
_08046104:
	cmp r2, #0xff
	bgt _0804611E
	movs r1, #4
	ldrsh r2, [r3, r1]
	movs r5, #4
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _08046118
	rsbs r2, r2, #0
_08046118:
	movs r1, #1
	cmp r2, r4
	blt _08046120
_0804611E:
	movs r1, #0
_08046120:
	cmp r1, #0
	beq _08046196
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r3, #0
	ldrsh r2, [r1, r3]
	mov ip, r2
	movs r4, #0
	ldrsh r0, [r7, r4]
	subs r3, r2, r0
	movs r5, #4
	ldrsh r4, [r1, r5]
	movs r2, #4
	ldrsh r1, [r7, r2]
	subs r2, r4, r1
	adds r5, r3, #0
	muls r5, r3, r5
	mov sb, r5
	adds r3, r2, #0
	muls r3, r2, r3
	adds r2, r3, #0
	add sb, r2
	mov r5, ip
	subs r0, r0, r5
	subs r1, r1, r4
	bl FUN_0823785c
	adds r2, r0, #0
	ldr r1, [sp, #8]
	subs r2, r1, r2
	mov r3, sl
	ldrb r1, [r3]
	adds r1, #0x80
	ldr r4, [sp, #8]
	subs r1, r4, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #0
	bge _08046174
	rsbs r2, r2, #0
_08046174:
	mov r5, r8
	ldr r3, [r5, #0x18]
	cmp r2, #0x3f
	bgt _08046196
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	bge _08046186
	rsbs r1, r1, #0
_08046186:
	cmp r1, #0x1f
	bgt _08046196
	adds r2, r6, #0
	adds r2, #0x37
	movs r1, #1
	strb r1, [r2]
	mov r1, sb
	str r1, [r6, #0x44]
_08046196:
	ldrb r2, [r6, #0xb]
	mov r4, sl
	ldrb r1, [r4]
	subs r1, r2, r1
	cmp r1, #0
	bge _080461A4
	rsbs r1, r1, #0
_080461A4:
	cmp r1, #0x3f
	ble _080461EC
	ldr r1, [r6, #0x40]
	lsrs r4, r1, #1
	movs r5, #0
	ldrsh r2, [r3, r5]
	movs r5, #0
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _080461BC
	rsbs r2, r2, #0
_080461BC:
	cmp r2, r4
	bge _08046234
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r5, #2
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _080461D0
	rsbs r2, r2, #0
_080461D0:
	cmp r2, #0xff
	bgt _08046234
	movs r1, #4
	ldrsh r2, [r3, r1]
	movs r3, #4
	ldrsh r1, [r7, r3]
	subs r2, r2, r1
	cmp r2, #0
	bge _080461E4
	rsbs r2, r2, #0
_080461E4:
	movs r3, #1
	cmp r2, r4
	blt _08046236
	b _08046234
_080461EC:
	adds r4, r3, #0
	ldr r5, [r6, #0x40]
	mov sb, r5
	movs r2, #0
	ldrsh r1, [r4, r2]
	mov r8, r1
	movs r5, #0
	ldrsh r1, [r7, r5]
	mov r5, r8
	subs r2, r5, r1
	cmp r2, #0
	bge _08046206
	rsbs r2, r2, #0
_08046206:
	cmp r2, sb
	bge _08046234
	movs r1, #2
	ldrsh r2, [r4, r1]
	movs r4, #2
	ldrsh r1, [r7, r4]
	subs r2, r2, r1
	cmp r2, #0
	bge _0804621A
	rsbs r2, r2, #0
_0804621A:
	cmp r2, #0xff
	bgt _08046234
	movs r5, #4
	ldrsh r2, [r3, r5]
	movs r3, #4
	ldrsh r1, [r7, r3]
	subs r2, r2, r1
	cmp r2, #0
	bge _0804622E
	rsbs r2, r2, #0
_0804622E:
	movs r3, #1
	cmp r2, sb
	blt _08046236
_08046234:
	movs r3, #0
_08046236:
	cmp r3, #0
	bne _08046244
	ldrb r1, [r6, #0xc]
	strb r1, [r6, #4]
	movs r1, #1
	strb r1, [r6, #5]
	str r3, [r6, #0x10]
_08046244:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08046254
FUN_08046254: @ 0x08046254
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r3, r0, #0
	adds r5, r1, #0
	ldrb r1, [r5, #5]
	cmp r1, #0
	beq _08046324
	movs r6, #0
	strb r6, [r5, #5]
	ldrb r0, [r5, #7]
	ldr r2, _080462B8 @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r4, r5, #0
	adds r4, #0xa4
	lsls r0, r0, #5
	adds r7, r0, r3
	ldr r0, _080462BC @ =0x0000192C
	adds r7, r7, r0
	ldrh r3, [r1]
	movs r2, #1
	mov ip, r2
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	adds r1, r2, #0
	strb r2, [r5, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080462C0
	movs r0, #8
	subs r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x2d
	mov r2, ip
	strb r2, [r0]
	b _080462CC
	.align 2, 0
_080462B8: .4byte 0x085AB404
_080462BC: .4byte 0x0000192C
_080462C0:
	adds r1, r5, #0
	adds r1, #0x2c
	strb r2, [r1]
	adds r0, r5, #0
	adds r0, #0x2d
	strb r6, [r0]
_080462CC:
	adds r6, r0, #0
	ldrb r0, [r1]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r0, [r6]
	cmp r0, #0
	beq _080462F2
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _080462FA
_080462F2:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080462FA:
	str r0, [r4, #8]
	movs r2, #0
	movs r0, #1
	strb r0, [r5, #8]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x60
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #1
	bl FUN_080da9c4
	adds r1, r0, #0
	str r1, [r4]
_08046324:
	ldr r1, [r5, #0x10]
	cmp r1, #7
	bls _08046336
	movs r1, #5
	movs r2, #0
	strb r1, [r5, #4]
	movs r1, #1
	strb r1, [r5, #5]
	str r2, [r5, #0x10]
_08046336:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08046340
FUN_08046340: @ 0x08046340
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x60
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r6, #5]
	cmp r0, #0
	beq _0804642C
	movs r4, #0
	strb r4, [r6, #5]
	ldrb r0, [r6, #7]
	ldr r2, _080463AC @ =0x085AB424
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	add r0, sb
	mov ip, r0
	ldr r2, _080463B0 @ =0x0000192C
	add ip, r2
	ldrh r3, [r1]
	movs r0, #1
	mov sl, r0
	adds r0, r6, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r6, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080463B4
	adds r0, r6, #0
	adds r0, #0x2c
	mov r1, sl
	strb r1, [r0]
	b _080463BA
	.align 2, 0
_080463AC: .4byte 0x085AB424
_080463B0: .4byte 0x0000192C
_080463B4:
	adds r0, r6, #0
	adds r0, #0x2c
	strb r4, [r0]
_080463BA:
	adds r2, r0, #0
	ldrb r0, [r6, #0x1a]
	cmp r0, #1
	bls _080463CA
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #1
	b _080463D0
_080463CA:
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #0
_080463D0:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	mov r3, sl
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	mov r1, ip
	bl FUN_082370cc
	ldrb r0, [r4]
	cmp r0, #0
	beq _080463F8
	ldr r0, [r5, #8]
	movs r1, #4
	orrs r0, r1
	b _08046400
_080463F8:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08046400:
	str r0, [r5, #8]
	movs r5, #0
	movs r0, #1
	strb r0, [r6, #8]
	adds r4, r7, #0
	adds r4, #8
	mov r0, r8
	adds r1, r4, #0
	bl FUN_082362fc
	adds r0, r6, #0
	adds r0, #0x29
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	adds r2, #0x2c
	add r2, sb
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08235f40
	strb r5, [r6, #0xa]
_0804642C:
	adds r2, r7, #0
	adds r2, #8
	mov r3, r8
	movs r0, #0x1c
	ldrsh r1, [r3, r0]
	movs r3, #8
	ldrsh r0, [r7, r3]
	subs r4, r1, r0
	mov r0, r8
	movs r3, #0x20
	ldrsh r1, [r0, r3]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08046480 @ =0x000003FF
	adds r5, r2, #0
	cmp r1, r0
	bgt _08046484
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r7, #8]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r7, #0xc]
	movs r0, #8
	strb r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #5]
	str r1, [r6, #0x10]
	movs r0, #0
	b _080465A0
	.align 2, 0
_08046480: .4byte 0x000003FF
_08046484:
	adds r0, r4, #0
	adds r1, r3, #0
	bl FUN_0823785c
	strb r0, [r7, #5]
	add r3, sp, #4
	ldrb r4, [r7, #5]
	ldr r2, _080464B0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080464B4
	asrs r1, r0, #0xc
	b _080464BA
	.align 2, 0
_080464B0: .4byte 0x085B0A08
_080464B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080464BA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _080464D8 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _080464DC
	asrs r0, r0, #0xc
	b _080464E2
	.align 2, 0
_080464D8: .4byte 0x085B0A08
_080464DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080464E2:
	strh r0, [r3, #4]
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r3, [r7, #8]
	adds r0, r0, r3
	strh r0, [r7, #8]
	add r0, sp, #4
	ldrh r0, [r0, #4]
	ldrh r1, [r7, #0xc]
	adds r0, r0, r1
	strh r0, [r7, #0xc]
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08236268
	ldrb r0, [r6, #7]
	ldr r2, _08046548 @ =0x085AB424
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	mov r2, sb
	adds r7, r0, r2
	ldr r3, _0804654C @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r6, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08046550
	adds r0, r6, #0
	adds r0, #0x2c
	mov r1, r8
	strb r1, [r0]
	adds r2, r0, #0
	b _0804655A
	.align 2, 0
_08046548: .4byte 0x085AB424
_0804654C: .4byte 0x0000192C
_08046550:
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_0804655A:
	ldrb r0, [r6, #0x1a]
	cmp r0, #1
	bls _08046568
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #1
	b _0804656E
_08046568:
	adds r1, r6, #0
	adds r1, #0x2d
	movs r0, #0
_0804656E:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r1, [r4]
	cmp r1, #0
	beq _08046596
	ldr r1, [r5, #8]
	movs r2, #4
	orrs r1, r2
	b _0804659E
_08046596:
	ldr r1, [r5, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804659E:
	str r1, [r5, #8]
_080465A0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080465b0
FUN_080465b0: @ 0x080465B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r0
	adds r5, r1, #0
	str r2, [sp, #0x14]
	movs r0, #0x60
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r1, r5, r1
	str r1, [sp, #0x18]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r2, r5, r2
	str r2, [sp, #0x1c]
	adds r3, r5, #0
	adds r3, #0x68
	str r3, [sp, #0x20]
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _080466D8
	movs r4, #0
	strb r4, [r5, #5]
	ldrb r0, [r5, #7]
	ldr r2, _08046630 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r5, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, sl
	adds r7, r0, r2
	ldr r3, _08046634 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r0, #1
	mov ip, r0
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r6
	cmp r0, #1
	bhi _08046638
	adds r0, r5, #0
	adds r0, #0x2c
	mov r1, ip
	strb r1, [r0]
	b _0804663E
	.align 2, 0
_08046630: .4byte 0x085AB414
_08046634: .4byte 0x0000192C
_08046638:
	adds r0, r5, #0
	adds r0, #0x2c
	strb r4, [r0]
_0804663E:
	adds r2, r0, #0
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _0804664E
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _08046654
_0804664E:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_08046654:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	mov r3, ip
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804667C
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08046684
_0804667C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08046684:
	str r0, [r6, #8]
	movs r0, #0
	strb r0, [r5, #8]
	mov r2, sb
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r5, r3
	bl FUN_08013698
	mov r4, r8
	adds r4, #8
	ldr r0, [sp, #0x1c]
	adds r1, r4, #0
	bl FUN_082362fc
	adds r0, r5, #0
	adds r0, #0x28
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r5, #0x30]
	ldrh r3, [r5, #0x32]
	ldr r0, [sp, #0x18]
	bl FUN_08234de8
	movs r6, #0xa6
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	add r0, sp, #4
	movs r2, #0
	bl FUN_08234f80
	ldr r0, [sp, #0x1c]
	adds r1, r4, #0
	add r2, sp, #4
	bl FUN_08235f40
_080466D8:
	ldr r0, [r5, #0x10]
	cmp r0, #0x77
	bls _08046772
	mov r1, sl
	ldr r0, [r1, #0x28]
	movs r1, #0xf
	ands r0, r1
	ldr r2, [sp, #0x14]
	cmp r0, r2
	bne _08046772
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0804671A
	mov r0, sl
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804671A
	movs r0, #5
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	movs r0, #0
	str r0, [r5, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0
	b _08046960
_0804671A:
	ldrb r0, [r5, #0x1f]
	cmp r0, #0
	beq _08046772
	mov r3, sl
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _08046772
	mov r2, sl
	adds r2, #0x20
	adds r3, r5, #0
	adds r3, #0x26
	ldrb r0, [r2]
	ldrb r4, [r3]
	cmp r0, r4
	bne _08046748
	mov r0, sl
	adds r0, #0x21
	adds r1, r5, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08046762
_08046748:
	ldrb r0, [r2]
	subs r0, #1
	ldrb r3, [r3]
	cmp r0, r3
	bne _08046772
	mov r0, sl
	adds r0, #0x21
	adds r1, r5, #0
	adds r1, #0x27
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _08046772
_08046762:
	movs r0, #0
	strb r0, [r5, #0x1e]
	movs r1, #6
	strb r1, [r5, #4]
	movs r1, #1
	strb r1, [r5, #5]
	str r0, [r5, #0x10]
	b _08046960
_08046772:
	mov r6, sl
	ldr r2, [r6, #0x18]
	ldr r3, [r5, #0x3c]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r4, [sp, #0x20]
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _0804678A
	rsbs r1, r1, #0
_0804678A:
	cmp r1, r3
	bge _080467BC
	movs r0, #2
	ldrsh r1, [r2, r0]
	ldr r4, [sp, #0x20]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080467A0
	rsbs r1, r1, #0
_080467A0:
	cmp r1, #0xff
	bgt _080467BC
	movs r0, #4
	ldrsh r1, [r2, r0]
	ldr r2, [sp, #0x20]
	movs r4, #4
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _080467B6
	rsbs r1, r1, #0
_080467B6:
	movs r0, #1
	cmp r1, r3
	blt _080467BE
_080467BC:
	movs r0, #0
_080467BE:
	cmp r0, #0
	beq _080467D6
	ldrb r0, [r5, #4]
	movs r1, #0
	strb r0, [r5, #0xc]
	movs r0, #3
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	str r1, [r5, #0x10]
	movs r0, #0
	b _08046960
_080467D6:
	mov r2, r8
	adds r2, #8
	ldr r6, [sp, #0x1c]
	movs r0, #0x1c
	ldrsh r1, [r6, r0]
	mov r3, r8
	movs r4, #8
	ldrsh r0, [r3, r4]
	subs r4, r1, r0
	movs r0, #0x20
	ldrsh r1, [r6, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08046824 @ =0x000003FF
	adds r7, r2, #0
	cmp r1, r0
	bgt _08046828
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	mov r6, r8
	strh r0, [r6, #8]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	adds r0, r5, #0
	bl FUN_080453b0
	movs r0, #0
	b _08046960
	.align 2, 0
_08046824: .4byte 0x000003FF
_08046828:
	adds r2, r5, #0
	adds r2, #0xa4
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _080468BA
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	movs r6, #0x20
	cmp r0, #0
	beq _08046846
	movs r6, #0x10
_08046846:
	adds r0, r4, #0
	adds r1, r3, #0
	bl FUN_0823785c
	mov r2, r8
	strb r0, [r2, #5]
	add r3, sp, #0xc
	ldrb r4, [r2, #5]
	ldr r2, _08046874 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r2, r3, #0
	cmp r0, #0
	blt _08046878
	asrs r1, r0, #0xc
	b _0804687E
	.align 2, 0
_08046874: .4byte 0x085B0A08
_08046878:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0804687E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08046898 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _0804689C
	asrs r0, r0, #0xc
	b _080468A2
	.align 2, 0
_08046898: .4byte 0x085B0A08
_0804689C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080468A2:
	strh r0, [r3, #4]
	ldrh r0, [r2]
	mov r6, r8
	ldrh r6, [r6, #8]
	adds r0, r0, r6
	mov r1, r8
	strh r0, [r1, #8]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	ldrh r2, [r1, #0xc]
	adds r0, r0, r2
	strh r0, [r1, #0xc]
_080468BA:
	ldr r0, [sp, #0x1c]
	adds r1, r7, #0
	bl FUN_08236268
	ldrb r0, [r5, #7]
	ldr r2, _08046908 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	mov r6, sb
	lsls r0, r0, #5
	mov r3, sl
	adds r7, r0, r3
	ldr r4, _0804690C @ =0x0000192C
	adds r7, r7, r4
	ldrh r3, [r1]
	movs r0, #1
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08046910
	adds r0, r5, #0
	adds r0, #0x2c
	mov r1, r8
	strb r1, [r0]
	adds r2, r0, #0
	b _0804691A
	.align 2, 0
_08046908: .4byte 0x085AB414
_0804690C: .4byte 0x0000192C
_08046910:
	adds r1, r5, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_0804691A:
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _08046928
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _0804692E
_08046928:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_0804692E:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r1, [r4]
	cmp r1, #0
	beq _08046956
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _0804695E
_08046956:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804695E:
	str r1, [r6, #8]
_08046960:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08046970
FUN_08046970: @ 0x08046970
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	adds r5, r1, #0
	str r2, [sp, #0xc]
	adds r7, r5, #0
	adds r7, #0x60
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x68
	adds r1, r1, r5
	mov r8, r1
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _08046A60
	movs r4, #0
	strb r4, [r5, #5]
	ldrb r0, [r5, #7]
	ldr r2, _080469E0 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r5, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	add r0, sb
	mov ip, r0
	ldr r2, _080469E4 @ =0x0000192C
	add ip, r2
	ldrh r3, [r1]
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080469E8
	adds r0, r5, #0
	adds r0, #0x2c
	movs r4, #1
	b _080469EC
	.align 2, 0
_080469E0: .4byte 0x085AB414
_080469E4: .4byte 0x0000192C
_080469E8:
	adds r0, r5, #0
	adds r0, #0x2c
_080469EC:
	strb r4, [r0]
	adds r2, r0, #0
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _080469FE
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _08046A04
_080469FE:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_08046A04:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	movs r3, #1
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	mov r1, ip
	bl FUN_082370cc
	ldrb r0, [r4]
	cmp r0, #0
	beq _08046A2C
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08046A34
_08046A2C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08046A34:
	str r0, [r6, #8]
	movs r0, #0
	strb r0, [r5, #8]
	adds r4, r7, #0
	adds r4, #8
	mov r0, sl
	adds r1, r4, #0
	bl FUN_082362fc
	adds r0, r5, #0
	adds r0, #0x29
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #3
	adds r2, #0x2c
	add r2, sb
	mov r0, sl
	adds r1, r4, #0
	bl FUN_08235f40
	movs r0, #1
	strb r0, [r5, #0xa]
_08046A60:
	mov r6, sb
	ldr r0, [r6, #0x28]
	movs r1, #0xf
	ands r0, r1
	ldr r1, [sp, #0xc]
	cmp r0, r1
	bne _08046A9C
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08046A9C
	mov r0, sb
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #0
	beq _08046A9C
	movs r0, #5
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	movs r0, #0
	str r0, [r5, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r5, #0x1c]
	movs r0, #0
	b _08046C88
_08046A9C:
	mov r3, sb
	ldr r2, [r3, #0x18]
	ldr r3, [r5, #0x3c]
	movs r4, #0
	ldrsh r1, [r2, r4]
	mov r6, r8
	movs r4, #0
	ldrsh r0, [r6, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _08046AB4
	rsbs r1, r1, #0
_08046AB4:
	cmp r1, r3
	bge _08046AE6
	movs r6, #2
	ldrsh r1, [r2, r6]
	mov r4, r8
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08046ACA
	rsbs r1, r1, #0
_08046ACA:
	cmp r1, #0xff
	bgt _08046AE6
	movs r0, #4
	ldrsh r1, [r2, r0]
	mov r2, r8
	movs r4, #4
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _08046AE0
	rsbs r1, r1, #0
_08046AE0:
	movs r6, #1
	cmp r1, r3
	blt _08046AE8
_08046AE6:
	movs r6, #0
_08046AE8:
	cmp r6, #0
	beq _08046B00
	ldrb r0, [r5, #4]
	movs r1, #0
	strb r0, [r5, #0xc]
	movs r0, #3
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	str r1, [r5, #0x10]
	movs r0, #0
	b _08046C88
_08046B00:
	adds r2, r7, #0
	adds r2, #8
	mov r0, sl
	movs r3, #0x1c
	ldrsh r1, [r0, r3]
	movs r4, #8
	ldrsh r0, [r7, r4]
	subs r4, r1, r0
	mov r0, sl
	movs r3, #0x20
	ldrsh r1, [r0, r3]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _08046B50 @ =0x000003FF
	str r2, [sp, #0x10]
	cmp r1, r0
	bgt _08046B54
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r7, #8]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r7, #0xc]
	movs r0, #8
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	str r6, [r5, #0x10]
	movs r0, #0
	b _08046C88
	.align 2, 0
_08046B50: .4byte 0x000003FF
_08046B54:
	adds r2, r5, #0
	adds r2, #0xa4
	ldrb r1, [r2, #0x1d]
	movs r0, #4
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _08046BE0
	ldrh r1, [r2, #0x14]
	movs r0, #1
	ands r0, r1
	movs r6, #0x20
	cmp r0, #0
	beq _08046B72
	movs r6, #0x10
_08046B72:
	adds r0, r4, #0
	adds r1, r3, #0
	bl FUN_0823785c
	strb r0, [r7, #5]
	add r3, sp, #4
	ldrb r4, [r7, #5]
	ldr r2, _08046B9C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08046BA0
	asrs r1, r0, #0xc
	b _08046BA6
	.align 2, 0
_08046B9C: .4byte 0x085B0A08
_08046BA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08046BA6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08046BC0 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _08046BC4
	asrs r0, r0, #0xc
	b _08046BCA
	.align 2, 0
_08046BC0: .4byte 0x085B0A08
_08046BC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08046BCA:
	strh r0, [r3, #4]
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r6, [r7, #8]
	adds r0, r0, r6
	strh r0, [r7, #8]
	add r0, sp, #4
	ldrh r0, [r0, #4]
	ldrh r1, [r7, #0xc]
	adds r0, r0, r1
	strh r0, [r7, #0xc]
_08046BE0:
	mov r0, sl
	ldr r1, [sp, #0x10]
	bl FUN_08236268
	ldrb r0, [r5, #7]
	ldr r2, _08046C30 @ =0x085AB414
	lsls r1, r0, #1
	adds r1, r1, r2
	mov r6, r8
	lsls r0, r0, #5
	mov r2, sb
	adds r7, r0, r2
	ldr r3, _08046C34 @ =0x0000192C
	adds r7, r7, r3
	ldrh r3, [r1]
	movs r4, #1
	mov r8, r4
	adds r0, r5, #0
	adds r0, #0x65
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r5, #0x1a]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08046C38
	adds r0, r5, #0
	adds r0, #0x2c
	mov r1, r8
	strb r1, [r0]
	adds r2, r0, #0
	b _08046C42
	.align 2, 0
_08046C30: .4byte 0x085AB414
_08046C34: .4byte 0x0000192C
_08046C38:
	adds r1, r5, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
_08046C42:
	ldrb r0, [r5, #0x1a]
	cmp r0, #1
	bls _08046C50
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #1
	b _08046C56
_08046C50:
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0
_08046C56:
	strb r0, [r1]
	adds r4, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	strh r0, [r5, #0x2e]
	ldrh r2, [r5, #0x2e]
	movs r3, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r1, [r4]
	cmp r1, #0
	beq _08046C7E
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _08046C86
_08046C7E:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08046C86:
	str r1, [r6, #8]
_08046C88:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08046c98
FUN_08046c98: @ 0x08046C98
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r1, [r4, #5]
	cmp r1, #0
	beq _08046CC0
	movs r0, #0
	strb r0, [r4, #5]
	strb r0, [r4, #8]
	adds r2, r4, #0
	adds r2, #0xa4
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_080136b4
_08046CC0:
	ldrh r1, [r4, #0x1c]
	cmp r1, #0
	bne _08046D6A
	adds r1, r5, #0
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	bne _08046D6E
	ldrb r1, [r5, #0x1e]
	adds r3, r5, #0
	adds r3, #0x20
	adds r6, r4, #0
	adds r6, #0x24
	cmp r1, #0
	beq _08046D1E
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _08046D1E
	ldrb r1, [r3]
	ldrb r2, [r6]
	cmp r1, r2
	bne _08046D04
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x25
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08046D5A
_08046D04:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r2, [r6]
	cmp r1, r2
	bne _08046D1E
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x25
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bls _08046D5A
_08046D1E:
	ldrb r3, [r3]
	ldrb r6, [r6]
	cmp r3, r6
	bne _08046D36
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x25
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08046D5A
_08046D36:
	adds r1, r4, #0
	adds r1, #0x26
	cmp r3, r6
	bls _08046D44
	ldrb r2, [r1]
	cmp r3, r2
	blo _08046D5A
_08046D44:
	ldrb r1, [r1]
	cmp r3, r1
	bne _08046D6E
	adds r1, r5, #0
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08046D6E
_08046D5A:
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0x10]
	movs r0, #0
	b _08046D6E
_08046D6A:
	subs r1, #1
	strh r1, [r4, #0x1c]
_08046D6E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08046d74
FUN_08046d74: @ 0x08046D74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	bl FUN_08018a08
	adds r1, r7, #0
	adds r1, #0x25
	strb r0, [r1]
	bl GetHour
	adds r1, r7, #0
	adds r1, #0x20
	strb r0, [r1]
	bl GetMinute
	adds r1, r7, #0
	adds r1, #0x21
	strb r0, [r1]
	ldrb r1, [r7, #0x1f]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	beq _08046DAE
	movs r0, #1
	b _08046DB0
_08046DAE:
	movs r0, #0
_08046DB0:
	strb r0, [r7, #0x1e]
	adds r0, r7, #0
	adds r0, #0x21
	ldrb r0, [r0]
	strb r0, [r7, #0x1f]
	ldr r0, _08046E64 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08046DCA
	b _08046FA8
_08046DCA:
	movs r0, #0x96
	lsls r0, r0, #1
	adds r6, r7, r0
	movs r1, #0
	str r1, [sp, #0x10]
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sl, r2
	movs r3, #0xa8
	lsls r3, r3, #2
	adds r4, r7, r3
	adds r0, #0x37
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
_08046DF0:
	ldrb r0, [r6, #9]
	cmp r0, #0
	bne _08046DF8
	b _08046F76
_08046DF8:
	mov r2, r8
	str r2, [sp, #0x14]
	adds r3, r6, #0
	adds r3, #0xa4
	str r3, [sp, #0x18]
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
	ldr r1, _08046E68 @ =0x085AB434
	ldrb r0, [r6, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r6, #0
	ldr r2, [sp, #0x10]
	bl _call_via_r3
	ldrb r0, [r6, #4]
	mov r2, r8
	str r2, [sp, #0x20]
	mov r1, sb
	adds r3, r1, #0
	str r3, [sp, #0x1c]
	cmp r0, #8
	bne _08046E2E
	b _08046F70
_08046E2E:
	mov r0, r8
	bl FUN_0823b4b8
	adds r3, r6, #0
	adds r3, #0x68
	mov r2, r8
	ldrh r0, [r2, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, r8
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08046E60
	cmp r1, #0
	blt _08046E60
	ldr r0, _08046E6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08046E60
	ldr r0, _08046E70 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08046E74
_08046E60:
	movs r5, #0
	b _08046E82
	.align 2, 0
_08046E64: .4byte 0x030047A4
_08046E68: .4byte 0x085AB434
_08046E6C: .4byte 0x030046A8
_08046E70: .4byte 0x030046AC
_08046E74:
	ldr r0, _08046E98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08046E82:
	adds r0, r5, #0
	movs r1, #1
	str r3, [sp, #0x24]
	bl FUN_08234224
	ldr r3, [sp, #0x24]
	cmp r0, #0
	beq _08046E9C
	adds r0, #4
	b _08046EA8
	.align 2, 0
_08046E98: .4byte 0x030046A4
_08046E9C:
	ldr r0, _08046EBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08046EA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08046EC0
	cmp r2, #2
	beq _08046EC4
	b _08046EC8
	.align 2, 0
_08046EBC: .4byte 0x030046A4
_08046EC0:
	ldrb r0, [r3, #4]
	b _08046EC6
_08046EC4:
	ldrb r0, [r3]
_08046EC6:
	subs r1, r1, r0
_08046EC8:
	ldr r2, [sp, #0x14]
	strh r1, [r2, #0xa]
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	ldr r3, [sp, #0x18]
	str r0, [r3, #0x20]
	str r1, [r3, #0x24]
	ldrb r1, [r6, #7]
	lsls r1, r1, #5
	ldr r0, _08046F30 @ =0x0000192C
	adds r1, r1, r0
	adds r1, r7, r1
	ldr r0, [sp, #0x18]
	bl FUN_082372cc
	ldr r0, _08046F34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08046F70
	ldr r1, [sp, #0x1c]
	ldrb r5, [r1]
	cmp r5, #0
	beq _08046F4A
	ldrh r5, [r4]
	cmp r5, #0
	bne _08046F38
	ldrh r0, [r4, #6]
	strh r0, [r4, #4]
	ldr r0, [r4, #8]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	mov ip, r3
	mov r1, sl
	str r1, [sp]
	movs r3, #6
	ldrsh r1, [r4, r3]
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x64
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	mov r3, ip
	bl FUN_080da9c4
	str r0, [r4, #8]
	movs r0, #1
	strh r0, [r4]
	b _08046F70
	.align 2, 0
_08046F30: .4byte 0x0000192C
_08046F34: .4byte 0x030047A4
_08046F38:
	ldrh r0, [r4, #4]
	subs r0, #1
	strh r0, [r4, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08046F70
	ldrh r0, [r4, #6]
	strh r0, [r4, #4]
	b _08046F70
_08046F4A:
	ldrh r0, [r4]
	cmp r0, #0
	beq _08046F70
	ldr r0, [r4, #8]
	ldrb r2, [r4, #2]
	mov r1, sl
	str r1, [sp]
	movs r3, #6
	ldrsh r1, [r4, r3]
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x64
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4, #8]
	strh r5, [r4]
_08046F70:
	ldr r0, [r6, #0x10]
	adds r0, #1
	str r0, [r6, #0x10]
_08046F76:
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #1
	add sl, r1
	adds r4, r4, r1
	add sb, r1
	add r8, r1
	adds r6, r6, r1
	cmp r0, #0xf
	bgt _08046F90
	b _08046DF0
_08046F90:
	ldr r0, _08046FBC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08046FA2
	adds r0, r7, #0
	bl FUN_08045408
_08046FA2:
	ldr r0, [r7, #0x28]
	adds r0, #1
	str r0, [r7, #0x28]
_08046FA8:
	movs r0, #0
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08046FBC: .4byte 0x030044E0

	thumb_func_start FUN_08046fc0
FUN_08046fc0: @ 0x08046FC0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #0
_08046FCC:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08046FDC
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080452f4
_08046FDC:
	adds r5, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0xf
	ble _08046FCC
	ldr r1, _08046FF4 @ =0x030000C0
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08046FF4: .4byte 0x030000C0

	thumb_func_start FUN_08046ff8
FUN_08046ff8: @ 0x08046FF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _0804703C @ =0x030000C0
	str r7, [r0]
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047054
	movs r0, #0x23
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x24
	adds r1, r1, r7
	mov sl, r1
	adds r2, r7, #0
	adds r2, #0x20
	str r2, [sp, #0x10]
	adds r3, r7, #0
	adds r3, #0x21
	str r3, [sp, #0x14]
	mov r4, sp
_0804702E:
	bl VM_GetPC
	cmp r0, #0
	beq _08047040
	bl Script_GetValue
	b _08047042
	.align 2, 0
_0804703C: .4byte 0x030000C0
_08047040:
	ldr r0, _08047050 @ =0x0000FFFF
_08047042:
	strh r0, [r4]
	adds r4, #2
	mov r0, sp
	adds r0, #0xe
	cmp r4, r0
	ble _0804702E
	b _08047082
	.align 2, 0
_08047050: .4byte 0x0000FFFF
_08047054:
	movs r4, #0x23
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x24
	adds r5, r5, r7
	mov sl, r5
	adds r0, r7, #0
	adds r0, #0x20
	str r0, [sp, #0x10]
	adds r1, r7, #0
	adds r1, #0x21
	str r1, [sp, #0x14]
	ldr r3, _080470D8 @ =0x0000FFFF
	adds r2, r3, #0
	mov r1, sp
	movs r6, #7
_08047074:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r1, #2
	subs r6, #1
	cmp r6, #0
	bge _08047074
_08047082:
	movs r0, #0
	mov r4, sb
	strb r0, [r4]
	movs r0, #0x68
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047158
	adds r5, r7, #0
	movs r0, #0x2c
	adds r0, r0, r7
	mov r8, r0
	movs r6, #0xf
_0804709C:
	bl VM_GetPC
	cmp r0, #0
	beq _08047144
	bl Script_GetValue
	strh r0, [r5, #0x2c]
	bl Script_GetValue
	strh r0, [r5, #0x30]
	mov r3, r8
	ldrh r1, [r5, #0x2c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080470D4
	cmp r1, #0
	blt _080470D4
	ldr r0, _080470DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080470D4
	ldr r0, _080470E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080470E4
_080470D4:
	movs r4, #0
	b _080470F2
	.align 2, 0
_080470D8: .4byte 0x0000FFFF
_080470DC: .4byte 0x030046A8
_080470E0: .4byte 0x030046AC
_080470E4:
	ldr r0, _08047108 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080470F2:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _0804710C
	adds r0, #4
	b _08047118
	.align 2, 0
_08047108: .4byte 0x030046A4
_0804710C:
	ldr r0, _0804712C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08047118:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08047130
	cmp r2, #2
	beq _08047134
	b _08047138
	.align 2, 0
_0804712C: .4byte 0x030046A4
_08047130:
	ldrb r0, [r3, #4]
	b _08047136
_08047134:
	ldrb r0, [r3]
_08047136:
	subs r1, r1, r0
_08047138:
	strh r1, [r5, #0x2e]
	mov r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0804714A
_08047144:
	strh r0, [r5, #0x2c]
	strh r0, [r5, #0x2e]
	strh r0, [r5, #0x30]
_0804714A:
	adds r5, #8
	movs r2, #8
	add r8, r2
	subs r6, #1
	cmp r6, #0
	bge _0804709C
	b _0804716E
_08047158:
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x2c
	movs r6, #0xf
_08047160:
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r0, #8
	subs r6, #1
	cmp r6, #0
	bge _08047160
_0804716E:
	movs r0, #0
	mov r3, sl
	strb r0, [r3]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804723E
	adds r5, r7, #0
	adds r5, #0xac
	movs r6, #0xf
_08047184:
	bl VM_GetPC
	cmp r0, #0
	beq _08047228
	bl Script_GetValue
	strh r0, [r5]
	bl Script_GetValue
	strh r0, [r5, #4]
	adds r3, r5, #0
	ldrh r1, [r5]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080471BC
	cmp r1, #0
	blt _080471BC
	ldr r0, _080471C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080471BC
	ldr r0, _080471C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080471C8
_080471BC:
	movs r4, #0
	b _080471D6
	.align 2, 0
_080471C0: .4byte 0x030046A8
_080471C4: .4byte 0x030046AC
_080471C8:
	ldr r0, _080471EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080471D6:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _080471F0
	adds r0, #4
	b _080471FC
	.align 2, 0
_080471EC: .4byte 0x030046A4
_080471F0:
	ldr r0, _08047210 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080471FC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08047214
	cmp r2, #2
	beq _08047218
	b _0804721C
	.align 2, 0
_08047210: .4byte 0x030046A4
_08047214:
	ldrb r0, [r3, #4]
	b _0804721A
_08047218:
	ldrb r0, [r3]
_0804721A:
	subs r1, r1, r0
_0804721C:
	strh r1, [r5, #2]
	mov r4, sl
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804722E
_08047228:
	strh r0, [r5]
	strh r0, [r5, #2]
	strh r0, [r5, #4]
_0804722E:
	adds r5, #8
	subs r6, #1
	cmp r6, #0
	bge _08047184
	b _08047254
_08047238:
	movs r0, #1
	rsbs r0, r0, #0
	b _080472BE
_0804723E:
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0xac
	movs r6, #0xf
_08047246:
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	adds r0, #8
	subs r6, #1
	cmp r6, #0
	bge _08047246
_08047254:
	movs r4, #0
	strb r4, [r7, #0x1e]
	bl GetHour
	ldr r5, [sp, #0x10]
	strb r0, [r5]
	bl GetMinute
	ldr r1, [sp, #0x14]
	strb r0, [r1]
	strb r0, [r7, #0x1f]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r7, #0x1c]
	str r4, [r7, #0x28]
	movs r6, #0
	ldr r2, _080472D0 @ =0x0000192C
	adds r2, r2, r7
	mov r8, r2
_0804727E:
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _080472D4 @ =0x0000CB05
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _08047238
	mov r1, r8
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r0, r8
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r5, #0x20
	add r8, r5
	adds r6, #1
	cmp r6, #7
	ble _0804727E
	ldr r0, _080472D8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080472DC @ =0x00001A2C
	adds r1, r7, r2
	str r0, [r1]
	adds r0, #0x2c
	str r0, [r7, #0x18]
	movs r0, #0
_080472BE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080472D0: .4byte 0x0000192C
_080472D4: .4byte 0x0000CB05
_080472D8: .4byte 0x03002BE0
_080472DC: .4byte 0x00001A2C

	thumb_func_start FUN_080472e0
FUN_080472e0: @ 0x080472E0
	push {r4, lr}
	ldr r0, _08047314 @ =0x030000C0
	ldr r0, [r0]
	cmp r0, #0
	bne _08047326
	ldr r1, _08047318 @ =0x00001A30
	movs r0, #5
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08047324
	ldr r1, _0804731C @ =FUN_08046d74
	ldr r2, _08047320 @ =FUN_08046fc0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08046ff8
	cmp r0, #0
	bge _08047324
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08047326
	.align 2, 0
_08047314: .4byte 0x030000C0
_08047318: .4byte 0x00001A30
_0804731C: .4byte FUN_08046d74
_08047320: .4byte FUN_08046fc0
_08047324:
	adds r0, r4, #0
_08047326:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804732c
FUN_0804732c: @ 0x0804732C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r0, _08047354 @ =0x030000C0
	ldr r0, [r0]
	str r0, [sp, #0x20]
	cmp r0, #0
	beq _0804734E
	ldr r0, [sp, #0x20]
	bl FUN_080452cc
	adds r7, r0, #0
	cmp r7, #0
	bne _08047358
_0804734E:
	movs r0, #1
	rsbs r0, r0, #0
	b _080476F6
	.align 2, 0
_08047354: .4byte 0x030000C0
_08047358:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r7]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r7, #2]
	movs r0, #0x6d
	movs r1, #2
	bl VM_GetKeywordValue
	strb r0, [r7, #4]
	movs r0, #1
	strb r0, [r7, #5]
	str r4, [r7, #0x10]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r7, #7]
	movs r0, #0x68
	movs r1, #4
	bl VM_GetKeywordValue
	adds r2, r0, #0
	ldr r0, [sp, #0x20]
	adds r1, r7, #0
	bl FUN_08045530
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0xb4
	strh r1, [r0]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080473F8
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080473F0 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080473F4 @ =0x0000FFFF
	ldr r1, [sp, #0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	adds r6, r0, #0
	b _08047420
	.align 2, 0
_080473F0: .4byte 0xFFFF0000
_080473F4: .4byte 0x0000FFFF
_080473F8:
	ldr r0, _0804745C @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _08047460 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _08047464 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x10]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r6, #0
_08047420:
	movs r0, #0x74
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08047468
	movs r0, #1
	strb r0, [r7, #0x1f]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x24
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x25
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x26
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x27
	strb r0, [r1]
	b _08047484
	.align 2, 0
_0804745C: .4byte 0x030046A0
_08047460: .4byte 0xFFFF0000
_08047464: .4byte 0x0000FFFF
_08047468:
	strb r2, [r7, #0x1f]
	adds r0, r7, #0
	adds r0, #0x24
	movs r1, #9
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0x26
	movs r0, #0x15
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x27
	strb r2, [r0]
_08047484:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804749A
	bl Script_GetValue
	str r0, [r7, #0x3c]
	bl Script_GetValue
	b _080474A4
_0804749A:
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r7, #0x3c]
	movs r0, #0x80
	lsls r0, r0, #2
_080474A4:
	str r0, [r7, #0x40]
	movs r0, #0x72
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _080474D8
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0x28
	strb r0, [r4]
	bl Script_GetValue
	strh r0, [r7, #0x30]
	bl Script_GetValue
	strh r0, [r7, #0x32]
	bl Script_GetValue
	strh r0, [r7, #0x34]
	bl Script_GetValue
	str r0, [r7, #0x38]
	mov sb, r4
	b _080474EE
_080474D8:
	adds r1, r7, #0
	adds r1, #0x28
	movs r0, #0xff
	strb r0, [r1]
	strh r2, [r7, #0x30]
	strh r2, [r7, #0x32]
	movs r0, #8
	strh r0, [r7, #0x34]
	movs r0, #0xc
	str r0, [r7, #0x38]
	mov sb, r1
_080474EE:
	movs r0, #0x45
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047516
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x29
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x2a
	strb r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x2b
	b _08047528
_08047516:
	adds r1, r7, #0
	adds r1, #0x29
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r1, #1
_08047528:
	strb r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047572
	movs r5, #0
	movs r0, #0x60
	adds r0, r0, r7
	mov sl, r0
	lsls r4, r6, #0x18
	add r6, sp, #0x18
	movs r1, #0x68
	adds r1, r1, r7
	mov r8, r1
	adds r2, r7, #0
	adds r2, #0x6a
	str r2, [sp, #0x24]
	adds r0, r7, #0
	adds r0, #0xa4
	str r0, [sp, #0x28]
	b _08047564
_08047554:
	bl Script_GetValue
	lsls r2, r5, #2
	adds r1, r7, #0
	adds r1, #0x48
	adds r1, r1, r2
	str r0, [r1]
	adds r5, #1
_08047564:
	cmp r5, #3
	bgt _080475A4
	bl VM_GetPC
	cmp r0, #0
	bne _08047554
	b _08047590
_08047572:
	movs r5, #0
	movs r1, #0x60
	adds r1, r1, r7
	mov sl, r1
	lsls r4, r6, #0x18
	add r6, sp, #0x18
	movs r2, #0x68
	adds r2, r2, r7
	mov r8, r2
	adds r0, r7, #0
	adds r0, #0x6a
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0xa4
	str r1, [sp, #0x28]
_08047590:
	cmp r5, #3
	bgt _080475A4
	movs r1, #0
	lsls r0, r5, #2
	adds r0, #0x48
	adds r0, r0, r7
_0804759C:
	stm r0!, {r1}
	adds r5, #1
	cmp r5, #3
	ble _0804759C
_080475A4:
	ldrh r1, [r7]
	lsrs r3, r4, #0x18
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	mov r0, sl
	add r2, sp, #0x10
	bl FUN_0823b400
	ldr r1, _08047638 @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0x12
	str r0, [sp, #0x18]
	ldr r0, [r6, #4]
	ands r0, r1
	str r0, [r6, #4]
	mov r0, sl
	adds r1, r6, #0
	bl FUN_0823b47c
	mov r2, sb
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08047608
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrb r2, [r2]
	ldrh r3, [r7, #0x30]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrh r0, [r7, #0x32]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	mov r0, sl
	bl FUN_0823b490
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	mov r0, r8
	movs r2, #0
	bl FUN_08234f80
	adds r0, r7, #0
	bl FUN_080453b0
_08047608:
	movs r0, #0
	strb r0, [r7, #0xc]
	mov r5, r8
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08047632
	cmp r1, #0
	blt _08047632
	ldr r0, _0804763C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08047632
	ldr r0, _08047640 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08047644
_08047632:
	movs r4, #0
	b _08047652
	.align 2, 0
_08047638: .4byte 0xFFFF0000
_0804763C: .4byte 0x030046A8
_08047640: .4byte 0x030046AC
_08047644:
	ldr r0, _08047664 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08047652:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08047668
	adds r0, #4
	b _08047674
	.align 2, 0
_08047664: .4byte 0x030046A4
_08047668:
	ldr r0, _08047688 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08047674:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0804768C
	cmp r2, #2
	beq _08047690
	b _08047694
	.align 2, 0
_08047688: .4byte 0x030046A4
_0804768C:
	ldrb r0, [r5, #4]
	b _08047692
_08047690:
	ldrb r0, [r5]
_08047692:
	subs r1, r1, r0
_08047694:
	movs r6, #0
	movs r5, #0
	ldr r2, [sp, #0x24]
	strh r1, [r2]
	strb r6, [r7, #0x1b]
	ldr r0, [sp, #0x20]
	ldr r1, _08047708 @ =0x0000192C
	adds r4, r0, r1
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, r8
	str r2, [sp, #0xc]
	ldr r0, [sp, #0x28]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r1, _0804770C @ =0x085AB404
	ldrb r0, [r7, #7]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	str r5, [sp]
	ldr r0, [sp, #0x28]
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
	mov r0, sl
	bl FUN_08002a48
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r7, r0
	adds r0, r4, #0
	mov r1, r8
	movs r2, #1
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_08013698
	strb r6, [r7, #8]
	movs r1, #1
	strb r1, [r7, #9]
_080476F6:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047708: .4byte 0x0000192C
_0804770C: .4byte 0x085AB404
_08047710:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0xC4, 0x00, 0x00, 0x03

	thumb_func_start FUN_0804771c
FUN_0804771c: @ 0x0804771C
	push {lr}
	ldr r0, _0804772C @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _08047728
	movs r0, #1
_08047728:
	pop {r1}
	bx r1
	.align 2, 0
_0804772C: .4byte 0x030000C4

	thumb_func_start FUN_08047730
FUN_08047730: @ 0x08047730
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08047758 @ =0x000092B3
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	cmp r1, #0
	beq _0804775C
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	adds r2, #0x58
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0
	b _08047760
	.align 2, 0
_08047758: .4byte 0x000092B3
_0804775C:
	movs r0, #1
	rsbs r0, r0, #0
_08047760:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047768
FUN_08047768: @ 0x08047768
	push {lr}
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, #0xc
	adds r0, r0, r1
	ldr r1, _08047784 @ =0x03004430
	ldr r2, _08047788 @ =0x04000008
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_08047784: .4byte 0x03004430
_08047788: .4byte 0x04000008

	thumb_func_start FUN_0804778c
FUN_0804778c: @ 0x0804778C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	movs r2, #0x15
	ldrsb r2, [r5, r2]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r2, r1
	bne _080477B0
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1, #8]
	movs r3, #1
	orrs r2, r3
	str r2, [r1, #8]
	b _080477D4
_080477B0:
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0x15
	ldrsb r2, [r5, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl Sprite_SetSprite
_080477D4:
	ldrb r2, [r5, #0x15]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	strb r2, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080477e4
FUN_080477e4: @ 0x080477E4
	push {lr}
	adds r1, r0, #0
	ldr r0, _080477F4 @ =0x030000C4
	ldr r2, [r0]
	cmp r2, #0
	bne _080477F8
	movs r0, #0
	b _0804784C
	.align 2, 0
_080477F4: .4byte 0x030000C4
_080477F8:
	movs r3, #0xbf
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	bne _08047824
	ldr r0, _0804781C @ =FUN_08048294
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r1, r2, r3
	str r0, [r1]
	ldr r0, _08047820 @ =0x00000183
	adds r1, r2, r0
	movs r0, #3
	strb r0, [r1]
	b _08047838
	.align 2, 0
_0804781C: .4byte FUN_08048294
_08047820: .4byte 0x00000183
_08047824:
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #0
	str r0, [r1]
	ldr r1, _08047850 @ =FUN_080483c8
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r0, r2, r3
	str r1, [r0]
_08047838:
	adds r1, r2, #0
	adds r1, #0x27
	movs r0, #0
	strb r0, [r1]
	subs r1, #0xf
	movs r0, #0xff
	strb r0, [r1, #0x15]
	adds r0, r2, #0
	bl FUN_0804778c
_0804784C:
	pop {r1}
	bx r1
	.align 2, 0
_08047850: .4byte FUN_080483c8

	thumb_func_start FUN_08047854
FUN_08047854: @ 0x08047854
	push {lr}
	bl Script_GetValue
	bl FUN_080477e4
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047864
FUN_08047864: @ 0x08047864
	push {r4, r5, lr}
	ldr r0, _08047874 @ =0x030000C4
	ldr r4, [r0]
	cmp r4, #0
	bne _08047878
	movs r0, #0
	b _080478CC
	.align 2, 0
_08047874: .4byte 0x030000C4
_08047878:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _080478D4 @ =0x00000179
	adds r1, r4, r2
	ldrb r1, [r1]
	movs r3, #0xbd
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrb r2, [r2]
	ldr r5, _080478D8 @ =0x0000017B
	adds r3, r4, r5
	ldrb r3, [r3]
	bl FUN_0822ea60
	ldr r2, _080478DC @ =FUN_080483bc
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r1, r4, r3
	str r2, [r1]
	adds r5, #0x99
	adds r2, r4, r5
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	adds r2, r4, #0
	adds r2, #0x18
	movs r1, #0xff
	strb r1, [r2, #0x15]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r1, [r2, #8]
	orrs r1, r3
	str r1, [r2, #8]
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r2, r4, r3
	ldr r1, _080478E0 @ =0x0000FFFF
	strh r1, [r2]
_080478CC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080478D4: .4byte 0x00000179
_080478D8: .4byte 0x0000017B
_080478DC: .4byte FUN_080483bc
_080478E0: .4byte 0x0000FFFF

	thumb_func_start FUN_080478e4
FUN_080478e4: @ 0x080478E4
	push {lr}
	bl FUN_08047864
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080478f0
FUN_080478f0: @ 0x080478F0
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	ldr r0, _08047954 @ =0x030000C4
	ldr r7, [r0]
	cmp r7, #0
	beq _0804794A
	cmp r1, #0
	beq _0804794A
	adds r6, r7, #0
	adds r6, #0x18
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r4, #0
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08047fd8
	str r0, [r6, #0x1c]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r1, #0xd3
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r5, #1
	strh r5, [r0]
	subs r2, #0x12
	adds r0, r7, r2
	strh r4, [r0]
	adds r0, r6, #0
	bl FUN_08049640
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_0804794A:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047954: .4byte 0x030000C4

	thumb_func_start FUN_08047958
FUN_08047958: @ 0x08047958
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, _08047A04 @ =0x030000C4
	ldr r5, [r0]
	cmp r5, #0
	beq _080479F4
	adds r4, r5, #0
	adds r4, #0x18
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	str r6, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08047fd8
	str r0, [r4, #0x1c]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r1, r8
	strh r1, [r0]
	movs r0, #0xd3
	lsls r0, r0, #1
	adds r2, r5, r0
	strh r7, [r2]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	adds r6, r4, #0
	cmp r0, #0x20
	bls _080479A6
	movs r0, #0x20
	strh r0, [r2]
_080479A6:
	movs r4, #0
	ldrh r1, [r2]
	cmp r4, r1
	bge _080479C6
	mov r3, sb
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r1, r5, r0
_080479B6:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	adds r4, #1
	ldrh r0, [r2]
	cmp r4, r0
	blt _080479B6
_080479C6:
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r1, r1, #1
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r2, #0x16
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_08049640
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080479F4:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047A04: .4byte 0x030000C4

	thumb_func_start Textbox_Open
Textbox_Open: @ 0x08047A08
	push {lr}
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _08047A1A
	bl VM_GetPC
	b _08047A1E
_08047A1A:
	bl FUN_0823d340
_08047A1E:
	bl FUN_080478f0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047a28
FUN_08047a28: @ 0x08047A28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	ldr r0, _08047ABC @ =0x030000C4
	ldr r5, [r0]
	cmp r5, #0
	beq _08047AFE
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0x18
	adds r2, r2, r5
	mov sb, r2
	cmp r0, #0
	beq _08047AFE
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrb r0, [r4]
	ldr r1, _08047AC0 @ =0x00000179
	adds r1, r1, r5
	mov r8, r1
	ldrb r1, [r1]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r7, r5, r2
	ldrb r2, [r7]
	adds r3, #3
	adds r6, r5, r3
	ldrb r3, [r6]
	bl FUN_0822ea60
	ldrb r1, [r4]
	mov r0, r8
	ldrb r2, [r0]
	ldrb r3, [r7]
	ldrb r0, [r6]
	str r0, [sp]
	mov r0, sb
	bl FUN_08049650
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r5, r1
	mov r2, sl
	strh r2, [r0]
	ldrh r1, [r0]
	adds r0, r5, #0
	bl FUN_08047fd8
	mov r3, sb
	str r0, [r3, #0x1c]
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08047ACC
	ldr r0, _08047AC4 @ =FUN_08048294
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	ldr r3, _08047AC8 @ =0x00000183
	adds r1, r5, r3
	movs r0, #3
	strb r0, [r1]
	b _08047AE0
	.align 2, 0
_08047ABC: .4byte 0x030000C4
_08047AC0: .4byte 0x00000179
_08047AC4: .4byte FUN_08048294
_08047AC8: .4byte 0x00000183
_08047ACC:
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	ldr r1, _08047B10 @ =FUN_080483c8
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
_08047AE0:
	mov r0, sb
	bl FUN_08049640
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, _08047B14 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_08047AFE:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047B10: .4byte FUN_080483c8
_08047B14: .4byte 0x0000FFFF

	thumb_func_start FUN_08047b18
FUN_08047b18: @ 0x08047B18
	push {r4, lr}
	ldr r0, _08047B44 @ =0x030000C4
	ldr r4, [r0]
	cmp r4, #0
	beq _08047B3A
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08047B3A
	bl Script_GetValue
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
_08047B3A:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08047B44: .4byte 0x030000C4

	thumb_func_start FUN_08047b48
FUN_08047b48: @ 0x08047B48
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08047B88 @ =0x030000C4
	ldr r3, [r0]
	cmp r3, #0
	beq _08047B7E
	adds r1, r3, #0
	adds r1, #0x18
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r2, #0
	str r2, [r0]
	movs r5, #0xc9
	lsls r5, r5, #1
	movs r0, #0
	strh r2, [r5, r3]
	str r4, [r1, #0x1c]
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_08047B7E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08047B88: .4byte 0x030000C4

	thumb_func_start FUN_08047b8c
FUN_08047b8c: @ 0x08047B8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov sl, r1
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, _08047BAC @ =0x030000C4
	ldr r5, [r0]
	cmp r5, #0
	bne _08047BB0
	movs r0, #0
	b _08047BFC
	.align 2, 0
_08047BAC: .4byte 0x030000C4
_08047BB0:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	ldr r1, _08047C0C @ =0x00000179
	adds r1, r1, r5
	mov r8, r1
	ldrb r1, [r1]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r7, r5, r2
	ldrb r2, [r7]
	ldr r3, _08047C10 @ =0x0000017B
	adds r6, r5, r3
	ldrb r3, [r6]
	bl FUN_0822ea60
	mov r0, sb
	strb r0, [r4]
	mov r2, sl
	mov r1, r8
	strb r2, [r1]
	mov r3, sp
	ldrb r3, [r3, #4]
	strb r3, [r7]
	mov r0, sp
	ldrb r0, [r0, #8]
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0x18
	ldrb r1, [r4]
	mov r3, r8
	ldrb r2, [r3]
	ldrb r3, [r7]
	ldrb r4, [r6]
	str r4, [sp]
	bl FUN_08049650
_08047BFC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047C0C: .4byte 0x00000179
_08047C10: .4byte 0x0000017B

	thumb_func_start FUN_08047c14
FUN_08047c14: @ 0x08047C14
	push {r4, r5, r6, lr}
	bl Script_GetValue
	adds r6, r0, #0
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r3, r0, #0
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08047b8c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047c40
FUN_08047c40: @ 0x08047C40
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08047C5C @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _08047C60
	adds r0, #0x18
	adds r1, r3, #0
	bl FUN_080496c0
	movs r0, #0
	b _08047C64
	.align 2, 0
_08047C5C: .4byte 0x030000C4
_08047C60:
	movs r0, #1
	rsbs r0, r0, #0
_08047C64:
	pop {r1}
	bx r1

	thumb_func_start TextBox_SetVar
TextBox_SetVar: @ 0x08047C68
	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08047c40
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047c84
FUN_08047c84: @ 0x08047C84
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08047C98 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	bne _08047C9C
	movs r0, #0
	b _08047CA4
	.align 2, 0
_08047C98: .4byte 0x030000C4
_08047C9C:
	adds r0, #0x18
	adds r1, r3, #0
	bl FUN_080496cc
_08047CA4:
	pop {r1}
	bx r1

	thumb_func_start FUN_08047ca8
FUN_08047ca8: @ 0x08047CA8
	push {r4, r5, r6, lr}
	bl Script_GetValue
	adds r6, r0, #0
	bl FUN_0823d340
	adds r5, r0, #0
	cmp r5, #0
	beq _08047CDC
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	adds r0, r5, #0
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08047c84
	movs r0, #0
	b _08047CE0
_08047CDC:
	movs r0, #1
	rsbs r0, r0, #0
_08047CE0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start TextBox_SetExtend
TextBox_SetExtend: @ 0x08047CE8
	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl FUN_0823d34c
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08047c84
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047d04
FUN_08047d04: @ 0x08047D04
	push {r4, lr}
	ldr r0, _08047D24 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _08047D46
	adds r4, r0, #0
	adds r4, #0x18
	movs r0, #0
	strb r0, [r4, #0xd]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047D4A
	b _08047D3E
	.align 2, 0
_08047D24: .4byte 0x030000C4
_08047D28:
	bl Script_GetValue
	ldrb r2, [r4, #0xd]
	lsls r2, r2, #2
	adds r1, r4, #0
	adds r1, #0xc4
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_08047D3E:
	bl VM_GetPC
	cmp r0, #0
	bne _08047D28
_08047D46:
	movs r0, #0
	b _08047D4E
_08047D4A:
	movs r0, #1
	rsbs r0, r0, #0
_08047D4E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08047d54
FUN_08047d54: @ 0x08047D54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r1, _08047D68 @ =0x030000C4
	ldr r3, [r1]
	cmp r3, #0
	bne _08047D6C
	movs r0, #0
	b _08047D8C
	.align 2, 0
_08047D68: .4byte 0x030000C4
_08047D6C:
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r3, r1
	movs r1, #0
	strb r4, [r2]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r2, r3, r4
	strh r5, [r2]
	adds r4, #2
	adds r2, r3, r4
	strh r1, [r2]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r3, r2
	str r6, [r1]
_08047D8C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start TextBox_EnableAutoAdvance
TextBox_EnableAutoAdvance: @ 0x08047D94
	push {r4, r5, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r5, r0, #0
	rsbs r1, r4, #0
	orrs r1, r4
	lsrs r1, r1, #0x1f
	movs r0, #0x6d
	bl VM_GetKeywordValue
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08047d54
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047dc0
FUN_08047dc0: @ 0x08047DC0
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _08047DE0 @ =0x030000C4
	ldr r4, [r0]
	cmp r4, #0
	beq _08047DE4
	adds r0, r4, #0
	bl FUN_08047730
	cmp r0, #0
	blt _08047DE4
	adds r0, r4, #0
	bl FUN_08047768
	movs r0, #0
	b _08047DE8
	.align 2, 0
_08047DE0: .4byte 0x030000C4
_08047DE4:
	movs r0, #1
	rsbs r0, r0, #0
_08047DE8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047df0
FUN_08047df0: @ 0x08047DF0
	push {lr}
	bl Script_GetValue
	bl FUN_08047dc0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047e00
FUN_08047e00: @ 0x08047E00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08047E84 @ =0x030000C4
	ldr r7, [r0]
	cmp r7, #0
	beq _08047E7C
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047E36
	bl FUN_0823d340
	adds r1, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
	cmp r1, #0
	beq _08047E7C
	adds r0, r1, #0
	bl FUN_080478f0
_08047E36:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047E62
	bl Script_GetValue
	adds r6, r0, #0
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r3, r0, #0
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08047b8c
_08047E62:
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r0, #0x63
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r7, #0
	bl FUN_08047730
	cmp r0, #0
	bge _08047E88
_08047E7C:
	movs r0, #1
	rsbs r0, r0, #0
	b _08047F72
	.align 2, 0
_08047E84: .4byte 0x030000C4
_08047E88:
	adds r0, r7, #0
	bl FUN_08047768
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r7, r0
	ldrh r1, [r4]
	movs r0, #0x69
	bl VM_GetKeywordValue
	strh r0, [r4]
	mov r2, r8
	ldrb r1, [r2, #0x11]
	movs r0, #0x6d
	bl VM_GetKeywordValue
	mov r3, r8
	strb r0, [r3, #0x11]
	ldr r0, _08047EF0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x12
	ldrsh r1, [r0, r2]
	movs r0, #0x77
	bl VM_GetKeywordValue
	mov r3, r8
	strb r0, [r3, #9]
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08047EF4
	bl Script_GetValue
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl Script_GetValue
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	str r0, [r1]
	b _08047F0C
	.align 2, 0
_08047EF0: .4byte 0x030046A0
_08047EF4:
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r2, [r0]
	adds r3, #0x12
	adds r0, r7, r3
	str r2, [r0]
_08047F0C:
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047F48
	movs r0, #0
	mov r1, r8
	strb r0, [r1, #0xd]
	b _08047F40
_08047F28:
	bl Script_GetValue
	mov r3, r8
	ldrb r2, [r3, #0xd]
	lsls r2, r2, #2
	mov r1, r8
	adds r1, #0xc4
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_08047F40:
	bl VM_GetPC
	cmp r0, #0
	bne _08047F28
_08047F48:
	movs r0, #0x61
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08047F6C
	bl Script_GetValue
	adds r1, r0, #0
	cmp r1, #0
	beq _08047F72
	ldr r1, _08047F68 @ =0x0000017F
	adds r2, r7, r1
	movs r1, #0
	strb r1, [r2]
	b _08047F72
	.align 2, 0
_08047F68: .4byte 0x0000017F
_08047F6C:
	ldr r3, _08047F7C @ =0x0000017F
	adds r1, r7, r3
	strb r2, [r1]
_08047F72:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047F7C: .4byte 0x0000017F

	thumb_func_start FUN_08047f80
FUN_08047f80: @ 0x08047F80
	push {lr}
	adds r2, r0, #0
	ldr r0, _08047FA0 @ =0x030000C4
	ldr r1, [r0]
	cmp r1, #0
	beq _08047FA4
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r1, r3
	str r2, [r0]
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #0
	str r0, [r1]
	b _08047FA8
	.align 2, 0
_08047FA0: .4byte 0x030000C4
_08047FA4:
	movs r0, #1
	rsbs r0, r0, #0
_08047FA8:
	pop {r1}
	bx r1

	thumb_func_start FUN_08047fac
FUN_08047fac: @ 0x08047FAC
	push {lr}
	bl Script_GetValue
	bl FUN_08047f80
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08047fbc
FUN_08047fbc: @ 0x08047FBC
	push {lr}
	ldr r0, _08047FCC @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _08047FD0
	movs r0, #0
	b _08047FD4
	.align 2, 0
_08047FCC: .4byte 0x030000C4
_08047FD0:
	movs r0, #1
	rsbs r0, r0, #0
_08047FD4:
	pop {r1}
	bx r1

	thumb_func_start FUN_08047fd8
FUN_08047fd8: @ 0x08047FD8
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08047ff4
FUN_08047ff4: @ 0x08047FF4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x18
	adds r0, r0, r5
	mov sb, r0
	movs r4, #0
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08048034
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	subs r3, #2
	adds r1, r5, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080480A2
	strh r4, [r2]
	movs r4, #2
	b _080480A2
_08048034:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, [r3]
	ldr r0, [r2]
	cmp r1, r0
	blo _08048088
	str r4, [r2]
	str r4, [r3]
	ldr r2, _08048080 @ =0x030044E0
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08048062
	ldr r3, _08048084 @ =0x0000017F
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r4, #1
_08048062:
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804806E
	movs r4, #1
_0804806E:
	movs r1, #0x85
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _080480A2
	.align 2, 0
_08048080: .4byte 0x030044E0
_08048084: .4byte 0x0000017F
_08048088:
	ldr r2, _080480E4 @ =0x0000017F
	adds r0, r5, r2
	strb r4, [r0]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
_080480A2:
	ldr r1, _080480E4 @ =0x0000017F
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080480B0
	cmp r4, #0
	beq _08048188
_080480B0:
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08048188
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	movs r3, #0
	strh r1, [r0]
	ldrb r0, [r2]
	cmp r0, #0
	beq _080480EC
	ldr r1, _080480E8 @ =FUN_080481a8
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	mov r0, sb
	strb r3, [r0, #9]
	strb r3, [r0, #8]
	b _0804810A
	.align 2, 0
_080480E4: .4byte 0x0000017F
_080480E8: .4byte FUN_080481a8
_080480EC:
	ldr r1, _08048170 @ =FUN_08048294
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	ldr r3, _08048174 @ =0x00000183
	adds r1, r5, r3
	movs r0, #3
	strb r0, [r1]
	ldr r0, _08048178 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	mov r2, sb
	strb r0, [r2, #9]
_0804810A:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r0, r5, #0
	bl FUN_08047fd8
	mov r1, sb
	str r0, [r1, #0x1c]
	cmp r4, #2
	beq _08048126
	ldr r0, _0804817C @ =0x00000107
	bl PlaySound_082406e0
_08048126:
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r4, r5, r2
	ldrb r0, [r4]
	ldr r3, _08048180 @ =0x00000179
	adds r3, r3, r5
	mov r8, r3
	ldrb r1, [r3]
	adds r2, #2
	adds r7, r5, r2
	ldrb r2, [r7]
	ldr r3, _08048184 @ =0x0000017B
	adds r6, r5, r3
	ldrb r3, [r6]
	bl FUN_0822ea60
	ldrb r1, [r4]
	mov r0, r8
	ldrb r2, [r0]
	ldrb r3, [r7]
	ldrb r0, [r6]
	str r0, [sp]
	mov r0, sb
	bl FUN_08049650
	adds r0, r5, #0
	adds r0, #0x18
	bl FUN_08049640
	movs r1, #0x85
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _08048198
	.align 2, 0
_08048170: .4byte FUN_08048294
_08048174: .4byte 0x00000183
_08048178: .4byte 0x030046A0
_0804817C: .4byte 0x00000107
_08048180: .4byte 0x00000179
_08048184: .4byte 0x0000017B
_08048188:
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r1, r5, r3
	bl FUN_082372cc
_08048198:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080481a8
FUN_080481a8: @ 0x080481A8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x18
	ldr r1, _080481C0 @ =0x0000017F
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080481C4
	movs r0, #1
	b _080481CC
	.align 2, 0
_080481C0: .4byte 0x0000017F
_080481C4:
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
_080481CC:
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x1c]
	cmp r1, #0
	beq _0804823E
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0804821C
	ldrb r1, [r1]
	cmp r1, #0
	bne _0804821C
	movs r4, #0xc6
	lsls r4, r4, #1
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _08048218 @ =FUN_08047ff4
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r4, #0xa
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804827E
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _0804827E
	subs r2, #0xd8
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0804827E
	.align 2, 0
_08048218: .4byte FUN_08047ff4
_0804821C:
	movs r0, #0
	strb r0, [r4, #8]
	movs r0, #1
	strb r0, [r4, #0x16]
	adds r0, r4, #0
	bl FUN_08049568
	cmp r0, #0
	beq _0804823E
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0804823E
	ldr r1, _08048284 @ =FUN_080483bc
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
_0804823E:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08048284 @ =FUN_080483bc
	cmp r1, r0
	beq _0804827E
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804827E
	ldr r4, _08048288 @ =0x0000017F
	adds r3, r5, r4
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804827E
	ldr r0, _0804828C @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0804827E
	ldr r1, _08048290 @ =FUN_08048294
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
	strb r2, [r3]
_0804827E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08048284: .4byte FUN_080483bc
_08048288: .4byte 0x0000017F
_0804828C: .4byte 0x030044E0
_08048290: .4byte FUN_08048294

	thumb_func_start FUN_08048294
FUN_08048294: @ 0x08048294
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x18
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	strb r0, [r4, #0xa]
	ldr r1, [r4, #0x1c]
	cmp r1, #0
	beq _0804833A
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _080482F8
	ldrb r1, [r1]
	cmp r1, #0
	bne _080482F8
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _080482F4 @ =FUN_08047ff4
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080483AA
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _080483AA
	adds r1, #0x92
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _080483AA
	.align 2, 0
_080482F4: .4byte FUN_08047ff4
_080482F8:
	ldrb r0, [r4, #8]
	adds r1, r0, #1
	strb r1, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r4, #9]
	cmp r0, r2
	blo _0804833A
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #0x16]
	adds r0, r4, #0
	bl FUN_08049568
	cmp r0, #0
	beq _0804833A
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08048330
	ldr r1, _0804832C @ =FUN_080483bc
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	b _0804833A
	.align 2, 0
_0804832C: .4byte FUN_080483bc
_08048330:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0804833A
	ldrb r0, [r4, #9]
	strb r0, [r4, #8]
_0804833A:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08048378 @ =FUN_080483bc
	cmp r1, r0
	beq _080483AA
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080483AA
	ldr r0, _0804837C @ =0x00000183
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08048388
	ldr r2, _08048380 @ =0x030044E0
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804838E
	ldr r1, _08048384 @ =FUN_080481a8
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	b _080483AA
	.align 2, 0
_08048378: .4byte FUN_080483bc
_0804837C: .4byte 0x00000183
_08048380: .4byte 0x030044E0
_08048384: .4byte FUN_080481a8
_08048388:
	subs r0, #1
	strb r0, [r1]
	ldr r2, _080483B0 @ =0x030044E0
_0804838E:
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080483AA
	ldr r0, _080483B4 @ =FUN_080481a8
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	ldr r0, _080483B8 @ =0x0000017F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080483AA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080483B0: .4byte 0x030044E0
_080483B4: .4byte FUN_080481a8
_080483B8: .4byte 0x0000017F

	thumb_func_start FUN_080483bc
FUN_080483bc: @ 0x080483BC
	adds r0, #0x18
	movs r1, #0
	strb r1, [r0, #0xf]
	bx lr

	thumb_func_start FUN_080483c4
FUN_080483c4: @ 0x080483C4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080483c8
FUN_080483c8: @ 0x080483C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0x18
	movs r0, #1
	strb r0, [r4, #0xa]
	movs r6, #0
	ldr r0, _08048410 @ =FUN_080483bc
	mov r8, r0
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r5, r1, r0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r7, r1, r0
_080483EA:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _08048420
	movs r0, #0
	strb r0, [r4, #8]
	adds r0, r4, #0
	bl FUN_08049568
	cmp r0, #0
	beq _08048420
	movs r0, #1
	str r0, [r7]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08048414
	mov r0, r8
	str r0, [r5]
	b _08048426
	.align 2, 0
_08048410: .4byte FUN_080483bc
_08048414:
	ldr r0, _0804841C @ =FUN_080483c4
	str r0, [r5]
	b _08048426
	.align 2, 0
_0804841C: .4byte FUN_080483c4
_08048420:
	adds r6, #1
	cmp r6, #3
	ble _080483EA
_08048426:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08048430
FUN_08048430: @ 0x08048430
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	ldr r1, [r5, #0x18]
	cmp r1, #0
	beq _0804844A
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0
	str r0, [r5, #0x18]
_0804844A:
	adds r0, r5, #0
	bl FUN_08049884
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08048462
	bl FUN_08047a28
_08048462:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08048474
	adds r0, r4, #0
	bl _call_via_r1
_08048474:
	ldr r2, _0804849C @ =0x00000179
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r2, #2
	adds r1, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	cmp r0, #9
	bgt _080484A4
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #0xdf
	strh r0, [r1]
	ldr r0, _080484A0 @ =0x0000022E
	adds r1, r4, r0
	movs r0, #0x29
	b _080484B6
	.align 2, 0
_0804849C: .4byte 0x00000179
_080484A0: .4byte 0x0000022E
_080484A4:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0xdf
	strh r0, [r1]
	ldr r0, _080484F0 @ =0x0000022E
	adds r1, r4, r0
	movs r0, #0x8f
_080484B6:
	strh r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, [r0]
	ldr r0, _080484F4 @ =FUN_080483bc
	cmp r1, r0
	beq _080484F8
	adds r0, r4, #0
	bl FUN_08047768
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x15
	ldrsb r0, [r5, r0]
	cmp r1, r0
	beq _0804851C
	adds r0, r4, #0
	bl FUN_0804778c
	b _0804851C
	.align 2, 0
_080484F0: .4byte 0x0000022E
_080484F4: .4byte FUN_080483bc
_080484F8:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r4, r2
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804851C
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r0, #0xff
	strb r0, [r3]
_0804851C:
	adds r0, r5, #0
	bl FUN_08049890
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804852c
FUN_0804852c: @ 0x0804852C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _08048550 @ =0x030000C4
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08048550: .4byte 0x030000C4

	thumb_func_start FUN_08048554
FUN_08048554: @ 0x08048554
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080485AC @ =0x030000C4
	str r6, [r0]
	adds r5, r6, #0
	adds r5, #0x18
	bl FUN_0822ec58
	bl FUN_0822ec5c
	movs r0, #0x72
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080485B8
	bl Script_GetValue
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _080485B0 @ =0x00000179
	adds r1, r6, r3
	strb r0, [r1]
	bl Script_GetValue
	movs r7, #0xbd
	lsls r7, r7, #1
	adds r1, r6, r7
	strb r0, [r1]
	bl Script_GetValue
	ldr r2, _080485B4 @ =0x0000017B
	adds r1, r6, r2
	strb r0, [r1]
	b _080485D4
	.align 2, 0
_080485AC: .4byte 0x030000C4
_080485B0: .4byte 0x00000179
_080485B4: .4byte 0x0000017B
_080485B8:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	ldr r7, _0804864C @ =0x00000179
	adds r0, r6, r7
	strb r1, [r0]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, #3
	adds r0, r6, r3
	strb r1, [r0]
_080485D4:
	movs r7, #0xc6
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r4, #0
	str r4, [r0]
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r1, [r0]
	subs r7, #0x13
	adds r0, r6, r7
	ldrb r2, [r0]
	adds r3, #2
	adds r0, r6, r3
	ldrb r3, [r0]
	adds r7, #2
	adds r0, r6, r7
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_0804967c
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	movs r0, #0x73
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08048650
	bl FUN_0823d340
	adds r1, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r6, r2
	str r1, [r0]
	cmp r1, #0
	bne _08048638
	b _0804880C
_08048638:
	adds r0, r1, #0
	bl VM_ParseStringRef
	bl Textbox_LookupString
	str r0, [r5, #0x1c]
	cmp r0, #0
	bne _0804865A
	b _0804880C
	.align 2, 0
_0804864C: .4byte 0x00000179
_08048650:
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r6, r3
	str r1, [r0]
	str r1, [r5, #0x1c]
_0804865A:
	ldr r1, _080486C0 @ =0x0000519C
	movs r0, #0x63
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08047730
	cmp r0, #0
	bge _08048670
	b _0804880C
_08048670:
	adds r0, r6, #0
	bl FUN_08047768
	movs r4, #0
	strb r4, [r5, #0x11]
	ldr r7, _080486C4 @ =0x00000181
	adds r0, r6, r7
	strb r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r7, #0
	strh r0, [r1]
	ldr r3, _080486C8 @ =0x00000183
	adds r1, r6, r3
	movs r0, #3
	strb r0, [r1]
	ldr r1, _080486CC @ =0x0000017F
	adds r0, r6, r1
	strb r7, [r0]
	adds r2, #6
	adds r0, r6, r2
	strb r7, [r0]
	adds r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	strb r7, [r5, #0xd]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080486F0
	movs r7, #0xbb
	lsls r7, r7, #2
	adds r4, r6, r7
	b _080486E6
	.align 2, 0
_080486C0: .4byte 0x0000519C
_080486C4: .4byte 0x00000181
_080486C8: .4byte 0x00000183
_080486CC: .4byte 0x0000017F
_080486D0:
	bl Script_GetValue
	ldrb r2, [r5, #0xd]
	lsls r2, r2, #2
	adds r1, r5, #0
	adds r1, #0xc4
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080486E6:
	bl VM_GetPC
	cmp r0, #0
	bne _080486D0
	b _080486F8
_080486F0:
	strb r7, [r5, #0xd]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r4, r6, r0
_080486F8:
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r0, _080487EC @ =0x0000FFFF
	strh r0, [r1]
	ldr r1, _080487F0 @ =FUN_080483bc
	str r1, [r4]
	movs r3, #0xbf
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	ldr r5, _080487F4 @ =0x0000CB05
	mov sl, r5
	ldr r1, _080487F8 @ =0x000082F1
	mov r0, sl
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0804880C
	movs r7, #0xf6
	lsls r7, r7, #1
	adds r4, r6, r7
	adds r1, r4, #0
	adds r0, r2, #0
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r2, _080487FC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0xdf
	orrs r0, r1
	ldr r1, _080487EC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x8f
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r7, sp, #0x10
	mov r8, r7
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r0, #0x83
	lsls r0, r0, #2
	adds r5, r6, r0
	ldr r3, _08048800 @ =0x00003071
	movs r1, #0
	str r1, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r2, #0x3c
	mov sb, r2
	str r2, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #8
	bl FUN_0822f3fc
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08048804 @ =0x0000D27A
	mov r0, sl
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0804880C
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r1, r4, #0
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r1, #4
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x40
	mov r7, r8
	strh r0, [r7, #2]
	movs r0, #0
	strh r0, [r7, #4]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r3, _08048808 @ =0x00001051
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r5, sb
	str r5, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	adds r1, r4, #0
	bl FUN_0822f3fc
	movs r0, #0
	b _08048810
	.align 2, 0
_080487EC: .4byte 0x0000FFFF
_080487F0: .4byte FUN_080483bc
_080487F4: .4byte 0x0000CB05
_080487F8: .4byte 0x000082F1
_080487FC: .4byte 0xFFFF0000
_08048800: .4byte 0x00003071
_08048804: .4byte 0x0000D27A
_08048808: .4byte 0x00001051
_0804880C:
	movs r0, #1
	rsbs r0, r0, #0
_08048810:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048820
FUN_08048820: @ 0x08048820
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0804885C @ =0x030000C4
	ldr r4, [r0]
	cmp r4, #0
	bne _08048868
	movs r1, #0xbc
	lsls r1, r1, #2
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08048868
	ldr r1, _08048860 @ =FUN_08048430
	ldr r2, _08048864 @ =FUN_0804852c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08048554
	cmp r0, #0
	bge _08048868
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804886A
	.align 2, 0
_0804885C: .4byte 0x030000C4
_08048860: .4byte FUN_08048430
_08048864: .4byte FUN_0804852c
_08048868:
	adds r0, r4, #0
_0804886A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048870
FUN_08048870: @ 0x08048870
	push {lr}
	adds r2, r0, #0
	ldr r0, _08048890 @ =0x030000C4
	ldr r1, [r0]
	cmp r1, #0
	beq _08048894
	ldrb r0, [r1, #0x1a]
	str r0, [r2]
	ldrb r0, [r1, #0x1b]
	str r0, [r2, #4]
	ldrb r0, [r1, #0x1c]
	str r0, [r2, #8]
	ldrb r0, [r1, #0x1d]
	str r0, [r2, #0xc]
	movs r0, #0
	b _08048898
	.align 2, 0
_08048890: .4byte 0x030000C4
_08048894:
	movs r0, #1
	rsbs r0, r0, #0
_08048898:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804889c
FUN_0804889c: @ 0x0804889C
	push {lr}
	adds r1, r0, #0
	ldr r0, _080488B0 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _080488B4
	adds r0, #0x18
	bl FUN_08049708
	b _080488B6
	.align 2, 0
_080488B0: .4byte 0x030000C4
_080488B4:
	movs r0, #0
_080488B6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080488bc
FUN_080488bc: @ 0x080488BC
	push {lr}
	adds r1, r0, #0
	ldr r0, _080488D0 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _080488D4
	adds r0, #0x18
	bl FUN_08049784
	b _080488D6
	.align 2, 0
_080488D0: .4byte 0x030000C4
_080488D4:
	movs r0, #0
_080488D6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080488dc
FUN_080488dc: @ 0x080488DC
	push {lr}
	ldr r0, _080488F0 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _080488F4
	adds r0, #0x18
	bl FUN_08048c58
	b _080488F6
	.align 2, 0
_080488F0: .4byte 0x030000C4
_080488F4:
	movs r0, #0
_080488F6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080488fc
FUN_080488fc: @ 0x080488FC
	ldr r0, _0804890C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08048910 @ =0x00000938
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0804890C: .4byte 0x030046A0
_08048910: .4byte 0x00000938

	thumb_func_start FUN_08048914
FUN_08048914: @ 0x08048914
	push {lr}
	ldr r0, _08048928 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _0804892C
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	b _0804892E
	.align 2, 0
_08048928: .4byte 0x030000C4
_0804892C:
	movs r0, #0
_0804892E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08048934
FUN_08048934: @ 0x08048934
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, #6
	bhi _0804895A
	ldr r1, _08048960 @ =0x00000105
	adds r0, r3, r1
	ldrb r1, [r2]
	adds r0, r0, r1
	ldrb r1, [r3, #7]
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	strb r4, [r3, #7]
_0804895A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08048960: .4byte 0x00000105

	thumb_func_start FUN_08048964
FUN_08048964: @ 0x08048964
	push {lr}
	adds r2, r0, #0
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08048984
	subs r0, #1
	strb r0, [r1]
	ldr r3, _08048988 @ =0x00000105
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2, #7]
_08048984:
	pop {r0}
	bx r0
	.align 2, 0
_08048988: .4byte 0x00000105

	thumb_func_start FUN_0804898c
FUN_0804898c: @ 0x0804898C
	ldrb r1, [r0, #2]
	strb r1, [r0]
	ldrb r1, [r0, #1]
	adds r1, #2
	strb r1, [r0, #1]
	bx lr

	thumb_func_start FUN_08048998
FUN_08048998: @ 0x08048998
	push {r4, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _080489A6
	ldrb r1, [r3]
	adds r1, #1
	b _080489AA
_080489A6:
	ldrb r1, [r3]
	adds r1, #2
_080489AA:
	strb r1, [r3]
	ldrb r4, [r3]
	ldrb r2, [r3, #2]
	ldrb r1, [r3, #4]
	adds r1, r2, r1
	cmp r4, r1
	blt _080489BC
	subs r1, r4, r1
	strb r1, [r3]
_080489BC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080489c4
FUN_080489c4: @ 0x080489C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	bne _08048A18
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	bne _08048A18
	ldrb r0, [r4, #9]
	cmp r0, #1
	bls _080489E0
	ldrb r0, [r4, #0x16]
	cmp r0, #0
	beq _080489E6
_080489E0:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _08048A08
_080489E6:
	cmp r1, #0
	beq _08048A02
	ldr r0, _08048A0C @ =0x030047D8
	ldrh r0, [r0]
	cmp r1, r0
	beq _08048A02
	ldr r0, _08048A10 @ =0x085AB458
	ldrb r1, [r4, #0x11]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl PlaySound_082406e0
_08048A02:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _08048A14
_08048A08:
	movs r0, #0
	b _08048A16
	.align 2, 0
_08048A0C: .4byte 0x030047D8
_08048A10: .4byte 0x085AB458
_08048A14:
	adds r0, #1
_08048A16:
	strb r0, [r4, #0x12]
_08048A18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08048a20
FUN_08048a20: @ 0x08048A20
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl FUN_080489c4
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	ldrb r3, [r5, #6]
	adds r0, r4, #0
	bl Video_DrawCharNarrow
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08048998
	movs r1, #0
	strb r1, [r5, #0x13]
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048a4c
FUN_08048a4c: @ 0x08048A4C
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0
	bl FUN_080489c4
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	ldrb r3, [r5, #6]
	adds r0, r4, #0
	bl Video_DrawCharWide
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08048998
	movs r1, #1
	strb r1, [r5, #0x13]
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048a78
FUN_08048a78: @ 0x08048A78
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	ldr r3, [r4]
	cmp r3, r1
	blt _08048A90
_08048A84:
	adds r0, #1
	subs r2, r3, r1
	adds r3, r2, #0
	cmp r2, r1
	bge _08048A84
	str r2, [r4]
_08048A90:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08048a98
FUN_08048a98: @ 0x08048A98
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	bl VM_ParseStringRef
	adds r1, r0, #0
	adds r4, r1, r4
	adds r0, r4, #0
	bl Textbox_LookupString
	adds r1, r0, #0
	cmp r1, #0
	beq _08048ADC
	b _08048AC0
_08048AB8:
	ldrb r0, [r1]
	strb r0, [r5]
	adds r1, #1
	adds r5, #1
_08048AC0:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08048AB8
	adds r0, r6, #0
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldr r0, [sp, #0x10]
	adds r0, r1, r0
	bl Textbox_LookupString
	adds r1, r0, #0
	cmp r1, #0
	bne _08048AEC
_08048ADC:
	strb r1, [r5]
	movs r0, #1
	rsbs r0, r0, #0
	b _08048AF6
_08048AE4:
	ldrb r0, [r1]
	strb r0, [r5]
	adds r1, #1
	adds r5, #1
_08048AEC:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08048AE4
	strb r0, [r5]
	movs r0, #0
_08048AF6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048afc
FUN_08048afc: @ 0x08048AFC
	push {lr}
	ldr r2, _08048B10 @ =0x085AB45C
	ldrh r1, [r2]
	cmp r1, #0
	beq _08048B1C
	ldrb r0, [r0, #1]
_08048B08:
	cmp r1, r0
	bne _08048B14
	ldrh r0, [r2, #2]
	b _08048B1E
	.align 2, 0
_08048B10: .4byte 0x085AB45C
_08048B14:
	adds r2, #4
	ldrh r1, [r2]
	cmp r1, #0
	bne _08048B08
_08048B1C:
	ldr r0, _08048B24 @ =0x0000FFFF
_08048B1E:
	pop {r1}
	bx r1
	.align 2, 0
_08048B24: .4byte 0x0000FFFF

	thumb_func_start FUN_08048b28
FUN_08048b28: @ 0x08048B28
	push {r4, r5, lr}
	sub sp, #4
	str r1, [sp]
	movs r5, #0
	adds r4, r0, #0
	movs r2, #0
	adds r1, r4, #0
	adds r1, #0xb
_08048B38:
	strb r2, [r1]
	subs r1, #1
	cmp r1, r0
	bge _08048B38
	ldr r0, [sp]
	cmp r0, #0
	bge _08048B52
	movs r0, #0x2d
	strb r0, [r4]
	adds r4, #1
	ldr r0, [sp]
	rsbs r0, r0, #0
	str r0, [sp]
_08048B52:
	ldr r1, _08048BEC @ =0x000186A0
	mov r0, sp
	bl FUN_08048a78
	cmp r0, #0
	beq _08048B66
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048B66:
	ldr r1, _08048BF0 @ =0x00002710
	mov r0, sp
	bl FUN_08048a78
	cmp r0, #0
	bne _08048B76
	cmp r5, #0
	beq _08048B7E
_08048B76:
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048B7E:
	movs r1, #0xfa
	lsls r1, r1, #2
	mov r0, sp
	bl FUN_08048a78
	cmp r0, #0
	bne _08048B90
	cmp r5, #0
	beq _08048B98
_08048B90:
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048B98:
	mov r0, sp
	movs r1, #0x64
	bl FUN_08048a78
	cmp r0, #0
	bne _08048BA8
	cmp r5, #0
	beq _08048BB0
_08048BA8:
	adds r0, #0x30
	strb r0, [r4]
	movs r5, #1
	adds r4, #1
_08048BB0:
	mov r0, sp
	movs r1, #0xa
	bl FUN_08048a78
	cmp r0, #0
	bne _08048BC0
	cmp r5, #0
	beq _08048BC6
_08048BC0:
	adds r0, #0x30
	strb r0, [r4]
	adds r4, #1
_08048BC6:
	movs r0, #0
	ldr r2, [sp]
	adds r3, r4, #1
	cmp r2, #0
	ble _08048BDC
_08048BD0:
	adds r0, #1
	subs r1, r2, #1
	adds r2, r1, #0
	cmp r1, #0
	bgt _08048BD0
	str r1, [sp]
_08048BDC:
	adds r0, #0x30
	strb r0, [r4]
	movs r0, #0
	strb r0, [r3]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08048BEC: .4byte 0x000186A0
_08048BF0: .4byte 0x00002710

	thumb_func_start FUN_08048bf4
FUN_08048bf4: @ 0x08048BF4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r3, #0
	cmp r3, r2
	bge _08048C24
_08048BFE:
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08048C12
	ldrb r0, [r1]
	cmp r0, #0
	beq _08048C24
	movs r0, #1
	rsbs r0, r0, #0
	b _08048C26
_08048C12:
	ldrb r5, [r1]
	cmp r0, r5
	beq _08048C1C
	movs r0, #1
	b _08048C26
_08048C1C:
	adds r1, #1
	adds r3, #1
	cmp r3, r2
	blt _08048BFE
_08048C24:
	movs r0, #0
_08048C26:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048c2c
FUN_08048c2c: @ 0x08048C2C
	push {r4, lr}
	movs r4, #0
	movs r3, #1
	cmp r4, r1
	bge _08048C50
	subs r0, #1
	adds r2, r1, r0
_08048C3A:
	ldrb r0, [r2]
	subs r0, #0x30
	muls r0, r3, r0
	adds r4, r4, r0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r3, r0, #1
	subs r2, #1
	subs r1, #1
	cmp r1, #0
	bne _08048C3A
_08048C50:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048c58
FUN_08048c58: @ 0x08048C58
	push {r4, r5, lr}
	ldr r4, [r0, #0x1c]
	movs r5, #0
	b _08048CBA
_08048C60:
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08048CAE
	lsrs r0, r0, #0x18
	cmp r0, #0x3c
	bne _08048C7E
_08048C6C:
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _08048CAA
	cmp r0, #0
	beq _08048CAA
	cmp r0, #0xa
	bne _08048C6C
	b _08048CAA
_08048C7E:
	cmp r0, #0x1f
	bne _08048CA8
	adds r0, r4, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _08048CA4 @ =0x0000FFFF
	cmp r2, r0
	beq _08048CA8
	movs r0, #0xff
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08048CAE
	adds r5, #1
	b _08048CB0
	.align 2, 0
_08048CA4: .4byte 0x0000FFFF
_08048CA8:
	adds r5, #1
_08048CAA:
	adds r4, #1
	b _08048CB2
_08048CAE:
	adds r5, #2
_08048CB0:
	adds r4, #2
_08048CB2:
	cmp r5, #0xfe
	ble _08048CBA
	movs r5, #0xff
	b _08048CC0
_08048CBA:
	ldrb r0, [r4]
	cmp r0, #0
	bne _08048C60
_08048CC0:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08048cc8
FUN_08048cc8: @ 0x08048CC8
	push {lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	b _08048CD2
_08048CD0:
	adds r0, #1
_08048CD2:
	ldrb r2, [r0]
	cmp r2, r1
	beq _08048CDC
	cmp r2, #0
	bne _08048CD0
_08048CDC:
	pop {r1}
	bx r1

	thumb_func_start FUN_08048ce0
FUN_08048ce0: @ 0x08048CE0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r0, #0
	str r0, [r3, #0x2c]
	str r0, [r3, #0x30]
	movs r5, #0
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _08048D2A
	adds r6, r3, #0
	adds r6, #0x34
	cmp r0, #0
	beq _08048D2A
_08048CFC:
	ldrb r2, [r4]
	cmp r2, #0x3d
	bne _08048D08
	movs r0, #1
	str r0, [r3, #0x2c]
	b _08048D18
_08048D08:
	ldr r0, [r3, #0x2c]
	cmp r0, #0
	beq _08048D18
	ldr r1, [r3, #0x30]
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	str r1, [r3, #0x30]
_08048D18:
	adds r5, #1
	adds r4, #1
	cmp r5, #0x3f
	bgt _08048D2A
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _08048D2A
	cmp r0, #0
	bne _08048CFC
_08048D2A:
	adds r0, r3, #0
	adds r0, #0x34
	ldr r1, [r3, #0x30]
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08048d40
FUN_08048d40: @ 0x08048D40
	push {lr}
	ldr r0, _08048D60 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _08048D72
	cmp r0, #1
	bgt _08048D64
	cmp r0, #0
	beq _08048D6A
	b _08048D72
	.align 2, 0
_08048D60: .4byte 0x030046A0
_08048D64:
	cmp r0, #5
	beq _08048D6E
	b _08048D72
_08048D6A:
	movs r0, #0
	b _08048D74
_08048D6E:
	movs r0, #3
	b _08048D74
_08048D72:
	movs r0, #1
_08048D74:
	pop {r1}
	bx r1

	thumb_func_start FUN_08048d78
FUN_08048d78: @ 0x08048D78
	push {lr}
	ldr r0, _08048D98 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _08048D9C
	cmp r0, #1
	bgt _08048D9C
	cmp r0, #0
	bne _08048D9C
	movs r0, #0x1b
	b _08048D9E
	.align 2, 0
_08048D98: .4byte 0x030046A0
_08048D9C:
	movs r0, #0x1c
_08048D9E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08048da4
FUN_08048da4: @ 0x08048DA4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r7, r4, #0
	ldrb r0, [r4]
	cmp r0, #0x2f
	bne _08048DB4
	b _080493D0
_08048DB4:
	ldr r1, _08048DC8 @ =0x08251B64
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048DCC
	movs r0, #1
	b _0804945A
	.align 2, 0
_08048DC8: .4byte 0x08251B64
_08048DCC:
	ldr r1, _08048DE0 @ =0x08251B6C
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048DE4
	movs r0, #2
	b _0804945A
	.align 2, 0
_08048DE0: .4byte 0x08251B6C
_08048DE4:
	ldr r1, _08048DF8 @ =0x08251B74
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048DFC
	movs r0, #2
	b _0804945A
	.align 2, 0
_08048DF8: .4byte 0x08251B74
_08048DFC:
	ldr r1, _08048E2C @ =0x08251B7C
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048E40
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _08048E30
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _08048E30
	adds r0, r5, #0
	adds r0, #0x34
	bl FUN_08048c2c
	strb r0, [r5, #9]
	b _08049466
	.align 2, 0
_08048E2C: .4byte 0x08251B7C
_08048E30:
	ldr r0, _08048E3C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	strb r0, [r5, #9]
	b _08049466
	.align 2, 0
_08048E3C: .4byte 0x030046A0
_08048E40:
	ldr r1, _08048E70 @ =0x08251B84
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048E90
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _08048E74
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _08048E74
	adds r0, r5, #0
	adds r0, #0x34
	bl FUN_08048c2c
	adds r3, r0, #0
	b _08048E76
	.align 2, 0
_08048E70: .4byte 0x08251B84
_08048E74:
	movs r3, #0
_08048E76:
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r2]
	adds r0, r0, r1
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	b _08049466
_08048E90:
	ldr r1, _08048EB0 @ =0x08251B8C
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048EB4
	bl FUN_0823cd38
	str r0, [r5, #0x20]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08048934
	adds r0, r4, #0
	b _08049302
	.align 2, 0
_08048EB0: .4byte 0x08251B8C
_08048EB4:
	ldr r1, _08048F14 @ =0x08251B94
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	beq _08048EC4
	b _080491D8
_08048EC4:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	bne _08048ED6
	b _080491C4
_08048ED6:
	ldr r0, [r5, #0x30]
	cmp r0, #0
	bne _08048EDE
	b _080491C4
_08048EDE:
	adds r4, r5, #0
	adds r4, #0x34
	ldr r1, _08048F18 @ =0x08251B9C
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048EF2
	b _080491C4
_08048EF2:
	ldr r1, _08048F1C @ =0x08251BA4
	adds r0, r4, #0
	movs r2, #8
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048F02
	b _080491C6
_08048F02:
	ldr r1, _08048F20 @ =0x08251BB0
	adds r0, r4, #0
	movs r2, #8
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048F24
	movs r0, #1
	b _080491C6
	.align 2, 0
_08048F14: .4byte 0x08251B94
_08048F18: .4byte 0x08251B9C
_08048F1C: .4byte 0x08251BA4
_08048F20: .4byte 0x08251BB0
_08048F24:
	ldr r1, _08048F38 @ =0x08251BBC
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048F3C
	movs r0, #2
	b _080491C6
	.align 2, 0
_08048F38: .4byte 0x08251BBC
_08048F3C:
	ldr r1, _08048F50 @ =0x08251BC4
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048F54
	movs r0, #3
	b _080491C6
	.align 2, 0
_08048F50: .4byte 0x08251BC4
_08048F54:
	ldr r1, _08048F68 @ =0x08251BCC
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048F6C
	movs r0, #4
	b _080491C6
	.align 2, 0
_08048F68: .4byte 0x08251BCC
_08048F6C:
	ldr r1, _08048F80 @ =0x08251BD4
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048F84
	movs r0, #5
	b _080491C6
	.align 2, 0
_08048F80: .4byte 0x08251BD4
_08048F84:
	ldr r1, _08048F98 @ =0x08251BDC
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048F9C
	movs r0, #6
	b _080491C6
	.align 2, 0
_08048F98: .4byte 0x08251BDC
_08048F9C:
	ldr r1, _08048FB0 @ =0x08251BE4
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048FB4
	movs r0, #7
	b _080491C6
	.align 2, 0
_08048FB0: .4byte 0x08251BE4
_08048FB4:
	ldr r1, _08048FC8 @ =0x08251BEC
	adds r0, r4, #0
	movs r2, #8
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048FCC
	movs r0, #0x1d
	b _080491C6
	.align 2, 0
_08048FC8: .4byte 0x08251BEC
_08048FCC:
	ldr r1, _08048FE0 @ =0x08251BF8
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048FE4
	movs r0, #8
	b _080491C6
	.align 2, 0
_08048FE0: .4byte 0x08251BF8
_08048FE4:
	ldr r1, _08048FF8 @ =0x08251C00
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08048bf4
	cmp r0, #0
	bne _08048FFC
	movs r0, #9
	b _080491C6
	.align 2, 0
_08048FF8: .4byte 0x08251C00
_08048FFC:
	ldr r1, _08049010 @ =0x08251C04
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049014
	movs r0, #0xa
	b _080491C6
	.align 2, 0
_08049010: .4byte 0x08251C04
_08049014:
	ldr r1, _08049028 @ =0x08251C0C
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08048bf4
	cmp r0, #0
	bne _0804902C
	movs r0, #0xb
	b _080491C6
	.align 2, 0
_08049028: .4byte 0x08251C0C
_0804902C:
	ldr r1, _08049040 @ =0x08251C14
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049044
	movs r0, #0xc
	b _080491C6
	.align 2, 0
_08049040: .4byte 0x08251C14
_08049044:
	ldr r1, _08049058 @ =0x08251C1C
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _0804905C
	movs r0, #0xd
	b _080491C6
	.align 2, 0
_08049058: .4byte 0x08251C1C
_0804905C:
	ldr r1, _08049070 @ =0x08251C24
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049074
	movs r0, #0xe
	b _080491C6
	.align 2, 0
_08049070: .4byte 0x08251C24
_08049074:
	ldr r1, _08049088 @ =0x08251C2C
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	bne _0804908C
	movs r0, #0xf
	b _080491C6
	.align 2, 0
_08049088: .4byte 0x08251C2C
_0804908C:
	ldr r1, _080490A0 @ =0x08251C34
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	bne _080490A4
	movs r0, #0x10
	b _080491C6
	.align 2, 0
_080490A0: .4byte 0x08251C34
_080490A4:
	ldr r1, _080490B8 @ =0x08251C3C
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _080490BC
	movs r0, #0x11
	b _080491C6
	.align 2, 0
_080490B8: .4byte 0x08251C3C
_080490BC:
	ldr r1, _080490D0 @ =0x08251C44
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	bne _080490D4
	movs r0, #0x12
	b _080491C6
	.align 2, 0
_080490D0: .4byte 0x08251C44
_080490D4:
	ldr r1, _080490E8 @ =0x08251C4C
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	bne _080490EC
	movs r0, #0x13
	b _080491C6
	.align 2, 0
_080490E8: .4byte 0x08251C4C
_080490EC:
	ldr r1, _08049100 @ =0x08251C54
	adds r0, r4, #0
	movs r2, #9
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049104
	movs r0, #0x14
	b _080491C6
	.align 2, 0
_08049100: .4byte 0x08251C54
_08049104:
	ldr r1, _08049118 @ =0x08251C60
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _0804911C
	movs r0, #0x15
	b _080491C6
	.align 2, 0
_08049118: .4byte 0x08251C60
_0804911C:
	ldr r1, _08049130 @ =0x08251C68
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049134
	movs r0, #0x16
	b _080491C6
	.align 2, 0
_08049130: .4byte 0x08251C68
_08049134:
	ldr r1, _08049148 @ =0x08251C70
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _0804914C
	movs r0, #0x17
	b _080491C6
	.align 2, 0
_08049148: .4byte 0x08251C70
_0804914C:
	ldr r1, _08049160 @ =0x08251C78
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049164
	movs r0, #0x18
	b _080491C6
	.align 2, 0
_08049160: .4byte 0x08251C78
_08049164:
	ldr r1, _08049178 @ =0x08251C80
	adds r0, r4, #0
	movs r2, #8
	bl FUN_08048bf4
	cmp r0, #0
	bne _0804917C
	movs r0, #0x19
	b _080491C6
	.align 2, 0
_08049178: .4byte 0x08251C80
_0804917C:
	ldr r1, _08049190 @ =0x08251C8C
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049194
	movs r0, #0x1a
	b _080491C6
	.align 2, 0
_08049190: .4byte 0x08251C8C
_08049194:
	ldr r1, _080491A8 @ =0x08251C94
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _080491AC
	bl FUN_08048d78
	b _080491C6
	.align 2, 0
_080491A8: .4byte 0x08251C94
_080491AC:
	ldr r1, _080491C0 @ =0x08251C9C
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _080491C4
	bl FUN_08048d40
	b _080491C6
	.align 2, 0
_080491C0: .4byte 0x08251C9C
_080491C4:
	movs r0, #0xff
_080491C6:
	strb r0, [r5, #0x15]
	movs r0, #0
	movs r1, #1
	strb r1, [r5, #0xb]
	ldrb r1, [r5, #9]
	strb r1, [r5, #0xc]
	strb r0, [r5, #9]
	adds r0, r7, #0
	b _0804945E
_080491D8:
	ldr r1, _080491EC @ =0x08251CA4
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	bne _080491F0
	movs r0, #0xff
	strb r0, [r5, #0x15]
	b _0804945C
	.align 2, 0
_080491EC: .4byte 0x08251CA4
_080491F0:
	ldr r1, _08049220 @ =0x08251CAC
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08048bf4
	cmp r0, #0
	bne _0804922A
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _08049224
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _08049224
	adds r0, r5, #0
	adds r0, #0x34
	bl FUN_08048c2c
	b _08049226
	.align 2, 0
_08049220: .4byte 0x08251CAC
_08049224:
	movs r0, #0
_08049226:
	str r0, [r5, #0x18]
	b _08049466
_0804922A:
	ldr r1, _08049258 @ =0x08251CB4
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049272
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _0804925C
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _0804925C
	adds r0, r5, #0
	adds r0, #0x34
	bl FUN_08048c2c
	b _0804925E
	.align 2, 0
_08049258: .4byte 0x08251CB4
_0804925C:
	movs r0, #0
_0804925E:
	lsls r1, r0, #2
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r5, #0x28]
	adds r0, r5, #0
	movs r1, #3
	b _080492FC
_08049272:
	ldr r1, _080492A0 @ =0x08251CBC
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _080492AC
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _080492A4
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _080492A4
	adds r0, r5, #0
	adds r0, #0x34
	bl FUN_08048c2c
	b _080492A6
	.align 2, 0
_080492A0: .4byte 0x08251CBC
_080492A4:
	movs r0, #0xdd
_080492A6:
	bl PlaySound_082406e0
	b _08049466
_080492AC:
	ldr r1, _080492DC @ =0x08251CC4
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049310
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _080492E0
	ldr r1, [r5, #0x30]
	cmp r1, #0
	beq _080492E0
	adds r0, r5, #0
	adds r0, #0x34
	bl FUN_08048c2c
	b _080492E2
	.align 2, 0
_080492DC: .4byte 0x08251CC4
_080492E0:
	movs r0, #0
_080492E2:
	adds r4, r5, #0
	adds r4, #0x78
	lsls r1, r0, #2
	adds r0, r5, #0
	adds r0, #0x84
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_08048b28
	str r4, [r5, #0x24]
	adds r0, r5, #0
	movs r1, #2
_080492FC:
	bl FUN_08048934
	adds r0, r7, #0
_08049302:
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r7, r0, #0
	movs r0, #1
	strb r0, [r5, #0xe]
	b _08049466
_08049310:
	ldr r1, _08049340 @ =0x08251CC8
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	adds r6, r0, #0
	cmp r6, #0
	bne _08049360
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08048ce0
	adds r7, r0, #0
	adds r4, r5, #0
	adds r4, #0x34
	ldr r1, _08049344 @ =0x08251CD0
	adds r0, r4, #0
	movs r2, #0xd
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049348
_0804933C:
	strb r6, [r5, #0x11]
	b _08049466
	.align 2, 0
_08049340: .4byte 0x08251CC8
_08049344: .4byte 0x08251CD0
_08049348:
	ldr r1, _0804935C @ =0x08251CE0
	adds r0, r4, #0
	movs r2, #0xb
	bl FUN_08048bf4
	cmp r0, #0
	bne _0804933C
	movs r0, #1
	strb r0, [r5, #0x11]
	b _08049466
	.align 2, 0
_0804935C: .4byte 0x08251CE0
_08049360:
	ldr r1, _08049384 @ =0x08251CEC
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049388
	bl FUN_0823cd38
	str r0, [r5, #0x20]
	adds r0, r7, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r7, r0, #0
	movs r0, #1
	strb r0, [r5, #0xf]
	b _08049466
	.align 2, 0
_08049384: .4byte 0x08251CEC
_08049388:
	ldr r1, _080493B0 @ =0x08251CF0
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _080493B4
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _080493AC
	adds r0, r5, #0
	movs r1, #0x5b
	bl FUN_080489c4
	adds r0, r5, #0
	movs r1, #0x3b
	bl FUN_08048a20
_080493AC:
	adds r0, r7, #0
	b _0804945E
	.align 2, 0
_080493B0: .4byte 0x08251CF0
_080493B4:
	ldr r1, _080493CC @ =0x08251CF8
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049466
	movs r0, #1
	strb r0, [r5, #6]
	adds r0, r7, #0
	b _0804945E
	.align 2, 0
_080493CC: .4byte 0x08251CF8
_080493D0:
	ldr r1, _08049410 @ =0x08251D00
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	beq _0804945A
	ldr r1, _08049414 @ =0x08251D08
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	beq _0804945A
	ldr r1, _08049418 @ =0x08251D10
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08048bf4
	cmp r0, #0
	beq _0804945A
	ldr r1, _0804941C @ =0x08251D18
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049420
	strb r0, [r5, #0xb]
	ldrb r0, [r5, #0xc]
	strb r0, [r5, #9]
	b _0804945C
	.align 2, 0
_08049410: .4byte 0x08251D00
_08049414: .4byte 0x08251D08
_08049418: .4byte 0x08251D10
_0804941C: .4byte 0x08251D18
_08049420:
	ldr r1, _08049448 @ =0x08251D20
	adds r0, r4, #0
	movs r2, #5
	bl FUN_08048bf4
	cmp r0, #0
	bne _0804944C
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	beq _0804945C
	adds r0, r5, #0
	movs r1, #0x5d
	bl FUN_080489c4
	adds r0, r5, #0
	movs r1, #0x3d
	bl FUN_08048a20
	b _0804945C
	.align 2, 0
_08049448: .4byte 0x08251D20
_0804944C:
	ldr r1, _08049484 @ =0x08251D28
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049466
_0804945A:
	strb r0, [r5, #6]
_0804945C:
	adds r0, r4, #0
_0804945E:
	movs r1, #0x3e
	bl FUN_08048cc8
	adds r7, r0, #0
_08049466:
	ldrb r0, [r5, #0x14]
	cmp r0, #0
	bne _08049470
	movs r0, #1
	strb r0, [r5, #0xe]
_08049470:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08049478
	adds r7, #1
_08049478:
	adds r4, r7, #0
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08049484: .4byte 0x08251D28

	thumb_func_start FUN_08049488
FUN_08049488: @ 0x08049488
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	b _08049546
_08049490:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08048da4
	adds r5, r0, #0
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	bne _08049560
	ldrb r0, [r5]
	cmp r0, #0
	bne _08049544
	b _08049560
_080494A8:
	ldrb r0, [r5]
	cmp r0, #0xa
	bne _080494B6
	adds r0, r6, #0
	bl FUN_0804898c
	b _08049544
_080494B6:
	cmp r0, #0x1f
	bne _08049506
	adds r0, r5, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080494DC @ =0x0000FFFF
	cmp r1, r0
	bne _080494E0
	ldrb r0, [r5]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08048a20
	b _08049502
	.align 2, 0
_080494DC: .4byte 0x0000FFFF
_080494E0:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080494FC
	ldr r0, _080494F8 @ =0x00007FFF
	ands r1, r0
	adds r0, r6, #0
	bl FUN_08048a20
	b _08049502
	.align 2, 0
_080494F8: .4byte 0x00007FFF
_080494FC:
	adds r0, r6, #0
	bl FUN_08048a20
_08049502:
	adds r5, #2
	b _08049560
_08049506:
	ldrb r0, [r5]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08048a20
_08049516:
	adds r5, #1
	b _08049560
_0804951A:
	ldrb r1, [r5]
	movs r0, #0x7f
	ands r0, r1
	adds r5, #1
	ldrb r1, [r5]
	lsls r4, r0, #8
	orrs r4, r1
	bl FUN_0822e860
	cmp r4, r0
	blo _0804953A
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08048998
	b _08049516
_0804953A:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08048a4c
	b _08049516
_08049544:
	adds r5, #1
_08049546:
	ldrb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _0804951A
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08049560
	cmp r0, #0x3c
	bne _080494A8
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08049490
_08049560:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049568
FUN_08049568: @ 0x08049568
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strb r0, [r4, #0xe]
	ldrb r0, [r4, #7]
	cmp r0, #1
	beq _080495A6
	cmp r0, #1
	bgt _08049580
	cmp r0, #0
	beq _0804958A
	b _08049604
_08049580:
	cmp r0, #2
	beq _080495BA
	cmp r0, #3
	beq _080495CE
	b _08049604
_0804958A:
	ldr r1, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x1c]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08049600
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08049604
	ldrb r0, [r1]
	b _080495FC
_080495A6:
	ldr r1, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x20]
	ldrb r0, [r4, #7]
	cmp r0, #1
	bne _08049604
	b _080495E0
_080495BA:
	ldr r1, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x24]
	ldrb r0, [r4, #7]
	cmp r0, #2
	bne _08049604
	b _080495E0
_080495CE:
	ldr r1, [r4, #0x28]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x28]
	ldrb r0, [r4, #7]
	cmp r0, #3
	bne _08049604
_080495E0:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08049604
	adds r0, r4, #0
	bl FUN_08048964
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08049604
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08049600
	ldr r0, [r4, #0x1c]
	ldrb r0, [r0]
_080495FC:
	cmp r0, #0
	bne _08049604
_08049600:
	movs r0, #1
	b _08049606
_08049604:
	movs r0, #0
_08049606:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804960c
FUN_0804960c: @ 0x0804960C
	push {lr}
	ldrb r1, [r0, #7]
	cmp r1, #1
	beq _0804962C
	cmp r1, #1
	bgt _0804961E
	cmp r1, #0
	beq _08049628
	b _08049638
_0804961E:
	cmp r1, #2
	beq _08049630
	cmp r1, #3
	beq _08049634
	b _08049638
_08049628:
	ldr r0, [r0, #0x1c]
	b _0804963A
_0804962C:
	ldr r0, [r0, #0x20]
	b _0804963A
_08049630:
	ldr r0, [r0, #0x24]
	b _0804963A
_08049634:
	ldr r0, [r0, #0x28]
	b _0804963A
_08049638:
	movs r0, #0
_0804963A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049640
FUN_08049640: @ 0x08049640
	movs r1, #0
	strb r1, [r0, #6]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r0, r3
	strb r1, [r2]
	strb r1, [r0, #7]
	bx lr

	thumb_func_start FUN_08049650
FUN_08049650: @ 0x08049650
	push {r4, lr}
	ldr r4, [sp, #8]
	strb r1, [r0, #2]
	strb r2, [r0, #3]
	strb r3, [r0, #4]
	strb r4, [r0, #5]
	strb r1, [r0]
	strb r2, [r0, #1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08049668
FUN_08049668: @ 0x08049668
	movs r1, #0
	strb r1, [r0, #8]
	ldr r1, _08049678 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x12
	ldrsh r1, [r1, r2]
	strb r1, [r0, #9]
	bx lr
	.align 2, 0
_08049678: .4byte 0x030046A0

	thumb_func_start FUN_0804967c
FUN_0804967c: @ 0x0804967C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [sp, #0xc]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08049650
	adds r0, r4, #0
	bl FUN_08049640
	adds r0, r4, #0
	bl FUN_08049668
	movs r0, #0
	strb r0, [r4, #0xa]
	strb r0, [r4, #0xb]
	ldrb r1, [r4, #9]
	strb r1, [r4, #0xc]
	strb r0, [r4, #0x13]
	strb r0, [r4, #0xd]
	str r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r0, [r4, #0x24]
	str r0, [r4, #0x28]
	movs r1, #0xff
	strb r1, [r4, #0x15]
	movs r1, #1
	strb r1, [r4, #0x14]
	str r0, [r4, #0x18]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080496c0
FUN_080496c0: @ 0x080496C0
	adds r3, r0, #0
	lsls r1, r1, #2
	adds r3, #0x84
	adds r3, r3, r1
	str r2, [r3]
	bx lr

	thumb_func_start FUN_080496cc
FUN_080496cc: @ 0x080496CC
	push {r4, lr}
	adds r3, r0, #0
	lsls r1, r1, #2
	movs r4, #0x86
	lsls r4, r4, #1
	adds r3, r3, r4
	adds r3, r3, r1
	str r2, [r3]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080496e4
FUN_080496e4: @ 0x080496E4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	ble _08049700
	adds r5, r2, #0
	adds r2, r6, #0
	adds r2, #0xc4
	adds r3, r4, #0
_080496F6:
	ldm r5!, {r1}
	stm r2!, {r1}
	subs r3, #1
	cmp r3, #0
	bne _080496F6
_08049700:
	strb r4, [r6, #0xd]
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049708
FUN_08049708: @ 0x08049708
	push {lr}
	lsls r1, r1, #2
	adds r0, #0x84
	adds r0, r0, r1
	ldr r1, [r0]
	lsrs r2, r1, #0x1f
	adds r0, r1, #0
	cmp r1, #0
	bge _0804971C
	rsbs r0, r1, #0
_0804971C:
	adds r1, r0, #0
	ldr r0, _08049728 @ =0x0098967F
	cmp r1, r0
	ble _0804972C
	adds r2, #8
	b _0804977E
	.align 2, 0
_08049728: .4byte 0x0098967F
_0804972C:
	ldr r0, _08049738 @ =0x000F423F
	cmp r1, r0
	ble _0804973C
	adds r2, #7
	b _0804977E
	.align 2, 0
_08049738: .4byte 0x000F423F
_0804973C:
	ldr r0, _08049748 @ =0x0001869F
	cmp r1, r0
	ble _0804974C
	adds r2, #6
	b _0804977E
	.align 2, 0
_08049748: .4byte 0x0001869F
_0804974C:
	ldr r0, _08049758 @ =0x0000270F
	cmp r1, r0
	ble _0804975C
	adds r2, #5
	b _0804977E
	.align 2, 0
_08049758: .4byte 0x0000270F
_0804975C:
	ldr r0, _08049768 @ =0x000003E7
	cmp r1, r0
	ble _0804976C
	adds r2, #4
	b _0804977E
	.align 2, 0
_08049768: .4byte 0x000003E7
_0804976C:
	cmp r1, #0x63
	ble _08049774
	adds r2, #3
	b _0804977E
_08049774:
	cmp r1, #9
	ble _0804977C
	adds r2, #2
	b _0804977E
_0804977C:
	adds r2, #1
_0804977E:
	adds r0, r2, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08049784
FUN_08049784: @ 0x08049784
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	ldr r5, [r0]
	movs r7, #0
	b _08049866
_0804979C:
	ldrb r0, [r5]
	cmp r0, #0x3c
	bne _08049834
	adds r5, #1
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049878
	adds r4, r5, #0
	ldr r1, _080497D0 @ =0x08251CC4
	adds r0, r5, #0
	movs r2, #3
	bl FUN_08048bf4
	cmp r0, #0
	bne _08049824
	movs r6, #0
	movs r2, #0
	ldrb r0, [r5]
	mov r3, r8
	adds r3, #0x34
	cmp r0, #0x3e
	beq _080497F6
	cmp r0, #0
	bne _080497D4
	adds r4, r5, #1
	b _080497F6
	.align 2, 0
_080497D0: .4byte 0x08251CC4
_080497D4:
	ldrb r1, [r4]
	cmp r1, #0x3d
	bne _080497DE
	movs r6, #1
	b _080497E8
_080497DE:
	cmp r6, #0
	beq _080497E8
	adds r0, r3, r2
	strb r1, [r0]
	adds r2, #1
_080497E8:
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _080497F6
	cmp r0, #0
	bne _080497D4
	adds r4, #1
_080497F6:
	adds r1, r3, r2
	movs r0, #0
	strb r0, [r1]
	cmp r6, #0
	beq _08049810
	cmp r2, #0
	beq _08049810
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_08048c2c
	adds r1, r0, #0
	b _08049812
_08049810:
	movs r1, #0
_08049812:
	mov r0, r8
	bl FUN_08049708
	adds r7, r7, r0
	adds r0, r4, #0
	movs r1, #0x3e
	bl FUN_08048cc8
	b _0804982C
_08049824:
	adds r0, r5, #0
	movs r1, #0x3e
	bl FUN_08048cc8
_0804982C:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049878
	b _08049866
_08049834:
	cmp r0, #0x1f
	bne _0804985C
	adds r0, r5, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08049858 @ =0x0000FFFF
	cmp r1, r0
	beq _08049862
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08049862
	adds r7, #1
	b _08049864
	.align 2, 0
_08049858: .4byte 0x0000FFFF
_0804985C:
	adds r7, #1
	adds r5, #1
	b _08049866
_08049862:
	adds r7, #2
_08049864:
	adds r5, #2
_08049866:
	ldrb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08049862
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08049878
	cmp r0, #0xa
	bne _0804979C
_08049878:
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049884
FUN_08049884: @ 0x08049884
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	bx lr

	thumb_func_start FUN_08049890
FUN_08049890: @ 0x08049890
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _080498B4
_08049898:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r0, r4, #0
	adds r0, #0xc4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	bl Script_ExecById
	adds r5, #1
_080498B4:
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r5, r0
	blo _08049898
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080498c8
FUN_080498c8: @ 0x080498C8
	ldr r1, _080498D0 @ =0x030000C8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080498D0: .4byte 0x030000C8

	thumb_func_start FUN_080498d4
FUN_080498d4: @ 0x080498D4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r4, #0x18
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x20
	movs r3, #2
	bl FUN_0822ea60
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x20
	movs r3, #2
	bl FUN_0822eadc
	movs r0, #2
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #0x20
	bl FUN_08049650
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804990c
FUN_0804990c: @ 0x0804990C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	cmp r1, #0
	beq _0804991C
	bl FUN_080498d4
_0804991C:
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #4
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #9
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0x1e
	strb r0, [r2]
	ldr r2, _08049968 @ =0x0000017D
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #0x13
	adds r0, r4, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	strb r1, [r5, #7]
	adds r0, r5, #0
	bl FUN_08049640
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08049968: .4byte 0x0000017D

	thumb_func_start FUN_0804996c
FUN_0804996c: @ 0x0804996C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x18
	movs r0, #0
	mov r8, r0
	ldr r1, _080499B4 @ =0x0000017B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080499D4
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _080499CE
	ldr r0, _080499B8 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080499BC
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #4
	rsbs r2, r2, #0
	ands r1, r2
	adds r1, #4
	str r1, [r0]
	b _080499C8
	.align 2, 0
_080499B4: .4byte 0x0000017B
_080499B8: .4byte 0x030044E0
_080499BC:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080499C8:
	movs r0, #1
	mov r8, r0
	b _080499EA
_080499CE:
	subs r0, #1
	strb r0, [r1]
	b _080499EA
_080499D4:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #8
	rsbs r2, r2, #0
	ands r1, r2
	adds r1, #8
	str r1, [r0]
	movs r2, #1
	mov r8, r2
_080499EA:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080499FC
	b _08049C1A
_080499FC:
	ldr r2, _08049AE8 @ =0x0000017B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049A1E
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _08049A1E
	ldr r0, _08049AEC @ =0x0000017D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08049A1E
	strb r2, [r1]
_08049A1E:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08049A70
	ldr r2, _08049AE8 @ =0x0000017B
	adds r6, r5, r2
	ldrb r0, [r6]
	cmp r0, #0
	bne _08049A70
	subs r1, #8
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x1f
	bne _08049A70
	adds r2, #9
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #8
	bne _08049A70
	adds r0, r7, #0
	bl FUN_0804960c
	cmp r0, #0
	beq _08049A70
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08049A70
	ldr r0, [r4]
	subs r0, #8
	str r0, [r4]
	movs r0, #1
	strb r0, [r6]
	ldr r2, _08049AEC @ =0x0000017D
	adds r1, r5, r2
	strb r0, [r1]
_08049A70:
	ldr r1, _08049AEC @ =0x0000017D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049A7C
	b _08049C1A
_08049A7C:
	mov r2, r8
	cmp r2, #0
	bne _08049A84
	b _08049C1A
_08049A84:
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #0x12
	movs r2, #1
	movs r3, #2
	bl FUN_0822ea60
	ldr r0, [r4]
	movs r1, #0x12
	movs r2, #1
	movs r3, #2
	bl FUN_0822eadc
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_0804960c
	adds r4, r0, #0
	cmp r4, #0
	bne _08049AB6
	b _08049BEA
_08049AB6:
	ldrb r0, [r4]
	cmp r0, #0x3c
	bne _08049AF0
	adds r0, r7, #0
	bl FUN_08049568
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08049AF0
	adds r0, r7, #0
	bl FUN_0804960c
	adds r4, r0, #0
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _08049AB6
	ldrb r0, [r4]
	cmp r0, #0
	bne _08049AB6
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #8
	str r0, [r1]
	b _08049AB6
	.align 2, 0
_08049AE8: .4byte 0x0000017B
_08049AEC: .4byte 0x0000017D
_08049AF0:
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _08049B54
	adds r0, r5, #0
	adds r0, #0x18
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r1, [r4]
	movs r2, #2
	str r2, [sp]
	movs r2, #0x12
	movs r3, #1
	bl FUN_08049650
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	movs r2, #0xc8
	lsls r2, r2, #1
	adds r4, r5, r2
	ldr r0, [r4]
	cmp r0, #0
	ble _08049B44
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08048a20
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bgt _08049BEA
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	movs r0, #0
	str r0, [r4]
	b _08049BEA
_08049B44:
	adds r0, r7, #0
	bl FUN_08049568
	cmp r0, #0
	beq _08049BEA
	movs r0, #8
	str r0, [r4]
	b _08049BEA
_08049B54:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08049B76
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08049B86
	b _08049BEA
_08049B76:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #8
	bne _08049BEA
_08049B86:
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r0, [r6]
	cmp r0, #0
	ble _08049BBE
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08048a20
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
	cmp r0, #0
	bgt _08049BEA
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	movs r0, #0
	b _08049BE8
_08049BBE:
	adds r0, r5, #0
	adds r0, #0x18
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r1, [r4]
	movs r2, #2
	str r2, [sp]
	movs r2, #0x12
	movs r3, #2
	bl FUN_08049650
	ldr r0, [r4]
	adds r0, #2
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_08049568
	cmp r0, #0
	beq _08049BEA
	movs r0, #8
_08049BE8:
	str r0, [r6]
_08049BEA:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1f
	ble _08049C0A
	ldr r0, _08049C38 @ =0x0000017B
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _08049C04
	movs r0, #1
	strb r0, [r2]
_08049C04:
	ldr r0, [r1]
	subs r0, #0x20
	str r0, [r1]
_08049C0A:
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	cmp r0, #0x1f
	ble _08049C1A
	subs r0, #0x20
	str r0, [r1]
_08049C1A:
	ldr r1, _08049C38 @ =0x0000017B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08049C2A
	adds r0, r5, #0
	bl FUN_0804996c
_08049C2A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08049C38: .4byte 0x0000017B

	thumb_func_start FUN_08049c3c
FUN_08049c3c: @ 0x08049C3C
	push {r4, lr}
	adds r1, r0, #0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r1, r0
	ldrb r2, [r4]
	cmp r2, #0
	bne _08049C6C
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r1, r3
	str r2, [r0]
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0804990c
	ldr r1, _08049C68 @ =0x03003520
	movs r0, #1
	str r0, [r1]
	strb r0, [r4]
	movs r0, #0
	b _08049C70
	.align 2, 0
_08049C68: .4byte 0x03003520
_08049C6C:
	movs r0, #1
	rsbs r0, r0, #0
_08049C70:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049c78
FUN_08049c78: @ 0x08049C78
	push {r4, lr}
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _08049C98
	bl FUN_08049e5c
	ldr r1, _08049C94 @ =0x03003520
	movs r0, #0
	str r0, [r1]
	strb r0, [r4]
	b _08049C9C
	.align 2, 0
_08049C94: .4byte 0x03003520
_08049C98:
	movs r0, #1
	rsbs r0, r0, #0
_08049C9C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049ca4
FUN_08049ca4: @ 0x08049CA4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08049D04 @ =0x00000179
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049CBC
	adds r0, r4, #0
	bl FUN_08049c3c
	movs r0, #0
	strb r0, [r5]
_08049CBC:
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049CD2
	adds r0, r4, #0
	bl FUN_08049c78
	movs r0, #0
	strb r0, [r5]
_08049CD2:
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049D26
	adds r5, r4, #0
	adds r5, #0x18
	adds r0, r5, #0
	bl FUN_08049884
	adds r0, r4, #0
	bl FUN_0804996c
	ldr r1, _08049D08 @ =0x0000017B
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _08049D10
	ldr r0, _08049D0C @ =0x03002CE8
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	b _08049D12
	.align 2, 0
_08049D04: .4byte 0x00000179
_08049D08: .4byte 0x0000017B
_08049D0C: .4byte 0x03002CE8
_08049D10:
	ldr r0, _08049D30 @ =0x03002CE8
_08049D12:
	str r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_08049890
_08049D26:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08049D30: .4byte 0x03002CE8

	thumb_func_start FUN_08049d34
FUN_08049d34: @ 0x08049D34
	push {lr}
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08049D46
	movs r0, #0
	strb r0, [r1]
_08049D46:
	ldr r0, _08049D58 @ =0x03002CE8
	movs r1, #0
	str r1, [r0]
	ldr r0, _08049D5C @ =0x030000C8
	str r1, [r0]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08049D58: .4byte 0x03002CE8
_08049D5C: .4byte 0x030000C8

	thumb_func_start FUN_08049d60
FUN_08049d60: @ 0x08049D60
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08049DD8 @ =0x030000C8
	str r6, [r0]
	adds r5, r6, #0
	adds r5, #0x18
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r4, #0
	strb r4, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #6
	adds r0, r6, r1
	str r4, [r0]
	adds r1, #0xc
	adds r0, r6, r1
	str r4, [r0]
	subs r1, #4
	adds r0, r6, r1
	str r4, [r0]
	movs r0, #2
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #2
	bl FUN_0804967c
	strb r4, [r5, #0x14]
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08049DDC @ =0x085AB548
	str r0, [r1]
	str r0, [r5, #0x1c]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0804990c
	strb r4, [r5, #0x11]
	movs r0, #1
	strb r0, [r5, #0xa]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
	ldr r0, _08049DE0 @ =0x03002CE8
	str r4, [r0]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08049DD8: .4byte 0x030000C8
_08049DDC: .4byte 0x085AB548
_08049DE0: .4byte 0x03002CE8

	thumb_func_start FUN_08049de4
FUN_08049de4: @ 0x08049DE4
	push {r4, lr}
	ldr r0, _08049E1C @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	bne _08049E2A
	movs r1, #0xcc
	lsls r1, r1, #1
	movs r0, #3
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08049E28
	ldr r1, _08049E20 @ =FUN_08049ca4
	ldr r2, _08049E24 @ =FUN_08049d34
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08049d60
	cmp r0, #0
	bge _08049E28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08049E2A
	.align 2, 0
_08049E1C: .4byte 0x030000C8
_08049E20: .4byte FUN_08049ca4
_08049E24: .4byte FUN_08049d34
_08049E28:
	adds r0, r4, #0
_08049E2A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049e30
FUN_08049e30: @ 0x08049E30
	push {lr}
	adds r2, r0, #0
	ldr r0, _08049E50 @ =0x030000C8
	ldr r1, [r0]
	cmp r1, #0
	beq _08049E54
	movs r3, #0xca
	lsls r3, r3, #1
	adds r0, r1, r3
	str r2, [r0]
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0804990c
	movs r0, #0
	b _08049E58
	.align 2, 0
_08049E50: .4byte 0x030000C8
_08049E54:
	movs r0, #1
	rsbs r0, r0, #0
_08049E58:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049e5c
FUN_08049e5c: @ 0x08049E5C
	push {lr}
	ldr r0, _08049E68 @ =0x085AB548
	bl FUN_08049e30
	pop {r1}
	bx r1
	.align 2, 0
_08049E68: .4byte 0x085AB548

	thumb_func_start FUN_08049e6c
FUN_08049e6c: @ 0x08049E6C
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08049E88 @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049E8C
	adds r0, #0x18
	adds r1, r3, #0
	bl FUN_080496c0
	movs r0, #0
	b _08049E90
	.align 2, 0
_08049E88: .4byte 0x030000C8
_08049E8C:
	movs r0, #1
	rsbs r0, r0, #0
_08049E90:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049e94
FUN_08049e94: @ 0x08049E94
	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08049e6c
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049eb0
FUN_08049eb0: @ 0x08049EB0
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08049EC4 @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	bne _08049EC8
	movs r0, #1
	rsbs r0, r0, #0
	b _08049ED0
	.align 2, 0
_08049EC4: .4byte 0x030000C8
_08049EC8:
	adds r0, #0x18
	adds r1, r3, #0
	bl FUN_080496cc
_08049ED0:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049ed4
FUN_08049ed4: @ 0x08049ED4
	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl FUN_0823d340
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08049eb0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049ef0
FUN_08049ef0: @ 0x08049EF0
	push {r4, lr}
	bl Script_GetValue
	adds r4, r0, #0
	bl FUN_0823d34c
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08049eb0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08049f0c
FUN_08049f0c: @ 0x08049F0C
	push {r4, lr}
	ldr r0, _08049F2C @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049F52
	adds r4, r0, #0
	adds r4, #0x18
	movs r0, #0
	strb r0, [r4, #0xd]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08049F52
	b _08049F46
	.align 2, 0
_08049F2C: .4byte 0x030000C8
_08049F30:
	bl Script_GetValue
	ldrb r2, [r4, #0xd]
	lsls r2, r2, #2
	adds r1, r4, #0
	adds r1, #0xc4
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_08049F46:
	bl VM_GetPC
	cmp r0, #0
	bne _08049F30
	movs r0, #0
	b _08049F56
_08049F52:
	movs r0, #1
	rsbs r0, r0, #0
_08049F56:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08049f5c
FUN_08049f5c: @ 0x08049F5C
	push {lr}
	ldr r0, _08049F74 @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049F7C
	ldr r2, _08049F78 @ =0x00000179
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _08049F80
	.align 2, 0
_08049F74: .4byte 0x030000C8
_08049F78: .4byte 0x00000179
_08049F7C:
	movs r0, #1
	rsbs r0, r0, #0
_08049F80:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049f84
FUN_08049f84: @ 0x08049F84
	push {lr}
	ldr r0, _08049F9C @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049FA0
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _08049FA4
	.align 2, 0
_08049F9C: .4byte 0x030000C8
_08049FA0:
	movs r0, #1
	rsbs r0, r0, #0
_08049FA4:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049fa8
FUN_08049fa8: @ 0x08049FA8
	push {lr}
	ldr r0, _08049FBC @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049FC0
	bl FUN_08049c78
	movs r0, #0
	b _08049FC4
	.align 2, 0
_08049FBC: .4byte 0x030000C8
_08049FC0:
	movs r0, #1
	rsbs r0, r0, #0
_08049FC4:
	pop {r1}
	bx r1

	thumb_func_start FUN_08049fc8
FUN_08049fc8: @ 0x08049FC8
	ldr r1, _08049FD0 @ =0x030000CC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08049FD0: .4byte 0x030000CC

	thumb_func_start FUN_08049fd4
FUN_08049fd4: @ 0x08049FD4
	push {lr}
	ldr r0, _08049FE4 @ =0x030000CC
	ldr r0, [r0]
	cmp r0, #0
	beq _08049FE0
	movs r0, #1
_08049FE0:
	pop {r1}
	bx r1
	.align 2, 0
_08049FE4: .4byte 0x030000CC

	thumb_func_start FUN_08049fe8
FUN_08049fe8: @ 0x08049FE8
	push {r4, lr}
	adds r4, r1, #0
	ldr r0, [r0, #0x10]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a000
FUN_0804a000: @ 0x0804A000
	push {r4, lr}
	ldr r2, [r0, #0x1c]
	cmp r2, #0
	beq _0804A020
	movs r4, #0xe0
	lsls r4, r4, #1
_0804A00C:
	adds r0, r2, r4
	ldr r3, [r0]
	ldr r0, [r2]
	cmp r0, r1
	bne _0804A01A
	adds r0, r2, #0
	b _0804A022
_0804A01A:
	adds r2, r3, #0
	cmp r2, #0
	bne _0804A00C
_0804A020:
	movs r0, #0
_0804A022:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a028
FUN_0804a028: @ 0x0804A028
	push {lr}
	adds r1, r0, #0
	ldr r0, _0804A03C @ =0x030000CC
	ldr r0, [r0]
	cmp r0, #0
	beq _0804A040
	bl FUN_0804a000
	b _0804A042
	.align 2, 0
_0804A03C: .4byte 0x030000CC
_0804A040:
	movs r0, #0
_0804A042:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a048
FUN_0804a048: @ 0x0804A048
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_0804A04E:
	ldr r1, [r4, #0x18]
	adds r1, #1
	str r1, [r4, #0x18]
	ldr r0, _0804A070 @ =0x000F423F
	cmp r1, r0
	ble _0804A05E
	movs r0, #1
	str r0, [r4, #0x18]
_0804A05E:
	ldr r1, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_0804a000
	cmp r0, #0
	bne _0804A074
	ldr r0, [r4, #0x18]
	b _0804A07E
	.align 2, 0
_0804A070: .4byte 0x000F423F
_0804A074:
	adds r5, #1
	cmp r5, #3
	ble _0804A04E
	movs r0, #1
	rsbs r0, r0, #0
_0804A07E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a084
FUN_0804a084: @ 0x0804A084
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	mov sb, r1
	mov sl, r2
	str r3, [sp, #4]
	ldr r0, _0804A0D0 @ =0x030000CC
	ldr r5, [r0]
	cmp r5, #0
	beq _0804A0CA
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r4, #0
	bl Malloc
	adds r7, r0, #0
	cmp r7, #0
	beq _0804A0CA
	adds r0, r7, #0
	adds r1, r4, #0
	bl ClearMemory
	adds r0, r5, #0
	bl FUN_0804a048
	str r0, [r7]
	cmp r0, #0
	bge _0804A0D4
	adds r0, r7, #0
	bl Free
_0804A0CA:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A152
	.align 2, 0
_0804A0D0: .4byte 0x030000CC
_0804A0D4:
	movs r6, #0
	mov r0, r8
	strb r0, [r7, #4]
	mov r1, sb
	strb r1, [r7, #5]
	mov r0, sl
	strb r0, [r7, #6]
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r7, #7]
	movs r0, #0
	mov sb, r0
	strh r6, [r7, #8]
	strh r6, [r7, #0xa]
	ldr r0, _0804A164 @ =0x0000FFFF
	strh r0, [r7, #0xc]
	str r6, [r7, #0x10]
	strh r6, [r7, #0x14]
	movs r1, #1
	mov r8, r1
	movs r0, #1
	strh r0, [r7, #0x16]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	str r6, [r0]
	adds r1, #4
	adds r0, r7, r1
	str r6, [r0]
	ldr r0, _0804A168 @ =FUN_0804a4a0
	str r0, [r7, #0x58]
	adds r4, r7, #0
	adds r4, #0x5c
	ldrb r1, [r7, #4]
	ldrb r2, [r7, #5]
	ldrb r3, [r7, #6]
	ldrb r0, [r7, #7]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_0804967c
	mov r0, sb
	strb r0, [r4, #0xf]
	mov r1, r8
	strb r1, [r4, #0xb]
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq _0804A13C
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r0, r1
	str r7, [r0]
_0804A13C:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	str r6, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r5, #0x1c]
	str r0, [r1]
	str r7, [r5, #0x1c]
	ldr r0, [r7]
_0804A152:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804A164: .4byte 0x0000FFFF
_0804A168: .4byte FUN_0804a4a0

	thumb_func_start FUN_0804a16c
FUN_0804a16c: @ 0x0804A16C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0804A18C @ =0x030000CC
	ldr r5, [r0]
	cmp r5, #0
	beq _0804A186
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0804a000
	adds r4, r0, #0
	cmp r4, #0
	bne _0804A190
_0804A186:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A1EA
	.align 2, 0
_0804A18C: .4byte 0x030000CC
_0804A190:
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl FUN_0822ea60
	ldr r0, _0804A1BC @ =FUN_0804a4a0
	str r0, [r4, #0x58]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r3, r0, #0
	cmp r2, #0
	beq _0804A1C0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r1, r4, r0
	ldr r0, [r1]
	str r0, [r2]
	b _0804A1CA
	.align 2, 0
_0804A1BC: .4byte FUN_0804a4a0
_0804A1C0:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	str r0, [r5, #0x1c]
_0804A1CA:
	adds r2, r1, #0
	ldr r1, [r2]
	cmp r1, #0
	beq _0804A1DC
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r3]
	str r0, [r1]
_0804A1DC:
	movs r0, #0
	str r0, [r3]
	str r0, [r2]
	adds r0, r4, #0
	bl Free
	adds r0, r6, #0
_0804A1EA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a1f0
FUN_0804a1f0: @ 0x0804A1F0
	push {lr}
	bl FUN_0804a028
	adds r1, r0, #0
	cmp r1, #0
	beq _0804A208
	ldr r0, _0804A204 @ =FUN_0804a4a8
	str r0, [r1, #0x58]
	movs r0, #0
	b _0804A20C
	.align 2, 0
_0804A204: .4byte FUN_0804a4a8
_0804A208:
	movs r0, #1
	rsbs r0, r0, #0
_0804A20C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a210
FUN_0804a210: @ 0x0804A210
	push {r4, lr}
	bl FUN_0804a028
	adds r4, r0, #0
	cmp r4, #0
	beq _0804A234
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl FUN_0822ea60
	ldr r0, _0804A230 @ =FUN_0804a4a0
	str r0, [r4, #0x58]
	movs r0, #0
	b _0804A238
	.align 2, 0
_0804A230: .4byte FUN_0804a4a0
_0804A234:
	movs r0, #1
	rsbs r0, r0, #0
_0804A238:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a240
FUN_0804a240: @ 0x0804A240
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	bl FUN_0804a028
	adds r5, r0, #0
	cmp r5, #0
	beq _0804A272
	adds r4, r5, #0
	adds r4, #0x5c
	str r6, [r5, #0x10]
	ldrh r1, [r5, #0xa]
	bl FUN_08049fe8
	str r0, [r4, #0x1c]
	movs r1, #0
	strh r1, [r5, #0xa]
	strh r1, [r5, #0x14]
	movs r0, #1
	strh r0, [r5, #0x16]
	strh r1, [r5, #0xc]
	adds r0, r4, #0
	bl FUN_08049640
	movs r0, #0
	b _0804A276
_0804A272:
	movs r0, #1
	rsbs r0, r0, #0
_0804A276:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a27c
FUN_0804a27c: @ 0x0804A27C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl FUN_0804a028
	adds r5, r0, #0
	cmp r5, #0
	bne _0804A298
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A2EE
_0804A298:
	adds r4, r5, #0
	adds r4, #0x5c
	str r6, [r5, #0x10]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08049fe8
	str r0, [r4, #0x1c]
	mov r0, r8
	strh r0, [r5, #0x14]
	strh r7, [r5, #0x16]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	adds r6, r4, #0
	cmp r0, #0x20
	bls _0804A2BC
	movs r0, #0x20
	strh r0, [r5, #0x16]
_0804A2BC:
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0x18
	ldrh r0, [r5, #0x16]
	cmp r3, r0
	bge _0804A2DC
	ldr r2, [sp, #0x18]
	adds r1, r4, #0
_0804A2CC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	ldrh r0, [r5, #0x16]
	cmp r3, r0
	blt _0804A2CC
_0804A2DC:
	ldrh r0, [r5, #0x14]
	lsls r0, r0, #1
	adds r0, r4, r0
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	adds r0, r6, #0
	bl FUN_08049640
	movs r0, #0
_0804A2EE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a2f8
FUN_0804a2f8: @ 0x0804A2F8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r1, #0
	bl FUN_0804a028
	adds r4, r0, #0
	cmp r4, #0
	bne _0804A30E
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A350
_0804A30E:
	adds r5, r4, #0
	adds r5, #0x5c
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0804A34E
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	bl FUN_0822ea60
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	ldrb r3, [r4, #6]
	ldrb r0, [r4, #7]
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_08049650
	strh r6, [r4, #0xa]
	ldrh r1, [r4, #0xa]
	adds r0, r4, #0
	bl FUN_08049fe8
	str r0, [r5, #0x1c]
	ldr r0, _0804A358 @ =FUN_0804a4a8
	str r0, [r4, #0x58]
	adds r0, r5, #0
	bl FUN_08049640
	ldr r0, _0804A35C @ =0x0000FFFF
	strh r0, [r4, #0xc]
_0804A34E:
	movs r0, #0
_0804A350:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0804A358: .4byte FUN_0804a4a8
_0804A35C: .4byte 0x0000FFFF

	thumb_func_start FUN_0804a360
FUN_0804a360: @ 0x0804A360
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0804a028
	adds r3, r0, #0
	cmp r3, #0
	beq _0804A382
	adds r0, #0x5c
	movs r1, #0
	str r1, [r3, #0x10]
	movs r2, #0
	strh r1, [r3, #0xc]
	str r4, [r0, #0x1c]
	strb r2, [r0, #8]
	strb r2, [r0, #7]
	movs r0, #0
	b _0804A386
_0804A382:
	movs r0, #1
	rsbs r0, r0, #0
_0804A386:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a38c
FUN_0804a38c: @ 0x0804A38C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl FUN_0804a028
	adds r5, r0, #0
	cmp r5, #0
	bne _0804A3AA
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A3D6
_0804A3AA:
	adds r4, r5, #0
	adds r4, #0x5c
	ldrb r0, [r5, #4]
	ldrb r1, [r5, #5]
	ldrb r2, [r5, #6]
	ldrb r3, [r5, #7]
	bl FUN_0822ea60
	strb r6, [r5, #4]
	strb r7, [r5, #5]
	mov r0, r8
	strb r0, [r5, #6]
	ldr r0, [sp, #0x1c]
	strb r0, [r5, #7]
	ldrb r1, [r5, #4]
	ldrb r2, [r5, #5]
	ldrb r3, [r5, #6]
	ldrb r0, [r5, #7]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08049650
_0804A3D6:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a3e4
FUN_0804a3e4: @ 0x0804A3E4
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	bl FUN_0804a028
	cmp r0, #0
	beq _0804A400
	adds r0, #0x5c
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080496c0
	movs r0, #0
	b _0804A404
_0804A400:
	movs r0, #1
	rsbs r0, r0, #0
_0804A404:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a40c
FUN_0804a40c: @ 0x0804A40C
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	bl FUN_0804a028
	cmp r0, #0
	bne _0804A420
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A42A
_0804A420:
	adds r0, #0x5c
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080496cc
_0804A42A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a430
FUN_0804a430: @ 0x0804A430
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0804a028
	cmp r0, #0
	beq _0804A454
	adds r1, r0, #0
	adds r1, #0x5c
	ldrb r0, [r1, #2]
	str r0, [r4]
	ldrb r0, [r1, #3]
	str r0, [r4, #4]
	ldrb r0, [r1, #4]
	str r0, [r4, #8]
	ldrb r0, [r1, #5]
	str r0, [r4, #0xc]
	movs r0, #0
	b _0804A458
_0804A454:
	movs r0, #1
	rsbs r0, r0, #0
_0804A458:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804a460
FUN_0804a460: @ 0x0804A460
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0804a028
	cmp r0, #0
	beq _0804A476
	adds r0, #0x5c
	adds r1, r4, #0
	bl FUN_08049708
	b _0804A47A
_0804A476:
	movs r0, #1
	rsbs r0, r0, #0
_0804A47A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a480
FUN_0804a480: @ 0x0804A480
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_0804a028
	cmp r0, #0
	beq _0804A496
	adds r0, #0x5c
	adds r1, r4, #0
	bl FUN_08049784
	b _0804A49A
_0804A496:
	movs r0, #1
	rsbs r0, r0, #0
_0804A49A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a4a0
FUN_0804a4a0: @ 0x0804A4A0
	adds r1, #0x5c
	movs r0, #0
	strb r0, [r1, #0xf]
	bx lr

	thumb_func_start FUN_0804a4a8
FUN_0804a4a8: @ 0x0804A4A8
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x5c
	movs r6, #0
	b _0804A4BA
_0804A4B4:
	adds r6, #1
	cmp r6, #0
	bgt _0804A4E0
_0804A4BA:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0804A4B4
	movs r0, #0
	strb r0, [r4, #8]
	adds r0, r4, #0
	bl FUN_08049568
	cmp r0, #0
	beq _0804A4B4
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _0804A4DC
	ldr r0, _0804A4D8 @ =FUN_0804a4a0
	b _0804A4DE
	.align 2, 0
_0804A4D8: .4byte FUN_0804a4a0
_0804A4DC:
	ldr r0, _0804A4E8 @ =FUN_0804a4ec
_0804A4DE:
	str r0, [r5, #0x58]
_0804A4E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804A4E8: .4byte FUN_0804a4ec

	thumb_func_start FUN_0804a4ec
FUN_0804a4ec: @ 0x0804A4EC
	bx lr
	.align 2, 0

	thumb_func_start FUN_0804a4f0
FUN_0804a4f0: @ 0x0804A4F0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r4, [r7, #0x1c]
	cmp r4, #0
	beq _0804A538
_0804A4FA:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	adds r5, r4, #0
	adds r5, #0x5c
	adds r0, r5, #0
	bl FUN_08049884
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	cmp r0, #0
	blt _0804A51E
	ldr r0, [r4]
	movs r2, #0xc
	ldrsh r1, [r4, r2]
	bl FUN_0804a2f8
_0804A51E:
	ldr r2, [r4, #0x58]
	cmp r2, #0
	beq _0804A52C
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_0804A52C:
	adds r0, r5, #0
	bl FUN_08049890
	adds r4, r6, #0
	cmp r4, #0
	bne _0804A4FA
_0804A538:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a540
FUN_0804a540: @ 0x0804A540
	push {r4, lr}
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq _0804A55C
_0804A548:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r4, [r0]
	ldr r0, [r1]
	bl FUN_0804a16c
	adds r1, r4, #0
	cmp r1, #0
	bne _0804A548
_0804A55C:
	ldr r1, _0804A568 @ =0x030000CC
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A568: .4byte 0x030000CC

	thumb_func_start FUN_0804a56c
FUN_0804a56c: @ 0x0804A56C
	ldr r1, _0804A57C @ =0x030000CC
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x18]
	str r1, [r0, #0x1c]
	movs r0, #0
	bx lr
	.align 2, 0
_0804A57C: .4byte 0x030000CC

	thumb_func_start FUN_0804a580
FUN_0804a580: @ 0x0804A580
	push {r4, lr}
	ldr r0, _0804A5B4 @ =0x030000CC
	ldr r4, [r0]
	cmp r4, #0
	bne _0804A5C0
	movs r0, #0xc
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804A5C0
	ldr r1, _0804A5B8 @ =FUN_0804a4f0
	ldr r2, _0804A5BC @ =FUN_0804a540
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0804a56c
	cmp r0, #0
	bge _0804A5C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804A5C2
	.align 2, 0
_0804A5B4: .4byte 0x030000CC
_0804A5B8: .4byte FUN_0804a4f0
_0804A5BC: .4byte FUN_0804a540
_0804A5C0:
	adds r0, r4, #0
_0804A5C2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a5c8
FUN_0804a5c8: @ 0x0804A5C8
	push {r4, lr}
	ldr r0, _0804A5F4 @ =0x030000CC
	ldr r0, [r0]
	cmp r0, #0
	beq _0804A5EC
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq _0804A5EC
_0804A5D8:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r4, [r0]
	ldr r0, [r1]
	bl FUN_0804a16c
	adds r1, r4, #0
	cmp r1, #0
	bne _0804A5D8
_0804A5EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A5F4: .4byte 0x030000CC

	thumb_func_start FUN_0804a5f8
FUN_0804a5f8: @ 0x0804A5F8
	ldr r1, _0804A600 @ =gCredits
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0804A600: .4byte gCredits

	thumb_func_start FUN_0804a604
FUN_0804a604: @ 0x0804A604
	push {r4, r5, lr}
	adds r3, r0, #0
	ldrb r4, [r3, #0x1a]
	lsls r4, r4, #1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r3, r1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r3, r2
	adds r1, r1, r4
	ldrh r1, [r1]
	movs r5, #0xad
	lsls r5, r5, #2
	adds r2, r3, r5
	adds r2, r2, r4
	ldrh r2, [r2]
	adds r5, #0x80
	adds r3, r3, r5
	adds r3, r3, r4
	ldrh r3, [r3]
	bl FUN_08047b8c
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804a63c
FUN_0804a63c: @ 0x0804A63C
	movs r2, #0
	strb r1, [r0, #0x18]
	movs r1, #1
	strb r1, [r0, #0x19]
	str r2, [r0, #0x20]
	bx lr

	thumb_func_start FUN_0804a648
FUN_0804a648: @ 0x0804A648
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x19]
	cmp r0, #0
	bne _0804A656
	movs r0, #0
	b _0804A65C
_0804A656:
	movs r0, #0
	strb r0, [r1, #0x19]
	movs r0, #1
_0804A65C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804a660
FUN_0804a660: @ 0x0804A660
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804a648
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804A680
	movs r0, #0
	bl FUN_0822b644
	adds r0, r4, #0
	bl FUN_0804a604
	ldrb r0, [r4, #0x1a]
	bl FUN_08047a28
_0804A680:
	ldrb r1, [r4, #0x1a]
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0xb4
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, [r4, #0x20]
	cmp r0, r1
	blo _0804A6A8
	ldr r1, _0804A6A4 @ =0x03004040
	movs r0, #0x40
	str r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0804a63c
	b _0804A6B2
	.align 2, 0
_0804A6A4: .4byte 0x03004040
_0804A6A8:
	lsls r0, r0, #6
	bl Div
	ldr r1, _0804A6B8 @ =0x03004040
	str r0, [r1]
_0804A6B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A6B8: .4byte 0x03004040

	thumb_func_start FUN_0804a6bc
FUN_0804a6bc: @ 0x0804A6BC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804a648
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804A6D0
	ldr r1, _0804A6F4 @ =0x03004040
	movs r0, #0x40
	str r0, [r1]
_0804A6D0:
	ldrb r1, [r4, #0x1a]
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x20]
	cmp r0, r1
	blo _0804A6EC
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0804a63c
_0804A6EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A6F4: .4byte 0x03004040

	thumb_func_start FUN_0804a6f8
FUN_0804a6f8: @ 0x0804A6F8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804a648
	ldrb r1, [r4, #0x1a]
	lsls r1, r1, #1
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, [r4, #0x20]
	cmp r0, r1
	blo _0804A75E
	ldr r1, _0804A74C @ =0x03004040
	movs r0, #0
	str r0, [r1]
	ldrb r0, [r4, #0x1a]
	ldrb r1, [r4, #0x1b]
	cmp r0, r1
	bne _0804A750
	bl FUN_08047864
	adds r0, r4, #0
	movs r1, #4
	bl FUN_0804a63c
	ldrh r0, [r4, #0x30]
	cmp r0, #0
	beq _0804A73A
	movs r1, #0
	bl Script_ExecById
_0804A73A:
	ldrh r1, [r4, #0x24]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804A76C
	adds r0, r4, #0
	bl KillEntity
	b _0804A76C
	.align 2, 0
_0804A74C: .4byte 0x03004040
_0804A750:
	adds r0, #1
	strb r0, [r4, #0x1a]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0804a63c
	b _0804A76C
_0804A75E:
	ldr r4, _0804A774 @ =0x03004040
	lsls r0, r0, #6
	bl Div
	movs r1, #0x40
	subs r1, r1, r0
	str r1, [r4]
_0804A76C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A774: .4byte 0x03004040

	thumb_func_start FUN_0804a778
FUN_0804a778: @ 0x0804A778
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0804a648
	ldrh r0, [r5, #0x32]
	cmp r0, #0
	beq _0804A7B8
	ldr r0, [r5, #0x20]
	cmp r0, #0xf
	bls _0804A7A8
	ldr r0, _0804A7A4 @ =0x03004040
	movs r4, #0
	str r4, [r0]
	ldrh r0, [r5, #0x32]
	movs r1, #0
	bl Script_ExecById
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	bl KillEntity
	b _0804A7B8
	.align 2, 0
_0804A7A4: .4byte 0x03004040
_0804A7A8:
	ldr r4, _0804A7C0 @ =0x03004040
	lsls r0, r0, #6
	movs r1, #0x10
	bl Div
	movs r1, #0x40
	subs r1, r1, r0
	str r1, [r4]
_0804A7B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804A7C0: .4byte 0x03004040

	thumb_func_start Credits_Update
Credits_Update: @ 0x0804A7C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0804A810 @ =0x085AB550
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804A7DC
	adds r0, r4, #0
	bl _call_via_r1
_0804A7DC:
	ldr r1, _0804A814 @ =0x03004250
	ldr r0, _0804A818 @ =0x00001084
	strh r0, [r1]
	ldr r0, _0804A81C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0804A802
	ldrh r0, [r4, #0x32]
	cmp r0, #0
	beq _0804A802
	ldrb r0, [r4, #0x18]
	cmp r0, #2
	bhi _0804A802
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804a63c
_0804A802:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A810: .4byte 0x085AB550
_0804A814: .4byte 0x03004250
_0804A818: .4byte 0x00001084
_0804A81C: .4byte 0x030044E0

	thumb_func_start Credits_Destroy
Credits_Destroy: @ 0x0804A820
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0804A848 @ =gCredits
	movs r0, #0
	str r0, [r1]
	bl FUN_08047864
	ldrh r1, [r4, #0x24]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804A83E
	ldr r1, _0804A84C @ =0x03003E78
	ldrh r0, [r4, #0x26]
	strh r0, [r1]
_0804A83E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A848: .4byte gCredits
_0804A84C: .4byte 0x03003E78

	thumb_func_start FUN_0804a850
FUN_0804a850: @ 0x0804A850
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r4, #0
	strb r4, [r5, #0x18]
	strb r4, [r5, #0x19]
	str r4, [r5, #0x20]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0x1a]
	str r4, [r5, #0x1c]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804A882
	bl FUN_0823d340
	str r0, [r5, #0x28]
	cmp r0, #0
	bne _0804A88E
_0804A882:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A978
_0804A888:
	subs r0, r7, #1
	strb r0, [r5, #0x1b]
	b _0804A924
_0804A88E:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804A924
	bl FUN_0823d34c
	str r0, [r5, #0x2c]
	bl VM_SetPC
	movs r7, #0
	movs r0, #1
	rsbs r0, r0, #0
	mov sb, r0
	adds r6, r5, #0
	adds r6, #0x34
	movs r1, #0xb4
	adds r1, r1, r5
	mov r8, r1
_0804A8B4:
	bl Script_GetValue
	lsls r4, r7, #1
	strh r0, [r6]
	bl Script_GetValue
	movs r2, #0xda
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xad
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xcd
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl Script_GetValue
	mov r1, r8
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	ldrb r0, [r5, #0x1a]
	cmp r7, r0
	blt _0804A918
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, sb
	beq _0804A888
_0804A918:
	adds r6, #2
	movs r2, #2
	add r8, r2
	adds r7, #1
	cmp r7, #0x3f
	ble _0804A8B4
_0804A924:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r5, #0x30]
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x32]
	ldr r0, [r5, #0x28]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _0804A984 @ =0x0000539C
	bl FUN_08047dc0
	ldrb r0, [r5, #0x1a]
	bl FUN_08047a28
	adds r0, r5, #0
	bl FUN_0804a604
	ldr r1, _0804A988 @ =0x03004494
	ldr r2, _0804A98C @ =0x00001084
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _0804A990 @ =0x03004454
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0804A994 @ =0x03004040
	str r4, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0804a63c
	movs r0, #0
_0804A978:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804A984: .4byte 0x0000539C
_0804A988: .4byte 0x03004494
_0804A98C: .4byte 0x00001084
_0804A990: .4byte 0x03004454
_0804A994: .4byte 0x03004040

	thumb_func_start Credits_Init
Credits_Init: @ 0x0804A998
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804A9D0 @ =gCredits
	str r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r4, #0x24]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0804A9C4
	ldr r2, _0804A9D4 @ =0x03003E78
	ldrh r1, [r2]
	strh r1, [r4, #0x26]
	ldr r0, _0804A9D8 @ =0xFFFFF1FF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	strh r0, [r2]
_0804A9C4:
	adds r0, r4, #0
	bl FUN_0804a850
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804A9D0: .4byte gCredits
_0804A9D4: .4byte 0x03003E78
_0804A9D8: .4byte 0xFFFFF1FF

	thumb_func_start Credits_Create
Credits_Create: @ 0x0804A9DC
	push {r4, lr}
	ldr r4, _0804A9F0 @ =gCredits
	ldr r0, [r4]
	cmp r0, #0
	beq _0804A9F4
	bl FUN_0804a850
	ldr r0, [r4]
	b _0804AA2A
	.align 2, 0
_0804A9F0: .4byte gCredits
_0804A9F4:
	movs r1, #0xed
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804AA28
	ldr r1, _0804AA20 @ =Credits_Update
	ldr r2, _0804AA24 @ =Credits_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Credits_Init
	cmp r0, #0
	bge _0804AA28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804AA2A
	.align 2, 0
_0804AA20: .4byte Credits_Update
_0804AA24: .4byte Credits_Destroy
_0804AA28:
	adds r0, r4, #0
_0804AA2A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804aa30
FUN_0804aa30: @ 0x0804AA30
	push {r4, lr}
	sub sp, #0x10
	str r1, [sp, #0xc]
	ldr r0, _0804AA84 @ =0x0000C091
	ldr r1, _0804AA88 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804AA8C @ =0x000092B3
	ldr r1, _0804AA90 @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804AA94 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	movs r0, #0
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804AA84: .4byte 0x0000C091
_0804AA88: .4byte 0x0000CD91
_0804AA8C: .4byte 0x000092B3
_0804AA90: .4byte 0x000026BB
_0804AA94: .4byte 0x03004250

	thumb_func_start FUN_0804aa98
FUN_0804aa98: @ 0x0804AA98
	push {r4, lr}
	sub sp, #0x10
	str r1, [sp, #0xc]
	ldr r0, _0804AAEC @ =0x0000C091
	ldr r1, _0804AAF0 @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804AAF4 @ =0x000092B3
	ldr r1, _0804AAF8 @ =0x0000EFDA
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _0804AAFC @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
	movs r0, #0
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804AAEC: .4byte 0x0000C091
_0804AAF0: .4byte 0x0000A413
_0804AAF4: .4byte 0x000092B3
_0804AAF8: .4byte 0x0000EFDA
_0804AAFC: .4byte 0x030043F0

	thumb_func_start FUN_0804ab00
FUN_0804ab00: @ 0x0804AB00
	push {r4, r5, lr}
	adds r1, r0, #0
	adds r1, #0x58
	movs r2, #0
	adds r3, r0, #0
	adds r3, #0x2c
	movs r5, #2
	rsbs r5, r5, #0
	movs r4, #1
_0804AB12:
	ldrb r0, [r3]
	cmp r2, r0
	bge _0804AB1E
	ldr r0, [r1, #8]
	ands r0, r5
	b _0804AB22
_0804AB1E:
	ldr r0, [r1, #8]
	orrs r0, r4
_0804AB22:
	str r0, [r1, #8]
	adds r2, #1
	adds r1, #0x60
	cmp r2, #2
	ble _0804AB12
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ab34
FUN_0804ab34: @ 0x0804AB34
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0804AB5C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r4, #1
	movs r2, #1
	ands r2, r1
	cmp r2, #0
	beq _0804AB64
	ldr r1, _0804AB60 @ =0x030000D4
	adds r2, r3, #0
	adds r2, #0x2a
	movs r0, #0
	ldrsb r0, [r2, r0]
	str r0, [r1]
	ldrb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x2f
	movs r2, #0
	b _0804AB76
	.align 2, 0
_0804AB5C: .4byte 0x030044E0
_0804AB60: .4byte 0x030000D4
_0804AB64:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804AB70
	movs r0, #0
	b _0804AB88
_0804AB70:
	adds r1, r3, #0
	adds r1, #0x2f
	movs r0, #3
_0804AB76:
	strb r0, [r1]
	movs r1, #4
	adds r0, r3, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	str r2, [r3, #0x34]
	movs r0, #1
_0804AB88:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804ab90
FUN_0804ab90: @ 0x0804AB90
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _0804ABBC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804ABC0
	adds r4, r7, #0
	adds r4, #0x2a
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	movs r0, #0xdc
	bl PlaySound_082406e0
	adds r6, r4, #0
	b _0804ABD8
	.align 2, 0
_0804ABBC: .4byte 0x030044E0
_0804ABC0:
	movs r0, #0x80
	ands r0, r1
	adds r6, r7, #0
	adds r6, #0x2a
	cmp r0, #0
	beq _0804ABD8
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r0, #0xdc
	bl PlaySound_082406e0
_0804ABD8:
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bge _0804ABEE
	adds r1, r7, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r6]
	mov r8, r1
	b _0804AC02
_0804ABEE:
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r0, r7, #0
	adds r0, #0x2c
	mov r8, r0
	ldrb r0, [r0]
	cmp r1, r0
	blt _0804AC02
	movs r0, #0
	strb r0, [r6]
_0804AC02:
	adds r0, r7, #0
	adds r0, #0x2b
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r1, #0
	ldrsb r1, [r6, r1]
	mov sb, r0
	cmp r2, r1
	beq _0804AC6A
	adds r5, r7, #0
	adds r5, #0x58
	movs r4, #0
	mov r1, r8
	ldrb r1, [r1]
	cmp r4, r1
	bge _0804AC4E
_0804AC22:
	lsls r1, r4, #1
	adds r2, r1, #0
	adds r2, #0x1a
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r4, r0
	beq _0804AC32
	adds r2, #1
_0804AC32:
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #0
	bl Sprite_SetSprite
	adds r4, #1
	adds r5, #0x60
	mov r2, r8
	ldrb r2, [r2]
	cmp r4, r2
	blt _0804AC22
_0804AC4E:
	movs r4, #0
	ldrsb r4, [r6, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
_0804AC6A:
	ldrb r0, [r6]
	mov r2, sb
	strb r0, [r2]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804ac7c
FUN_0804ac7c: @ 0x0804AC7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x29
	ldrb r0, [r7]
	cmp r0, #0
	beq _0804AC96
	movs r0, #0
	strb r0, [r7]
_0804AC96:
	bl FUN_082412f8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0804AD24
	adds r6, r5, #0
	adds r6, #0x58
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x2c
	mov sl, r7
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x2a
	movs r0, #0x28
	adds r0, r0, r5
	mov sb, r0
	mov r1, r8
	ldrb r1, [r1]
	cmp r4, r1
	bge _0804ACEE
_0804ACC2:
	lsls r1, r4, #1
	adds r2, r1, #0
	adds r2, #0x1a
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r4, r0
	beq _0804ACD2
	adds r2, #1
_0804ACD2:
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	adds r1, #0x38
	movs r3, #0
	bl Sprite_SetSprite
	adds r4, #1
	adds r6, #0x60
	mov r2, r8
	ldrb r2, [r2]
	cmp r4, r2
	blt _0804ACC2
_0804ACEE:
	movs r4, #0
	ldrsb r4, [r7, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #3
	beq _0804AD14
	movs r0, #2
_0804AD14:
	movs r1, #0
	mov r2, sb
	strb r0, [r2]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	str r1, [r5, #0x34]
	b _0804AD30
_0804AD24:
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x28
	strb r1, [r0]
	strb r1, [r7]
	str r2, [r5, #0x34]
_0804AD30:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ad40
FUN_0804ad40: @ 0x0804AD40
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AD98
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804aa98
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	adds r2, r0, #0
	str r2, [r5]
	cmp r2, #0
	blt _0804AD90
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl FUN_0804a240
	ldr r0, [r5]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r5]
	bl FUN_0804a1f0
_0804AD90:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804AD98:
	ldr r2, [r4, #0x34]
	cmp r2, #0x1e
	bls _0804ADCC
	ldr r0, _0804ADC8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0804ADCC
	adds r1, r4, #0
	adds r1, #0x2f
	movs r2, #0
	movs r0, #3
	strb r0, [r1]
	movs r1, #4
	adds r0, r4, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x34]
	b _0804ADD0
	.align 2, 0
_0804ADC8: .4byte 0x030044E0
_0804ADCC:
	adds r0, r2, #1
	str r0, [r4, #0x34]
_0804ADD0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804add8
FUN_0804add8: @ 0x0804ADD8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AE2C
	movs r5, #0
	strb r5, [r1]
	adds r1, #3
	movs r0, #2
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0804aa30
	adds r0, r6, #0
	adds r0, #0x2a
	movs r4, #0
	ldrsb r4, [r0, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	bl FUN_08049f5c
	adds r0, r6, #0
	bl FUN_0804ab00
	adds r0, r6, #0
	adds r0, #0x2d
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_0804AE2C:
	ldr r0, [r6, #0x34]
	cmp r0, #0x1e
	bls _0804AE3C
	adds r0, r6, #0
	bl FUN_0804ab34
	cmp r0, #0
	bne _0804AEBA
_0804AE3C:
	adds r0, r6, #0
	bl FUN_0804ab90
	adds r2, r6, #0
	adds r2, #0x2d
	ldrb r3, [r2]
	ldr r0, [r6, #0x30]
	lsls r1, r3, #1
	adds r1, r1, r0
	ldr r0, _0804AE68 @ =0x030044E0
	ldrh r0, [r0, #2]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804AE6C
	adds r0, r3, #1
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x2e
	strb r1, [r0]
	adds r1, r0, #0
	b _0804AE7A
	.align 2, 0
_0804AE68: .4byte 0x030044E0
_0804AE6C:
	adds r1, r6, #0
	adds r1, #0x2e
	cmp r0, #0
	beq _0804AE7A
	movs r0, #0
	strb r0, [r2]
	strb r0, [r1]
_0804AE7A:
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x77
	bls _0804AE8E
	strb r3, [r2]
	strb r3, [r1]
_0804AE8E:
	ldrb r0, [r2]
	cmp r0, #0xf
	bls _0804AEB4
	movs r1, #3
	adds r0, r6, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r3, [r6, #0x34]
	ldr r1, _0804AEC0 @ =0x0000369F
	ldr r0, _0804AEC4 @ =gSystemSaveData
	ldr r0, [r0]
	str r1, [r0, #0x10]
	ldr r0, _0804AEC8 @ =0x00000296
	bl PlaySound_082406e0
_0804AEB4:
	ldr r0, [r6, #0x34]
	adds r0, #1
	str r0, [r6, #0x34]
_0804AEBA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804AEC0: .4byte 0x0000369F
_0804AEC4: .4byte gSystemSaveData
_0804AEC8: .4byte 0x00000296

	thumb_func_start FUN_0804aecc
FUN_0804aecc: @ 0x0804AECC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AF16
	movs r0, #0
	strb r0, [r1]
	adds r1, #3
	movs r0, #3
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0804aa30
	adds r0, r5, #0
	adds r0, #0x2a
	movs r4, #0
	ldrsb r4, [r0, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	bl FUN_08049f5c
	adds r0, r5, #0
	bl FUN_0804ab00
_0804AF16:
	ldr r0, [r5, #0x34]
	cmp r0, #0x1e
	bls _0804AF26
	adds r0, r5, #0
	bl FUN_0804ab34
	cmp r0, #0
	bne _0804AF32
_0804AF26:
	adds r0, r5, #0
	bl FUN_0804ab90
	ldr r0, [r5, #0x34]
	adds r0, #1
	str r0, [r5, #0x34]
_0804AF32:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804af38
FUN_0804af38: @ 0x0804AF38
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804AF8A
	movs r5, #0
	strb r5, [r1]
	movs r0, #4
	str r0, [sp]
	ldr r0, _0804AF7C @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #3
	bne _0804AF84
	ldr r0, _0804AF80 @ =0x0300481C
	str r5, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _0804AF8A
	.align 2, 0
_0804AF7C: .4byte 0x0000FFFF
_0804AF80: .4byte 0x0300481C
_0804AF84:
	movs r0, #0xdd
	bl PlaySound_082406e0
_0804AF8A:
	ldr r0, [r4, #0x34]
	cmp r0, #0x14
	bne _0804AFAA
	adds r0, r4, #0
	adds r0, #0x2f
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #2
	subs r0, #0x17
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804AFAA
	movs r1, #0
	bl Script_ExecById
_0804AFAA:
	ldr r0, [r4, #0x34]
	adds r0, #1
	str r0, [r4, #0x34]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804afb8
FUN_0804afb8: @ 0x0804AFB8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _0804B020 @ =0x085AB584
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r1, [r4]
	adds r1, #1
	movs r7, #0
	strh r1, [r4]
	ldr r2, _0804B024 @ =0x0000FFFF
	adds r6, r2, #0
	ldr r2, _0804B028 @ =0x085AB598
	adds r0, #2
	adds r3, r5, r0
	ldrh r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _0804B018
	strh r7, [r4]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ands r0, r6
	cmp r0, #5
	bls _0804B006
	strh r7, [r3]
_0804B006:
	ldr r1, _0804B02C @ =0x085AB5A4
	ldrh r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0804B018:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804B020: .4byte 0x085AB584
_0804B024: .4byte 0x0000FFFF
_0804B028: .4byte 0x085AB598
_0804B02C: .4byte 0x085AB5A4

	thumb_func_start FUN_0804b030
FUN_0804b030: @ 0x0804B030
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x58
	movs r5, #2
_0804B03A:
	adds r0, r4, #0
	bl FUN_0822f1c0
	subs r5, #1
	adds r4, #0x60
	cmp r5, #0
	bge _0804B03A
	bl FUN_08049f84
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0804a16c
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b060
FUN_0804b060: @ 0x0804B060
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804B086
	bl FUN_0823d340
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	cmp r0, #0
	bne _0804B08C
_0804B086:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804B202
_0804B08C:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804B0AA
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #3
_0804B09C:
	bl Script_GetValue
	stm r4!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _0804B09C
	b _0804B0BC
_0804B0AA:
	adds r1, r6, #0
	adds r1, #0x18
	movs r2, #0
	adds r0, r6, #0
	adds r0, #0x24
_0804B0B4:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0804B0B4
_0804B0BC:
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	ldr r0, _0804B10C @ =0x0000CB05
	ldr r1, _0804B110 @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0804B086
	adds r1, r6, #0
	adds r1, #0x38
	adds r0, r2, #0
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x38
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r0, #0
	str r0, [r6, #0x34]
	ldr r0, _0804B114 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, _0804B118 @ =0x0000369F
	mov sb, r4
	cmp r1, r0
	bne _0804B11C
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #3
	b _0804B122
	.align 2, 0
_0804B10C: .4byte 0x0000CB05
_0804B110: .4byte 0x0000DCC1
_0804B114: .4byte gSystemSaveData
_0804B118: .4byte 0x0000369F
_0804B11C:
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #2
_0804B122:
	strb r0, [r1]
	ldr r0, _0804B138 @ =0x030000D4
	ldr r0, [r0]
	adds r3, r6, #0
	adds r3, #0x2a
	strb r0, [r3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _0804B13C
	movs r0, #0
	b _0804B148
	.align 2, 0
_0804B138: .4byte 0x030000D4
_0804B13C:
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldrb r2, [r1]
	cmp r0, r2
	blt _0804B14A
	subs r0, r2, #1
_0804B148:
	strb r0, [r3]
_0804B14A:
	adds r2, r6, #0
	adds r2, #0x2b
	movs r0, #0xff
	strb r0, [r2]
	cmp r5, #0
	beq _0804B168
	movs r0, #0
	adds r1, r6, #0
	adds r1, #0x28
	strb r0, [r1]
	subs r2, #2
	movs r1, #1
	strb r1, [r2]
	str r0, [r6, #0x34]
	b _0804B18A
_0804B168:
	ldrb r1, [r1]
	cmp r1, #3
	bne _0804B17A
	adds r0, r6, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x29
	b _0804B184
_0804B17A:
	movs r0, #2
	adds r1, r6, #0
	adds r1, #0x28
	strb r0, [r1]
	adds r1, #1
_0804B184:
	movs r0, #1
	strb r0, [r1]
	str r5, [r6, #0x34]
_0804B18A:
	ldr r2, _0804B210 @ =0xFFFF0000
	movs r1, #0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r0, _0804B214 @ =0x085AB564
	str r0, [r6, #0x30]
	adds r2, r6, #0
	adds r2, #0x2f
	movs r0, #3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x2d
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r1, _0804B218 @ =0x03003584
	ldr r1, [r1]
	ldr r2, _0804B21C @ =0x00005260
	adds r1, r1, r2
	movs r2, #0x80
	lsls r2, r2, #1
	bl CopyMemory
	adds r4, r6, #0
	adds r4, #0x58
	movs r3, #0
	mov r8, r3
	movs r7, #0xd8
	lsls r7, r7, #0xd
	movs r5, #2
_0804B1D0:
	lsrs r2, r7, #0x10
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r3, #0x11
	bl FUN_0822f3fc
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	str r0, [r4, #0x48]
	movs r3, #0x80
	lsls r3, r3, #0xa
	adds r7, r7, r3
	subs r5, #1
	adds r4, #0x60
	cmp r5, #0
	bge _0804B1D0
	movs r0, #0
_0804B202:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804B210: .4byte 0xFFFF0000
_0804B214: .4byte 0x085AB564
_0804B218: .4byte 0x03003584
_0804B21C: .4byte 0x00005260

	thumb_func_start FUN_0804b220
FUN_0804b220: @ 0x0804B220
	push {r4, lr}
	movs r1, #0xa1
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804B258
	ldr r1, _0804B250 @ =FUN_0804afb8
	ldr r2, _0804B254 @ =FUN_0804b030
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0804b060
	cmp r0, #0
	bge _0804B258
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804B25A
	.align 2, 0
_0804B250: .4byte FUN_0804afb8
_0804B254: .4byte FUN_0804b030
_0804B258:
	adds r0, r4, #0
_0804B25A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b260
FUN_0804b260: @ 0x0804B260
	push {lr}
	ldr r0, _0804B270 @ =0x030000D8
	ldr r0, [r0]
	cmp r0, #0
	bne _0804B274
	movs r0, #0
	b _0804B276
	.align 2, 0
_0804B270: .4byte 0x030000D8
_0804B274:
	movs r0, #1
_0804B276:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804b27c
FUN_0804b27c: @ 0x0804B27C
	push {r4, lr}
	ldr r0, _0804B2B4 @ =0x030000D8
	ldr r4, [r0]
	cmp r4, #0
	beq _0804B2AC
	adds r1, r4, #0
	adds r1, #0x39
	adds r2, r4, #0
	adds r2, #0x3a
	adds r3, r4, #0
	adds r3, #0x3b
	movs r0, #0
	bl rfu_REQBN_watchLink
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0804B2A8
	ldrb r1, [r4, #0x1a]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0x1a]
_0804B2A8:
	bl rfu_REQ_recvData
_0804B2AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804B2B4: .4byte 0x030000D8

	thumb_func_start FUN_0804b2b8
FUN_0804b2b8: @ 0x0804B2B8
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0804B2D8 @ =0x030000D8
	ldr r2, [r0]
	cmp r2, #0
	beq _0804B2D4
	cmp r1, #0
	beq _0804B2D4
	movs r0, #0xf0
	orrs r1, r0
	ldrb r0, [r2, #0x1a]
	orrs r1, r0
	strb r1, [r2, #0x1a]
_0804B2D4:
	pop {r0}
	bx r0
	.align 2, 0
_0804B2D8: .4byte 0x030000D8

	thumb_func_start FUN_0804b2dc
FUN_0804b2dc: @ 0x0804B2DC
	push {lr}
	bl FUN_0823a6c0
	cmp r0, #0
	blt _0804B33C
	ldr r0, _0804B328 @ =FUN_0804b2b8
	bl rfu_setREQCallback
	bl rfu_REQBN_softReset_and_checkID
	ldr r1, _0804B32C @ =0x00008001
	cmp r0, r1
	bne _0804B33C
	bl rfu_REQ_reset
	bl rfu_waitREQComplete
	movs r0, #0
	movs r1, #4
	movs r2, #0x20
	bl rfu_REQ_configSystem
	bl rfu_waitREQComplete
	ldr r2, _0804B330 @ =0x08251D30
	ldr r3, _0804B334 @ =0x08251D38
	movs r0, #0
	movs r1, #0x10
	bl rfu_REQ_configGameData
	bl rfu_waitREQComplete
	ldr r0, _0804B338 @ =FUN_0804b27c
	bl rfu_setMSCCallback
	movs r0, #0
	b _0804B340
	.align 2, 0
_0804B328: .4byte FUN_0804b2b8
_0804B32C: .4byte 0x00008001
_0804B330: .4byte 0x08251D30
_0804B334: .4byte 0x08251D38
_0804B338: .4byte FUN_0804b27c
_0804B33C:
	movs r0, #1
	rsbs r0, r0, #0
_0804B340:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b344
FUN_0804b344: @ 0x0804B344
	push {lr}
	movs r2, #0
	ldr r3, _0804B354 @ =0x03005800
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	movs r1, #1
	b _0804B368
	.align 2, 0
_0804B354: .4byte 0x03005800
_0804B358:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bhi _0804B36E
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r2
_0804B368:
	ands r0, r1
	cmp r0, #0
	beq _0804B358
_0804B36E:
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r2
	lsrs r0, r0, #0x18
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	bl rfu_clearAllSlot
	movs r0, #0
	bl rfu_setREQCallback
	bl rfu_REQ_stopMode
	bl rfu_waitREQComplete
	pop {r0}
	bx r0

	thumb_func_start FUN_0804b394
FUN_0804b394: @ 0x0804B394
	push {r4, lr}
	sub sp, #0x10
	str r1, [sp, #0xc]
	ldr r0, _0804B3E4 @ =0x0000C091
	ldr r1, _0804B3E8 @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804B3EC @ =0x000092B3
	ldr r1, _0804B3F0 @ =0x0000EFDA
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804B3F4 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804B3E4: .4byte 0x0000C091
_0804B3E8: .4byte 0x0000A413
_0804B3EC: .4byte 0x000092B3
_0804B3F0: .4byte 0x0000EFDA
_0804B3F4: .4byte 0x03004250

	thumb_func_start FUN_0804b3f8
FUN_0804b3f8: @ 0x0804B3F8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #3
	bl FUN_0804b394
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	str r0, [r4, #0x30]
	adds r0, r4, #0
	bl FUN_0804b2dc
	cmp r0, #0
	blt _0804B448
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #0x18]
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B43E
	ldr r1, [r4, #0x28]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #2
	bl FUN_0804a2f8
	ldr r0, [r4, #0x30]
	bl FUN_0804a1f0
_0804B43E:
	bl rfu_REQ_startSearchParent
	bl rfu_waitREQComplete
	b _0804B46C
_0804B448:
	movs r1, #0
	strb r1, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B46C
	ldr r1, [r4, #0x28]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r4, #0x30]
	bl FUN_0804a1f0
_0804B46C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b474
FUN_0804b474: @ 0x0804B474
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B48A
	movs r0, #0
	strb r0, [r4, #0x19]
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B48A:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B4B4
	ldr r0, _0804B4B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B4B4
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B4B8
	.align 2, 0
_0804B4B0: .4byte 0x030044E0
_0804B4B4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B4B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b4c0
FUN_0804b4c0: @ 0x0804B4C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r6, _0804B4EC @ =0x085AB5B0
_0804B4C8:
	movs r3, #0
	movs r2, #0
	lsls r0, r4, #1
	adds r1, r0, r6
_0804B4D0:
	adds r0, r5, r2
	ldrb r0, [r0]
	ldrb r7, [r1]
	cmp r0, r7
	bne _0804B4DC
	adds r3, #1
_0804B4DC:
	adds r1, #1
	adds r2, #1
	cmp r2, #1
	ble _0804B4D0
	cmp r3, #2
	bne _0804B4F0
	adds r0, r4, #0
	b _0804B4FA
	.align 2, 0
_0804B4EC: .4byte 0x085AB5B0
_0804B4F0:
	adds r4, #1
	cmp r4, #3
	ble _0804B4C8
	movs r0, #1
	rsbs r0, r0, #0
_0804B4FA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b500
FUN_0804b500: @ 0x0804B500
	push {r4, r5, lr}
	lsls r2, r0, #1
	ldr r0, _0804B528 @ =0x085AB5B0
	ldr r5, _0804B52C @ =gSystemSaveData
	adds r3, r2, r0
	movs r4, #1
_0804B50C:
	ldrb r1, [r3]
	ldr r0, [r5]
	adds r0, #0x18
	adds r0, r0, r2
	strb r1, [r0]
	adds r3, #1
	subs r4, #1
	adds r2, #1
	cmp r4, #0
	bge _0804B50C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804B528: .4byte 0x085AB5B0
_0804B52C: .4byte gSystemSaveData

	thumb_func_start FUN_0804b530
FUN_0804b530: @ 0x0804B530
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x19]
	cmp r0, #0
	beq _0804B540
	movs r0, #0
	strb r0, [r5, #0x19]
	strb r0, [r5, #0x1b]
_0804B540:
	bl rfu_REQ_pollSearchParent
	bl rfu_waitREQComplete
	adds r4, r5, #0
	adds r4, #0x3c
	adds r2, r5, #0
	adds r2, #0x44
	movs r0, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl FUN_0824beb8
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	blt _0804B58C
	adds r0, r4, #0
	bl FUN_0804b4c0
	adds r1, r0, #0
	cmp r1, #0
	blt _0804B588
	adds r0, r5, #0
	adds r0, #0x20
	movs r4, #0
	strb r1, [r0]
	adds r0, r1, #0
	bl FUN_0804b500
	movs r0, #2
	strb r0, [r5, #0x18]
	movs r0, #1
	strb r0, [r5, #0x19]
	str r4, [r5, #0x24]
	b _0804B5E8
_0804B588:
	movs r0, #3
	b _0804B5D2
_0804B58C:
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0804B598
	movs r0, #1
	strb r0, [r5, #0x1b]
_0804B598:
	ldr r0, _0804B5AC @ =0x00000257
	ldr r2, [r5, #0x24]
	cmp r2, r0
	bls _0804B5B4
	ldrb r1, [r5, #0x1b]
	cmp r1, #0
	beq _0804B5B0
	movs r0, #3
	b _0804B5D2
	.align 2, 0
_0804B5AC: .4byte 0x00000257
_0804B5B0:
	movs r0, #4
	b _0804B5D4
_0804B5B4:
	cmp r2, #9
	bls _0804B5E4
	ldr r0, _0804B5E0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804B5E4
	adds r0, r5, #0
	bl FUN_0804b344
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
_0804B5D2:
	movs r1, #0
_0804B5D4:
	strb r0, [r5, #0x18]
	movs r0, #1
	strb r0, [r5, #0x19]
	str r1, [r5, #0x24]
	b _0804B5E8
	.align 2, 0
_0804B5E0: .4byte 0x030044E0
_0804B5E4:
	adds r0, r2, #1
	str r0, [r5, #0x24]
_0804B5E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b5f0
FUN_0804b5f0: @ 0x0804B5F0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B626
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r2, [r4, #0x30]
	movs r0, #7
_0804B602:
	subs r0, #1
	cmp r0, #0
	bge _0804B602
	cmp r2, #0
	blt _0804B61A
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r1, [r0]
	adds r1, #3
	adds r0, r2, #0
	bl FUN_0804a2f8
_0804B61A:
	ldr r0, _0804B648 @ =0x00000123
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0804b344
_0804B626:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B650
	ldr r0, _0804B64C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B650
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #5
	strb r1, [r4, #0x18]
	movs r1, #1
	strb r1, [r4, #0x19]
	b _0804B652
	.align 2, 0
_0804B648: .4byte 0x00000123
_0804B64C: .4byte 0x030044E0
_0804B650:
	adds r0, r2, #1
_0804B652:
	str r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b65c
FUN_0804b65c: @ 0x0804B65C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B684
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B676
	movs r1, #7
	bl FUN_0804a2f8
_0804B676:
	adds r0, r4, #0
	bl FUN_0804b344
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B684:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B6B0
	ldr r0, _0804B6AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B6B0
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B6B4
	.align 2, 0
_0804B6AC: .4byte 0x030044E0
_0804B6B0:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B6B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b6bc
FUN_0804b6bc: @ 0x0804B6BC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B6E4
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B6D6
	movs r1, #7
	bl FUN_0804a2f8
_0804B6D6:
	adds r0, r4, #0
	bl FUN_0804b344
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B6E4:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B710
	ldr r0, _0804B70C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B710
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B714
	.align 2, 0
_0804B70C: .4byte 0x030044E0
_0804B710:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B714:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b71c
FUN_0804b71c: @ 0x0804B71C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B73E
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B73E
	ldr r1, [r4, #0x2c]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #0xb
	bl FUN_0804a2f8
_0804B73E:
	ldr r0, [r4, #0x24]
	cmp r0, #0x3c
	bne _0804B76A
	bl FUN_082410bc
	movs r2, #0
	strb r0, [r4, #0x1f]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	bne _0804B75E
	movs r0, #6
	strb r0, [r4, #0x18]
	strb r1, [r4, #0x19]
	str r2, [r4, #0x24]
	b _0804B76E
_0804B75E:
	movs r0, #7
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r2, [r4, #0x24]
	b _0804B76E
_0804B76A:
	adds r0, #1
	str r0, [r4, #0x24]
_0804B76E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804b774
FUN_0804b774: @ 0x0804B774
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B79C
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B79C
	ldr r1, [r4, #0x2c]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #0xe
	bl FUN_0804a2f8
	ldr r0, _0804B7BC @ =0x000002AE
	bl PlaySound_082406e0
_0804B79C:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B7C4
	ldr r0, _0804B7C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B7C4
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B7C8
	.align 2, 0
_0804B7BC: .4byte 0x000002AE
_0804B7C0: .4byte 0x030044E0
_0804B7C4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B7C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b7d0
FUN_0804b7d0: @ 0x0804B7D0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B7FA
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B7FA
	ldr r1, [r4, #0x2c]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #0xf
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B7FA:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B830
	ldr r0, _0804B820 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B830
	ldrb r0, [r4, #0x1e]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x1e]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0804B824
	movs r0, #8
	b _0804B826
	.align 2, 0
_0804B820: .4byte 0x030044E0
_0804B824:
	movs r0, #5
_0804B826:
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B834
_0804B830:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B834:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b83c
FUN_0804b83c: @ 0x0804B83C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B84A
	movs r0, #0
	strb r0, [r4, #0x19]
_0804B84A:
	ldr r1, [r4, #0x24]
	cmp r1, #0x14
	bne _0804B864
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _0804B864
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
	b _0804B868
_0804B864:
	adds r0, r1, #1
	str r0, [r4, #0x24]
_0804B868:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b870
FUN_0804b870: @ 0x0804B870
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804B89A
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B892
	ldr r1, [r4, #0x28]
	bl FUN_0804a240
	ldr r0, [r4, #0x30]
	movs r1, #0
	bl FUN_0804a2f8
_0804B892:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804B89A:
	ldr r2, [r4, #0x24]
	cmp r2, #0x1d
	bls _0804B8C4
	ldr r0, _0804B8C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804B8C4
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	b _0804B8C8
	.align 2, 0
_0804B8C0: .4byte 0x030044E0
_0804B8C4:
	adds r0, r2, #1
	str r0, [r4, #0x24]
_0804B8C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804b8d0
FUN_0804b8d0: @ 0x0804B8D0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08241704
	ldr r0, _0804B920 @ =0x03002B54
	ldr r0, [r0]
	cmp r0, #0
	beq _0804B8E8
	ldrb r1, [r4, #0x1a]
	movs r0, #0x70
	orrs r0, r1
	strb r0, [r4, #0x1a]
_0804B8E8:
	ldrb r0, [r4, #0x18]
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0804B906
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804B906
	movs r0, #9
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
_0804B906:
	ldr r0, _0804B924 @ =0x085AB5B8
	ldrb r1, [r4, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804B920: .4byte 0x03002B54
_0804B924: .4byte 0x085AB5B8

	thumb_func_start FUN_0804b928
FUN_0804b928: @ 0x0804B928
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0824172c
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B940
	bl FUN_0804a210
	ldr r0, [r4, #0x30]
	bl FUN_0804a16c
_0804B940:
	ldr r1, _0804B94C @ =0x030000D8
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804B94C: .4byte 0x030000D8

	thumb_func_start FUN_0804b950
FUN_0804b950: @ 0x0804B950
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0804B990 @ =0x03002B54
	movs r0, #0
	str r0, [r1]
	ldr r0, _0804B994 @ =0x030000D8
	str r4, [r0]
	bl FUN_08241704
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804B98A
	bl FUN_0823d340
	str r0, [r4, #0x28]
	cmp r0, #0
	beq _0804B98A
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804B98A
	bl FUN_0823d340
	str r0, [r4, #0x2c]
	cmp r0, #0
	bne _0804B998
_0804B98A:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804B9B2
	.align 2, 0
_0804B990: .4byte 0x03002B54
_0804B994: .4byte 0x030000D8
_0804B998:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r4, #0x34]
	adds r0, r4, #0
	bl FUN_0804b3f8
	movs r0, #0
	movs r1, #0
	bl FUN_0804e9f4
	movs r0, #0
_0804B9B2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b9b8
FUN_0804b9b8: @ 0x0804B9B8
	push {r4, lr}
	movs r0, #2
	movs r1, #0x4c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804B9EC
	ldr r1, _0804B9E4 @ =FUN_0804b8d0
	ldr r2, _0804B9E8 @ =FUN_0804b928
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0804b950
	cmp r0, #0
	bge _0804B9EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804B9EE
	.align 2, 0
_0804B9E4: .4byte FUN_0804b8d0
_0804B9E8: .4byte FUN_0804b928
_0804B9EC:
	adds r0, r4, #0
_0804B9EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804b9f4
FUN_0804b9f4: @ 0x0804B9F4
	push {r4, r5, r6, lr}
	bl Script_GetValue
	lsls r1, r0, #1
	movs r4, #0
	movs r3, #0
	ldr r0, _0804BA2C @ =gSystemSaveData
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #0x18
	ldr r0, _0804BA30 @ =0x085AB5B0
	adds r2, r1, r0
_0804BA0C:
	adds r0, r5, r1
	ldrb r0, [r0]
	ldrb r6, [r2]
	cmp r0, r6
	bne _0804BA18
	adds r4, #1
_0804BA18:
	adds r2, #1
	adds r3, #1
	adds r1, #1
	cmp r3, #1
	ble _0804BA0C
	cmp r4, #2
	beq _0804BA34
	movs r0, #0
	b _0804BA36
	.align 2, 0
_0804BA2C: .4byte gSystemSaveData
_0804BA30: .4byte 0x085AB5B0
_0804BA34:
	movs r0, #1
_0804BA36:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804ba3c
FUN_0804ba3c: @ 0x0804BA3C
	ldr r0, _0804BA44 @ =0x03002B58
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0804BA44: .4byte 0x03002B58

	thumb_func_start FUN_0804ba48
FUN_0804ba48: @ 0x0804BA48
	push {lr}
	ldr r0, _0804BA58 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	bne _0804BA5C
	movs r0, #0
	b _0804BA5E
	.align 2, 0
_0804BA58: .4byte 0x03002B58
_0804BA5C:
	movs r0, #1
_0804BA5E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804ba64
FUN_0804ba64: @ 0x0804BA64
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0
	strb r0, [r5, #0x1c]
	strb r0, [r5, #0x19]
	strb r0, [r5, #0x1a]
	strb r0, [r5, #0x1e]
	strb r0, [r5, #0x1f]
	adds r1, r5, #0
	adds r1, #0x20
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r1, #0
	strh r0, [r5, #0x22]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r6, _0804BB2C @ =0x030000DC
	movs r2, #0
	movs r1, #7
	adds r0, #8
_0804BA9C:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0804BA9C
	adds r0, r5, #0
	adds r0, #0x30
	movs r2, #0
	movs r3, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r4, r5, #0
	adds r4, #0x34
	strb r2, [r4]
	adds r0, #4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	strb r2, [r5, #0x1c]
	movs r1, #0
	strh r2, [r5, #0x38]
	str r2, [r5, #0x44]
	subs r0, #4
	strb r3, [r0]
	strh r2, [r5, #0x3a]
	adds r0, #0xa
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strh r2, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	str r2, [r5, #0x48]
	strb r1, [r6]
	adds r0, #0xb8
	strb r1, [r0]
	strb r1, [r4]
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r5, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r5, r1
	str r2, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x40
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #4
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0xa8
	movs r1, #0x10
	bl ClearMemory
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BB2C: .4byte 0x030000DC

	thumb_func_start FUN_0804bb30
FUN_0804bb30: @ 0x0804BB30
	push {lr}
	adds r2, r0, #0
	movs r0, #0
	strb r0, [r2, #0x1e]
	movs r1, #0
	strh r0, [r2, #0x22]
	adds r0, r2, #0
	adds r0, #0x35
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #6
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #0x40
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804bb68
FUN_0804bb68: @ 0x0804BB68
	adds r2, r0, #0
	adds r2, #0xee
	strh r1, [r2]
	bx lr

	thumb_func_start FUN_0804bb70
FUN_0804bb70: @ 0x0804BB70
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xec
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0804BB8A
	movs r0, #1
	rsbs r0, r0, #0
	b _0804BB94
_0804BB8A:
	adds r0, r2, #0
	adds r0, #0xee
	ldrh r0, [r0]
	strh r0, [r3]
	movs r0, #0
_0804BB94:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804bb98
FUN_0804bb98: @ 0x0804BB98
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r2, #0xba
	lsls r2, r2, #1
	adds r0, r4, r2
	bl FUN_0823a7d8
	cmp r0, #0
	beq _0804BBE2
	movs r0, #0xfa
	adds r0, r0, r4
	mov ip, r0
	movs r2, #0x88
	lsls r2, r2, #1
	adds r3, r4, r2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r4, r0
	adds r4, #0xf0
	movs r5, #4
_0804BBC6:
	ldrh r0, [r3]
	strh r0, [r4]
	ldrh r0, [r2]
	ldrh r1, [r3]
	eors r0, r1
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0804BBC6
	movs r1, #0
	b _0804BBEA
_0804BBE2:
	movs r1, #2
	rsbs r1, r1, #0
	adds r4, #0xfa
	mov ip, r4
_0804BBEA:
	movs r0, #1
	mov r2, ip
	strb r0, [r2]
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804bbf8
FUN_0804bbf8: @ 0x0804BBF8
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x1b]
	cmp r0, #0
	bne _0804BC06
	movs r0, #0
	b _0804BC0C
_0804BC06:
	movs r0, #0
	strb r0, [r1, #0x1b]
	movs r0, #1
_0804BC0C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804bc10
FUN_0804bc10: @ 0x0804BC10
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	bne _0804BC1E
	movs r0, #0
	b _0804BC24
_0804BC1E:
	movs r0, #0
	strb r0, [r1, #0x1c]
	movs r0, #1
_0804BC24:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804bc28
FUN_0804bc28: @ 0x0804BC28
	push {r4, r5, lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0x27
	movs r0, #0
	strb r0, [r1]
	movs r2, #0
	ldr r4, _0804BCA0 @ =0x03005800
	ldr r0, [r4]
	adds r5, r4, #0
	ldrb r0, [r0, #8]
	cmp r2, r0
	bge _0804BC7C
	adds r3, r1, #0
_0804BC44:
	mov r0, ip
	adds r0, #0x26
	ldrb r0, [r0]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BC70
	ldr r0, [r4]
	lsls r1, r2, #5
	adds r0, r0, r1
	ldrb r0, [r0, #0x16]
	cmp r0, #3
	bhi _0804BC70
	mov r0, ip
	adds r0, #0x28
	ldrb r1, [r3]
	adds r0, r0, r1
	strb r2, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_0804BC70:
	adds r2, #1
	adds r4, r5, #0
	ldr r0, [r4]
	ldrb r0, [r0, #8]
	cmp r2, r0
	blt _0804BC44
_0804BC7C:
	mov r0, ip
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r0, #2
	adds r0, #3
	cmp r1, #0
	bge _0804BC96
	adds r2, r1, #0
_0804BC90:
	adds r2, #1
	cmp r2, #0
	blt _0804BC90
_0804BC96:
	adds r2, r1, #0
	cmp r2, #0
	bge _0804BCA6
	movs r2, #0
	b _0804BCA6
	.align 2, 0
_0804BCA0: .4byte 0x03005800
_0804BCA4:
	adds r2, #1
_0804BCA6:
	adds r1, r0, #0
	cmp r0, #8
	ble _0804BCAE
	movs r1, #8
_0804BCAE:
	cmp r2, r1
	blt _0804BCA4
	cmp r0, #7
	ble _0804BCC2
	cmp r2, r0
	bge _0804BCC2
	subs r2, r0, r2
_0804BCBC:
	subs r2, #1
	cmp r2, #0
	bne _0804BCBC
_0804BCC2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804bcc8
FUN_0804bcc8: @ 0x0804BCC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r0, sp
	movs r4, #0
	strh r4, [r0]
	ldr r2, _0804BD08 @ =0x01000020
	adds r1, r5, #0
	bl CpuSet
	ldrh r1, [r7, #0x22]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804BD10
	movs r0, #1
	strb r0, [r5]
	ldrh r0, [r7, #0x22]
	movs r1, #8
	orrs r0, r1
	orrs r0, r4
	ldr r1, _0804BD0C @ =0x0000FEFF
	ands r0, r1
	strh r0, [r7, #0x22]
	b _0804BD12
	.align 2, 0
_0804BD08: .4byte 0x01000020
_0804BD0C: .4byte 0x0000FEFF
_0804BD10:
	strb r4, [r5]
_0804BD12:
	ldrh r1, [r7, #0x22]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _0804BD38
	movs r0, #1
	strb r0, [r5, #1]
	ldrh r1, [r7, #0x22]
	movs r0, #0x10
	orrs r0, r1
	ldr r1, _0804BD34 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r7, #0x22]
	b _0804BD3A
	.align 2, 0
_0804BD34: .4byte 0x0000FDFF
_0804BD38:
	strb r0, [r5, #1]
_0804BD3A:
	movs r0, #1
	strb r0, [r5, #3]
	movs r3, #0
	ldr r4, _0804BDD0 @ =0x03005800
	adds r2, r5, #4
	movs r1, #1
_0804BD46:
	ldrb r0, [r7, #0x19]
	asrs r0, r3
	ands r0, r1
	cmp r0, #0
	beq _0804BD56
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
_0804BD56:
	adds r3, #1
	cmp r3, #3
	ble _0804BD46
	ldrb r0, [r7, #0x19]
	lsls r0, r0, #1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #2]
	ldr r0, [r4]
	adds r0, #0xa9
	adds r1, r2, #0
	movs r2, #8
	bl FUN_0823766c
	ldr r1, [r4]
	adds r1, #0x94
	ldrh r1, [r1]
	strh r1, [r5, #0x36]
	movs r3, #0
	mov r8, r4
_0804BD7E:
	ldrb r2, [r7, #0x19]
	asrs r2, r3
	movs r1, #1
	ands r2, r1
	adds r6, r3, #1
	cmp r2, #0
	beq _0804BDBC
	lsls r4, r3, #5
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r1
	adds r0, #0x15
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r1, #0xe
	adds r1, r5, r1
	movs r2, #8
	bl FUN_0823766c
	lsls r1, r6, #1
	adds r2, r5, #0
	adds r2, #0x36
	adds r2, r2, r1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r1, r4
	ldrh r1, [r1, #0x14]
	strh r1, [r2]
_0804BDBC:
	adds r3, r6, #0
	cmp r3, #3
	ble _0804BD7E
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804BDD0: .4byte 0x03005800

	thumb_func_start FUN_0804bdd4
FUN_0804bdd4: @ 0x0804BDD4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	ldrh r2, [r4, #0x22]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	bne _0804BDF8
	ldr r0, _0804BDFC @ =0x03005800
	ldr r1, [r0]
	ldrb r1, [r1, #3]
	adds r6, r0, #0
	cmp r1, #0
	bne _0804BDF8
	movs r0, #0xa0
	ands r0, r2
	cmp r0, #0
	beq _0804BE00
_0804BDF8:
	movs r0, #0
	b _0804BECC
	.align 2, 0
_0804BDFC: .4byte 0x03005800
_0804BE00:
	ldrh r0, [r4, #0x38]
	cmp r0, #9
	bne _0804BE18
	movs r0, #0x84
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	bne _0804BE18
	ldr r1, _0804BEB4 @ =0x00000205
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r4, #0x22]
_0804BE18:
	ldrb r0, [r4, #0x19]
	ldrb r1, [r4, #0x1a]
	adds r3, r0, #0
	cmp r1, r3
	beq _0804BE3A
	ldrh r1, [r4, #0x22]
	movs r0, #4
	movs r2, #0
	orrs r1, r0
	strh r1, [r4, #0x22]
	ldr r0, [r6]
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _0804BE3A
	movs r0, #1
	orrs r1, r0
	strh r1, [r4, #0x22]
_0804BE3A:
	strb r3, [r4, #0x1a]
	ldrh r1, [r4, #0x22]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0804BE56
	adds r0, r4, #0
	bl FUN_0804bcc8
	ldrh r1, [r4, #0x22]
	ldr r0, _0804BEB8 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4, #0x22]
	movs r7, #1
_0804BE56:
	ldrh r1, [r4, #0x22]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0804BECA
	ldrb r0, [r4, #0x19]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r1, #0x43
	movs r3, #0x40
	bl rfu_NI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804BEC4
	movs r2, #0
	ldr r0, _0804BEBC @ =0x03005800
	ldr r1, [r0]
	ldrb r1, [r1, #2]
	ands r1, r5
	adds r6, r0, #0
	adds r5, r4, #0
	adds r5, #0x20
	cmp r1, #0
	bne _0804BEA2
	adds r3, r6, #0
	movs r1, #1
_0804BE90:
	adds r2, #1
	cmp r2, #3
	bgt _0804BEA2
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r2
	ands r0, r1
	cmp r0, #0
	beq _0804BE90
_0804BEA2:
	strb r2, [r5]
	ldrh r0, [r4, #0x22]
	ldr r1, _0804BEC0 @ =0x0000FFFE
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strh r1, [r4, #0x22]
	b _0804BECA
	.align 2, 0
_0804BEB4: .4byte 0x00000205
_0804BEB8: .4byte 0x0000FFFB
_0804BEBC: .4byte 0x03005800
_0804BEC0: .4byte 0x0000FFFE
_0804BEC4:
	movs r0, #2
	bl FUN_0804e584
_0804BECA:
	adds r0, r7, #0
_0804BECC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804bed4
FUN_0804bed4: @ 0x0804BED4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804BF8A
	ldr r1, _0804BF3C @ =0x030057F0
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r3, [r0]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	cmp r0, #0x26
	bne _0804BF48
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	ldrb r0, [r2, #0x1a]
	adds r5, r0, #0
	eors r5, r1
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	ldrh r0, [r4, #0x22]
	ldr r2, _0804BF40 @ =0x0000FFFD
	ands r2, r0
	strh r2, [r4, #0x22]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0804BF24
	movs r1, #0x80
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4, #0x22]
_0804BF24:
	ldrh r1, [r4, #0x22]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0804BF7C
	ldr r0, _0804BF44 @ =0x0000FFF7
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r4, #0x22]
	b _0804BF7C
	.align 2, 0
_0804BF3C: .4byte 0x030057F0
_0804BF40: .4byte 0x0000FFFD
_0804BF44: .4byte 0x0000FFF7
_0804BF48:
	cmp r0, #0x27
	bne _0804BF7C
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	ldrb r0, [r2, #0x1a]
	adds r5, r0, #0
	eors r5, r1
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	movs r2, #0
	strh r2, [r4, #0x22]
	ldrh r0, [r4, #0x38]
	cmp r0, #9
	bne _0804BF7C
	movs r0, #7
	movs r1, #0
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r2, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804BF7C:
	cmp r5, #0
	beq _0804BF8A
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	orrs r5, r0
	strb r5, [r1]
_0804BF8A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804bf90
FUN_0804bf90: @ 0x0804BF90
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _0804BFC4 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	bne _0804BFA0
	b _0804C184
_0804BFA0:
	cmp r3, #0x33
	bne _0804BFA6
	b _0804C0C4
_0804BFA6:
	cmp r3, #0x33
	bgt _0804BFE6
	cmp r3, #0x13
	beq _0804C058
	cmp r3, #0x13
	bgt _0804BFCE
	cmp r3, #0x10
	bne _0804BFB8
	b _0804C184
_0804BFB8:
	cmp r3, #0x10
	bgt _0804BFC8
	cmp r3, #0
	beq _0804C036
	b _0804C184
	.align 2, 0
_0804BFC4: .4byte 0x03002B58
_0804BFC8:
	cmp r3, #0x11
	beq _0804C046
	b _0804C184
_0804BFCE:
	cmp r3, #0x30
	beq _0804C0C4
	cmp r3, #0x30
	bgt _0804BFDC
	cmp r3, #0x14
	beq _0804C06A
	b _0804C184
_0804BFDC:
	cmp r3, #0x31
	beq _0804C09A
	cmp r3, #0x32
	beq _0804C0B0
	b _0804C184
_0804BFE6:
	cmp r3, #0x44
	bne _0804BFEC
	b _0804C148
_0804BFEC:
	cmp r3, #0x44
	bgt _0804C010
	cmp r3, #0x41
	bne _0804BFF6
	b _0804C184
_0804BFF6:
	cmp r3, #0x41
	bgt _0804C002
	cmp r3, #0x40
	bne _0804C000
	b _0804C0F4
_0804C000:
	b _0804C184
_0804C002:
	cmp r3, #0x42
	bne _0804C008
	b _0804C124
_0804C008:
	cmp r3, #0x43
	bne _0804C00E
	b _0804C136
_0804C00E:
	b _0804C184
_0804C010:
	cmp r3, #0xf1
	bne _0804C016
	b _0804C166
_0804C016:
	cmp r3, #0xf1
	bgt _0804C028
	cmp r3, #0x50
	bne _0804C020
	b _0804C17E
_0804C020:
	cmp r3, #0xf0
	bne _0804C026
	b _0804C166
_0804C026:
	b _0804C184
_0804C028:
	cmp r3, #0xf2
	bne _0804C02E
	b _0804C166
_0804C02E:
	cmp r3, #0xff
	bne _0804C034
	b _0804C15A
_0804C034:
	b _0804C184
_0804C036:
	movs r0, #5
	strb r3, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r3, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C046:
	ldr r0, _0804C054 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r4, #0x19]
	orrs r0, r1
	strb r0, [r4, #0x19]
	b _0804C184
	.align 2, 0
_0804C054: .4byte 0x03004740
_0804C058:
	movs r1, #5
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C06A:
	ldr r0, _0804C084 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #1]
	cmp r1, #0
	bne _0804C088
	movs r0, #5
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
	.align 2, 0
_0804C084: .4byte 0x03005800
_0804C088:
	movs r1, #9
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C09A:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804C0AC @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804C184
	.align 2, 0
_0804C0AC: .4byte 0x03004740
_0804C0B0:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804C0C0 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804C184
	.align 2, 0
_0804C0C0: .4byte 0x03004740
_0804C0C4:
	ldr r2, _0804C0F0 @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r4, #0x19]
	bics r0, r1
	strb r0, [r4, #0x19]
	adds r3, r4, #0
	adds r3, #0x25
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0x19]
	cmp r1, #0
	bne _0804C184
	movs r0, #0xb
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
	.align 2, 0
_0804C0F0: .4byte 0x03004740
_0804C0F4:
	ldr r2, _0804C120 @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r4, #0x19]
	bics r0, r1
	strb r0, [r4, #0x19]
	adds r3, r4, #0
	adds r3, #0x25
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	strb r0, [r3]
	ldrb r1, [r4, #0x19]
	cmp r1, #0
	bne _0804C184
	movs r0, #0xb
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
	.align 2, 0
_0804C120: .4byte 0x03004740
_0804C124:
	movs r1, #0x20
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C136:
	movs r1, #5
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C148:
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804C182
_0804C15A:
	ldrh r0, [r4, #0x38]
	cmp r0, #0x1c
	beq _0804C17E
	cmp r0, #1
	bls _0804C17E
	b _0804C16C
_0804C166:
	ldrh r0, [r4, #0x38]
	cmp r0, #0x1c
	beq _0804C17E
_0804C16C:
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804C17E:
	ldr r1, _0804C18C @ =0x030000DC
	movs r0, #0
_0804C182:
	strb r0, [r1]
_0804C184:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C18C: .4byte 0x030000DC

	thumb_func_start FUN_0804c190
FUN_0804c190: @ 0x0804C190
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _0804C1C0 @ =0x03002B58
	ldr r5, [r0]
	cmp r5, #0
	bne _0804C1A0
	b _0804C3A2
_0804C1A0:
	cmp r3, #0x33
	bne _0804C1A6
	b _0804C30C
_0804C1A6:
	cmp r3, #0x33
	bgt _0804C1EE
	cmp r3, #0x23
	beq _0804C290
	cmp r3, #0x23
	bgt _0804C1CE
	cmp r3, #0x20
	beq _0804C24E
	cmp r3, #0x20
	bgt _0804C1C4
	cmp r3, #0
	beq _0804C244
	b _0804C3A2
	.align 2, 0
_0804C1C0: .4byte 0x03002B58
_0804C1C4:
	cmp r3, #0x21
	beq _0804C260
	cmp r3, #0x22
	beq _0804C264
	b _0804C3A2
_0804C1CE:
	cmp r3, #0x30
	bne _0804C1D4
	b _0804C30C
_0804C1D4:
	cmp r3, #0x30
	bgt _0804C1E2
	cmp r3, #0x24
	beq _0804C294
	cmp r3, #0x25
	beq _0804C2BC
	b _0804C3A2
_0804C1E2:
	cmp r3, #0x31
	beq _0804C2C0
	cmp r3, #0x32
	bne _0804C1EC
	b _0804C2E8
_0804C1EC:
	b _0804C3A2
_0804C1EE:
	cmp r3, #0x45
	bne _0804C1F4
	b _0804C3A2
_0804C1F4:
	cmp r3, #0x45
	bgt _0804C218
	cmp r3, #0x42
	bne _0804C1FE
	b _0804C36C
_0804C1FE:
	cmp r3, #0x42
	bgt _0804C20A
	cmp r3, #0x40
	bne _0804C208
	b _0804C346
_0804C208:
	b _0804C3A2
_0804C20A:
	cmp r3, #0x43
	bne _0804C210
	b _0804C370
_0804C210:
	cmp r3, #0x44
	bne _0804C216
	b _0804C374
_0804C216:
	b _0804C3A2
_0804C218:
	cmp r3, #0xf1
	bne _0804C21E
	b _0804C378
_0804C21E:
	cmp r3, #0xf1
	bgt _0804C22E
	cmp r3, #0x50
	beq _0804C23C
	cmp r3, #0xf0
	bne _0804C22C
	b _0804C378
_0804C22C:
	b _0804C3A2
_0804C22E:
	cmp r3, #0xf2
	bne _0804C234
	b _0804C38A
_0804C234:
	cmp r3, #0xff
	bne _0804C23A
	b _0804C380
_0804C23A:
	b _0804C3A2
_0804C23C:
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	b _0804C3A2
_0804C244:
	movs r0, #6
	strb r3, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r3, [r5, #0x44]
	b _0804C39A
_0804C24E:
	ldr r0, _0804C25C @ =0x03004740
	ldrh r1, [r0, #0x14]
	adds r0, r5, #0
	adds r0, #0x26
	strb r1, [r0]
	b _0804C3A2
	.align 2, 0
_0804C25C: .4byte 0x03004740
_0804C260:
	movs r1, #6
	b _0804C392
_0804C264:
	ldr r0, _0804C28C @ =0x03004740
	ldrh r0, [r0, #0x14]
	adds r1, r5, #0
	adds r1, #0x21
	movs r4, #0
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r0, #0x20
	movs r3, #0x40
	bl rfu_setRecvBuffer
	movs r0, #0xe
	strb r4, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r4, [r5, #0x44]
	b _0804C39A
	.align 2, 0
_0804C28C: .4byte 0x03004740
_0804C290:
	movs r1, #6
	b _0804C392
_0804C294:
	adds r1, r5, #0
	adds r1, #0x43
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0804C2B8 @ =0x03005800
	ldr r0, [r0]
	ldrb r3, [r0, #2]
	subs r3, #1
	cmp r3, #0
	bne _0804C2AA
	b _0804C3A2
_0804C2AA:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	subs r3, #1
	cmp r3, #0
	bne _0804C2AA
	b _0804C3A2
	.align 2, 0
_0804C2B8: .4byte 0x03005800
_0804C2BC:
	movs r1, #6
	b _0804C392
_0804C2C0:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C2E4 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	movs r3, #0
	strb r0, [r2]
	ldrh r1, [r5, #0x38]
	adds r0, r5, #0
	adds r0, #0x40
	movs r2, #0
	strh r1, [r0]
	movs r0, #0x10
	strb r2, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r3, [r5, #0x44]
	b _0804C39A
	.align 2, 0
_0804C2E4: .4byte 0x03004740
_0804C2E8:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C308 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	b _0804C39A
	.align 2, 0
_0804C308: .4byte 0x03004740
_0804C30C:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C338 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	movs r1, #0
	strb r0, [r2]
	ldrh r0, [r5, #0x38]
	cmp r0, #0xf
	bls _0804C33C
	movs r0, #0x1d
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	bl rfu_LMAN_stopManager
	b _0804C3A2
	.align 2, 0
_0804C338: .4byte 0x03004740
_0804C33C:
	movs r0, #0xb
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	b _0804C39A
_0804C346:
	movs r1, #0xb
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C368 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804C3A2
	.align 2, 0
_0804C368: .4byte 0x03004740
_0804C36C:
	movs r1, #0x20
	b _0804C392
_0804C370:
	movs r1, #6
	b _0804C392
_0804C374:
	movs r1, #0x1e
	b _0804C392
_0804C378:
	ldrh r0, [r5, #0x38]
	cmp r0, #0x1c
	beq _0804C3A2
	b _0804C38A
_0804C380:
	ldrh r0, [r5, #0x38]
	cmp r0, #0x1c
	beq _0804C3A2
	cmp r0, #1
	bls _0804C3A2
_0804C38A:
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1c
_0804C392:
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
_0804C39A:
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804C3A2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804c3a8
FUN_0804c3a8: @ 0x0804C3A8
	push {lr}
	bl rfu_REQ_recvData
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804c3b4
FUN_0804c3b4: @ 0x0804C3B4
	push {lr}
	ldr r0, _0804C3C8 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804C3C2
	bl rfu_REQ_recvData
_0804C3C2:
	pop {r0}
	bx r0
	.align 2, 0
_0804C3C8: .4byte 0x03002B58

	thumb_func_start FUN_0804c3cc
FUN_0804c3cc: @ 0x0804C3CC
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804C3DE
	movs r1, #0
	strb r1, [r2]
_0804C3DE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c3e4
FUN_0804c3e4: @ 0x0804C3E4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804C3F6
	movs r0, #0
	strb r0, [r5]
_0804C3F6:
	ldr r0, _0804C418 @ =FUN_0804bf90
	ldr r1, _0804C41C @ =FUN_0804c3a8
	bl rfu_LMAN_initializeManager
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0804C420
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
	b _0804C42E
	.align 2, 0
_0804C418: .4byte FUN_0804bf90
_0804C41C: .4byte FUN_0804c3a8
_0804C420:
	movs r0, #2
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
	strb r0, [r4, #0x18]
_0804C42E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c438
FUN_0804c438: @ 0x0804C438
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x32
	ldrb r0, [r7]
	cmp r0, #0
	beq _0804C44C
	movs r0, #0
	strb r0, [r7]
_0804C44C:
	adds r4, r5, #0
	adds r4, #0x3c
	ldrb r0, [r4]
	adds r6, r0, #0
	cmp r6, #0
	beq _0804C45E
	subs r0, #1
	strb r0, [r4]
	b _0804C568
_0804C45E:
	bl FUN_0823a6fc
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C48A
	cmp r1, #0
	bgt _0804C476
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804C47C
	b _0804C568
_0804C476:
	cmp r1, #1
	beq _0804C490
	b _0804C568
_0804C47C:
	movs r0, #0x1b
	strb r6, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r6, [r5, #0x44]
	movs r0, #1
	strb r0, [r7]
	b _0804C568
_0804C48A:
	movs r0, #0x3c
	strb r0, [r4]
	b _0804C568
_0804C490:
	movs r4, #3
	strb r6, [r5, #0x1c]
	strh r4, [r5, #0x38]
	str r6, [r5, #0x44]
	strb r1, [r7]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r6, r0, #0
	ldr r2, _0804C4DC @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _0804C4E0 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	ldr r7, _0804C4E4 @ =0x0203B400
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _0804C4F2
	bl FUN_0823e1b0
	adds r4, r0, #0
	bl GetHour
	adds r1, r0, #0
	subs r4, #1
	cmp r4, #2
	bhi _0804C4E8
	movs r0, #1
	cmp r1, #0xb
	bgt _0804C504
	movs r0, #0
	b _0804C504
	.align 2, 0
_0804C4DC: .4byte 0x030046B8
_0804C4E0: .4byte 0x000003FF
_0804C4E4: .4byte 0x0203B400
_0804C4E8:
	movs r0, #3
	cmp r1, #0xb
	bgt _0804C504
	movs r0, #2
	b _0804C504
_0804C4F2:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0804C574 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ands r0, r4
	adds r0, #4
_0804C504:
	adds r0, r6, r0
	bl Textbox_LookupString
	adds r4, r0, #0
	ldr r0, _0804C578 @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0xf0
	lsls r7, r7, #2
	adds r0, r0, r7
	adds r7, r5, #0
	adds r7, #0x60
	adds r1, r7, #0
	movs r2, #8
	bl FUN_0804e6d8
	adds r6, r5, #0
	adds r6, #0x50
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xb
	bl FUN_0804e6d8
	adds r1, r5, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r2, r5, #0
	adds r2, #0x5b
	strb r0, [r2]
	ldrh r0, [r1]
	lsrs r0, r0, #8
	subs r1, #0x10
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r3, #0
	cmp r1, #0
	beq _0804C558
	movs r3, #3
_0804C558:
	movs r0, #0
	str r0, [sp]
	str r6, [sp, #4]
	str r7, [sp, #8]
	adds r0, r2, #0
	movs r2, #0x11
	bl FUN_0823a730
_0804C568:
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804C574: .4byte 0x0203B400
_0804C578: .4byte 0x030046A0

	thumb_func_start FUN_0804c57c
FUN_0804c57c: @ 0x0804C57C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804C58E
	movs r0, #0
	strb r0, [r5]
_0804C58E:
	ldr r0, [r4, #0x44]
	cmp r0, #0x3b
	bls _0804C5B2
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl rfu_LMAN_initializeRFU
	ldr r1, _0804C5BC @ =0x030000DC
	movs r0, #0
	strb r0, [r1]
	movs r1, #4
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
_0804C5B2:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804C5BC: .4byte 0x030000DC

	thumb_func_start FUN_0804c5c0
FUN_0804c5c0: @ 0x0804C5C0
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C5D0
	movs r0, #0
	strb r0, [r1]
_0804C5D0:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c5d8
FUN_0804c5d8: @ 0x0804C5D8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C604
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0xa8
_0804C5F0:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x20
	adds r2, r6, #0
	movs r3, #4
	bl rfu_setRecvBuffer
	adds r4, #1
	cmp r4, #3
	ble _0804C5F0
_0804C604:
	movs r2, #0x96
	lsls r2, r2, #2
	ldr r3, _0804C634 @ =0x08251D40
	movs r0, #1
	movs r1, #0
	bl rfu_LMAN_establishConnection
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0
	beq _0804C638
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	subs r0, #2
	b _0804C648
	.align 2, 0
_0804C634: .4byte 0x08251D40
_0804C638:
	movs r1, #7
	strb r2, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r2, [r5, #0x44]
	adds r2, r5, #0
	adds r2, #0x32
	movs r1, #1
	strb r1, [r2]
_0804C648:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c650
FUN_0804c650: @ 0x0804C650
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804C668
	movs r0, #0
	strb r0, [r5]
	adds r1, r4, #0
	adds r1, #0x26
	strb r0, [r1]
_0804C668:
	movs r2, #0x96
	lsls r2, r2, #2
	ldr r3, _0804C694 @ =0x08251D40
	movs r0, #0
	movs r1, #0
	bl rfu_LMAN_establishConnection
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0
	beq _0804C698
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	movs r0, #1
	strb r0, [r5]
	subs r0, #2
	b _0804C6A4
	.align 2, 0
_0804C694: .4byte 0x08251D40
_0804C698:
	movs r1, #8
	strb r2, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r2, [r4, #0x44]
	movs r1, #1
	strb r1, [r5]
_0804C6A4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804c6ac
FUN_0804c6ac: @ 0x0804C6AC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C6C2
	movs r0, #0
	strb r0, [r1]
	strb r0, [r4, #0x1b]
	strb r0, [r4, #0x1c]
_0804C6C2:
	adds r0, r4, #0
	bl FUN_0804bbf8
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C6F0
	ldr r2, _0804C76C @ =0x00000135
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _0804C6EC
	ldrh r2, [r4, #0x22]
	movs r1, #0x8e
	lsls r1, r1, #2
	ands r1, r2
	cmp r1, #0
	bne _0804C6EC
	ldr r3, _0804C770 @ =0x00000105
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r4, #0x22]
_0804C6EC:
	movs r1, #0
	strb r1, [r4, #0x1b]
_0804C6F0:
	ldrh r2, [r4, #0x22]
	movs r1, #0x40
	ands r1, r2
	cmp r1, #0
	beq _0804C70C
	movs r1, #0xce
	lsls r1, r1, #2
	ands r1, r2
	cmp r1, #0
	bne _0804C70C
	ldr r3, _0804C770 @ =0x00000105
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r4, #0x22]
_0804C70C:
	ldr r2, _0804C774 @ =0x030057F0
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r1, [r5]
	lsls r3, r1, #2
	adds r2, r3, r2
	ldr r1, [r2]
	ldrh r1, [r1, #0x34]
	cmp r1, #0x46
	bne _0804C740
	adds r0, r4, r3
	adds r1, r0, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C738
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r4, #0x22]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4, #0x22]
_0804C738:
	ldrb r1, [r5]
	movs r0, #8
	bl rfu_clearSlot
_0804C740:
	ldrh r2, [r4, #0x22]
	movs r1, #0x60
	ands r1, r2
	cmp r1, #0x60
	bne _0804C784
	ldr r0, _0804C778 @ =0x0000FFDF
	ands r0, r2
	ldr r1, _0804C77C @ =0x0000FFBF
	ands r0, r1
	strh r0, [r4, #0x22]
	adds r2, r4, #0
	adds r2, #0x35
	ldr r0, _0804C780 @ =0x03005800
	ldr r1, [r0]
	ldrb r0, [r1, #2]
	ldrb r1, [r1, #3]
	orrs r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0
	b _0804C7BC
	.align 2, 0
_0804C76C: .4byte 0x00000135
_0804C770: .4byte 0x00000105
_0804C774: .4byte 0x030057F0
_0804C778: .4byte 0x0000FFDF
_0804C77C: .4byte 0x0000FFBF
_0804C780: .4byte 0x03005800
_0804C784:
	ldrb r3, [r4, #0x19]
	cmp r3, #0
	beq _0804C7BC
	movs r5, #0xb4
	lsls r5, r5, #1
	ands r5, r2
	cmp r5, #0
	bne _0804C7BC
	ldr r1, _0804C7C4 @ =0x03005800
	ldr r1, [r1]
	ldrb r1, [r1, #2]
	cmp r3, r1
	bne _0804C7BC
	adds r0, r4, #0
	bl FUN_0804bc10
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C7BC
	movs r0, #9
	strb r5, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r5, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0804C7BC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804C7C4: .4byte 0x03005800

	thumb_func_start FUN_0804c7c8
FUN_0804c7c8: @ 0x0804C7C8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C7DA
	movs r0, #0
	strb r0, [r1]
_0804C7DA:
	adds r0, r4, #0
	bl FUN_0804bc28
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r2, [r1]
	adds r7, r1, #0
	cmp r2, #0
	beq _0804C87C
	adds r3, r4, #0
	adds r3, #0x24
	movs r6, #0
	ldrsb r6, [r3, r6]
	ldr r2, _0804C808 @ =0x030044E0
	ldrh r5, [r2, #2]
	movs r1, #0x40
	ands r1, r5
	cmp r1, #0
	beq _0804C80C
	ldrb r1, [r3]
	subs r1, #1
	b _0804C818
	.align 2, 0
_0804C808: .4byte 0x030044E0
_0804C80C:
	movs r1, #0x80
	ands r1, r5
	cmp r1, #0
	beq _0804C81A
	ldrb r1, [r3]
	adds r1, #1
_0804C818:
	strb r1, [r3]
_0804C81A:
	movs r1, #0
	ldrsb r1, [r3, r1]
	cmp r6, r1
	beq _0804C832
	cmp r1, #7
	ble _0804C82A
	movs r1, #7
	b _0804C830
_0804C82A:
	cmp r1, #0
	bge _0804C832
	movs r1, #0
_0804C830:
	strb r1, [r3]
_0804C832:
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	ldrb r5, [r7]
	ldrh r2, [r2, #2]
	movs r1, #1
	ands r1, r2
	cmp r1, #0
	beq _0804C87C
	cmp r3, r5
	bge _0804C87C
	adds r0, r4, #0
	adds r0, #0x28
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r0, _0804C884 @ =0x03005800
	ldr r0, [r0]
	lsls r1, r1, #5
	adds r0, r0, r1
	ldrh r0, [r0, #0x14]
	movs r1, #0
	bl rfu_LMAN_CHILD_connectParent
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0
	bne _0804C87C
	movs r0, #0xa
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0804C87C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804C884: .4byte 0x03005800

	thumb_func_start FUN_0804c888
FUN_0804c888: @ 0x0804C888
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804C8A0
	movs r0, #0
	strb r0, [r2]
	movs r0, #0xdd
	bl PlaySound_082406e0
_0804C8A0:
	ldrh r2, [r4, #0x22]
	movs r1, #0x80
	ands r1, r2
	cmp r1, #0
	beq _0804C8B6
	movs r0, #8
	bl FUN_08229f4c
	adds r0, r4, #0
	bl FUN_0804d868
_0804C8B6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804c8bc
FUN_0804c8bc: @ 0x0804C8BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r1, [r5]
	cmp r1, #0
	beq _0804C8CE
	movs r1, #0
	strb r1, [r5]
_0804C8CE:
	ldr r2, [r4, #0x44]
	ldr r1, _0804C8F0 @ =0x00000257
	cmp r2, r1
	bls _0804C8EA
	movs r0, #0
	bl rfu_LMAN_stopManager
	movs r2, #4
	movs r1, #0
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x38]
	str r1, [r4, #0x44]
	movs r1, #1
	strb r1, [r5]
_0804C8EA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804C8F0: .4byte 0x00000257

	thumb_func_start FUN_0804c8f4
FUN_0804c8f4: @ 0x0804C8F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r1, [r5]
	cmp r1, #0
	beq _0804C90C
	movs r0, #0
	strb r0, [r5]
	movs r0, #0xde
	bl PlaySound_082406e0
_0804C90C:
	ldr r1, [r4, #0x44]
	cmp r1, #0x59
	bls _0804C93A
	adds r0, r4, #0
	bl FUN_0804bb30
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r2, [r1]
	cmp r2, #0
	beq _0804C92E
	movs r2, #7
	movs r1, #0
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x38]
	str r1, [r4, #0x44]
	b _0804C936
_0804C92E:
	movs r1, #6
	strb r2, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r2, [r4, #0x44]
_0804C936:
	movs r1, #1
	strb r1, [r5]
_0804C93A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804c940
FUN_0804c940: @ 0x0804C940
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C950
	movs r0, #0
	strb r0, [r1]
_0804C950:
	bl rfu_getMasterSlave
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _0804C970
	ldr r0, _0804C974 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #2]
	ldrb r0, [r0, #3]
	orrs r0, r1
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_0804C970:
	pop {r1}
	bx r1
	.align 2, 0
_0804C974: .4byte 0x03005800

	thumb_func_start FUN_0804c978
FUN_0804c978: @ 0x0804C978
	push {lr}
	adds r3, r0, #0
	movs r1, #0x32
	adds r1, r1, r3
	mov ip, r1
	ldrb r1, [r1]
	cmp r1, #0
	beq _0804C98E
	movs r1, #0
	mov r2, ip
	strb r1, [r2]
_0804C98E:
	ldr r1, [r3, #0x44]
	cmp r1, #0x78
	bls _0804C9A4
	movs r2, #8
	movs r1, #0
	strb r1, [r3, #0x1c]
	strh r2, [r3, #0x38]
	str r1, [r3, #0x44]
	movs r1, #1
	mov r2, ip
	strb r1, [r2]
_0804C9A4:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804c9a8
FUN_0804c9a8: @ 0x0804C9A8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804C9BA
	movs r1, #0
	strb r1, [r2]
_0804C9BA:
	ldr r2, _0804CAA8 @ =0x030057F0
	adds r3, r6, #0
	adds r3, #0x21
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	ldrh r1, [r1, #0x34]
	adds r5, r3, #0
	cmp r1, #0x46
	bne _0804CA00
	ldr r1, _0804CAAC @ =0x00000135
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804C9E0
	adds r0, r6, #0
	bl FUN_0804dbe0
_0804C9E0:
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C9F8
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r6, #0x22]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r6, #0x22]
_0804C9F8:
	ldrb r1, [r5]
	movs r0, #8
	bl rfu_clearSlot
_0804CA00:
	ldr r1, _0804CAB0 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _0804CA1C
	ldrh r1, [r6, #0x22]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r3, #0
	orrs r2, r1
	movs r1, #1
	orrs r2, r1
	strh r2, [r6, #0x22]
_0804CA1C:
	ldrh r2, [r6, #0x22]
	movs r1, #0x40
	ands r1, r2
	cmp r1, #0
	beq _0804CA3C
	movs r1, #0x28
	ands r1, r2
	cmp r1, #0
	bne _0804CA3C
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r1, r2
	movs r2, #1
	orrs r1, r2
	strh r1, [r6, #0x22]
_0804CA3C:
	ldrh r2, [r6, #0x22]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	bne _0804CAD2
	ldr r1, _0804CAB4 @ =0x03005800
	ldr r1, [r1]
	ldrb r1, [r1, #3]
	cmp r1, #0
	bne _0804CAC8
	movs r7, #1
	adds r1, r7, #0
	ands r1, r2
	cmp r1, #0
	beq _0804CAC8
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	adds r4, r6, #0
	adds r4, #0xa4
	cmp r0, #0
	beq _0804CA78
	movs r0, #1
	strb r0, [r4]
	ldrh r1, [r6, #0x22]
	ldr r0, _0804CAB8 @ =0x0000FEFF
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r6, #0x22]
_0804CA78:
	ldrb r1, [r5]
	movs r0, #4
	bl rfu_clearSlot
	adds r0, r7, #0
	ldrb r1, [r5]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #6
	adds r2, r4, #0
	movs r3, #4
	bl rfu_NI_setSendData
	adds r1, r0, #0
	lsls r1, r1, #0x10
	cmp r1, #0
	beq _0804CABC
	movs r0, #2
	bl FUN_0804e584
	movs r0, #0
	b _0804CB5E
	.align 2, 0
_0804CAA8: .4byte 0x030057F0
_0804CAAC: .4byte 0x00000135
_0804CAB0: .4byte 0x030044E0
_0804CAB4: .4byte 0x03005800
_0804CAB8: .4byte 0x0000FEFF
_0804CABC:
	ldrh r1, [r6, #0x22]
	ldr r2, _0804CB10 @ =0x0000FFFE
	ands r2, r1
	movs r1, #2
	orrs r2, r1
	strh r2, [r6, #0x22]
_0804CAC8:
	ldrh r2, [r6, #0x22]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _0804CB30
_0804CAD2:
	ldr r1, _0804CB14 @ =0x030057F0
	ldrb r3, [r5]
	lsls r2, r3, #2
	adds r2, r2, r1
	ldr r1, [r2]
	ldrh r1, [r1]
	cmp r1, #0x26
	bne _0804CB20
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	ldrh r1, [r6, #0x22]
	ldr r2, _0804CB18 @ =0x0000FFFD
	ands r2, r1
	strh r2, [r6, #0x22]
	movs r1, #8
	ands r1, r2
	cmp r1, #0
	beq _0804CB30
	ldr r1, _0804CB1C @ =0x0000FFF7
	ands r1, r2
	movs r2, #0x20
	orrs r1, r2
	strh r1, [r6, #0x22]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0
	strb r1, [r2]
	b _0804CB30
	.align 2, 0
_0804CB10: .4byte 0x0000FFFE
_0804CB14: .4byte 0x030057F0
_0804CB18: .4byte 0x0000FFFD
_0804CB1C: .4byte 0x0000FFF7
_0804CB20:
	cmp r1, #0x27
	bne _0804CB30
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	movs r1, #0
	strh r1, [r6, #0x22]
_0804CB30:
	ldrh r2, [r6, #0x22]
	movs r1, #0x60
	ands r1, r2
	cmp r1, #0x60
	bne _0804CB5E
	ldr r0, _0804CB64 @ =0x0000FFDF
	ands r0, r2
	movs r4, #0
	movs r5, #0
	ldr r1, _0804CB68 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r6, #0x22]
	bl rfu_LMAN_requestChangeAgbClockMaster
	movs r0, #0xc
	strb r4, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r5, [r6, #0x44]
	adds r1, r6, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0804CB5E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804CB64: .4byte 0x0000FFDF
_0804CB68: .4byte 0x0000FFBF

	thumb_func_start FUN_0804cb6c
FUN_0804cb6c: @ 0x0804CB6C
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804CB7E
	movs r1, #0
	strb r1, [r2]
_0804CB7E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cb84
FUN_0804cb84: @ 0x0804CB84
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804CB96
	movs r1, #0
	strb r1, [r2]
_0804CB96:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cb9c
FUN_0804cb9c: @ 0x0804CB9C
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804CBAE
	movs r1, #0
	strb r1, [r2]
_0804CBAE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cbb4
FUN_0804cbb4: @ 0x0804CBB4
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804CBC6
	movs r1, #0
	strb r1, [r2]
_0804CBC6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cbcc
FUN_0804cbcc: @ 0x0804CBCC
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CBE2
	movs r0, #0
	strb r0, [r1]
	strb r0, [r4, #0x1b]
	strb r0, [r4, #0x1c]
_0804CBE2:
	adds r0, r4, #0
	bl FUN_0804bc10
	cmp r0, #0
	beq _0804CBF2
	adds r0, r4, #0
	bl FUN_0804ba64
_0804CBF2:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cbfc
FUN_0804cbfc: @ 0x0804CBFC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CC1E
	movs r4, #0
	strb r4, [r1]
	movs r0, #1
	bl FUN_0804e584
	movs r0, #1
	bl rfu_LMAN_stopManager
	strb r4, [r5, #0x1b]
	strb r4, [r5, #0x1c]
_0804CC1E:
	adds r0, r5, #0
	bl FUN_0804bc10
	cmp r0, #0
	beq _0804CC2E
	adds r0, r5, #0
	bl FUN_0804ba64
_0804CC2E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cc38
FUN_0804cc38: @ 0x0804CC38
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x32
	ldrb r0, [r6]
	cmp r0, #0
	beq _0804CC5A
	movs r4, #0
	strb r4, [r6]
	movs r0, #2
	bl FUN_0804e584
	movs r0, #1
	bl rfu_LMAN_stopManager
	strb r4, [r5, #0x1b]
	strb r4, [r5, #0x1c]
_0804CC5A:
	adds r0, r5, #0
	bl FUN_0804bc10
	cmp r0, #0
	beq _0804CC72
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
	movs r0, #1
	strb r0, [r6]
_0804CC72:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cc7c
FUN_0804cc7c: @ 0x0804CC7C
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CC90
	movs r0, #0
	strb r0, [r1]
	bl rfu_LMAN_powerDownRFU
_0804CC90:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804cc98
FUN_0804cc98: @ 0x0804CC98
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CCB4
	movs r0, #0
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	bl rfu_LMAN_stopManager
_0804CCB4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804ccbc
FUN_0804ccbc: @ 0x0804CCBC
	push {r4, lr}
	adds r4, r0, #0
	bl rfu_clearAllSlot
	adds r0, r4, #0
	bl FUN_0804ba64
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804ccd0
FUN_0804ccd0: @ 0x0804CCD0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xe7
	ldr r0, _0804CD00 @ =0x03004740
	ldrb r0, [r0, #3]
	lsls r0, r0, #1
	ldrb r1, [r3]
	orrs r0, r1
	movs r4, #0
	strb r0, [r3]
	movs r3, #0x9b
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, r1
	bne _0804CD04
	adds r0, r2, #0
	adds r0, #0xe8
	strb r4, [r0]
	subs r0, #0xb2
	strb r4, [r0]
	b _0804CD14
	.align 2, 0
_0804CD00: .4byte 0x03004740
_0804CD04:
	adds r1, r2, #0
	adds r1, #0xe8
	movs r0, #1
	strb r0, [r1]
	subs r1, #8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804CD14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804cd1c
FUN_0804cd1c: @ 0x0804CD1C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r4
	mov sb, r0
	movs r3, #0
	ldr r1, _0804CD78 @ =0x030057E0
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r2, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #0
	beq _0804CDD4
	adds r5, r4, #0
	adds r5, #0x90
	adds r0, r2, #0
	bl rfu_UNI_clearRecvNewDataFlag
	adds r0, r4, #0
	adds r0, #0xd0
	ldrb r6, [r0]
	adds r1, r6, #1
	adds r2, r4, #0
	adds r2, #0x94
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r3, [r2]
	mov r8, r0
	adds r7, r2, #0
	cmp r1, r3
	bne _0804CD7C
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r7, #0
	bl FUN_0823a790
	b _0804CD94
	.align 2, 0
_0804CD78: .4byte 0x030057E0
_0804CD7C:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r3
	bne _0804CD8A
	adds r1, r4, #0
	adds r1, #0xd4
	b _0804CD8E
_0804CD8A:
	adds r1, r4, #0
	adds r1, #0xd8
_0804CD8E:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CD94:
	ldrb r0, [r7]
	movs r1, #0
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	strb r1, [r5, #1]
	adds r3, r4, #0
	adds r3, #0xec
	adds r2, r4, #0
	adds r2, #0xfa
	movs r4, #1
_0804CDAE:
	mov r6, sb
	ldrb r0, [r6, #2]
	asrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _0804CDC0
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_0804CDC0:
	adds r1, #1
	cmp r1, #4
	ble _0804CDAE
	ldrh r0, [r3]
	movs r1, #0
	strh r0, [r5, #2]
	ldr r0, _0804CDE4 @ =0x0000FFFF
	strh r0, [r3]
	strb r1, [r2]
	movs r3, #1
_0804CDD4:
	adds r0, r3, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804CDE4: .4byte 0x0000FFFF

	thumb_func_start FUN_0804cde8
FUN_0804cde8: @ 0x0804CDE8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804cd1c
	cmp r0, #0
	beq _0804CDFE
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r0, [r0]
	bl rfu_UNI_readySendData
_0804CDFE:
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ce0c
FUN_0804ce0c: @ 0x0804CE0C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xea
	ldr r0, _0804CE38 @ =0x0000FFFF
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	adds r3, r0, #0
	adds r1, #4
	movs r2, #4
_0804CE26:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0804CE26
	pop {r0}
	bx r0
	.align 2, 0
_0804CE38: .4byte 0x0000FFFF

	thumb_func_start FUN_0804ce3c
FUN_0804ce3c: @ 0x0804CE3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sl, r0
	adds r1, r5, #0
	adds r1, #0x3e
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x80
_0804CE5E:
	lsls r2, r4, #2
	movs r1, #2
	lsls r1, r4
	mov r3, sl
	ldrb r0, [r3, #2]
	ands r0, r1
	movs r3, #0xe6
	adds r3, r3, r5
	mov r8, r3
	cmp r0, #0
	beq _0804CEEC
	ldr r0, _0804CEC0 @ =0x030057E0
	adds r0, r2, r0
	ldr r0, [r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #0
	beq _0804CEEC
	ldrb r0, [r3]
	orrs r1, r0
	movs r0, #0
	mov sb, r0
	strb r1, [r3]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl rfu_UNI_clearRecvNewDataFlag
	adds r1, r5, #0
	adds r1, #0xd0
	adds r0, r1, r4
	ldrb r3, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r6]
	adds r7, r1, #0
	cmp r0, r2
	beq _0804CEE6
	adds r0, r3, #0
	cmp r0, r2
	bne _0804CEC4
	adds r1, #4
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r2, sb
	strh r2, [r6, #2]
	b _0804CEE6
	.align 2, 0
_0804CEC0: .4byte 0x030057E0
_0804CEC4:
	cmp r0, r2
	bhs _0804CEDA
	adds r1, r5, #0
	adds r1, #0xdc
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r3, sb
	strh r3, [r6, #2]
	b _0804CEE6
_0804CEDA:
	adds r1, r5, #0
	adds r1, #0xd8
	adds r1, r1, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CEE6:
	adds r1, r7, r4
	ldrb r0, [r6]
	strb r0, [r1]
_0804CEEC:
	adds r6, #4
	adds r4, #1
	cmp r4, #3
	ble _0804CE5E
	mov r0, r8
	ldrb r1, [r0]
	mov r2, sl
	ldrb r0, [r2, #2]
	adds r3, r0, #0
	adds r2, r3, #0
	ands r2, r1
	adds r1, r0, #0
	adds r4, r5, #0
	adds r4, #0xe7
	cmp r2, r1
	bne _0804CF1E
	ldrb r0, [r4]
	ands r3, r0
	cmp r3, r2
	beq _0804CF2A
	adds r1, r5, #0
	adds r1, #0xe4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CF1E:
	ldrb r0, [r4]
	mov r3, sl
	ldrb r1, [r3, #2]
	ands r0, r1
	cmp r0, r1
	bne _0804CF3E
_0804CF2A:
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, r1
	beq _0804CF3E
	adds r1, r5, #0
	adds r1, #0xe5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CF3E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804cf4c
FUN_0804cf4c: @ 0x0804CF4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x70
	movs r1, #0xe7
	adds r1, r1, r5
	mov sb, r1
	ldrb r0, [r1]
	mov r2, r8
	ldrb r1, [r2, #2]
	ands r0, r1
	cmp r0, r1
	bne _0804D044
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r6, [r0]
	cmp r6, #0
	beq _0804CF92
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0804D044
	adds r1, r5, #0
	adds r1, #0x36
	movs r0, #1
	strb r0, [r1]
	b _0804D044
_0804CF92:
	ldrb r0, [r7]
	str r0, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r7, #0
	bl FUN_0823a790
	adds r4, r5, #0
	adds r4, #0x36
	strb r6, [r4]
	str r6, [sp]
	ldr r2, _0804D054 @ =0x05000004
	mov r0, sp
	adds r1, r7, #0
	bl CpuSet
	movs r2, #0
	mov r0, sb
	str r0, [sp, #0xc]
	str r4, [sp, #8]
	adds r6, r5, #0
	adds r6, #0xea
	movs r1, #0xec
	adds r1, r1, r5
	mov ip, r1
	movs r0, #0xe6
	adds r0, r0, r5
	mov sl, r0
	movs r1, #2
	mov sb, r1
	adds r3, r5, #0
	adds r3, #0x82
	adds r4, #0x40
_0804CFD6:
	mov r1, sb
	lsls r1, r2
	mov r5, r8
	ldrb r0, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0804CFE8
	ldrh r0, [r3]
	strh r0, [r4]
_0804CFE8:
	adds r3, #4
	adds r4, #2
	adds r2, #1
	cmp r2, #3
	ble _0804CFD6
	ldrh r0, [r6]
	strh r0, [r7, #4]
	mov r1, ip
	ldrh r0, [r1]
	strh r0, [r6]
	ldr r0, _0804D058 @ =0x0000FFFF
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #2]
	strb r0, [r7, #2]
	movs r0, #1
	strb r0, [r7, #1]
	movs r2, #0
	ldr r3, [sp, #4]
	adds r3, #1
	movs r5, #2
_0804D012:
	mov r0, r8
	ldrb r1, [r0, #2]
	adds r0, r5, #0
	lsls r0, r2
	ands r1, r0
	cmp r1, #0
	beq _0804D026
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
_0804D026:
	adds r2, #1
	cmp r2, #3
	ble _0804D012
	strb r3, [r7]
	movs r1, #1
	ldr r2, [sp, #0xc]
	strb r1, [r2]
	mov r5, sl
	strb r1, [r5]
	mov r2, r8
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0804D044
	ldr r5, [sp, #8]
	strb r1, [r5]
_0804D044:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D054: .4byte 0x05000004
_0804D058: .4byte 0x0000FFFF

	thumb_func_start FUN_0804d05c
FUN_0804d05c: @ 0x0804D05C
	push {r4, r5, lr}
	mov ip, r0
	movs r2, #0x9a
	lsls r2, r2, #1
	add r2, ip
	lsls r1, r1, #0x19
	lsrs r3, r1, #0x18
	movs r1, #0
	ldrb r4, [r2, #2]
	movs r5, #2
_0804D070:
	adds r0, r5, #0
	lsls r0, r1
	ands r0, r4
	ands r0, r3
	cmp r0, #0
	beq _0804D086
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0804D086
	subs r0, #1
	strb r0, [r2, #3]
_0804D086:
	adds r1, #1
	cmp r1, #4
	ble _0804D070
	ldrb r1, [r2, #2]
	bics r1, r3
	strb r1, [r2, #2]
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, r1
	bne _0804D0A6
	mov r1, ip
	adds r1, #0xe8
	movs r0, #0
	strb r0, [r1]
_0804D0A6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804d0ac
FUN_0804d0ac: @ 0x0804D0AC
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804D0E4 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	bne _0804D0BE
	b _0804D20A
_0804D0BE:
	cmp r3, #0x41
	bne _0804D0C4
	b _0804D20A
_0804D0C4:
	cmp r3, #0x41
	bgt _0804D0E8
	cmp r3, #0x30
	beq _0804D158
	cmp r3, #0x30
	bgt _0804D0D2
	b _0804D20A
_0804D0D2:
	cmp r3, #0x32
	beq _0804D144
	cmp r3, #0x32
	blt _0804D130
	cmp r3, #0x33
	beq _0804D158
	cmp r3, #0x40
	beq _0804D19C
	b _0804D20A
	.align 2, 0
_0804D0E4: .4byte 0x03002B58
_0804D0E8:
	cmp r3, #0x50
	beq _0804D118
	cmp r3, #0x50
	bgt _0804D100
	cmp r3, #0x43
	bne _0804D0F6
	b _0804D20A
_0804D0F6:
	cmp r3, #0x43
	blt _0804D1D0
	cmp r3, #0x44
	beq _0804D1D8
	b _0804D20A
_0804D100:
	cmp r3, #0xf1
	beq _0804D1EC
	cmp r3, #0xf1
	bgt _0804D10E
	cmp r3, #0xf0
	beq _0804D1EC
	b _0804D20A
_0804D10E:
	cmp r1, #0xf2
	beq _0804D1EC
	cmp r1, #0xff
	beq _0804D1EC
	b _0804D20A
_0804D118:
	adds r0, r4, #0
	bl FUN_0804ccd0
	adds r0, r4, #0
	bl FUN_0804ce3c
	ldr r1, _0804D12C @ =0x030000DC
	movs r0, #0
	strb r0, [r1]
	b _0804D20A
	.align 2, 0
_0804D12C: .4byte 0x030000DC
_0804D130:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D140 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804D20A
	.align 2, 0
_0804D140: .4byte 0x03004740
_0804D144:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D154 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804D20A
	.align 2, 0
_0804D154: .4byte 0x03004740
_0804D158:
	adds r3, r4, #0
	adds r3, #0x25
	ldr r2, _0804D194 @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	movs r6, #0
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0xe9
	movs r0, #1
	strb r0, [r1]
	ldrb r1, [r2, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D198 @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D20A
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r0, #0x1d
	strb r6, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r6, [r4, #0x44]
	b _0804D1C0
	.align 2, 0
_0804D194: .4byte 0x03004740
_0804D198: .4byte 0x00000137
_0804D19C:
	ldr r0, _0804D1C8 @ =0x03004740
	ldrb r1, [r0, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D1CC @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D20A
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1d
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
_0804D1C0:
	adds r0, r4, #0
	adds r0, #0x32
	strb r5, [r0]
	b _0804D20A
	.align 2, 0
_0804D1C8: .4byte 0x03004740
_0804D1CC: .4byte 0x00000137
_0804D1D0:
	adds r0, r4, #0
	bl FUN_0804ba64
	b _0804D20A
_0804D1D8:
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	b _0804D20A
_0804D1EC:
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r4, #0x1c]
	movs r2, #0
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0804D210 @ =0x030000DC
	strb r2, [r0]
_0804D20A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D210: .4byte 0x030000DC

	thumb_func_start FUN_0804d214
FUN_0804d214: @ 0x0804D214
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804D244 @ =0x03002B58
	ldr r5, [r0]
	cmp r5, #0
	beq _0804D2FE
	cmp r3, #0x41
	bgt _0804D248
	cmp r3, #0x40
	bge _0804D2FE
	cmp r3, #0x30
	beq _0804D2A0
	cmp r3, #0x30
	ble _0804D2FE
	cmp r3, #0x32
	beq _0804D28C
	cmp r3, #0x32
	blt _0804D276
	cmp r3, #0x33
	beq _0804D2A0
	b _0804D2FE
	.align 2, 0
_0804D244: .4byte 0x03002B58
_0804D248:
	cmp r3, #0x50
	beq _0804D26E
	cmp r3, #0x50
	bgt _0804D256
	cmp r3, #0x42
	beq _0804D2C4
	b _0804D2FE
_0804D256:
	cmp r3, #0xf1
	beq _0804D2E6
	cmp r3, #0xf1
	bgt _0804D264
	cmp r3, #0xf0
	beq _0804D2CC
	b _0804D2FE
_0804D264:
	cmp r1, #0xf2
	beq _0804D2E6
	cmp r1, #0xff
	beq _0804D2E6
	b _0804D2FE
_0804D26E:
	adds r0, r5, #0
	bl FUN_0804cde8
	b _0804D2FE
_0804D276:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804D288 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804D2FE
	.align 2, 0
_0804D288: .4byte 0x03004740
_0804D28C:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804D29C @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804D2FE
	.align 2, 0
_0804D29C: .4byte 0x03004740
_0804D2A0:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804D2C0 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	movs r4, #0
	strb r0, [r2]
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r0, #0x1d
	strb r4, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r4, [r5, #0x44]
	b _0804D2F6
	.align 2, 0
_0804D2C0: .4byte 0x03004740
_0804D2C4:
	adds r0, r5, #0
	bl FUN_0804ba64
	b _0804D2FE
_0804D2CC:
	ldr r0, _0804D304 @ =0x03004740
	ldrh r1, [r0, #0x14]
	adds r2, r0, #0
	cmp r1, #0x30
	bne _0804D2E0
	ldrh r0, [r2, #0x16]
	cmp r0, #3
	bne _0804D2E0
	movs r0, #0
	strh r0, [r2, #0x16]
_0804D2E0:
	ldrh r0, [r2, #0x16]
	cmp r0, #0
	beq _0804D2FE
_0804D2E6:
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
_0804D2F6:
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804D2FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D304: .4byte 0x03004740

	thumb_func_start FUN_0804d308
FUN_0804d308: @ 0x0804D308
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _0804D34C @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	beq _0804D364
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r4, r0
	mov r0, sp
	bl rfu_UNI_PARENT_getDRAC_ACK
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0804D360
	adds r2, r4, #0
	adds r2, #0xe7
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, r1
	bne _0804D350
	adds r0, r4, #0
	adds r0, #0xe8
	strb r3, [r0]
	subs r0, #0xb2
	strb r3, [r0]
	b _0804D360
	.align 2, 0
_0804D34C: .4byte 0x03002B58
_0804D350:
	adds r1, r4, #0
	adds r1, #0xe8
	movs r0, #1
	strb r0, [r1]
	subs r1, #8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804D360:
	bl rfu_REQ_recvData
_0804D364:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804d36c
FUN_0804d36c: @ 0x0804D36C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0804D388 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804D390
	cmp r1, #0x27
	bne _0804D38C
	bl rfu_REQ_changeMasterSlave
	bl rfu_waitREQComplete
	b _0804D390
	.align 2, 0
_0804D388: .4byte 0x03002B58
_0804D38C:
	bl rfu_REQ_recvData
_0804D390:
	pop {r0}
	bx r0

	thumb_func_start FUN_0804d394
FUN_0804d394: @ 0x0804D394
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r7, r6, r0
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	strb r4, [r6, #0x1f]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_0823a76c
	adds r5, r6, #0
	adds r5, #0x70
	adds r0, r5, #0
	movs r1, #0x10
	bl ClearMemory
	adds r0, r6, #0
	adds r0, #0x80
	movs r1, #0x10
	bl ClearMemory
	adds r0, r6, #0
	bl FUN_0804ce0c
	adds r0, r6, #0
	adds r0, #0xe8
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	subs r0, #2
	movs r2, #1
	movs r1, #1
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	ldrb r0, [r7, #2]
	adds r3, r6, #0
	adds r3, #0x37
	strb r0, [r3]
	ldr r0, _0804D51C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #2]
	lsls r0, r0, #1
	orrs r0, r2
	strb r0, [r7, #2]
	adds r2, r6, #0
	adds r2, #0x72
	strb r0, [r2]
	strb r1, [r5]
	adds r0, r6, #0
	adds r0, #0x71
	strb r1, [r0]
	movs r5, #0
	movs r3, #2
	adds r2, r0, #0
_0804D416:
	ldrb r1, [r7, #2]
	adds r0, r3, #0
	lsls r0, r5
	ands r1, r0
	cmp r1, #0
	beq _0804D428
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
_0804D428:
	adds r5, #1
	cmp r5, #3
	ble _0804D416
	adds r1, r6, #0
	adds r1, #0x36
	movs r0, #1
	strb r0, [r1]
	movs r5, #0
	adds r2, r6, #0
	adds r2, #0x70
	str r2, [sp]
	movs r4, #0xe0
	adds r4, r4, r6
	mov r8, r4
	movs r0, #0xe4
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0xe5
	adds r1, r1, r6
	mov sl, r1
	subs r2, #0x3e
	str r2, [sp, #4]
	movs r4, #0xd0
	adds r4, r4, r6
	mov ip, r4
	movs r1, #0
	adds r0, r6, #0
	adds r0, #0xd4
	str r0, [sp, #8]
	adds r3, r6, #0
	adds r3, #0xd8
	adds r2, #0xaa
_0804D468:
	mov r4, ip
	adds r0, r4, r5
	strb r1, [r0]
	ldr r4, [sp, #8]
	adds r0, r4, r5
	strb r1, [r0]
	adds r0, r3, r5
	strb r1, [r0]
	adds r0, r2, r5
	strb r1, [r0]
	adds r5, #1
	cmp r5, #3
	ble _0804D468
	movs r0, #0
	mov r1, r8
	str r0, [r1]
	mov r2, sb
	strb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r0, _0804D520 @ =FUN_0804d0ac
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804D524 @ =FUN_0804d308
	bl rfu_LMAN_setMSCCallback
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x80
_0804D4A2:
	ldrb r1, [r7, #2]
	movs r0, #2
	mov r8, r0
	lsls r0, r5
	ands r1, r0
	cmp r1, #0
	beq _0804D4BE
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x10
	adds r2, r4, #0
	movs r3, #4
	bl rfu_setRecvBuffer
_0804D4BE:
	adds r4, #4
	adds r5, #1
	cmp r5, #3
	ble _0804D4A2
	ldrb r0, [r7, #2]
	lsrs r0, r0, #1
	ldr r1, [sp]
	movs r2, #0x10
	bl rfu_UNI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804D528
	movs r5, #0
	ldrb r1, [r7, #2]
	adds r0, r1, #0
	mov r2, r8
	ands r0, r2
	adds r2, r6, #0
	adds r2, #0x20
	adds r7, r6, #0
	adds r7, #0x34
	cmp r0, #0
	bne _0804D500
	movs r3, #2
_0804D4F0:
	adds r5, #1
	cmp r5, #3
	bgt _0804D500
	adds r0, r3, #0
	lsls r0, r5
	ands r0, r1
	cmp r0, #0
	beq _0804D4F0
_0804D500:
	movs r4, #0
	strb r5, [r2]
	ldrb r0, [r2]
	bl rfu_UNI_readySendData
	movs r1, #1
	strb r1, [r7]
	movs r0, #0x13
	strb r4, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r4, [r6, #0x44]
	ldr r4, [sp, #4]
	strb r1, [r4]
	b _0804D538
	.align 2, 0
_0804D51C: .4byte 0x03005800
_0804D520: .4byte FUN_0804d0ac
_0804D524: .4byte FUN_0804d308
_0804D528:
	movs r1, #0x1b
	movs r0, #0
	strb r0, [r6, #0x1c]
	strh r1, [r6, #0x38]
	str r0, [r6, #0x44]
	movs r0, #1
	ldr r1, [sp, #4]
	strb r0, [r1]
_0804D538:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804d548
FUN_0804d548: @ 0x0804D548
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp]
	movs r0, #0
	bl FUN_0822b644
	movs r3, #0
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _0804D650 @ =0x03005800
	ldr r0, [r2]
	adds r0, #0x94
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0804D596
	adds r4, r2, #0
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r2, r6, r0
_0804D582:
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	bgt _0804D596
	ldr r0, [r4]
	adds r0, #0x94
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _0804D582
_0804D596:
	strb r3, [r6, #0x1f]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_0823a76c
	adds r5, r6, #0
	adds r5, #0x90
	adds r0, r5, #0
	movs r1, #4
	bl ClearMemory
	adds r4, r6, #0
	adds r4, #0x94
	adds r0, r4, #0
	movs r1, #0x10
	bl ClearMemory
	adds r0, r6, #0
	bl FUN_0804ce0c
	movs r3, #0
	mov sb, r5
	mov sl, r4
	movs r2, #0x37
	adds r2, r2, r6
	mov ip, r2
	movs r0, #0x21
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0x32
	str r1, [sp, #4]
	adds r7, r6, #0
	adds r7, #0xd0
	movs r1, #0
	adds r5, #0x44
	adds r4, #0x44
	adds r2, r6, #0
	adds r2, #0xdc
_0804D5E6:
	adds r0, r7, r3
	strb r1, [r0]
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
	cmp r3, #3
	ble _0804D5E6
	ldr r2, [sp]
	ldrb r0, [r2, #2]
	movs r7, #0
	mov r1, ip
	strb r0, [r1]
	mov r2, sb
	strb r7, [r2]
	ldr r0, _0804D654 @ =FUN_0804d214
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804D658 @ =FUN_0804d36c
	bl rfu_LMAN_setMSCCallback
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #0x10
	mov r2, sl
	movs r3, #0x10
	bl rfu_setRecvBuffer
	movs r4, #1
	adds r0, r4, #0
	mov r1, r8
	ldrb r1, [r1]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, sb
	movs r2, #4
	bl rfu_UNI_setSendData
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0804D65C
	movs r0, #0x1b
	strb r7, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r7, [r6, #0x44]
	ldr r2, [sp, #4]
	strb r4, [r2]
	b _0804D66E
	.align 2, 0
_0804D650: .4byte 0x03005800
_0804D654: .4byte FUN_0804d214
_0804D658: .4byte FUN_0804d36c
_0804D65C:
	adds r0, r6, #0
	adds r0, #0x34
	strb r4, [r0]
	movs r0, #0x14
	strb r1, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r1, [r6, #0x44]
	ldr r0, [sp, #4]
	strb r4, [r0]
_0804D66E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804d680
FUN_0804d680: @ 0x0804D680
	push {lr}
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804D68E
	movs r0, #0
	b _0804D694
_0804D68E:
	bl rfu_clearAllSlot
	movs r0, #1
_0804D694:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804d698
FUN_0804d698: @ 0x0804D698
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804D6AE
	movs r0, #0
	strb r0, [r1]
	bl FUN_0822b644
_0804D6AE:
	ldr r0, _0804D6CC @ =0x03004508
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r1, r0
	adds r0, r4, #0
	bl FUN_0804bb68
	adds r2, r4, #0
	adds r2, #0x31
	movs r1, #1
	strb r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804D6CC: .4byte 0x03004508

	thumb_func_start FUN_0804d6d0
FUN_0804d6d0: @ 0x0804D6D0
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804D6E6
	movs r0, #0
	strb r0, [r1]
	bl FUN_0822b644
_0804D6E6:
	ldr r0, _0804D704 @ =0x03004508
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r1, r0
	adds r0, r4, #0
	bl FUN_0804bb68
	adds r2, r4, #0
	adds r2, #0x31
	movs r1, #1
	strb r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804D704: .4byte 0x03004508

	thumb_func_start FUN_0804d708
FUN_0804d708: @ 0x0804D708
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804D740 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	bne _0804D71A
	b _0804D850
_0804D71A:
	cmp r3, #0x41
	bne _0804D720
	b _0804D850
_0804D720:
	cmp r3, #0x41
	bgt _0804D744
	cmp r3, #0x30
	beq _0804D7A0
	cmp r3, #0x30
	bgt _0804D72E
	b _0804D850
_0804D72E:
	cmp r3, #0x32
	beq _0804D78C
	cmp r3, #0x32
	blt _0804D776
	cmp r3, #0x33
	beq _0804D7A0
	cmp r3, #0x40
	beq _0804D7E4
	b _0804D850
	.align 2, 0
_0804D740: .4byte 0x03002B58
_0804D744:
	cmp r3, #0x50
	bne _0804D74A
	b _0804D84A
_0804D74A:
	cmp r3, #0x50
	bgt _0804D75E
	cmp r3, #0x43
	bne _0804D754
	b _0804D850
_0804D754:
	cmp r3, #0x43
	blt _0804D818
	cmp r3, #0x44
	beq _0804D820
	b _0804D850
_0804D75E:
	cmp r3, #0xf1
	beq _0804D832
	cmp r3, #0xf1
	bgt _0804D76C
	cmp r3, #0xf0
	beq _0804D832
	b _0804D850
_0804D76C:
	cmp r1, #0xf2
	beq _0804D832
	cmp r1, #0xff
	beq _0804D832
	b _0804D850
_0804D776:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D788 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804D850
	.align 2, 0
_0804D788: .4byte 0x03004740
_0804D78C:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D79C @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804D850
	.align 2, 0
_0804D79C: .4byte 0x03004740
_0804D7A0:
	adds r3, r4, #0
	adds r3, #0x25
	ldr r2, _0804D7DC @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	movs r6, #0
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0xe9
	movs r0, #1
	strb r0, [r1]
	ldrb r1, [r2, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D7E0 @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D850
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r0, #0x1d
	strb r6, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r6, [r4, #0x44]
	b _0804D808
	.align 2, 0
_0804D7DC: .4byte 0x03004740
_0804D7E0: .4byte 0x00000137
_0804D7E4:
	ldr r0, _0804D810 @ =0x03004740
	ldrb r1, [r0, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D814 @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D850
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1d
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
_0804D808:
	adds r0, r4, #0
	adds r0, #0x32
	strb r5, [r0]
	b _0804D850
	.align 2, 0
_0804D810: .4byte 0x03004740
_0804D814: .4byte 0x00000137
_0804D818:
	adds r0, r4, #0
	bl FUN_0804ba64
	b _0804D850
_0804D820:
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	b _0804D84E
_0804D832:
	ldrh r0, [r4, #0x38]
	cmp r0, #0x1c
	beq _0804D84A
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804D84A:
	ldr r1, _0804D858 @ =0x030000DC
	movs r0, #0
_0804D84E:
	strb r0, [r1]
_0804D850:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D858: .4byte 0x030000DC

	thumb_func_start FUN_0804d85c
FUN_0804d85c: @ 0x0804D85C
	push {lr}
	bl rfu_REQ_recvData
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804d868
FUN_0804d868: @ 0x0804D868
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r0, #0
	bl FUN_0822b644
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_0823a76c
	adds r0, r5, #0
	adds r0, #0xb8
	movs r1, #0xc
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0xc4
	movs r1, #0xc
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r1, [r0]
	movs r0, #8
	bl rfu_clearSlot
	ldr r0, _0804D904 @ =FUN_0804d708
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804D908 @ =FUN_0804d85c
	bl rfu_LMAN_setMSCCallback
	movs r4, #0
_0804D8B0:
	ldrb r1, [r7, #2]
	movs r6, #2
	adds r0, r6, #0
	lsls r0, r4
	ands r1, r0
	cmp r1, #0
	beq _0804D8CE
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x20
	adds r2, r5, #0
	adds r2, #0xc4
	movs r3, #0xc
	bl rfu_setRecvBuffer
_0804D8CE:
	adds r4, #1
	cmp r4, #3
	ble _0804D8B0
	adds r0, r5, #0
	adds r0, #0x34
	movs r1, #0
	strb r6, [r0]
	movs r0, #0x17
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x4c]
	cmp r0, #0
	beq _0804D8F8
	movs r1, #0
	bl Script_ExecById
_0804D8F8:
	movs r0, #4
	bl sound_fadeout_08240440
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804D904: .4byte FUN_0804d708
_0804D908: .4byte FUN_0804d85c

	thumb_func_start FUN_0804d90c
FUN_0804d90c: @ 0x0804D90C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrh r1, [r5, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804D996
	ldr r7, _0804D988 @ =0x03005800
	ldr r0, [r7]
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0804D996
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0804D99A
	adds r4, r5, #0
	adds r4, #0x20
	ldrb r1, [r4]
	movs r0, #4
	bl rfu_clearSlot
	adds r0, r6, #0
	ldrb r1, [r4]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r5, #0
	adds r2, #0xb8
	movs r1, #0xf
	movs r3, #0xc
	bl rfu_NI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804D990
	movs r1, #0
	ldr r0, [r7]
	ldrb r0, [r0, #2]
	ands r0, r6
	cmp r0, #0
	bne _0804D978
	adds r3, r7, #0
	movs r2, #1
_0804D966:
	adds r1, #1
	cmp r1, #3
	bgt _0804D978
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _0804D966
_0804D978:
	strb r1, [r4]
	ldrh r0, [r5, #0x22]
	ldr r1, _0804D98C @ =0x0000FFFE
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strh r1, [r5, #0x22]
	b _0804D99A
	.align 2, 0
_0804D988: .4byte 0x03005800
_0804D98C: .4byte 0x0000FFFE
_0804D990:
	movs r0, #2
	bl FUN_0804e584
_0804D996:
	movs r0, #0
	b _0804D99C
_0804D99A:
	movs r0, #1
_0804D99C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804d9a4
FUN_0804d9a4: @ 0x0804D9A4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r6, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804DA48
	ldr r7, _0804DA00 @ =0x030057F0
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0x26
	bne _0804DA08
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804D9DC
	adds r0, r4, #0
	adds r0, #0xb8
	bl _call_via_r1
_0804D9DC:
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r3, [r0]
	ldrb r0, [r2, #0x1a]
	adds r6, r0, #0
	eors r6, r3
	movs r0, #4
	bl rfu_clearSlot
	ldrh r1, [r4, #0x22]
	ldr r0, _0804DA04 @ =0x0000FFFD
	ands r0, r1
	b _0804DA38
	.align 2, 0
_0804DA00: .4byte 0x030057F0
_0804DA04: .4byte 0x0000FFFD
_0804DA08:
	cmp r0, #0x27
	bne _0804DA3A
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DA1C
	bl _call_via_r0
_0804DA1C:
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r3, [r0]
	ldrb r0, [r2, #0x1a]
	adds r6, r0, #0
	eors r6, r3
	movs r0, #4
	bl rfu_clearSlot
	movs r0, #0
_0804DA38:
	strh r0, [r4, #0x22]
_0804DA3A:
	cmp r6, #0
	beq _0804DA48
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	orrs r6, r0
	strb r6, [r1]
_0804DA48:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804da50
FUN_0804da50: @ 0x0804DA50
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x32
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804DA62
	movs r0, #0
	strb r0, [r3]
_0804DA62:
	movs r1, #0x17
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r1, [r2, #0x38]
	str r0, [r2, #0x44]
	movs r0, #1
	strb r0, [r3]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804da78
FUN_0804da78: @ 0x0804DA78
	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DA8A
	movs r0, #0
	strb r0, [r1]
_0804DA8A:
	ldr r0, _0804DABC @ =0x030057F0
	adds r4, r2, #0
	adds r4, #0x20
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldrh r0, [r0, #0x34]
	cmp r0, #0x46
	bne _0804DAC0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804DAB2
	adds r0, r2, #0
	adds r0, #0xc4
	bl _call_via_r1
_0804DAB2:
	ldrb r1, [r4]
	movs r0, #8
	bl rfu_clearSlot
	b _0804DADA
	.align 2, 0
_0804DABC: .4byte 0x030057F0
_0804DAC0:
	subs r0, #0x47
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0804DADA
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DADA
	bl _call_via_r0
_0804DADA:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804dae4
FUN_0804dae4: @ 0x0804DAE4
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DAF4
	movs r0, #0
	strb r0, [r1]
_0804DAF4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804dafc
FUN_0804dafc: @ 0x0804DAFC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804DB2C @ =0x03002B58
	ldr r2, [r0]
	cmp r2, #0
	beq _0804DBC4
	cmp r3, #0x41
	bgt _0804DB30
	cmp r3, #0x40
	bge _0804DBC4
	cmp r3, #0x30
	beq _0804DB84
	cmp r3, #0x30
	ble _0804DBC4
	cmp r3, #0x32
	beq _0804DB70
	cmp r3, #0x32
	blt _0804DB5E
	cmp r3, #0x33
	beq _0804DB84
	b _0804DBC4
	.align 2, 0
_0804DB2C: .4byte 0x03002B58
_0804DB30:
	cmp r3, #0x50
	beq _0804DB56
	cmp r3, #0x50
	bgt _0804DB3E
	cmp r3, #0x42
	beq _0804DBA4
	b _0804DBC4
_0804DB3E:
	cmp r3, #0xf1
	beq _0804DBAC
	cmp r3, #0xf1
	bgt _0804DB4C
	cmp r3, #0xf0
	beq _0804DBAC
	b _0804DBC4
_0804DB4C:
	cmp r1, #0xf2
	beq _0804DBAC
	cmp r1, #0xff
	beq _0804DBAC
	b _0804DBC4
_0804DB56:
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	b _0804DBC4
_0804DB5E:
	adds r2, #0x25
	ldr r0, _0804DB6C @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804DBC4
	.align 2, 0
_0804DB6C: .4byte 0x03004740
_0804DB70:
	adds r2, #0x25
	ldr r0, _0804DB80 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804DBC4
	.align 2, 0
_0804DB80: .4byte 0x03004740
_0804DB84:
	adds r3, r2, #0
	adds r3, #0x25
	ldr r0, _0804DBA0 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	movs r1, #0
	strb r0, [r3]
	movs r0, #0x1d
	strb r1, [r2, #0x1c]
	strh r0, [r2, #0x38]
	str r1, [r2, #0x44]
	b _0804DBBC
	.align 2, 0
_0804DBA0: .4byte 0x03004740
_0804DBA4:
	adds r0, r2, #0
	bl FUN_0804ba64
	b _0804DBC4
_0804DBAC:
	ldrh r0, [r2, #0x38]
	cmp r0, #0x1c
	beq _0804DBC4
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r1, [r2, #0x38]
	str r0, [r2, #0x44]
_0804DBBC:
	adds r1, r2, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804DBC4:
	pop {r0}
	bx r0

	thumb_func_start FUN_0804dbc8
FUN_0804dbc8: @ 0x0804DBC8
	push {lr}
	ldr r0, _0804DBDC @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DBD6
	bl rfu_REQ_recvData
_0804DBD6:
	pop {r0}
	bx r0
	.align 2, 0
_0804DBDC: .4byte 0x03002B58

	thumb_func_start FUN_0804dbe0
FUN_0804dbe0: @ 0x0804DBE0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	bl FUN_0822b644
	movs r3, #0
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r2, _0804DC84 @ =0x03005800
	ldr r0, [r2]
	adds r0, #0x94
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0804DC1C
	adds r4, r2, #0
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r2, r6, r1
_0804DC08:
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	bgt _0804DC1C
	ldr r0, [r4]
	adds r0, #0x94
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bne _0804DC08
_0804DC1C:
	movs r5, #0
	strb r3, [r6, #0x1f]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r6, r1
	bl FUN_0823a76c
	adds r0, r6, #0
	adds r0, #0xb8
	movs r1, #0xc
	bl ClearMemory
	adds r4, r6, #0
	adds r4, #0xc4
	adds r0, r4, #0
	movs r1, #0xc
	bl ClearMemory
	ldr r0, _0804DC88 @ =FUN_0804dafc
	bl rfu_LMAN_setLMANCallback
	ldr r0, _0804DC8C @ =FUN_0804dbc8
	bl rfu_LMAN_setMSCCallback
	adds r0, r6, #0
	adds r0, #0x21
	ldrb r1, [r0]
	movs r0, #0x20
	adds r2, r4, #0
	movs r3, #0xc
	bl rfu_setRecvBuffer
	adds r1, r6, #0
	adds r1, #0x34
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x18
	strb r5, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r5, [r6, #0x44]
	subs r1, #2
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x4c]
	cmp r0, #0
	beq _0804DC7E
	movs r1, #0
	bl Script_ExecById
_0804DC7E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804DC84: .4byte 0x03005800
_0804DC88: .4byte FUN_0804dafc
_0804DC8C: .4byte FUN_0804dbc8

	thumb_func_start FUN_0804dc90
FUN_0804dc90: @ 0x0804DC90
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804DD72
	ldr r0, _0804DCDC @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0804DD72
	ldr r1, _0804DCE0 @ =0x030057F0
	adds r2, r4, #0
	adds r2, #0x21
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #0x34]
	adds r5, r2, #0
	cmp r0, #0x46
	bne _0804DCE4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804DCD2
	adds r0, r4, #0
	adds r0, #0xc4
	bl _call_via_r1
_0804DCD2:
	ldrb r1, [r5]
	movs r0, #8
	bl rfu_clearSlot
	b _0804DCFE
	.align 2, 0
_0804DCDC: .4byte 0x03005800
_0804DCE0: .4byte 0x030057F0
_0804DCE4:
	subs r0, #0x47
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0804DCFE
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DCFE
	bl _call_via_r0
_0804DCFE:
	ldrh r1, [r4, #0x22]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0804DD76
	ldrb r1, [r5]
	movs r0, #4
	bl rfu_clearSlot
	adds r0, r6, #0
	ldrb r1, [r5]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r4, #0
	adds r2, #0xb8
	movs r1, #0xe
	movs r3, #0xc
	bl rfu_NI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804DD6C
	movs r1, #0
	ldr r2, _0804DD64 @ =0x03005800
	ldr r0, [r2]
	ldrb r0, [r0, #2]
	ands r0, r6
	cmp r0, #0
	bne _0804DD52
	adds r3, r2, #0
	movs r2, #1
_0804DD40:
	adds r1, #1
	cmp r1, #3
	bgt _0804DD52
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _0804DD40
_0804DD52:
	strb r1, [r5]
	ldrh r0, [r4, #0x22]
	ldr r1, _0804DD68 @ =0x0000FFFE
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strh r1, [r4, #0x22]
	b _0804DD76
	.align 2, 0
_0804DD64: .4byte 0x03005800
_0804DD68: .4byte 0x0000FFFE
_0804DD6C:
	movs r0, #2
	bl FUN_0804e584
_0804DD72:
	movs r0, #0
	b _0804DD78
_0804DD76:
	movs r0, #1
_0804DD78:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804dd80
FUN_0804dd80: @ 0x0804DD80
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r6, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804DE10
	ldr r7, _0804DDC8 @ =0x030057F0
	adds r5, r4, #0
	adds r5, #0x21
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0x26
	bne _0804DDD0
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804DDB8
	adds r0, r4, #0
	adds r0, #0xb8
	bl _call_via_r1
_0804DDB8:
	ldrb r1, [r5]
	movs r0, #4
	bl rfu_clearSlot
	ldrh r1, [r4, #0x22]
	ldr r0, _0804DDCC @ =0x0000FFFD
	ands r0, r1
	b _0804DE00
	.align 2, 0
_0804DDC8: .4byte 0x030057F0
_0804DDCC: .4byte 0x0000FFFD
_0804DDD0:
	cmp r0, #0x27
	bne _0804DE02
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DDE4
	bl _call_via_r0
_0804DDE4:
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r3, [r0]
	ldrb r0, [r2, #0x1a]
	adds r6, r0, #0
	eors r6, r3
	movs r0, #4
	bl rfu_clearSlot
	movs r0, #0
_0804DE00:
	strh r0, [r4, #0x22]
_0804DE02:
	cmp r6, #0
	beq _0804DE10
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	orrs r6, r0
	strb r6, [r1]
_0804DE10:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804de18
FUN_0804de18: @ 0x0804DE18
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x32
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804DE2A
	movs r0, #0
	strb r0, [r3]
_0804DE2A:
	movs r1, #0x17
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r1, [r2, #0x38]
	str r0, [r2, #0x44]
	movs r0, #1
	strb r0, [r3]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804de40
FUN_0804de40: @ 0x0804DE40
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DE50
	movs r0, #0
	strb r0, [r1]
_0804DE50:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804de58
FUN_0804de58: @ 0x0804DE58
	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DE68
	movs r0, #0
	strb r0, [r1]
_0804DE68:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804de70
FUN_0804de70: @ 0x0804DE70
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x18]
	cmp r0, #0
	beq _0804DEB8
	ldr r1, _0804DEDC @ =0x030000DC
	ldrb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x35
	cmp r0, #1
	bne _0804DE8C
_0804DE86:
	ldrb r0, [r1]
	cmp r0, #1
	beq _0804DE86
_0804DE8C:
	movs r0, #0
	bl rfu_LMAN_manager_entity
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804DEA4
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	movs r0, #0
	strb r0, [r4]
_0804DEA4:
	ldr r0, _0804DEE0 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0]
	cmp r1, #1
	bne _0804DEB8
	ldr r0, _0804DEDC @ =0x030000DC
	strb r1, [r0]
	movs r0, #1
	bl rfu_REQ_sendData
_0804DEB8:
	adds r0, r5, #0
	bl FUN_0804bdd4
	adds r0, r5, #0
	bl FUN_0804bed4
	ldr r0, _0804DEE4 @ =0x085AB5E0
	ldrh r1, [r5, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804DEDC: .4byte 0x030000DC
_0804DEE0: .4byte 0x03005800
_0804DEE4: .4byte 0x085AB5E0

	thumb_func_start FUN_0804dee8
FUN_0804dee8: @ 0x0804DEE8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _0804DEFE
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #0
	strb r0, [r1]
	bl rfu_LMAN_manager_entity
_0804DEFE:
	ldr r0, _0804DF14 @ =0x085AB5E0
	ldrh r1, [r4, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804DF14: .4byte 0x085AB5E0

	thumb_func_start FUN_0804df18
FUN_0804df18: @ 0x0804DF18
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0804DFA0 @ =0x030000DC
_0804DF26:
	ldrb r0, [r1]
	cmp r0, #1
	beq _0804DF26
	movs r0, #0
	bl rfu_LMAN_manager_entity
	adds r3, r4, #0
	adds r3, #0xe9
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804DF56
	adds r2, r4, #0
	adds r2, #0xe8
	ldrb r0, [r2]
	cmp r0, #0
	beq _0804DF56
	movs r1, #0
	strb r1, [r2]
	subs r2, #1
	movs r0, #1
	strb r0, [r2]
	subs r2, #1
	strb r0, [r2]
	strb r1, [r3]
_0804DF56:
	adds r0, r4, #0
	bl FUN_0804bb70
	adds r0, r4, #0
	bl FUN_0804cf4c
	ldr r0, _0804DFA4 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0804DFAC
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804DFAC
	ldr r1, _0804DFA0 @ =0x030000DC
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804DFA8
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x70
	movs r2, #0x10
	bl rfu_UNI_changeAndReadySendData
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	b _0804DFAC
	.align 2, 0
_0804DFA0: .4byte 0x030000DC
_0804DFA4: .4byte 0x03005800
_0804DFA8:
	bl rfu_REQ_PARENT_resumeRetransmitAndChange
_0804DFAC:
	adds r0, r4, #0
	bl FUN_0804bb98
	ldr r0, _0804DFF4 @ =0x085AB5E0
	ldrh r1, [r4, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0x31
	ldrb r2, [r1]
	cmp r2, #0
	beq _0804E01A
	ldr r2, _0804DFF8 @ =0x030044D0
	movs r1, #1
	str r1, [r2]
	movs r5, #0
	movs r1, #0x80
	lsls r1, r1, #6
	mov ip, r1
	ldr r7, _0804DFFC @ =0x00000FFF
	ldr r3, _0804E000 @ =0x03004510
	ldr r1, _0804E004 @ =0x0000FFFF
	adds r6, r1, #0
	adds r4, #0xf0
_0804DFE4:
	ldrh r2, [r4]
	mov r1, ip
	ands r1, r2
	cmp r1, #0
	beq _0804E008
	adds r1, r7, #0
	ands r1, r2
	b _0804E00C
	.align 2, 0
_0804DFF4: .4byte 0x085AB5E0
_0804DFF8: .4byte 0x030044D0
_0804DFFC: .4byte 0x00000FFF
_0804E000: .4byte 0x03004510
_0804E004: .4byte 0x0000FFFF
_0804E008:
	ldrh r1, [r3]
	orrs r1, r6
_0804E00C:
	strh r1, [r3]
	adds r3, #2
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _0804DFE4
	b _0804E01E
_0804E01A:
	ldr r1, _0804E024 @ =0x030044D0
	str r2, [r1]
_0804E01E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804E024: .4byte 0x030044D0

	thumb_func_start FUN_0804e028
FUN_0804e028: @ 0x0804E028
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x31
	movs r0, #0
	strb r0, [r5]
	bl rfu_LMAN_manager_entity
	bl rfu_getMasterSlave
	adds r0, r4, #0
	bl FUN_0804bb70
	adds r0, r4, #0
	bl FUN_0804bb98
	ldr r1, _0804E088 @ =0x085AB5E0
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r2, [r5]
	cmp r2, #0
	beq _0804E0AE
	ldr r2, _0804E08C @ =0x030044D0
	movs r1, #1
	str r1, [r2]
	movs r5, #0
	movs r1, #0x80
	lsls r1, r1, #6
	mov ip, r1
	ldr r7, _0804E090 @ =0x00000FFF
	ldr r3, _0804E094 @ =0x03004510
	ldr r1, _0804E098 @ =0x0000FFFF
	adds r6, r1, #0
	adds r4, #0xf0
_0804E076:
	ldrh r2, [r4]
	mov r1, ip
	ands r1, r2
	cmp r1, #0
	beq _0804E09C
	adds r1, r7, #0
	ands r1, r2
	b _0804E0A0
	.align 2, 0
_0804E088: .4byte 0x085AB5E0
_0804E08C: .4byte 0x030044D0
_0804E090: .4byte 0x00000FFF
_0804E094: .4byte 0x03004510
_0804E098: .4byte 0x0000FFFF
_0804E09C:
	ldrh r1, [r3]
	orrs r1, r6
_0804E0A0:
	strh r1, [r3]
	adds r3, #2
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _0804E076
	b _0804E0B2
_0804E0AE:
	ldr r1, _0804E0B8 @ =0x030044D0
	str r2, [r1]
_0804E0B2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804E0B8: .4byte 0x030044D0

	thumb_func_start FUN_0804e0bc
FUN_0804e0bc: @ 0x0804E0BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0804E11C @ =0x030000DC
_0804E0C2:
	ldrb r0, [r1]
	cmp r0, #1
	beq _0804E0C2
	movs r0, #0
	bl rfu_LMAN_manager_entity
	adds r4, r5, #0
	adds r4, #0x35
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804E0E4
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	movs r0, #0
	strb r0, [r4]
_0804E0E4:
	ldr r0, _0804E120 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0]
	cmp r1, #1
	bne _0804E0F8
	ldr r0, _0804E11C @ =0x030000DC
	strb r1, [r0]
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
_0804E0F8:
	adds r0, r5, #0
	bl FUN_0804d90c
	adds r0, r5, #0
	bl FUN_0804d9a4
	ldr r0, _0804E124 @ =0x085AB5E0
	ldrh r1, [r5, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E11C: .4byte 0x030000DC
_0804E120: .4byte 0x03005800
_0804E124: .4byte 0x085AB5E0

	thumb_func_start FUN_0804e128
FUN_0804e128: @ 0x0804E128
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #0
	strb r0, [r1]
	bl rfu_LMAN_manager_entity
	bl rfu_getMasterSlave
	adds r0, r4, #0
	bl FUN_0804dc90
	adds r0, r4, #0
	bl FUN_0804dd80
	ldr r1, _0804E160 @ =0x085AB5E0
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0804E160: .4byte 0x085AB5E0

	thumb_func_start FUN_0804e164
FUN_0804e164: @ 0x0804E164
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_08241704
	ldr r0, _0804E18C @ =0x030000E0
	adds r1, r5, #0
	adds r1, #0x33
	ldrb r1, [r1]
	str r1, [r0]
	adds r0, r5, #0
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804E1B0
	cmp r0, #1
	bgt _0804E190
	cmp r0, #0
	beq _0804E196
	b _0804E1E2
	.align 2, 0
_0804E18C: .4byte 0x030000E0
_0804E190:
	cmp r0, #2
	beq _0804E1CA
	b _0804E1E2
_0804E196:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E1A8
	adds r0, r5, #0
	bl FUN_0804de70
	b _0804E1E2
_0804E1A8:
	adds r0, r5, #0
	bl FUN_0804dee8
	b _0804E1E2
_0804E1B0:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E1C2
	adds r0, r5, #0
	bl FUN_0804df18
	b _0804E1E2
_0804E1C2:
	adds r0, r5, #0
	bl FUN_0804e028
	b _0804E1E2
_0804E1CA:
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E1DC
	adds r0, r5, #0
	bl FUN_0804e0bc
	b _0804E1E2
_0804E1DC:
	adds r0, r5, #0
	bl FUN_0804e128
_0804E1E2:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804E204
	movs r4, #0
	strb r4, [r1]
	movs r0, #1
	bl rfu_LMAN_stopManager
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x38]
	str r4, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804E204:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _0804E230
	ldr r0, _0804E228 @ =0x0300481C
	movs r1, #0
	str r1, [r0]
	ldr r0, _0804E22C @ =0x03002B58
	str r1, [r0]
	adds r0, r5, #0
	bl RemoveEntity
	adds r0, r5, #0
	bl Free
	bl FUN_0824172c
	b _0804E24E
	.align 2, 0
_0804E228: .4byte 0x0300481C
_0804E22C: .4byte 0x03002B58
_0804E230:
	ldrh r0, [r5, #0x38]
	subs r0, #9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x11
	bhi _0804E242
	ldr r1, _0804E258 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_0804E242:
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x48]
	adds r0, #1
	str r0, [r5, #0x48]
_0804E24E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804E258: .4byte 0x030047B8

	thumb_func_start FUN_0804e25c
FUN_0804e25c: @ 0x0804E25C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x33
	movs r5, #0
	strb r5, [r0]
	ldr r0, _0804E2B4 @ =0x030000E0
	str r5, [r0]
	bl FUN_0823a6c0
	cmp r0, #0
	blt _0804E2AE
	strb r5, [r4, #0x1d]
	adds r0, r4, #0
	bl FUN_0804ba64
	movs r0, #1
	strb r5, [r4, #0x1c]
	movs r1, #1
	strh r0, [r4, #0x38]
	str r5, [r4, #0x44]
	adds r0, r4, #0
	adds r0, #0x32
	strb r1, [r0]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r4, #0x4c]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804E2AE
	bl FUN_0823d340
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _0804E2B8
_0804E2AE:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804E2BA
	.align 2, 0
_0804E2B4: .4byte 0x030000E0
_0804E2B8:
	movs r0, #0
_0804E2BA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e2c0
FUN_0804e2c0: @ 0x0804E2C0
	push {r4, r5, r6, r7, lr}
	ldr r7, _0804E2D0 @ =0x03002B58
	ldr r6, [r7]
	cmp r6, #0
	beq _0804E2D4
	adds r0, r6, #0
	b _0804E364
	.align 2, 0
_0804E2D0: .4byte 0x03002B58
_0804E2D4:
	bl FUN_08241704
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r0, r4, #0
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _0804E362
	adds r0, r5, #0
	adds r1, r4, #0
	bl ClearMemory
	bl GetSecond
	ldr r3, _0804E348 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0804E34C @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0804E350 @ =0x0203B400
	adds r1, r1, r2
	ldrh r3, [r1]
	ldr r1, _0804E354 @ =0x03002CF0
	movs r2, #0xff
	ldrb r1, [r1]
	adds r0, r0, r3
	ands r0, r2
	lsls r0, r0, #8
	orrs r1, r0
	adds r0, r5, #0
	adds r0, #0x6c
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_0804e25c
	cmp r0, #0
	blt _0804E35C
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl SetEntityRoutine
	movs r4, #1
	strb r4, [r5, #0x14]
	strb r4, [r5, #0x16]
	strh r6, [r5, #0x10]
	adds r0, r5, #0
	bl AddEntity
	ldr r0, _0804E358 @ =0x0300481C
	str r4, [r0]
	str r5, [r7]
	adds r0, r5, #0
	b _0804E364
	.align 2, 0
_0804E348: .4byte 0x030046B8
_0804E34C: .4byte 0x000003FF
_0804E350: .4byte 0x0203B400
_0804E354: .4byte 0x03002CF0
_0804E358: .4byte 0x0300481C
_0804E35C:
	adds r0, r5, #0
	bl Free
_0804E362:
	movs r0, #0
_0804E364:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e36c
FUN_0804e36c: @ 0x0804E36C
	push {lr}
	ldr r0, _0804E380 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E37A
	bl FUN_0804e164
_0804E37A:
	pop {r0}
	bx r0
	.align 2, 0
_0804E380: .4byte 0x03002B58

	thumb_func_start FUN_0804e384
FUN_0804e384: @ 0x0804E384
	push {lr}
	ldr r0, _0804E39C @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E396
	adds r1, r0, #0
	adds r1, #0xfb
	movs r0, #1
	strb r0, [r1]
_0804E396:
	pop {r0}
	bx r0
	.align 2, 0
_0804E39C: .4byte 0x03002B58

	thumb_func_start FUN_0804e3a0
FUN_0804e3a0: @ 0x0804E3A0
	push {lr}
	ldr r0, _0804E3B4 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E3B8
	ldrb r0, [r0, #0x1f]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _0804E3BC
	.align 2, 0
_0804E3B4: .4byte 0x03002B58
_0804E3B8:
	movs r0, #1
	rsbs r0, r0, #0
_0804E3BC:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e3c0
FUN_0804e3c0: @ 0x0804E3C0
	push {lr}
	ldr r0, _0804E3D8 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E3D4
	ldr r0, _0804E3DC @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E3E0
_0804E3D4:
	movs r0, #0
	b _0804E3E6
	.align 2, 0
_0804E3D8: .4byte 0x03002B58
_0804E3DC: .4byte 0x03005800
_0804E3E0:
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
_0804E3E6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e3ec
FUN_0804e3ec: @ 0x0804E3EC
	push {lr}
	ldr r0, _0804E414 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E426
	adds r0, r1, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E41C
	ldrh r0, [r1, #0x38]
	cmp r0, #4
	bls _0804E426
	ldr r0, _0804E418 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _0804E426
	b _0804E430
	.align 2, 0
_0804E414: .4byte 0x03002B58
_0804E418: .4byte 0x03005800
_0804E41C:
	ldr r0, _0804E42C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E430
_0804E426:
	movs r0, #0
	b _0804E432
	.align 2, 0
_0804E42C: .4byte 0x03005800
_0804E430:
	movs r0, #1
_0804E432:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e438
FUN_0804e438: @ 0x0804E438
	push {lr}
	ldr r0, _0804E44C @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E450
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r0, r1
	b _0804E452
	.align 2, 0
_0804E44C: .4byte 0x03002B58
_0804E450:
	movs r0, #0
_0804E452:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e458
FUN_0804e458: @ 0x0804E458
	push {lr}
	ldr r0, _0804E468 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E46C
	adds r0, #0x30
	ldrb r0, [r0]
	b _0804E46E
	.align 2, 0
_0804E468: .4byte 0x03002B58
_0804E46C:
	movs r0, #0
_0804E46E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e474
FUN_0804e474: @ 0x0804E474
	push {lr}
	ldr r0, _0804E484 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E488
	ldrb r0, [r0, #0x19]
	b _0804E48A
	.align 2, 0
_0804E484: .4byte 0x03002B58
_0804E488:
	movs r0, #0
_0804E48A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e490
FUN_0804e490: @ 0x0804E490
	push {lr}
	ldr r0, _0804E4A0 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E4A4
	ldrh r0, [r0, #0x38]
	b _0804E4A6
	.align 2, 0
_0804E4A0: .4byte 0x03002B58
_0804E4A4:
	movs r0, #0
_0804E4A6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e4ac
FUN_0804e4ac: @ 0x0804E4AC
	push {lr}
	ldr r0, _0804E4C0 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E4BA
	movs r0, #1
	strb r0, [r1, #0x1b]
_0804E4BA:
	pop {r0}
	bx r0
	.align 2, 0
_0804E4C0: .4byte 0x03002B58

	thumb_func_start FUN_0804e4c4
FUN_0804e4c4: @ 0x0804E4C4
	push {lr}
	ldr r0, _0804E4D8 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E4D2
	movs r0, #1
	strb r0, [r1, #0x1c]
_0804E4D2:
	pop {r0}
	bx r0
	.align 2, 0
_0804E4D8: .4byte 0x03002B58

	thumb_func_start FUN_0804e4dc
FUN_0804e4dc: @ 0x0804E4DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804E510 @ =0x03002B58
	ldr r0, [r0]
	mov ip, r0
	cmp r0, #0
	beq _0804E50A
	movs r0, #0xde
	lsls r0, r0, #2
	add r0, ip
	str r4, [r0]
	movs r0, #0xdf
	lsls r0, r0, #2
	add r0, ip
	str r1, [r0]
	movs r0, #0xe0
	lsls r0, r0, #2
	add r0, ip
	str r2, [r0]
	movs r0, #0xe1
	lsls r0, r0, #2
	add r0, ip
	str r3, [r0]
_0804E50A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804E510: .4byte 0x03002B58

	thumb_func_start FUN_0804e514
FUN_0804e514: @ 0x0804E514
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0804E548 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	beq _0804E550
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804E550
	adds r1, r4, #0
	adds r1, #0xb8
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r2, _0804E54C @ =0x04000003
	adds r0, r3, #0
	bl CpuSet
	ldrh r1, [r4, #0x22]
	movs r0, #1
	orrs r0, r1
	strh r0, [r4, #0x22]
	movs r0, #0
	b _0804E554
	.align 2, 0
_0804E548: .4byte 0x03002B58
_0804E54C: .4byte 0x04000003
_0804E550:
	movs r0, #1
	rsbs r0, r0, #0
_0804E554:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e55c
FUN_0804e55c: @ 0x0804E55C
	push {lr}
	adds r1, r0, #0
	ldr r0, _0804E574 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E57C
	adds r0, #0xc4
	ldr r2, _0804E578 @ =0x04000003
	bl CpuSet
	movs r0, #0
	b _0804E580
	.align 2, 0
_0804E574: .4byte 0x03002B58
_0804E578: .4byte 0x04000003
_0804E57C:
	movs r0, #1
	rsbs r0, r0, #0
_0804E580:
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e584
FUN_0804e584: @ 0x0804E584
	push {lr}
	adds r1, r0, #0
	ldr r0, _0804E598 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E594
	adds r0, #0x33
	strb r1, [r0]
_0804E594:
	pop {r0}
	bx r0
	.align 2, 0
_0804E598: .4byte 0x03002B58

	thumb_func_start FUN_0804e59c
FUN_0804e59c: @ 0x0804E59C
	push {lr}
	ldr r0, _0804E5AC @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E5B0
	adds r0, #0x33
	ldrb r0, [r0]
	b _0804E5B4
	.align 2, 0
_0804E5AC: .4byte 0x03002B58
_0804E5B0:
	ldr r0, _0804E5B8 @ =0x030000E0
	ldr r0, [r0]
_0804E5B4:
	pop {r1}
	bx r1
	.align 2, 0
_0804E5B8: .4byte 0x030000E0

	thumb_func_start FUN_0804e5bc
FUN_0804e5bc: @ 0x0804E5BC
	push {lr}
	ldr r0, _0804E5E4 @ =0x03002B58
	ldr r3, [r0]
	cmp r3, #0
	beq _0804E5DE
	adds r0, r3, #0
	adds r0, #0x3f
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	movs r0, #0x1f
	strb r1, [r3, #0x1c]
	strh r0, [r3, #0x38]
	str r1, [r3, #0x44]
	adds r0, r3, #0
	adds r0, #0x32
	strb r2, [r0]
_0804E5DE:
	pop {r0}
	bx r0
	.align 2, 0
_0804E5E4: .4byte 0x03002B58

	thumb_func_start FUN_0804e5e8
FUN_0804e5e8: @ 0x0804E5E8
	push {lr}
	ldr r0, _0804E600 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E5FA
	adds r1, r0, #0
	adds r1, #0x3d
	movs r0, #1
	strb r0, [r1]
_0804E5FA:
	pop {r0}
	bx r0
	.align 2, 0
_0804E600: .4byte 0x03002B58

	thumb_func_start FUN_0804e604
FUN_0804e604: @ 0x0804E604
	push {lr}
	ldr r0, _0804E618 @ =0x03002B58
	ldr r1, [r0]
	cmp r1, #0
	beq _0804E612
	movs r0, #1
	strb r0, [r1, #0x1d]
_0804E612:
	pop {r0}
	bx r0
	.align 2, 0
_0804E618: .4byte 0x03002B58

	thumb_func_start FUN_0804e61c
FUN_0804e61c: @ 0x0804E61C
	push {lr}
	ldr r0, _0804E62C @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E630
	adds r0, #0x50
	b _0804E632
	.align 2, 0
_0804E62C: .4byte 0x03002B58
_0804E630:
	movs r0, #0
_0804E632:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e638
FUN_0804e638: @ 0x0804E638
	push {lr}
	ldr r0, _0804E648 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E64C
	adds r0, #0x6c
	ldrh r0, [r0]
	b _0804E64E
	.align 2, 0
_0804E648: .4byte 0x03002B58
_0804E64C:
	movs r0, #0
_0804E64E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e654
FUN_0804e654: @ 0x0804E654
	ldr r0, _0804E658 @ =0x0203FC00
	bx lr
	.align 2, 0
_0804E658: .4byte 0x0203FC00

	thumb_func_start FUN_0804e65c
FUN_0804e65c: @ 0x0804E65C
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl FUN_0804e654
	lsls r4, r4, #1
	adds r4, r4, r0
	ldrh r0, [r4]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e674
FUN_0804e674: @ 0x0804E674
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl FUN_0804e654
	adds r2, r0, #0
	movs r1, #0
_0804E682:
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r4
	beq _0804E694
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _0804E682
_0804E694:
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e69c
FUN_0804e69c: @ 0x0804E69C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r5, #0
	cmp r5, r6
	bge _0804E6CE
_0804E6AA:
	adds r0, r7, r5
	ldrb r0, [r0]
	bl FUN_0804e65c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x7f
	bhi _0804E6C0
	strb r1, [r4]
	adds r4, #1
	b _0804E6C8
_0804E6C0:
	strb r1, [r4]
	lsrs r0, r0, #0x18
	strb r0, [r4, #1]
	adds r4, #2
_0804E6C8:
	adds r5, #1
	cmp r5, r6
	blt _0804E6AA
_0804E6CE:
	movs r0, #0
	strb r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804e6d8
FUN_0804e6d8: @ 0x0804E6D8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r5, #0
	b _0804E706
_0804E6E4:
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _0804E6F0
	ldrb r1, [r4]
	adds r4, #1
	b _0804E6FA
_0804E6F0:
	ldrb r1, [r4]
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	orrs r1, r0
	adds r4, #2
_0804E6FA:
	adds r0, r1, #0
	bl FUN_0804e674
	adds r1, r7, r5
	strb r0, [r1]
	adds r5, #1
_0804E706:
	cmp r5, r6
	bge _0804E720
	ldrb r0, [r4]
	cmp r0, #0
	bne _0804E6E4
	cmp r5, r6
	bge _0804E720
	movs r1, #0
_0804E716:
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #1
	cmp r5, r6
	blt _0804E716
_0804E720:
	adds r1, r7, r6
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Crossover_LoadMappingBuf
Crossover_LoadMappingBuf: @ 0x0804E72C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804E744
	bl VM_GetPC
	adds r6, r0, #0
	b _0804E746
_0804E744:
	movs r6, #0
_0804E746:
	cmp r6, #0
	beq _0804E7A8
	bl FUN_0804e654
	adds r7, r0, #0
	movs r5, #0
	movs r4, #0
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
_0804E75A:
	adds r0, r6, #0
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	adds r2, r0, #0
	ldrb r1, [r2]
	adds r4, #1
	cmp r1, #0
	beq _0804E7A0
	cmp r5, r8
	beq _0804E7A0
	lsls r0, r5, #1
	adds r3, r0, r7
_0804E778:
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _0804E786
	ldrb r0, [r2]
	strh r0, [r3]
	adds r2, #1
	b _0804E792
_0804E786:
	ldrb r1, [r2, #1]
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	strh r0, [r3]
	adds r2, #2
_0804E792:
	adds r3, #2
	adds r5, #1
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804E7A0
	cmp r5, r8
	bne _0804E778
_0804E7A0:
	cmp r4, #4
	ble _0804E75A
	movs r0, #0
	strh r0, [r7]
_0804E7A8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804e7b4
FUN_0804e7b4: @ 0x0804E7B4
	ldr r0, _0804E7BC @ =0x030000E4
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0804E7BC: .4byte 0x030000E4

	thumb_func_start FUN_0804e7c0
FUN_0804e7c0: @ 0x0804E7C0
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0xe4
	ble _0804E7E6
	ldr r0, [r4, #0x1c]
	movs r3, #0x1f
	ands r3, r0
	movs r2, #0x3f
	adds r1, r0, #0
	cmp r3, #7
	ble _0804E82A
	movs r2, #0x40
	cmp r3, #0xf
	ble _0804E82A
	movs r2, #0x42
	cmp r3, #0x17
	bgt _0804E82A
	movs r2, #0x41
	b _0804E82A
_0804E7E6:
	cmp r1, #0x7e
	ble _0804E802
	ldr r0, [r4, #0x1c]
	movs r3, #0x1f
	ands r3, r0
	movs r2, #0x3f
	adds r1, r0, #0
	cmp r3, #9
	ble _0804E82A
	movs r2, #0x41
	cmp r3, #0x13
	bgt _0804E82A
	movs r2, #0x40
	b _0804E82A
_0804E802:
	cmp r1, #0x18
	ble _0804E81C
	ldr r0, [r4, #0x1c]
	movs r3, #0x1f
	ands r3, r0
	movs r2, #0x3e
	adds r1, r0, #0
	cmp r3, #9
	ble _0804E82A
	movs r2, #0x40
	cmp r3, #0x13
	bgt _0804E82A
	b _0804E828
_0804E81C:
	ldr r1, [r4, #0x1c]
	movs r0, #0x1f
	ands r0, r1
	movs r2, #0x3e
	cmp r0, #0xf
	bgt _0804E82A
_0804E828:
	movs r2, #0x3f
_0804E82A:
	adds r0, r1, #1
	str r0, [r4, #0x1c]
	ldr r0, [r4, #0x20]
	cmp r2, r0
	beq _0804E844
	str r2, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x44
	adds r1, r4, #0
	adds r1, #0x24
	movs r3, #0
	bl Sprite_SetSprite
_0804E844:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804e84c
FUN_0804e84c: @ 0x0804E84C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804E86C @ =0x03005800
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0804E870
	ldrb r1, [r1, #0xa]
	adds r0, r4, #0
	bl FUN_0804e7c0
	ldr r0, [r4, #0x4c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0804E876
	.align 2, 0
_0804E86C: .4byte 0x03005800
_0804E870:
	ldr r0, [r4, #0x4c]
	movs r1, #1
	orrs r0, r1
_0804E876:
	str r0, [r4, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804e880
FUN_0804e880: @ 0x0804E880
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0804e59c
	cmp r0, #0
	bne _0804E90A
	movs r5, #0xff
	bl FUN_0804e3ec
	cmp r0, #0
	beq _0804E902
	ldr r0, _0804E8B8 @ =0x03005800
	ldr r2, [r0]
	ldrb r1, [r2]
	adds r7, r0, #0
	cmp r1, #0
	bne _0804E8BC
	bl FUN_0804e3c0
	ldr r1, [r7]
	adds r1, #0xa
	adds r1, r1, r0
	ldrb r5, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0804e7c0
	b _0804E8F8
	.align 2, 0
_0804E8B8: .4byte 0x03005800
_0804E8BC:
	movs r1, #0
	ldrb r3, [r2, #2]
	movs r6, #1
	adds r2, #0xa
_0804E8C4:
	adds r0, r3, #0
	asrs r0, r1
	ands r0, r6
	cmp r0, #0
	beq _0804E8D8
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r5, r0
	ble _0804E8D8
	adds r5, r0, #0
_0804E8D8:
	adds r1, #1
	cmp r1, #3
	ble _0804E8C4
	ldr r0, [r7]
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne _0804E8F0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0804e7c0
	b _0804E8F8
_0804E8F0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0804e7c0
_0804E8F8:
	ldr r0, [r4, #0x4c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0804E908
_0804E902:
	ldr r0, [r4, #0x4c]
	movs r1, #1
	orrs r0, r1
_0804E908:
	str r0, [r4, #0x4c]
_0804E90A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804e910
FUN_0804e910: @ 0x0804E910
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804e880
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804e928
FUN_0804e928: @ 0x0804E928
	push {lr}
	adds r0, #0x44
	bl FUN_0822f1c0
	ldr r1, _0804E93C @ =0x030000E4
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0804E93C: .4byte 0x030000E4

	thumb_func_start FUN_0804e940
FUN_0804e940: @ 0x0804E940
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _0804E994 @ =0x030000E4
	str r5, [r0]
	ldr r0, _0804E998 @ =0x0000CB05
	ldr r1, _0804E99C @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0804E9A0
	adds r1, r5, #0
	adds r1, #0x24
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x3f
	movs r3, #0x11
	bl FUN_0822f3fc
	movs r0, #0
	b _0804E9A4
	.align 2, 0
_0804E994: .4byte 0x030000E4
_0804E998: .4byte 0x0000CB05
_0804E99C: .4byte 0x0000DCC1
_0804E9A0:
	movs r0, #1
	rsbs r0, r0, #0
_0804E9A4:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e9ac
FUN_0804e9ac: @ 0x0804E9AC
	push {r4, lr}
	bl FUN_0804e7b4
	adds r4, r0, #0
	cmp r4, #0
	bne _0804E9EE
	movs r0, #0xb
	movs r1, #0xa4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804E9EC
	ldr r1, _0804E9E4 @ =FUN_0804e910
	ldr r2, _0804E9E8 @ =FUN_0804e928
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0804e940
	cmp r0, #0
	bge _0804E9EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804E9EE
	.align 2, 0
_0804E9E4: .4byte FUN_0804e910
_0804E9E8: .4byte FUN_0804e928
_0804E9EC:
	adds r0, r4, #0
_0804E9EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804e9f4
FUN_0804e9f4: @ 0x0804E9F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_0804e9ac
	cmp r0, #0
	beq _0804EA08
	adds r0, #0x44
	strh r4, [r0, #0x20]
	strh r5, [r0, #0x22]
_0804EA08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ea10
FUN_0804ea10: @ 0x0804EA10
	ldr r0, _0804EA18 @ =0x030000E8
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0804EA18: .4byte 0x030000E8

	thumb_func_start FUN_0804ea1c
FUN_0804ea1c: @ 0x0804EA1C
	push {lr}
	bl FUN_0804a5c8
	bl FUN_08016f84
	ldr r2, _0804EA54 @ =0x03003E78
	ldr r0, _0804EA58 @ =0xFFFFF9FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	bl FUN_0822b41c
	ldr r1, _0804EA5C @ =FUN_0822e738
	ldr r2, _0804EA60 @ =FUN_0822b09c
	ldr r3, _0804EA64 @ =FUN_0822f584
	movs r0, #0
	bl FUN_0822a448
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #0
	bl FUN_0822b644
	pop {r0}
	bx r0
	.align 2, 0
_0804EA54: .4byte 0x03003E78
_0804EA58: .4byte 0xFFFFF9FF
_0804EA5C: .4byte FUN_0822e738
_0804EA60: .4byte FUN_0822b09c
_0804EA64: .4byte FUN_0822f584

	thumb_func_start FUN_0804ea68
FUN_0804ea68: @ 0x0804EA68
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0804EABC @ =0x0000C091
	ldr r1, _0804EAC0 @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x24]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804EAC4 @ =0x000092B3
	ldr r1, _0804EAC8 @ =0x0000EFDA
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804EACC @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EABC: .4byte 0x0000C091
_0804EAC0: .4byte 0x0000A413
_0804EAC4: .4byte 0x000092B3
_0804EAC8: .4byte 0x0000EFDA
_0804EACC: .4byte 0x03004250

	thumb_func_start FUN_0804ead0
FUN_0804ead0: @ 0x0804EAD0
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0804EB24 @ =0x0000C091
	ldr r1, _0804EB28 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x24]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0804EB2C @ =0x000092B3
	ldr r1, _0804EB30 @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	ldr r1, _0804EB34 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EB24: .4byte 0x0000C091
_0804EB28: .4byte 0x0000CD91
_0804EB2C: .4byte 0x000092B3
_0804EB30: .4byte 0x000026BB
_0804EB34: .4byte 0x03004250

	thumb_func_start FUN_0804eb38
FUN_0804eb38: @ 0x0804EB38
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x19]
	cmp r0, #0
	beq _0804EB46
	movs r0, #0
	strb r0, [r1, #0x19]
_0804EB46:
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
	pop {r0}
	bx r0

	thumb_func_start FUN_0804eb50
FUN_0804eb50: @ 0x0804EB50
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #4
	ldr r1, _0804EBC0 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804EB6C
	movs r0, #0
	strb r0, [r4, #0x19]
	bl FUN_0804e5bc
_0804EB6C:
	ldr r0, [r4, #0x1c]
	cmp r0, #4
	bne _0804EBB4
	movs r0, #1
	bl sound_fadeout_08240440
	adds r0, r4, #0
	bl FUN_0804ea1c
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804ea68
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	str r0, [r4, #0x20]
	cmp r0, #0
	blt _0804EBB4
	ldr r1, [r4, #0x28]
	bl FUN_0804a240
	ldr r0, [r4, #0x20]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r4, #0x20]
	bl FUN_0804a1f0
_0804EBB4:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EBC0: .4byte 0x030044BC

	thumb_func_start FUN_0804ebc4
FUN_0804ebc4: @ 0x0804EBC4
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #4
	ldr r1, _0804EC44 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804EC22
	movs r0, #0
	strb r0, [r4, #0x19]
	movs r0, #1
	bl sound_fadeout_08240440
	adds r0, r4, #0
	bl FUN_0804ea1c
	bl FUN_0804e5bc
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_0804ead0
	movs r0, #1
	movs r1, #0xe
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	str r0, [r4, #0x20]
	cmp r0, #0
	blt _0804EC1A
	ldr r1, [r4, #0x28]
	bl FUN_0804a240
	ldr r0, [r4, #0x20]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r4, #0x20]
	bl FUN_0804a1f0
_0804EC1A:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804EC22:
	ldr r2, [r4, #0x1c]
	cmp r2, #0x3b
	bls _0804EC4C
	ldr r0, _0804EC48 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0804EC4C
	movs r0, #3
	movs r1, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x1c]
	b _0804EC50
	.align 2, 0
_0804EC44: .4byte 0x030044BC
_0804EC48: .4byte 0x030044E0
_0804EC4C:
	adds r0, r2, #1
	str r0, [r4, #0x1c]
_0804EC50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0804ec58
FUN_0804ec58: @ 0x0804EC58
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804EC88
	movs r0, #0
	strb r0, [r4, #0x19]
	movs r1, #4
	str r1, [sp]
	ldr r1, _0804ECC8 @ =0x0000FFFF
	str r1, [sp, #4]
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0xde
	bl PlaySound_082406e0
	bl FUN_0804e5e8
_0804EC88:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x14
	bne _0804EC92
	bl FUN_0804e604
_0804EC92:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x13
	bls _0804ECBA
	bl FUN_0804ba3c
	cmp r0, #0
	bne _0804ECBA
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0804ECBA
	ldr r1, _0804ECCC @ =FUN_0822db5c
	ldr r2, _0804ECD0 @ =FUN_0822aaac
	ldr r3, _0804ECD4 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	ldr r0, [r4, #0x2c]
	movs r1, #0
	bl Script_ExecById
_0804ECBA:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804ECC8: .4byte 0x0000FFFF
_0804ECCC: .4byte FUN_0822db5c
_0804ECD0: .4byte FUN_0822aaac
_0804ECD4: .4byte FUN_0822f204

	thumb_func_start FUN_0804ecd8
FUN_0804ecd8: @ 0x0804ECD8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0x18]
	cmp r5, #0
	bne _0804ECFA
	bl FUN_0804e59c
	cmp r0, #1
	bne _0804ECEE
	strb r0, [r4, #0x18]
	b _0804ECF6
_0804ECEE:
	cmp r0, #2
	bne _0804ECFA
	strb r0, [r4, #0x18]
	movs r0, #1
_0804ECF6:
	strb r0, [r4, #0x19]
	str r5, [r4, #0x1c]
_0804ECFA:
	ldr r0, _0804ED14 @ =0x085AB664
	ldrb r1, [r4, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804ED14: .4byte 0x085AB664

	thumb_func_start FUN_0804ed18
FUN_0804ed18: @ 0x0804ED18
	push {lr}
	ldr r0, [r0, #0x20]
	bl FUN_0804a16c
	ldr r1, _0804ED2C @ =0x030000E8
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0804ED2C: .4byte 0x030000E8

	thumb_func_start FUN_0804ed30
FUN_0804ed30: @ 0x0804ED30
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804ED58 @ =0x030000E8
	str r4, [r0]
	bl FUN_08016f84
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804ED50
	bl FUN_0823d340
	str r0, [r4, #0x28]
	cmp r0, #0
	bne _0804ED5C
_0804ED50:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804ED78
	.align 2, 0
_0804ED58: .4byte 0x030000E8
_0804ED5C:
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r4, #0x2c]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x20]
	movs r1, #0
	strb r1, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x1c]
	movs r0, #0
_0804ED78:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804ed80
FUN_0804ed80: @ 0x0804ED80
	push {r4, lr}
	bl FUN_0804ea10
	adds r4, r0, #0
	cmp r4, #0
	bne _0804EDC2
	movs r0, #0xc
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804EDC0
	ldr r1, _0804EDB8 @ =FUN_0804ecd8
	ldr r2, _0804EDBC @ =FUN_0804ed18
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0804ed30
	cmp r0, #0
	bge _0804EDC0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804EDC2
	.align 2, 0
_0804EDB8: .4byte FUN_0804ecd8
_0804EDBC: .4byte FUN_0804ed18
_0804EDC0:
	adds r0, r4, #0
_0804EDC2:
	pop {r4}
	pop {r1}
	bx r1

