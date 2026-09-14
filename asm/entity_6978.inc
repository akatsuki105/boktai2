	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080026fc
FUN_080026fc: @ 0x080026FC
	push {lr}
	adds r1, r0, #0
	ldr r0, _08002714 @ =gEntity4AE5
	ldr r0, [r0]
	cmp r0, #0
	beq _0800270E
	ldr r2, _08002718 @ =0x00000644
	adds r0, r0, r2
	strb r1, [r0]
_0800270E:
	pop {r0}
	bx r0
	.align 2, 0
_08002714: .4byte gEntity4AE5
_08002718: .4byte 0x00000644

	thumb_func_start FUN_0800271c
FUN_0800271c: @ 0x0800271C
	push {lr}
	ldr r0, _0800272C @ =gEntity4AE5
	ldr r0, [r0]
	cmp r0, #0
	beq _08002730
	adds r0, #0x20
	ldrb r0, [r0]
	b _08002732
	.align 2, 0
_0800272C: .4byte gEntity4AE5
_08002730:
	movs r0, #0
_08002732:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08002738
FUN_08002738: @ 0x08002738
	ldr r1, _08002740 @ =0x03002B30
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08002740: .4byte 0x03002B30

	thumb_func_start FUN_08002744
FUN_08002744: @ 0x08002744
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r4, _08002778 @ =0x0300445C
	ldrh r1, [r2, #0x20]
	lsls r1, r1, #6
	ldrh r0, [r2, #0x22]
	asrs r1, r0
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [r4]
	ldrh r0, [r2, #0x20]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x20]
	ldrh r1, [r2, #0x20]
	movs r0, #1
	ldrh r5, [r2, #0x22]
	lsls r0, r5
	cmp r1, r0
	blt _08002780
	str r3, [r4]
	ldrh r0, [r2, #0x1e]
	cmp r0, #2
	bne _0800277C
	strh r3, [r2, #0x1e]
	b _08002780
	.align 2, 0
_08002778: .4byte 0x0300445C
_0800277C:
	movs r0, #5
	strh r0, [r2, #0x1e]
_08002780:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08002788
FUN_08002788: @ 0x08002788
	push {r4, lr}
	adds r2, r0, #0
	ldr r3, _080027B8 @ =0x0300445C
	ldrh r0, [r2, #0x20]
	lsls r0, r0, #6
	ldrh r1, [r2, #0x22]
	asrs r0, r1
	str r0, [r3]
	ldrh r0, [r2, #0x20]
	adds r0, #1
	strh r0, [r2, #0x20]
	ldrh r1, [r2, #0x20]
	movs r0, #1
	ldrh r4, [r2, #0x22]
	lsls r0, r4
	cmp r1, r0
	blt _080027B2
	movs r0, #0x40
	str r0, [r3]
	movs r0, #0
	strh r0, [r2, #0x1e]
_080027B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080027B8: .4byte 0x0300445C

	thumb_func_start FUN_080027bc
FUN_080027bc: @ 0x080027BC
	push {r4, r5, lr}
	ldr r0, _080027E0 @ =0x03002B30
	ldr r4, [r0]
	cmp r4, #0
	beq _080027FA
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r4, #0x24]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080027FA
	movs r5, #0
	adds r4, #0x26
	b _080027EE
	.align 2, 0
_080027E0: .4byte 0x03002B30
_080027E4:
	bl Script_GetValue
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
_080027EE:
	bl VM_GetPC
	cmp r0, #0
	beq _080027FA
	cmp r5, #6
	ble _080027E4
_080027FA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08002800
FUN_08002800: @ 0x08002800
	push {lr}
	adds r3, r0, #0
	ldr r0, _08002828 @ =0x03002B30
	ldr r0, [r0]
	cmp r0, #0
	beq _08002822
	strh r3, [r0, #0x24]
	cmp r1, #0
	ble _08002822
	adds r3, r0, #0
	adds r3, #0x26
_08002816:
	ldm r2!, {r0}
	strh r0, [r3]
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bne _08002816
_08002822:
	pop {r0}
	bx r0
	.align 2, 0
_08002828: .4byte 0x03002B30

