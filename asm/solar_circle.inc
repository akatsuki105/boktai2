	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a1e28
FUN_080a1e28: @ 0x080A1E28
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x32]
	adds r2, r0, #1
	strh r2, [r3, #0x32]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A1E48
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x30]
	b _080A1E70
_080A1E48:
	ldrh r0, [r3, #0x28]
	ldrh r4, [r3, #0x18]
	adds r0, r0, r4
	strh r0, [r3, #0x18]
	ldrh r0, [r3, #0x2a]
	ldrh r4, [r3, #0x1a]
	adds r0, r0, r4
	strh r0, [r3, #0x1a]
	ldrh r0, [r3, #0x2c]
	ldrh r4, [r3, #0x1c]
	adds r0, r0, r4
	strh r0, [r3, #0x1c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r3, #0
	bl Particle_SetFrame
_080A1E70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a1e78
FUN_080a1e78: @ 0x080A1E78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0xbd
	adds r0, r0, r7
	mov sl, r0
	ldrb r2, [r0]
	movs r0, #0x34
	adds r4, r2, #0
	muls r4, r0, r4
	adds r4, #0xc0
	adds r4, r7, r4
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r5, _080A1F50 @ =0x0203B400
	ldr r1, _080A1F54 @ =0x030046B8
	mov sb, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r3, _080A1F58 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xac
	asrs r0, r0, #4
	movs r6, #0xff
	mov r8, r6
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x18]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0xae
	adds r2, r2, r7
	mov ip, r2
	movs r2, #0x3f
	ands r0, r2
	mov r6, ip
	ldrh r6, [r6]
	adds r0, r0, r6
	strh r0, [r4, #0x1a]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xb0
	asrs r0, r0, #4
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x28]
	adds r1, #1
	ands r1, r3
	mov r2, sb
	str r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strh r0, [r4, #0x2a]
	movs r6, #0
	strh r6, [r4, #0x2c]
	strh r6, [r4, #0x32]
	movs r0, #1
	strh r0, [r4, #0x30]
	mov r1, sl
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080A1F42
	movs r0, #0
	strb r0, [r1]
_080A1F42:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1F50: .4byte 0x0203B400
_080A1F54: .4byte 0x030046B8
_080A1F58: .4byte 0x000003FF

	thumb_func_start FUN_080a1f5c
FUN_080a1f5c: @ 0x080A1F5C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _080A1FA2
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r2, r5, #0
	adds r2, #0xac
	movs r4, #0
	ldrsh r2, [r2, r4]
	subs r1, r1, r2
	cmp r1, #0
	bge _080A1F7E
	rsbs r1, r1, #0
_080A1F7E:
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r1, #4
	ldrsh r2, [r3, r1]
	adds r1, r5, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r2, r1
	cmp r1, #0
	bge _080A1F96
	rsbs r1, r1, #0
_080A1F96:
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r4, #0x7f
	bhi _080A1FA2
	cmp r2, #0x7f
	bls _080A1FA6
_080A1FA2:
	movs r0, #0
	b _080A1FBA
_080A1FA6:
	adds r1, r4, #0
	muls r1, r4, r1
	adds r4, r2, #0
	muls r4, r2, r4
	adds r2, r4, #0
	adds r1, r1, r2
	ldr r2, _080A1FC0 @ =0x00003FFF
	cmp r1, r2
	bgt _080A1FBA
	movs r0, #1
_080A1FBA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1FC0: .4byte 0x00003FFF

	thumb_func_start FUN_080a1fc4
FUN_080a1fc4: @ 0x080A1FC4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xa8
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2040
	adds r0, r4, #0
	bl FUN_080a1f5c
	cmp r0, #0
	beq _080A200C
	ldr r0, _080A2034 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080A2038 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080A200C
	strh r0, [r5]
	movs r2, #0x98
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1FFE
	movs r1, #0
	bl VM_ExecByID
_080A1FFE:
	movs r0, #1
	bl FUN_0808670c
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A200C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A203C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
	b _080A2090
	.align 2, 0
_080A2034: .4byte 0x03002C00
_080A2038: .4byte 0x000001F5
_080A203C: .4byte 0x0000FFFF
_080A2040:
	adds r0, r4, #0
	bl FUN_080a1f5c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A206C
	movs r1, #0x99
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080A205E
	movs r1, #0
	bl VM_ExecByID
_080A205E:
	movs r0, #0
	bl FUN_0808670c
	strh r6, [r5]
	ldr r0, _080A2098 @ =0x00000199
	bl PlaySound_082406e0
_080A206C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A209C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
_080A2090:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2098: .4byte 0x00000199
_080A209C: .4byte 0x0000FFFF

	thumb_func_start FUN_080a20a0
FUN_080a20a0: @ 0x080A20A0
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x18]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080A20DC
	adds r0, r2, #0
	adds r0, #0xae
	ldrh r0, [r0]
	adds r0, #0x1e
	strh r0, [r2, #0x36]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A20D8 @ =FUN_080a1fc4
	str r0, [r1]
	b _080A20E8
	.align 2, 0
_080A20D8: .4byte FUN_080a1fc4
_080A20DC:
	adds r3, r2, #0
	adds r3, #0xae
	lsls r0, r1, #1
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r2, #0x36]
_080A20E8:
	adds r1, r2, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r3, _080A2110 @ =0x0000FFFF
	adds r1, r3, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A210C
	adds r0, r2, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r2, #0
	bl FUN_080a1e78
_080A210C:
	pop {r0}
	bx r0
	.align 2, 0
_080A2110: .4byte 0x0000FFFF

	thumb_func_start FUN_080a2114
FUN_080a2114: @ 0x080A2114
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x18]
	ldr r0, [r2, #0x60]
	subs r1, #3
	ands r0, r1
	str r0, [r2, #0x60]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080A216C
	ldr r0, [r2, #0x60]
	subs r1, #1
	ands r0, r1
	str r0, [r2, #0x60]
	adds r0, r2, #0
	adds r0, #0x68
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A2164 @ =FUN_080a20a0
	str r0, [r1]
	ldr r0, _080A2168 @ =0x0000032F
	bl PlaySound_082406e0
	b _080A218C
	.align 2, 0
_080A2164: .4byte FUN_080a20a0
_080A2168: .4byte 0x0000032F
_080A216C:
	ldr r0, [r2, #0x60]
	movs r1, #2
	orrs r0, r1
	str r0, [r2, #0x60]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x68
	strb r1, [r0]
	ldrh r0, [r3]
	adds r1, r2, #0
	adds r1, #0x69
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	subs r1, #3
	strb r0, [r1]
_080A218C:
	pop {r0}
	bx r0

	thumb_func_start SolarCircle_Update
SolarCircle_Update: @ 0x080A2190
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_080A2196:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xf0
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A21B6
	adds r0, r1, #0
	adds r0, #0xc0
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	bl FUN_080a1e28
_080A21B6:
	adds r5, #1
	cmp r5, #7
	ble _080A2196
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start SolarCircle_Destroy
SolarCircle_Destroy: @ 0x080A21D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x60
	bl AuxSprite_Remove
	adds r4, #0xc0
	movs r5, #7
_080A21E6:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A21E6
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a21fc
FUN_080a21fc: @ 0x080A21FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r0, _080A2290 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	movs r7, #0
	mov r8, r1
	movs r0, #4
	rsbs r0, r0, #0
	mov sl, r0
	movs r1, #1
	mov sb, r1
_080A2222:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	adds r4, r5, #0
	adds r4, #0xc0
	adds r4, r6, r4
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl Particle_Add
	adds r0, r4, #0
	mov r1, sl
	mov r2, sl
	bl Particle_SetOffset
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	mov r1, sb
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	mov r1, sb
	orrs r0, r1
	str r0, [r4]
	adds r5, r6, r5
	adds r5, #0xf0
	movs r0, #0
	strh r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A2222
	adds r0, r6, #0
	adds r0, #0xbd
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2290: .4byte 0x00001C1E

	thumb_func_start SolarCircle_Init
SolarCircle_Init: @ 0x080A2294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A2350
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sl, r4
	cmp r2, #0
	blt _080A22F0
	cmp r1, #0
	blt _080A22F0
	ldr r0, _080A22F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A22F0
	ldr r0, _080A22F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A22FC
_080A22F0:
	movs r6, #0
	b _080A230A
	.align 2, 0
_080A22F4: .4byte 0x030046A8
_080A22F8: .4byte 0x030046AC
_080A22FC:
	ldr r0, _080A231C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A230A:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A2320
	adds r0, #4
	b _080A232C
	.align 2, 0
_080A231C: .4byte 0x030046A4
_080A2320:
	ldr r0, _080A2340 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A232C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A2344
	cmp r2, #2
	beq _080A2348
	b _080A234C
	.align 2, 0
_080A2340: .4byte 0x030046A4
_080A2344:
	ldrb r0, [r4, #4]
	b _080A234A
_080A2348:
	ldrb r0, [r4]
_080A234A:
	subs r1, r1, r0
_080A234C:
	strh r1, [r5]
	b _080A2362
_080A2350:
	adds r1, r7, #0
	adds r1, #0xac
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	mov sl, r1
_080A2362:
	adds r4, r7, #0
	adds r4, #0x44
	ldr r0, _080A2428 @ =0x00000BA8
	mov sb, r0
	adds r0, r4, #0
	mov r1, sb
	bl Video_GetAuxSprite
	adds r5, r7, #0
	adds r5, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r6, #6
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x63
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r1, #3
	mov r8, r1
	mov r2, r8
	strb r2, [r7, #0x1f]
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r7, #0x36]
	adds r0, #0x1e
	strh r0, [r7, #0x36]
	adds r4, #0x48
	adds r0, r4, #0
	mov r1, sb
	bl Video_GetAuxSprite
	adds r5, #0x48
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x61
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x60]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x67
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x7c
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_080a21fc
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A2430
	bl VM_GetValue
	cmp r0, #0
	beq _080A2430
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x60]
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A242C @ =FUN_080a2114
	str r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2438
	.align 2, 0
_080A2428: .4byte 0x00000BA8
_080A242C: .4byte FUN_080a2114
_080A2430:
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A2458 @ =FUN_080a1fc4
	str r0, [r1]
_080A2438:
	adds r1, r7, #0
	adds r1, #0xaa
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080a1f5c
	adds r1, r0, #0
	cmp r1, #0
	beq _080A245C
	adds r1, r7, #0
	adds r1, #0xa8
	movs r0, #1
	strh r0, [r1]
	adds r4, r1, #0
	b _080A2464
	.align 2, 0
_080A2458: .4byte FUN_080a1fc4
_080A245C:
	adds r0, r7, #0
	adds r0, #0xa8
	strh r1, [r0]
	adds r4, r0, #0
_080A2464:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A247E
	bl VM_GetValue
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A2486
_080A247E:
	movs r3, #0x98
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A2486:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A24A0
	bl VM_GetValue
	movs r2, #0x99
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A24A8
_080A24A0:
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A24A8:
	adds r0, r7, #0
	bl FUN_080a1f5c
	cmp r0, #0
	beq _080A24BC
	movs r0, #1
	strh r0, [r4]
	bl FUN_0808670c
	b _080A24C4
_080A24BC:
	strh r0, [r4]
	movs r0, #0
	bl FUN_0808670c
_080A24C4:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start SolarCircle_Create
SolarCircle_Create: @ 0x080A24D4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x9a
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A2514
	ldr r1, _080A250C @ =SolarCircle_Update
	ldr r2, _080A2510 @ =SolarCircle_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl SolarCircle_Init
	cmp r0, #0
	bge _080A2514
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A2516
	.align 2, 0
_080A250C: .4byte SolarCircle_Update
_080A2510: .4byte SolarCircle_Destroy
_080A2514:
	adds r0, r4, #0
_080A2516:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
